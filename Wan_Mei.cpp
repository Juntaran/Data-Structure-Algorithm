
/*
 * a balls, n floors, want to find the minimum number of floor
 * where a ball drops will be broken. output the minimum number
 * of drops
 * METHOD: dynamic programming
 * assum the answer is b, that is the number of drops
 * f(a, b): the maximum number of floors, when a balls and b drops
 * f(a, b) = 1 + f(a, b - 1) + f(a - 1, b - 1)
 * obviously, f(a, 1) = 1; f(1, b) = b
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temp[10001][10001];

int calcThrowNumberCore(int i, int j)
{
	if (temp[i-1][j-1] != NULL)
		return temp[i-1][j-1];
	temp[i-1][j-1] = calcThrowNumberCore(i-1, j-1) + calcThrowNumberCore(i, j-1) + 1;
	
	return temp[i-1][j-1];
}


int calcThrowNumber(int numOfFloors, int numOfBalls)
{
	//implement your code here
	memset(temp, 0, sizeof(temp));
	for (int i = 1; i < 10001; i++)
	{
		temp[i-1][0] = 1;
	}
	for (int i = 1; i < 10001; i++)
	{
		temp[0][i-1] = i;
	}
	
	int left = 1;
	int right = numOfFloors;
	int middle;
	int count = 0;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (calcThrowNumberCore(numOfBalls, middle) + 1 < numOfFloors)
			left = middle + 1;
		else
			right = middle - 1;
	}
	count = left;

	return count;
}

int main()
{
	int numOfFloors, numOfBalls;
	while (scanf("%d%d", &numOfFloors, &numOfBalls) != EOF) 
	{
		printf("%d\n", calcThrowNumber(numOfFloors, numOfBalls));
	}
}
