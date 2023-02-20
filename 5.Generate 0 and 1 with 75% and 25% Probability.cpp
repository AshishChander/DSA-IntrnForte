//The following function generates 0 or 1 with 50% probability each, which can be used to generate 0 and 1 with 75% and 25% probability:

int random()
{
    // `rand()` produces a random number
    int random = rand();
 
    // if the random number is even, return 0; otherwise, return 1
    return (random % 2);
}

/* --------------------------------------------------------------
1. Using Bitwise AND Operator (or Logical AND Operator)
We can use bitwise or logical AND operator to solve this problem. The idea is two make two calls to the random() function and return AND of results returned by the individual calls.

// Return 0 and 1 with 75% and 25% probability, respectively, using the
// specified function and bitwise AND operator


*/
int generate()
{
    int x = random();
    int y = random();
 
    return (x & y);
}

/* 
Explanation:

x can be either {0, 1}
y can be either {0, 1}
(x & y) can be either {0, 0, 0, 1}


--------------------------------------------------------------
2. Using Bitwise OR Operator (or Logical OR Operator)
We can also use a bitwise or logical OR operator. The idea remains similar. First, make two calls to the random() function and then return the negation of OR of results returned by the individual calls, as shown below:

// Return 0 and 1 with 75% and 25% probability, respectively, using the
// specified function and bitwise OR operator

*/
int generate()
{
    int x = random();
    int y = random();
 
    return !(x | y);
}

/* 
Explanation:

x can be either {0, 1}
y can be either {0, 1}
(x | y) can be either {1, 1, 1, 0}
!(x | y) can be either {0, 0, 0, 1}


--------------------------------------------------------------
3. Using Left Shift Operator and Bitwise XOR Operator
The idea is to use this expression: (random() << 1) ^ random().

 
How this works?

random() returns either 0000 or 0001 (in binary)
(random() << 1) can be either 0000 or 0010
(random() << 1) ^ random() can be either {0001, 0011, 0000, 0010}
// Return 0 and 1 with 75% and 25% probability, respectively, using the
// specified function, left shift operator, and bitwise XOR operator

*/

int generate() {
    return ((random() << 1) ^ random()) == 0;
}
