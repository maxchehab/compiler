#include <string>

using namespace std;

enum Type { conditional, literal, command, null };

class Keyword{
public:
     Keyword(){}
     static Type identify(string);
     virtual Keyword* clone() const = 0;
};
