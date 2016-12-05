#include <stdio.h>
#include"functions.h"

int main(int argc,char *argv[],char ** envp){
	int a = stringToInt(argv[0]);
	int b = stringToInt(argv[1]);
	printf("%d - %d = %d\n",a,b,(a-b));
	return 0;
}
