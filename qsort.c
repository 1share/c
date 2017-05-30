#include<stdio.h>


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
int main()
{
	//int a[] = {1,3,2};
	int a[] = {4,5,3,6,8,9,10,7,2,1};
	int len =  sizeof(a) / sizeof(int);
	tranverse(a, len);

	quickSort(a, 0, len-1);
	tranverse(a, len);
}
