/**
 * 
 * Problem  : Attribute Parser
 * Link     : https://www.hackerrank.com/challenges/attribute-parser
 * Date     : 02 Sept 2018
 * Status   : All test Cases Passed
 * inputFile: input_attributeParser.txt
 * 
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


// #define cout if(0) std::cout

class Tag{
  vector<Tag *> mNextTag;
  string mTagName;
  vector< pair<string , string > > mAttrib;
  Tag *mParent;
  public:
    Tag(string tagName):mTagName(tagName), mParent(NULL){}
    // Tag(string tagName, string attrib_key, string attrib_val):mTagName(tagName){}
    void mAddParent(Tag *pTag){  mParent = pTag; }
    void mAddAttrib(pair<string, string> p){  mAttrib.push_back(p);  }
    Tag *mGetParent(){  return mParent; }
    string getName(){   return mTagName; }
    void mInsertTag(Tag *newTag){
        
        mNextTag.push_back(newTag);
        // cout<<"mInserting "<<newTag->getName()<<endl;
    }
    void printInfo();
    string key2Val(string key);
    Tag *visitTag(string tagName){
        for(auto &t : mNextTag){
            if(tagName == t->getName()){
                return t;
            }
        }
        return NULL;
    }
};

string Tag::key2Val(string key){
    for(auto &i : mAttrib){
        if(i.first == key){
            return i.second;
        }
    }
    return "Not Found!";
}

void Tag :: printInfo(){

    cout<<"printing attributes for tag : "<<mTagName<<" and has parent : "<<mParent<<endl;
    for(auto it : mAttrib){
        cout<<it.first<<" "<<it.second<<endl;
    }
    
    //cout<<mTagName<<endl;
    for(auto *it : mNextTag){
        cout<<(*it).mTagName<<endl;
        (*it).printInfo();
    }
    
    cout<<endl;
}

void printDetails(Tag *list[]){
    cout<<"printing taglist details : "<<endl;
    for(int i=0; i<20; i++){
        //cout<<"Tag "<<i<<endl;
        if(list[i] != NULL)
            list[i]->printInfo();
    }
}

void processLine(string line){
    cout<<line<<endl;
    
}


Tag *tagList[20] = {NULL,};

int main_debug() {
    int N, Q;

    freopen("input_attributeParser.txt", "r", stdin);
    cin>>N;
    cin>>Q;
    
    int index = 0;
    Tag *head = tagList[index];
    pair<string, string> temp_attrib;

    cout<<"Registering data now."<<endl;
    while(N>0){
        // cout<<N<<endl;
        string input_line;
        //This reads till it encounters a newLine or SPACE
        cin>>input_line;
        //cout<<input_line<<endl;
        
        //case </tag>, move to parent tag as current tag is over
        if(input_line.at(1) == '/'){
            N--;
            cout<<input_line<<endl;
            cout<<"current head at : "<<head->getName()<<endl;
            if (head->mGetParent() == NULL){
               cout<<"head is NULL now\n";
               head = tagList[++index];
               cout<<"head pointing at taglist "<<index<<", head address : "<<head<<", taglist address : "<<tagList[index]<<endl;
            }
            //if head to root, point it to other root tag
            else{
               head = head->mGetParent();
               cout<<"head at : "<<head->getName()<<" now\n";
            }
            cout<<"move out of tag "<<input_line<<endl;

            // cout<<"move out of tag "<<input_line.substr(2, input_line.length()-3)<<endl;

            // head->printInfo();
        }
        //case <tag .... >, add new taag inside current tag
        else if(input_line.at(0) == '<'){
            cout<<"input_line len : "<<input_line.length()<<endl;
            N--;
            if(input_line.find(' ') != string::npos)
                cout<<"inserting new tag "<<input_line.substr(1, input_line.length()-1)<<endl;
            else
                cout<<"inserting new tag "<<input_line.substr(1, input_line.length())<<endl;
            //if 1st tag
            if(head == NULL){
                if(input_line.find(">") != string::npos)
                    tagList[index] = new Tag(input_line.substr(1, input_line.length()-2));
                else
                    tagList[index] = new Tag(input_line.substr(1, input_line.length()));
                head = tagList[index];
                cout<<"new head "<<head->getName()<<", head address : "<<head<<", taglist address : "<<tagList[index]<<" new index : "<<index<<endl;
                // cout<<"new head"<<endl;
            }
            
            //insert a tag inside current tag, added tag is the new tag
            else{
                // cout<<"old head"<<endl;
                Tag *temp = new Tag(input_line.substr(1, input_line.length()-1));
                temp->mAddParent(head);
                head->mInsertTag(temp);
                head = temp;
            }
        }
        else{
            if(input_line.at(0) != '\"'){
                string attrib_val;
                //skip one input which is "="
                cin>>attrib_val;
                
                cin>>attrib_val;
                //cout<<attrib_val<<endl;
                int pos = (attrib_val.at(attrib_val.length()-1) == '>') ? attrib_val.length()-3 : attrib_val.length()-2;
                //cout<<"pos "<< pos<<endl;
                attrib_val = attrib_val.substr(1, pos);
                //cout<<"attrib < "<< input_line << ", "<<attrib_val<< " >"<<endl;
                head->mAddAttrib(make_pair(input_line, attrib_val));
                head->printInfo();
            }
        }
    }

    cout<<"print details "<<endl;
    for(int ii=0; ii<=index; ii++){
        head = tagList[ii];
        cout<<"head address : "<<tagList[0]<<endl;
        if(head == NULL){
            cout<<"head is NULL\n";
        }
        else{
            head->printInfo();
        }
    }
    string querry;
    cout<<"Processing Querries now."<<endl;
    for(int i=0; i<Q; i++){
        //Querry processing
        cin>>querry;
        Tag *head = tagList[0];
        cout<<querry<<endl;
        int pos = querry.find("~");
        string temp = querry.substr(pos+1, querry.length());
        cout<<"search key  "<<temp<<endl;

        querry.erase(pos, querry.length());
        cout<<"querry now : "<<querry<<endl;
        string tagName(querry);
        pos = querry.find(".");

        if(pos != string::npos){
            tagName = querry.substr(0, pos);
            cout<<"find tag "<<tagName<<endl;
            querry.erase(0, pos+1);
        }
        else{
            querry = "";
        }

        cout<<"tagname = "<<tagName<<" querry now : "<<querry<<endl;
        cout<<"index : "<<index<<endl;
        for(int i=0; i<=index; i++){
            cout<<"at index : "<<i<<endl;
            if(tagList[i] == NULL){
                cout<<index << " NULL"<<endl;
                head = NULL;
                break;
            }
            else if(tagList[i]->getName() == tagName){
                head = tagList[i];
                cout<<"found tag"<<endl;
                break;
            }
            else{
                cout<<"left "<<tagList[i]->getName()<<endl;
            }
        }
        if(head == NULL){
            //cout<<"Not Found!\n";
            printf("Not Found!\n");
            continue;
        }

        while(!tagName.empty() && !querry.empty()){
            cout<<"querry now : "<<querry<<endl;
            pos = querry.find(".");
            if(pos == string::npos){
                pos = querry.length();
            }
            tagName = querry.substr(0, pos);
            cout<<"now find tag "<<tagName<<" in : tag "<<head->getName()<<endl;
            head = head->visitTag(tagName);
            
            if(head == NULL){
                printf("Not Found!\n");
                break;
            }
            querry.erase(0, pos+1);
        }
        if(head != NULL){
            cout<<endl;
            printf("%s\n", head->key2Val(temp).c_str());
            //cout<<(head->key2Val(temp))<<endl;
            cout<<endl;
        }
    }
    cout<<endl;
    return 0;
}

int main_release() {
    int N, Q;

    freopen("input_attributeParser.txt", "r", stdin);
    cin>>N;
    cin>>Q;
    
    int index = 0;
    Tag *head = tagList[index];
    pair<string, string> temp_attrib;

    // cout<<"Registering data now."<<endl;
    while(N>0){
        string input_line;
        //This reads till it encounters a newLine or SPACE
        cin>>input_line;

        //case </tag>, move to parent tag as current tag is over
        if(input_line.at(1) == '/'){
            N--;
            if (head->mGetParent() == NULL){
               head = tagList[++index];
            }
            //if head to root, point it to other root tag
            else{
               head = head->mGetParent();
            }
            // head->printInfo();
        }
        //case <tag .... >, add new taag inside current tag
        else if(input_line.at(0) == '<'){
            N--;
            // if(input_line.find(' ') != string::npos)
            //     cout<<"inserting new tag "<<input_line.substr(1, input_line.length()-1)<<endl;
            // else
            //     cout<<"inserting new tag "<<input_line.substr(1, input_line.length())<<endl;
            //if 1st tag
            if(head == NULL){
                if(input_line.find(">") != string::npos)
                    tagList[index] = new Tag(input_line.substr(1, input_line.length()-2));
                else
                    tagList[index] = new Tag(input_line.substr(1, input_line.length()));
                head = tagList[index];
            }
            
            //insert a tag inside current tag, added tag is the new tag
            else{
                Tag *temp = new Tag(input_line.substr(1, input_line.length()-1));
                temp->mAddParent(head);
                head->mInsertTag(temp);
                head = temp;
            }
        }
        else{
            if(input_line.at(0) != '\"'){
                string attrib_val;
                //skip one input which is "="
                cin>>attrib_val;
                cin>>attrib_val;
                int pos = (attrib_val.at(attrib_val.length()-1) == '>') ? attrib_val.length()-3 : attrib_val.length()-2;
                attrib_val = attrib_val.substr(1, pos);
                head->mAddAttrib(make_pair(input_line, attrib_val));
                // head->printInfo();
            }
        }
    }
    /*
    cout<<"print details "<<endl;
    for(int ii=0; ii<=index; ii++){
        head = tagList[ii];
        if(head == NULL){
            cout<<"head is NULL\n";
        }
        else{
            head->printInfo();
        }
    }
    */
    string querry;
    // cout<<"Processing Querries now."<<endl;
    for(int i=0; i<Q; i++){
        //Querry processing
        cin>>querry;
        Tag *head = tagList[0];
        int pos = querry.find("~");
        string temp = querry.substr(pos+1, querry.length());

        querry.erase(pos, querry.length());
        string tagName(querry);
        pos = querry.find(".");

        if(pos != string::npos){
            tagName = querry.substr(0, pos);
            querry.erase(0, pos+1);
        }
        else{
            querry = "";
        }
        
        for(int i=0; i<=index; i++){
            if(tagList[i] == NULL){
                head = NULL;
                break;
            }
            else if(tagList[i]->getName() == tagName){
                head = tagList[i];
                break;
            }
        }
        if(head == NULL){
            //cout<<"Not Found!\n";
            printf("Not Found!\n");
            continue;
        }

        while(!tagName.empty() && !querry.empty()){

            pos = querry.find(".");
            if(pos == string::npos){
                pos = querry.length();
            }
            tagName = querry.substr(0, pos);
            head = head->visitTag(tagName);
            
            if(head == NULL){
                printf("Not Found!\n");
                break;
            }
            querry.erase(0, pos+1);
        }
        if(head != NULL){
            printf("%s\n", head->key2Val(temp).c_str());
            //cout<<(head->key2Val(temp))<<endl;
        }
    }
    cout<<endl;
    return 0;
}

int main(){
    main_release();
    // main_debug();
    return 0;
}