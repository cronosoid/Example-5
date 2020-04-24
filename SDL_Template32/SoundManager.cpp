#include "SoundManager.h"

SoundManager* SoundManager::s_pInstance = NULL;

SoundManager::SoundManager()
{
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager()
{
	Mix_CloseAudio();
}

bool SoundManager::load(std::string filename, std::string id, sound_type type)
{
	if (type == SOUND_MUSIC)
	{
		Mix_Music* pMusic = Mix_LoadMUS(filename.c_str());

		if (pMusic == 0)
		{
			printf("Could not load music: ERROR - %s\n", Mix_GetError());
			return false;
		}

		m_music[id] = pMusic;
		return true;
	}
	else if (type == SOUND_SFX)
	{
		Mix_Chunk* pChunk = Mix_LoadWAV(filename.c_str());
		if (pChunk == 0)
		{
			printf("Could not load SFX: ERROR - %s\n", Mix_GetError());
			return false;
		}
		m_sfxs[id] = pChunk;
		return true;
	}

	return false;
}


void SoundManager::playMusic(std::string id, int loop)
{
	Mix_PlayMusic(m_music[id], loop);
}

void SoundManager::InitAll()
{

	if (!SoundManager::Instance()->load("pew.wav", "pew", SOUND_SFX))
	{
		printf("SFX LOAD FAILED\n");
	}

	if (!SoundManager::Instance()->load("music.ogg", "music", SOUND_MUSIC))
	{
		printf("MUSIC LOAD FAILED\n");
	}
}

void SoundManager::IncreaseMasterVolume()
{
	IncreaseMusicVolume();
	IncreaseSFXVolume();
}
void SoundManager::DecreaseMasterVolume()
{
	DecreaseMusicVolume();
	DecreaseSFXVolume();
}

void SoundManager::IncreaseMusicVolume()
{
	if (masterVolume + musicVolumeOffset < MIX_MAX_VOLUME)
	{
		Mix_VolumeMusic(masterVolume + ++musicVolumeOffset);
		printf("Master: %i | Music: %i | SFX: %i\n", masterVolume, masterVolume + musicVolumeOffset, masterVolume + sfxVolumeOffset);
	}
	else
	{
		printf("Already at max volume");
	}
}

void SoundManager::DecreaseMusicVolume()
{
	if (masterVolume + musicVolumeOffset > 0)
	{
		Mix_VolumeMusic(masterVolume + --musicVolumeOffset);
		printf("Master: %i | Music: %i | SFX: %i\n", masterVolume, masterVolume + musicVolumeOffset, masterVolume + sfxVolumeOffset);
	}
	else
	{
		printf("Already at 0 volume");
	}
}




void SoundManager::IncreaseSFXVolume()
{
	if (masterVolume + sfxVolumeOffset < MIX_MAX_VOLUME)
	{
		Mix_Volume(0, masterVolume + ++sfxVolumeOffset);
		printf("Master: %i | Music: %i | SFX: %i\n", masterVolume, masterVolume + musicVolumeOffset, masterVolume + sfxVolumeOffset);
	}
	else
	{
		printf("Already at max volume");
	}
}

void SoundManager::DecreaseSFXVolume()
{
	if (masterVolume + sfxVolumeOffset > 0)
	{
		Mix_Volume(0, masterVolume + --sfxVolumeOffset);
		printf("Master: %i | Music: %i | SFX: %i\n", masterVolume, masterVolume + musicVolumeOffset, masterVolume + sfxVolumeOffset);
	}
	else
	{
		printf("Already at 0 volume");
	}

}


void SoundManager::playSound(std::string id, int loop)
{
	Mix_PlayChannel(-1, m_sfxs[id], loop);
}
