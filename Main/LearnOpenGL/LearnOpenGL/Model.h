#pragma once
#include <memory_resource>
#include <vector>
#include <iostream>
class Model
{
public:
	Model();
	Model(const std::pmr::vector<float>& vert);
	std::pmr::vector<float> vert;
	Model& operator=(const std::pmr::vector<float>& vert);
};

