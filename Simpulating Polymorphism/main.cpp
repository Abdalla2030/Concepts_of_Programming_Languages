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
    // Shape has object of shape virtual table
    ShapeVtable* vtable;
};
// virtual table of class shape consists of 2 virtual function
// GetArea and PrintInfo
struct ShapeVtable
{
    double (*GetArea)(Shape*);
     void (*PrintInfo)(Shape*);
};
// call GetArea of a specific Shape ( Circle or Rectangle or Ellipse)
double GetArea(Shape* shape)
{
    return shape->vtable->GetArea(shape);
}
// call PrintInfo of a specific Shape ( Circle or Rectangle or Ellipse)
void PrintInfo(Shape* shape)
{
    shape->vtable->PrintInfo(shape);
}
///////////////////////////////////////
// Derived Class ( Circle ) - Concrete
struct Circle
{
    // Circle has object of Shape struct
    // Simulate Inheritance
    Shape parent;
    // radius of Circle
    double radius;
};
// Calculate area of Circle
double GetAreaCircle(Circle* circle)
{
    return  PI* circle->radius * circle->radius;
}
// Print Circle Info ( radius )
void PrintInfoCircle(Circle* circle)
{
    cout<<"Radius of Circle = "<<circle->radius <<endl;
    cout<<endl;
}
// simulate function overriding
// override GetArea function
// override PrintInfo function
ShapeVtable circle_vtable = {
        (double(*)(Shape*)) GetAreaCircle,
        (void(*)(Shape*)) PrintInfoCircle
};
// Simulate Constructor
// Assign initial value to Circle attributes
void CircleInitialize(Circle* circle,double radius)
{
    circle->parent.vtable=&circle_vtable;
    circle->radius=radius;
}
//////////////////////////////////////////
// Derived Class ( Rectangle ) - Concrete
struct Rectangle
{
    // Rectangle has object of Shape struct
    // Simulate Inheritance
    Shape parent;
    // width and height of Rectangle
    double width;
    double height;
};
// Calculate area of Rectangle
double GetAreaRectangle(Rectangle* rectangle)
{
    return rectangle->height * rectangle->width;
}
// Print Rectangle Info ( width and height )
void PrintInfoRectangle(Rectangle* rectangle)
{
    cout<<"Width and Height of Rectangle = "<<rectangle->width<<" "<<rectangle->height<<endl;
    cout<<endl;
}
// simulate function overriding
// override GetArea function
// override PrintInfo function
ShapeVtable rectangle_vtable = {
        (double(*)(Shape*)) GetAreaRectangle,
        (void(*)(Shape*)) PrintInfoRectangle
};
// Simulate Constructor
// Assign initial value to Rectangle attributes
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
    // Ellipse has object of Shape struct
    // Simulate Inheritance
    Shape parent;
    // 2 radius of Ellipse
    double a;   // radius 1
    double b;  // radius 2
};
// Calculate area of Ellipse
double GetAreaEllipse(Ellipse* ellipse)
{

    return ellipse->a*ellipse->b*PI;
}
// Print Ellipse Info ( radius 1 and radius 2 )
void PrintInfoEllipse(Ellipse* ellipse)
{
    cout<<"2 Radius of Ellipse = "<<ellipse->a<<" "<<ellipse->b<<endl;
    cout<<endl;
}
// simulate function overriding
// override GetArea function
// override PrintInfo function
ShapeVtable ellipse_vtable = {
        (double(*)(Shape*)) GetAreaEllipse,
        (void(*)(Shape*))PrintInfoEllipse
};
// Simulate Constructor
// Assign initial value to Ellipse attributes
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
