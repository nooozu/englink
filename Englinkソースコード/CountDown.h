#pragma once
#include <Siv3D.hpp>
#include "MyDefine.h"
#include <cmath>
#include <string>

class CountDown
{
private:
	bool flag;
	int count, alpha;
	float cx, cy, x, y, length;
	Font font;
	std::string text;

public:
	CountDown();
	~CountDown();
	void Initialize(float x_cen, float y_cen, float width);
	void Update();
	void Draw();
	void Reset();
	void SetColor(Color m, Color s, float font_size = 30.0, float frame_width = 1.0);

	bool GetFlag() { return flag; }
};

