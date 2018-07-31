#include <Siv3D.hpp>
#include "SceneMgr.h"

void Main()
{
	Window::SetTitle(L"Englink");
	Window::Resize(1280, 720);

	SceneMgr scene_mgr;
	scene_mgr.Initialize();

	while (System::Update())
	{
		scene_mgr.Update();
		scene_mgr.Draw();
	}
}
