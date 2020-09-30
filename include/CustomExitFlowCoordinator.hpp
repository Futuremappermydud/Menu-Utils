#pragma once
#include "Main.hpp"

#include "HMUI/ViewController.hpp"
#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/FlowCoordinator_ActivationType.hpp"

#include "./CustomExitViewController.hpp"

#include "custom-types/shared/macros.hpp"

DECLARE_CLASS_CODEGEN(MenuUtils, CustomExitFlowCoordinator, HMUI::FlowCoordinator,

    DECLARE_INSTANCE_FIELD(MenuUtils::CustomExitViewController*, vc);

    DECLARE_METHOD(void, Awake);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "FlowCoordinator", "DidActivate", 2), bool firstActivation, HMUI::FlowCoordinator::ActivationType activationType);

    REGISTER_FUNCTION(CustomExitFlowCoordinator,
        REGISTER_FIELD(vc);

        REGISTER_METHOD(Awake);
        REGISTER_METHOD(DidActivate);
    )
)