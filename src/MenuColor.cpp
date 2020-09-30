#include "MenuColor.hpp"

MenuLightsPresetSO* CustomLights;
MenuLightsManager* Manager;
ColorScheme* scheme;

void RecolorLights()
{
    for (int i = 0; i < CustomLights->lightIdColorPairs->Length(); i++)
    {
        UnityEngine::Color SelectedColor;
        SelectedColor.r = getConfig().config["Menu Color"]["Menu R"].GetFloat() / 255;
        SelectedColor.g = getConfig().config["Menu Color"]["Menu G"].GetFloat() / 255;
        SelectedColor.b = getConfig().config["Menu Color"]["Menu B"].GetFloat() / 255;
        MenuLightsPresetSO::LightIdColorPair* pair = CustomLights->lightIdColorPairs->values[i];
        SimpleColorSO* SCS = SimpleColorSO::New_ctor();
        SCS->SetColor(SelectedColor);
        pair->baseColor = SCS;
    }
    Manager->SetColorPreset(CustomLights, true);
}

void ColorLightsCampaign(CampaignFlowCoordinator* self)
{
	//scheme = self->playerDataModel->playerData->colorSchemesSettings->GetSelectedColorScheme();
    CustomLights = Object::Instantiate<MenuLightsPresetSO*>(self->defaultLightsPreset);
    Manager = self->menuLightsManager;
    RecolorLights();
}

void ColorLightsSolo(SoloFreePlayFlowCoordinator* self)
{
	//scheme = self->playerDataModel->playerData->colorSchemesSettings->GetSelectedColorScheme();
    CustomLights = Object::Instantiate<MenuLightsPresetSO*>(self->defaultLightsPreset);
    Manager = self->menuLightsManager;
    RecolorLights();
}

void ColorLightsMain(MainFlowCoordinator* self)
{
	//scheme = self->playerDataModel->playerData->colorSchemesSettings->GetSelectedColorScheme();
    CustomLights = Object::Instantiate<MenuLightsPresetSO*>(self->defaultLightsPreset);
    Manager = self->menuLightsManager;
    RecolorLights();
}

bool HandleColored = false;

void RecolorHandle()
{
    /*
    GameObject* Left = GameObject::Find(createcsstr("ControllerLeft"));
    GameObject* Right = GameObject::Find(createcsstr("ControllerRight"));
    Il2CppString* Handle = createcsstr("MenuHandle");
    Il2CppString* Normal = createcsstr("Normal");
    Il2CppString* _Color = createcsstr("_Color");
    MeshRenderer* LeftMR = Left->get_transform()->Find(Handle)->Find(Normal)->GetComponent<MeshRenderer*>(); 
    MeshRenderer* RightMR = Right->get_transform()->Find(Handle)->Find(Normal)->GetComponent<MeshRenderer*>(); 
    LeftMR->get_material()->SetColor(_Color, scheme->get_saberAColor());
    RightMR->get_material()->SetColor(_Color, scheme->get_saberBColor());
    HandleColored = true;
    */
}