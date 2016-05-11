/*
 * CSCI 112 - LAB 9
 * Anthony Skinner
 * 4/20/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 25
//delcare struct
typedef struct{
	int num;
	char sym[NAME_SIZE];
	char name[NAME_SIZE];
	float weight;
	char state[NAME_SIZE];
	char type[NAME_SIZE];
	char year[NAME_SIZE];
} element_t;

// check if the argument is a file
int checkInput(char * arg){
	char * pch;
	pch = strchr(arg, '.');
	if(pch!=NULL){
		return 1;
	}			

	return 0;
}

//load file into array of structures
void loadFile(FILE *fp, element_t * list){
	char line[256];
	
	if(fp){
		int i = 0;
		int j;
		while(fgets(line, 256, fp)!=NULL){
			element_t new;
			
			//break the line into seperate pieces and place them in the struct
			char * tok = strtok(line,",");			
			
			new.num = atoi(tok);
			tok = strtok(NULL, ",");					
			
			
			for (  j= 0; j <= sizeof(tok) / sizeof(char); j++) {
				new.sym[j] = *(tok + j);
			}
			
			tok = strtok(NULL, ",");			
			
			for(j = 0; j <= sizeof(tok)/sizeof(char); j++){
				new.name[j] = *(tok+j);
			}
			tok = strtok(NULL, ",");
			
					
			new.weight = atof(tok);
			
			//if i didn't do this it created a segmentation fault
			if(i<=98){
				tok = strtok(NULL, ",");
				for(j = 0; j <= sizeof(tok)/sizeof(char); j++){
					new.state[j] = *(tok+j);
				}
						
		
			
				
				if(i < 98){
					tok = strtok(NULL, ",");
					for(j = 0; j<= sizeof(tok)/sizeof(char); j++){
						new.type[j] = *(tok+j);
					}
				}
			}
			tok = strtok(NULL, ",");
			
			for(j =0; j <= sizeof(tok)/sizeof(char); j++){
				new.year[j] = *(tok+j);
			}
			
			list[i] = new;
			//printf("New name: %s\n", list[i].name);	
			i++;	
		}

	}

}
//return the position of the element or -1
int search(char sym[], element_t list[]){
	int i;
	for(i = 0; i < 118; i++) {
		if(strcmp(sym,list[i].sym) == 0){
			return i;
		}
	}	

	return -1;
}

//print the output to terminal
void printOutput(int count, char * params[], element_t list[]){
	int i;
	int s;
	for( i = 1; i < count; i++){
		s = search(params[i], list);	
		if( s > -1){
			printf("---------------\n| %d\t%.4f\n| %s\t%s\n| %s\n| %s\n| Found: %s\n---------------\n",
			list[s].num,
			list[s].weight,
			list[s].sym,
			list[s].name,
			list[s].state,
			list[s].type,
			list[s].year);

		}else{
			printf("WARNING: No such element: %s\n", params[i]);
		}

	}

}

//print the output to File
void printToFile(int count, char * params[], element_t list[]){
	int i;
	int s;
	FILE * output;
	output = fopen(params[1], "w");
	//comments are the best
	for(i = 2; i < count;i++){
		s = search( params[i], list);
		if(s > -1){
		 	fprintf(output,"---------------\n| %d\t%.4f\n| %s\t%s\n| %s\n| %s\n| Found: %s\n--------------\n",
			list[s].num,
			list[s].weight,
			list[s].sym,
			list[s].name,
			list[s].state,
			list[s].type,
			list[s].year);
                
	
		}else{
			fprintf(output, "WARNING: No such element: %s\n",params[i]);	
		}	
	}
	fclose(output);	
}

//declare main function
int main(int argc, char * argv[]){
	FILE *fp;
	if(argc > 1){
		
		element_t * list;
		list = (element_t*)malloc(118* sizeof(element_t));
		fp = fopen("element_db.csv", "r");
				
		loadFile(fp, list);
		
		int check = checkInput(argv[1]);
		if( check > 0){
			printToFile(argc, argv, list);
		}
		else{
			printOutput(argc, argv,list);
		}			
		fclose(fp);
	}else{
		printf("ERROR: Please provide at least one program argument.\n");
	}
	
	return 1;
}
