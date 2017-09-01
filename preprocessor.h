#include <vector>
#include <string>
#include "conditional.h"

using namespace std;

class PreProcessor{
public:
     static string readFile(string);
     static vector<Keyword*> generateKeywords(string);
};
