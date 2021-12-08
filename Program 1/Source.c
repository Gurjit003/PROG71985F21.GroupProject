//PROG71985F21 - Week 14 - Assignment Group Project - The program manages a person's tasks 
//Source file
//Gurjit Singh and David Oladimeji - December 7 - 2021 


#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "Source.h" 
#include <stdbool.h> 


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

        break;
    }
    case 'b':
    {
        showAllTasks();
        deleteTask();

        break;
    }
    case 'c':
    {
        printf("feauture hasn't been added yet\n");

        break;
    }
    case 'd':
    {
        displaySpecificTask();

        break;
    }
    case 'e':
    {
        printf("feauture hasn't been added yet\n");

        break;
    }
    case 'f':
    {
        showAllTasks(); 

        break;
    }
    case 'g':
    {
        printf("feauture hasn't been added yet\n");

        break;
    }
    case 'h':
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
    \ra) Add a new task\n\
    \rb) Delete a task\n\
    \rc) Update a task\n\
    \rd) Display specific task\n\
    \re) \n\
    \rf) Display all tasks\n\
    \rg) \n\
    \rh) Quit\n");
}
//Search for a task

void addNewTask()
{
    TASKS tasksList;

    FILE* fp = fopen("Tasks.txt", "a");

    if (fp == NULL)
    {
        printf("Can't open file %s\n", fp);
        exit(EXIT_FAILURE);
    }

    char* newTask[NEWTASKLENGTH];

    printf("\nEnter the task information you would like to add:\n");
    fgets(newTask, sizeof(newTask), stdin);
    fgets(newTask, sizeof(newTask), stdin);
    //scanf("%s", newTask, NEWTASKLENGTH);
    
    tasksList.newTask = newTask;

    fprintf(fp, "%s", tasksList.newTask);
    printf("\nTask added\n");

    fclose(fp);

    return 0;
}


void showAllTasks()
{
    FILE* fp;
    int ch;
    unsigned long count = 0;

    if ((fp = fopen("Tasks.txt", "r")) == NULL)
    {
        printf("Can't open file\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
}


void deleteTask()
{
    FILE* fp, * fptemp;
    char ch[NEWTASKLENGTH];
    int delete = 0;
    char tempfile[NEWTASKLENGTH];

    strcpy(tempfile, "temp____");
    strcat(tempfile, "Tasks_txt");

    printf("\n");
    printf("which line would you like to delete: ");
    scanf_s("%d", &delete);

    fp = fopen("Tasks.txt", "r");
    fptemp = fopen(tempfile, "w");

    bool keep_reading = true;
    int current_line = 1;

    do
    {
        fgets(ch, NEWTASKLENGTH, fp);
        if (feof(fp))
        {
            keep_reading = false;
        }
        else if (current_line != delete)
        {
            fputs(ch, fptemp);
        }
        current_line++;
    } while (keep_reading);

    fclose(fp);
    fclose(fptemp);

    remove("Tasks.txt");
    rename(tempfile, "Tasks.txt");
}


void displaySpecificTask()
{
    int line;

    printf("what like of task will you like to be shown: ");
    scanf_s("%d", &line);

    FILE* fp = fopen("Tasks.txt", "r");
    if (fp == NULL)
    {
        perror("Unable to open file");
        exit(1);
    }

    bool keep_reading = true;
    int current_line = 1;
    char ch[NEWTASKLENGTH];

    do
    {
        fgets(ch, NEWTASKLENGTH, fp);
        if (feof(fp))
        {
            keep_reading = false;
        }
        else if (current_line == line)
        {
            printf("%s", ch);
        }
        current_line++;
    } while (keep_reading);


    fclose(fp);
}