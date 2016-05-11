/*
 * CSCI 112 - LAB 6
 * Anthony Skinner 
 * 4/1/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//total size of the input 
#define SIZE 80

void reverse(char line[]){
	//initialize all local variables
	char temp[SIZE] = "";
	char word[SIZE] = "";
	int idx = strlen(line);
	int word_len = 0;	
	//scan through characters one by one
	while(0 <= idx){
		
		//only adds words if they are alphnumeric	
		if(isspace(line[idx]) && word_len > 0){
					
			//copy word to temp
			
			strncpy(word, &line[idx+1], word_len);
			
			//add space to end of each word
			strcat(word, " ");
			
			//add word to temp
			strcat(temp, word);
			
			//rewrite old word space
			memset(word,'\0',word_len+1);	
		
			word_len = 0;
		}
		else if(isalnum(line[idx])){
			word_len += 1;
		
		}
			
		idx--;

	}
	//catches the last word	
	if(word_len > 0){
					
		strncpy(word,&line[0], word_len);
		strcat(word, " ");
		strcat(temp, word);
	}	
	
	printf("%s\n", temp);		
	
}

//main function takes in a specified number of arguments
int main(int argc, char* argv[]){
	//convert input parameter to integer
	int n = (int) strtol(argv[1], NULL, 10);
	if(argc >= 2 && n >= 0){
		int i;
		//repeat this as many times as the user asks in the arg	
		for(i=0; i < n; i++){
			char str[SIZE];
			
			if( fgets(str, SIZE, stdin)){
		
				reverse(str);
				
			}
		}
	
	}
	else{
		printf("ERROR: Please provide an integer greater than or equal to 0\n");
	}
	return 0;
}
