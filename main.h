#include <string>
using namespace std;

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void parse(string command);
void compile();
void print();

bool contains(string str1, string str2);
string fileToString(string path);
vector<string> explode(const string& str, const char& ch);
string randomString();
void addVariable(string name, string value);
void addOperator(string parent, vector<string> children, string type);
int findVariableIndex(string literal);
string erase(string str, char character);

#endif
