//Copyright(C) 2026 Lost Empire Entertainment
//This program comes with ABSOLUTELY NO WARRANTY.
//This is free software, and you are welcome to redistribute it under certain conditions.
//Read LICENSE.md for more information.

#include <string>
#include <csignal>

#include "KalaHeaders/log_utils.hpp"

#include "core/ka_core.hpp"
#include "core/ka_audio.hpp"

using KalaHeaders::KalaLog::Log;
using KalaHeaders::KalaLog::LogType;

using std::to_string;
using std::raise;

namespace KalaAudio::Core
{
	//The ID that is bumped by every object when it needs a new ID
	static u32 globalID{};

	void KalaAudioCore::SetGlobalID(u32 newID) { globalID = newID; }
	u32 KalaAudioCore::GetGlobalID() { return globalID; }

	void KalaAudioCore::CleanAllWindowResources(u32 windowID)
	{
		Log::Print(
			"Cleaning resources for window '" + to_string(windowID) + "'.",
			"KALAAUDIO",
			LogType::LOG_INFO);
	}
	
	void KalaAudioCore::CleanAllResources()
	{
		Log::Print(
			"Cleaning all KalaAudio resources.",
			"KALAAUDIO",
			LogType::LOG_INFO);
			
		if (Audio::IsInitialized()) Audio::Shutdown();
		
		AudioPlayer::GetRegistry().RemoveAllContent();
	}

	void KalaAudioCore::ForceClose(
		const string& target,
		const string& reason)
	{
		Log::Print(
			"\n================"
			"\nFORCE CLOSE"
			"\n================\n",
			true);

		Log::Print(
			reason,
			target,
			LogType::LOG_ERROR,
			2,
			true,
			TimeFormat::TIME_NONE,
			DateFormat::DATE_NONE);

#ifdef _WIN32
		__debugbreak();
#else
		raise(SIGTRAP);
#endif
	}
}