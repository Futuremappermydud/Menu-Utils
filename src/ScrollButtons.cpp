#include "ScrollButtons.hpp"
#include "BeatSaberUI.hpp"

Button* _pageUpFastButton;
Button* _pageDownFastButton;
Button* _scrollBottomButton;
Button* _scrollTopButton;
Button* originalUp;
Button* originalDown;
TableView* tableview;
LevelCollectionTableView* CollectionTableView;
const float SEGMENT_PERCENT = 0.1f;
const int LIST_ITEMS_VISIBLE_AT_ONCE = 6;
Array<IPreviewBeatmapLevel*>* beatmaps;


void RefreshQuickScroll()
{
    _pageUpFastButton->set_interactable(originalUp->get_interactable());
    _pageDownFastButton->set_interactable(originalDown->get_interactable());
    _scrollBottomButton->set_interactable(originalDown->get_interactable());
    _scrollTopButton->set_interactable(originalUp->get_interactable());
}

//Stolen from System.Math
int Sign(int value)
{
	if (value < 0)
	{
		return -1;
	}
	if (value > 0)
	{
		return 1;
	}
	return 0;
}

//Hardcoded bad but whatever
//System.Array.FindIndex
int FindIndex(Array<IPreviewBeatmapLevel*>* array, int startIndex, int count, std::string TargetID)
{
    int num = startIndex + count;
	for (int i = startIndex; i < num; i++)
	{
		if (to_utf8(csstrtostr(array->values[i]->get_levelID())) == TargetID)
		{
			return i;
		}
	}
    return -1;
}

void ScrollToLevelByRow(int selectedIndex)
{

    int selectedRow = CollectionTableView->selectedRow;
    if (selectedRow != selectedIndex && CollectionTableView->get_isActiveAndEnabled())
    {
        CollectionTableView->HandleDidSelectRowEvent(tableview, selectedIndex);
    }
    tableview->ScrollToCellWithIdx(selectedIndex, TableViewScroller::ScrollPositionType::Beginning, true);
    //tableview->SelectCellWithIdx(selectedIndex, true);  
    RefreshQuickScroll();          
}

void JumpSongList(int numJumps, float segmentPercent)
{
    int totalSize = beatmaps->Length();
    int segmentSize = (int)(totalSize * segmentPercent);

    if (segmentSize < LIST_ITEMS_VISIBLE_AT_ONCE)
    {
        segmentSize = LIST_ITEMS_VISIBLE_AT_ONCE;
    }
    int currentRow = CollectionTableView->selectedRow;
    int jumpDirection = Sign(numJumps);
    int newRow = currentRow + (jumpDirection * segmentSize);

    if (newRow <= 0)
    {
        newRow = 0;
    }
    else if (newRow >= totalSize)
    {
        newRow = totalSize - 1;
    }


    int selectedIndex = 0;

    if (totalSize <= 0)
    {
        return;
    }

    int selectedRow = FindIndex(beatmaps, 0, totalSize, to_utf8(csstrtostr(beatmaps->values[newRow]->get_levelID())));
    if (selectedIndex < 0)
    {
        int selectedRow = CollectionTableView->selectedRow;

        selectedIndex = System::Math::Min(totalSize, selectedRow);
    }
    else
    {
        // the header counts as an index, so if the index came from the level array we have to add 1.
        selectedIndex += 1;
    }

    CollectionTableView->SelectLevel(beatmaps->values[newRow]);   
    RefreshQuickScroll();
}
void QuickScrollUp()
{
    beatmaps = CollectionTableView->previewBeatmapLevels;
    JumpSongList(-1, SEGMENT_PERCENT);
}

void QuickScrollDown()
{
    beatmaps = CollectionTableView->previewBeatmapLevels;
    JumpSongList(1, SEGMENT_PERCENT);
}

void ScrollToBottom()
{
    beatmaps = CollectionTableView->previewBeatmapLevels;
    ScrollToLevelByRow(beatmaps->Length());
    CollectionTableView->SelectLevel(beatmaps->values[beatmaps->Length()]); 
}
void ScrollToTop()
{
    beatmaps = CollectionTableView->previewBeatmapLevels;
    ScrollToLevelByRow(0);
    CollectionTableView->SelectLevel(beatmaps->values[0]); 
}

void ToggleQuickScrollButtons(bool val)
{
    _pageDownFastButton->get_gameObject()->get_gameObject()->SetActive(val);
    _pageUpFastButton->get_gameObject()->get_gameObject()->SetActive(val);
    _scrollBottomButton->get_gameObject()->get_gameObject()->SetActive(val);
    _scrollTopButton->get_gameObject()->get_gameObject()->SetActive(val);
}

void CreateQuickScrollButtons(LevelCollectionTableView* self)
{
	
    CollectionTableView = self;
    
    beatmaps = self->previewBeatmapLevels;
    
    
    if(!FirstTime)
    {
        tableview = self->tableView;
        originalDown = tableview->pageDownButton;
        originalUp = tableview->pageUpButton;
        RefreshQuickScroll();

    }

    if(!FirstTime) return;
    FirstTime = false;
    tableview = self->tableView;
    originalUp = tableview->pageUpButton;
    _pageUpFastButton = Object::Instantiate(originalUp, self->get_transform(), false);
    RectTransform* FastUpRectTransform = (RectTransform*)_pageUpFastButton->get_transform();
    FastUpRectTransform->set_anchorMin(UnityEngine::Vector2(0.5f, 1.0f));
    FastUpRectTransform->set_anchorMax(UnityEngine::Vector2(0.5f, 1.0f));
    FastUpRectTransform->set_anchoredPosition(UnityEngine::Vector2(-26.0f, 1.0f));
    FastUpRectTransform->set_sizeDelta(UnityEngine::Vector2(8.0f, 6.0f));
    DoubleArrowSprite = BeatSaberUI::Base64ToSprite(DoubleArrow, 56, 36);
    BeatSaberUI::GetRectByName(_pageUpFastButton, "BG")->set_sizeDelta(UnityEngine::Vector2(8.0f, 6.0f));
    BeatSaberUI::GetImageByName(_pageUpFastButton, "Arrow")->set_sprite(DoubleArrowSprite);
    
    _scrollTopButton = Object::Instantiate(originalUp, self->get_transform(), false);
    RectTransform* FastTopRectTransform = (RectTransform*)_scrollTopButton->get_transform();
    FastTopRectTransform->set_anchorMin(UnityEngine::Vector2(0.5f, 1.0f));
    FastTopRectTransform->set_anchorMax(UnityEngine::Vector2(0.5f, 1.0f));
    FastTopRectTransform->set_anchoredPosition(UnityEngine::Vector2(-35.5f, 1.0f));
    FastTopRectTransform->set_sizeDelta(UnityEngine::Vector2(8.0f, 6.0f));
    TripleArrowSprite = BeatSaberUI::Base64ToSprite(TripleArrow, 56, 50);
    BeatSaberUI::GetRectByName(_scrollTopButton, "BG")->set_sizeDelta(UnityEngine::Vector2(8.0f, 6.0f));
    BeatSaberUI::GetImageByName(_scrollTopButton, "Arrow")->set_sprite(TripleArrowSprite);  

    originalDown = tableview->pageDownButton;
    _pageDownFastButton = Object::Instantiate(originalDown, self->get_transform(), false);
    RectTransform* FastDownRectTransform = (RectTransform*)_pageDownFastButton->get_transform();
    FastDownRectTransform->set_anchorMin(UnityEngine::Vector2(0.5f, 0.0f));
    FastDownRectTransform->set_anchorMax(UnityEngine::Vector2(0.5f, 0.0f));
    FastDownRectTransform->set_anchoredPosition(UnityEngine::Vector2(-26.0f, -1.0f));
    FastDownRectTransform->set_sizeDelta(UnityEngine::Vector2(8.0f, 6.0f));
    BeatSaberUI::GetRectByName(_pageDownFastButton, "BG")->set_sizeDelta(UnityEngine::Vector2(8.0f, 6.0f));
    BeatSaberUI::GetImageByName(_pageDownFastButton, "Arrow")->set_sprite(DoubleArrowSprite);
    
    auto action = MakeAction<UnityEngine::Events::UnityAction>(il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("UnityEngine.Events", "UnityAction")), (Il2CppObject*)nullptr, RefreshQuickScroll);
    originalUp->get_onClick()->AddListener(action);
    originalDown->get_onClick()->AddListener(action);
    auto actionUp = MakeAction<UnityEngine::Events::UnityAction>(il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("UnityEngine.Events", "UnityAction")), (Il2CppObject*)nullptr, QuickScrollUp);
    auto actionDown = MakeAction<UnityEngine::Events::UnityAction>(il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("UnityEngine.Events", "UnityAction")), (Il2CppObject*)nullptr, QuickScrollDown);

    _pageUpFastButton->get_onClick()->AddListener(actionUp);
    _pageDownFastButton->get_onClick()->AddListener(actionDown);
    

    _scrollBottomButton = Object::Instantiate(originalDown, self->get_transform(), false);
    RectTransform* FastBottomRectTransform = (RectTransform*)_scrollBottomButton->get_transform();
    FastBottomRectTransform->set_anchorMin(UnityEngine::Vector2(0.5f, 0.0f));
    FastBottomRectTransform->set_anchorMax(UnityEngine::Vector2(0.5f, 0.0f));
    FastBottomRectTransform->set_anchoredPosition(UnityEngine::Vector2(-35.5f, -1.0f));
    FastBottomRectTransform->set_sizeDelta(UnityEngine::Vector2(8.0f, 6.0f));
    BeatSaberUI::GetRectByName(_scrollBottomButton, "BG")->set_sizeDelta(UnityEngine::Vector2(8.0f, 6.5f));
    BeatSaberUI::GetImageByName(_scrollBottomButton, "Arrow")->set_sprite(TripleArrowSprite);

    auto actionBottom = MakeAction<UnityEngine::Events::UnityAction>(il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("UnityEngine.Events", "UnityAction")), (Il2CppObject*)nullptr, ScrollToBottom);

    _scrollBottomButton->get_onClick()->AddListener(actionBottom);

    auto actionTop = MakeAction<UnityEngine::Events::UnityAction>(il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("UnityEngine.Events", "UnityAction")), (Il2CppObject*)nullptr, ScrollToTop);

    _scrollTopButton->get_onClick()->AddListener(actionTop);
}