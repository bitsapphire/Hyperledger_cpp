#ifndef HELPERFUNC_H
#define HELPERFUNC_H


#include <time.h>
#include <ctime>
#include <chrono>
#include <sstream>
#include <fstream>

namespace utility
{
	bool file_exists(const std::string& name);

	bool file_exists(const char *fileName);

	const std::string currentDateTime();
}

#endif