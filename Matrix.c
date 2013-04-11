#include "Matrix.h"
#include <math.h>
#include <string.h>
#define to_rad(x) (float(x*M_PI/180.f))
void multiplyMM(float *result, float*L, float*R){
	for(int c = 0; c < 4; c++)
		for(int r = 0; r < 4; r++)
			result[r*4+c] = L[c+0*4]   * R[r*4+0] +
							L[c+1*4] * R[r*4+1] + 
							L[c+2*4] * R[r*4+2] + 
							L[c+3*4]* R[r*4+3];
	return;
}
void translateMM(float *r,float *m, float x, float y, float z){
	float translationMatrix[16] = {1,0,0,0,
							   0,1,0,0,
							   0,0,1,0,
							   x,y,z,1};
	multiplyMM(r, m, translationMatrix);
}

void scaleMM(float *r,float *m, float sx, float sy, float sz){
	float scaleMatrix[16] = {sx,0 ,0 ,0,
						 0 ,sy,0 ,0,
						 0 ,0 ,sz,0,
					     0 ,0 ,0 ,1};
	multiplyMM(r, m, scaleMatrix);
}

void rotateMM(float *r,float *m, float angle, float _x, float _y, float _z){
	float s = sin(to_rad(angle));
	float c = cos(to_rad(angle));
	float magnitude = sqrt(_x*_x + _y*_y + _z*_z);
	float x = _x / magnitude;
	float y = _y / magnitude;
	float z = _z / magnitude;
	float rotationMatrix[16] = {c+(x*x)*(1-c),y*x*(1-c)+z*s, z*x*(1-c) - y*s,0,
							y*x*(1-c)-z*s,c+(y*y)*(1-c), z*y*(1-c) + x*s,0,
							z*x*(1-c)+y*s,y*z*(1-c)-x*s, c+z*z*(1-c)    ,0,
							0,0,0,1};
	multiplyMM(r, m, rotationMatrix);
	return;
}

void transposeMM(float *result, float*matrix){
	for(int c = 0; c < 4; c++) // HA
		for(int r = 0; r < 4; r++)
			result[c*4+r] = matrix[r*4+c];
}

void setIdentityM(float*m){
	for(int x = 0; x < 4; x++)
		for(int y=0; y < 4; y++)
			m[y*4+x] = x==y?1:0;
}

void rotateM(float*mat, float angle, float x, float y, float z){
	float result[16];
	rotateMM(result, mat, angle, x, y, z);
	memcpy(mat, result, sizeof(float)*16);
}
void scaleM(float*mat, float sx, float sy, float sz){
	float result[16];
	scaleMM(result, mat, sx, sy, sz);
	memcpy(mat, result, sizeof(float)*16);
}

void translateM(float*mat, float x, float y, float z){
	float result[16];
	translateMM(result, mat, x, y, z);
	memcpy(mat, result, sizeof(float)*16);
}
void transposeM(float*mat){
	float result[16];
	transposeMM(result, mat);
	memcpy(mat, result, sizeof(float)*16);
}