#include<stdio.h>
int bs1(int *s, int b, int e, int n) {
	int m;
	while(b<e) {
		m = (b+e)/2;

		if(n>s[m])
			b=m+1;
		else
			e=m;
	}


	if(s[b]==n)
		return b;
	else 
		return -1;
		
}


int bs2(int *s, int b, int e, int n) {
	if(b>e)
		return -1;

	int m = (b+e)/2;

	if (s[m]>n) {
		return bs2(s, b,m-1,n);
	}


	if (s[m]<n) {
		return bs2(s,m+1,e,n);
	}

	return m;
}



int main() {
	int a[] = {1,3,5,7,9,11,13,7,15};
	int count = sizeof(a)/sizeof(int);

	printf("index:%d\n",bs1(a,0,count-1, 7));

	int b[] = {1,7,7,7,9,11,13,14,15};
	count = sizeof(b)/sizeof(int);

	printf("index:%d\n",bs2(b,0,count-1, 7));
}
