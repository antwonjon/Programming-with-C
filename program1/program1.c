/*
 * Anthony Skinner
 * CSCI 112 - PROGRAM 1
 * 3/11/2016
 */
#include <stdio.h>
//define the max size of array
#define MAX_ARRAY_SIZE 50
int populate_array( int array[] );                   // Fill array with values from user.
void print_array( int array[], int n );              // Print out the array values
void swap( int array[], int index1, int index2 );    // Swap two array elements. 
void quicksort( int array[], int low, int high );    // Sorting algorithm
int partition( int array[], int low, int high );     // Find the partition point (pivot)

int main(void){
	//creates an array of the maximum size
	int array[MAX_ARRAY_SIZE];
	int total = populate_array(array);
	printf("The initial array contains:\n");
	print_array(array, total);
	quicksort(array, 0, total-1);
	printf("The array is now sorted:\n");
	print_array(array, total);	
	return 0;
}

int populate_array(int array[]){
	int total;
	do{
		printf("Enter the value of n > ");
		scanf("%d", &total);
		if(total < 0){
			//when its too small
			printf("%d is less than zero. Please try again.\n", total);
		}else if( total > MAX_ARRAY_SIZE){
			//when its too large
			printf("%d exceeds the maximum array size. Please try again.\n", total);
		}
	
	//while catches when its an array of size zero as well as when its exceeds maximum size	
	}while(total < 1 || total > MAX_ARRAY_SIZE);
	printf("Enter %d integers(positive, negative, or zero) >\n", total);
	int i;
	int input;
	for(i = 0; i < total; i++){
		scanf("%d", &input);
		array[i] = input;
		
	}
	return total;

}

//prints the array
void print_array( int array[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%+5d\n", array[i]);
	}
}

//swaps the location of the two indices
void swap(int array[], int index1, int index2){
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

//quicksort!!!
void quicksort(int array[], int low, int high){
	if(low<high){

		int pivot = partition(array, low, high);
		//sort to the left sub array
		quicksort(array, low, pivot - 1);
		//sort to the right sub array
		quicksort(array, pivot+1, high);
	}
	
}


int partition(int array[], int low, int high){
	int pivot = array[high];
	int i = low;
	int j;
	//starts arranging the array so that everything is to the left and right of the pivot
	for(j = low; j <= high-1; j++){
		if(array[j] <= pivot){
			//swap individual elements so that the elements that are greater are to right and the elements that are lesser are to the left
			swap(array, i, j);
			i++;
		}
	}
	//swaps the last little bit to get the pivot in place
	swap(array, i, high);	
	
	return i;
}	
	
