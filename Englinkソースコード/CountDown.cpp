#include "CountDown.h"

CountDown::CountDown()
{
}

CountDown::~CountDown()
{

}

void CountDown::Initialize(float x_center, float y_center, float width)
{
	cx = x_center, cy = y_center;
	length = width;

	font = Font(30, Typeface::Medium, FontStyle::Outline);
	font.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 1.0));

	Reset();

	text = "3";
}

void CountDown::Update()
{
	if (!flag) {
		if (x < cx + length) {
			count++;
			x += 1.0;
			alpha = 255 * sin(PI * count / length);
			if (alpha == 255) {
				System::Sleep(400);
			}
		}

		if (alpha <= 1.0e-4) {
			if (text == "START") {
				flag = true;
			}
			else {
				switch (std::stoi(text)) {
				case 3:
					text = "2";
					break;
				case 2:
					text = "1";
					break;
				case 1:
					text = "START";
					break;
				}
			}

			Reset();
		}
	}
}

void CountDown::Draw()
{
	if (!flag) {
		font(Widen(text)).drawCenter(x, y, Color(255, 255, 255, alpha));
	}
}

void CountDown::Reset()
{
	x = cx - length / 2, y = cy;
	count = 0;
}

void CountDown::SetColor(Color m, Color s, float font_size, float frame_width)
{
	font = Font(font_size, Typeface::Medium, FontStyle::Outline);
	font.changeOutlineStyle(TextOutlineStyle(s, m, frame_width));
}