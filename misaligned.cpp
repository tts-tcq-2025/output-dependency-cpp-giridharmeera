#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <assert.h>
#include "misaligned.h"

struct ColorPair {
    int index;
    std::string major;
    std::string minor;
};

std::vector<ColorPair> generateColorMap();
std::string formatColorMapLine(const ColorPair& entry);

std::vector<ColorPair> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<ColorPair> colorMap;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            colorMap.push_back({i * 5 + j, majorColor[i], minorColor[i]});
        }
    }
    return colorMap;
}

std::string formatColorMapLine(const ColorPair& entry) {
    std::ostringstream oss;
    oss << entry.index << " | " << entry.major << " | " << entry.minor;
    return oss.str();
}

int printColorMap() 
{
    auto colorMap = generateColorMap();  
    for (ColorPair &entry : colorMap) 
    {
        std::cout << formatColorMapLine(entry) << "\n";
    }
    return colorMap.size();
}



