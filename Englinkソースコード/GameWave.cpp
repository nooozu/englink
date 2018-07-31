#include "GameWave.h"

GameWave::GameWave(std::string s_e, std::string s_j)
{
	count = 0;
	clear_frame = 90;
	flag = false;
	clear = false;

	str_e = s_e, str_j = s_j;
	s_array = split(str_e, ' ');

	f_text = Font(30);

	dictionary.Load("data/Dictionary.csv");

	pBubble = new MyCircleRebound;
	for (int i = 0; i < s_array.size(); i++) {
		pBubble->Initialize(Random(FIELD_LEFT, FIELD_RIGHT), Random(FIELD_TOP, FIELD_BOTTOM), 40);
		pBubble->RandomMove();
		pBubble->SetColor(SelectColor(s_array[i]));
		pBubble->SetFontAll(s_array[i], 10, Color(0, 0, 0));
		b_array.push_back(*pBubble);
	}
	delete pBubble;
	pBubble = NULL;

	sound_mgr.Load(L"sound/play_SE01.mp3");
	sound_mgr.Load(L"sound/play_SE02.mp3");
	sound_mgr.Load(L"sound/play_SE03.mp3");
	sound_mgr.Load(L"sound/play_SE04.mp3");
	sound_mgr.Load(L"sound/play_SE05.mp3");
	sound_mgr.Load(L"sound/play_SE06.mp3");
	sound_mgr.Load(L"sound/play_SE07.mp3");
	sound_mgr.Load(L"sound/play_SE08.mp3");
	sound_mgr.Load(L"sound/ok1.mp3");
	sound_mgr.Load(L"sound/no.mp3");
}

GameWave::~GameWave()
{
	b_array.clear();
}

void GameWave::Update()
{
	emitter.Update();

	if (!flag) {
		for (int i = 0; i < b_array.size(); i++) {
			b_array[i].Update();

			for (int j = 0; j < b_array.size(); j++) {
				if (i != j) {
					//‰~“¯Žm‚ÌÕ“Ë
					Rebound(b_array[i], b_array[j]);
				}
			}

			if (b_array[i].GetButton()) {
				//³‰ð
				if (b_array[i].GetStr() == s_array[count]) {
					count++;
					sound_mgr.Play(count % 8);
					if (count >= s_array.size()) {
						flag = true;
						for (int i = 0; i < s_array.size(); i++) {
							emitter.CreateParticle(b_array[i].GetX(), b_array[i].GetY(), 15, b_array[i].GetColor());
						}
						sound_mgr.Play(8);
					}
				}
				//•s³‰ð
				else {
					sound_mgr.Play(9);
					count = 0;
				}
			}
		}
	}
	else {
		clear_frame--;
		if (clear_frame <= 0) {
			clear = true;
		}
	}
}

void GameWave::Draw()
{
	emitter.Draw();

	f_text(Widen(str_j)).draw(140, 60, Color(COLOR_GAME_BACKGROUND2));

	if (!flag) {
		//‰~‚Æ‰~‚ðŒq‚®ü
		for (int i = 1; i < count; i++) {
			Line({ b_array[i - 1].GetX(), b_array[i - 1].GetY() }, { b_array[i].GetX(), b_array[i].GetY() }).draw(3, Color(13,41,48));
		}
		//³‰ð‚µ‚½‰~‚Ì˜g
		for (int i = 0; i < count; i++) {
			Circle(b_array[i].GetX(), b_array[i].GetY(), b_array[i].GetRadius() + 3).drawFrame(1, 3, Color(13,41,48));
		}
		//‰~
		for (int i = 0; i < b_array.size(); i++) {
			b_array[i].Draw();
		}
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim)) {
		if (!item.empty()) {
			elems.push_back(item);
		}
	}
	return elems;
}

Color GameWave::SelectColor(std::string str)
{
	for (int i = 0; i < dictionary.GetRow(); i++) {
		if (str == dictionary.GetCell(i, 0)) {
			if (dictionary.GetCell(i, 1) == "‘ã–¼ŽŒ") {
				return Color(220, 158, 54);
			}
			else if (dictionary.GetCell(i, 1) == "“®ŽŒ") {
				return Color(189, 73, 50);
			}
			else if (dictionary.GetCell(i, 1) == "•›ŽŒ") {
				return Color(93, 174, 139);
			}
			else if (dictionary.GetCell(i, 1) == "‘O’uŽŒ") {
				return Color(70, 108, 149);
			}
			else if (dictionary.GetCell(i, 1) == "–¼ŽŒ") {
				return Color(128, 189, 219);
			}
			else if (dictionary.GetCell(i, 1) == "be“®ŽŒ") {
				return Color(44, 176, 117);
			}
			else if (dictionary.GetCell(i, 1) == "Œ`—eŽŒ") {
				return Color(255, 83, 13);
			}
			else if (dictionary.GetCell(i, 1) == "Š¥ŽŒ") {
				return Color(255, 52, 131);
			}
			else if (dictionary.GetCell(i, 1) == "Ž©“®ŽŒ") {
				return Color(191, 117, 36);
			}
			else if (dictionary.GetCell(i, 1) == "Šî”ŽŒ") {
				return Color(190, 219, 57);
			}
			else if (dictionary.GetCell(i, 1) == "•“®ŽŒ") {
				return Color(255, 133, 152);
			}
			else {
				return Color(255, 255, 255);
			}
		}
	}
	return Color(255, 255, 255);
}