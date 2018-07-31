#pragma once
#include <Siv3D.hpp>
#include <vector>

class SoundManager
{
private:
	std::vector<Sound> sound_array;
	static float master_volume, se_volume, bgm_volume;

public:
	SoundManager();
	~SoundManager();

	void Load(String);
	void Load(String, int i);
	void Play(int i);
	void PlayLoop(int i);
	void Stop(int i);
	void AllStor();

	//çƒê∂íÜtrue
	bool State(int i);

	static void SetMasterVolume(float f) { master_volume = f; }
	static void SetSEVolume(float f) { se_volume = f; }
	static void SetBGMVolume(float f) { bgm_volume = f; }
};

