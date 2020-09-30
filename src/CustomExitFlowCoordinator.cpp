#include "CustomExitViewController.hpp"
#include "CustomExitFlowCoordinator.hpp"
#include "BeatSaberUI.hpp"

void MenuUtils::CustomExitFlowCoordinator::Awake()
{
	if(!vc){
        vc = BeatSaberUI::CreateViewController<MenuUtils::CustomExitViewController*>();
    }
}

void MenuUtils::CustomExitFlowCoordinator::DidActivate(bool firstActivation, HMUI::FlowCoordinator::ActivationType activationType)
{
	if(firstActivation){
        set_title(il2cpp_utils::createcsstr("Quit"));
        ProvideInitialViewControllers(vc, nullptr, nullptr, nullptr, nullptr);
    }
}