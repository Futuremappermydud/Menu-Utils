#include "CustomExitViewController.hpp"
#include "CustomExitViewController.hpp"
#include "BeatSaberUI.hpp"

MenuUtils::CustomExitViewController* self;

void MenuUtils::CustomExitViewController::Awake()
{
	self = this;
}

void Quit()
{
	Application::Quit();
}

void Cancel()
{
	BeatSaberUI::getMainFlowCoordinator()->DismissFlowCoordinator(self->_flowCoordinator, nullptr, false);
}

void MenuUtils::CustomExitViewController::DidActivate(bool firstActivation, HMUI::ViewController::ActivationType activationType)
{
	if(firstActivation)
	{
		RectTransform* rt = get_rectTransform();
		//getLogger().debug("Parent Name: " + to_utf8(csstrtostr(rt->get_parent()->get_name())));
  		QuitText = BeatSaberUI::CreateText(rt, "Are you really sure you want to quit <b><color=#FF6060>Beat <color=#00B0FF>Saber</b><color=#FFFFFF>?", UnityEngine::Vector2(0.0f, 13.0));
		QuitText->set_fontSize(6);
		QuitText->set_alignment(TextAlignmentOptions::Center);

		QuitButton =   BeatSaberUI::CreateUIButton(get_rectTransform(), "OkButton", UnityEngine::Vector2(12.0f, -10.0f), UnityEngine::Vector2(21.0f, 8.0f), il2cpp_utils::MakeAction<UnityEngine::Events::UnityAction>(il2cpp_functions::class_get_type(classof(UnityEngine::Events::UnityAction*)), (Il2CppObject*)nullptr, Quit), "Quit", nullptr);
		CancelButton = BeatSaberUI::CreateUIButton(get_rectTransform(), "OkButton", UnityEngine::Vector2(-12.0f, -10.0f), UnityEngine::Vector2(27.0f, 8.0f), il2cpp_utils::MakeAction<UnityEngine::Events::UnityAction>(il2cpp_functions::class_get_type(classof(UnityEngine::Events::UnityAction*)), (Il2CppObject*)nullptr, Cancel), "Cancel", nullptr);
		BeatSaberUI::ToggleButtonWordWrapping(QuitButton, false);
		BeatSaberUI::ToggleButtonWordWrapping(CancelButton, false);
		BeatSaberUI::SetButtonTextSize(QuitButton, 6);
		BeatSaberUI::SetButtonTextSize(CancelButton, 6);

	}
}