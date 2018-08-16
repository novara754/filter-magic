#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

void filter_greyscale(Mat &image) {
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++ ) {
			Vec3b &pixel = image.at<Vec3b>(x, y);
			float avg = (pixel[0] + pixel[1] + pixel[2]) / 3;
			for (int i = 0; i < 3; i++) pixel[i] = avg;
		}
	}
}

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
		else
			std::cerr << "Unknown filter: " << option << std::endl;
	}

	return 0;
}

