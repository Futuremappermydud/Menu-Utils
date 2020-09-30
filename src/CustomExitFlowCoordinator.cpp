#include "CustomExitViewController.hpp"
#include "CustomExitFlowCoordinator.hpp"
#include "BeatSaberUI.hpp"

MenuUtils::CustomExitViewController* vc;

void MenuUtils::CustomExitFlowCoordinator::Awake()
{
	if(!(vc != nullptr)){
        vc = BeatSaberUI::CreateViewController<MenuUtils::CustomExitViewController*>();
    }
}

void MenuUtils::CustomExitFlowCoordinator::DidActivate(bool firstActivation, HMUI::FlowCoordinator::ActivationType activationType)
{
	if(firstActivation){
        set_title(il2cpp_utils::createcsstr("Quit"));
        vc->_flowCoordinator = this;
        ProvideInitialViewControllers(vc, nullptr, nullptr, nullptr, nullptr);
    }
}