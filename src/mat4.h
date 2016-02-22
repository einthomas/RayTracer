#ifndef MAT4_H
#define MAT4_H

#include "vec3.h"

#include <string>

template <typename T>
class Mat4 {
public:
	Mat4();
	static Mat4<T> scale(Mat4<T> m, vec3 v);
	static Mat4<T> translate(Mat4<T> m, vec3 v);
	static Mat4<T> rotate(Mat4<T> m, vec3 axis, T angle);

	// Operators
    T* operator[] (int i);
	Mat4<T> operator*(const Mat4<T> &m);
	vec3 operator*(const vec3 &v);

private:
	T data[4][4] = {
		{ T(1), T(0), T(0), T(0) },
		{ T(0), T(1), T(0), T(0) },
		{ T(0), T(0), T(1), T(0) },
		{ T(0), T(0), T(0), T(1) },
	};
}; 


template <typename T>
Mat4<T>::Mat4() {
}

template <typename T>
Mat4<T> Mat4<T>::scale(Mat4<T> m, vec3 v) {
	Mat4<T> result;
	result.data[0][0] = v.x;
	result.data[1][1] = v.y;
	result.data[2][2] = v.z;

	return m * result;
}

template <typename T>
Mat4<T> Mat4<T>::translate(Mat4<T> m, vec3 v) {
	Mat4<T> result;
	result.data[0][3] = v.x;
	result.data[1][3] = v.y;
	result.data[2][3] = v.z;

	return m * result;
}

template <typename T>
Mat4<T> Mat4<T>::rotate(Mat4<T> m, vec3 axis, T angle) {
	Mat4<T> result;
	T sine = sin(angle);
	T cosine = cos(angle);
	axis = axis.normalize();
	vec3 v = (T(1) - cosine) * axis;

	result[0][0] = axis.x * v.x + cosine;
	result[0][1] = axis.y * v.x + sine * axis.z;
	result[0][2] = axis.z * v.x - sine * axis.y;

	result[1][0] = axis.x * v.y - sine * axis.z;
	result[1][1] = axis.y * v.y + cosine;
	result[1][2] = axis.z * v.y + sine * axis.x;

	result[2][0] = axis.x * v.z + sine * axis.y;
	result[2][1] = axis.y * v.z - sine * axis.x;
	result[2][2] = axis.z * v.z + cosine;

	return m * result;
}


// Operators
/*
 * Access: matrix[column][row]
 */
template <typename T>
T* Mat4<T>::operator[] (int i) {
	return data[i];
}

template <typename T>
Mat4<T> Mat4<T>::operator*(const Mat4<T> &m) {
	Mat4<T> result;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			result.data[i][k] = data[i][0] * m.data[0][k] +
								data[i][1] * m.data[1][k] +
								data[i][2] * m.data[2][k] +
								data[i][3] * m.data[3][k];
		}
	}

	return result;
}

template <typename T>
vec3 Mat4<T>::operator*(const vec3 &v) {
	vec3 result;
	result.x = data[0][0] * v.x + data[0][1] * v.y + data[0][2] * v.z + data[0][3];
	result.y = data[1][0] * v.x + data[1][1] * v.y + data[1][2] * v.z + data[1][3];
	result.z = data[2][0] * v.x + data[2][1] * v.y + data[2][2] * v.z + data[2][3];

	return result;
}

#endif // MAT4_H
