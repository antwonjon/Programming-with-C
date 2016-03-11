/*
 * Anthony Skinner
 * CSCI 112 - Lab 5
 * 3/3/16
 */
//include alot of libraries
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//initialize methods
int validCode(char *bar, int bC[]);
int stepOne(int bC[]);
int stepTwo(int bC[]);
int stepThree(int odd, int even);
int stepFour(int sum);
void stepFive(int checkD, int lastD);


int main (void){
	//break down problem into sub problems
	char * bar = (char *) malloc(sizeof(char) * 25);
	int bC[12];
	validCode(bar, bC);	//is the code valid?
		
	int odd = stepOne(bC); // what is the sum of the odd numbers times 3 in the array?
	int even = stepTwo(bC); // what is the sum of the even integers in the array?
	int sum = stepThree(odd, even); // what is total of the odd and even ints in the array excluding the final position?
	int checkD = stepFour(sum); // what is the final number that should be appearing in the final position? take the mod of the sum and subtract it from 10
	stepFive(checkD, bC[11]); // are the final position and the number we expected the same?
	return 0;
}

//this method sums the odds and then times' it by 3
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

//this method finds the even ints in the array
int stepTwo(int bC[]){
	int i;
	int sum = 0;
	for(i = 1; i < 11; i+=2){
		sum += bC[i];
	}
	
	printf("STEP 2: Sum of the even digits is %i\n", sum);
	return sum;
}

//this method adds the result of the last two methods together
int stepThree(int odd, int even){
	int sum = odd + even;	
	printf("STEP 3: Total sum is %i\n", sum);
	return sum;	
}

//this method calculates the expected last digit in the array
int stepFour(int sum){
	int lastD = 10 - sum%10;
	printf("STEP 4: Calculated check digit is %i\n", lastD);
	return lastD;
}

//this method checks if the expected last digit and the actual last digit are the same in the array
void stepFive(int checkD, int lastD){
	printf("STEP 5: Check digit and last digit ");
	if(checkD == lastD){
		printf("match\nBarcode is VALID.\n");
	}else{
		printf("do not match\nBarcode is INVALID.\n");
	}
}



//this method makes sure that there is valid code input using a recursive call
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


//I probably made this a little bit harder than was necessary but I think I got it
//If there are 
//any questions
//my email is
//anthonyjohnskinner@gmail.com






//here are a
//few more comments
//just in case
//my code isn't readable 
//enough,
// savvy?