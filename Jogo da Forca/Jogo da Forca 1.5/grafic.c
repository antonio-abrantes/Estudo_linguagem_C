#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "grafic.h"

void imprime_forca(int let_erro){
    printf("\n\n");
    printf("   _________\n");
		printf("   |       |\n");
			switch(let_erro){
				case 1:
					printf("   |       |\n");
					printf("   |       O\n");
					printf("   |\n");
					printf("   |\n"); break;
				case 2:
				    printf("   |       |\n");
					printf("   |       O\n");
					printf("   |       I\n");
					printf("   |\n"); break;
				case 3:
					printf("   |       |\n");
					printf("   |       O\n");
					printf("   |      /I\n");
					printf("   |\n"); break;
				case 4:
					printf("   |       |\n");
					printf("   |       O\n");
					printf("   |      /I\\\n");
					printf("   |\n"); break;
				case 5:
					printf("   |       |\n");
					printf("   |       O\n");
					printf("   |      /I\\\n");
					printf("   |      /\n"); break;
				case 6:
					printf("   |       |\n");
					printf("   |       O  \n");
					printf("   |      /I\\\n");
					printf("   |        \\\n"); break;
				case 7:
					printf("   |       |\n");
					printf("   |       O  GAME OVER\n");
					printf("   |      /I\\\n");
					printf("   |      / \\\n"); break;
				case 8:
					printf("   |        \n");
					printf("   |      \\O/  WIN!!\n");
					printf("   |       I\n");
					printf("   |      / \\\n"); break;	
				default:
					printf("   |\n");
					printf("   |\n");
					printf("   |\n");
					printf("   |\n"); break;
			}
		printf("   |\n");
		printf("   |\n");
		printf("   |\n");
		printf("   |\n");
		printf("\n\n");
}


void coracao(){
	system("cls");
			printf("\n\n\t    VOCE DESCOBRIU A FASE SECRETA          \n");
        	printf("\n\n\tMENSAGEM SECRETA: TE AMO MINHA GOSTOSA! =***\n");
        	printf("  ____________000000____________000000____________\n");
        	printf("  __________000000000000______000000000000_________\n");
        	printf("  ______000000000000000000__000000000000000000_____\n");
        	printf("  ____00000000000000000000000000000000000000000____\n");
        	printf("  ___00000000000000___000000000___00000000000000___\n");
        	printf("  __000000000000000___000000000___000000000000000__\n");
        	printf("  _0000000000000000___000000000___0000000000000000_\n");
        	printf("  _0000000000000000___000000000___0000000000000000_\n");
        	printf("  _0000000000000000___000000000___0000000000000000_\n");
        	printf("  _0000000000000000___000000000___0000000000000000_\n");
        	printf("  _0000000000___000000000000000000000___0000000000_\n");
        	printf("  __000000000___000000000000000000000___000000000__\n");
        	printf("  ___000000000___0000000000000000000___000000000___\n");
        	printf("  _____000000000___000000000000000___000000000_____\n");
        	printf("  _______00000000____00000000000____00000000_______\n");
        	printf("  __________0000000_______________0000000__________\n");
        	printf("  _____________0000000000000000000000000___________\n");
        	printf("  _______________000000000000000000000_____________\n");
        	printf("  __________________000000000000000________________\n");
        	printf("  ___________________000000000000__________________\n");
        	printf("  ______________________000000_____________________\n");
        	printf("  _______________________0000______________________\n");
        	printf("  ________________________00_______________________\n");
        	system("pause");
}
