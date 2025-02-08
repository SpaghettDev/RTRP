#include "equality.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_all.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>

#include <string_view>

#define private public
#include <rtrp/rtrp.hpp>
#undef private

static constexpr std::string_view SEARCH_RESPONSE = \
	"1:106749466:2:Drowsy:5:7:6:10143327:8:10:9:20:10:37165:12:0:13:22:14:3085:17::43:4:25::18:3:19:25067:42:0:45:17233:3:eW91IGxvb2sgdGlyZWQuIGhlcmUsIHRha2UgYSBicmVhay4u:15:3:30:0:31:0:37:1:38:1:39:3:46:1:47:2:35:1272705#10143327:TeeeJify:2723422#1~|~1272705~|~2~|~Windows96 - Hypnosis~|~3~|~10000168~|~4~|~whitegavriel~|~5~|~9.67~|~6~|~~|~10~|~https%3A%2F%2Faudio.ngfiles.com%2F1272000%2F1272705_Windows96---Hypnosis.mp3%3Ff1703190904~|~7~|~~|~8~|~1#9999:0:10#f3b3c99922de38105071e6def6db2eae92a1ef9f";

static constexpr std::string_view MALFORMED_SEARCH_RESPONSE = \
	"1:106749466:2:Drowsy:::6:10143327:8:10:9:20:10:37165:12::13:22:14:3085:17::43:4:25::18:3:19:25067:42:0::17233::eW91IGxvb2sgdGlyZWQuIGhlcmUsIHRha2UgYSBicmVhay4u:15:3:30:0:31:0:37.sasd:1:38:1:39:3:46:1:47:2:35:1272705#10143327:....:2723422#1~|~1272705~|~2~|~Windows96 - Hypnosis~|~3~|~10000168~|~4~|~whitegavriel~|~5~|~9.67~|~6~|~~|~10~|~https%3A%2F%2Faudio.ngfiles.com%2F1272000%2F1272705_Windows96---Hypnosis.mp3%3Ff1703190904~|~7~|~~|~8~|~1#9999:0:10#f3b3c99922de38105071e6def6db2eae92a1ef9f";
	
TEST_CASE("Level Response 1") {
	const auto parsed = rtrp::RtResponseParser::parseLevelResponse(SEARCH_RESPONSE);
	const rtrp::responses::LevelResponse expected{
		{ rtrp::objects::LevelObject{
			.levelID=106749466,
			.name="Drowsy",
			.description="eW91IGxvb2sgdGlyZWQuIGhlcmUsIHRha2UgYSBicmVhay4u",
			.levelString="",
			.version=7,
			.creatorUserID=10143327,
			.difficultyDenominator=10,
			.difficultyNumerator=20,
			.downloads=37165,
			.setCompletes=0,
			.officialSong=0,
			.gameVersion=22,
			.likes=3085,
			.length=3,
			.dislikes=0,
			.isDemon=0,
			.stars=3,
			.featureIdx=25067,
			.isAuto=0,
			.recordString="",
			.password="",
			.uploadDate="",
			.updateDate="",
			.copiedID=0,
			.twoPlayer=0,
			.customSongID=1272705,
			.extraString="",
			.coins=1,
			.verifiedCoins=1,
			.starsRequested=3,
			.lowDetailMode=0,
			.dailyNumber=0,
			.epic=0,
			.demonDifficulty=4,
			.isGauntlet=0,
			.objects=17233,
			.editorTime=1,
			.copiedEditorTime=2,
			.settingsString=""
		} },
		{ rtrp::objects::CreatorObject{
			.userID=2723422,
			.name="TeeeJify",
			.accountID=2723422
		} },
		{ rtrp::objects::SongObject{ 
			.ID=1272705,
			.name="Windows96 - Hypnosis",
			.artistID=10000168,
			.artistName="whitegavriel",
			.size=9.67,
			.videoID="",
			.youtubeChannelID="",
			.isVerified=true,
			.songPriority=0,
			.link="https%3A%2F%2Faudio.ngfiles.com%2F1272000%2F1272705_Windows96---Hypnosis.mp3%3Ff1703190904"
		} },
		{ 10, 9999, 0 },
		{ "f3b3c99922de38105071e6def6db2eae92a1ef9f" }
	};

	REQUIRE(!parsed.isErr());

	const auto& unwrapped = parsed.unwrap();

	REQUIRE_THAT(unwrapped.levels, Catch::Matchers::Equals(expected.levels));
	REQUIRE_THAT(unwrapped.creators, Catch::Matchers::Equals(expected.creators));
	REQUIRE(unwrapped.songs.size() > 0);
	REQUIRE_THAT(unwrapped.songs, Catch::Matchers::Equals(expected.songs));
	REQUIRE(unwrapped.page == expected.page);
	REQUIRE_THAT(unwrapped.hash, Catch::Matchers::Equals(expected.hash));
}

TEST_CASE("Malformed LevelResponse Data 1") {
	const auto parsed = rtrp::RtResponseParser::parseLevelResponse("akksjdkasfbasjn");

	REQUIRE(parsed.isErr());

	REQUIRE_THROWS_MATCHES(parsed.unwrap(), std::runtime_error, Catch::Matchers::Message("Tried unwrapping an erroneous Result<T>!"));
}

TEST_CASE("Malformed LevelResponse Data 2") {
	const auto parsed = rtrp::RtResponseParser::parseLevelResponse("");

	REQUIRE(parsed.isErr());

	REQUIRE_THROWS_MATCHES(parsed.unwrap(), std::runtime_error, Catch::Matchers::Message("Tried unwrapping an erroneous Result<T>!"));
}


TEST_CASE("Malformed LevelResponse Data 3") {
	const auto parsed = rtrp::RtResponseParser::parseLevelResponse(MALFORMED_SEARCH_RESPONSE);

	REQUIRE(parsed.isErr());

	REQUIRE_THROWS_MATCHES(parsed.unwrap(), std::runtime_error, Catch::Matchers::Message("Tried unwrapping an erroneous Result<T>!"));
}
