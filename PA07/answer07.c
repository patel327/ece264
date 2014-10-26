#include "answer07.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>

Image * Image_loadbmp(const char * filename)

int Image_savebmp(const char * filename, Image * image)

Image * Image_load(const char * filename)

int Image_save(const char * filename, Image * image)

void Image_free(Image * image)

void linearNormalization(int width, int height, uint8_t * intensity)
