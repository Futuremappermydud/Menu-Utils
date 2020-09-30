#include "Main.hpp"

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