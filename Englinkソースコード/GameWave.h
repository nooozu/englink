#pragma once
#include "MyDefine.h"
#include "MyCircleRebound.h"
#include <vector>
#include "Vec2string.h"
#include "Emitter.h"
#include "SoundManager.h"

class GameWave
{
private:
	bool flag, clear;
	int count, clear_frame;

	Font f_text;
	std::string str_e, str_j;
	std::vector<std::string> s_array;

	MyCircleRebound* pBubble;
	std::vector<MyCircleRebound> b_array;

	Emitter emitter;
	Vec2string dictionary;

	SoundManager sound_mgr;

public:
	GameWave(std::string, std::string);
	~GameWave();
	void Update();
	void Draw();

	bool IsClear() { return clear; }
	int GetBubbleCount() { return s_array.size(); }

	Color SelectColor(std::string str);
};

std::vector<std::string> split(const std::string &s, char delim);