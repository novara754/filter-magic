#ifndef filter_magic_filter_h
#define filter_magic_filter_h

#include <opencv2/opencv.hpp>

namespace filter {
	void greyscale(cv::Mat &source);
	void rotate(cv::Mat &source, float angle);
}

#endif

