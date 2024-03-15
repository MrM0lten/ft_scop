#include "ft_OpenGL.h"
#include <iostream>

void Print4x4Matrix(glm::mat4 m) {

	std::cout << m[0][0] << ", " << m[1][0] << ", " << m[2][0] << ", " << m[3][0] << std::endl;
	std::cout << m[0][1] << ", " << m[1][1] << ", " << m[2][1] << ", " << m[3][1] << std::endl;
	std::cout << m[0][2] << ", " << m[1][2] << ", " << m[2][2] << ", " << m[3][2] << std::endl;
	std::cout << m[0][3] << ", " << m[1][3] << ", " << m[2][3] << ", " << m[3][3] << std::endl;

}

void PrintVec4(glm::vec4 v) {
	std::cout << "( " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << " )" << std::endl;
}