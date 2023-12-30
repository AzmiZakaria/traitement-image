
#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include "./image.h"

typedef enum {
    RED,
    GREEN,
    BLUE
} ColorComponent;

// Prototypes des fonctions de traitement d'image
Image extractComponent(const Image *image, ColorComponent component);
Image applyBlur(const Image *image);

#endif // IMAGE_PROCESSING_H
