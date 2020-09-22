#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

// Simple helper function to load an image into a OpenGL texture with common settings
bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
bool LoadTextureFromMemory(const unsigned char * Data, int size, GLuint* out_texture, int* out_width, int* out_height);