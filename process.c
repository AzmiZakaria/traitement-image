// imageProcessing.c

#include "./process.h"

Image extractComponent(const Image *image, ColorComponent component) {
    Image grayscaleImage = createImage(image->length, image->height, image->resolution);

    for (int j = 0; j < image->height; j++) {
        for (int k = 0; k < image->length; k++) {
            grayscaleImage.data[0][j][k] = grayscaleImage.data[1][j][k] = grayscaleImage.data[2][j][k] = image->data[component][j][k];
        }
    }

    return grayscaleImage;
}

// imageProcessing.c

Image applyBlur(const Image *image) {
    Image blurredImage = createImage(image->length, image->height, image->resolution);

    // Implémentation de l'algorithme de flou (à adapter selon vos besoins)
    // ...

    return blurredImage;
}
