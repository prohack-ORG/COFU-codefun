#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

int countWords(string str) 
{ 
    // breaking input into word using string stream 
    stringstream s(str); // Used for breaking words 
    string word; // to store individual words 
  
    int count = 0; 
    while (s >> word) 
        count++; 
    return count; 
} 

void tokenize(string s){
    cout<<"tokenizing using space : "<<endl;
    stringstream ss(s);
    string word;
    while(ss >> word)
        cout<<word<<endl;
}

void tokenizeUsingDelimiter(string s, char delim){
    cout<<"tokenizing using delimiter : "<<delim<<endl;
    stringstream ss(s);
    string word;
    while(getline(ss, word, delim))
        cout<<word<<endl;
}

int main(){
    //using string stream to tokenize using ' '(spaces) in the give string
    string in = "This code shows use of stringstream to tokenize a string";
    cout<<"words count : "<<countWords(in)<<endl;
    tokenize(in);
    //using string stream to tokenize using provided delimiter in the given string
    string numeric = " *1, *2, *3, *4, *5, *6";
    tokenizeUsingDelimiter(numeric, ',');
    tokenizeUsingDelimiter(numeric, '*');
    tokenizeUsingDelimiter(numeric, ' ');
    cout<<endl;
    return 0;
}
