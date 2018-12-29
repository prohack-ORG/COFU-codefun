#include "Graph.h"

void Node::run(){
    PRINTLOG("base run");
    timeval startT, endT;
    gettimeofday(&startT, NULL);
    kernel();
    gettimeofday(&endT, NULL);
    timeTaken = (endT.tv_sec - startT.tv_sec)*1e3 + (endT.tv_usec - startT.tv_usec)/1e3;
}

void Node::printDetails(){
    cout<<"KernelName : "<<getNodeName()<<endl;
}

void Node::printPerformance(){
    printf("%20s : %30Lf ms\n",getNodeName().c_str(), timeTaken);
}

void Graph::addNode(Node *node){
    vertices.push_back(node);
}

void Graph::run(){
    for(auto &it : vertices){
        cout<<(("Executing "+it->getNodeName()).c_str())<<endl;
        it->run();
    }
}
void Graph::printDetails(){
    cout<<endl;
    for(auto &it : vertices){
        cout<<"--> ";
        cout<<(it->getNodeName());
    }
    cout<<endl;
#if ENABLE_PROFILING
    cout<<endl<<"Performance : "<<endl;
    for(auto &it : vertices){
        it->printPerformance();
    }
    cout<<endl;
#endif
}