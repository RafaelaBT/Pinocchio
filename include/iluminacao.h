#ifndef ILUMINACAO_H
#define ILUMINACAO_H

void luzes()
{
   GLfloat posicao[] = { 1.0f, 1.0f, 1.0f, 0.0f };
   GLfloat luzAmbiente[] = {0.2f, 0.2f, 0.2f, 1.0f};
   GLfloat luzEspecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
   
   glLightfv(GL_LIGHT0, GL_POSITION, posicao);
   glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
   glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);

   // configuracao do material
   GLfloat materialAmbiente[] = {0.3, 0.3, 0.3, 1.0};
   GLfloat materialDifuso[] = {1.0, 1.0, 1.0, 1.0};
   GLfloat materialEspecular[] = {1.0, 1.0, 1.0, 1.0};
   GLfloat materialBrilho[] = {50.0};

   glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbiente);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDifuso);
   glMaterialfv(GL_FRONT, GL_SPECULAR, materialEspecular);
   glMaterialfv(GL_FRONT, GL_SHININESS, materialBrilho);
}

void mudaCor(float r, float g, float b)
{
   // Normalizar pra manter a intensidade constante
   float soma = r + g + b;
   if (soma > 0.0f) {
      r = (r / soma) * intensidade;
      g = (g / soma) * intensidade;
      b = (b / soma) * intensidade;
   } else {
      // Luz branca, caso a soma seja zero
      r = g = b = intensidade;
   }
   // Atualiza a luz difusa
   luzDifusa[0] = r, luzDifusa[1] = g, luzDifusa[2] = b;

   glutPostRedisplay(); // Redesenha a cena
}

void mudaIntensidade(float intensidade)
{
   for (int i = 0; i < 3; i++) {
      float novaIntensidade = luzDifusa[i] * intensidade;
      if (novaIntensidade <= 1.0f && novaIntensidade > 0.1)
         luzDifusa[i] = novaIntensidade;
   }

   glutPostRedisplay();
}

#endif