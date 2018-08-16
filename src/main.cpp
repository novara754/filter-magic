#include <iostream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

#include "filter.h"

using namespace cv;

void missing_argument_error(std::string command, std::string parameter);

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: FilterMagic <image> [options]" << std::endl;
		return -1;
	}

	Mat image = imread(argv[1], 1);

	if (!image.data) {
		std::cerr << "No image data." << std::endl;
		return -1;
	}

	for (int i = 2; i < argc; i++) {
		std::string option(argv[i]);
		if (option == "grey" || option == "greyscale")
			filter::greyscale(image);
		else if (option == "rotate") {
			if (i + 1 >= argc) {
				missing_argument_error("rotate", "angle");
			}
			float angle = atof(argv[++i]);
			if (angle == 0) continue;
			filter::rotate(image, angle);
		}
		else
			std::cerr << "Unknown filter: " << option << std::endl;
	}

	std::cout << "Writing image to output.png..." << std::endl;
	imwrite("output.png", image);

	return 0;
}

void missing_argument_error(std::string command, std::string parameter) {
		std::cerr << "Missing argument: Command `" << command << "' expects an argument of `" << parameter << "'." << std::endl;
		exit(-1);
}

