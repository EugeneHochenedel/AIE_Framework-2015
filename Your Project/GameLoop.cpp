#include "GameLoop.h"



void GameLoop::Loop()
{
	while (m_bRunning)
	{
		SDL_Event sdlEvent; // Will hold the next event to be parsed

		while (m_bRunning)
		{
			// Events get called one at a time, so if multiple things happen in one frame, they get parsed individually through 'SDL_PollEvent'
			// The next event to parse gets stored into 'sdlEvent', and then passed to the 'EventHandler' class which will call it's appropriate function here
			// 'SDL_PollEvent' returns 0 when there are no more events to parse
			while (SDL_PollEvent(&sdlEvent))
			{
				// Calls the redefined event function for the EventHandler class
				// Refer to its header file and cpp for more information on what each inherited function is capable of
				// and its syntax
				OnEvent(sdlEvent);
			}
			Update();

			LateUpdate();

			Draw();

			Graphics::Flip(); // Required to update the window with all the newly drawn content
		}
	}
}

void GameLoop::Update()
{

}
void GameLoop::LateUpdate()
{

}

System::Point2D<int> Middle{ 800, 450 };
System::Color<int> ColorCode{ 192, 192, 192, 150 };

void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas

	Graphics::DrawRect({ 400, 400 }, { 400, 400 }, { 160, 65, 255, 255 });
	Graphics::DrawRect({ 250, 500 }, { 1000, 200 }, { 0, 255, 0, 255 });

	Graphics::DrawLine({ 10, 10 }, { 100, 100 }, { 255, 255, 255, 255 });
	Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

	Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
	Graphics::DrawCircle({ Middle }, 200, 50, { ColorCode });
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	
	switch (ac_sdlSym)
	{
	case SDLK_w: Middle.Y -= 5; break;
	case SDLK_s: Middle.Y += 5; break;
	case SDLK_d: Middle.X += 5; break;
	case SDLK_a: Middle.X -= 5; break;
	case SDLK_HOME: ColorCode.Red += 1; break;
	case SDLK_END: ColorCode.Red -= 1; break;
	case SDLK_PAGEUP: ColorCode.Green += 1; 	break;
	case SDLK_PAGEDOWN: ColorCode.Green -= 1; break;
	case SDLK_BACKSPACE: ColorCode.Blue += 1; break;
	case SDLK_RETURN: ColorCode.Blue -= 1; break;
	case SDLK_INSERT: ColorCode.Alpha += 1; break;
	case SDLK_DELETE: ColorCode.Alpha -= 1; break;
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n",SDL_GetKeyName(ac_sdlSym)); break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	/*case SDLK_w: iY = 450; break;
	case SDLK_s: iY = 450; break;
	case SDLK_d: iX = 800; break;
	case SDLK_a: iX = 800; break;
	case SDLK_HOME: iRed = 192; break;
	case SDLK_END: iRed = 192; break;
	case SDLK_PAGEUP: iGreen = 192; 	break;
	case SDLK_PAGEDOWN: iGreen = 192; break;
	case SDLK_BACKSPACE: iBlue = 192; break;
	case SDLK_RETURN: iBlue = 192; break;
	case SDLK_INSERT: iAlpha = 150; break;
	case SDLK_DELETE: iAlpha = 150; break;*/
	default: break;
	}
}
void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop
}

GameLoop::GameLoop()
{
	m_bRunning = true;
}
GameLoop::~GameLoop()
{

}
