#ifndef __SoundManager__
#define __SoundManager__

#include <map>
#include <string>
#include "SDL_mixer.h"


enum sound_type
{
	SOUND_MUSIC = 0,
	SOUND_SFX = 1
};

class SoundManager
{


private:

	static SoundManager* s_pInstance;

	std::map<std::string, Mix_Chunk*> m_sfxs;
	std::map<std::string, Mix_Music*> m_music;

	SoundManager();
	~SoundManager();

	SoundManager(const SoundManager&) {};
	SoundManager& operator=(const SoundManager&) {};

	int masterVolume = MIX_MAX_VOLUME / 2;
	int sfxVolumeOffset = 0;
	int musicVolumeOffset = 0;

public:

	static SoundManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new SoundManager();
		}

		return s_pInstance;
	}

	bool load(std::string filename, std::string id, sound_type type);

	void playSound(std::string id, int loop);
	void playMusic(std::string id, int loop);
	void InitAll();
	void IncreaseMasterVolume();
	void DecreaseMasterVolume();
	void IncreaseMusicVolume();
	void DecreaseMusicVolume();
	void IncreaseSFXVolume();
	void DecreaseSFXVolume();
};



#endif /* defined(__SoundManager__) */