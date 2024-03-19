#include <iostream>
#include "Mesh.h"

Mesh* Load3DMesh(const std::string& filepath) {

	std::cout <<"This is the filepath: " << filepath << std::endl;
	//determine filetype
		//if obj call load Obj object
			//todo: figure out what a base object needs to contain

	Mesh* mesh = new Mesh(filepath);
	return mesh;

}