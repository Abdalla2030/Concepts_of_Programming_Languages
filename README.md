# Concepts_of_Programming_Languages
Assignments of Concepts of Programming Languages Course ( CS322 ) 

***************************************************************************************************
Assignment 1  ( Convert Recursion to Iterative )

Consider the following recursive function:
------------------------------------------
## Example 
```
int F(int n) {

    if(n<=1) return 1;
    
    int a=n+F(n-1);
    
    int b=n*F(n/2);
    
    int c=n-2-(a+b)%2;
    
    int d=F(c);
    
    return a+b+d;   
 }
 ```
------------------------------------------
* Write a C++ code that does the following:
* You are not allowed to use any built-in functions except: cstdlib, cstdio, cstring, iostream, stack.
* You are not allowed to use string class, vector, or anything from STL libraries except <stack>.
* Convert the above function to a non-recursive function using the simulating recursion method using stack in Lecture04_Subprograms.
* Simulate recursion as specified in our lecture, without using any recursive call directly or indirectly.
* You are not allowed to use any other method than the method described in Lecture04_Subprograms applied to the above function.
* Your code must be general to handle all input values.
* Write at least 20 test case statements (F(1),F(2),..,F(20)) that make sure that your output matches the original function output.
* Half the mark is dedicatd to comments explaining the code before each code line, test cases, and following the CodingStyle.pdf file.
***************************************************************************************************
Assignment 2  ( Simpulating Polymorphism )

* Write a C++ code that does the following:
* You are not allowed to use any built-in functions except: <cmath>, <cstdlib>, <cstdio>, <cstring>, <iostream>.
* You are not allowed to use string class, vector, or anything from STL libraries.
* Implement base struct Shape and derived struct Circle, Rectangle and Ellipse simulating polymorphism without using the virtual keyword. Do not use the C++ inheritance or polymorphism mechanisms but simulate them as described in our lecture Lecture05_GenericProg. You are allowed to use some lecture code. Your code must be general.
* Write standard C++, such that the following main() works. You are not allowed to modify the main().
* Half the mark is dedicatd to comments explaining the code before each code line, test cases, and following the CodingStyle.pdf file.
## Example 
```
int main(){
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
    for(i=0;i<3;i++) {                    
        double d=GetArea(shapes[i]);                   
        total_area+=d;                     
        PrintInfo(shapes[i]); // prints (cout) the radius if circle, width and height if rectangle, ... etc 
   }   
    cout<<total_area<<endl; // check if the value is correct                          
    return 0;                           
}
```
