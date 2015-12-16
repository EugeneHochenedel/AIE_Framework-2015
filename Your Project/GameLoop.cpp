#include "GameLoop.h"
#include <time.h>

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

double iSpeed = 1;

System::Point2D<double> Ring1{ 52, 35 };
System::Point2D<double> Ring2{ 86, 58 };
System::Point2D<double> Ring3{ 120, 81 };
System::Point2D<double> Ring4{ 154, 104 };
System::Point2D<double> Ring5{ 188, 127 };
System::Point2D<double> Ring6{ 222, 150 };
System::Point2D<double> Ring7{ 256, 173 };
System::Point2D<double> Ring8{ 290, 196 };
System::Point2D<double> Ring9{ 324, 219};
System::Point2D<double> Ring10{ 358, 242 };
Vectors<int> ColorHex;
Vectors<int> RGBAvalues = ColorHex.HexCode("#FF3366");

void GameLoop::Update()
{
	
	if (Ring1.X < 1547 && Ring1.Y == 35)
	{
		Ring1.X += iSpeed;
	}
	else if (Ring1.X >= 1547 && Ring1.Y < 862)
	{
		Ring1.Y += iSpeed;
	}
	else if (Ring1.X > 52 && Ring1.Y >= 862)
	{
		Ring1.X -= iSpeed;
	}
	else if (Ring1.X <= 52 && Ring1.Y > 35)
	{
		Ring1.Y -= iSpeed + 10;
	}
	
	if (Ring2.X < 1513 && Ring2.Y == 58)
	{
		Ring2.X += iSpeed;
	}
	else if (Ring2.X >= 1513 && Ring2.Y < 839)
	{
		Ring2.Y += iSpeed;
	}
	else if (Ring2.X > 86 && Ring2.Y >= 839)
	{
		Ring2.X -= iSpeed;
	}
	else if (Ring2.X <= 86 && Ring2.Y > 58)
	{
		Ring2.Y -= iSpeed;
	}

	if (Ring3.X < 1479 && Ring3.Y == 81)
	{
		Ring3.X += iSpeed;
	}
	else if (Ring3.X >= 1479 && Ring3.Y < 816)
	{
		Ring3.Y += iSpeed;
	}
	else if (Ring3.X > 120 && Ring3.Y >= 816)
	{
		Ring3.X -= iSpeed;
	}
	else if (Ring3.X <= 120 && Ring3.Y > 81)
	{
		Ring3.Y -= iSpeed;
	}

	if (Ring4.X < 1445 && Ring4.Y == 104)
	{
		Ring4.X += iSpeed;
	}
	else if (Ring4.X >= 1445 && Ring4.Y < 793)
	{
		Ring4.Y += iSpeed;
	}
	else if (Ring4.X > 154 && Ring4.Y >= 793)
	{
		Ring4.X -= iSpeed;
	}
	else if (Ring4.X <= 154 && Ring4.Y > 104)
	{
		Ring4.Y -= iSpeed;
	}
}
void GameLoop::LateUpdate()
{

}
System::Size2D<double> Rect1Size{ 100, 50 };
System::Point2D<double> Rect1Min{ 500, 300 };
System::Point2D<double> Rect1Max = Rect1Min + Rect1Size;
System::Size2D<double> Rect2Size{ 145, 150 };
System::Point2D<double> Rect2Min{ 500, 500 };
System::Point2D<double> Rect2Max = Rect2Min + Rect2Size;
System::Point2D<double> Middle{ 800, 450 };
System::Point2D<float> Point{ 5, 5 };
void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas
	for (int iX = 1.0; iX <= 1599; iX += 34)	
	{
		Graphics::DrawLine({ iX, 1 }, { iX, 897}, { 153, 255, 51, 255 });
	}
	for (int iY = 0; iY <= 897; iY += 23)
	{
		Graphics::DrawLine({ 1, iY }, { 1599, iY }, { 153, 255, 51, 255 });
	}

	Graphics::DrawRect((Rect1Min), { Rect1Size }, { 160, 65, 255, 255 });
	Graphics::DrawRect((Rect2Min), { Rect2Size }, { 255, 255, 255, 255 });

	Graphics::DrawPoint({ Point }, { 255, 255, 255, 255 });

	//Graphics::DrawRing({ Ring1 }, 11, 25, { 255, 255, 255, 255 });
	/*Graphics::DrawRing({ Ring2 }, 11, 25, { 255, 255, 255, 255 });
	Graphics::DrawRing({ Ring3 }, 11, 25, { 255, 255, 255, 255 });
	Graphics::DrawRing({ Ring4 }, 11, 25, { 255, 255, 255, 255 });
	Graphics::DrawRing({ Ring5 }, 11, 25, { 255, 255, 255, 255 });
	Graphics::DrawRing({ Ring6 }, 11, 25, { 255, 255, 255, 255 });
	Graphics::DrawRing({ Ring7 }, 11, 25, { 255, 255, 255, 255 });
	Graphics::DrawRing({ Ring8 }, 11, 25, { 255, 255, 255, 255 });
	Graphics::DrawRing({ Ring9 }, 11, 25, { 255, 255, 255, 255 });
	Graphics::DrawRing({ Ring10 }, 11, 25, { 255, 255, 255, 255 });*/

	//Graphics::DrawCircle({ Middle }, 200, 50, { RGBAvalues.tX, RGBAvalues.tY, RGBAvalues.tZ, RGBAvalues.tA });

	if (Rect2Min.X <= Rect1Max.X && Rect2Min.Y <= Rect1Max.Y && Rect2Max.X >= Rect1Min.X && Rect2Max.Y >= Rect1Min.Y)
	{
		Graphics::DrawRing({ 800, 500 }, 11, 25, { 255, 255, 255, 255 });
		cout << "Collision! " << clock() << endl;
	}
	else
	{
		Graphics::DrawCircle({ 800, 500 }, 11, 25, { 153, 128, 51, 255 });
	}
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	
	switch (ac_sdlSym)
	{
	case SDLK_w: Middle.Y -= 5; break;
	case SDLK_s: Middle.Y += 5; break;
	case SDLK_d: Middle.X += 5; break;
	case SDLK_a: Middle.X -= 5; break;
	case SDLK_LEFT: Rect2Min.X -= 5; break;
	case SDLK_RIGHT: Rect2Min.X += 5; break;
	case SDLK_UP: Rect2Min.Y -= 5; break;
	case SDLK_DOWN: Rect2Min.Y += 5; break;

	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n",SDL_GetKeyName(ac_sdlSym)); break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	/*case SDLK_UP: if (iRingY >= 35)
	{
		iRingY -= iSpeed;
	}; break;
	case SDLK_DOWN: while (iRingY <= 862)
	{
		iRingY += iSpeed;
	}; break;*/
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
