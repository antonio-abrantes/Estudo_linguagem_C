#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    float sx;
    float sy;
    float heading;
    float speed;
    ALLEGRO_COLOR dark;
}Spaceship;

bool inicializar();

const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;

ALLEGRO_DISPLAY *janela = NULL;

int main(void)
{

    Spaceship cor;
    cor.dark = al_map_rgb(255, 100, 0);

    if (!inicializar())
    {
        return -1;
    }
    al_show_native_message_box(NULL, "www.rafaeltoledo.net",
            "Pergunta:", "Deseja exibir a mensagem de erro?",
            NULL, ALLEGRO_MESSAGEBOX_YES_NO);

    //al_draw_line(20.0, 40.0, 40.0, 60.0, cor.dark, 3.0f);
    al_draw_line(20.0, 40.0, 40.0, 60.0, al_map_rgb(255, 100, 0), 8.0f);

    al_flip_display();
    al_rest(5.0);
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_destroy_display(janela);

    return 0;
}

bool inicializar()
{
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a biblioteca Allegro.\n");
        return false;
    }

    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on de primitivas.\n");
        return false;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }

    al_set_window_title(janela, "Testando Allegro");

    return true;
}
