//////////////////////////////////////////////////////////////
// Project: Student Graphics Engine
// Author: Ben Odom
//////////////////////////////////////////////////////////////

#include "GameLoop.h"

int wmain()
{
	Vectors<int> Vec1(5, 5);
	Vectors<int> Vec2(6, 8);
	Vectors<int> Vec(0, 0);
	Vec = Addition(Vec1, Vec2);
	cout << Vec.tX << ", " << Vec.tY << "\n\n";

	Graphics::Init();

	Graphics::NewWindow({ 1600, 900 }, false, { 1600, 900 }, "Graphics Engine");

	GameLoop oGameLoop;

	oGameLoop.Loop();

	Graphics::Quit();

	return 0;
}