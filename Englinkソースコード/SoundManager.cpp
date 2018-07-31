#include "SoundManager.h"

float SoundManager::se_volume = 0.5;
float SoundManager::bgm_volume = 0.1;
float SoundManager::master_volume = 0.3;

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
	sound_array.clear();
}

void SoundManager::Load(String s)
{
	sound_array.push_back(Sound(s));
}

void SoundManager::Load(String s, int i)
{
	if (i < sound_array.size()) {
		sound_array[i] = Sound(s);
	}
}

void SoundManager::Play(int i)
{
	if (i < sound_array.size()) {
		float vol = master_volume * se_volume;
		sound_array[i].setVolume(vol);
		sound_array[i].setLoop(false);
		sound_array[i].play();
	}
}

void SoundManager::PlayLoop(int i)
{
	if (i < sound_array.size()) {
		float vol = master_volume * bgm_volume;
		sound_array[i].setVolume(vol);
		sound_array[i].setLoop(true);
		sound_array[i].play();
	}
}

void SoundManager::Stop(int i)
{
	if (i < sound_array.size()) {
		sound_array[i].stop();
	}
}

void SoundManager::AllStor()
{
	for (int i = 0; i < sound_array.size(); i++) {
		sound_array[i].stop();
	}
}

bool SoundManager::State(int i)
{
	if (i < sound_array.size()) {
		// 曲の長さ（秒）
		int32 length = static_cast<int32>(sound_array[i].lengthSec());
		// 現在の再生位置（秒）
		int32 pos = static_cast<int32>(sound_array[i].streamPosSec());

		float current = (float)pos / length;
		
		PutText(pos, L"/",length);

		if (0.0 < current && current < 1.0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}