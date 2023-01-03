#include "AudioManager.h"

AudioManager* AudioManager::instance = nullptr;

AudioManager::AudioManager() {
	assert(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != -1);
	isMuted = false;
}

AudioManager* AudioManager::GetInstance() {
	if (instance == nullptr) {
		instance = new AudioManager();
	}
	return instance;
}

void AudioManager::LoadSFX(std::string name) {
	assert(sfx.find(name) == sfx.end());

	Mix_Chunk* loadedChunk = Mix_LoadWAV(("resources/audio/sfx/" + name + ".wav").c_str());

	assert(loadedChunk != nullptr);

	sfx.emplace(name, loadedChunk);
}

void AudioManager::UnloadSFX(std::string name)
{
	assert(sfx.find(name) != sfx.end());

	Mix_FreeChunk(sfx[name]);
	sfx.erase(name);
}

void AudioManager::PlaySFX(std::string name, int repetitions) {
	assert(sfx.find(name) != sfx.end());
	Mix_PlayChannel(-1, sfx[name], repetitions);
}

void AudioManager::LoadMusic(std::string name) {
	assert(music.find(name) == music.end());

	Mix_Music* loadedMusic = Mix_LoadMUS(("resources/audio/music/" + name + ".wav").c_str());

	assert(loadedMusic != nullptr);

	music.emplace(name, loadedMusic);
}

void AudioManager::UnloadMusic(std::string name)
{
	assert(music.find(name) != music.end());

	Mix_FreeMusic(music[name]);
	music.erase(name);
}

void AudioManager::PlayMusic(std::string name)
{
	assert(music.find(name) != music.end());
	Mix_FadeInMusic(music[name], -1, 200);
}

void AudioManager::SetMuted(bool isMuted)
{
	if (isMuted)
	{
		if (this->isMuted)
			return;

		Mix_Volume(-1, 0);
		Mix_VolumeMusic(0);
		this->isMuted = true;
	}
	else
	{
		if (!this->isMuted)
			return;

		Mix_Volume(-1, MIX_MAX_VOLUME);
		Mix_VolumeMusic(0);
		this->isMuted = false;
	}
}

bool AudioManager::GetMuted()
{
	return isMuted;
}