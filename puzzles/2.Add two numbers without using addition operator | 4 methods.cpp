
/*
Given two numbers, add them without using an addition operator.

1. Using subtraction operator
*/

int add(int a, int b) {
    return a-(-b);
}

/*

2. Repeated Addition/Subtraction using --/++ operator
*/

#include <iostream>
using namespace std;
 
int add(int a, int b)
{
    // to handle positive `a`
    while (a > 0)
    {
        b++;
        a--;
    }
 
    // to handle negative `a`
    while (a < 0)
    {
        b--;
        a++;
    }
 
    return b;
}
 
int main()
{
    cout << add(5, 8) << " ";
    cout << add(5, -8) << " ";
    cout << add(-5, 8) << " ";
 
    return 0;
}

//Output:

//13 -3 3

/*
3. Using printf() function
This method makes use of two facts:

We can use an asterisk * to pass the width precision to printf(), rather than hard-coding it into the format string.
printf() function returns the total number of characters printed on the output stream.
Note that we can also use %*c, ' ' replacing %*s, "".

*/

int add(int a, int b)
{
    // `%*s` means print a character `*` number of times
    return printf("%*s%*s", a, "", b, "");
}

/*
4. Half adder logic
*/

int add(int a, int b)
{
    if (!b) {
        return a;
    }
 
    int sum = a ^ b;
    int carry = (a & b) << 1;
 
    return add(sum, carry);
}

/*
5. Using logarithm and exponential function

*/

#include <stdio.h>
 
int main(void)
{
    int a = 8, b = 6;
 
    printf("%g\n", log(exp(a) * exp(b)));
 
    return 0;
}
