#include <stdio.h>
#include <stdlib.h>

int main(){

  int a, b, c, maiorAB;

  scanf("%d %d %d", &a, &b, &c);

  maiorAB = (a + b + abs(a - b))/2.0;
  
  if(maiorAB < c){
	  printf("%d eh o maior\n", c);
  }
  else{
	  printf("%d eh o maior\n", maiorAB);
  }

  return 0;
}