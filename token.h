#include <string>

using namespace std;

enum Type { statement, literal, oper, null };

class Token{
public:
     static Type identify(string);
};
