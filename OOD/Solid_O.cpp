/***
 * 
 * SOLID Principles [ O : Open Closed Principle ]
 * --------------------------------------------------------
 * Date : 5th April 2019
 * 
 * A class should be closed for modification but open for extension.
 * 
 * 
 ***/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

#define OPEN_CLOSED

#ifdef OPEN_CLOSED
class Shape {
    double mHeight, mWidth;
    string mShapeName;
    public:
        Shape ( string name, double h, double w ) : mShapeName(name), mHeight(h), mWidth(w) {}
        virtual ~Shape(){}  //destructor is virtual because shape objects will be released through base pointers.
        virtual double mGetArea() = 0;
        double mGetHeight() {   return mHeight;         }
        double mGetWidth()  {   return mWidth;          }
        string mGetName()   {   return mShapeName;      }
};

class Square : public Shape{
    public:
        Square(int x):Shape("Square", x, x){}
        ~Square(){}
        double mGetArea(){
            return mGetHeight() * mGetWidth();
        }
};

class Rectangle : public Shape{
    public:
        Rectangle(int h, int w):Shape("Rectangle", h, w){}
        ~Rectangle(){}
        double mGetArea(){
            return mGetHeight() * mGetWidth();
        }
};

class Circle : public Shape{
    public:
        Circle(int r):Shape("Circle", r, r){}
        ~Circle(){}
        double mGetArea(){
            return mGetHeight() * mGetWidth() * M_PI;
        }
};

class AreaCalculator{
    Shape *mShape;
    public:
        AreaCalculator(Shape *shapeObj):mShape(shapeObj){}
        void mPrintArea(){
            cout<<"Area of "<<(mShape->mGetName())<<" is "<<(mShape->mGetArea())<<endl;
        }
};

#else

class Shape {
    double mHeight, mWidth;
    string mShapeName;
    public:
        Shape ( string name, double h, double w ) : mShapeName(name), mHeight(h), mWidth(w) {}
        virtual ~Shape(){}  //destructor is virtual because shape objects will be released through base pointers.
        double mGetHeight() {   return mHeight;         }
        double mGetWidth()  {   return mWidth;          }
        string mGetName()   {   return mShapeName;      }
};

class Square : public Shape{
    public:
        Square(int x):Shape("Square", x, x){}
        ~Square(){}
};

class Rectangle : public Shape{
    public:
        Rectangle(int h, int w):Shape("Rectangle", h, w){}
        ~Rectangle(){}
};

class Circle : public Shape{
    public:
        Circle(int r):Shape("Circle", r, r){}
        ~Circle(){}
};

/**
 * This design is a violation of Open/Closed Principle.
 * This class will keep on being modified for the addition of every new type of shape. 
 * Which makes the design difficult to modify in case someone new wants to modify it.
 * It will consume unnecessary time and effort of user to understand the functionality as often it will not be
 * so straignt forward as the current method.
 * Further with each addition, retesting will be needed for all the cases.
 **/
class AreaCalculator{
    Shape *mShape;
    public:
        AreaCalculator(Shape *shapeObj):mShape(shapeObj){}
        void mPrintArea(){
            cout<<"Area of "<<(mShape->mGetName())<<" is ";
            if((mShape->mGetName()) == "Rectangle"){
                cout<<mShape->mGetHeight() * mShape->mGetWidth()<<endl;
            }
            else if((mShape->mGetName()) == "Square"){
                cout<<mShape->mGetHeight() * mShape->mGetWidth()<<endl;
            }
            else if((mShape->mGetName()) == "Circle"){
                cout<<mShape->mGetHeight() * mShape->mGetWidth() * M_PI<<endl;
            }
            else
                cout<<"Shape is not supported yet"<<endl;
        }
};

#endif

int main(){
    Shape *shape1 = new Square(4.0);
    Shape *shape2 = new Circle(1.0);
    Shape *shape3 = new Rectangle(2.0, 3.0);

    AreaCalculator a1(shape1);
    AreaCalculator a2(shape2);
    AreaCalculator a3(shape3);
    a1.mPrintArea();
    a2.mPrintArea();
    a3.mPrintArea();

    delete shape1;
    delete shape2;
    delete shape3;
    return 0;
}