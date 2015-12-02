///////////////////////////////////
// File: Header.h
// Author: Eugene Hochenedel
// Date Created: 11/9/15
///////////////////////////////////

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

	T tX; //Sets up a variable for the first number of  both 2D and 3D vectors
	T tY; //Sets up a variable for the second number of  both 2D and 3D vectors
	T tZ; //Sets up a variable for the third number of a 3D vector
	T tRoot; //Sets up a variable for the square root of a vector for finding the magnitude and normalization.
	T tDot; //Sets up a variable for dot product.
};

template<typename T>
Vectors<T>::Vectors(T a_Num1, T a_Num2)//Constructs the 2D Vectors.
{
	tX = a_Num1;
	tY = a_Num2;
}

template<typename T>
Vectors<T>::Vectors(T a_Num1, T a_Num2, T a_Num3)//Constructs 3D Vectors.
{
	tX = a_Num1;
	tY = a_Num2;
	tZ = a_Num3;
}

template<typename T>
Vectors<T> Addition(Vectors<T> a_One, Vectors<T> a_Two)//Performs addition operation for 2D and 3D Vectors. Takes in two different vectors.
{
	T tOne = a_One.tX + a_Two.tX;
	T tTwo = a_One.tY + a_Two.tY;
	T tThree = a_One.tZ + a_Two.tZ;
	return{ tOne, tTwo, tThree };
}

template<typename T>
Vectors<T> Subtraction(Vectors<T> a_One, Vectors<T> a_Two)//Performs subtraction operation for 2D and 3D Vectors. Takes in two different vectors.
{
	T tOne = a_One.tX - a_Two.tX;
	T tTwo = a_One.tY - a_Two.tY;
	T tThree = a_One.tZ - a_Two.tZ;
	return{ tOne, tTwo, tThree };
}

template<typename T>
Vectors<T> Magnitude2D(Vectors<T> Single)//Performs math to find the magnitude of a given 2D Vector.
{
	T tFirst = Single.tX;
	T tSecond = Single.tY;

	T tSquare;
	tSquare = (pow(tFirst, 2.0) + pow(tSecond, 2.0));
	Single.tRoot = sqrt(tSquare);

	return Single;
}

template<typename T>
Vectors<T> Magnitude3D(Vectors<T> a_Three)//Performs math to find the magnitude of a given 3D Vector
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
Vectors<T>  Normalizing2D(Vectors<T> a_Alone)//Takes a given 2D Vector and returns the normalized values of the vectors, using the tRoot variable.
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
Vectors<T>  Normalizing3D(Vectors<T> a_Alone)//Takes a given 3D Vector and returns the normalized values of the vectors, using the tRoot variable.
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
Vectors<T>  DotProduct2D(Vectors<T> a_One, Vectors<T> a_Two)//Takes in two 2D Vectors and returns the Dot Product.
{
	Vectors<T> temp{ (a_One.tX * a_Two.tX), (a_One.tY * a_Two.tY) };
	temp.tDot = temp.tX + temp.tY;

	return temp;
}

template<typename T>
Vectors<T>  DotProduct3D(Vectors<T> a_One, Vectors<T> a_Two)//Takes in two 3D Vectors and returns the Dot Product
{
	Vectors<T> temp{ (a_One.tX * a_Two.tX), (a_One.tY * a_Two.tY), (a_One.tZ * a_Two.tZ) };
	temp.tDot = temp.tX + temp.tY + temp.tZ;

	return temp;
}

template<typename T>
Vectors<T>  CrossProduct3D(Vectors<T> a_One, Vectors<T> a_Two)//Takes in two 3D Vectors and performs the Cross Product operations.
{
	Vectors<T> temp{ (a_One.tY * a_Two.tZ - a_One.tZ * a_Two.tY), (a_One.tZ * a_Two.tX - a_One.tX * a_Two.tZ), (a_One.tX * a_Two.tY - a_One.tY * a_One.tX) };

	return temp;
}

#endif