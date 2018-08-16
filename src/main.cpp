#include <iostream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

using namespace cv;

void missing_argument_error(std::string command, std::string parameter);
void filter_greyscale(Mat &image);
void filter_rotate(Mat &image, float angle);

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
			filter_greyscale(image);
		else if (option == "rotate") {
			if (i + 1 >= argc) {
				missing_argument_error("rotate", "angle");
			}
			float angle = atof(argv[++i]);
			if (angle == 0) continue;
			filter_rotate(image, angle);
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

void filter_rotate(Mat &image, float angle) {
	Point2f center(image.rows / 2, image.cols / 2);
	Mat rotation = getRotationMatrix2D(center, angle, 1.0);
	warpAffine(image, image, rotation, image.size());
}

void filter_greyscale(Mat &image) {
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++ ) {
			Vec3b &pixel = image.at<Vec3b>(x, y);
			float avg = (pixel[0] + pixel[1] + pixel[2]) / 3;
			for (int i = 0; i < 3; i++) pixel[i] = avg;
		}
	}
}

