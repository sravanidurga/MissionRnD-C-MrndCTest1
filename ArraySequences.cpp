/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	int d = -1, r = -1, i = 0, j = 1, k = 2, a[6] = { 0 }, flag = 0;
	if (arr == NULL || len <0)
		return NULL;
	while (k<len)
	{
		if (len < 3)
			return NULL;
		if (*(arr + i)*(*(arr + k)) == *(arr + j)*(*(arr + j)))
		{
			r = *(arr + (i + 1)) / (*(arr + 0));
		}
		else if (*(arr + i) + *(arr + k) == 2 * (*(arr + j)))
		{
			d = *(arr + j) - *(arr + i);
		}
		if (d == -1 && r == -1)
		{
			i++;
			j = i + 1;
			k = i + 2;
		}
		if (d != -1)
		{
			a[flag] = i;
			flag++;
			while (*(arr + i) + d == *(arr + (i + 1)))
			{
				i++;
			}
			a[flag] = i;
			flag++;
			d = -1;
		}

		if (r != -1)
		{
			a[4] = i;
			while (*(arr + i) * r == *(arr + (i + 1)))
			{
				i++;

			}
			a[5] = i;
			r = -1;
		}
		
		j = i + 1;
		k = i + 2;

		if (i >= len)
			break;

	}

	for (j = 0; j<6; j++)
	{
		if (*(a + j) == 0 && *(a + (j + 1)) == 0)
			break;
	}
	*(a + j) = i;
	*(a + (j + 1)) = len - 1;

	return a;
}
