/* 
 * File:   main.c
 * Author: Adam IW 
 *
 * Created on February 7, 2022, 7:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>


int main(int argc, char** argv) {

    char ch[100]; //to store input commands
    int flag=0; //0 for false, 1 for true
    char *args[100]; //array of strings for holding input commands
    args[0]=&ch[0]; //first element is the address of first character in input array 
    int argNum=0; //we'll use this number to find the amount of input arguments
    int i; //used as a counter for loops throughout the program
    
    while(ch[0]!=EOF){
        flag=0;
        i=0;
        argNum=0;
        
        fprintf(stderr, "Your command> ");
    
        //takes input until new line  (enter/return button) is invoked
        for(i=0;(ch[i]=getchar())!= '\n';i++){ 
        
            //checks for a space
            if(isspace(ch[i])){  
                ch[i]='\0'; //makes the char null, to separate strings
                argNum++; 
                args[argNum]=&ch[i+1]; //increase the arg pointer to the next string from input
        }
    }
    
    //If there were no spaces (single word command), we need to add the null 
    //character at the end so the command isn't 100 chars long and doesn't execute properly
    if(argNum==0){ 
        ch[i]='\0';
    }
    args[argNum+1]=NULL; //adds NULL to end of args array
    
    if(ch[--i] == '&') //if the input line is ended with '&' then the flag is set to 1 (true)
        flag=1;
    
    if(fork()==0){ //this ensures only the child will execute after forking, child returns 0 from fork()
        if(flag!=1){ //checks first to make sure there was no ampersand
            fprintf(stderr, "\nCHILD PROCESS CREATED. Executing the command...\n\n");
            execvp(args[0], args);
        }
    }  
    else{
        if(flag==1){
        fprintf(stderr, "\nPARENT process running...\n\n");
        }
        else{
            wait(NULL);
            fprintf(stderr, "\nPARENT PROCESS done waiting...\n\n");
        }
    } 
    }   
    exit(0);
}

