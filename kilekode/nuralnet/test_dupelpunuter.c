#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	
	int h = 30;
	double **hej;
	hej = (double **)malloc(sizeof(double)*h);
	for(int i = 0; i< h; i++) {
		*(hej+i) = (double *)malloc(sizeof(double)*h);
		for(int i2 = 0; i2 < h; i2++) {
			*(*(hej+i)+i2) = i2*i;
		}
	}
	for(int i = 0; i < h; i++) {
		for(int i2 = 0; i2 < h; i2++) {
			printf("%f,",*(*(hej+i)+i2));
		}
		printf("\n");
	}
}