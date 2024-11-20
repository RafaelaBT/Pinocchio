#ifndef ANIMACAO_H
#define ANIMACAO_H

void atualiza(int value) {
   if(animacao)
   {
      tempo += (16/velocidade) * 0.05f;                    // Incrementa o tempo

      size = 2.25 + 1.75 * sin(tempo);   // Oscila de 0.5 a 4.0
      tronco = 7.5 + 7.5 * sin(tempo);   // Oscila de 0 a 15
      cabeca = 0 + 30 * sin(tempo);      // Oscila de -30 a 30
      braco = -7.5 + 37.5 * sin(tempo);  // Oscila de -45 a 30
      perna = 0 + 15 * sin(tempo);       // Oscila de -15 a 15

      glutPostRedisplay();                       // Re-renderiza
      glutTimerFunc(velocidade, atualiza, 0);    // Atualiza a cada 16ms (60 fps)
   }
}

#endif