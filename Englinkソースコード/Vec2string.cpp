#include "Vec2string.h"

Vec2string::Vec2string()
{
	row = 0, col = 0;
}

Vec2string::Vec2string(const char* file_name, char split)
{
	Load(file_name, split);
}

Vec2string::~Vec2string()
{
}

bool Vec2string::InRange(int r, int c)
{
	if (r > -1 && r < row && c > -1 && c < col) {
		return true;
	}
	else {
		return false;
	}
}

void Vec2string::Load(const char* file_name, char split)
{
	std::ifstream ifs(file_name);
	if (!ifs) {
		Println(L"ファイルの読み込みに失敗しました。");
		return;
	}

	s_array.clear();

	int ir = 0, ic = 0;
	std::string str;

	//行と列を数える
	ir = 0;
	while (getline(ifs, str)) {
		std::string token;
		std::istringstream stream(str);
		ic = 0;
		while (getline(stream, token, split)) {
			ic++;
		}
		ir++;
	}
	
	row = ir;
	col = ic;

	//配列を拡張
	s_array.resize(row);
	for (int i = 0; i < row; i++) {
		s_array[i].resize(col);
	}

	std::ifstream ifs2(file_name);

	//csvのデータを配列に格納
	ir = 0;
	while (getline(ifs2, str)) {
		std::string token;
		std::istringstream stream(str);
		ic = 0;
		while (getline(stream, token, split)) {
			s_array[ir][ic] = token;
			ic++;
		}
		ir++;
	}
}

void Vec2string::Save(const char* file_name)
{
	std::ofstream ofs(file_name);

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			ofs << s_array[r][c];
			if (c < col - 1) {
				ofs << ",";
			}
		}
		ofs << std::endl;
	}
}

void Vec2string::InputCell(std::string s, int r, int c)
{
	if (InRange(r, c)) {
		s_array[r][c] = s;
	}
	else {
		Println(L"範囲外です。");
	}
}

std::string Vec2string::GetCell(int r, int c)
{
	if (InRange(r, c)) {
		return s_array[r][c];
	}
	else {
		return "";
	}
}

void Vec2string::Draw()
{
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			Println(Widen(s_array[r][c]));
		}
	}
}

void Vec2string::AddCol() 
{
	std::vector<std::vector<std::string>> backup;
	int current_row, current_col;

	current_row = row + 1;
	current_col = col;

	//バックアップの拡張
	backup.resize(current_row);
	for (int r = 0; r < current_row; r++) {
		backup[r].resize(current_col);
	}

	//初期化
	for (int r = 0; r < current_row; r++) {
		for (int c = 0; c < current_col; c++) {
			backup[r][c] = "none";
		}
	}

	//元のデータのコピー
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			backup[r][c] = s_array[r][c];
		}
	}

	//元のデータ消去
	s_array.clear();

	//元のデータを拡張
	s_array.resize(current_row);
	for (int r = 0; r < current_row; r++) {
		s_array[r].resize(current_col);
	}

	//元のデータに代入
	for (int r = 0; r < current_row; r++) {
		for (int c = 0; c < current_col; c++) {
			s_array[r][c] = backup[r][c];
		}
	}

	row = current_row;
	col = current_col;
}