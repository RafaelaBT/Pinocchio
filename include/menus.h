#ifndef MENUS_H
#define MENUS_H

void menu(int opcao)
{
   switch (opcao)
   {
      case 1:
         size = 0.5, opcaoRoupa = 0;
         tronco = 0.0, cabeca = 0.0;
         braco = 0.0, perna = 0.0;
         x = 0.0f, y = 0.0f, angulo = 0.0f;
         luzDifusa[0] = 1.0f, luzDifusa[1] = 1.0f;
         luzDifusa[2] = 1.0f, luzDifusa[3] = 1.0f;
         intensidade = 1.0f;
         anguloLuzX = 0.0, anguloLuzY = 0.0, anguloLuzZ = 0.0;
         tempo = 0.0f, velocidade = 16.0;
         animacao = false;
         posX = 0.0f, posZ = 0.0f;
         distancia = 50.0f; anguloCamera = 0.0f;
         break;
      case 0:
         exit(0);
         break;
   }
   glutPostRedisplay();
}

void menuAnimacao(int opcao)
{
   switch (opcao)
   {
      case 1:
         if (!animacao)
         {
            animacao = true;
            glutTimerFunc(velocidade, atualiza, 0);
         }
         break;
      case 2:
         animacao = false;
         break;
   }
   glutPostRedisplay();
}

void menuVelocidade(int opcao)
{
   switch (opcao)
   {
      case 1:
         velocidade = 32;
         break;
      case 2:
         velocidade = 16;
         break;
      case 3:
         velocidade = 8;
         break;
      case 4:
         velocidade = 4;
         break;
   }
   glutPostRedisplay();
}

void menuIluminacao(int opcao)
{
   switch (opcao)
   {
      case 1:
         mudaCor(1.0, 1.0, 1.0);
         break;
      case 2:
         mudaCor(1.0, 0.0, 0.0);
         break;
      case 3:
         mudaCor(0.0, 1.0, 0.0);
         break;
      case 4:
         mudaCor(0.0, 0.0, 1.0);
         break;
      case 5:
         mudaCor(1.0, 1.0, 0.0);
         break;
      case 6:
         mudaCor(1.0, 0.5, 0.0);
         break;
   }
   glutPostRedisplay();
}

void menus()
{
   int subMenuVelocidade = glutCreateMenu(menuVelocidade);
   glutAddMenuEntry("0.5x", 1);
   glutAddMenuEntry("1.0x", 2);
   glutAddMenuEntry("1.5x", 3);
   glutAddMenuEntry("2.0x", 4);

   int subMenuAnimacao = glutCreateMenu(menuAnimacao);
   glutAddMenuEntry("Iniciar", 1);
   glutAddMenuEntry("Pausar", 2);
   glutAddSubMenu("Velocidade", subMenuVelocidade);

   int subMenuCor = glutCreateMenu(menuIluminacao);
   glutAddMenuEntry("Branco", 1);
   glutAddMenuEntry("Vermelho", 2);
   glutAddMenuEntry("Verde", 3);
   glutAddMenuEntry("Azul", 4);
   glutAddMenuEntry("Amarelo", 5);
   glutAddMenuEntry("Laranja", 6);

   int subMenuIluminacao = glutCreateMenu(menuIluminacao);
   glutAddSubMenu("Cor", subMenuCor);

   glutCreateMenu(menu);
   glutAddSubMenu("Animacao", subMenuAnimacao);
   glutAddSubMenu("Iluminacao", subMenuIluminacao);
   glutAddMenuEntry("Reiniciar", 1);
   glutAddMenuEntry("Sair", 0);

   glutAttachMenu(GLUT_RIGHT_BUTTON);
}

#endif