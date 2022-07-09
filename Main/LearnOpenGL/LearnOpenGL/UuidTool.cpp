#include "UuidTool.h"

boost::uuids::random_generator UuidTool::rgen;

std::string UuidTool::random()
{

    return 	 boost::uuids::to_string(rgen());;
}
