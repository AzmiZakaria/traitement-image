// main.c

#include <stdio.h>
#include <stdlib.h>
#include "./image.h"
#include "./process.h"

int main() {
    // Caractéristiques de l'image
    int length, height, resolution;

    printf("Entrez la longueur de l'image : ");
    scanf("%d", &length);

    printf("Entrez la hauteur de l'image : ");
    scanf("%d", &height);

    printf("Entrez la résolution de l'image : ");
    scanf("%d", &resolution);

    // Création de l'image
    Image myImage = createImage(length, height, resolution);
    // Initialisation de l'image avec des valeurs aléatoires
    initializeRandom(&myImage);
    printImage(&myImage);
    customDisplay(&myImage);
    // Traitement d'image : Extraction de la composante rouge (à titre d'exemple)
    Image grayscaleImage = extractComponent(&myImage, RED);

    // Affichage de l'image en niveaux de gris (à titre d'exemple)
    printf("Image en niveaux de gris (composante rouge) :\n");
    printImage(&grayscaleImage);

    // Libération de la mémoire
    freeImage(&myImage);
    freeImage(&grayscaleImage);

    return 0;
}
