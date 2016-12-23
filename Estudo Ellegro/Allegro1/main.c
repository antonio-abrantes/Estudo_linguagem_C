#include <allegro.h>
#include <stdio.h>

int main() {
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);



    BITMAP *imagem_ufscar = load_bitmap("ufscar.bmp",NULL);
    unsigned char data[10][30];
    char nome[] = "Antonio";
    int i = 0;
    while (!key[KEY_ESC]) {
          textprintf_ex( screen, font, ((640/2) - 12), ((480/2) +50), makecol(155,155,255), -1, "Hello World para vc %s", nome);
          textprintf_ex( screen, font, 10, 20, makecol(255,0,0), -1, "Exercicio numero: %i", 1);
          //rect(screen, 50, 50, 250, 150, makecol(255,255,255));
          //circlefill(screen, i, 150, 50, makecol(0,0,255));


          if(key[KEY_LEFT]){

             i++;
             circlefill(screen, i, 150, 50, makecol(0,0,255));

          }

          if(key[KEY_RIGHT]){
             i--;
             circlefill(screen, i, 150, 50, makecol(0,0,255));

          }
          blit(imagem_ufscar, screen, 0, 0, 100, 100, 311, 204);


      }
      destroy_bitmap(imagem_ufscar);
   return 0;
}
END_OF_MAIN()

