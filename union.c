#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int getPartition(int *a, int beg, int end)
{
	int i;
  	int part;
    	if(beg<=end) {
		part = beg;
		for(i = beg+1; i <= end; ++i)
		{
			if(a[i] <= a[beg])
			{
				swap(&a[part+1], &a[i]);
				++part;
			}
		}
		swap(&a[beg], &a[part]);
    	}
	return part;
	
}

void quickSort(int *a, int beg, int end)
{
	if (a == NULL || beg >= end)
		return;
	int part = getPartition(a, beg, end);

	quickSort(a, beg, part-1);
	quickSort(a, part+1, end);
}

void tranverse(int *a, int len)
{
	int i;
	for(i = 0; i < len; ++i)
	{
		printf("%d\n", a[i]);
	}
	printf("\n");
}


void xxx(int *a, int la, int *b, int lb, int *c, int *lc) {
	int i;
	int count = 0;
	int t = 0;

	for (i = 0; i<la; i++)
		c[i]=a[i];
	for (i = 0; i<lb; i++)
		c[i+la]=b[i];

	quickSort(c,0,la+lb-1);


	for(i = 0;i<la+lb;i++) {
		if(c[i] != t) {
			c[count++]=c[i];
		}
		else
		{	
			continue;
		}	
		
		t = c[i];
	}


	*lc = count;
}

int main()
{
	int a[] = {1,5,7,6,8};
	int b[] = {3,7,2,1,9,10};
	
	int la = sizeof(a) / sizeof(int);
	int lb = sizeof(b) / sizeof(int);

	int lc;
	int *c = malloc((la+lb)*sizeof(int));
	if (NULL == c)
		return 1;
	memset(c, 0, la+lb);
	
	xxx(a, la, b, lb, c, &lc);

	tranverse(c, lc);
	
	if(c)
		free(c);

}
