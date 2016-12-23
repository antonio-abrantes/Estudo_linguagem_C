#include <stdio.h>
#include <stdlib.h>
//include do GTK
#include <gtk/gtk.h>

void fechar()
{
    gtk_main_quit();
}

void titulo(GtkWidget *w, gpointer p)
{
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(w)))
    {
        gtk_window_set_title(p,"CheckButton");
    }else{
        gtk_window_set_title(p,"");
    }
}

int main(int argc, char **argv)
{
    GtkWidget *janela;
    GtkWidget *fixedC;
    GtkWidget *check;

    gtk_init(&argc, &argv);

    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW (janela), "TreinaWeb");
    gtk_window_set_default_size(GTK_WINDOW(janela),800,600);
    gtk_window_set_position(GTK_WINDOW(janela),GTK_WIN_POS_CENTER);
    gtk_signal_connect(GTK_OBJECT(janela),"destroy",GTK_SIGNAL_FUNC(fechar),NULL);

    fixedC = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(janela),fixedC);

    check = gtk_check_button_new_with_label("Titulo");
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check),TRUE);
    GTK_WIDGET_UNSET_FLAGS(check,GTK_CAN_FOCUS);
    gtk_fixed_put(GTK_FIXED(fixedC),check,80,80);

    g_signal_connect(GTK_OBJECT(check),"clicked",GTK_SIGNAL_FUNC(titulo),(gpointer) janela);

    gtk_widget_show_all(janela);

    gtk_main();

    return 0;
}
