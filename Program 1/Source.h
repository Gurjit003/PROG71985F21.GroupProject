//PROG71985F21 - Week 14 - Assignment Group Project - The program manages a person's tasks 
//Header file
//Gurjit Singh and David Oladimeji - December 7 - 2021 


#pragma once


/* typedef struct tasksFormat {
    char* firstWord;
    char* secondWord;
} TASKSFORMAT; */ 

typedef struct tasks {
    char* firstTask; 
    char* secondTask; 
    char* thirdTask; 
    char* fourthTask; 
    char* fifthTask; 
    char* sixthTask; 
    char* seventhTask; 
    char* eighthTask; 
    char* ninthTask; 
    char* tenthTask; 
    char* newTask; 
} TASKS; 


void displayMenu(); 
void addNewTask(); 
void displayAllTasks();
void deleteTask();
void updateTask(); 
void displaySpecificTask(); 
void displayRangeTasks(); 