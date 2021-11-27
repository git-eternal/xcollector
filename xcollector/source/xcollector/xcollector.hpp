#pragma once

#include "../utils/utils.hpp"

using beatmap_t = std::vector<int>;

namespace XCollect
{
	beatmap_t GetBeatmapIds(const nlohmann::json& data);
	void DownloadCollection(const beatmap_t& beatmapIds, const std::string collectionId);
	nlohmann::json GetCollectionData(const std::string& id);
}