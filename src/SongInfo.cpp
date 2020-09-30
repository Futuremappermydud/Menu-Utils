#include "SongInfo.hpp"
#include "BeatSaberUI.hpp"

RectTransform* _njsStatButton;

RectTransform* _ppStatButton;

void CreateInfoButtons(StandardLevelDetailView* self)
{
	auto id = self->level->get_levelID();
    auto ConvertedID = to_utf8(csstrtostr(id));
    float _njs = 0.0f;
    float _stars = 0.0f;
    float _pp = 0.0f;

    bool CustomLevel = ConvertedID.find("custom_level_") != std::string::npos;

    _njs = CustomLevel ? self->selectedDifficultyBeatmap->get_noteJumpMovementSpeed() : 0.0f;

    if(FirstTime2)
    {
    	auto statsPanel = self->levelParamsPanel;
        auto statTransforms = statsPanel->GetComponentsInChildren<RectTransform*>();

        auto Texts = statsPanel->GetComponentsInChildren<TextMeshProUGUI*>();

        int x = 0;
        for (int i = 0; i < Texts->Length(); i++)
        {
            if(to_utf8(csstrtostr(Texts->values[i]->get_name())) == "ValueText")
            {
                
                auto text = Texts->values[i];
                float fontSize = text->get_fontSize();
                text->set_fontSize(fontSize -= 0.75f);
            }
        }
        RectTransform* panelRect = (RectTransform*)self->levelParamsPanel->get_transform();
        auto PanelSize = panelRect->get_sizeDelta();
        panelRect->set_sizeDelta(UnityEngine::Vector2 {PanelSize.x * 1.2f, PanelSize.y * 1.2f});
        
        for (int i = 0; i < statTransforms->Length(); i++)
        {
            auto r = statTransforms->values[i];
            if (to_utf8(csstrtostr(r->get_name())) == "Separator")
            {
                continue;
            }
            auto rSize = r->get_sizeDelta();
            r->set_sizeDelta(UnityEngine::Vector2 {rSize.x * 0.9f, rSize.y * 0.9f});   
        }

        
        Transform* statsTransform = statsPanel->get_transform();

        // inject our components
        SpeedSprite = BeatSaberUI::Base64ToSprite(Speed, 40, 40);
        //GraphSprite = Base64ToSprite(Graph, 100, 100);

        _njsStatButton = Object::Instantiate(statTransforms->values[1], statsTransform, false);
        BeatSaberUI::SetStatButtonIcon(_njsStatButton, SpeedSprite);

        //_ppStatButton = Object::Instantiate(statTransforms->values[1], statsTransform, false);
        //SetStatButtonIcon(_ppStatButton, GraphSprite);

        // shrink title
        self->songNameText->set_fontSize(5.0f);   

        //Shrink play buttons
        RectTransform* PlayRect = (RectTransform*)self->playButton->get_transform()->get_parent();
        //DeleteButton = Object::Instantiate(self->playButton->get_gameObject(), PlayRect, false)->GetComponent<Button*>();
        PlayRect->set_localScale(UnityEngine::Vector3(0.9f, 0.9f, 0.9f));
		FirstTime2 = false;
    }
    BeatSaberUI::SetStatButtonText(_njsStatButton, Round(_njs, 1));
}