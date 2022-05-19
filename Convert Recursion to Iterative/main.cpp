////////////////////////////////////////
// Abdalla Fadl Shehata  - 20190305   //
///////////////////////////////////////
#include <iostream>
#include <stack>
using namespace std;
///////////////////////////////////////
int F(int n)
{
    if(n<=1) return 1;
    int a=n+F(n-1);
    int b=n*F(n/2);
    int c=n-2-(a+b)%2;
    int d=F(c);
    return a+b+d;
}
/////////////////////////////////////////
enum operationType{calculate_n,calculate_a,calculate,calculate_b,a_plus_b,calculate_d,a_plus_b_plus_d};
/////////////////////////////////////////
struct call
{
    int n; // input
    int c ; // c  = n-2-(a+b)%2
    int temp; // temp = a+b+f(c)
    operationType type ; // the type of operation
};
///////////////////////////////////////////
int iterativeFun(int n)
{
    // store the return value of this function
    int finalResult ;
    stack<call>s;
    call currentCall ;
    // add input number to the stack
    currentCall.n = n ;
    currentCall.type=calculate_n;
    // add first call to the stack
    s.push(currentCall);
    while(!s.empty())
    {
        // get the top of the stack and remove it
        currentCall=s.top();
        s.pop();
        if(currentCall.type==0)
        {
                // base case
                if(currentCall.n<=1)
                {
                    finalResult=1;
                    continue;
                }
                // if input(n) > 1
                else
                {
                    // after calculate a, now calculate b and c and d
                    currentCall.type=calculate;
                    s.push(currentCall);
                   // after calculate the F(n-1), then calculate a
                   // a = n + F(n-1)
                    currentCall.type=calculate_a;
                    s.push(currentCall);
                   // to call F(n-1) -> decrease n and push F(n-1) at the top of the stack
                    currentCall.n=currentCall.n-1;
                    currentCall.type=calculate_n;
                    s.push(currentCall);
                    continue;
                }
            }
            else if(currentCall.type ==1)
            {
                //add value of F(n-1) to n to calculate a and store result in return variable of this function
                finalResult+=currentCall.n;
                continue;
            }
             else if(currentCall.type==2)
            {
              // after the value of (a+b) is calculated, now the can get the value of c and calculate d
               currentCall.type= calculate_d;
               s.push(currentCall);
              // store the value of a in temp variable
                currentCall.temp = finalResult;
                // after calculate b
                // now we can find the value of a+b
                currentCall.type=a_plus_b;
                s.push(currentCall);
                // after calculate the F(n/2), then calculate b
                // b = n * F(n/2)
                currentCall.type=calculate_b;
                s.push(currentCall);
                // to call F(n/2) -> decrease n by 1/2 and push F(n/2) at the top of the stack
                currentCall.n=currentCall.n/2;
                currentCall.type=calculate_n;
                s.push(currentCall);
                continue;
            }
        else if(currentCall.type==3)
        {
            //calculate value of b and store result in return variable of this function
            // b = n*F(n/2)
            finalResult*=currentCall.n;
            continue;
        }
        else if(currentCall.type==4)
        {
            // to calculate (a+b)  --> temp store the value of a and finalResult store the value of b
            finalResult+=currentCall.temp;
            continue;
        }
        else if(currentCall.type==5)
        {
            //calculate value of c
            // now finalResult = a+b
            currentCall.c=currentCall.n-2-(finalResult)%2;
            // to calculate F(c) , update n to be c
            currentCall.n=currentCall.c;
            // now temp store the value of (a+b)
            currentCall.temp = finalResult;
            // after calculate F(c)
            // now we calculate a+b+d and store result in the top of stack
            currentCall.type=a_plus_b_plus_d;
            s.push(currentCall);
            // to calculate F(c) go to the first condition again
            currentCall.type=calculate_n;
            s.push(currentCall);
        }
        // calculate the sum of a+b+d and store it in finalResult
        else
        {
            // temp store the value of (a+b)
            // finalResult store the value of d
            finalResult+=currentCall.temp;
            continue;
        }
     }
     // return the final value of function
    return finalResult;
}
//////////////////////////////////////////
int main()
{
   cout<<"     Recursive \t   Iteration"<<endl;
    for(int i=1;i<=20;i++)
    {
     cout<<"F("<<i<<")\t"<<F(i)<<"\t\t"<<iterativeFun(i)<<endl;
     cout<<"================================"<<endl;
    }
}
