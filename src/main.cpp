#include <iostream>

#include "color.h"

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {

        // Progress indicator
        std::clog << "\rScanlines remaining: " << (image_height - j) << " " << std::flush;

        for (int i = 0; i < image_width; i++) {

            auto pixle_color = color(double(i) / double(image_width-1), double(j) / double(image_height-1), 0);

            write_color(std::cout, pixle_color);
        }
    }

    std::clog << "\rDone.                           \n";
}
