/*
    Author  : Siddheshwar P Sharma
    Date    : 16th Feb 2019
    Purpose : Study of behaviour of dynamic_cast<> and std::is_base_of<> (c++11 feature).
    Status  : dynamic cast requires atleast one of the classes to have atleast one virtual method(failing which results in compile time error. Whereas is_base_of doesn't impose any such restrictions.
*/

#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

class A{
    public:
        virtual void mPrint(){
            cout<<"class A function"<<endl;
        }
};

class B: public A{
    public:
        void mPrint(){
            cout<<"class B function"<<endl;
        }
};

class C{
    public:
        void mPrint(){
            cout<<"class C function"<<endl;
        }
};

class D{
    public:
        void mPrint(){
            cout<<"class C function"<<endl;
        }
};

//using is_base_of
//no criteria like dynamic_cast needed.
template <typename A, typename B>
void checkBase1(A *a, B *b){
    cout<<typeid(A).name()<<" is ";
    cout<<(std::is_base_of<A, B>::value ? "parent ":"not a parent ")<<endl;
    cout<<"of "<<typeid(B).name()<<endl;
}

//using dynamic_cast
//Atleast one class should have a virtual method.
template <typename A, typename B>
void checkBase2(A *a, B *b){
    cout<<typeid(A).name()<<" is ";
    cout<<((b = dynamic_cast<B *>(a)) ? "parent ":"not a parent ")<<endl;
    cout<<"of "<<typeid(B).name()<<endl;
}

int main(){
    A *aPtr = nullptr;
    B *objB = new B;
    aPtr = objB;
    B *bPtr = objB;
    C *cPtr = new C;
    D *dPtr = new D;
    checkBase1(aPtr, objB);
    checkBase1(aPtr, bPtr);
    checkBase1(aPtr, cPtr);
    checkBase1(dPtr, cPtr);
    checkBase2(aPtr, objB);
    checkBase2(aPtr, bPtr);
    checkBase2(aPtr, cPtr);
    checkBase2(cPtr, cPtr); //OK, as both are same class, dynamic cast doesn't report any compilation error.
    //checkBase2(dPtr, cPtr); //causes compile time error : D is not polymorphic
    return 0;
}
