#include <iostream>
using namespace std;
  
void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void bubbleSort(int arr[], int n) 
{ 
	int i, j, is_swap = 0; 
	for (i = 0; i < n-1; i++)	 
	{
		is_swap=0;
		// Last i elements are already in place 
		for (j = 0; j < n-i-1; j++) 
			if (arr[j] > arr[j+1]) 
			{	
				swap(&arr[j], &arr[j+1]); 
				is_swap=1;
			}
		if(is_swap==0)
			break;
	}
} 
