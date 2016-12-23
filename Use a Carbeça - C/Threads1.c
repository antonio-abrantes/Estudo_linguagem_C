#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <conio.h>

void error(char *msg){
    fprintf(stderr, "%s\n", msg, strerror(errno));
    exit(1);
}

void* does_not(void *a){
    int i = 0;
    for(i = 0; i < 5; i++){
        Sleep(1000);
        puts("Does not");
    }
    return NULL;
}

void* does_too(void *a){
    int i = 0;
    for(i = 0; i < 5; i++){
        Sleep(1000);
        puts("Does too");
    }
    return NULL;
}

int main(){
    pthread_t t0;
    pthread_t t1;
    if(pthread_create(&t0, NULL, does_not, NULL) == -1){
        error("Cant create thread t0");
    }
    if(pthread_create(&t1, NULL, does_too, NULL) == -1){
        error("Cant create thread t1");
    }
    void* result;

    if(pthread_join(t0, &result) == -1){
        error("Cant join thread t0)");
    }
    if(pthread_join(t1, &result) == -1){
        error("Cant join thread t1");
    }

  return 0;
}









