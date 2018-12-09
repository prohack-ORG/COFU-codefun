/**
 *	SHALLOW vs DEEP copy C++
 *	09th Dec 2018
 */
#include <iostream>
#include <stdio.h>

using namespace std;

class A{
    int val;
    int *ptr;
    public:
        A(int val){
            this->val = val;
            this->ptr = &val;
        }
        void modifyVal(){   (*ptr)++;     }
        void print(){
            std::cout<<&ptr<<" points to "<<ptr<<" which holds value :"<<*ptr<<" but shall point to "<<val<<std::endl;
        }
};

class B{
    int val;
    int *ptr;
    public:
    	B(): val(0), ptr(&val){}
        B(int val){
            this->val = val;
            ptr = &val;
        }
        B(const B &temp){
            this->val = temp.val;
            this->ptr = &(this->val);
            //std::cout<<"copy constructor overload"<<std::endl;
        }
        void modifyVal(){   (*ptr)++;     }
        void operator=(const B &temp){
        	//std::cout<<"assignment operator overload"<<std::endl;
            this->val = temp.val;
            this->ptr = &(this->val);
        }
        void print(){
            std::cout<<&ptr<<" points to "<<ptr<<" which holds value :"<<*ptr<<" but shall point to "<<val<<std::endl;
        }
};

int main(){
    A a1(100), a2(200);
    a2 = a1;
    a2.modifyVal();
    a1.print();
    a2.print();

    B b1(300), b2(b1), b3(400);
    b2.modifyVal();
    b1.print();
    b2.print();
    b3 = b2;
    b3.modifyVal();
    b3.print();
    
    return 0;
}
