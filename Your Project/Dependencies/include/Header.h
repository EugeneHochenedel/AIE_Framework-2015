#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class Vectors
{
public:
	Vectors(T, T);// Constructs 2D Vector
	Vectors(T, T, T);// Constructs 3D Vector

	T tX;
	T tY;
	T tZ;
	T tRoot;
	T tDot;
};

template<typename T>
Vectors<T>::Vectors(T a_Num1, T a_Num2)
{
	tX = a_Num1;
	tY = a_Num2;
}

template<typename T>
Vectors<T>::Vectors(T a_Num1, T a_Num2, T a_Num3)
{
	tX = a_Num1;
	tY = a_Num2;
	tZ = a_Num3;
}

template<typename T>
Vectors<T> Addition(Vectors<T> a_One, Vectors<T> a_Two)
{
	T tOne = a_One.tX + a_Two.tX;
	T tTwo = a_One.tY + a_Two.tY;
	T tThree = a_One.tZ + a_Two.tZ;
	return{ tOne, tTwo, tThree };
}

template<typename T>
Vectors<T> Subtraction(Vectors<T> a_One, Vectors<T> a_Two)
{
	T tOne = a_One.tX - a_Two.tX;
	T tTwo = a_One.tY - a_Two.tY;
	T tThree = a_One.tZ - a_Two.tZ;
	return{ tOne, tTwo, tThree };
}

template<typename T>
Vectors<T> Magnitude2D(Vectors<T> Single)
{
	T tFirst = Single.tX;
	T tSecond = Single.tY;

	T tSquare;
	tSquare = (pow(tFirst, 2.0) + pow(tSecond, 2.0));
	Single.tRoot = sqrt(tSquare);

	return Single;
}

template<typename T>
Vectors<T> Magnitude3D(Vectors<T> a_Three)
{
	T tFirst = a_Three.tX;
	T tSecond = a_Three.tY;
	T tThird = a_Three.tZ;

	T tSquare;
	tSquare = (pow(tFirst, 2.0) + pow(tSecond, 2.0) + pow(tThird, 2.0));
	a_Three.tRoot = sqrt(tSquare);

	return a_Three;
}

template<typename T>
Vectors<T>  Normalizing2D(Vectors<T> a_Alone)
{
	T tOne = a_Alone.tX;
	T tTwo = a_Alone.tY;

	T tSquare;
	tSquare = (pow(tOne, 2.0) + pow(tTwo, 2.0));
	a_Alone.tRoot = sqrt(tSquare);

	a_Alone.tX = tOne / a_Alone.tRoot;
	a_Alone.tY = tTwo / a_Alone.tRoot;

	return a_Alone;
}

template<typename T>
Vectors<T>  Normalizing3D(Vectors<T> a_Alone)
{
	T tOne = a_Alone.tX;
	T tTwo = a_Alone.tY;
	T tThree = a_Alone.tZ;
	T tSquare;
	tSquare = (pow(tOne, 2.0) + pow(tTwo, 2.0) + pow(tThree, 2.0));
	a_Alone.tRoot = sqrt(tSquare);

	a_Alone.tX = tOne / a_Alone.tRoot;
	a_Alone.tY = tTwo / a_Alone.tRoot;
	a_Alone.tZ = tThree / a_Alone.tRoot;

	return a_Alone;
}

template<typename T>
Vectors<T>  DotProduct2D(Vectors<T> a_One, Vectors<T> a_Two)
{
	Vectors<T> temp{ (a_One.tX * a_Two.tX), (a_One.tY * a_Two.tY) };
	temp.tDot = temp.tX + temp.tY;

	return temp;
}

template<typename T>
Vectors<T>  DotProduct3D(Vectors<T> a_One, Vectors<T> a_Two)
{
	Vectors<T> temp{ (a_One.tX * a_Two.tX), (a_One.tY * a_Two.tY), (a_One.tZ * a_Two.tZ) };
	temp.tDot = temp.tX + temp.tY + temp.tZ;

	return temp;
}

template<typename T>
Vectors<T>  CrossProduct3D(Vectors<T> a_One, Vectors<T> a_Two)
{
	Vectors<T> temp{ (a_One.tY * a_Two.tZ - a_One.tZ * a_Two.tY), (a_One.tZ * a_Two.tX - a_One.tX * a_Two.tZ), (a_One.tX * a_Two.tY - a_One.tY * a_One.tX) };

	return temp;
}

#endif