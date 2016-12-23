#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]){
	printf("Diners: %s\n", argv[1]);
	printf("Juice: %s\n", getenv("JUICE"));
	
	char *my_env[] = {"JUICE=peach end apple", NULL};
	execle("Edit3", "Edit3", "4", NULL, my_env);
	
	return 0;
}

