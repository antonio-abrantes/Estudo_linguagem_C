#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(){
	if(execl("ipconfig", "ipconfig", NULL) == -1)
		if(execlp("ipconfig", "ipconfig", NULL) == -1){
			fprintf(stderr, "Canot rum ipconfig: %s", strerror(errno));
			return 1;
		}
	
	return 0;
}
