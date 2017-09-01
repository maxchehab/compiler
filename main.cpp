#include <string>
#include <iostream>
#include "preprocessor.h"

using namespace std;


int main() public: Token{
     string input = PreProcessor::readFile("resources/test.chehab");
     PreProcessor::tokenize(input);
     return 0;
}
