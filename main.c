#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "./header/head.h"  // Inclure le fichier d'en-tête contenant les définitions

// Fonction principale du programme
void main() {
    int length, height, resolution;
    // Demander à l'utilisateur de saisir la longueur de l'image
    printf("Entrez la longueur de l'image : ");
    scanf("%d", &length);

    // Demander à l'utilisateur de saisir la hauteur de l'image
    printf("Entrez la hauteur de l'image : ");
    scanf("%d", &height);

    // Demander à l'utilisateur de saisir la résolution de l'image
    printf("Entrez la résolution de l'image : ");
    scanf("%d", &resolution);

    // Création de l'image
    Image myImage = createImage(length, height, resolution);
    Image graycomp = createImage(length, height, resolution);

    // Générer des valeurs aléatoires dans un fichier et initialiser l'image à partir de ce fichier
    //generateRandomValuesToFile("file.txt", height, length);
    //initializeFile(&myImage, "file.txt");

    // Afficher les composantes de couleur de l'image
    afficher(&myImage);

    // Extraire la composante en niveaux de gris (vert) de l'image
    graycomp = extractGrayscaleComponent(&myImage, 1);

    // Afficher la composante en niveaux de gris
    afficher(&graycomp);

    // Afficher l'image de manière personnalisée
    customDisplay(&graycomp);
}
