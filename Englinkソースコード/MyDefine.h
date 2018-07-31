#pragma once

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT  720
#define SCREEN_CENTER_X (SCREEN_WIDTH / 2)
#define SCREEN_CENTER_Y	(SCREEN_HEIGHT / 2)

#define FIELD_LEFT     0
#define FIELD_RIGHT    SCREEN_WIDTH
#define FIELD_TOP      (SCREEN_HEIGHT / 4)
#define FIELD_BOTTOM   SCREEN_HEIGHT

#define PI 3.14159265359
#define DEG_TO_RAD(x) (x * PI / 180)
#define RAD_TO_DEG(x) (x * 180 / PI)

#define POW2(x) ((x) * (x))

//-----------------COLOR-----------------
//デフォルト
#define COLOR_DEFAULT_FONT      42,42,42
#define COLOR_DEFAULT_CIRCLE    220,196,186   

//タイトル画面
#define COLOR_TITLE_BACKGROUND  17,91,101
#define COLOR_TITLE_FONT        41,41,41
#define COLOR_TITLE_BUTTON      215,196,187

//メニュー画面
#define COLOR_MENU_BACKGROUND   95,147,149
#define COLOR_MENU_FONT         33,33,33
#define COLOR_MENU_CIRCLE       220,196,186

//設定画面
#define COLOR_CONFIG_BACKGROUND 18,57,67
#define COLOR_CONFIG_CIRCLE     215,196,187
#define COLOR_CONFIG_FONT       42,42,42

//ゲーム画面（練習）
#define COLOR_GAME_BACKGROUND1  16,91,99
#define COLOR_GAME_BACKGROUND2  255,250,213
#define COLOR_GAME_FONT         42,42,42
#define COLOR_GAME_LINE         25,25,25
//ゲーム画面（試験）

//ランキング画面
#define COLOR_RANKING_BACKGROUND 111,203,167
#define COLOR_RANKING_FONT       219,196,186
#define COLOR_RANKING_CIRCLE1    40,37,68
#define COLOR_RANKING_CIRCLE2    247,97,78
#define COLOR_RANKING_CIRCLE3    118,137,105

//リザルト画面
#define COLOR_RESULT_BACKGROUND 255,250,213
#define COLOR_RESULT_CIRCLE     18,57,67