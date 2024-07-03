#include <iostream>
#include <fstream>

#define _PROFILE
#ifdef _PROFILE
#include <chrono>
#endif // _PROFILE

#include "Polygon2D.h"

//---------------------------------------------------------------------------------------

int main
(
    int argc,
    char** argv
)
{
    if (argc < 2) {
        std::cout << "Argument:\nname of text file containing coordinates of nodes\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "Can't open file\n";
        return 1;
    }

#ifdef _PROFILE
    auto start = std::chrono::high_resolution_clock::now();
#endif // _PROFILE

    auto result = TPolygon2D(file).GetAllAxisOfSymmetry();

#ifdef _PROFILE
    auto duration = std::chrono::high_resolution_clock::now() - start;
#endif // _PROFILE

    if (result.size()) {
        std::copy(
            result.begin(),
            result.end(),
            std::ostream_iterator<TLine2D>(std::cout, "\n")
        );
    }
    else
        std::cout << "non-symmetric\n";

#ifdef _PROFILE
    std::cout << "Time ns: " << duration.count();
#endif // _PROFILE

    return 0;
}
