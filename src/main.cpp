#include <iostream>
#include <string>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

#include "log.h"
#include "filter.h"

using namespace cv;
using std::string;

int main(int argc, char **argv) {
	if (argc < 2)
		log::fatal("Invalid Usage", "Use `FilterMagic <image> [options]'.");

	Mat image = imread(argv[1], 1);
	string out_file = "output.png";

	if (!image.data)
		log::fatal("No Image Data", "The selected file does not contain an image.");

	for (int i = 2; i < argc; i++) {
		string option(argv[i]);
		if (option == "grey" || option == "greyscale" || option == "gray" || option == "grayscale") {
			filter::greyscale(image);
		} else if (option == "sepia") {
			filter::sepia(image);
		} else if (option == "rotate") {
			if (i + 1 >= argc) {
				log::missing_argument("rotate", "angle");
			}
			float angle = atof(argv[++i]);
			if (angle == 0) continue;
			filter::rotate(image, angle);
		} else if (option == "scale" || option == "resize") {
			if (i + 1 >= argc) {
				log::missing_argument("scale", "width,height");
			}
			string input(argv[++i]);
			int i = input.find(',');
			float width = atof(input.substr(0, i).c_str());
			float height = atof(input.substr(i + 1, input.size() - i).c_str());
			if (width == 1 && height == 1) continue;
			filter::scale(image, width, height);
		} else if (option == "output") {
			out_file = argv[++i];
		} else {
			log::error("Unknown filter", option);
		}
	}

	std::stringstream message;
	message << "Writing image to " << out_file << "...";
	log::info(message.str());
	imwrite(out_file, image);

	return 0;
}

