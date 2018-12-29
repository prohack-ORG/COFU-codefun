#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <string>
#include <sys/time.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;

#if ENABLE_DEBUG
//#define PRINTLOG(s) cout<<__LINE__<<" "<<__FILE__<<" "<<s<<endl;
#define PRINTLOG(s) printf("%-4d %-50s:\t%s\n",__LINE__,__FILE__,s);
#else
#define PRINTLOG(s)
#endif

class Graph;

class Node{
    Node *node;
    string nodeName;
    long double timeTaken;
    public:
        Node(Node *tempNode, string tag):node(tempNode),nodeName(tag),timeTaken(0){
            PRINTLOG("base constructor");
        }
        virtual ~Node(){
            PRINTLOG("base destructor");
        }
        void printDetails();
        void printPerformance();
        virtual void kernel() = 0;
        void run();
        string getNodeName(){
            return nodeName;
        }
};

class Graph{
    vector<Node *> vertices;
    string graphName;
    public:
        Graph(string tag):graphName(tag){
            PRINTLOG("graph constructor");
        }
        ~Graph(){
            for(auto &it : vertices)
                delete it;
            PRINTLOG("graph destructor");
        }
        void addNode(Node *node);
        void run();
        void printDetails();
};

#endif //~GRAPH_H