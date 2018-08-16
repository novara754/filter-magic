#include <iostream>
#include <string>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

#include "error.h"
#include "filter.h"

using namespace cv;
using std::string;

int main(int argc, char **argv) {
	if (argc < 2)
		error::fatal("Invalid Usage", "Use `FilterMagic <image> [options]'.");

	Mat image = imread(argv[1], 1);
	string out_file = "output.png";

	if (!image.data)
		error::fatal("No Image Data", "The selected file does not contain an image.");

	for (int i = 2; i < argc; i++) {
		string option(argv[i]);
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
		else if (option == "output") {
			out_file = argv[++i];
		}
		else
			error::error("Unknown filter", option);
	}

	std::cout << "Writing image to " << out_file << "..." << std::endl;
	imwrite(out_file, image);

	return 0;
}

