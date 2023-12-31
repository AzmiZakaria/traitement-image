#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef unsigned char unchar;

typedef struct {
    int length;
    int height;
    int resolution;
    unchar ***data;  // Tableau à trois dimensions pour les composantes de couleur
} Image;

Image createImage(int L, int H, int R) {
    Image image;
    image.length = L;
    image.height = H;
    image.resolution = R;

    // Allocation de mémoire pour les trois composantes de couleur
    image.data=(unchar***)malloc(3*sizeof(unchar**));
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

void afficher(const Image *image) {
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

void initializeClavier(Image *image) {
    printf("Veuillez entrer les valeurs pour chaque composante de couleur (rouge, vert, bleu) :\n");

    for (int i = 0; i < 3; i++) {
        printf("Composante %d :\n", i);

        for (int j = 0; j < image->height; j++) {
            for (int k = 0; k < image->length; k++) {
                printf("Valeur pour la position (%d, %d) : ", j + 1, k + 1);
                scanf("%hhu", &image->data[i][j][k]);
            }
        }
    }
}

void generateRandomValuesToFile(const char *filename, int height, int length) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s pour l'écriture.\n", filename);
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < length; k++) {
                fprintf(file, "%hhu ", rand() % 256);
            }
            fprintf(file, "\n");
        }
    }

    fclose(file);
    printf("Données aléatoires générées et écrites dans le fichier %s.\n", filename);
}

void initializeFile(Image *image, const char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s.\n", filename);
        return;
    }

    printf("Lecture des données à partir du fichier %s...\n", filename);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < image->height; j++) {
            for (int k = 0; k < image->length; k++) {
                if (fscanf(file, "%hhu", &image->data[i][j][k]) != 1) {
                    fprintf(stderr, "Erreur lors de la lecture du fichier %s.\n", filename);
                    fclose(file);
                    return;
                }
            }
        }
    }

    fclose(file);
    printf("Données lues avec succès à partir du fichier %s.\n", filename);
}

Image extractGrayscaleComponent(const Image *originalImage, int componentIndex) {
    if (componentIndex < 0 || componentIndex >= 3) {
        fprintf(stderr, "Index de composante invalide. Utiliser 0 pour rouge, 1 pour vert, 2 pour bleu.\n");
        exit(EXIT_FAILURE);
    }

    Image grayscaleImage = createImage(originalImage->length, originalImage->height, originalImage->resolution);

    for (int j = 0; j < originalImage->height; j++) {
        for (int k = 0; k < originalImage->length; k++) {
            // La composante spécifiée est copiée dans chaque composante de la nouvelle image
            for (int i = 0; i < 3; i++) {
                if (i == componentIndex) {
                    grayscaleImage.data[i][j][k] = originalImage->data[i][j][k];
                } else {
                    grayscaleImage.data[i][j][k] = 0;  // Les autres composantes sont mises à zéro
                }
            }
        }
    }

    return grayscaleImage;
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
