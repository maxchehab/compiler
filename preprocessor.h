#include <vector>
#include <string>
#include "token.h"

using namespace std;

class PreProcessor{
public:
     static string readFile(string);
     static vector<Token*> tokenize(string);
};
