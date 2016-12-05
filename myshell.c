#include<stdio.h>
#include<stdlib.h>
#include"functions.h"
#include "string.h"

#define EXIT "exit"
#define CLEAR "clear"
#define CAT "cat"
#define FACTORIAL "factorial"
#define PLUSTWO "plustwo"
#define MINUSTWO "minustwo"

void initializeNewargv(char c1[],char c2[],char c3[]);

char *newargv[3];
int i,f;
char *data;
ssize_t buffersize = 0;

int main(int argc,char *argv[],char ** envp){
	while(1){
		memset(&KOMUT[0], 0, sizeof(KOMUT));//KOMUT arrayini temizledik
    	printf("myshell>>");
		getline(&data,&buffersize,stdin);	
		splitWords(data);
		if(equals(KOMUT,EXIT)){
			exit(0);
		}
		f = fork();
		if(f == 0){		
	    	if(equals(KOMUT,CLEAR)){
				system("clear");	    
			}
			else if(equals(KOMUT,CAT)){
				text(data,' ','\0');
				initializeNewargv(CAT,TXT,NULL);
				i = execve(CAT,newargv,envp);
				perror("execve failed!");
			}			
			else if(equals(KOMUT,FACTORIAL)){
				initializeNewargv(ARG1,NULL,NULL);
				i = execv(FACTORIAL,newargv);
				perror("execve failed!");
			}
			else if(equals(KOMUT,PLUSTWO)){
				initializeNewargv(ARG1,ARG2,NULL);
				i = execv(PLUSTWO,newargv);
				perror("execve failed!");
			}
			else if(equals(KOMUT,MINUSTWO)){	
				initializeNewargv(ARG1,ARG2,NULL);
				i = execv(MINUSTWO,newargv);
				perror("execve failed!");
			}else {
				printf("invalid command!\n");		
			}
		}
		else{wait(&i);}
	}
   
	return 0;
}




void initializeNewargv(char c1[],char c2[],char c3[]){
	newargv[0] = c1;
	newargv[1] = c2;
	newargv[2] = c3;
}






