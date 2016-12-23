#include <stdio.h>
#include "msg.h"

void tes(int num){
	printf("\nA soma esta em.: %d\n", num);
}

void encrypt(char *msg){
	while(*msg){
		*msg = *msg ^ 31;
		msg++;
	}
}
