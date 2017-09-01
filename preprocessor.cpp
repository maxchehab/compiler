#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "preprocessor.h"

using namespace std;

const string keywords[] = {"equals", "print", "(", ")", ","};

vector<char> PreProcessor::readFile(string path){
     vector<char> input;
     ifstream file (path);
     if(file.is_open()){
          while(file.good()){
               char temp = file.get();
               if(!isspace(temp) && temp != -1){
                    input.push_back(temp);
               }
          }
          file.close();
     }else{
          cout << "File can not be opened." << endl;
     }

     return input;
}

vector<Keyword*> PreProcessor::generateKeywords(vector<char> input){
     vector<Keyword*> output;
     string temp;
     for(int i = 0; i < input.size(); i++){
          temp += input[i];
          Type tempType = Keyword::identify(temp);
          switch(tempType){
               case Type::conditional : int endpoint = Conditional::findEndPoint(i + 1, string(input.begin(),input.end()));
                                        Conditional *conditional = new Conditional("hello!");
                                        output.push_back(conditional->clone());
                                        break;
          }

          if(tempType != Type::null){
               temp = "";
          }
     }

     return output;
}
