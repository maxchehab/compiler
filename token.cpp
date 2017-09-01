#include <string>
#include "token.h"

using namespace std;

Type Token::identify(string input){
     if(input == "var" || input == "print"){
          return Type::statement;
     }

     return Type::null;
}
