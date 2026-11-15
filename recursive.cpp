#include <iostream>
using namespace std;

// sum of first N natural numbers
// this is basically the following for contexttr sum(n) = n + sum(n - 1),  base case: sum(0) = 0
int sumN(int n) 
{
    if (n == 0)                 // base case
        return 0;
    return n + sumN(n - 1);     // recursionn part
}

// Implementation of Factorial of a number
// literal expression should be as follows  factorial(n) = n * factorial(n - 1),  base case: factorial(0) = factorial(1) = 1
long long factorial(int n) 
{
    if (n == 0 || n == 1)
    {      
        return 1;
      // Base case section
    }
    return n * factorial(n - 1);    // recursion section 
}

//  Nth term of the Fibonacci series (0, 1, 1, 2, 3, 5, 8, ...)
// fib(n) = fib(n - 1) + fib(n - 2),  base cases: fib(0) = 0, fib(1) = 1 (excuse my abbreviations fib for fibonacci)
int fibonacci(int n) {
    if (n == 0)
    {
      // base case .....
        return 0;
    }
    if (n == 1)
    { 
      // base case (the second one)
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);     // recursive part 
}

// generate N terms of the fibonacci series or sequence bla bla bla
// prints the current term 'a', then recurses with the next pair (b, a + b)
void generateFib(int n, int a = 0, int b = 1) {
    if (n == 0)
    {// base case basically when  no terms left
        return;
    }
    cout << a << " ";
    generateFib(n - 1, b, a + b);   // recursive sec
}

int main() 
{
  //I promise to add it as a Menu in the next commit
    int n;

    cout << "Enter N for sum of first N natural numbers: ";
    cin >> n;
    cout << "Sum = " << sumN(n) << "\n\n";

    cout << "Enter a number for factorial: ";
    cin >> n;
    cout << n << "! = " << factorial(n) << "\n\n";

    cout << "Enter N to find the Nth Fibonacci term: ";
    cin >> n;
    cout << "Fibonacci term " << n << " = " << fibonacci(n) << "\n\n";

    cout << "Enter N to generate N Fibonacci terms: ";
    cin >> n;
    cout << "Series: ";
    generateFib(n);
    cout << "\n";

    return 0;
}
