#include "Model.h"

Model::Model()
{
}

Model::Model(const std::pmr::vector<float>& vert)
	:vert(vert)
{
}

Model& Model::operator=(const std::pmr::vector<float>& vert)
{
	this->vert = vert;
	return *this;
}
