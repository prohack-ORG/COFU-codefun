/***
 * 
 * SOLID Principles [ L : Liskov's Substitution Principle ]
 * --------------------------------------------------------
 * Date : 14th April 2019
 *
 * If a function uses the pointer or reference to base class, it must be able to use objects of the derived classes without nowing it. 
 * If a function uses base class pointer then it should not worry about what it points to.
 * In other words, any derived class object shall be replacable with the base class object.
 * 
 * Derived classes must extend the base class but without changing their behaviour.
 * 
 ***/

#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;;

#define LISKOVS_SUBSTITUTION

#ifndef LISKOVS_SUBSTITUTION

class Rectangle{

    protected:

        int mWidth, mHeight;
    public:

        virtual void mSetWidth(int w){
            mWidth = w;
        }
        virtual void mSetHeight(int h){
            mHeight = h;
        }
        float mGetArea(){
            return mWidth * mHeight;
        }
};

class Square : public Rectangle{

    public:

        void mSetHeight(int h){
            mHeight = h;
            mWidth = h;
        }
        void mSetWidth(int w){
            mWidth = w;
            mHeight = w;
        }
};
#else

class Quadrilateral {
    protected:
        int mHeight, mWidth;
    public:
        virtual void mSetWidth(int ){
            mWidth = 0; 
        };
        virtual void mSetHeight(int ){
            mHeight = 0;
        }
        float mGetArea(){
            return mWidth * mHeight;
        }
};

class Rectangle: public Quadrilateral{

    public:
        void mSetWidth(int w){
            mWidth = w;
        }
        void mSetHeight(int h){
            mHeight = h;
        }
};

class Square : public Quadrilateral{

    public:
        void mSetHeight(int h){
            mHeight = h;
            mWidth = h;
        }
        void mSetWidth(int w){
            mWidth = w;
            mHeight = w;
        }
};

#endif

int main(){

#ifndef LISKOVS_SUBSTITUTION

    Rectangle *rect1 = new Rectangle;   //The derived object might come from some factory or some library of which user has no prior information.
    rect1->mSetWidth(12);
    rect1->mSetHeight(42);
    int area = rect1->mGetArea();
    cout << "Area of rectangle 1 : " << area << endl; 

    Rectangle *rect2 = new Square;
    rect2->mSetWidth(12);
    rect2->mSetHeight(42);
    area = rect2->mGetArea();   //This would return sonething unexpected to the user who has no info about the derived classes of Rectangle
    //In this case user will be surprised to see the area of rectangle to be a different than expected value since s/he doesn't know that derived class is a square not a rectangle.
    cout << "Area of rectangle 2 : " << area << endl;

    delete rect1;
    delete rect2;
#else
    Quadrilateral *q1 = new Rectangle;  //The derived object might come from some factory or some library of which the user has no prior information.
    Quadrilateral *q2 = new Square;
    q1->mSetHeight(12);
    q1->mSetWidth(42);
    int area = q1->mGetArea();
    cout << "Area of quadrilateral 1 : " << area << endl;
    
    q2->mSetHeight(12);
    q2->mSetWidth(42);
    area = q2->mGetArea();
    //But in this case the output won't surprise the user as s/he is expecting area of quadrilateral which can be rectangle as well as square.
    cout << "Area of quadrilateral 2 : " << area << endl;
#endif
    return 0;
}
