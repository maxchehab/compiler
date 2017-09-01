#include <string>
#include <iostream>
#include "preprocessor.h"

using namespace std;


int main(){
     string input = PreProcessor::readFile("resources/test.chehab");
     PreProcessor::generateKeywords(input);
     return 0;
}
