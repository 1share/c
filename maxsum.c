#include<stdio.h>

int get_max_sum(int *a, int size) {
	
	int sum = 0;
	int max = -(1<<31);
	int cur = 0;

	while(cur < size) {
		sum+=a[cur++];
		if(sum>max) {
			max = sum;
		}else if(sum<0){
			sum=0;
		}
	}

	return max;
}



int main() {

	int a[] = {1,-2,3,10,-4,7,2,-5};
	
	printf("%d\n", get_max_sum(a,sizeof(a)/sizeof(int)));

}
