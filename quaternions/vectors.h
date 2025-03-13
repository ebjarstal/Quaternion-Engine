#pragma once

#include <iostream>

// VECTOR2D
struct Vector2D {
	float x, y;
};




// VECTOR3D
struct Vector3D {
	float x, y, z;

public:
	// Returns the Euclidean norm of the vector.
	float getNorm() const;

	// Returns the normalized vector relative to the vector.
	Vector3D getNormalized() const;

	// Returns true if the norm of the vector is 1. Returns false otherwise.
	bool isUnit() const;
};

std::ostream& operator<<(std::ostream& f, const Vector3D& v);

Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
Vector3D operator*(const Vector3D& v, const float& lambda);
Vector3D operator*(const float& lambda, const Vector3D& v);
Vector3D operator/(const Vector3D& v, const float& lambda);

// Returns the dot product of two vectors, also known as the scalar product.
float dotProduct(const Vector3D& v1, const Vector3D& v2);

// Returns the cross product of two vectors.
Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2);



// VECTOR4D
struct Vector4D {
	float x, y, z, w;

public:
	// Returns the Euclidean norm of the vector.
	float getNorm() const;

	// Returns the normalized vector relative to the vector.
	Vector4D getNormalized() const;

	// Returns true if the norm of the vector is 1. Returns false otherwise.
	bool isUnit() const;
};

std::ostream& operator<<(std::ostream& f, const Vector4D& v);

Vector4D operator+(const Vector4D& v1, const Vector4D& v2);
Vector4D operator-(const Vector4D& v1, const Vector4D& v2);
Vector4D operator*(const Vector4D& v, const float& lambda);
Vector4D operator*(const float& lambda, const Vector4D& v);
Vector4D operator/(const Vector4D& v, const float& lambda);

// Returns the dot product of two vectors, also known as the scalar product.
float dotProduct(const Vector4D& v1, const Vector4D& v2);