#include<iostream> 
using namespace std; 
  
int fibonacci(int n) 
{ 
    if (n <= 1) 
        return 1; 
    return fibonacci(n-1) + fibonacci(n-2); 
} 
  
int main () 
{ 
    int number;
    cout<<"Enter Fibonacci number : ";
    cin >> number;
    cout << fibonacci(number)<<endl; 
    return 0; 
} 
