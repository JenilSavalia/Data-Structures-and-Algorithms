// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main()
{

    int a = 10;
    cout << &a << endl; // prints memort address of a

    int *ptr = &a; // pointer of type int storing value of integer a

    // Note : Type of pointer must be same as of adressed stored
    // (above type if pointer is int and address stored of variable is also of type int)

    float price = 25.66;
    float *ptr2 = &price;

    // -------------------------------------

    // Pointer to Pointer

    int **ptr3 = &ptr;
    // See type of pointer should be same as type of variable whose address is stored

    // therefore (int*) is type of vairable whose address want to stored.
    // i.e a pointer , and declaring new pointer *ptr3 and assigingn address &ptr

    cout << &ptr << endl;
    cout << ptr3 << endl;
    // both will print same value

    // -------------------------------------

    // * = Dereferencing Operator

    cout << *(&a) << endl;
    cout << *(ptr) << endl;
    // this will give value of a

    int a = 10;

    int *ptr = &a;

    int **parPtr = &ptr;

    cout << *(parPtr) << endl;
    cout << ptr << endl;
    // o/p will be same

    cout << **(parPtr) << endl;
    // Double Dereferencing ,o/p will be 10

    // ---------------------

    return 0;
}

// -----------------------------------------------------------------------

// Pass By Value

void changeA(int a)
{ // Pass bt Value
    a = 20;
}

int main()
{
    int a = 10;

    changeA(20);

    cout << a; // still value of a will be 10, it will not change
}

// Pass by  Reference (POINTER)

void changeA(int *ptr)
{              // storing address of a in pointer ptr
    *prt = 20; // accessing value stored in address and modifying it
}

int main()
{
    int a = 10;

    changeA(&a); // passing address of a as parameter

    cout << a; // now value of a will be 20
}

// Pass by  Reference (alias)

void changeA(int &b)
{   // accessing "a" as alias in form of b
    // NOTE : here &b is alias syntax not for ponter

    b = 20; // "a" and "b" are same , b is alias of a,
    // value changed to "b" will reflect in "a"
}

int main()
{
    int a = 10;

    changeA(a); // passing address of a as parameter

    cout << a; // now value of a will be 20
}

// ----------------------------------------------------

// Array Pointers

int arr[] = {1, 2, 3, 4, 5};

// array in c++ is a constant pointer which points to first element of array

cout << arr << endl;
// this will print address of first element

cout << *arr << endl;

// this will print 1
