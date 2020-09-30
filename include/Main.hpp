#pragma once

#include "Codegen.hpp"
#include "../extern/custom-types/shared/macros.hpp"
#include "../extern/custom-types/shared/types.hpp"
#include "../extern/custom-types/shared/register.hpp"

#include <unordered_set>
#include <map>
#include <list>
#include <tuple> // for tuple 
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

#include "../extern/beatsaber-hook/shared/utils/utils.h"
#include "../extern/beatsaber-hook/shared/utils/logging.hpp"
#include "../extern/modloader/shared/modloader.hpp"
#include "../extern/beatsaber-hook/shared/utils/il2cpp-utils.hpp" 
#include "../extern/beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "../extern/beatsaber-hook/shared/utils/typedefs.h"
#include "../extern/beatsaber-hook/shared/config/config-utils.hpp"

using namespace GlobalNamespace;
using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace HMUI;
using namespace TMPro;
using namespace il2cpp_utils;

static ModInfo modInfo;

static Configuration& getConfig() {
  static Configuration configuration(modInfo);
  return configuration;
}

static const Logger& getLogger() {
    static const Logger logger(modInfo);
    return logger;
}

static struct Config
{
	float MenuR = 255.0f;
	float MenuG = 255.0f;
	float MenuB = 255.0f;
    bool ConfirmQuit = true;
} Config;

static std::vector<std::string> split(std::string const &str, const char delim)
{
    std::vector<std::string> out;
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
    return out;
}

static std::string GetHash(std::string levelId)
{
    getLogger().debug(levelId);
    if (levelId.find("custom_level_"))
    {
        auto splits = split(levelId, '_');
        return splits[2];
    }
    getLogger().debug(levelId);
    return levelId;
}

extern GameplayModifiersModelSO* modifiersModel;

static std::string Round (float val, int precision = 2)
{
	std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << val;
    std::string Out = stream.str();
	return Out;
}

struct SongID
{
    std::string id;
    BeatmapDifficulty difficulty;

    SongID(std::string _id, BeatmapDifficulty _difficulty)
    {
        id = _id;
        difficulty = _difficulty;
    }
};

struct RawPPData
{
    float _Easy_SoloStandard;
    float _Normal_SoloStandard;
    float _Hard_SoloStandard;
    float _Expert_SoloStandard;
    float _ExpertPlus_SoloStandard;
};

void PPDownloader_WebRequest();