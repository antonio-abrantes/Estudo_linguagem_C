#include <stdio.h>
#include <stdlib.h>
//include do GTK
#include <gtk/gtk.h>
#include <string.h>

    GtkWidget *janela;
    GtkWidget *fixedC;
    GtkWidget *botao1, *botao2, *botao3, *botao4, *botao5, *botao6, *botao7, *botao8, *botao9, *botao0;
    GtkWidget *botaoIgual, *botaoSoma, *botaoSub, *botaoDiv, *botaoMult, *botaoC;
    GtkWidget *cx;
    //GtkWidget *rotuloval1, *rotuloval2, *rotuloval3, *rotuloval4;

    char *valorc1 = NULL;
    char *valorc2 = NULL;
    char valorc3[];
    int valori1 = NULL;
    int valori2 = NULL;
    int valori3 = NULL;
    char valores[];
    char valores2[];


void fechar()
{
    gtk_main_quit();
}

void pegaVal1(){
    valorc1 = gtk_entry_get_text(cx);
}

void pegaVal2(){
    valorc2 = gtk_entry_get_text(cx);
}

void concat(GtkWidget *w, gpointer p){

    if(valori1 == NULL)
    {
      strcat(valores, p);
      valUm();
    }else
    {
      strcat(valores2, p);
      valDois();
    }
}

void valUm(){
    gtk_entry_set_text(cx, valores);
    pegaVal1();
}

void valDois(){
    gtk_entry_set_text(cx, valores2);
    pegaVal2();
}

char *op;

void operacao(GtkWidget *w, gpointer p){
    if(valori1 == NULL){
      valori1 = atoi(valorc1);
      gtk_entry_set_text(cx, "");
    }

    op = p;
}

void soma(int a, int b){
  valori3 = a + b;
  itoa(valori3, valorc3, 10);
  gtk_entry_set_text(cx, valorc3);
}

void sub(int a, int b){
  valori3 = a - b;
  itoa(valori3, valorc3, 10);
  gtk_entry_set_text(cx, valorc3);
}

void mult(int a, int b){
  valori3 = a * b;
  itoa(valori3, valorc3, 10);
  gtk_entry_set_text(cx, valorc3);
}

void divi(int a, int b){
  if(b != 0){
    valori3 = a / b;
    itoa(valori3, valorc3, 10);
    gtk_entry_set_text(cx, valorc3);
  }

}

void limpeza(){
    valorc1 = NULL;
    valorc2 = NULL;
    valori1 = NULL;
    valori2 = NULL;
    valori3 = NULL;

    int size1 = strlen(valores);
    int i;
    for(i = 0; i < size1; i++){
      valores[i] = NULL;
    }

    int size2 = strlen(valores2);
    for(i = 0; i < size2; i++){
      valores2[i] = NULL;
    }
}

void limpezaT(){
    valorc1 = NULL;
    valorc2 = NULL;
    valori1 = NULL;
    valori2 = NULL;
    valori3 = NULL;

    int size1 = strlen(valores);
    int i;
    for(i = 0; i < size1; i++){
      valores[i] = NULL;
    }

    int size2 = strlen(valores2);
    for(i = 0; i < size2; i++){
      valores2[i] = NULL;
    }
    gtk_entry_set_text(cx, "");
}

void resultado(){

    if(valori2 == NULL){
      valori2 = atoi(valorc2);
      gtk_entry_set_text(cx, "");
    }

    if(op == "soma"){
      soma(valori1, valori2);
      limpeza();
    }

    if(op == "subtracao"){
      sub(valori1, valori2);
      limpeza();
    }

    if(op == "divisao"){
      divi(valori1, valori2);
      limpeza();
    }

    if(op == "multiplicacao"){
      mult(valori1, valori2);
      limpeza();
    }

}


int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW (janela), "Calculadora");
    gtk_window_set_default_size(GTK_WINDOW(janela),204,260);
    gtk_window_set_position(GTK_WINDOW(janela),GTK_WIN_POS_CENTER);
    gtk_signal_connect(GTK_OBJECT(janela),"destroy",GTK_SIGNAL_FUNC(fechar),NULL);

    fixedC = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(janela), fixedC);

    //Rotulos

    //rotuloNome = gtk_label_new("Nome: ");
    //gtk_fixed_put(GTK_FIXED(fixedC), rotuloNome, 20, 30);

    //Caixas de texto

    cx = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixedC), cx, 20, 28);
    gtk_widget_set_size_request(cx, 164, 27);


    //Botoes
    //Fila 1
    botao1 = gtk_button_new_with_label("1");
    gtk_fixed_put(GTK_FIXED(fixedC), botao1, 20, 70);
    gtk_widget_set_size_request(botao1, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botao1), "clicked", GTK_SIGNAL_FUNC(concat), "1");

    botao2 = gtk_button_new_with_label("2");
    gtk_fixed_put(GTK_FIXED(fixedC), botao2, 62, 70);
    gtk_widget_set_size_request(botao2, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botao2), "clicked", GTK_SIGNAL_FUNC(concat), "2");

    botao3 = gtk_button_new_with_label("3");
    gtk_fixed_put(GTK_FIXED(fixedC), botao3, 103, 70);
    gtk_widget_set_size_request(botao3, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botao3), "clicked", GTK_SIGNAL_FUNC(concat), "3");

    botaoDiv = gtk_button_new_with_label("/");
    gtk_fixed_put(GTK_FIXED(fixedC), botaoDiv, 144, 70);
    gtk_widget_set_size_request(botaoDiv, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botaoDiv), "clicked", GTK_SIGNAL_FUNC(operacao), "divisao");

    //Fila 2
    botao4 = gtk_button_new_with_label("4");
    gtk_fixed_put(GTK_FIXED(fixedC), botao4, 20, 112);
    gtk_widget_set_size_request(botao4, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botao4), "clicked", GTK_SIGNAL_FUNC(concat), "4");

    botao5 = gtk_button_new_with_label("5");
    gtk_fixed_put(GTK_FIXED(fixedC), botao5, 62, 112);
    gtk_widget_set_size_request(botao5, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botao5), "clicked", GTK_SIGNAL_FUNC(concat), "5");

    botao6 = gtk_button_new_with_label("6");
    gtk_fixed_put(GTK_FIXED(fixedC), botao6, 103, 112);
    gtk_widget_set_size_request(botao6, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botao6), "clicked", GTK_SIGNAL_FUNC(concat), "6");

    botaoMult = gtk_button_new_with_label("*");
    gtk_fixed_put(GTK_FIXED(fixedC), botaoMult, 144, 112);
    gtk_widget_set_size_request(botaoMult, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botaoMult), "clicked", GTK_SIGNAL_FUNC(operacao), "multiplicacao");

    //Fila 3
    botao7 = gtk_button_new_with_label("7");
    gtk_fixed_put(GTK_FIXED(fixedC), botao7, 20, 154);
    gtk_widget_set_size_request(botao7, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botao7), "clicked", GTK_SIGNAL_FUNC(concat), "7");

    botao8 = gtk_button_new_with_label("8");
    gtk_fixed_put(GTK_FIXED(fixedC), botao8, 62, 154);
    gtk_widget_set_size_request(botao8, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botao8), "clicked", GTK_SIGNAL_FUNC(concat), "8");

    botao9 = gtk_button_new_with_label("9");
    gtk_fixed_put(GTK_FIXED(fixedC), botao9, 103, 154);
    gtk_widget_set_size_request(botao9, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botao9), "clicked", GTK_SIGNAL_FUNC(concat), "9");

    botaoSub = gtk_button_new_with_label("-");
    gtk_fixed_put(GTK_FIXED(fixedC), botaoSub, 144, 154);
    gtk_widget_set_size_request(botaoSub, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botaoSub), "clicked", GTK_SIGNAL_FUNC(operacao), "subtracao");

    //Fila 4
    botaoC = gtk_button_new_with_label("C");
    gtk_fixed_put(GTK_FIXED(fixedC), botaoC, 20, 196);
    gtk_widget_set_size_request(botaoC, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botaoC), "clicked", GTK_SIGNAL_FUNC(limpezaT), NULL);


    botao0 = gtk_button_new_with_label("0");
    gtk_fixed_put(GTK_FIXED(fixedC), botao0, 62, 196);
    gtk_widget_set_size_request(botao0, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botao0), "clicked", GTK_SIGNAL_FUNC(concat), "0");

    botaoIgual = gtk_button_new_with_label("=");
    gtk_fixed_put(GTK_FIXED(fixedC), botaoIgual, 103, 196);
    gtk_widget_set_size_request(botaoIgual, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botaoIgual), "clicked", GTK_SIGNAL_FUNC(resultado), NULL);

    botaoSoma = gtk_button_new_with_label("+");
    gtk_fixed_put(GTK_FIXED(fixedC), botaoSoma, 144, 196);
    gtk_widget_set_size_request(botaoSoma, 40, 40);
    gtk_signal_connect(GTK_OBJECT(botaoSoma), "clicked", GTK_SIGNAL_FUNC(operacao), "soma");

    gtk_widget_show_all(janela);

    gtk_main();

    return 0;
}
