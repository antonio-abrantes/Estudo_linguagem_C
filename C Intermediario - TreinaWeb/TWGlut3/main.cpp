#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

void Desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void mensagens(int val){
    printf("Ola!\n");

    glutTimerFunc(1000, mensagens, val);
}
void Inicializa (void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
void AjustaTamanho(GLsizei w, GLsizei h)
{

}
// Programa Principal
int main(void)
{
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(800,600);
     glutInitWindowPosition(400,100);
     glutCreateWindow("Janela");
     glutDisplayFunc(Desenha);
     glutTimerFunc(1000, mensagens, 1);
     Inicializa();
     glutMainLoop();
}
