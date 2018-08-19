# Filter Magic

Filter Magic is a small CLI tool to apply different filters to images.
It is written in C++ using the OpenCV library.

## Usage

The general usage is `filter-magic <file> [options]` where `[options]` is a list of filters to apply to the image.  
Example:
```bash
# Apply a sepia filter and scale the image by two in width and height.
$ filter-magic input.png sepia scale 2,2
```

As of now, the supported filters are:
 - `grey`/`greyscale`
 - `sepia`
 - `rotate <degrees>`
 - `scale <width>,<height>`

