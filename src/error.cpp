#include <string>
#include <sstream>
#include <iostream>

#include "error.h"

using std::string;
using std::stringstream;

void error::error(string name, string message) {
	std::cerr << "\e[0;31m" << name << ":\e[0m " << message << std::endl;
}

void error::fatal(string name, string message) {
	stringstream err_name;
	err_name << "Fatal - " << name;
	error::error(err_name.str(), message);
	exit(1);
}

void error::missing_argument(string command, string parameter) {
	stringstream message;
	message << "Command `" << command << "' expects an argument of `" << parameter << "'.";
	error::fatal("Missing Argument", message.str());
}

