#include "CustomExitViewController.hpp"
#include "BeatSaberUI.hpp"

void MenuUtils::CustomExitViewController::Awake()
{
}

void Quit()
{
	Application::Quit();
}

void MenuUtils::CustomExitViewController::DidActivate(bool firstActivation, HMUI::ViewController::ActivationType activationType)
{
	if(firstActivation)
	{
		RectTransform* rt = get_rectTransform();
		//getLogger().debug("Parent Name: " + to_utf8(csstrtostr(rt->get_parent()->get_name())));
    	QuitText = BeatSaberUI::CreateText(rt, "Are you really sure you want to quit <b><color=#FF6060>Beat <color=#00B0FF>Saber</b><color=#FFFFFF>?", UnityEngine::Vector2::get_zero());
		QuitButton = BeatSaberUI::CreateUIButton(get_rectTransform(), "OkButton", UnityEngine::Vector2(0.0f, -2.0f), UnityEngine::Vector2(28.0f, 10.0f), il2cpp_utils::MakeAction<UnityEngine::Events::UnityAction>(il2cpp_functions::class_get_type(classof(UnityEngine::Events::UnityAction*)), (Il2CppObject*)nullptr, Quit), "Quit", nullptr);
	}
}