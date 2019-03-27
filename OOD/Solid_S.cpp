/***
 * 
 * SOLID Principles [ S : Single Responsibility Principle ]
 * --------------------------------------------------------
 * Date : 27th March 2019
 * 
 * A class should have only one reason to change or better say one responsibility per class.
 * 
 * Pros:
 * 1. If a class has more than one responsibility, in case of any feature change, even the dependents which don't use 
 * that particular feature of the class need to be recompiled.
 * 2. Makes the module easy to understand and debug. Also reduces number of bugs. More responsibilities 
 * mean more plausible changes meaning more sources of bugs.
 * 
 ***/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

#define SINGLE_RESPONSIBILITY

class Shape {
    double mHeight, mWidth;
    string mShapeName;
    public:
        Shape ( string name, double h, double w ) : mShapeName(name), mHeight(h), mWidth(w) {}
        virtual ~Shape(){}  //destructor is virtual because shape objects will be released through base pointers.
        virtual double mGetArea() = 0;
        virtual void mDraw() = 0;
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
        void mDraw(){
            for(int y=0; y<mGetHeight(); y++){
                for(int x=0; x<mGetWidth(); x++){
                    cout<<"[]";
                }
                cout<<endl;
            }
        }
};

class Rectangle : public Shape{
    public:
        Rectangle(int h, int w):Shape("Rectangle", h, w){}
        ~Rectangle(){}
        double mGetArea(){
            return mGetHeight() * mGetWidth();
        }
        void mDraw(){
            for(int y=0; y<mGetHeight(); y++){
                for(int x=0; x<mGetWidth(); x++){
                    cout<<"[]";
                }
                cout<<endl;
            }
        }
};

class Circle : public Shape{
    public:
        Circle(int r):Shape("Circle", r, r){}
        ~Circle(){}
        double mGetArea(){
            return mGetHeight() * mGetWidth() * M_PI;
        }
        void mDraw(){
            cout<<"Mechanism to draw "<<mGetName()<<" to be implemented"<<endl;
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

class DrawShape{
    Shape *mShape;
    public:
        DrawShape(Shape *shapeObj):mShape(shapeObj){}
        void mDrawShape(){
            mShape->mDraw();
        }
};

/***
 * This class ShapeManagerNormal has two reasons to change
 * 1. If method to calculate area changes (suppose if pre/post unit conversion is to be added).
 * 2. If method to draw shapes changes (suppose if draw has to scale image before drawing it).
 * Therefore it has more than one responsability
 ***/
class ShapeManagerNormal{
    Shape *mShape;
    public:
        ShapeManagerNormal(Shape *shape): mShape(shape){}
        void mPrintArea(){
            cout<<"Area of "<<(mShape->mGetName())<<" is "<<(mShape->mGetArea())<<endl;
        }
        void mDrawShape(){
            mShape->mDraw();
        }
};

int main(){
    Shape *shape1 = new Square(4.0);
    Shape *shape2 = new Circle(1.0);
    Shape *shape3 = new Rectangle(2.0, 3.0);

#ifdef SINGLE_RESPONSIBILITY
    AreaCalculator a1(shape1);
    AreaCalculator a2(shape2);
    AreaCalculator a3(shape3);
    DrawShape d1(shape1);
    DrawShape d2(shape2);
    DrawShape d3(shape3);
    a1.mPrintArea();
    d1.mDrawShape();
    a2.mPrintArea();
    d2.mDrawShape();
    a3.mPrintArea();
    d3.mDrawShape();
#else
    ShapeManagerNormal sm1(shape1);
    ShapeManagerNormal sm2(shape2);
    ShapeManagerNormal sm3(shape3);
    sm1.mPrintArea();
    sm1.mDrawShape();
    sm2.mPrintArea();
    sm2.mDrawShape();
    sm3.mPrintArea();
    sm3.mDrawShape();
#endif

    delete shape1;
    delete shape2;
    delete shape3;
    return 0;
}