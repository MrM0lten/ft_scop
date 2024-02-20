#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

class ImGuiDebugger {
public:
	ImGuiDebugger(GLFWwindow* window);
	void Render();
	void Destroy();

private:
	ImGuiIO* _io;
	GLFWwindow* window;
};