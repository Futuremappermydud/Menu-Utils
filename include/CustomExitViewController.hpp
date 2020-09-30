#pragma once
#include "Main.hpp"

#include "HMUI/ViewController.hpp"
#include "HMUI/ViewController_ActivationType.hpp"
#include "HMUI/ViewController_DeactivationType.hpp"

#include "custom-types/shared/macros.hpp"
#include "CustomExitFlowCoordinator.hpp"

DECLARE_CLASS_CODEGEN(MenuUtils, CustomExitViewController, HMUI::ViewController,

	DECLARE_INSTANCE_FIELD(TMPro::TextMeshProUGUI*, QuitText);
    DECLARE_INSTANCE_FIELD(MenuUtils::CustomExitFlowCoordinator*, _flowCoordinator);
    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Button*, QuitButton);
    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Button*, CancelButton);

    DECLARE_METHOD(void, Awake);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 2), bool firstActivation, HMUI::ViewController::ActivationType activationType);

    REGISTER_FUNCTION(CustomExitViewController,
		REGISTER_FIELD(QuitText);
        REGISTER_FIELD(_flowCoordinator);
        REGISTER_FIELD(QuitButton);
        REGISTER_FIELD(CancelButton);
        REGISTER_METHOD(Awake);
        REGISTER_METHOD(DidActivate);
    )
)