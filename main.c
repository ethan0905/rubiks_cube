// algorithm that solves the rubiks cube following these rules:
// 1. the cube is represented by a 3x3x3 array of integers
// 2. the cube is solved when all the faces are the same color
// 3. the cube instructions are:
//    1. "U" : rotate the top face clockwise
//    2. "B" : rotate the bottom face clockwise
//    3. "L" : rotate the left face clockwise
//    4. "R" : rotate the right face clockwise
//    5. "F" : rotate the front face clockwise
//    6. "D" : rotate the back face clockwise
//    7. "U'" : rotate the top face counter-clockwise
//    8. "B'" : rotate the bottom face counter-clockwise
//    9. "L'" : rotate the left face counter-clockwise
//    10. "R'" : rotate the right face counter-clockwise
//    11. "F'" : rotate the front face counter-clockwise
//    12. "D'" : rotate the back face counter-clockwise

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

// function prototypes
void rotate(int cube[SIZE][SIZE][SIZE], char face, char direction);
void printCube(int cube[SIZE][SIZE][SIZE]);
int isSolved(int cube[SIZE][SIZE][SIZE]);
int isUnsolvable(int cube[SIZE][SIZE][SIZE]);
int isSolvable(int cube[SIZE][SIZE][SIZE]);

int main(int argc, char *argv[])
{
	int cube[SIZE][SIZE][SIZE] = {0};
	int i, j, k;
	int count = 0;
	char face, direction;

	// initialize the cube
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			for (k = 0; k < SIZE; k++)
				cube[i][j][k] = i;

	// print the cube
	printCube(cube);

	// read the instructions
	while (scanf("%c%c", &face, &direction) != EOF)
	{
		// rotate the cube
		rotate(cube, face, direction);

		// print the cube
		printCube(cube);

		// check if the cube is solved
		if (isSolved(cube))
		{
			printf("Solved in %d moves !\n", count);
			break;
		}

		// increment the count
		count++;
	}
	
	return 0;
}

// function definitions

// rotate the cube
void rotate(int cube[SIZE][SIZE][SIZE], char face, char direction)
{
	int i, j, k;
	int temp[SIZE][SIZE][SIZE];

	// copy the cube to temp
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			for (k = 0; k < SIZE; k++)
				temp[i][j][k] = cube[i][j][k];

	// rotate the cube
	switch (face)
	{
		case 'U':
			if (direction == '\'')
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[i][j][0] = temp[SIZE - 1 - j][i][0];
			}
			else
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[i][j][0] = temp[j][SIZE - 1 - i][0];
			}
			break;
		case 'B':
			if (direction == '\'')
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[i][j][SIZE - 1] = temp[SIZE - 1 - j][i][SIZE - 1];
			}
			else
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[i][j][SIZE - 1] = temp[j][SIZE - 1 - i][SIZE - 1];
			}
			break;
		case 'L':
			if (direction == '\'')
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[i][0][j] = temp[SIZE - 1 - j][0][i];
			}
			else
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[i][0][j] = temp [j][0][SIZE - 1 - i];
			}
			break;
		case 'R':
			if (direction == '\'')
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[i][SIZE - 1][j] = temp[SIZE - 1 - j][SIZE - 1][i];
			}
			else
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[i][SIZE - 1][j] = temp[j][SIZE - 1][SIZE - 1 - i];
			}
			break;
		case 'F':
			if (direction == '\'')
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[0][i][j] = temp[0][SIZE - 1 - j][i];
			}
			else
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[0][i][j] = temp[0][j][SIZE - 1 - i];
			}
			break;
		case 'D':
			if (direction == '\'')
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[SIZE - 1][i][j] = temp[SIZE - 1][SIZE - 1 - j][i];
			}
			else
			{
				for (i = 0; i < SIZE; i++)
					for (j = 0; j < SIZE; j++)
						cube[SIZE - 1][i][j] = temp[SIZE - 1][j][SIZE - 1 - i];
			}
			break;
	}
}

// print the cube
void printCube(int cube[SIZE][SIZE][SIZE])
{
	int i, j, k;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			for (k = 0; k < SIZE; k++)
				printf("%d ", cube[i][j][k]);
			printf("\t");
		}
		printf("\n");
	}
	printf("\n");
}

// check if the cube is solved
int isSolved(int cube[SIZE][SIZE][SIZE])
{
	int i, j, k;

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			for (k = 0; k < SIZE; k++)
				if (cube[i][j][k] != cube[0][0][0])
					return 0;

	return 1;
}

// check if the cube is unsolvable
int isUnsolvable(int cube[SIZE][SIZE][SIZE])
{
	int i, j, k;
	int count = 0;

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			for (k = 0; k < SIZE; k++)
				if (cube[i][j][k] == cube[0][0][0])
					count++;

	if (count == SIZE * SIZE * SIZE)
		return 1;
	else
		return 0;
}

// check if the cube is in a state that can be solved
int isSolvable(int cube[SIZE][SIZE][SIZE])
{
	int i, j, k;
	int count = 0;

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			for (k = 0; k < SIZE; k++)
				if (cube[i][j][k] == cube[0][0][0])
					count++;

	if (count == SIZE * SIZE * SIZE - 1)
		return 1;
	else
		return 0;
}

