void cubo(float tamanho) {
    float meio = tamanho / 2.0f;

    glBegin(GL_QUADS);

    // Face superior
    glTexCoord2f(0, 0); glVertex3f(-meio,  meio, -meio);
    glTexCoord2f(1, 0); glVertex3f( meio,  meio, -meio);
    glTexCoord2f(1, 1); glVertex3f( meio,  meio,  meio);
    glTexCoord2f(0, 1); glVertex3f(-meio,  meio,  meio);

    // Face inferior
    glTexCoord2f(0, 0); glVertex3f(-meio, -meio, -meio);
    glTexCoord2f(1, 0); glVertex3f( meio, -meio, -meio);
    glTexCoord2f(1, 1); glVertex3f( meio, -meio,  meio);
    glTexCoord2f(0, 1); glVertex3f(-meio, -meio,  meio);

    // Face frontal
    glTexCoord2f(0, 0); glVertex3f(-meio, -meio,  meio);
    glTexCoord2f(1, 0); glVertex3f( meio, -meio,  meio);
    glTexCoord2f(1, 1); glVertex3f( meio,  meio,  meio);
    glTexCoord2f(0, 1); glVertex3f(-meio,  meio,  meio);

    // Face traseira
    glTexCoord2f(0, 0); glVertex3f(-meio, -meio, -meio);
    glTexCoord2f(1, 0); glVertex3f( meio, -meio, -meio);
    glTexCoord2f(1, 1); glVertex3f( meio,  meio, -meio);
    glTexCoord2f(0, 1); glVertex3f(-meio,  meio, -meio);

    // Face direita
    glTexCoord2f(0, 0); glVertex3f( meio, -meio, -meio);
    glTexCoord2f(1, 0); glVertex3f( meio, -meio,  meio);
    glTexCoord2f(1, 1); glVertex3f( meio,  meio,  meio);
    glTexCoord2f(0, 1); glVertex3f( meio,  meio, -meio);

    // Face esquerda
    glTexCoord2f(0, 0); glVertex3f(-meio, -meio, -meio);
    glTexCoord2f(1, 0); glVertex3f(-meio, -meio,  meio);
    glTexCoord2f(1, 1); glVertex3f(-meio,  meio,  meio);
    glTexCoord2f(0, 1); glVertex3f(-meio,  meio, -meio);

    glEnd();
}