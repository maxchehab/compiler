#include "conditional.h"
#include <string>
#include <iostream>

using namespace std;


Conditional::Conditional(string input){

}

int Conditional::findEndPoint(int current, string input){
     int endpos = input.length();
     string search = "then";
     for(int i = 0; i < input.length() - search.length(); i++){
          if(input.substr(i,search.length()) == search){
               cout << input.substr(i, search.length()) << endl;
          }
     }

}
