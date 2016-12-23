#include <stdio.h>
#include <stdlib.h>
//include do GTK
#include <gtk/gtk.h>

void fechar()
{
    gtk_main_quit();
}

int main(int argc, char **argv)
{
    GtkWidget *janela;
    GtkWidget *Hbox;
    GtkWidget *botao1, *botao2, *botao3;

    gtk_init(&argc, &argv);

    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW (janela), "TreinaWeb");
    gtk_window_set_default_size(GTK_WINDOW(janela),800,600);
    gtk_window_set_position(GTK_WINDOW(janela),GTK_WIN_POS_CENTER);
    gtk_signal_connect(GTK_OBJECT(janela),"destroy",GTK_SIGNAL_FUNC(fechar),NULL);

    Hbox = gtk_hbox_new(TRUE,1);
    gtk_container_add(GTK_CONTAINER(janela),Hbox);

    botao1 = gtk_button_new_with_label("Botao 1");

    botao2 = gtk_button_new_with_label("Botao 2");

    botao3 = gtk_button_new_with_label("Botao 3");

    gtk_box_pack_start(GTK_BOX(Hbox),botao1,TRUE,TRUE,0);
    gtk_box_pack_start(GTK_BOX(Hbox),botao2,TRUE,TRUE,0);
    gtk_box_pack_start(GTK_BOX(Hbox),botao3,TRUE,TRUE,0);

    gtk_widget_show_all(janela);

    gtk_main();

    return 0;
}
