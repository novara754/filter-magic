#include <iostream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

#include "error.h"
#include "filter.h"

using namespace cv;

int main(int argc, char **argv) {
	if (argc < 2)
		error::fatal("Invalid Usage", "Use `FilterMagic <image> [options]'.");

	Mat image = imread(argv[1], 1);

	if (!image.data)
		error::fatal("No Image Data", "The selected file does not contain an image.");

	for (int i = 2; i < argc; i++) {
		std::string option(argv[i]);
		if (option == "grey" || option == "greyscale")
			filter::greyscale(image);
		else if (option == "rotate") {
			if (i + 1 >= argc) {
				error::missing_argument("rotate", "angle");
			}
			float angle = atof(argv[++i]);
			if (angle == 0) continue;
			filter::rotate(image, angle);
		}
		else
			error::error("Unknown filter", option);
	}

	std::cout << "Writing image to output.png..." << std::endl;
	imwrite("output.png", image);

	return 0;
}

