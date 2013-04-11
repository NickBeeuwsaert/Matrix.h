#ifndef __MATRIX_H__
#define __MATRIX_H__

void multiplyMM(float*, float*, float*);

void translateMM(float*, float*,  float, float, float);

void scaleMM(float*, float*, float, float, float);


void rotateMM(float*, float*, float, float, float, float);

void transposeMM(float*, float*);

void setIdentityM(float*);


void rotateM(float*, float, float, float, float);

void scaleM(float*, float, float, float);

void translateM(float*, float, float, float);

void transposeM(float*);

#endif // __MATRIX_H__
