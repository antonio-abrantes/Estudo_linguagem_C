#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void diediedie(int sig){
	exit(1);
}

int catch_signal(int sig, void(*handler) (int)){
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction (sig, &action, NULL);
}


int mian(){
	if(catch_signal(SIGINT, handle_interrupt) == -1){
		fprintf(stderr, "Cant map the handler");
		exit(2);
	}
		
	char name[30];
	printf("Digite o nome.: ");
	fgets(name, 30, stdin);
	printf("Hello %s \n", name);
	
	return 0;
}
