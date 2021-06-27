#include <iostream>

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


void heapify(int tree[], int n, int i)
{
	if (i >= n) {
		return;
	}
	
    int max = i;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;

    if (c1 < n && tree[max] < tree[c1]){
    	max = c1;
    }
    if (c2 < n && tree[max] < tree[c2]){
    	max = c2;
    }
    if ( i != max){
    	swap(tree, i, max);
    	heapify(tree, n, max);
    }
}

void build_heap(int tree[], int n){
	int last_node = n - 1;
	int parent = (last_node - 1) / 2;
	for(int i = parent; i >= 0; --i){
		heapify(tree, n, i);
	}
}

void heap_sort(int tree[], int n){
	build_heap(tree, n);
	int i;
	for(i = n - 1; n >= 0; i--){
		swap(tree, i, 0);
		heapify(tree, i, 0);
	}
}

int main(){
	int size = 6;
	int arr[] = {2, 5, 3, 1, 10, 4};

	heap_sort(arr, size);
	// heapify(tree, size , 0);	

	int i;
	for(i = 0; i < size; ++i ){
		printf("%d\n", arr[i]);
	}
}
