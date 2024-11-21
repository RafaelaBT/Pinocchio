#ifndef TEXTURAS_H
#define TEXTURAS_H

#include <GL/glut.h>
#include "stb/stb_image.h"

GLuint textura;

void carregaTextura(const char* filename)
{
    int width, height, channels;
    unsigned char* image = stbi_load("sua_imagem.jpg", &width, &height, &channels, 0);

    if (image == NULL) {
        printf("Erro ao carregar a imagem.\n");
    }

    GLuint textura;
    glGenTextures(1, &textura);
    glBindTexture(GL_TEXTURE_2D, textura);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(image);
}

void texturas()
{
    carregaTextura("../texturas/madeira.jpg");
}

#endif