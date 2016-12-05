#include <stdio.h>
#include "string.h"
#include"functions.h"

int main(int argc,char *argv[]){
	int num = stringToInt(argv[0]);
	if(num < 0){
		printf("Negative value!\n");
		return 0;
	}
	int result = 1;
	int i;
	for(i = num; i > 0; i--){
		result *= i;
	}
	printf("%d! = %d\n",num,result);
	return 0;
}

