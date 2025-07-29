#include "misaligned.h"

vector<std::string&>  generatedMannual;
vector<std::string&>  actualMannual;
void FakeVersionOfPrintFunction(std::string& lineContent){
        generatedMannual.push_back(lineContent);
}
void testPrintColorMap() 
{
  int size=  printColorMap(FakeVersionOfPrintFunction);
    assert(generatedMannual==actualMannual);
    
}
