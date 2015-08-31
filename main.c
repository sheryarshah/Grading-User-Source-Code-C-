/****************************************************************************************
* Author: Sheyar Shah 
* Last updated: 3-25-14
* Compiler Used: Microsoft Visual Studio 2013 Professional.
* Program Description: Program written in C.
* The program reads in a source file a student wrote and and a system function is used
* to compile a program and than a system function is used to pipe the output of the program
* to a text file (output.txt). The student written program uses an input text file. The output
* of the program is than compared with results which in a seperate text file and tells
* whether the program is correct or not.
* Note: The program has bonus implemented, where the program recieves a numerical grade,
* and also the program is capable of handling expected output files of variable length
*****************************************************************************************/
#include "header.h"

int main(){

	FILE *ptr;								//pointer for a file
	char sourceFile[FILE_NAME_SIZE];		//source file written by a student that is to be graded
	char inputFile[FILE_NAME_SIZE];			//input file required for the source file
	char resultFile[FILE_NAME_SIZE];		//result file or answer key that is used to compare the result of student source code

	char command[SYSTEM_COMMAND];			//command is used for system function to compile the student source code
	char command1[SYSTEM_COMMAND];			//command1 is used to excute and run the student code and pipes the ouput to output.txt file

	int count = 0;							//variable used to keep track of elements in students output results
	int output[MAX];						//an array where output results individual integer elements are put in
	int result[MAX];						//an array where answer key results intger elements are put in


	/**************************************The files names are entered and read*******************************************/

	printf("Please enter the name of the source file in .c format: ");
	while (1){
		scanf("%s", &sourceFile);
		if ((ptr = fopen(sourceFile, "r")) == NULL) {
			printf("File not found or could'nt be opened, please re-enter: ");
			continue;
		}

		break;
	}

	printf("\nPlease enter the name of the input file in .txt format: ");
	while (1){
		scanf("%s", &inputFile);
		if ((ptr = fopen(inputFile, "r")) == NULL) {
			printf("File not found or could'nt be opened, please re-enter: ");
			continue;
		}

		break;
	}

	printf("\nPlease enter the name of the expected result file: ");
	while (1){
		scanf("%s", &resultFile);
		if ((ptr = fopen(resultFile, "r")) == NULL) {
			printf("File not found or could'nt be opened, please re-enter: ");
			continue;
		}

		break;
	}

	answerKey(ptr, result, count);
	/************************FOR WINDOWS******************************/
	/*compling the program*/
	
	strcpy(command, "gcc ");
	strcat(command, sourceFile);
	strcat(command, " -o grader");
		//gcc sourceFile.c - o program
	
	/*executing the program*/
	strcpy(command1, "grader.exe ");
	strcat(command1, inputFile);
	strcat(command1, " > output.txt");
		//program.exe inputFile.txt > output.txt

	/************************FOR UNIX********************************/
	/*Compiling the program*/
	/*
	strcpy(command, "gcc -o grader ");
	strcat(command, sourceFile);
	//     gcc -o program myProg1.c
	*/
	/*Executing the program*/
	/*
	strcpy(command1, "./grader ");
	strcat(command1, inputFile);
	strcat(command1, " > output.txt");
	//    ./program input.txt > output.txt
	*/

	system(command);					//compiling the program
	system(command1);					//executing the program

	count_program_results(ptr, output);

	count = count_program_results(ptr, output);

	grade_program(ptr, output, result, count);

	fclose(ptr);

	getchar();							//helps keep cmd open (necessary for this compiler)
	getchar();							//helps keep cmd open (necessary for this compiler)

	return 0;

}

