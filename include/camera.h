#ifndef CAMERA_H
#define CAMERA_H

void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Limpa os buffers de cor para a próxima cena

 glLoadIdentity();                        // Reinicia as transformações

 posX = distancia * cos(anguloCamera);
 posZ = distancia * sin(anguloCamera);
 
 gluLookAt(posX, 10.0, posZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

 luzes();

 pinoquio(size, tronco, cabeca, braco, perna);             // Desenha cubo

 glutSwapBuffers();  // Troca os buffers/evita o 'flickering' em animações
}

void reshape(int largura, int altura)
{
 glViewport(0, 0, largura, altura);             // Ocupar toda janela
 defineProjecaoPerspectiva(largura, altura);    // Define projeção perspectiva
}

#endif