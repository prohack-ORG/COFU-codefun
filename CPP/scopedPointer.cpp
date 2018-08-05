#include <iostream>
#include <stdio.h>
#include <boost/scoped_ptr.hpp>

int i;
class A{
    int *mptr;
    public:
        A(){
            mptr = new int(2);
            std::cout<<__FUNCTION__<<" "<<*mptr<<std::endl;
        }
        ~A(){
            std::cout<<__FUNCTION__<<" "<<*mptr<<std::endl;
            delete mptr;
        }
};
class B{
    boost::scoped_ptr<int> mptr;
    public:
        B():mptr(new int){
            i=3;
            mptr.reset(new int(i));
            std::cout<<__FUNCTION__<<" "<<*mptr<<std::endl;
        }
};

int main(){
    int *ptr = new int(1);
    std::cout<<__FUNCTION__<<" "<<*ptr<<std::endl;
    A a;
    B b;
    boost::scoped_ptr<int> ptr_(new int);
    int i=4;
    ptr_.reset(new int(i));
    std::cout<<__FUNCTION__<<" "<<*ptr_<<std::endl;
    delete ptr;
    return 0;
}
