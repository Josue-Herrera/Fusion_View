#pragma once

#include <glad/glad.h>

bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
bool LoadTextureFromMemory(const unsigned char * Data, int size, GLuint* out_texture, int* out_width, int* out_height);