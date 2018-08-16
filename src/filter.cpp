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

void filter::sepia(Mat &image) {
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++ ) {
			Vec3b &pixel = image.at<Vec3b>(x, y);
			float new_r = pixel[2] * 0.393 + pixel[1] * 0.769 + pixel[0] * 0.189;
			float new_g = pixel[2] * 0.349 + pixel[1] * 0.686 + pixel[0] * 0.168;
			float new_b = pixel[2] * 0.272 + pixel[1] * 0.534 + pixel[0] * 0.131;
			pixel[0] = new_b > 255 ? 255 : new_b;
			pixel[1] = new_g > 255 ? 255 : new_g;
			pixel[2] = new_r > 255 ? 255 : new_r;
		}
	}
}

void filter::rotate(Mat &image, float angle) {
	Point2f center(image.rows / 2, image.cols / 2);
	Mat rotation = getRotationMatrix2D(center, angle, 1.0);
	warpAffine(image, image, rotation, image.size());
}

void filter::scale(Mat &image, float width, float height) {
	resize(image, image, Size(), width, height);
}

