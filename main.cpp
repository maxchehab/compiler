#include <vector>
#include <iostream>
#include "preprocessor.h"

using namespace std;


int main(){
     vector<char> input = PreProcessor::readFile("resources/test.chehab");
     PreProcessor::generateKeywords(input);
     for(int i = 0; i < input.size(); i++){
          cout << input[i];
     }
     cout << endl;
     return 0;
}
