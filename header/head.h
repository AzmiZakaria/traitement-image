// head.h - Fichier d'en-tête contenant les prototypes de fonctions

// Inclusion des bibliothèques nécessaires
#include "../function/function.c"

// Déclaration des prototypes de fonctions

// Fonction pour créer une image avec la taille spécifiée
Image createImage(int L, int H, int R);

// Fonction pour libérer la mémoire utilisée par une image
void freeImage(Image *image);

// Fonction pour afficher les composantes de couleur d'une image
void afficher(const Image *image);

// Fonction pour initialiser une image avec des valeurs aléatoires
void initializeRandom(Image *image);

// Fonction pour initialiser une image à partir des valeurs saisies par l'utilisateur
void initializeClavier(Image *image);

// Fonction pour générer des valeurs aléatoires dans un fichier spécifié
void generateRandomValuesToFile(const char *filename, int height, int length);

// Fonction pour initialiser une image à partir des valeurs stockées dans un fichier
void initializeFile(Image *image, const char *filename);

// Fonction pour extraire une composante en niveaux de gris d'une image
Image extractGrayscaleComponent(const Image *originalImage, int componentIndex);

// Fonction pour afficher une image de manière personnalisée
void customDisplay(const Image *image);
