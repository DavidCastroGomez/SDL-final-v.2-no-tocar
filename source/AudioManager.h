#pragma once
#include <SDL_mixer.h>
#include <unordered_map>
#include <string>
#include <cassert>

#define AM AudioManager::GetInstance()

class AudioManager {
public:
	static AudioManager* GetInstance();

	void LoadSFX(std::string name);
	void UnloadSFX(std::string name);
	void PlaySFX(std::string name, int repetitions);

	void LoadMusic(std::string name);
	void UnloadMusic(std::string name);
	void PlayMusic(std::string name);

	void SetMuted(bool isMuted);
	bool GetMuted();
private:
	std::unordered_map<std::string, Mix_Chunk*> sfx;
	std::unordered_map<std::string, Mix_Music*> music;

	bool isMuted;

	static AudioManager* instance;
	AudioManager();
	AudioManager(const AudioManager&) = delete;
	AudioManager& operator=(const AudioManager&) = delete;
};