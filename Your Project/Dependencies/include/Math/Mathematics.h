///////////////////////////////////
// File: Mathematics.h
// Author: Eugene Hochenedel
// Date Created: 12/1/15
///////////////////////////////////

#ifndef MATHEMATICS_H_
#define MATHEMATICS_H_

#include <iostream>
#include <cmath>
#include <string>

const double pi = 3.14159265358979323846;

using namespace std;

template<typename T>
class Vectors
{
public:
	Vectors(); //Constructs an empty vector
	Vectors(T); //Constructs a scalar
	Vectors(T, T); // Constructs 2D Vector
	Vectors(T, T, T); // Constructs 3D Vector
	Vectors(T, T, T, T); // Constructs 4D Vector

	T tX; //Sets up a variable for the first number of both 2D, 3D, and 4D vectors
	T tY; //Sets up a variable for the second number of both 2D, 3D, and 4D vectors
	T tZ; //Sets up a variable for the third number of both 3D and 4D vectors
	T tA; //Sets up a variable for the fourth part of a 4D vectpor
	T tRoot; //Sets up a variable for the square root of a vector for finding the magnitude and normalization.
	T tDot; //Sets up a variable for dot product.

	Vectors<T> operator+(Vectors<T> &); //Overloads the addition operator
	Vectors<T> operator-(Vectors<T> &); //Overloads the subtraction operator
	Vectors<T> operator*(Vectors<T> &); //Overloads the multiplication operator

	Vectors<T> HexCode(string); //Converts a hexadecimal color code to rgba values
};
#include "Mathematics.h"


template<typename T>
Vectors<T>::Vectors() //Creates an empty Vector type
{
}

template<typename T>
Vectors<T>::Vectors(T a_Scalar) //Constructs a scalar, the black sheep of the class.
{
	tX = a_Scalar;
}

template<typename T>
Vectors<T>::Vectors(T a_Num1, T a_Num2) //Constructs the 2D Vectors.
{
	tX = a_Num1;
	tY = a_Num2;
}

template<typename T>
Vectors<T>::Vectors(T a_Num1, T a_Num2, T a_Num3) //Constructs 3D Vectors.
{
	tX = a_Num1;
	tY = a_Num2;
	tZ = a_Num3;
}

template<typename T>
Vectors<T>::Vectors(T a_Red, T a_Green, T a_Blue, T a_Alpha) //Constructs 4D Vectors.
{
	tX = a_Red;
	tY = a_Green;
	tZ = a_Blue;
	tA = a_Alpha;
}

template<typename T>
Vectors<T> Vectors<T>::operator+(Vectors<T> &a_Add) //Overloads the addition operator.
{
	Vectors<T> OverAdd;
	OverAdd.tX = tX + a_Add.tX;
	OverAdd.tY = tY + a_Add.tY;
	OverAdd.tZ = tZ + a_Add.tZ;
	return OverAdd;
}

template<typename T>
Vectors<T> Vectors<T>::operator-(Vectors<T> &a_Sub) //Overloads the subtraction operator. Allows subtraction of vectors.
{
	Vectors<T> OverSub;
	OverSub.tX = tX - a_Sub.tX;
	OverSub.tY = tY - a_Sub.tY;
	OverSub.tZ = tZ - a_Sub.tZ;
	return OverSub;
}

template<typename T>
Vectors<T> Vectors<T>::operator*(Vectors<T> &a_Dot) //Overloads the multiplication operator.
{
	Vectors<T> OverMulti;
	OverMulti.tX = tX * a_Dot.tX;
	OverMulti.tY = tY * a_Dot.tY;
	OverMulti.tZ = tZ * a_Dot.tZ;
	return OverMulti;
}

template<typename T>
Vectors<T> Magnitude2D(Vectors<T> a_Two) //Performs math to find the magnitude of a given 2D Vector.
{
	T tSquare;
	tSquare = (pow(a_Two.tX, 2.0) + pow(a_Two.tY, 2.0));
	a_Two.tRoot = sqrt(tSquare);
	return a_Two;
}

template<typename T>
Vectors<T> Magnitude3D(Vectors<T> a_Three) //Performs math to find the magnitude of a given 3D Vector
{

	T tSquare;
	tSquare = (pow(a_Three.tX, 2.0) + pow(a_Three.tY, 2.0) + pow(a_Three.tZ, 2.0));
	a_Three.tRoot = sqrt(tSquare);

	return a_Three;
}

template<typename T>
Vectors<T>  Normalizing2D(Vectors<T> a_NormTwo) //Takes a given 2D Vector and returns the normalized values of the vectors, using the tRoot variable.
{
	T tSquare;
	tSquare = (pow(a_NormTwo.tX, 2.0) + pow(a_NormTwo.tY, 2.0));
	a_NormTwo.tRoot = sqrt(tSquare);

	a_NormTwo.tX = a_NormTwo.tX / a_NormTwo.tRoot;
	a_NormTwo.tY = a_NormTwo.tY / a_NormTwo.tRoot;

	return a_NormTwo;
}

template<typename T>
Vectors<T>  Normalizing3D(Vectors<T> a_NormThree) //Takes a given 3D Vector and returns the normalized values of the vectors, using the tRoot variable.
{
	T tSquare;
	tSquare = (pow(a_NormThree.tX, 2.0) + pow(a_NormThree.tY, 2.0) + pow(a_NormThree.tZ, 2.0));
	a_NormThree.tRoot = sqrt(tSquare);

	a_NormThree.tX = a_NormThree.tX / a_NormThree.tRoot;
	a_NormThree.tY = a_NormThree.tY / a_NormThree.tRoot;
	a_NormThree.tZ = a_NormThree.tZ / a_NormThree.tRoot;

	return a_NormThree;
}

template<typename T>
Vectors<T> Normalizing4D(Vectors<T> a_Color) //Takes a given 4D Vector and returns the normalized values of the vectors, using the tRoot variable.
{

	T tSquare;
	tSquare = (pow(a_Color.tX, 2.0) + pow(a_Color.tY, 2.0) + pow(a_Color.tZ, 2.0) + pow(a_Color.tA, 2.0));
	a_Color.tRoot = sqrt(tSquare);

	a_Color.tX = a_Color.tX / a_Color.tRoot;
	a_Color.tY = a_Color.tY / a_Color.tRoot;
	a_Color.tZ = a_Color.tZ / a_Color.tRoot;
	a_Color.tA = a_Color.tA / a_Color.tRoot;

	return a_Color;

}

template<typename T>
Vectors<T> DotProduct2D(Vectors<T> a_One, Vectors<T> a_Two) //Takes in two 2D Vectors and returns the Dot Product.
{
	Vectors<T> VecDot2{ (a_One.tX * a_Two.tX), (a_One.tY * a_Two.tY) };
	VecDot2.tDot = VecDot2.tX + VecDot2.tY;

	return VecDot2;
}

template<typename T>
Vectors<T> DotProduct3D(Vectors<T> a_One, Vectors<T> a_Two) //Takes in two 3D Vectors and returns the Dot Product.
{
	Vectors<T> VecDot3{ (a_One.tX * a_Two.tX), (a_One.tY * a_Two.tY), (a_One.tZ * a_Two.tZ) };
	VecDot3.tDot = VecDot3.tX + VecDot3.tY + VecDot3.tZ;

	return VecDot3;
}

template<typename T>
Vectors<T> CrossProduct3D(Vectors<T> a_One, Vectors<T> a_Two) //Takes in two 3D Vectors and performs the Cross Product operations.
{
	Vectors<T> VecCross3{ (a_One.tY * a_Two.tZ - a_One.tZ * a_Two.tY), (a_One.tZ * a_Two.tX - a_One.tX * a_Two.tZ), (a_One.tX * a_Two.tY - a_One.tY * a_Two.tX) };

	return VecCross3;
}

template<typename T>
Vectors<T> LinearInterpolation(Vectors<T> a_First, Vectors<T> a_Second) //Takes in two vectors and performs Linear Interpolation operations.
{
	Vectors<T> Linear;
	Linear.tX = a_First.tX + 0.5 * (a_Second.tX - a_First.tX);
	Linear.tY = a_First.tY + 0.5 * (a_Second.tY - a_First.tY);
	Linear.tZ = a_First.tZ + 0.5 * (a_Second.tZ - a_First.tZ);

	return Linear;
}

template<typename T>
Vectors<T> Vectors<T>::HexCode(string a_Colors) //Converts a given hexadecimal code to rgba values. Does not properly work if lowercase letters are used in the Hexadecimal.
{
	Vectors<T> Values;
	if (a_Colors[0] == '#')
	{
		T HexRay[6];
		for (T tOne = 1; tOne <= 6; tOne++)
			HexRay[tOne - 1] = (T(a_Colors[tOne]));

		for (T tTwo = 0; tTwo < 6; tTwo++)
		{
			if (HexRay[tTwo] / 10 == 4 || HexRay[tTwo] / 10 == 5)
				HexRay[tTwo] = HexRay[tTwo] - 48;
			else if (HexRay[tTwo] / 10 == 6 || HexRay[tTwo] / 10 == 7)
				HexRay[tTwo] = HexRay[tTwo] - 55;
			else
				HexRay[tTwo] = HexRay[tTwo];
		}
		Values.tX = (HexRay[0] * 16) + HexRay[1];
		Values.tY = (HexRay[2] * 16) + HexRay[3];
		Values.tZ = (HexRay[4] * 16) + HexRay[5];
		Values.tA = 255;
		return Values;
	}
	else
	{
		Values.tX = 0;
		Values.tY = 0;
		Values.tZ = 0;
		Values.tA = 0;
		return Values;
	}
}

template<typename T>
T ToDegrees(T a_Radians) //Converts Radians to Degrees.
{
	T tDegree = (180 / pi) * a_Radians;
	return tDegree;
}

template<typename T>
T ToRadians(T a_Degrees) //Converts Degrees to Radians.
{
	T tRadian = (pi / 180) * a_Degrees;
	return tRadian;
}

#endif