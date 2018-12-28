/**
 * Class with no data member
 * size is not zero because that will cause the address of 
 * all the objexts to be same which will be catastrophic in
 * case of accessing array of objects of that particular class.
 */ 

#include <iostream>
#include <stdio.h>

class A{
    public:
    void print(){};
};

class B{
    public:
    //adding a virtual function forces c++ compiler to place a 
    //VPTR for accessing the VTABLE
    virtual void print(){
        std::cout<<"Hi SIDD B"<<std::endl;
    };
};

class C : public B{
    int i;
    public:
    void func(){
        std::cout<<"Hi SIDD C "<<i<<std::endl;
    }
};

class D : public B{
    public:
    void print(){
        func();
    }
    void func(){
        std::cout<<"Hi SIDD D "<<std::endl;
    }
};

int main(){
    A a;
    B b;
    std::cout<<sizeof(A)<<" "<<sizeof(a)<<std::endl;
    std::cout<<sizeof(B)<<" "<<sizeof(b)<<std::endl;
    D c;
    B *base = &c;
    base->print();
    dynamic_cast<D*>(base)->func();
    // dynamic_cast<C*>(base)->func();  //causes segFault
    return 0;
}