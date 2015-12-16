//////////////////////////////////////////////////////////////
// Project: Student Graphics Engine
// Author: Ben Odom
//////////////////////////////////////////////////////////////

#include "GameLoop.h"

int wmain()
{
	Vectors<double> Scalar1(5);
	Vectors<double> Scalar2(8);
	Vectors<double> Vec2D1(5, 10);
	Vectors<double> Vec2D2(6, 8);
	Vectors<double> Vec3D1(7, 10, 16);
	Vectors<double> Vec3D2(8, 2, 11);
	Vectors<double> Vec4D1(7, 10, 16, 12);
	
	Vectors<int> VecHex;
	Vectors<int> RGBA;

	double fRadian = 3.4;
	double fDegrees = 23;
	double fEmpty;

	cout << "Overloaded addition operator with scalar values:" << endl;
	Vectors<double> Scalar = Scalar1 + Scalar2;
	cout << Scalar.tX << "\n\n";

	cout << "Overloaded subtraction operator with scalar values:" << endl;
	Scalar = Scalar1 - Scalar2;
	cout << Scalar.tX << "\n\n";

	cout << "Overloaded multiplication operator with scalar values:" << endl;
	Scalar = Scalar1 * Scalar2;
	cout << Scalar.tX << "\n\n";

	cout << "Linear Interpolation of scalar values:" << endl;
	Scalar = LinearInterpolation(Scalar1, Scalar2);
	cout << Scalar.tX << "\n\n";

	cout << "Overloaded addition operator with 2D Vectors:" << endl;
	Vectors<double> Vec2D = Vec2D1 + Vec2D2;
	cout << Vec2D.tX << ", " << Vec2D.tY << "\n\n";

	cout << "Overloaded subtraction operator with 2D Vectors:" << endl;
	Vec2D = Vec2D1 - Vec2D2;
	cout << Vec2D.tX << ", " << Vec2D.tY << "\n\n";

	cout << "Overloaded multiplication operator with 2D Vectors:" << endl;
	Vec2D = Vec2D1 * Vec2D2;
	cout << Vec2D.tX << ", " << Vec2D.tY << "\n\n";

	cout << "2D Dot Product using overloaded operators:" << endl;
	Vec2D.tDot = (Vec2D1.tX * Vec2D2.tX + Vec2D1.tY * Vec2D2.tY);
	cout << Vec2D.tDot << "\n\n";

	cout << "2D Dot Product with a function:" << endl;
	Vec2D = DotProduct2D(Vec2D1, Vec2D2);
	cout << Vec2D.tDot << "\n\n";

	cout << "Magnitude function for a 2D Vector:" << endl;
	Vec2D = Magnitude2D(Vec2D1);
	cout << Vec2D.tRoot << "\n\n";

	cout << "Normalization of a 2D Vector:" << endl;
	Vec2D = Normalizing2D(Vec2D1);
	cout << Vec2D.tX << ", " << Vec2D.tY << "\n\n";

	cout << "Linear Interpolation of 2D Vectors:" << endl;
	Vec2D = LinearInterpolation(Vec2D1, Vec2D2);
	cout << Vec2D.tX << ", " << Vec2D.tY << "\n\n";

	cout << "Overloaded addition operator with 3D Vectors:" << endl;
	Vectors<double> Vec3D = Vec3D1 + Vec3D2;
	cout << Vec3D.tX << ", " << Vec3D.tY << ", " << Vec3D.tZ << "\n\n";

	cout << "Overloaded subtraction operator with 3D Vectors:" << endl;
	Vec3D = Vec3D1 - Vec3D2;
	cout << Vec3D.tX << ", " << Vec3D.tY << ", " << Vec3D.tZ << "\n\n";

	cout << "Overloaded multiplication operator with 3D Vectors:" << endl;
	Vec3D = Vec3D1 * Vec3D2;
	cout << Vec3D.tX << ", " << Vec3D.tY << ", " << Vec3D.tZ << "\n\n";

	cout << "3D Dot Product using overloaded operators:" << endl;
	Vec3D.tDot = (Vec3D1.tX * Vec3D2.tX + Vec3D1.tY * Vec3D2.tY + Vec3D1.tZ * Vec3D2.tZ);
	cout << Vec3D.tDot << "\n\n";

	cout << "3D Dot Product with a function:" << endl;
	Vec3D = DotProduct3D(Vec3D1, Vec3D2);
	cout << Vec3D.tDot << "\n\n";

	cout << "3D Cross Product using overloaded operators:" << endl;
	Vec3D = { (Vec3D1.tY * Vec3D2.tZ - Vec3D1.tZ * Vec3D2.tY), (Vec3D1.tZ * Vec3D2.tX - Vec3D1.tX * Vec3D2.tZ), (Vec3D1.tX * Vec3D2.tY - Vec3D1.tY * Vec3D2.tX) };
	cout << Vec3D.tX << ", " << Vec3D.tY << ", " << Vec3D.tZ << "\n\n";

	cout << "3D Cross Product with a function:" << endl;
	Vec3D = CrossProduct3D(Vec3D1, Vec3D2);
	cout << Vec3D.tX << ", " << Vec3D.tY << ", " << Vec3D.tZ << "\n\n";

	cout << "Magnitude function for a 3D Vector:" << endl;
	Vec3D = Magnitude3D(Vec3D1);
	cout << Vec3D.tRoot << "\n\n";

	cout << "Normalization function of a 3D Vector:" << endl;
	Vec3D = Normalizing3D(Vec3D1);
	cout << Vec3D.tX << ", " << Vec3D.tY << ", " << Vec3D.tZ << "\n\n";

	cout << "Linear Interpolation of 3D Vectors:" << endl;
	Vec3D = LinearInterpolation(Vec3D1, Vec3D2);
	cout << Vec3D.tX << ", " << Vec3D.tY << ", " << Vec3D.tZ << "\n\n";

	cout << "Normalization of a 4D Vector:" << endl;
	Vectors<double> Vec4D = Normalizing4D(Vec4D1);
	cout << Vec4D.tX << ", " << Vec4D.tY << ", " << Vec4D.tZ << ", " << Vec4D.tA << "\n\n";

	cout << "Conversion of a hexadecimal to a RGBA value represented as a 4D Vector: \n#FF3366" << endl;
	RGBA = VecHex.HexCode("#FF3366");
	cout << RGBA.tX << ", " << RGBA.tY << ", " << RGBA.tZ << ", " << RGBA.tA << "\n\n";

	cout << "Conversion from radians to degrees:" << endl;
	fEmpty = ToDegrees(fRadian);
	cout << fEmpty << "\n\n";

	cout << "Conversion from degrees to radians:" << endl;
	fEmpty = ToRadians(fDegrees);
	cout << fEmpty << "\n\n";

	Graphics::Init();

	Graphics::NewWindow({ 1600, 900 }, false, { 1600, 900 }, "Graphics Engine");

	GameLoop oGameLoop;

	oGameLoop.Loop();

	Graphics::Quit();

	return 0;
}