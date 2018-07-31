#pragma once
#include "MyVec.h"

class MyCircle : public MyVec
{
protected:
	float radius;
	Color main_color, font_color;
	Font font;
	std::string text;

public:
	MyCircle();
	~MyCircle();
	void Initialize(float, float, float);
	void Draw();
	void SetColor(int i) { main_color = i; }
	void SetColor(Color c) { main_color = c; }
	void SetColor(int r, int g, int b) { main_color = Color(r, g, b); }
	
	Color GetColor() { return main_color; }
	float GetRadius() { return radius; }

	//•¶ŽšŠÖŒW
	void SetFontColor(Color c) { font_color = c; }
	void SetFontColor(int r, int g, int b) { font_color = Color(r, g, b); }
	void SetFontSize(float size) { font = Font(size); }
	void SetFontText(std::string s) { text = s; }
	void SetFontAll(std::string s, float size, Color c);

	std::string GetStr() { return text; }

	friend bool CircleHitCheck(MyCircle, MyCircle);
};

//‰~‚Ì“–‚½‚è”»’è
bool CircleHitCheck(MyCircle, MyCircle);