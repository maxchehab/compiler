#include <string>
#include <vector>
#include "token.h"
#include <iostream>

using namespace std;

vector<Variable> Token::variables;

Type Token::identify(string input){
     if(input == "var" || input == "print"){
          return Type::statement;
     }

     return Type::null;
}

Token::Token(string input, Type& type){
  value = input;
  tokenType = type;
  if(type == Type::statement){
    string var = input.substr(0,3);
    string print = input.substr(0,5);
    if(var == "var"){
      commandType = CommandType::assign;
      cout << input << " input is assignment" << endl;
      initializeAssignment(input);
    }else if(print == "print"){
      commandType = CommandType::print;
      cout << input << " input is print" << endl;
    }
  }
}

void Token::initializeAssignment(string input){
  struct Variable variable;
  for(int i = 0; i < input.length(); i++){
      if(input[i + 3] == '='){
        variable.name = input.substr(3, i);
        cout << variable.name << endl;
      }

  }
}

void Token::initializePrint(string input){

}

int Token::getVariableIndex(string name){
  for(int i = 0; i < variables.size(); i++){
    if(variables[i].name == name){
      return i;
    }
  }

  return -1;
}
