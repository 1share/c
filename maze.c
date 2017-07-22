#include <stdio.h>  
#include <stdlib.h>  

#define END_I 8  
#define END_J 7  
#define START_I 0  
#define START_J 0  

int VistMaze(int maze[][8], int i, int j)  
{  
	int end = 0;  

	//默认当前节点是能走通迷宫的，打一个标记2，以区别0值的情况
	maze[i][j] = 2;  

	if (i == END_I && j == END_J){  
		end = 1;  
	}  
	if (end != 1 && j + 1 <= END_J && maze[i][j + 1] == 0){     
		if (VistMaze(maze, i, j + 1) == 1)  
			end = 1;  
	}  
	if (end != 1 && i + 1 <= END_I && maze[i + 1][j] == 0){ 
		if (VistMaze(maze, i + 1, j) == 1)  
			end = 1;  
	}  
	if (end != 1 && j - 1 >= START_J && maze[i][j - 1] == 0){ 
		if (VistMaze(maze, i, j - 1) == 1)  
			end = 1;  
	}  
	if (end != 1 && i - 1 >= START_I && maze[i - 1][j] == 0){    
		if (VistMaze(maze, i - 1, j) == 1)  
			end = 1;  
	} 

	//增加走过到的地方，被标记为2了，要清除一下，恢复为原来的值0
	if (end != 1){  
		maze[i][j] = 0;  
	}  

	return end;  
}  

int main(void)  
{  
	int i, j;  
	int maze[9][8] = {  
		{0,0,1,0,0,0,1,0},  
		{0,0,1,0,0,0,1,0},  
		{0,0,0,0,1,1,0,1},  
		{0,1,1,1,0,0,1,0},  
		{0,0,0,1,0,0,0,0},  
		{0,1,0,0,0,1,0,1},  
		{0,1,1,1,1,0,0,1},  
		{1,1,0,0,1,1,0,1},  
		{1,1,0,0,0,0,0,0}  
	};  
	for(i = 0; i <= 9; i++)  
		printf("-");  
	printf("\n");  
	for (i = 0; i < 9; i++){  
		printf("|");  
		for (j = 0; j < 8; j++){  
			if (maze[i][j] == 1)  
				printf("#");  
			else  
				printf(" ");  
		}  
		printf("|\n");  
	}  
	for(i = 0; i <= 9; i++)  
		printf("-");  
	printf("\n");  

	if (VistMaze(maze, 0, 0) == 0){  
		exit(0);  
	}  

	for(i = 0; i <= 9; i++)  
		printf("-");  
	printf("\n");  
	for (i = 0; i < 9; i++){  
		printf("|");  
		for (j = 0; j < 8; j++){  
			if (maze[i][j] == 1)  
				printf("#");  
			else if (maze[i][j] == 2)  
				printf("$");  
			else  
				printf(" ");  
		}  
		printf("|\n");  
	}  
	for(i = 0; i <= 9; i++)  
		printf("-");  
	printf("\n");  

	return 0;  
}  
