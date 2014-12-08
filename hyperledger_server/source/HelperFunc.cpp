#include "HelperFunc.h"


bool utility::file_exists(const std::string& name)
{
	std::ifstream f(name.c_str());
	if (f.good())
	{
		f.close();
		return true;
	}
	else
	{
		f.close();
		return false;
	}
}



bool utility::file_exists(const char *fileName)
{
	std::ifstream f(fileName);
	if (f.good())
	{
		f.close();
		return true;
	}
	else
	{
		f.close();
		return false;
	}
}


const std::string utility::currentDateTime()
{
	std::stringstream now;

	auto tp = std::chrono::system_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
	size_t modulo = ms.count() % 1000;

	time_t seconds = std::chrono::duration_cast<std::chrono::seconds>(ms).count();
	struct tm timeinfo;
	localtime_s(&timeinfo, &seconds);

	char buffer[25];

	if (strftime(buffer, 25, "%d-%m-%Y %H:%M:%S.", &timeinfo)) {
		now << buffer;
	}

	now.fill('0');
	now.width(3);
	now << modulo;

	return now.str();
}