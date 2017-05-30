#include<stdio.h>

void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


void my_print(int *str, int n) {
        int i;
        for(i=0;i<n;i++) {
                printf("%d\n",str[i]);
        }
}


int main() {
	int str[] = {10,9,8,7,11,6,5,4,3,2,1};

	int n = sizeof(str)/sizeof(int);

	int i,j,flag;

	flag=1;
	for (i=0;i<n && flag;i++) {
		flag = 0;
		for (j=0;j<n-1-i;j++) {
			if(str[j]>str[j+1]) {
				swap(&str[j],&str[j+1]);
				flag = 1;
			}
		}
	}


	my_print(str, n);

	return 0;
}
