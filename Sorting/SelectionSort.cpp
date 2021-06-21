#include <iostream>
using namespace std;
  
void SelectionSort(int A[], int n)
{
    for(int i=0; i<n-1; i++){
        int iMin = i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[iMin]){
                iMin = j;
            }
        int temp = A[iMin];
        A[iMin] = A[i];
        A[i] = temp;
        }
    }
}