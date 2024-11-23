// Pinocchio
float size = 0.5f;
int opcaoRoupa = 0;
float tronco = 0.0f, cabeca = 0.0f;
float braco = 0.0f, perna = 0.0f;
float x = 0.0f, y = 0.0f, angulo = 0.0f;

// Luz difusa
float luzDifusa[] = {1.0f, 1.0f, 1.0f, 1.0f};
float intensidade = 1.0f;
float anguloLuzX = 0.0;
float anguloLuzY = 0.0;
float anguloLuzZ = 0.0;

// Animação
float tempo = 0.0f, velocidade = 16.0f;
bool animacao = false;

// Câmera
float posX = 0.0f, posZ = 0.0f;
float distancia = 50.0f, anguloCamera = 0.0f;

#define STB_IMAGE_IMPLEMENTATION
#include "include/includes.h"

int main(int argc, char** argv)
{
 glutInit(&argc, argv); // Inicia a biblioteca

 // Ativa os buffers duplos, cores RGB e teste de profundidade
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
 glutInitWindowSize(800, 800);           // Resolução da janela
 glutInitWindowPosition(0, 0);
 glutCreateWindow("Projeto Pinocchio");   // Título da janela

 inicializa();    // Pré-definições

 glutDisplayFunc(display);       // Renderiza
 glutReshapeFunc(reshape);       // Aplica projeção

 glutKeyboardFunc(teclado);      // Input do teclado
 glutSpecialFunc(tecladoEspecial);
 glutMouseFunc(mouse);   // Input do mouse

 menus();
 
 glutMainLoop();  // Inicia loop

 return 0;        // Sucesso
}