#include <stdio.h>
#include <stdlib.h>
//include do GTK
#include <gtk/gtk.h>
#include <string.h>

    GtkWidget *janela;
    GtkWidget *fixedC;
    GtkWidget *botao1, *botao2;
    GtkWidget *rotuloNome, *rotuloIdade, *rotuloProfissao, *rotuloEmpresa;
    GtkWidget *rotuloval1, *rotuloval2, *rotuloval3, *rotuloval4;
    GtkWidget *cxn, *cxi, *cxp, *cxe;


typedef struct Cliente{
    char *nome;
    char *idade;
    char *profissao;
    char *empresa;
}cliente;

void fechar()
{
    gtk_main_quit();
}

void cadastro(){
  cliente Novo;

  Novo.nome = gtk_entry_get_text(cxn);
  Novo.idade = gtk_entry_get_text(cxi);
  Novo.profissao = gtk_entry_get_text(cxp);
  Novo.empresa = gtk_entry_get_text(cxe);

  g_print("Gravado com sucesso...\n");

  cliente temp;

  temp.nome = gtk_label_get_text(rotuloNome);
  temp.idade = gtk_label_get_text(rotuloIdade);
  temp.profissao = gtk_label_get_text(rotuloProfissao);
  temp.empresa = gtk_label_get_text(rotuloEmpresa);

  strcat(temp.nome, Novo.nome);
  strcat(temp.idade, Novo.idade);
  strcat(temp.profissao, Novo.profissao);
  strcat(temp.empresa, Novo.empresa);

  gtk_label_set_text(rotuloval1, temp.nome);
  gtk_label_set_text(rotuloval2, temp.idade);
  gtk_label_set_text(rotuloval3, temp.profissao);
  gtk_label_set_text(rotuloval4,  temp.empresa);
}

void limpar(){
  gtk_entry_set_text(cxn, "");
  gtk_entry_set_text(cxi, "");
  gtk_entry_set_text(cxp, "");
  gtk_entry_set_text(cxe, "");
}

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW (janela), "Programa 2");
    gtk_window_set_default_size(GTK_WINDOW(janela),500,200);
    gtk_window_set_position(GTK_WINDOW(janela),GTK_WIN_POS_CENTER);
    gtk_signal_connect(GTK_OBJECT(janela),"destroy",GTK_SIGNAL_FUNC(fechar),NULL);

    fixedC = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(janela), fixedC);

    //Rotulos

    rotuloNome = gtk_label_new("Nome: ");
    gtk_fixed_put(GTK_FIXED(fixedC), rotuloNome, 20, 30);

    rotuloIdade = gtk_label_new("Idade: ");
    gtk_fixed_put(GTK_FIXED(fixedC), rotuloIdade, 20, 60);

    rotuloProfissao = gtk_label_new("Profissao: ");
    gtk_fixed_put(GTK_FIXED(fixedC), rotuloProfissao, 20, 90);

    rotuloEmpresa = gtk_label_new("Empresa: ");
    gtk_fixed_put(GTK_FIXED(fixedC), rotuloEmpresa, 20, 120);

    //Rotulos de resposta

    rotuloval1 = gtk_label_new("NOME");
    gtk_fixed_put(GTK_FIXED(fixedC), rotuloval1, 280, 30);

    rotuloval2 = gtk_label_new("IDADE");
    gtk_fixed_put(GTK_FIXED(fixedC), rotuloval2, 280, 60);

    rotuloval3 = gtk_label_new("PROFISSAO");
    gtk_fixed_put(GTK_FIXED(fixedC), rotuloval3, 280, 90);

    rotuloval4 = gtk_label_new("EMPRESA");
    gtk_fixed_put(GTK_FIXED(fixedC), rotuloval4, 280, 120);

    //Caixas de texto

    cxn = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixedC), cxn, 80, 28);

    cxi = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixedC), cxi, 80, 58);

    cxp = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixedC), cxp, 80, 88);

    cxe = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixedC), cxe, 80, 118);

    //Botoes

    botao1 = gtk_button_new_with_label("Cadastrar");
    gtk_fixed_put(GTK_FIXED(fixedC), botao1, 20, 150);
    gtk_widget_set_size_request(botao1, 80, 30);
    gtk_signal_connect(GTK_OBJECT(botao1), "clicked", GTK_SIGNAL_FUNC(cadastro), NULL);

    botao2 = gtk_button_new_with_label("Limpar");
    gtk_fixed_put(GTK_FIXED(fixedC), botao2, 160, 150);
    gtk_widget_set_size_request(botao2, 80, 30);
    gtk_signal_connect(GTK_OBJECT(botao2), "clicked", GTK_SIGNAL_FUNC(limpar), NULL);

    gtk_widget_show_all(janela);

    gtk_main();

    return 0;
}
