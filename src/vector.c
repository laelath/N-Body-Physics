#include <math.h>
#include <string.h>

#include "vector.h"

void vec2dSetEqual(double v[2], double vt[2])
{
	vt[0] = v[0];
	vt[1] = v[1];
}

void vec3dSetEqual(double v[3], double vt[3])
{
	vt[0] = v[0];
	vt[1] = v[1];
	vt[2] = v[2];
}

void vec4dSetEqual(double v[4], double vt[4])
{
	vt[0] = v[0];
	vt[1] = v[1];
	vt[2] = v[2];
	vt[3] = v[3];
}

//Vector Addition
void vec2dAdd(double v1[2], double v2[2], double vt[2])
{
	vt[0] = v1[0] + v2[0];
	vt[1] = v1[1] + v2[1];
}

void vec3dAdd(double v1[3], double v2[3], double vt[3])
{
	vt[0] = v1[0] + v2[0];
	vt[1] = v1[1] + v2[1];
	vt[2] = v1[2] + v2[2];
}

void vec4dAdd(double v1[4], double v2[4], double vt[4])
{
	vt[0] = v1[0] + v2[0];
        vt[1] = v1[1] + v2[1];
        vt[2] = v1[2] + v2[2];
	vt[3] = v1[3] + v2[3];
}

//Vector Subtraction
void vec2dSub(double v1[2], double v2[2], double vt[2])
{
	vt[0] = v1[0] - v2[0];
        vt[1] = v1[1] - v2[1];
}

void vec3dSub(double v1[3], double v2[3], double vt[3])
{
	vt[0] = v1[0] - v2[0];
	vt[1] = v1[1] - v2[1];
	vt[2] = v1[2] - v2[2];
}

void vec4dSub(double v1[4], double v2[4], double vt[4])
{
	vt[0] = v1[0] - v2[0];
        vt[1] = v1[1] - v2[1];
        vt[2] = v1[2] - v2[2];
	vt[3] = v1[3] - v2[3];
}

//Vector Multiplication
void vec2dMlt(double v1[2], double v2[2], double vt[2])
{
	vt[0] = v1[0] * v2[0];
        vt[1] = v1[1] * v2[1];
}

void vec3dMlt(double v1[3], double v2[3], double vt[3])
{
	vt[0] = v1[0] * v2[0];
	vt[1] = v1[1] * v2[1];
	vt[2] = v1[2] * v2[2];
}

void vec4dMlt(double v1[4], double v2[4], double vt[4])
{
	vt[0] = v1[0] * v2[0];
        vt[1] = v1[1] * v2[1];
        vt[2] = v1[2] * v2[2];
	vt[3] = v1[3] * v2[3];
}

//Vector Division
void vec2dDiv(double v1[2], double v2[2], double vt[2])
{
	vt[0] = v1[0] / v2[0];
        vt[1] = v1[1] / v2[1];
}

void vec3dDiv(double v1[3], double v2[3], double vt[3])
{
	vt[0] = v1[0] / v2[0];
	vt[1] = v1[1] / v2[1];
	vt[2] = v1[2] / v2[2];
}

void vec4dDiv(double v1[4], double v2[4], double vt[4])
{
	vt[0] = v1[0] / v2[0];
        vt[1] = v1[1] / v2[1];
        vt[2] = v1[2] / v2[2];
	vt[3] = v1[3] / v2[3];
}

//Vector Scalar Multiplication
void vec2dMltScl(double v1[2], double scl, double vt[2])
{
	vt[0] = v1[0] * scl;
        vt[1] = v1[1] * scl;
}

void vec3dMltScl(double v1[3], double scl, double vt[3])
{
	vt[0] = v1[0] * scl;
	vt[1] = v1[1] * scl;
	vt[2] = v1[2] * scl;
}

void vec4dMltScl(double v1[4], double scl, double vt[4])
{
	vt[0] = v1[0] * scl;
        vt[1] = v1[1] * scl;
        vt[2] = v1[2] * scl;
	vt[3] = v1[3] * scl;
}

//Vector Scalar Multiplication
void vec2dDivScl(double v1[2], double scl, double vt[2])
{
	vt[0] = v1[0] / scl;
        vt[1] = v1[1] / scl;
}

void vec3dDivScl(double v1[3], double scl, double vt[3])
{
	vt[0] = v1[0] / scl;
	vt[1] = v1[1] / scl;
	vt[2] = v1[2] / scl;
}

void vec4dDivScl(double v1[4], double scl, double vt[4])
{
	vt[0] = v1[0] / scl;
        vt[1] = v1[1] / scl;
        vt[2] = v1[2] / scl;
	vt[3] = v1[3] / scl;
}

//Vector Length
double vec2dLength(double v[2])
{
	return sqrt(pow(v[0], 2) + pow(v[1], 2));
}

double vec3dLength(double v[3])
{
	return sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
}

double vec4dLength(double v[4])
{
	return sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2) + pow(v[3], 2));
}

//Vector Distance
double vec2dDistance(double v1[2], double v2[2])
{
	return sqrt(pow(v1[0]-v2[0], 2) + pow(v1[1]-v2[1], 2));
}

double vec3dDistance(double v1[3], double v2[3])
{
	return sqrt(pow(v1[0]-v2[0], 2) + pow(v1[1]-v2[1], 2) + pow(v1[2]-v2[2], 2));
}

double vec4dDistance(double v1[4], double v2[4])
{
	return sqrt(pow(v1[0]-v2[0], 2) + pow(v1[1]-v2[1], 2) + pow(v1[2]-v2[2], 2) + pow(v1[3]-v2[3], 2));
}

//Vector Dot Product
double vec2dDot(double v1[2], double v2[2])
{
	return v1[0] * v2[0] + v1[1] * v2[1];
}

double vec3dDot(double v1[3], double v2[3])
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

double vec4dDot(double v1[4], double v2[4])
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2] + v1[3] * v2[3];
}

//Vector Cross Product
void vec3dCross(double v1[3], double v2[3], double vt[3])
{
	vt[0] = v1[1] * v2[2] - v1[2] * v2[1];
	vt[1] = v1[2] * v2[0] - v1[0] * v2[2];
	vt[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

//Vector Normalization
void vec2dNormalize(double v[2], double vt[2])
{
	double l = vec2dLength(v);
	vt[0] = v[0] / l;
	vt[1] = v[1] / l;
}

void vec3dNormalize(double v[3], double vt[3])
{
	double l = vec3dLength(v);
	vt[0] = v[0] / l;
	vt[1] = v[1] / l;
	vt[2] = v[2] / l;
}

void vec4dNormalize(double v[4], double vt[4])
{
	double l = vec4dLength(v);
	vt[0] = v[0] / l;
	vt[1] = v[1] / l;
	vt[2] = v[2] / l;
	vt[3] = v[3] / l;
}

//Multiply Vector by a Matrix
void vec2dMltMat(double m[2][2], double v[2], double vt[2])
{
	double vtemp[2];
	vtemp[0] = m[0][0] * v[0] + m[1][0] * v[1];
	vtemp[1] = m[0][1] * v[0] + m[1][1] * v[1];
	memcpy(vt, vtemp, 2 * sizeof(double));
}

void vec3dMltMat(double m[3][3], double v[3], double vt[3])
{
	double vtemp[3];
	vtemp[0] = m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2];
	vtemp[1] = m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2];
	vtemp[2] = m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2];
	memcpy(vt, vtemp, 3 * sizeof(double));
}

void vec4dMltMat(double m[4][4], double v[4], double vt[4])
{
	double vtemp[4];
	vtemp[0] = m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3];
	vtemp[1] = m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3];
	vtemp[2] = m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3];
	vtemp[3] = m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * v[3];
	memcpy(vt, vtemp, 4 * sizeof(double));
}

//Multiply a vec3 with a given w by a mat4, convinience function
void vec3dMltMat4(double m[4][4], double v[3], double w, double vt[4])
{
	vt[0] = m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * w;
	vt[1] = m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * w;
	vt[2] = m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * w;
	vt[3] = m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * w;
}

//Matrix Multiply
void mat2dMlt(double m1[2][2], double m2[2][2], double mt[2][2])
{
	double mtemp[2][2];
	mtemp[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1];
	mtemp[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1];
	mtemp[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1];
	mtemp[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1];
	memcpy(mt, mtemp, 4 * sizeof(double));
}

void mat3dMlt(double m1[3][3], double m2[3][3], double mt[3][3])
{
	double mtemp[3][3];
	mtemp[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2];
	mtemp[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2];
	mtemp[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2];
	mtemp[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2];
	mtemp[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2];
	mtemp[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2];
	mtemp[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2];
	mtemp[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2];
	mtemp[2][2] = m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2];
	memcpy(mt, mtemp, 9 * sizeof(double));
}

void mat4dMlt(double m1[4][4], double m2[4][4], double mt[4][4])
{
	double mtemp[4][4];
	mtemp[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3];
	mtemp[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3];
	mtemp[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3];
	mtemp[3][0] = m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2] + m1[3][0] * m2[3][3];
	mtemp[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3];
	mtemp[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3];
	mtemp[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3];
	mtemp[3][1] = m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2] + m1[3][1] * m2[3][3];
	mtemp[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3];
	mtemp[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3];
	mtemp[2][2] = m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3];
	mtemp[3][2] = m1[0][2] * m2[3][0] + m1[1][2] * m2[3][1] + m1[2][2] * m2[3][2] + m1[3][2] * m2[3][3];
	mtemp[0][3] = m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3];
	mtemp[1][3] = m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3];
	mtemp[2][3] = m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3];
	mtemp[3][3] = m1[0][3] * m2[3][0] + m1[1][3] * m2[3][1] + m1[2][3] * m2[3][2] + m1[3][3] * m2[3][3];
	memcpy(mt, mtemp, 16 * sizeof(double));
}

//Generate a Scale, translation, and rotation 4x4 matrix
//PASS AN IDENTITY MATRIX
void mat4dGenScale(double v[3], double mt[4][4])
{
	mt[0][0] = v[0]; //mt[1][0] = 0;
	mt[1][1] = v[1]; //mt[2][1] = 0;
	mt[2][2] = v[2]; //mt[3][2] = 0;
}

void mat4dGenTranslate(double v[3], double mt[4][4])
{
	mt[3][0] = v[0];
	mt[3][1] = v[1];
	mt[3][2] = v[2];
}

void mat4dGenRotate(double rad, double axis[3], double mt[4][4])
{
	double c = cos(rad);
	double s = sin(rad);
	double C = 1 - c;
	mt[0][0] = axis[0] * axis[0] * C + c;
	mt[1][0] = axis[0] * axis[1] * C - axis[2] * s;
	mt[2][0] = axis[0] * axis[2] * C + axis[1] * s;
	mt[0][1] = axis[1] * axis[0] * C + axis[2] * s;
	mt[1][1] = axis[1] * axis[1] * C + c;
	mt[2][1] = axis[1] * axis[2] * C - axis[0] * s;
	mt[0][2] = axis[2] * axis[0] * C - axis[1] * s;
	mt[1][2] = axis[2] * axis[1] * C + axis[0] * s;
	mt[2][2] = axis[2] * axis[2] * C + c;
}

//Scale, translate, and rotate a 4x4 matrix
void mat4dScale(double v[3], double mt[4][4])
{
	double mtemp[4][4] = MATRIX_IDENTITY_4;
	mat4dGenScale(v, mtemp);
	mat4dMlt(mtemp, mt, mt);
}

void mat4dTranslate(double v[3], double mt[4][4])
{
	double mtemp[4][4] = MATRIX_IDENTITY_4;
	mat4dGenTranslate(v, mtemp);
	mat4dMlt(mtemp, mt, mt);
}

void mat4dRotate(double rad, double axis[3], double mt[4][4])
{
	double mtemp[4][4] = MATRIX_IDENTITY_4;
	mat4dGenRotate(rad, axis, mtemp);
	mat4dMlt(mtemp, mt, mt);
}

//Generate perspective and orthogonal projection matrices
void mat4dProjection(double fovx, double aspect, double zNear, double zFar, double mt[4][4])
{
	double r = tan(0.5 * fovx);
	double t = r / aspect;
	mt[0][0] = 1.0 / r;
	mt[1][1] = 1.0 / t;
	mt[2][2] = (zNear + zFar) / (zNear - zFar);
	mt[3][2] = (2.0 * zNear * zFar) / (zNear - zFar);
	mt[2][3] = -1;
	mt[3][3] = 0;
}

//Sets an already created matrix to the identity matrix
void mat2dSetIdentity(double m[2][2])
{
	m[0][0] = 1; m[1][0] = 0;
	m[0][1] = 0; m[1][1] = 1;
}

void mat3dSetIdentity(double m[3][3])
{
	m[0][0] = 1; m[1][0] = 0; m[2][0] = 0;
	m[0][1] = 0; m[1][1] = 1; m[2][1] = 0;
	m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;
}

void mat4dSetIdentity(double m[4][4])
{
	m[0][0] = 1; m[1][0] = 0; m[2][0] = 0; m[3][0] = 0;
	m[0][1] = 0; m[1][1] = 1; m[2][1] = 0; m[3][1] = 0;
	m[0][2] = 0; m[1][2] = 0; m[2][2] = 1; m[3][2] = 0;
	m[0][3] = 0; m[1][3] = 0; m[2][3] = 0; m[3][3] = 1;
}

void doubleToSingle(double *c, float *t, unsigned int length)
{
	for (int i = 0; i < length; i++) t[i] = c[i];
}
