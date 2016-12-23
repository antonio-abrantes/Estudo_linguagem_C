#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_TRIANGLES);
               glColor3f(1.0f, 0.0f, 0.0f);
               glVertex2i(100,150);
               glColor3f(0.0f, 1.0f, 0.0f);
               glVertex2i(100,100);
               glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(150,100);
     glEnd();
     glFlush();
}
void Inicializa (void)
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
void AjustaTamanho(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    if(h == 0)
    {
      h = 1;
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    {
       gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
    }
    else
    {
        gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
    }
}
// Programa Principal
int main(void)
{
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(800,600);
     glutInitWindowPosition(400,100);
     glutCreateWindow("Quadrado");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AjustaTamanho);
     Inicializa();
     glutMainLoop();
}
