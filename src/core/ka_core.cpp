//Copyright(C) 2026 Lost Empire Entertainment
//This program comes with ABSOLUTELY NO WARRANTY.
//This is free software, and you are welcome to redistribute it under certain conditions.
//Read LICENSE.md for more information.

#include <csignal>

#include "log_utils.hpp"

#include "core/ka_core.hpp"

using KalaHeaders::KalaLog::Log;
using KalaHeaders::KalaLog::LogType;
using KalaHeaders::KalaLog::TimeFormat;
using KalaHeaders::KalaLog::DateFormat;

#if defined(KLIN_ANY)
using std::raise;
#endif

namespace KalaAudio::Core
{
	//The ID that is bumped by every object when it needs a new ID
	static u32 globalID{};

	void KalaAudioCore::SetGlobalID(u32 newID) { globalID = newID; }
	u32 KalaAudioCore::GetGlobalID() { return globalID; }

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

#if defined(KWIN_ANY)
		__debugbreak();
#else
		raise(SIGTRAP);
#endif
	}
}