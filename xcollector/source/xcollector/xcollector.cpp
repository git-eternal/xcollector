#include "xcollector.hpp"

beatmap_t XCollect::GetBeatmapIds(const nlohmann::json& data)
{
	beatmap_t beatmapIds{};

	for (const auto& beatmap : data["beatmaps"].items())
	{
		for (const auto& id : beatmap.value()["beatmapset_id"])
			beatmapIds.push_back(id);
	}

	return beatmapIds;
}

void XCollect::DownloadCollection(const beatmap_t& beatmapIds, const std::string collectionId)
{
	Utils::Output("Beatmap directory (blank for default): ");

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string outputPath{}; 
	
	std::getline(std::cin, outputPath);

	if (outputPath.empty())
		outputPath = "Beatmaps";

	if (!fs::exists(outputPath) && !fs::create_directory(outputPath))
	{
		Utils::Output("Error creating beatmap folder. Please run as admin");
		return;
	}

	if (!fs::exists(outputPath + "\\" + collectionId) && !fs::create_directory(outputPath + "\\" + collectionId))
	{
		Utils::Output("Error creating collection folder");
		return;
	}

	progressbar bar(beatmapIds.size());

	std::thread download([&]() -> void
	{
		std::for_each(std::execution::par, beatmapIds.begin(), 
			beatmapIds.end(), [&](auto& id) -> void
		{
			std::string url = std::regex_replace(
				Constants::BeatConnect,
				std::regex("%s"),
				std::to_string(id));

			std::string beatmapPath{ outputPath + "\\" + collectionId + "\\" + std::to_string(id) + ".osz" };

			std::ofstream path(beatmapPath, std::ios::binary);

			auto session = cpr::Session();

			session.SetUrl(cpr::Url{ url });

			// Download the beatmap
			//
			auto response = session.Download(path);

			if(response.downloaded_bytes != 0)
				bar.update();
			else
				// Retry download
				//
				session.Download(path);
		});
	});

	download.join();

	Log<Color::Default>("\n\n  [", false);
	Log<Color::Red>("#", false);
	Log<Color::Default>("] ", false);

	Log<Color::Default>("Download success. Press ENTER to exit");
}

nlohmann::json XCollect::GetCollectionData(const std::string& id)
{
	std::string url = std::regex_replace(Constants::Api, std::regex("%s"), id);

	// Grab the beatmap data json
	//
	cpr::Response res = cpr::Get
	(
		cpr::Header{ {"Content-Type", "application/json"} },
		cpr::Url{ url },
		cpr::Timeout{ 5000 },

		cpr::UserAgent
		{
			"Mozilla/5.0 (Macintosh; Intel" \
			"Mac OS X 10.12; rv:55.0)"      \
			"Gecko/20100101 Firefox/55.0"   \
		}
	);

	nlohmann::json data{ json::parse(res.text) };

	return data;
}
