#include <string>
#include <vector>
#include "keyword.h"

using namespace std;

class Conditional : public Keyword{
public:
     Conditional(){}
     Conditional(string);
     Conditional* clone() const{return new Conditional(*this);}
     static int findEndPoint(int, string);
};
