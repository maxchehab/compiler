#include <vector>
#include <string>
#include "conditional.h"

using namespace std;

class PreProcessor{
public:
     static vector<char> readFile(string);
     static vector<Keyword*> generateKeywords(vector<char>);
};
