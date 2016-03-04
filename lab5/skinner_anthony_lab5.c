/*
 * Anthony Skinner
 * CSCI 112 - Lab 5
 * 3/3/16
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int validCode(char *bar, int bC[]);
int stepOne(int bC[]);
int stepTwo(int bC[]);
int stepThree(int odd, int even);
int stepFour(int sum);
void stepFive(int checkD, int lastD);

int main (void){
	char * bar = (char *) malloc(sizeof(char) * 25);
	int bC[12];
	validCode(bar, bC);	
	int odd = stepOne(bC);
	int even = stepTwo(bC);
	int sum = stepThree(odd, even);
	int checkD = stepFour(sum);
	stepFive(checkD, bC[11]);		
	return 0;
}

int stepOne(int bC[]){
	int i;
	int sum = 0;
	for(i = 0; i < 12; i+=2){
		sum += bC[i];
	}
	int result = sum * 3;
	printf("STEP 1: Sum of odds times 3 is %i\n", result);
	return result;
}


int stepTwo(int bC[]){
	int i;
	int sum = 0;
	for(i = 1; i < 11; i+=2){
		sum += bC[i];
	}
	
	printf("STEP 2: Sum of the even digits is %i\n", sum);
	return sum;
}

int stepThree(int odd, int even){
	int sum = odd + even;	
	printf("STEP 3: Total sum is %i\n", sum);
	return sum;	
}

int stepFour(int sum){
	int lastD = 10 - sum%10;
	printf("STEP 4: Calculated check digit is %i\n", lastD);
	return lastD;
}

void stepFive(int checkD, int lastD){
	printf("STEP 5: Check digit and last digit ");
	if(checkD == lastD){
		printf("match\nBarcode is VALID.\n");
	}else{
		printf("do not match\nBarcode is INVALID.\n");
	}
}




int validCode(char * bar, int bC[]){
	//takes in user input
	char input[25];	
	printf("Enter a bar code to check. Seperate with a space >\n");
	fgets(input, 25, stdin);
 	char *token = strtok(input, " ");
	int i = 0;
	
	while(token){
		bar[i] = *token;
		token = strtok(NULL, " ");
		i++;
		}

	//checks to see if it was valid input
	if( i != 12){
		printf("\n\nThat was invalid input, try again.\n");	
		validCode(bar, bC);
		return 0;
	}
	int j;
	printf("\nYou entered the code:");	
	for (j =0 ; j < 12; j++){
		//converts from char to int
		bC[j] = *(bar+j)-'0' ;
		printf(" %d", bC[j]);
	}	
	printf("\n");	
	return 0;	
}
