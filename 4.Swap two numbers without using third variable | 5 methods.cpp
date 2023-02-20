//Method 1: Using addition and subtraction operator

#include <iostream>
using namespace std;
 
// Swap using references in C++
void swap(int &x, int &y)
{
    // return if both variables' data is the same, as we can't check for the
    // address of a reference
    if (x == y) {
        return;
    }
 
    x = x + y;          // Note: overflow might happen
    y = x - y;
    x = x - y;
}
 
int main()
{
    int x = 3, y = 4;
    swap(x, y);
 
    cout << x << " " << y;
 
    return 0;
}
 
//Note that a copy of the actual parameter address is passed in a pass by reference, 
//and any changes made to these variables in the function will affect the original. 
//This can also be achieved using pointers in C, as demonstrated below.

#include <stdio.h>
 
// Swap using pointers to a function
void swap(int *x, int *y)
{
    if (*x == *y) {     // Check if the two addresses are the same
        return;
    }
 
    *x = *x + *y;       // overflow might happen
    *y = *x - *y;
    *x = *x - *y;
}
 
int main()
{
    int x = 3, y = 4;
    swap(&x, &y);
 
    printf("%d %d", x, y);
 
    return 0;
}

//---------------------------------------------------------
//Method 2: Using multiplication and division operator
#include <iostream>
using namespace std;
 
void swap(int &x, int &y)
{
    if (y && x != y)
    {
        x = x * y;      // overflow can happen
        y = x / y;
        x = x / y;
    }
}
 
int main()
{
    int x = 3, y = 4;
    swap(x, y);
 
    cout << x << " " << y;
 
    return 0;
}
 
//-------------------------------------------------
//Method 3: Using Bitwise XOR operator
#include <iostream>
using namespace std;
 
void swap(int &x, int &y)
{
    if (x != y)
    {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
 
    // in a single line
    // (x == y) || ((x ^= y), (y ^= x), (x ^= y));
}
 
int main()
{
    int x = 3, y = 4;
    swap(x, y);
 
    cout << x << " " << y;
 
    return 0;
}

//----------------------------------------------------------
//Method 4: Using difference between two values
#include <iostream>
using namespace std;
 
void swap(int &x, int &y)
{
    if (x != y)
    {
        x = x - y;
        y = y + x;
        x = y - x;
    }
 
    // in a single line
    // (x == y) || ((x -= y), (y += x), (x = y - x));
}
 
int main()
{
    int x = 3, y = 4;
 
    cout << "Before swap: x = " << x << " and y = " << y;
    swap(x, y);
    cout << "\nAfter swap: x = " << x << " and y = " << y;
 
    return 0;
}

/*----------------------------------------------------------------------------------
Method 5: Using single line expressions
We can also use any of the following expressions to swap two variables in a single line:


x = x ^ y ^ (y = x);
x = x + y – (y = x);
x = (x × y) / (y = x);

The following C++ program demonstrates it:
*/

#include <iostream>
using namespace std;
 
void swap(int &x, int &y)
{
    // x = x ^ y ^ (y = x);
    // x = x + y - (y = x);
    x = (x * y) / (y = x);
}
 
int main()
{
    int x = 3, y = 4;
    swap(x, y);
 
    cout << x << " " << y;
 
    return 0;
}
