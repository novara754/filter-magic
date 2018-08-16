#include <string>
#include <sstream>
#include <iostream>

#include "log.h"

using std::string;
using std::stringstream;

void log::info(string message) {
	std::cout << "\e[0;32m[INFO]\e[0m - " << message << std::endl;
}

void log::error(string name, string message) {
	std::cerr << "\e[0;31m" << name << ":\e[0m " << message << std::endl;
}

void log::fatal(string name, string message) {
	stringstream err_name;
	err_name << "Fatal - " << name;
	log::error(err_name.str(), message);
	exit(1);
}

void log::missing_argument(string command, string parameter) {
	stringstream message;
	message << "Command `" << command << "' expects an argument of `" << parameter << "'.";
	log::fatal("Missing Argument", message.str());
}

