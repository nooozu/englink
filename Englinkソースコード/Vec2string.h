#pragma once
#include <Siv3D.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Vec2string
{
private:
	int row, col;
	std::vector<std::vector<std::string>> s_array;

	bool InRange(int r, int c);

public:
	Vec2string();
	Vec2string(const char* file_name, char split = ',');
	~Vec2string();
	void Load(const char* file_name, char split = ',');
	void Save(const char* file_name);

	void Draw();
	void InputCell(std::string s, int r, int c);
	std::string GetCell(int r, int c);
	int GetRow() { return row; }
	int GetCol() { return col; }

	void AddCol();
};

