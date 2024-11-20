#ifndef MOUSE_H
#define MOUSE_H

void mouse(int botao, int estado, int x, int y)
{
    if (botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        opcaoRoupa = (opcaoRoupa + 1) % 3;
        glutPostRedisplay();
    }
}

#endif