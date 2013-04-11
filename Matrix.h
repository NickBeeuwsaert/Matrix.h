#ifndef __MATRIX_H__
#define __MATRIX_H__
#define MATRIX_WIDTH 4
#define MATRIX_HEIGHT 4
void multiplyMM(float*, float*, float*);
void rotateMM(float*, float*, float, float, float, float);
void translateMM(float*, float*,  float, float, float);
void scaleMM(float*, float*, float, float, float);
void setIdentityM(float*);
void transposeMM(float*, float*);

void rotateM(float*, float, float, float, float);
void translateM(float*, float, float, float);
void scaleM(float*, float, float, float);
void transposeM(float*);

#endif // __MATRIX_H__
