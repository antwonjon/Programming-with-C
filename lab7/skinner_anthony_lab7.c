/*
 * CSCI 112- LAB7
 * Anthony Skinner
 * 4/12/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
//element structure
typedef struct element_t{
	int number;
	char name[30];
	char sym[5];
	char class[50];
	double weight;
	int atom[7];
} element_t;

void print_element(int total, element_t array[], char lg[], char sm[]){
	//print total, largest and smallest numbers
	printf("%d total elements.\n%s had the smallest atomic number.\n%s had the largest atomic number.\n", total, sm, lg);
	int i;
	char line[] = "---------------";
	//loop through the array elements
	for(i=0; i < total; i++){
		printf("%s\n", line);
		printf("| %d\t%.4f\n",array[i].number,array[i].weight);
		printf("| %s\t%s\n",array[i].sym,array[i].name);
		printf("| ");
		int j;
		//print the electrons
		for(j = 0; j < 7; j++){
			if(array[i].atom[j]>0){
				printf("%d ", array[i].atom[j]);
			}
		}
		printf("\n%s\n", line);
	}
		
}
void scan_element(int total){
	int i;
	struct element_t array[total];
	char sm[30];
	char lrg[30];
	int smallest = 999;
	int largest = 0;
	for(i = 0; i < total; i++){				
		//scan in the elements attributes
		scanf("%d %s %s %s %lf %d %d %d %d %d %d %d", 
			&array[i].number,
			array[i].name,
			array[i].sym,
			array[i].class,
			&array[i].weight,
			&array[i].atom[0],
			&array[i].atom[1],
			&array[i].atom[2],
			&array[i].atom[3],
			&array[i].atom[4],
			&array[i].atom[5],
			&array[i].atom[6]
			);
		//get smallest and largest atomic numbers
		if(array[i].number<smallest){
			memset(sm, '\0', sizeof(sm));
			smallest = array[i].number;
			strcpy(sm, array[i].name);
		}
		if(array[i].number>largest){
			memset(lrg, '\0', sizeof(lrg));
			largest = array[i].number;
			strcpy(lrg, array[i].name);
		}			
        }
	//print elements	
	print_element(total, array, lrg, sm);
	
}
	
int main (int argc, char* argv[]){
	
	//convert input
	int n = (int) strtol(argv[1], NULL, 10);
	//only scan element if it meets the prerequisites
	if( argc == 2 && 0 < n && n <= 20){
	
		scan_element(n);
	}else{
		//print ERRORS
		if(argc < 2 || argc > 2){
			printf("ERROR: You must provide exactly one argument to this program.\n");
		}else{
			printf("ERROR: You must provide an integer greater than 0 and less or equal to 20.\n");
}
}
}	
