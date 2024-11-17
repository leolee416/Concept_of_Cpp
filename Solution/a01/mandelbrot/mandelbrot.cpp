#include <complex>
#include <print> // C++23 Feature: std::print

namespace mandelbrot {

void mandelbrot(double realCenter, double imagCenter, double width, double height) {
    int col = 200; // Each line contains 200 characters
    double f_w = width / col; // Width of each pixel in the complex plane
    double f_h = f_w / 0.4; // Height of each pixel, adjusted for terminal aspect ratio
    int row = static_cast<int>(height / f_h); // Calculate the number of rows to maintain aspect ratio
    double r_min = realCenter - width / 2.0; // Real axis minimum (left boundary)
    double r_max = realCenter + width / 2.0; // Real axis maximum
    double i_min = imagCenter - height / 2.0; // Imaginary axis maximum (top boundary)
    double i_max = imagCenter + height / 2.0; // Imaginary axis maximum (top boundary)

    // Iterate over each row
    for (int i = 0; i < row; ++i) {
        // Iterate over each column
        for (int j = 0; j < col; ++j) {
            double x = r_min + (r_max - r_min) * j / col;
            double y = i_min + (i_max - i_min) * i / row;
            std::complex<double> c1(x, y); // Complex number corresponding to current pixel
            std::complex<double> c2(0, 0); // Initialize z0 to (0, 0)
            int k = 0;
            // Iterate to compute Mandelbrot set
            for (; k < 200; ++k) {
                if (std::abs(c2) > 2.0) { // Check if the point has diverged
                    std::print(" "); // If it diverged, print a space
                    break;
                }
                c2 = c2 * c2 + c1; // Mandelbrot iteration: z(i+1) = z(i)^2 + c
            }
            if (k == 200) {
                std::print("*"); // If after 200 iterations the point did not diverge, print '*'
            }
        }
        std::println(""); // Use '' for new line
    }
}
} // namespace mandelbrot

// int main() {
//     mandelbrot::mandelbrot(0.0, 0.0, 4.0, 3.0);
//     std::println("end 1:");
//     mandelbrot::mandelbrot(0.0, 0.0, 1.0, 2.0);
//     std::println("end 2:");
//     mandelbrot::mandelbrot(0.5, 0.5, 500.0, 100.0);

//     return 0;
// }
