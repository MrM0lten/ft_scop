#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <iostream>

#include "Mesh.h"

class ImGuiDebugger {
public:
	ImGuiDebugger(GLFWwindow* window);
	void Render();
	void Destroy();

private:
	ImGuiIO* _io;
	GLFWwindow* window;
};


//image loading currently set here
Mesh* Load3DMesh(const std::string& filepath);