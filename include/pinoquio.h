#ifndef PINOQUIO_H
#define PINOQUIO_H

#include <stdio.h>

typedef struct {
    float r, g, b;
} Cor;

Cor branco = {1.0f, 1.0f, 1.0f};
Cor amarelo = {1.0f, 1.0f, 0.0f};
Cor verde = {0.0f, 1.0f, 0.0f};
Cor azul = {0.0f, 0.0f, 1.0f};
Cor magenta = {1.0f, 0.0f, 1.0f};
Cor ciano = {0.0f, 1.0f, 1.0f};

Cor roupa1[] = {branco, verde, magenta};
Cor roupa2[] = {amarelo, azul, ciano};

void membrosSuperiores(float pos, float braco)
{
   glPushMatrix();
      glTranslatef(pos, 0.0, -0.8);
      glRotatef(braco, 1.0, 0.0, 0.0);

      // Braço
      glPushMatrix();
         glRotatef(15, 1.0, 0.0, 0.0);      // Rotaciona braço
         glColor3f(roupa1[opcaoRoupa].r, roupa1[opcaoRoupa].g, roupa1[opcaoRoupa].b);
         glScalef(1.5, 4.0, 2.0);
         glutSolidCube(1.0);
      glPopMatrix();

      // Antebraço
      glPushMatrix();
         glTranslatef(0.0, -4.0, 0.0);
         glRotatef(-15, 1.0, 0.0, 0.0);    // Rotaciona antebraço
         glColor3f(1.0, 0.5, 0.0);
         glScalef(1.0, 5.0, 1.5);
         glutSolidCube(1.0);
      glPopMatrix();
   glPopMatrix();
}

void membrosInferiores(float pos, float perna)
{
   glPushMatrix();
      glTranslatef(pos, 0.0, 0.0);
      glRotatef(perna - 10.0, 1.0, 0.0, 0.0);      // Rotaciona perna

      // Coxa
      glPushMatrix();
         glColor3f(1.0, 0.0, 0.0);
         glScalef(1.5, 4.5, 2.0);
         glutSolidCube(1.0);
      glPopMatrix();

      glPushMatrix();
         glTranslatef(0.0, -5.5, -1.0);

         // Panturrilha
         glPushMatrix();
            glRotatef(20, 1.0, 0.0, 0.0); // Rotaciona panturrilha
            glColor3f(1.0, 0.5, 0.0);
            glScalef(1.5, 7.0, 1.5);
            glutSolidCube(1.0);
         glPopMatrix();

         // Pé
         glPushMatrix();
            glTranslatef(0.0, -4.0, -0.5);
            glRotatef(10.0, 1.0, 0.0, 0.0); // Rotaciona pé
            glColor3f(1.0, 0.0, 0.0);
            glScalef(1.5, 1.5, 3.5);
            glutSolidCube(1.0);
         glPopMatrix();
      glPopMatrix();
   glPopMatrix();
}

void pinoquio(float size, float tronco, float cabeca, float braco, float perna)
{
   glPushMatrix();
      GLfloat posicao[] = {1.0, 1.0, 1.0, 0.0}; // 0: luz direcional 1: pontual
      glRotatef(anguloLuzX, 1.0, 0.0, 0.0);
      glRotatef(anguloLuzY, 0.0, 1.0, 0.0);
      glRotatef(anguloLuzZ, 0.0, 0.0, 1.0);
      glLightfv(GL_LIGHT0, GL_POSITION, posicao);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(x, y, 0.0f);  // Move corpo
      glRotatef(angulo, 0.0, 1.0, 0.0);      // Rotaciona corpo

      glPushMatrix();
         glRotatef(tronco + 6.0, 1.0, 0.0, 0.0);  // Rotaciona tronco + pescoço

         glPushMatrix();
            // Tronco
            glPushMatrix();
               glColor3f(roupa2[opcaoRoupa].r, roupa2[opcaoRoupa].g, roupa2[opcaoRoupa].b);
               glScalef(3.5, 6.0, 2.0);
               glutSolidCube(1.0);
            glPopMatrix();

            // Braços
            glPushMatrix();
               glTranslatef(0.0, 1.0, 0.0);
               membrosSuperiores(2.5, braco);    // Braço esquerda
               membrosSuperiores(-2.5, -braco);   // Braço direita
            glPopMatrix();
         glPopMatrix();

         glPushMatrix();
            glTranslatef(0.0, 3.3, 0.0);
            glRotatef(cabeca, 0.0, 1.0, 0.0);  // Rotaciona pescoço + cabeça

            // Pescoço
            glPushMatrix();
               glColor3f(1.0, 0.5, 0.0);
               glScalef(1.0, 2.0, 1.0);
               glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
               glTranslatef(0.0, 2.8, 0.0);
               // Cabeça
               glPushMatrix();
                  glColor3f(1.0, 0.5, 0.0);
                  glScalef(2.0, 2.0, 2.0);
                  glutSolidSphere(1.0, 10.0, 10.0);
               glPopMatrix();

               // Chapéu
               glPushMatrix();
                  glColor3f(roupa2[opcaoRoupa].r, roupa2[opcaoRoupa].g, roupa2[opcaoRoupa].b);
                  glTranslatef(0.0, 1.5, 0.0);
                  glRotatef(-90, 1.0, 0.0, 0.0);
                  glutSolidCone(1.5, 2.0, 10.0, 10.0);
               glPopMatrix();

               // Nariz
               glPushMatrix();
                  glColor3f(1.0, 0.0, 0.0);
                  glTranslatef(0.0, 0.0, size);
                  glScalef(0.5, 0.5, 4.5);
                  glutSolidCube(1.0);
               glPopMatrix();     
            glPopMatrix();   
         glPopMatrix();
      glPopMatrix();

      // Pernas
      glPushMatrix();
         glTranslatef(0.0, -4.6, -0.3);
         membrosInferiores(1.0, perna);    // Perna esquerda
         membrosInferiores(-1.0, -perna);   // Perna direita
      glPopMatrix();
   glPopMatrix();
}

#endif