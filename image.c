// image.c

#include "image.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Image createImage(int L, int H, int R) {
    Image image;
    image.length = L;
    image.height = H;
    image.resolution = R;

    // Allocation de mémoire pour les trois composantes de couleur
    image.data = (unchar ***)malloc(3 * sizeof(unchar **));
    
    for (int i = 0; i < 3; i++) {
        image.data[i] = (unchar **)malloc(H * sizeof(unchar *));
        
        for (int j = 0; j < H; j++) {
            image.data[i][j] = (unchar *)malloc(L * sizeof(unchar));
        }
    }

    return image;
}

void freeImage(Image *image) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < image->height; j++) {
            free(image->data[i][j]);
        }
        free(image->data[i]);
    }
    free(image->data);
}

void printImage(const Image *image) {
    printf("Image (composantes rouge, vert, bleu) :\n");
    for (int i = 0; i < 3; i++) {
        printf("Composante %d :\n", i);
        for (int j = 0; j < image->height; j++) {
            for (int k = 0; k < image->length; k++) {
                printf("%hhu ", image->data[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void customDisplay(const Image *image) {
    printf("Affichage personnalisé de l'image :\n");
    for (int j = 0; j < image->height; j++) {
        for (int k = 0; k < image->length; k++) {
            printf("(%hhu, %hhu, %hhu) ", image->data[0][j][k], image->data[1][j][k], image->data[2][j][k]);
        }
        printf("\n");
    }
}
// image.c


void initializeRandom(Image *image) {
    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < image->height; j++) {
            for (int k = 0; k < image->length; k++) {
                image->data[i][j][k] = rand() % 256;
            }
        }
    }
}

