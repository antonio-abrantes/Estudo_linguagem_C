#include <allegro.h>

int main(){
  //Inicialização
  allegro_init();
  install_timer();
  install_keyboard();
  set_color_depth(32);
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
  set_window_title("Game 3");

  //Variaveis
    int x = 100, y = 100;
    //rectfill(screen, 100, 100, 100, 100, makecol(210, 210, 100));
    //BITMAP* buffer = create_bitmap(800, 600);

  while(!key[KEY_ESC]){

    if(key[KEY_LEFT]){x -= 1;
      if(x == 800){
        x = 200;
        circlefill(screen, x, y, 50, makecol(100, 100, 200));
        rest(3);
        clear(screen);
      }
    }
    if(key[KEY_RIGHT]){x += 1;}
    if(key[KEY_UP]){y -= 1;}
    if(key[KEY_DOWN]){y += 1;}
    circlefill(screen, x, y, 50, makecol(255, 245, 200));
    //draw_sprite(screen, buffer, 0, 0);
    rest(3);
    //clear(buffer);
    clear(screen);
  }
  //destroy_bitmap(buffer);
  return 0;
}
END_OF_MAIN();
