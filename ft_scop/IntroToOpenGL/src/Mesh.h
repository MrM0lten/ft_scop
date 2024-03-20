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

public: //getters setters
	const std::string& getName() const;
	bool getVerbose() const;

	void setName(const std::string& name);
	void setVerbose(bool verbose);

private:
	std::string m_name;
	bool m_verbose; //for debugging the content, by default false

	std::vector<std::string> tokenizeString(const std::string& line);
};

std::ostream& operator<<(std::ostream& os, const Mesh& dt);