#pragma once
#include <string>
#include <boost/uuid/uuid_generators.hpp>
#include  <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid.hpp>
class UuidTool
{
 static	boost::uuids::random_generator rgen;
public:	
 static	std::string random();
};

