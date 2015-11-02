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

//int iX = 800;
//int iY = 450;
int iRadius = 200;
int iQuality = 50;
int iRed = 0;
int iGreen = 255;
int iBlue = 255;
int iAlpha = 150;

void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas

	Graphics::DrawRect({ 400, 400 }, { 450, 400 }, { 160, 65, 255, 255 });
	Graphics::DrawRect({ 250, 500 }, { 1000, 200 }, { 0, 255, 0, 255 });

	Graphics::DrawLine({ 10, 10 }, { 100, 100 }, { 255, 255, 255, 255 });
	Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

	Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
	Graphics::DrawCircle({ 800, 450 }, 200, 50, { 0, 255, 255, 150 });
}

struct System::Point2D<int> Directions;
struct System::Size2D<int> Sizes;
struct System::Color<int> Shades;

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	
	switch (ac_sdlSym)
	{
	case SDLK_w: Directions.Y -= 5; break;
	case SDLK_s: Directions.Y += 5; break;
	case SDLK_d: Directions.X += 5; break;
	case SDLK_a: Directions.X -= 5; break;
	case SDLK_UP: Sizes.W += 5; break;
	case SDLK_DOWN: Sizes.H -= 5; break;
	case SDLK_RIGHT: iQuality += 1; break;
	case SDLK_LEFT: iQuality -= 1; break;
	case SDLK_HOME: iRed += 1; break;
	case SDLK_BACKSPACE: iRed -= 1; break;
	case SDLK_PAGEUP: iGreen += 1; 	break;
	case SDLK_INSERT: iGreen -= 1; break;
	case SDLK_END: iBlue += 1; break;
	case SDLK_RETURN: iBlue -= 1; break;
	case SDLK_PAGEDOWN: iAlpha += 1; break;
	case SDLK_DELETE: iAlpha -= 1; break;
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n",SDL_GetKeyName(ac_sdlSym)); break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	case SDLK_w: Directions.Y = 450; break;
	case SDLK_s: Directions.Y = 450; break;
	case SDLK_d: Directions.X = 800; break;
	case SDLK_a: Directions.X = 800; break;
	case SDLK_UP: iRadius = 200; break;
	case SDLK_DOWN: iRadius = 200; break;
	case SDLK_RIGHT: iQuality = 50; break;
	case SDLK_LEFT: iQuality = 50; break;
	case SDLK_HOME: iRed = 0; break;
	case SDLK_BACKSPACE: iRed = 0; break;
	case SDLK_PAGEUP: iGreen = 255; break;
	case SDLK_INSERT: iGreen = 255; break;
	case SDLK_END: iBlue = 255; break;
	case SDLK_RETURN: iBlue = 255; break;
	case SDLK_PAGEDOWN: iAlpha = 150; break;
	case SDLK_DELETE: iAlpha = 150; break;
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
