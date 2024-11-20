#ifndef BASICO_H
#define BASICO_H

#include <GL/glut.h>
#include <math.h>

void inicializa()
{
 glClearColor(0.1, 0.1, 0.1, 1.0);  // Cor de fundo da tela
 glEnable(GL_DEPTH_TEST);           // Ativa o teste de profundidade
 glEnable(GL_LIGHTING);             // Ativa a iluminação
 glEnable(GL_LIGHT0);               // Ativa a luz 0
 glEnable(GL_COLOR_MATERIAL);
 glEnable(GL_TEXTURE_2D);
}

void defineProjecaoPerspectiva(int largura, int altura)
{
 // Define o tipo de projeção
 glMatrixMode(GL_PROJECTION);

 // Carrega a matriz identidade/reinicia as transformações
 glLoadIdentity();            

 // Ativa a projeção perspectiva (fov, aspecto, planoProximo, planoDistante)
 gluPerspective(45.0, (float)largura / (float)altura, 1.0, 150.0);

 // Aplica as transformações aos objetos
 glMatrixMode(GL_MODELVIEW);
}

#endif