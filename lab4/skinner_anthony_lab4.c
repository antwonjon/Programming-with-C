/*
 * Anthony Skinner
 * CSCI 112 - LAB 4
 * 2/26/16
 *
 */
#include <math.h>
#include <stdio.h>

//List of all function prototypes

//displays user menu, reads input, and validates input
int user_menu();

// Equation functions that are pass by reference 
void equation1(float *);            // calculate motion equation 1
void equation2(float *);            // calculate motion equation 2
void equation3(float *);            // calculate motion equation 3
void equation4(float *);            // calculate motion equation 4

// User input functions return a value from user
float get_position_initial(void);   // Prompts user for x0
float get_position_final(void);     // Prompts user for xf
float get_velocity_initial(void);   // Prompts user for v0
float get_velocity_final(void);     // Prompts user for vf
float get_acceleration(void);       // Prompts user for a
float get_time(void);               // Prompts user for t



int main(void){
	//Print welcome message
	printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");
	
	//Variable for the user choice
	int user_choice;
	
	do{
		user_choice = user_menu(); //print menu, validate choice between 1 and 5

		//You will pass the address of this variable to your equation functions
		float result;		//Variable to hold calculated result
		
		//Handle menu choice selected by user
		switch(user_choice){
			
			case 1:
				equation1(&result);
				//given the initial velocity, accelaration and time, this equation returns 
				//the final velocity
				break;
			case 2:
				equation2(&result);
				//given the initial position, initial velocity, time and acceleration, this equation returns
				// the final position
				break;
			case 3:
				equation3(&result);
				//given the intial velocity, acceleration, initial and final position, the equation returns	
				//the final velocity 
				break;
			case 4:
				equation4(&result);
				//given initial position, final and initial velocity, and time the equation returns
				//the final position
				break;
			case 5:
				//EXIT PROGRAM IF USER SELECTED QUIT
				printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
				return 0;
				break;
			}
		printf("Your result is %.4f.\n\n", result);

	} while (user_choice != 5);
	
	return 0; //exit with no error
}

int user_menu(){
	//take in user input
	int input;
	do{
	printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
	scanf("%d", &input);
		if( input < 1 || input > 5){
		printf("Invalid Option. Please try again.\n");
		}
	//if they take in wrong input, repeat the code
	}while(input < 1 || input > 5);
	
	//return the input
	return input;
}


void equation1(float* vf){
	float v = get_velocity_initial();
	float a = get_acceleration();
	float t = get_time();
	*vf = v + a * t;
}

void equation2(float* xf){
	float p = get_position_initial();
	float v = get_velocity_initial();
	float t = get_time();
	float a = get_acceleration();
	*xf = p + v * t + .5 * a * pow(t,2);
}	


void equation3(float* vf){
	float v = get_velocity_initial();
	float a = get_acceleration();
	float fp = get_position_final();
	float ip = get_position_initial();
	*vf = sqrt(pow(v,2)+2*a*(fp-ip));
}


void equation4(float* xf){
	float ip = get_position_initial();
	float fv = get_velocity_final();
	float iv = get_velocity_initial();
	float t = get_time();
	*xf = ip + (.5 * ( fv + iv ) * t);
}

float get_position_initial(void){
	float iP;
	printf("\tEnter initial position > ");
	scanf("%f", &iP);
	return iP;
}

float get_position_final(void){
	float fP;
	printf("\tEnter final position > ");
	scanf("%f", &fP);
	return fP;
}

float get_velocity_initial(void){
	float iV;
	printf("\tEnter initial velocity > ");
	scanf("%f", &iV);
	return iV;
}

float get_velocity_final(void){
	float fV;
	printf("\tEnter final velocity > ");
	scanf("%f", &fV);
	return fV;
}

float get_acceleration(void){
	float ac;
	printf("\tEnter acceleration > ");
	scanf("%f", &ac);
	return ac;
}

float get_time(void){
	float t;
	printf("\tEnter time > ");
	scanf("%f", &t);
	return t;
}
 

