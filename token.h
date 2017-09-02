#include <string>
#include <vector>
#include "variable.h"

using namespace std;

enum Type { statement, literal, oper, null };

enum CommandType { assign, print };

class Token{
public:
     static Type identify(string);
     static vector<Variable> variables;
     static int getVariableIndex(string);

     Token(string, Type&);
     string value;
     Type tokenType;
     CommandType commandType;
     void initializeAssignment(string);
     void initializePrint(string);

};
