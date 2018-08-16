#ifndef filter_magic_error_h
#define filter_magic_error_h

#include <string>

namespace error {
	void error(std::string name, std::string message);
	void fatal(std::string name, std::string message);
	void missing_argument(std::string command, std::string parameter);
}

#endif

