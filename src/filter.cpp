#include <filter.h>

using namespace cv;

void filter::greyscale(Mat &image) {
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++ ) {
			Vec3b &pixel = image.at<Vec3b>(x, y);
			float avg = (pixel[0] + pixel[1] + pixel[2]) / 3;
			for (int i = 0; i < 3; i++) pixel[i] = avg;
		}
	}
}

void filter::rotate(Mat &image, float angle) {
	Point2f center(image.rows / 2, image.cols / 2);
	Mat rotation = getRotationMatrix2D(center, angle, 1.0);
	warpAffine(image, image, rotation, image.size());
}

