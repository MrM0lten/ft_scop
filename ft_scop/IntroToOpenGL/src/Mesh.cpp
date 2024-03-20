#include "Mesh.h"


Mesh::Mesh(const std::string& filepath)
	:m_verbose(false)
{
	loadMesh(filepath);
}

void Mesh::loadMesh(const std::string& filepath)
{
	std::ifstream file(filepath);
	std::string line;

	while (std::getline(file, line)) {

		std::vector<std::string> values = tokenizeString(line);

		//for (size_t i = 0; i < values.size(); i++)
		//	std::cout <<"[" << i << "] " << values[i] << std::endl;

		const size_t tokens = values.size();
		//std::cout << "'" << values[0] << "'" << std::endl;
		if (tokens <= 1)
			continue;

		if (values[0].compare("#") == 0) {
			continue;
		}
		else if (values[0].compare("v") == 0) {
			for (size_t i = 1; i < tokens; i++){
				vertices.push_back(std::stof(values[i]));
			}
		}
		else if (values[0].compare("o") == 0) {
			setName(values[1]);
		}
		else if (values[0].compare("f") == 0) {
			for (size_t i = 1; i < tokens; i++) {
				indices.push_back(std::stoi(values[i]));
			}
		}
		
	}

}

const std::string& Mesh::getName() const
{
	return m_name;
}

bool Mesh::getVerbose() const
{
	return m_verbose;
}

void Mesh::setName(const std::string& name)
{
	m_name = name;
}

void Mesh::setVerbose(bool verbose)
{
	m_verbose = verbose;
}


std::vector<std::string> Mesh::tokenizeString(const std::string& line) 
{
	std::vector<std::string> tokens;
	auto it = line.begin();
	int strlen;
	int pos = 0;
	while (it < line.end()) {
		strlen = 0;
		while (*it != '\0' && isblank(*it)) {
			pos++;
			it++;
		}
		while (it + strlen < line.end() && it[strlen] != '\n' && !isblank(it[strlen])) {
			strlen++;
		}
		tokens.push_back(line.substr(pos, strlen));
		it += strlen;
		pos += strlen;
	}

	//for (size_t i = 0; i < tokens.size(); i++)
	//	std::cout << "[" << i << "] " << tokens[i] << std::endl;
	


	return tokens;
}


std::ostream& operator<<(std::ostream& os, const Mesh& mesh)
{
	os << "###------------ Mesh Info of: '" << mesh.getName() << "' --------------------###" << std::endl;
	os << " Vertices: " << mesh.vertices.size() << std::endl;
	os << " Indices: " << mesh.indices.size() << std::endl;

	if (mesh.getVerbose()) {

		for (size_t i = 0; i < mesh.vertices.size(); i++) {
			os << mesh.vertices[i] << ", ";
		}
		os << std::endl;
		os << "----------------------------------" << std::endl;
		for (size_t i = 0; i < mesh.indices.size(); i++) {
			os << mesh.indices[i] << ", ";
		}
		os << std::endl;
	}
	os << "###-------------------------------------------------------------------###" << std::endl;
	return os;
}