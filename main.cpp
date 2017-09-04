#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "main.h"
#include "variable.h"
#include "operator.h"

using namespace std;

vector<Variable> variables;
vector<Operator> operators;
vector<string> prints;

vector<string> bssSection;
vector<string> textSection;

int main(){
     string input = fileToString("resources/test.chehab");
     vector<string> commands = explode(input, ';');
     for(string command : commands){
          parse(command);
     }

     compile();
     print();

     /*cout << "Variables:" << endl;
     for(Variable variable : variables){
          cout << variable.literal << " " << variable.name << " " << variable.value << endl;
     }

     cout << endl << "Operators:" << endl;
     for(Operator oper : operators){
          cout << oper.parent << endl;
     }

     cout << endl << "Prints:" << endl;
     for(string print : prints){
          cout << print << endl;
     }

     cout << endl << "bssSection:" << endl;
     for(string bss : bssSection){
          cout << bss << endl;
     }

     cout << endl << "textSection:" << endl;
     for(string text : textSection){
          cout << text << endl;
     }*/

     return 0;
}

void print(){
     char filename[ ] = "output.nasm";
     fstream file;
     file.open(filename, fstream::in | fstream::out | fstream::trunc);

     if (!file){
         cout << "Cannot open file, file does not exist. Creating new file..";

         file.open(filename,  fstream::in | fstream::out | fstream::trunc);
         file <<"\n";
         file.close();
      }else{
           file << "section .bss" << endl;
           file << "digitSpace resb 100" << endl;
           file << "digitSpacePos resb 8" << endl << endl;

           for(string bss : bssSection){
                file << bss << endl;
           }

           file << "section .text" << endl;
           file << "global _start" << endl;
           file << "_start:" << endl << endl;

           for(string text : textSection){
                file << text << endl;
           }

           file << endl << endl << "\t\r\nmov rax, 60\r\n     mov rdi, 0\r\n     syscall\r\n\r\n\r\n_printRAX:\r\n     mov rcx, digitSpace\r\n     mov rbx, 10\r\n     mov [rcx], rbx\r\n     inc rcx\r\n     mov [digitSpacePos], rcx\r\n\r\n_printRAXLoop:\r\n     mov rdx, 0\r\n     mov rbx, 10\r\n     div rbx\r\n     push rax\r\n     add rdx, 48\r\n\r\n     mov rcx, [digitSpacePos]\r\n     mov [rcx], dl\r\n     inc rcx\r\n     mov [digitSpacePos], rcx\r\n\r\n     pop rax\r\n     cmp rax, 0\r\n     jne _printRAXLoop\r\n\r\n_printRAXLoop2:\r\n     mov rcx, [digitSpacePos]\r\n\r\n     mov rax, 1\r\n     mov rdi, 1\r\n     mov rsi, rcx\r\n     mov rdx, 1\r\n     syscall\r\n\r\n     mov rcx, [digitSpacePos]\r\n     dec rcx\r\n     mov [digitSpacePos], rcx\r\n\r\n     cmp rcx, digitSpace\r\n     jge _printRAXLoop2\r\n\r\n     ret";

           file.close();
           cout<<"\n";

    }

}

void compile(){
     for(Variable variable : variables){
          bssSection.push_back(variable.name + " resb 32");

          if(variable.value != ""){
               textSection.push_back("mov rax, " + variable.value);
               textSection.push_back("mov [" + variable.name + "], rax");
          }
     }

     for(Operator oper : operators){
          textSection.push_back("mov rax, [" + oper.parent + "]");
          for(string child : oper.children){
               textSection.push_back("add rax, [" + variables[findVariableIndex(child)].name + "]");
          }

          textSection.push_back("mov [" + oper.parent + "], rax");
     }

     for(string print : prints){
          int printVarIndex = findVariableIndex(print);
          if(printVarIndex != -1){
               textSection.push_back("mov rax, [" + variables[printVarIndex].name + "]");
               textSection.push_back("call _printRAX");
          }else {
               //error. variable unknown.
          }
     }
}

void parse(string command){
     if(command.substr(0,3) == "var"){
          vector<string> keys = explode(command.substr(3),'=');
          string name = keys[0];
          string value = keys[1];
          if(!contains(value, "+")){
               addVariable(name, value);
          }else{
               string parent = keys[0];
               keys = explode(value,'+');
               vector<string> children;
               for(int i = 0; i < keys.size(); i++){
                    cout << keys[i] << endl;
                    name = randomString();
                    value = keys[i];
                    if(findVariableIndex(value) != -1){
                         name = value;
                    }else{
                         addVariable(name, value);
                    }
                    children.push_back(name);
               }
               addVariable(parent, "");
               addOperator(parent, children, "sum");
          }
     }else if(command.substr(0,6) == "print("){
          string temp = command.substr(6);
          temp = erase(erase(temp,'('), ')');
          vector<string> keys = explode(temp, ',');
          for(string key : keys){
               prints.push_back(key);
          }
     }
}

string erase(string str, char character){
     str.erase(std::remove(str.begin(), str.end(), character), str.end());
     return str;
}

void addVariable(string name, string value){
     variables.push_back(Variable());
     variables.back().name = randomString();
     variables.back().value = value;
     variables.back().literal = name;
}

void addOperator(string parent, vector<string> children, string type){
     operators.push_back(Operator());
     operators.back().parent = variables[findVariableIndex(parent)].name;
     operators.back().children = children;
     operators.back().type = type;
}

bool contains(string str1, string str2){
     if(str1.find(str2) != string::npos){
          return true;
     }
     return false;
}

string randomString(){
     static const string charList = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

     srand(rand() % 100);
     string alphanumeric = "";

     for(int i = 0; i < 8; i++) {
          alphanumeric += charList [rand() % charList.size()];
     }
     return alphanumeric;
}

int findVariableIndex(string literal){
     for(int i = 0; i < variables.size(); i++){
          if(variables[i].literal == literal){
               return i;
          }
     }
     return -1;
}

string fileToString(string path){
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

vector<string> explode(const string& str, const char& ch) {
    string next;
    vector<string> result;

    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        if (*it == ch) {
            if (!next.empty()) {
                result.push_back(next);
                next.clear();
            }
        } else {
            next += *it;
        }
    }
    if (!next.empty()){
         result.push_back(next);
    }
    return result;
}
