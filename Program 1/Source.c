//PROG71985F21 - Week 14 - Assignment Group Project - The program manages a person's tasks 
//Source file
//Gurjit Singh and David Oladimeji - December 7 - 2021 


#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "Source.h" 


#define NUMOFTASKS 10 
#define NEWTASKLENGTH 50 
#define FORLOOPEND 20 


int main(void)
{
    displayMenu(); 

    char menuInput = 0;
    scanf("%c", &menuInput); 

    switch (menuInput) 
    {
    case 'a':
    {
        addNewTask();
        //addNewTask();

        break;
    }
    case 'b':
    {
        printf("Feature still not added\n"); 

        break;
    }
    case 'f':
    {
        printf("\nBYE!\n");

        break;
    }
    default:
    {
        printf("\nEnter correct option\n");
    }
    } 

	return 0; 
} 


void displayMenu()
{
    printf("***************\n\
    \r Tasks Manager\n\
    \r***************\n\n\
    \rTo choose an option, enter its letter label:\n\
    \ra) To add a new task\n\
    \rb) \n\
    \rf) Quit\n"); 
}


void addNewTask()
{
    TASKS tasksList; 

    FILE* fp = fopen("tasksSaveFile.txt", "a");

    if (fp == NULL)
    {
        printf("Can't open file %s\n", fp);
        exit(EXIT_FAILURE);
    }

    char* newTask[NEWTASKLENGTH]; 

    //int bookingNamesNum;
    //char* firstName = malloc(sizeof(char) * (bookingStatusLength + 1));
    //char* lastName = malloc(sizeof(char) * (bookingStatusLength + 1));

    printf("\nEnter the task information you would like to add:\n"); 
    fgets(newTask, sizeof(newTask), stdin);
    //scanf("%s", newTask, NEWTASKLENGTH); 
    //while ((newTask = getchar()) != '\n' && newTask != EOF);
    /* while (fgets(newTask, sizeof(newTask), stdin) != EOF)
    {
        fgets(newTask, sizeof(newTask), stdin); 
    } */ 
    tasksList.newTask = newTask; 

    fprintf(fp, "%s", tasksList.newTask); 
    printf("\nTask added\n"); 

    fclose(fp); 

    return 0;
}