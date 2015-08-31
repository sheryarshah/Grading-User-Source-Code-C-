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

#define _CRT_SECURE_NO_DEPRECATE		//needed for this specific complier, ignores unnessary warnings
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME_SIZE 20		//number of characters allowed for file name
#define MAX 50					//max number of output result values allowed
#define SYSTEM_COMMAND 100		//max characters allowed in total for system function

void answerKey(FILE *ptr, int result[], int count);					  /*in this function the answer key is printed*/
int count_program_results(FILE *ptr, int output[]);					  /*in this function the program is read and counts how many digits there are*/
int grade_program(FILE *ptr, int output[], int result[], int count);  /*in this function the program is graded and is given a numerical grade*/


