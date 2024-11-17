#include <iostream>

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::cout << "Hello " << argv[1] << "!\n";
    } else {
        std::cout << "Hello World\n";
    }
    return 0;
}