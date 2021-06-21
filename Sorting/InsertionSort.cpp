#include <iostream>
  
using namespace std;
  
// A function to implement bubble sort 
void InsertionSort(int arr[], int n)
{ 
    int i;
    for(i=1; i<n;i++){
        int value = arr[i];
        int hole = i;
        while(hole>0 && arr[hole-1]>value){
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
} 