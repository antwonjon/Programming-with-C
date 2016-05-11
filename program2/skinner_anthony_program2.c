/*
 * CSCI 112 - PROGRAM 2
 * Anthony Skinner
 * 4/5/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//this function uses a switch statement to change words to their plurals
void pluralize(char arg[]){
	
	printf("noun: %s\n", arg);
	int len = strlen(arg);
	//I ran into a memory issue where I was overwriting words so I had create a new word 
	//instead of just using arg
	char word[len+2];
	strcpy(word, arg);
	//these are the conditions for pluralizing
	switch(arg[len-1]){
		case 'y':
			word[len-1] = 'i';
			//I didn't ever think I would NOT use a break... then I did... mind blown			
		case 's':
			strcat(word, "es");
			break;
		case 'h':
			if(word[len-2]=='s' || word[len-2] == 'c'){
				strcat(word,"es");
			}
			break;
		default:
			strcat(word, "s");
		}
	//here is the final outcome
	printf("plural: %s\n\n", word);
}
int main( int argc, char* argv[]){
	//this catches if there is no input
	if(argc > 1){
		int count;
		for (count = 1; count < argc; count++){
		//	printf("arg[%d] is %s\n", count, argv[count]);
			pluralize(argv[count]);	
		}
	
	}
	//this is the catch
	else{
		printf("ERROR: You must pass the nouns to be pluralized as program arguments\n");
	}
	return 0;
}		
