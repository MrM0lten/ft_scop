#include "Mesh.h"


Mesh::Mesh(const std::string& filepath)
{
	loadMesh(filepath);
}

void Mesh::loadMesh(const std::string& filepath)
{
	std::ifstream file(filepath);
	std::string line;

	int i = -1;
	while (std::getline(file, line)) {
		std::cout <<line <<std::endl;
		//while (line[++i] == ' '); //segfaults

		//if (line[i] == '#')
		//	continue;
		//else if (line[i] == 'v') {
		//	std::cout << "found V " << line << std::endl;
		//}
		//else if (line[i] == 'o') {
		//	std::cout << "found o " << line << std::endl;
		//}
		//else if (line[i] == 'f') {
		//	std::cout << "found f " << line << std::endl;
		//}
		//get first token
	}

}

const std::string& Mesh::getName() const
{
	return m_name;
}

void Mesh::setName(const std::string& name)
{
	m_name = name;
}
