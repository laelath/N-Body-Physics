#ifndef VECTOR_H
#define VECTOR_H

void vec2dSetEqual(double v[2], double vt[2]);
void vec3dSetEqual(double v[3], double vt[3]);
void vec4dSetEqual(double v[4], double vt[4]);

void vec2dAdd(double v1[2], double v2[2], double vt[2]);
void vec3dAdd(double v1[3], double v2[3], double vt[3]);
void vec4dAdd(double v1[4], double v2[4], double vt[4]);

void vec2dSub(double v1[2], double v2[2], double vt[2]);
void vec3dSub(double v1[3], double v2[3], double vt[3]);
void vec4dSub(double v1[4], double v2[4], double vt[4]);

void vec2dMlt(double v1[2], double v2[2], double vt[2]);
void vec3dMlt(double v1[3], double v2[3], double vt[3]);
void vec4dMlt(double v1[4], double v2[4], double vt[4]);

void vec2dDiv(double v1[2], double v2[2], double vt[2]);
void vec3dDiv(double v1[3], double v2[3], double vt[3]);
void vec4dDiv(double v1[4], double v2[4], double vt[4]);

void vec2dMltScl(double v[2], double scl, double vt[2]);
void vec3dMltScl(double v[3], double scl, double vt[3]);
void vec4dMltScl(double v[4], double scl, double vt[4]);

void vec2dDivScl(double v[2], double scl, double vt[2]);
void vec3dDivScl(double v[3], double scl, double vt[3]);
void vec4dDivScl(double v[4], double scl, double vt[4]);

double vec2dLength(double v[2]);
double vec3dLength(double v[3]);
double vec4dLength(double v[4]);

double vec2dDistance(double v1[2], double v2[2]);
double vec3dDistance(double v1[3], double v2[3]);
double vec4dDistance(double v1[4], double v2[4]);

double vec2dDot(double v1[2], double vt[2]);
double vec3dDot(double v1[3], double vt[3]);
double vec4dDot(double v1[4], double vt[4]);

void vec3dCross(double v1[3], double v2[3], double vt[3]);

void vec2dNormalize(double v[2], double vt[2]);
void vec3dNormalize(double v[3], double vt[3]);
void vec4dNormalize(double v[4], double vt[4]);

void vec2dMltMat(double m[2][2], double v[2], double vt[2]);
void vec3dMltMat(double m[3][3], double v[3], double vt[3]);
void vec4dMltMat(double m[4][4], double v[4], double vt[4]);

void vec3dMltMat4(double m[4][4], double v[3], double w, double vt[4]);

void mat2dMlt(double m1[2][2], double m2[2][2], double mt[2][2]);
void mat3dMlt(double m1[3][3], double m2[3][3], double mt[3][3]);
void mat4dMlt(double m1[4][4], double m2[4][4], double mt[4][4]);

//PASS AN IDENTITY MATRIX
void mat4dGenScale(double v[3], double mt[4][4]);
void mat4dGenTranslate(double v[3], double mt[4][4]);
void mat4dGenRotate(double rad, double axis[3], double mt[4][4]);

void mat4dScale(double v[3], double mt[4][4]);
void mat4dTranslate(double v[3], double mt[4][4]);
void mat4dRotate(double rad, double axis[3], double mt[4][4]);

void mat4dProjection(double fovx, double aspect, double zNear, double zFar, double mt[4][4]);
//void mat4dOthrogonal();

void mat2dSetIdentity(double m[2][2]);
void mat3dSetIdentity(double m[3][3]);
void mat4dSetIdentity(double m[4][4]);

void doubleToSingle(double *c, float *t, unsigned int length);

#define MATRIX_IDENTITY_2 {1,0,0,1}
#define MATRIX_IDENTITY_3 {1,0,0,0,1,0,0,0,1}
#define MATRIX_IDENTITY_4 {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}

#endif
