#include "Main.hpp"
#include "CustomExitViewController.hpp"
#include "BeatSaberUI.hpp"
#include "CustomExitFlowCoordinator.hpp"
#include "MenuColor.hpp"
#include "ScrollButtons.hpp"
#include "SongInfo.hpp"

std::string DoubleArrow = R"(iVBORw0KGgoAAAANSUhEUgAAADgAAAAkCAYAAADckvn+AAAABGdBTUEAALGPC/xhBQAAAAlwSFlzAAAOwgAADsIBFShKgAAAABh0RVh0U29mdHdhcmUAcGFpbnQubmV0IDQuMS41ZEdYUgAAAixJREFUaEPtlslOwzAYhCsh8RhAQWzl1lZsBd4FnggeDU6c2NcDULYDl5aZ4lbBmSROYktp1ZE+OZr8v+2/atWp9fv9iUaaDsyANcsLySrgmepdKtJ04KTX671gbVp+CJo8CxyLd5lIM4MjMBAOfcXSAqrOBy1zxlCHQNUlIs0UdnDgD9aRAg7J4d6wjmTO3gaqXiLNFM5ATOYibaB6itC2h4voFKgeiTRT2ADPQKkLNoHqywP34F5KPJt3UH0SaWbQwKf7hFWJF9sCqs8Ffv3kcObMBlB9iUjTgawhc/1ODInDQY9gHai+VKTpCA/kwUpdfAC7WFVfDFPrfTgizRzwz/4BxIRLv2PpANUXpWNqlbh3qUAhzZwwZdyDmByG3AMfQIl7cm/V54w0C7AC5JAQB+Agdk/acHeAe9o9uZFmQXghXkzpE+zXjPhsPCXusQzs/QshTQeSwjYvdguUvsCBgc9K7FXDVSpsL4EboMTBvv8eY2IPe+39Khm2F0HSkErXgD32PpUO27wwL54l1tSB3V/tsA2PKy9+BZLEd3VTG6X6YTty6QVwCWzR47toLRmPsG1deh5Eh7wA9AbvI7XjE7atAQkHOjfMGW+AqZ2IsD1r+OebWu/DEWnmYBq2sUzDttB4hm0wrK182E4iVNgujDRL4jtsl0KaHvAVtksjTU+UDdtekKZHnMI2UL1ekKZnMsN2SKQZgNSwHRJpBiIxbIdEmgGRYTsc/dovkLE8tDZQiesAAAAASUVORK5CYII=)";
std::string Speed = R"(iVBORw0KGgoAAAANSUhEUgAAACgAAAAoCAYAAACM/rhtAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAQoSURBVFhH7Zfbi1VlGMbHQwo6WVGeIUGUwAvxFMQIoRfqpEKB1EWIh0HrIoSO4N9QE6SgV9pFgShqN5WKYF1EImgFQaEZHogUKXXEoqyc6fe87zNr7z1rRvee0QZi/+Dh+97nPay91957rbVbmjRpcp/o7u6ejbagvegbdBX9ZWkvT7lX0Gy33V96enrGcLCN6CT7hqDnBMsG9IDH3Vs4wBp0IY42BJhxHj3rsUOHmQ8z8GCOrwX/NjqOOpE+yhct7eWdQLddXgP+PjTBhxkczJnJkB9zZAW871heYp3s0gGhZip6GX2f3RXwzrDMdGlj0DwLXc5RCfEltIntaJcV4C9A+vjOofm2C9SD9Kb6zryMZrmsPmiYhn7yjID4CzTJ+SfQUuwR0QDEu7IyanfZjhdGvAzNUMw6GX2ZlQnxeZYp0XA3KBxFw+fRaYg/QGOVZ21Df9t/O5qAUL/QAH+9bdXvsfc7issN61j0YRQb4mMso6LpTlD4ZrYkxEdYikbiVzMTueO2A+JF2AsdBngXszrqX7DdeyKOZiYhfs3p/qFAX+ibrlfDaZaHnA6Ip+CfRL+g1bYHhJoOdB19hsbbDjQb76yOJdjfYBn4o6bg3SxNiJ+Wz/YRKYruAcx6jNkPas+q73IB8TtR1BdyrSSrz97H8lmfQX+iP1B7FA8SxupO9AbSGS1eCPtP86hx3Juo5kwHmOtc08s8+7sdq3l3FA8CevVGqz9Oven40RAuTDfBXxtN1WDud14FZ23Lb0c6e9Jy23VDzxx02KNrwH/LZaorbgjs99qugPmr8yrotB1gNfwdpF7fsx0oLknV4H3NssSlAV7x/Wd/xXaCMdW5gLihM0X9BLQT6U5zDR1A1z2uwPkOtiPdWoC/MqsS4sptlKDNfi+P25+OlqO4SPcHtSPIH8q2/iF/C3WyLS5Zmok0e7rjGVmdED8VhYJglf2AeLwa2XY5PuTSEuTmqGYgyH+ESvdazXRev+hpbFsV94K30qVxFp5Lu0BX+XbvRZdLS1C3wjUlyG1yWQlyuigHnqGHiQK8yjMjQd+L5aNIH4HeZRfrFpeWIDcJ3crOCvLQRJeVIKdbpmZ/wqrr48RoNMRLXRpncF7aCcnS49KdoF4X3263q1+87nRdUL/A7QHxXKfiBY7D+CdTkexwqm5oW0Lfe2ib9rbrhr7NcXBgr0vTOKcSzG8zHQX7bevAep5bj3Snufvj0CBh/oE4OOi12K6Aud15Feie3CqfdWuYydYoHgLMfhLpevgzWmRP19HffAwdf1sUV4O52PmAOH4YKrbVf2ODMON9j9O8uLfrWLYC4rYorgZfF9wfsmT44DXoj1TxV6IGEsVj+3DBCyz+LpQgrx/EV1k6LJxCpX+MNVCgB1fd+p7/L8Ux9bAQP8wmTZr8f2hp+ReWCz5Y6C35EgAAAABJRU5ErkJggg==)";
std::string TripleArrow = R"(iVBORw0KGgoAAAANSUhEUgAAADgAAAAyCAYAAAAJHRh4AAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsEAAA7BAbiRa+0AAAMWSURBVGhD7ZrNbhMxFIVTkLqAVwAKrUpL2aUVfwUELFjwFvBE7csgsQE2sIcVEqL/FFgA5acLWCSc4ziVxzmZsVM7zFQ50qc7vrl37NMm0VU0U91ut3WSdcrGE6uJwRIt2jgOLdgYrVENruOz+wqx3VtmVRt7vQZrdh0nfslE8gQYdTqdbwjLQNWlYNnu0ddjoOqGIpMl3MSGfxCPlNEkzX1HPJLd+wZQ9RKZLOEtGJA9yApQPaOw4ptz9AaoHolMlnAVfAFKB+AaUH0x8B68lxL35hlUn0QmK1jCX/czohIPdh2ovhD49pPm7J5LQPUNRSYDqDIZ9TmxDDUHfQJXgOorRSYD4YbcWOkAf4BbiKpvAFub3ByRyQgWwT4YEA79A2EVqD6XVVurxHtzD9UXhExGsgA+ggEFmLwNfgIl3pP3Vn3ByOQIXAbSJEQDNOL3lJnbA7yn3xONTAZwGvhvHR6IB1P6Be6Afi2vmVPiPeaBe2/+J7mnmwtCJgNYx9vvKyLnRDfPg+0Cpd/groXXSuz1zbW5F1jz8kHIZAVVs+gc2AFKNHbYuxwQe9jr3qu2s+gsGGZSaRuwx71H7WdRHpgHrxJrLgG3tzGzKA++BYaJr/nmGjeLXgSbwBdzfM2tbewsOgNckxuAObem8bMoDb2zXLA5g61Nbo7IZASTWRRhMosK/fdZVFE5i9of8lgbO4uOjEwGoIZtkmMWJbUZtknKWZTUbtgmKWZRUusffo8zi5J6D9vIMQbNorbWpf7DtnPoylnUM9iMYds7dOks6tQ2Z9j2DJKyWZSx8cM2mbYU8rY2uTkikxFMhm2EybAt1MxhG/RrxzZsp34QaB48B+fMqqhD8Kh32XoKzvYuC9oDD8B7s0qgHE86zYEX4LxZFUWTU+CMWRW1C+6DD2aVSLke5ZoFL4EyqbQDaG7DrBIq15NOPOg9wINXiTWsTW6OyvkoV9/ktllp8TXWbJpVBuV+Vo0Hp4EtsyqKuazmqNwGqb4R12SZ8aTK9SWjNAOe9S5bD0HI5/PYGqdBatrGvzZmVqv1D4lbDKROsZZbAAAAAElFTkSuQmCC)";
std::string Graph = R"(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)";
Sprite* SpeedSprite;
Sprite* DoubleArrowSprite;
Sprite* TripleArrowSprite;
Sprite* GraphSprite;

Button* DeleteButton;

bool FirstTime = true;

bool FirstTime2 = true;

MAKE_HOOK_OFFSETLESS(StandardLevelDetailView_RefreshContent, void, StandardLevelDetailView* self) {
    StandardLevelDetailView_RefreshContent(self);
    CreateInfoButtons(self);
}

MAKE_HOOK_OFFSETLESS(MenuTransitionsHelper_RestartGame, void, Il2CppObject* self) {
    FirstTime = true;
    FirstTime2 = true;
    MenuTransitionsHelper_RestartGame(self);
}

MAKE_HOOK_OFFSETLESS(WebRequest, void, HealthWarningFlowCoordinator* self, bool firstActivation, FlowCoordinator::ActivationType activationType) {
    //PPDownloader_WebRequest();
    WebRequest(self, firstActivation, activationType);
}

MAKE_HOOK_OFFSETLESS(Lights, void, MainFlowCoordinator* self, bool firstActivation, FlowCoordinator::ActivationType activationType) {
    Lights(self, firstActivation, activationType);
    ColorLightsMain(self);
}

MAKE_HOOK_OFFSETLESS(Lights2, void, SoloFreePlayFlowCoordinator* self, bool firstActivation, FlowCoordinator::ActivationType activationType) {
    Lights2(self, firstActivation, activationType);
    ColorLightsSolo(self);
}

MAKE_HOOK_OFFSETLESS(Lights3, void, CampaignFlowCoordinator* self, bool firstActivation, FlowCoordinator::ActivationType activationType) {
    Lights3(self, firstActivation, activationType);
    ColorLightsCampaign(self);
}

HMUI::FlowCoordinator* flowCoordinator = nullptr;
void ShowPanel() {
    getLogger().info("OnButtonClick");
    if(!flowCoordinator) {
        flowCoordinator = BeatSaberUI::CreateFlowCoordinator<MenuUtils::CustomExitFlowCoordinator*>();
    }
    BeatSaberUI::getMainFlowCoordinator()->PresentFlowCoordinator(flowCoordinator, nullptr, false, false);
}

UnityEngine::UI::Button* button;
MAKE_HOOK_OFFSETLESS(TryExit, void, MainFlowCoordinator* self, MainMenuViewController* viewController, MainMenuViewController::MenuButton subMenuType) {
    if (subMenuType == MainMenuViewController::MenuButton::Quit && Config.ConfirmQuit)
    {
        ShowPanel();
        return;
    }
    TryExit(self, viewController, subMenuType);
}
MAKE_HOOK_OFFSETLESS(LevelCollectionTableView_Init, void, LevelCollectionTableView* self)
{
    LevelCollectionTableView_Init(self);
    CreateQuickScrollButtons(self);
}

extern "C" void setup(ModInfo& info) {
    info.id = "MenuUtils";
    info.version = "0.2.0";
    modInfo = info;
}

void SaveConfig() {
    getConfig().config.RemoveAllMembers();
    getConfig().config.SetObject();
    rapidjson::Document::AllocatorType& allocator = getConfig().config.GetAllocator();
    ConfigValue Menu(rapidjson::kObjectType);
    Menu.AddMember("Menu R", Config.MenuR, allocator);
    Menu.AddMember("Menu G", Config.MenuG, allocator);
    Menu.AddMember("Menu B", Config.MenuB, allocator);
    getConfig().config.AddMember("Menu Color", Menu, allocator);
    getConfig().Write();
}   

bool LoadConfig() {
    getConfig().Load();
    bool foundEverything = true;
    if (getConfig().config["Menu Color"].HasMember("Menu R") && getConfig().config["Menu Color"]["Menu R"].IsFloat()) {
        Config.MenuR = getConfig().config["Menu Color"]["Menu R"].GetFloat();
    }
    else {
        foundEverything = false;
    }
    if (getConfig().config["Menu Color"].HasMember("Menu G") && getConfig().config["Menu Color"]["Menu G"].IsFloat()) {
        Config.MenuG = getConfig().config["Menu Color"]["Menu G"].GetFloat();
    }
    else {
        foundEverything = false;
    }
    if (getConfig().config["Menu Color"].HasMember("Menu B") && getConfig().config["Menu Color"]["Menu B"].IsFloat()) {
        Config.MenuB = getConfig().config["Menu Color"]["Menu B"].GetFloat();
    }
    else {
        foundEverything = false;
    }
    if (foundEverything) {
        return true;
    }
    return false;
}

extern "C" void load() {
    if(!LoadConfig())
    {
        SaveConfig();
    }

    il2cpp_functions::Init();

    custom_types::Register::RegisterType<MenuUtils::CustomExitFlowCoordinator>();
    custom_types::Register::RegisterType<MenuUtils::CustomExitViewController>();
    INSTALL_HOOK_OFFSETLESS(TryExit, il2cpp_utils::FindMethodUnsafe("", "MainFlowCoordinator", "HandleMainMenuViewControllerDidFinish", 2));
    INSTALL_HOOK_OFFSETLESS(Lights, il2cpp_utils::FindMethodUnsafe("", "MainFlowCoordinator", "DidActivate", 2));
    INSTALL_HOOK_OFFSETLESS(Lights2, il2cpp_utils::FindMethodUnsafe("", "SoloFreePlayFlowCoordinator", "DidActivate", 2));
    INSTALL_HOOK_OFFSETLESS(Lights3, il2cpp_utils::FindMethodUnsafe("", "CampaignFlowCoordinator", "DidActivate", 2));
    INSTALL_HOOK_OFFSETLESS(WebRequest, il2cpp_utils::FindMethodUnsafe("", "HealthWarningFlowCoordinator", "DidActivate", 2));
    INSTALL_HOOK_OFFSETLESS(LevelCollectionTableView_Init, il2cpp_utils::FindMethod("", "LevelCollectionTableView", "RefreshLevelsAvailability"));
    INSTALL_HOOK_OFFSETLESS(MenuTransitionsHelper_RestartGame, il2cpp_utils::FindMethod("", "MenuTransitionsHelper", "RestartGame"));
    INSTALL_HOOK_OFFSETLESS(StandardLevelDetailView_RefreshContent, il2cpp_utils::FindMethod("", "StandardLevelDetailView", "RefreshContent"));

}