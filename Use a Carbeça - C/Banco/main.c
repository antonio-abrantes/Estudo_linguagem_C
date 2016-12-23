#include <stdio.h>
#include <stdlib.h>
#include "encrypt.h"
#include "checksum.h"

int main() {
	char s[] = "Speak friend and enter";
	encrypt(s);
	printf("Encrypeted to '%s'\n", s);
	printf("Checksum is %i\n", checksum(s));
	encrypt(s);
	printf("Decrypted back to '%s'\n", s);
	printf("Checksum is %i\n", checksum(s));	
	
	return 0;
}
