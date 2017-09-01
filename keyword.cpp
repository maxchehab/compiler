#include "keyword.h"
#include <string>

using namespace std;

Type Keyword::identify(string input){
     if(input == "equals"){
          return Type::conditional;
     }

     return Type::null;
}
