// image.h

#ifndef IMAGE_H
#define IMAGE_H

typedef unsigned char unchar;

typedef struct {
    int length;
    int height;
    int resolution;
    unchar ***data;  // Tableau à trois dimensions pour les composantes de couleur
} Image;

// Prototypes des fonctions liées aux images
Image createImage(int L, int H, int R);
void freeImage(Image *image);
void printImage(const Image *image);
void initializeRandom(Image *image);
void customDisplay(const Image *image);

#endif // IMAGE_H
