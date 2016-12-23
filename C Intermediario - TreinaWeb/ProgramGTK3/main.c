#include <stdio.h>
#include <stdlib.h>
//include do GTK
#include <gtk/gtk.h>

    GtkWidget *janela;
    GtkWidget *fixedC;
    GtkWidget *botao1, *botao2;
    GtkWidget *rotulo1;
    GtkWidget *caixaT;

void fechar()
{
    gtk_main_quit();
}

void valor(){
  gtk_label_set_text(rotulo1, "Apertei o botao 1");
}

void valor2(){
  gtk_entry_set_text(caixaT, "Apertei o botao 2");
  //gtk_entry_set_text()
}

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW (janela), "Programa 2");
    gtk_window_set_default_size(GTK_WINDOW(janela),400,300);
    gtk_window_set_position(GTK_WINDOW(janela),GTK_WIN_POS_CENTER);
    gtk_signal_connect(GTK_OBJECT(janela),"destroy",GTK_SIGNAL_FUNC(fechar),NULL);

    fixedC = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(janela), fixedC);

    botao1 = gtk_button_new_with_label("Botao 1");
    gtk_fixed_put(GTK_FIXED(fixedC), botao1, 0, 0);
    gtk_widget_set_size_request(botao1, 80, 30);
    gtk_signal_connect(GTK_OBJECT(botao1), "clicked", GTK_SIGNAL_FUNC(valor), NULL);

    botao2 = gtk_button_new_with_label("Botao 2");
    gtk_fixed_put(GTK_FIXED(fixedC), botao2, 0, 50);
    gtk_widget_set_size_request(botao2, 80, 30);
    gtk_signal_connect(GTK_OBJECT(botao2), "clicked", GTK_SIGNAL_FUNC(valor2), NULL);

    rotulo1 = gtk_label_new("Mesangem inicial...");
    gtk_fixed_put(GTK_FIXED(fixedC), rotulo1, 100, 0);

    caixaT = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixedC), caixaT, 100, 50);
    gtk_widget_set_size_request(caixaT, 200, 50);

    gtk_widget_show_all(janela);

    gtk_main();

    return 0;
}
