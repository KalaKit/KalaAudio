//Copyright(C) 2025 Lost Empire Entertainment
//This program comes with ABSOLUTELY NO WARRANTY.
//This is free software, and you are welcome to redistribute it under certain conditions.
//Read LICENSE.md for more information.

#include <string>

#include "KalaHeaders/log_utils.hpp"

#include "core/ka_core.hpp"
#include "core/ka_audio.hpp"

using KalaHeaders::KalaLog::Log;
using KalaHeaders::KalaLog::LogType;

using std::to_string;

namespace KalaAudio::Core
{
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
		
		AudioPlayer::registry.RemoveAllContent();
	}
}