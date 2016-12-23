#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

enum drink {MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE};

//print_ints(3, 79, 101, 32);

double price(enum drink d){
	switch(d){
		case MUDSLIDE:
			return 6.79;
		case FUZZY_NAVEL:
			return 5.31;
		case MONKEY_GLAND:
			return 4.82;
		case ZOMBIE:
			return 5.89;			
		}
	return 0;	
}

double total(int args, ...){
	double total = 0;
	
	va_list ap;
	va_start(ap, args);
	int i;
	for(i = 0; i < args; i++){
		enum drink d = va_arg(ap, enum drink);
		//printf("\n->%i\n", va_arg(ap, enum drink));
		total = total + price(d);
	}
	
	va_end(ap);
	
  return total;	
}

int main(){
	
	printf("Price is %.2f\n", total(3, MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND));
	printf("Price is %.2f\n", total(MONKEY_GLAND, ZOMBIE));
	enum drink c;
	
	//printf("%i", MUDSLIDE);  Exibir valor de enum
	
	return 0;
}
