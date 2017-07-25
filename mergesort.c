#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int low, int mid, int high) {
	int count = high - low + 1;
	int *r = malloc(sizeof(int)*count);

	int i=low,j=mid+1,k=0;

	while(i<=mid && j<=high) {
		r[k++] = (a[i] <= a[j])?a[i++]:a[j++];
	}	
	
	while(i<=mid) {
		r[k++] = a[i++];
	}

	while(j<=high) {
		r[k++] = a[j++];
	}

	for(i=0;i<k;i++) {
		a[low+i]=r[i];
	}
}


void mergesort(int a[], int low, int high) {
	int mid;
	if(low < high) {
		mid = (low+high)/2;

		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}


void my_print(int a[], int len)
{
	int i;
	for(i = 0; i < len; ++i)
	{
		printf("%d\n", a[i]);
	}
	printf("\n");
}


int main() {
	int a[] = {11,13,12};
	//int a[] = {11,13,15,17,12,14,16,18};

	my_print(a, sizeof(a)/sizeof(int));	
	mergesort(a, 0, sizeof(a)/sizeof(int)-1);
	my_print(a, sizeof(a)/sizeof(int));	
}
