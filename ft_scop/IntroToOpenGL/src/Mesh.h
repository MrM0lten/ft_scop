#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

class Mesh {
public:
	Mesh(const std::string& filepath);

	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	void loadMesh(const std::string& filepath);

	const std::string& getName() const;
	void setName(const std::string& name);

private:
	std::string m_name;
};