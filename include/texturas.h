#ifndef TEXTURAS_H
#define TEXTURAS_H

#include <GL/glut.h>
#include <windows.h>
#include "stb/stb_image.h"

GLuint textura;

void substituirBarra(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\\') {
            str[i] = '/';
        }
    }
}

char* caminhoAbsoluto(const char* caminho_relativo)
{
    char* caminho_absoluto = (char*)malloc(MAX_PATH * sizeof(char));
    
    if (caminho_absoluto == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    // Usa GetFullPathName para obter o caminho absoluto
    DWORD resultado = GetFullPathNameA(caminho_relativo, MAX_PATH, caminho_absoluto, NULL);
    
    if (resultado == 0) {
        free(caminho_absoluto);  // Libera a memória caso haja erro
        exit(1);  // Retorna NULL em caso de erro
    }

    substituirBarra(caminho_absoluto);

    // Retorna o caminho absoluto
    return caminho_absoluto;
}

void carregaTextura(const char* filename)
{
    int width, height, channels;
    unsigned char* image = stbi_load(caminhoAbsoluto(filename), &width, &height, &channels, 0);

    if (image == NULL) {
        printf("Erro ao carregar a imagem.\n");
    }

    glGenTextures(1, &textura);
    glBindTexture(GL_TEXTURE_2D, textura);

    // Usando gluBuild2DMipmaps para gerar MIPMAPs manualmente
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, image);

    // Configurar filtros para minificação e magnificação
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Configurar mapeamento de bordas
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    stbi_image_free(image);
}

void texturas()
{
    carregaTextura("texturas/madeira.jpg");
}

#endif