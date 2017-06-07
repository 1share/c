#include <stdio.h>  
#include <stdlib.h>  


#define L	0
#define R	7
#define U	0
#define D	9


int run(int (*m)[R+1], int i, int j)
{
	int e = 0;

	m[i][j] = 2;

	if (i==D &&  j == R) 
		e=1;

	if (e!=1 && j+1<=R && m[i][j+1] == 0)
		if (run(m,i,j+1)==1)
			e=1;
	
	if (e!=1 && i+1<=D && m[i+1][j] == 0)
		if (run(m,i+1,j)==1)
			e=1;
	
	if (e!=1 && j-1>=L && m[i][j-1] == 0)
		if (run(m,i,j-1)==1)
			e=1;
	
	if (e!=1 && i-1>=U && m[i-1][j] == 0)
		if (run(m,i-1,j)==1)
			e=1;
	

	if(e!=1)
		m[i][j]=0;


	return e;
}


  
int main(void)  
{  
	int i, j;  
	int m[D+1][R+1] = {  
		{0,0,1,0,0,0,1,0},  
		{0,0,1,0,0,0,1,0},  
		{0,0,0,0,1,1,0,1},  
		{0,1,1,1,0,0,1,0},  
		{0,0,0,1,0,0,0,0},  
		{0,1,0,0,0,1,0,1},  
		{0,1,1,1,1,0,0,1},  
		{1,1,0,0,1,1,0,1},
		{1,1,0,0,1,1,0,0},
		{1,1,0,0,0,0,1,0}
	};  


	run(m,0,0);


	for (i=0;i<D+1;i++) {
		for(j=0;j<R+1;j++) {
			if(m[i][j]==2)
				printf("$");
			if(m[i][j]==1)
				printf("#");
			if(m[i][j]==0)
				printf("@");
			}
			printf("\n");
		}

}  
