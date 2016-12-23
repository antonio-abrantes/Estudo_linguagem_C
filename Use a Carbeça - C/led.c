#include <stdio.h>
#include <string.h>

int main(){

    int i,j,num;
    char str[100];
    int count;

    scanf("%d",&num);

    while(num--){
        scanf("%s",str);

        j= strlen(str);

        for(i=0,count=0;i<j;i++){

          if(str[i] == '0')
                count += 6;
          else   if(str[i] == '1')
                count += 2;
          else if(str[i] == '2')
                count += 5;
          else  if(str[i] == '3')
                count += 5;
          else   if(str[i] == '4')
                count += 4;
          else   if(str[i] == '5')
                count += 5;
          else  if(str[i] == '6')
                count += 6;
          else  if(str[i] == '7')
                count += 3;
          else  if(str[i] == '8')
                count += 7;
          else  if(str[i] == '9')
                count += 6;
        }

        printf("%d leds\n",count);
    }
    return 0;
}