//PROG71985F21 - Week 14 - Assignment Group Project - The program manages a person's tasks 
//Source file
//Gurjit Singh and David Oladimeji - December 7 - 2021 


//original file: tasksSaveFile.txt

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
        //addNewTask();

        break;
    }
    case 'b':
    {
        showalltasks();
        deletetask();

        break;
    }
    case 'c':
    {
        printf("feauture hasn't been added yet\n");
        break;
    }
    case 'd':
    {
        displayspecifictask();
        break;
    }
    case 'e':
    {
        printf("feauture hasn't been added yet\n");
        break;
    }
    case 'f':
    {
        showalltasks();
        break;
    }
    case 'g':
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
    \rb) Delete a task\n\
    \rc) \n\
    \rd) Display specific task\n\
    \re) \n\
    \rf) Display all task\n\
    \rg) Quit\n"); 
}


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

    //int bookingNamesNum;
    //char* firstName = malloc(sizeof(char) * (bookingStatusLength + 1));
    //char* lastName = malloc(sizeof(char) * (bookingStatusLength + 1));

    printf("\nEnter the task information you would like to add:\n"); 
    //fgets(newTask, sizeof(newTask), stdin);
    scanf("%s", newTask, NEWTASKLENGTH); 
    //while ((newTask = getchar()) != '\n' && newTask != EOF);
    /* while (fgets(newTask, sizeof(newTask), stdin) != EOF)
    {
        fgets(newTask, sizeof(newTask), stdin); 
    } */ 
    tasksList.newTask = newTask; 

    fprintf(fp, "%s", tasksList.newTask); 
    fprintf(fp, "\n"); 
    printf("\nTask added\n"); 

    fclose(fp); 

    return 0;
}

void showalltasks()
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

void deletetask()
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

void displayspecifictask()
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