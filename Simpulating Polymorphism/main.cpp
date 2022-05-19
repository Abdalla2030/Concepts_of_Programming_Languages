///////////////////////////////////////////
//    Abdalla Fadl shehata  - 20190305  //
/////////////////////////////////////////
#include <iostream>
using namespace std;
////////////////////////////////////////
const double PI = 3.14;
///////////////////////////////////////
// Base Class ( Shape ) - interface
struct ShapeVtable;
struct Shape
{
    ShapeVtable* vtable;
};

struct ShapeVtable
{
    double (*GetArea)(Shape*);
     void (*PrintInfo)(Shape*);
};

double GetArea(Shape* shape)
{
    return shape->vtable->GetArea(shape);
}

void PrintInfo(Shape* shape)
{
    shape->vtable->PrintInfo(shape);
}
///////////////////////////////////////
// Derived Class ( Circle ) - Concrete
struct Circle
{
    Shape parent;
    double radius;
};

double GetAreaCircle(Circle* circle)
{
    return  PI* circle->radius * circle->radius;
}

void PrintInfoCircle(Circle* circle)
{
    cout<<"Radius of Circle = "<<circle->radius <<endl;
    cout<<endl;
}

ShapeVtable circle_vtable = {
        (double(*)(Shape*)) GetAreaCircle,
        (void(*)(Shape*)) PrintInfoCircle
};

void CircleInitialize(Circle* circle,double radius)
{
    circle->parent.vtable=&circle_vtable;
    circle->radius=radius;
}
//////////////////////////////////////////
// Derived Class ( Rectangle ) - Concrete
struct Rectangle
{
    Shape parent;
    double height;
    double width;
};

double GetAreaRectangle(Rectangle* rectangle)
{
    return rectangle->height * rectangle->width;
}

void PrintInfoRectangle(Rectangle* rectangle)
{
    cout<<"Width and Height of Rectangle = "<<rectangle->width<<" "<<rectangle->height<<endl;
    cout<<endl;
}

ShapeVtable rectangle_vtable = {
        (double(*)(Shape*)) GetAreaRectangle,
        (void(*)(Shape*)) PrintInfoRectangle
};

void RectangleInitialize(Rectangle* rectangle,double width,double  height)
{
    rectangle->parent.vtable=&rectangle_vtable;
    rectangle->height=height;
    rectangle->width=width;
}
/////////////////////////////////////////////
// Derived Class ( Ellipse ) - Concrete
struct Ellipse
{
    Shape parent;
    double a;   // radius 1
    double b;  // radius 2
};

double GetAreaEllipse(Ellipse* ellipse)
{

    return ellipse->a*ellipse->b*PI;
}

void PrintInfoEllipse(Ellipse* ellipse)
{
    cout<<"2 Radius of Ellipse = "<<ellipse->a<<" "<<ellipse->b<<endl;
    cout<<endl;
}

ShapeVtable ellipse_vtable = {
        (double(*)(Shape*)) GetAreaEllipse,
        (void(*)(Shape*))PrintInfoEllipse
};

void EllipseInitialize(Ellipse* ellipse,double a,double b)
{
    ellipse->parent.vtable=&ellipse_vtable;
    ellipse->a = a;
    ellipse->b = b;
}
/////////////////////////////////////////////
int main()
{

   Circle circle;
    CircleInitialize(&circle, 10); // circle with radius 10

    Rectangle rectangle;
    RectangleInitialize(&rectangle, 3, 5); // rectangle with width 3 and height 5

    Ellipse ellipse;
    EllipseInitialize(&ellipse, 10, 12); // ellipse with radius 10, 12

    Shape* shapes[3];
    shapes[0]=(Shape*)&circle ;
    shapes[1]=(Shape*)&rectangle ;
    shapes[2]=(Shape*)&ellipse ;

    double total_area=0;

   int i;
    for(i=0;i<3;i++)
    {
        double d=GetArea(shapes[i]);
        total_area+=d;
        PrintInfo(shapes[i]); // prints (cout) the radius if circle, width and height if rectangle, ... etc
    }

    cout<<total_area<<endl; // check if the value is correct

    return 0;
}
