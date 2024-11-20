#ifndef TECLADO_H
#define TECLADO_H

void teclado(unsigned char tecla, int xPos, int yPos)
{
   switch(tecla)
   {
      case '+':
         if (size < 4.0)
            size += 0.5;   // Aumenta o nariz
         break;
      case '-':
         if (size > 0.5)
            size -= 0.5;   // Diminui o nariz
         break;
      case '*':
         mudaIntensidade(2.0f);
         break;
      case '/':
         mudaIntensidade(0.5f);
         break;
      case 't':
         if (tronco < 15)
            tronco += 1.0; // Rotaciona o tronco para frente
         break;
      case 'T':
         if (tronco > 0.0)
            tronco -= 1.0; // Rotaciona o tronco para trás
         break;
      case 'c':
         if (cabeca < 30)
            cabeca += 3.0; // Rotaciona a cabeça pra direita
         break;
      case 'C':
         if (cabeca > -30)
            cabeca -= 3.0; // Rotaciona a cabeça pra esquerda
         break;
      case 'b':
         if (braco > -45)
            braco -= 3.0; // Rotaciona o braço pra frente
         break;
      case 'B':
         if (braco < 30)
            braco += 3.0; // Rotaciona o braço pra trás
         break;
      case 'p':
         if (perna > -15)
            perna -= 1.0; // Rotaciona a perna pra frente
         break;
      case 'P':
         if (perna < 15)
            perna += 1.0; // Rotaciona a perna pra trás
         break;
      case 'w':
      case 'W':
         y += 1.0f;
         break;
      case 's':
      case 'S':
         y -= 1.0f;
         break;
      case 'a':
      case 'A':
         x -= 1.0f;
         break;
      case 'd':
      case 'D':
         x += 1.0f;
         break;
      case 'q':
      case 'Q':
         angulo -= 5.0f;
         break;
      case 'e':
      case 'E':
         angulo += 5.0f;
         break;
      case '5':
         anguloLuzX -= 5.0;
         break;
      case '2':
         anguloLuzX += 5.0;
         break;
      case '1':
         anguloLuzY -= 5.0;
         break;
      case '3':
         anguloLuzY += 5.0;
         break;
      case '4':
         anguloLuzZ -= 5.0;
         break;
      case '6':
         anguloLuzZ += 5.0;
         break;
   }
   glutPostRedisplay();
}

void tecladoEspecial(int tecla, int xPos, int yPos)
{
   switch(tecla)
   {
      case GLUT_KEY_UP:
         if (distancia > 50.f)
         {
            distancia -= 1.0f;
         }
         break;
      case GLUT_KEY_DOWN:
         if (distancia < 100.f)
         {
            distancia += 1.0f;
         }
         break;
      case GLUT_KEY_LEFT:
         anguloCamera += 0.1f;
         break;
      case GLUT_KEY_RIGHT:
         anguloCamera -= 0.1f;
         break;
   }  
   glutPostRedisplay();
}

#endif