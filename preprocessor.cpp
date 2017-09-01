#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "preprocessor.h"

using namespace std;

const string keywords[] = {"equals", "print", "(", ")", ","};

string PreProcessor::readFile(string path){
     string input;
     ifstream file (path);
     if(file.is_open()){
          while(file.good()){
               char temp = file.get();
               if(!isspace(temp) && temp != -1){
                    input += temp;
               }
          }
          file.close();
     }else{
          cout << "File can not be opened." << endl;
     }

     return input;
}

vector<Token> PreProcessor::tokenize(string input){
     vector<Token> output;
     int startPos = 0;

     for(int i = 0; i <= input.length() - startPos; i++) {
          string temp = input.substr(startPos, i);
          //cout << temp << endl;
          Type tempType = Token::identify(temp);
          if(tempType == Type::statement){
               for(int j = 0, finish = 0; j < input.length() && finish == 0; j++) {
                    if(input[startPos + j] == ';'){
                         output.push_back(new Statement(input.substr(startPos, j)))
                         cout << "new statement : " << input.substr(startPos, j + 1) << endl;
                         startPos += j + 1;
                         i = 1;
                         finish = 1;
                    }
               }
          }

     }

     return output;
}
