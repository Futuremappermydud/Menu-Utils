#include "Main.hpp"

extern Button* _pageUpFastButton;
extern Button* _pageDownFastButton;
extern Button* _scrollBottomButton;
extern Button* _scrollTopButton;
extern Button* originalUp;
extern Button* originalDown;
extern TableView* tableview;
extern LevelCollectionTableView* CollectionTableView;
extern const float SEGMENT_PERCENT;
extern const int LIST_ITEMS_VISIBLE_AT_ONC;
extern Array<IPreviewBeatmapLevel*>* beatmaps;

void CreateQuickScrollButtons(LevelCollectionTableView* self);