/*
 * CSCI 112 - LAB 8
 * Anthony Skinner
 * 4/15/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 25

typedef struct{
	int sid;
	char lname[NAME_SIZE];
	char fname[NAME_SIZE];
	float *grades;
	float gpa;
}student_t;

void freeUp(student_t * stud, int totalS){
	int i;
	for(i = 0; i < totalS; i++){
		
		free((stud+i)->grades);
		(stud+i)->grades = NULL;	
	}
	free(stud);
	stud = NULL;
}

void print(student_t *stud, int tS, int tG){
	int i;
	int j;
	for(i = 0; i < tS; i ++){
		printf("ID: %d, Name: %s %s, GPA: %.2f\nGrades: ", (stud+i)->sid,(stud+i)->fname,(stud+i)->lname,(stud+i)->gpa);
		for(j =0; j < tG; j++){
		//need to fix
			printf("%.1f ",stud[i].grades[j]);// this is the part that is broken
			//prints this error: lab8.c:38: error: expected identifier before ‘*’ token
			//I have tried using the dot notation and arrow notation to get the grades
		}	
		printf("\n");
	}	

}

student_t input(int totalG){
	student_t st;	

	scanf("%d %s %s", &st.sid, st.lname, st.fname);
	float *gr = (float *)calloc(totalG, sizeof(float));
	int i;
	float sum = 0.0;
	//scan in grades
	for(i = 0; i < totalG; i++){
		scanf("%f", gr+i);
		sum += *(gr+i);
	}
	//store grades in student struct
	st.grades = gr;	
	st.gpa = (sum/((float)totalG));
	return st;
}

int main(int argc, char * argv[]){
	FILE *fr;
	student_t *std;
	if( argc == 1){
		int totalS;
		int totalG;

		scanf("%d", &totalS);
		scanf("%d", &totalG);
		printf("Number of students: %d.\nNumber of grades (each): %d.\n",totalS,totalG);
		std = (student_t*)calloc(totalS,sizeof(student_t));	
		int i;
		for(i = 0; i < totalS; i++){
			//scan the students in
			*(std + i) = input(totalG);
		}

		print(std, totalS, totalG);

		freeUp(std,totalS);

	}
	else if( argc > 1){
		fr = fopen(argv[1], "r");
		char line[256];
		fgets(line, 5, fr);
		char * cTs;
		cTs = strtok(line, " ");
		char * cTg; 
		cTg = strtok(NULL, " ");
		int i;
		for(i = 0; i < 5;){
		} 	





			
	}	
	return 0;
}	
