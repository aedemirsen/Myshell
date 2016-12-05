#include<stdio.h>
#include"string.h"
#define buffer_size 50

char KOMUT[buffer_size];
char ARG1[buffer_size];
char ARG2[buffer_size];
char TXT[]="";


int equals(char first[],char second[]){
    int e = 1,i;
    int size1 = getSize(first);
    int size2 = getSize(second);
    if (size1 == size2){
       for(i = 0; i < size1; i++){
         if (first[i] != second[i]){
            e = 0;
            break;
         }
       }
    }
    else{
       e = 0;
    }
    return e;
}

int getSize(char str[]){
  int i = 0;
  while(str[i] != '\0'){
      i++; 
  }
  return i;
}

int stringToInt(char c[]){
	int i = atoi(c);
	return i;	
}

void splitWords(char *c){
	int i,a=0,b=0;
	int j = 0;
	for(i = 0; i<getSize(c);i++){
		if(j == 0) {KOMUT[i] = c[i];}
		else if(j == 1) {ARG1[a] = c[i];a++;}
		else if(j == 2) {ARG2[b] = c[i];b++;}				
		if((c[i] == ' ' || c[i] == '\0' || c[i] == '\n') && j == 0){
			KOMUT[i] = '\0';
			j++;
		}
		else if((c[i] == ' ' || c[i] == '\0' || c[i] == '\n') && j == 1){
			ARG1[i] = '\0';
			j++;
		}
		else if((c[i] == ' ' || c[i] == '\0' || c[i] == '\n') && j == 2){
			ARG2[i] = '\0';
			j++;
		}		
	}	
}

void text (char str[],char c1, char c2){  
   int i,j,a = 0;
   for(i = 0; i < getSize(str); i++){
      if(str[i] == c1){
         j = i+1;
         break;
      }
   }
   for(i = j; i < getSize(str); i++) {
      if(str[i] != c2){
        *(TXT+a) = str[i];
        a++;
      }
      else{
        TXT[a] = '\0'; 
        break;
      }
   }
}













