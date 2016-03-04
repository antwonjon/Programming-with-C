/*
 * Anthony Skinner
 * CSCI 112 - Lab 3
 * 2/19/16
 * 
 */
#include <math.h>
#include <stdio.h>


/*initialize variables and methods*/
typedef enum{
	Sine,
	Cosine,
	Tangent,
	QUIT
} menu_t;
int is_valid(menu_t);

/*initialize PI and LOOP_LIMIT*/
#define PI 3.14159
#define LOOP_LIMIT 90


int main (void){
	menu_t input;
	do
	{
	printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\nEnter your choice > ");
	scanf("%u", &input);
	
	//initialize local variables 
	int d = 0;
	double r;
	double result;
	
		//switch on input using ENUM values
		switch(input)
		{	//print of Sine values
			case Sine:
				while(d<=LOOP_LIMIT){
					//convert to radians
					r = PI * d/180;
					//use sin() function from math library to convert result
					result = sin(r);
					//print results
					printf("\tsin(%d) = %.4f\n", d, result);
					//increment degrees by 15
					d+=15;
				}
				break;	
			case Cosine:
					//use while loop because a for loop throws an error for some reason in C
				while(d<=LOOP_LIMIT){
					r = PI * d/180;
					result = cos(r);
					printf("\tcos(%d) = %.4f\n", d, result);
					d+=15;
				}
				break;
			case Tangent:
				while(d<=LOOP_LIMIT){
					if(d == 90.0){
					printf("\ttan(%d) is UNDEFINED\n",d);
					}
					else{
					r = PI * d/180;
					result = tan(r);
					printf("\ttan(%d) = %.4f\n", d, result);
					}
					d+=15;
				}
				break;
			case QUIT:
				printf("You chose QUIT. Thank you, come again!\n");
				break;
			default:
				printf("%d is an invalid option. Please try again.\n", input);				
			break;
		}
	
	}
	//stops loop on QUIT ENUM
	while(input != QUIT);
	//return 0 
	return (0);
}

	
