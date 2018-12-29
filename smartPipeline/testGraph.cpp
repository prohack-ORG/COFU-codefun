#include "Graph.h"

class tempNode : public Node{
    string nameTag;
    public:
        tempNode(string nameTag):Node(this, nameTag),nameTag(nameTag){
            PRINTLOG((nameTag+" constructor").c_str());
        }
        void kernel(){
            for(int i=0; i<1e6;)
                i++;
        }
        ~tempNode(){
            PRINTLOG((nameTag+" destructor").c_str());
        }
};

int main(){
    Graph *graph = new Graph("sampleGraph");
    Node *nodeA = new tempNode("tempNodeA");
    Node *nodeB = new tempNode("tempNodeB");
    graph->addNode(nodeA);
    graph->addNode(nodeB);
    graph->run();
    graph->printDetails();
    delete graph;
    cout<<endl;
    return 0;
}