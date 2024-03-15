#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "vendor/stb_image/stb_image.h"


void Print4x4Matrix(glm::mat4 m);
void PrintVec4(glm::vec4 v);