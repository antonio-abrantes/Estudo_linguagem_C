#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

char nome[15];

void clique_btn(){
  g_print("Clicou o botao\n");
  //exit(1);
}

void fechar()
{
    gtk_main_quit();
}

void del_t(){
  g_print("Deletou\n");
}

void Saiu(){
  g_print("Tchau!!!");
}

int main (int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *Vbox;
  //GtkWidget *fixedC;
  //GtkWidget *caixaT;
  //GtkWidget *botao;
  //GtkWidget *rotulo;
  //GtkWidget *BtnColor;

    gtk_init(&argc, &argv);
    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW (janela), "Programa 1");
    gtk_window_set_default_size(GTK_WINDOW(janela), 800, 600);
    gtk_window_set_position(GTK_WINDOW(janela), GTK_WIN_POS_CENTER);
    gtk_signal_connect(GTK_OBJECT(janela),"destroy",GTK_SIGNAL_FUNC(fechar),NULL);

    //fixedC = gtk_fixed_new();
    //gtk_container_add(GTK_CONTAINER(janela), fixedC);

    Vbox = gtk_vbox_new(TRUE, 100);
    gtk_container_add(GTK_CONTAINER(janela), Vbox);

    GtkWidget *botao1, *botao2, *botao3;

    botao1 = gtk_button_new_with_label("Botao 1");
    //gtk_fixed_put(GTK_FIXED(fixedC), botao1, 2, 2);
    //gtk_widget_set_size_request(botao1, 80, 30);

    botao2 = gtk_button_new_with_label("Botao 2");
    //gtk_fixed_put(GTK_FIXED(fixedC), botao2, 102, 2);
    //gtk_widget_set_size_request(botao2, 80, 30);

    botao3 = gtk_button_new_with_label("Botao 3");

    gtk_box_pack_start(GTK_BOX(Vbox), botao1, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(Vbox), botao2, TRUE, TRUE, 50);
    gtk_box_pack_start(GTK_BOX(Vbox), botao3, TRUE, TRUE, 30);

    //BtnColor = gtk_color_button_new();
    //gtk_container_add(GTK_CONTAINER(janela), BtnColor);
    //gtk_signal_connect(GTK_OBJECT(BtnColor), "leave", GTK_SIGNAL_FUNC(Saiu), NULL);

    //rotulo = gtk_label_new("ola");
    //gtk_label_set_selectable(rotulo, "true");
    //gtk_container_add(GTK_CONTAINER(janela), rotulo);
    //gtk_signal_connect(GTK_OBJECT(rotulo), "copy-clipboard", GTK_SIGNAL_FUNC(fechar), NULL);

    //caixaT = gtk_entry_new();
    //gtk_container_add(GTK_CONTAINER(janela), caixaT);
    //gtk_signal_connect(GTK_OBJECT(caixaT), "delete-text", GTK_SIGNAL_FUNC(del_t), NULL);

    //botao = gtk_button_new();
    //gtk_button_set_label(GTK_BUTTON(botao), "Clique!");
    //botao = gtk_button_new_with_label("Clique");
    //gtk_container_add(GTK_CONTAINER(janela), botao);
    //gtk_signal_connect(GTK_OBJECT(botao),"clicked", GTK_SIGNAL_FUNC(clique_btn), NULL );

    gtk_widget_show_all(janela);
    //gtk_widget_show(janela);
    //gtk_widget_show(BtnColor);
    //gtk_widget_show(rotulo);
    //gtk_widget_show(caixaT);
    //gtk_widget_show(botao);

    gtk_main();

  return 0;
}
