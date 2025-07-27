#include <iostream>
#include <assert.h>


struct ColorPair {
    int index;
    std::string major;
    std::string minor;
};


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
    std::vector<ColorPair> colorMap = generateColorMap();  
    for (ColorPair &entry : colorMap) 
    {
        std::cout << formatColorMapLine(entry) << "\n";
    }
    return colorMap.size();
}

void testPrintColorMap() 
{
    std::cout << "\nPrint color map test\n";
    auto colorMap = generateColorMap();

    // Count test
    assert(colorMap.size() == 25);

    // Test for BUG in minor color (should fail)
    assert(colorMap[1].minor == "Orange");

    // Test for alignment (line for index 0 vs 10)
    std::string line0 = formatColorMapLine(colorMap[0]);
    std::string line10 = formatColorMapLine(colorMap[10]);

    // This should fail because alignment is inconsistent (different column spacing)
    assert(line0.size() == line10.size());

    std::cout << "All is well (maybe!)\n";
}
