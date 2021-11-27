#include "utils/utils.hpp"
#include "xcollector/xcollector.hpp"

int main()
{
	Utils::InitializeConsole(); Utils::OutputLogo();

	Utils::Output("Collection ID: ");

	std::string collectionId;
	std::cin >> collectionId;

	nlohmann::json data{ XCollect::GetCollectionData(collectionId) };

	beatmap_t beatmapIds{ XCollect::GetBeatmapIds(data) };

	XCollect::DownloadCollection(beatmapIds, collectionId);

	return std::cin.get();
}