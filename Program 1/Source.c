//PROG71985F21 - Week 14 - Assignment Group Project - The program manages a person's tasks 
//Source file
//Gurjit Singh and David Oladimeji - December 7 - 2021 


#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "Source.h" 
#include <stdbool.h> 


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
        displayAllTasks();
        deleteTask();

        break;
    }
    case 'c':
    {
        displayAllTasks();
        updateTask(); 

        break;
    }
    case 'd':
    {
        displaySpecificTask();

        break;
    }
    case 'e':
    {
        displayRangeTasks(); 

        break;
    }
    case 'f':
    {
        displayAllTasks();

        break;
    }
    case 'g':
    {
       searchfortask(); 

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
    \re) Display a range of tasks\n\
    \rf) Display all tasks\n\
    \rg) Search for a task\n\
    \rh) Quit\n");
}


void addNewTask()
{
    FILE* fp = fopen("Tasks.txt", "a");

    if (fp == NULL)
    {
        perror("Unable to open file");
        exit(1);
    }

    char* newTask[NEWTASKLENGTH];

    printf("\nEnter the task information you would like to add:\n");
    fgets(newTask, sizeof(newTask), stdin);
    fgets(newTask, sizeof(newTask), stdin);
    //scanf_s("%s", newTask); 
    //scanf("%s", newTask, NEWTASKLENGTH);
    
    fprintf(fp, "%s", newTask);
    printf("\nTask added\n");

    fclose(fp);

    return 0;
}


void displayAllTasks()
{
    FILE* fp;
    int ch;
    unsigned long count = 0;

    if ((fp = fopen("Tasks.txt", "r")) == NULL)
    {
        perror("Unable to open file");
        exit(1);
    }

    printf("\n"); 

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

    printf("\nEnter the line number according to the task you would like to delete:\n");
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

    printf("\nTask deleted\n");

    fclose(fp);
    fclose(fptemp);

    remove("Tasks.txt");
    rename(tempfile, "Tasks.txt");
}


void updateTask()
{
    FILE* fp, * fptemp;
    char ch[NEWTASKLENGTH];
    char newCh[NEWTASKLENGTH];
    int update = 0;
    char tempfile[NEWTASKLENGTH];

    strcpy(tempfile, "temp____");
    strcat(tempfile, "Tasks_txt");

    printf("\nEnter the line number according to the task you would like to update:\n");
    scanf_s("%d", &update);

    printf("\nEnter the new information for the task:\n"); 
    fgets(newCh, sizeof(newCh), stdin); 
    fgets(newCh, sizeof(newCh), stdin); 

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
        else if (current_line != update)
        {
            fputs(ch, fptemp);
        }
        else if (current_line == update)
        {
            fputs(newCh, fptemp);
        }
        current_line++;
    } while (keep_reading);

    printf("\nTask updated\n"); 

    fclose(fp);
    fclose(fptemp);

    remove("Tasks.txt");
    rename(tempfile, "Tasks.txt");
}


void displaySpecificTask()
{
    int line;

    printf("\nEnter the line number according to the task you would like to be shown:\n");
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

    printf("\n"); 

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


void displayRangeTasks()
{
    int line1, line2;

    printf("\nEnter the line number according to the task from where you would like the tasks to be shown:\n");
    scanf_s("%d", &line1); 

    printf("\nEnter the line number according to the task until you would like the tasks to be shown:\n");
    scanf_s("%d", &line2); 

    if (line1 > line2) 
    {
        printf("\nFirst line number cannot be greater than the second line number\n"); 
    }
    else if (line1 <= 0 || line2 <= 0)
    {
        printf("\nLine numbers cannot be equal to or less than 0\n"); 
    }
    else
    {
        printf("\n"); 

        FILE* fp = fopen("Tasks.txt", "r");
        if (fp == NULL)
        {
            perror("Unable to open file");
            exit(1);
        }

        bool keep_reading = true;
        int current_line = 1;
        int i; 
        char ch[NEWTASKLENGTH];

        do
        {
            fgets(ch, NEWTASKLENGTH, fp);
            if (feof(fp))
            {
                keep_reading = false;
            }
            else if (current_line == line1)
            {
                printf("%s", ch);  
            }
            else if (current_line > line1 && current_line <= line2)
            {
                printf("%s", ch); 
            } 
            current_line++;
        } while (keep_reading);


        fclose(fp); 
    }
}

void searchfortask()
{
    char wrd[256], buffer[256];
    int n, m, i, j, line;

    FILE* fp;
    fp = fopen("Tasks.txt", "r");

    printf("Enter the word you want to search in the file: ");
    scanf("%s", wrd, NEWTASKLENGTH);

    m = strlen(wrd); 

    line = 0;
    
    while (fgets(buffer, 256, fp) != NULL) 
    {
        i = 0;
        n = strlen(buffer);

        while (i < n) 
        {
            j = 0;
            while (i < n && j < m && buffer[i] == wrd[j]) 
            {
                ++i, ++j;
            }

            if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m)
            {
                printf("%s", buffer);
            }

            while (i < n && buffer[i] != ' ') 
            {
                ++i;
            }
            ++i;
        }

        ++line;
    }

    fclose(fp);
}