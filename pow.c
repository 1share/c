#include<stdio.h>

float pow_normal(float x, int n) {
	float result = 1;

	int i = 0;
	for (i = 0; i < n; i++) {
		result = result * x;
	}

	return result;
}

float pow_fast(float x, int n) {
	float result = 1;
	
	if (n == 1) {
		return x;
	} else if (n % 2 == 0) {
		result = pow_fast(x, n/2);
		return result * result;
	} else {
		result = pow_fast(x, (n-1)/2);
		return result * result * x;
	}

	return result;
}


int main() {
	printf("result:%f\n", pow_normal(1.000001,100000000));
	printf("result:%f\n", pow_fast(1.000001,100000000));

	return 0;
}
