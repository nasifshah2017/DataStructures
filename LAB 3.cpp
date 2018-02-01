/* Filename: intarray.cpp
 * ----------------------
 * Course: CSci 161
 * Author: M. van Bommel
 * Date:   November 25, 2015
 *
 * Purpose: This program asks the user to enter values up to a sentinel value,
 * reverses the values, and prints them out in reverse order.
 *
 * Note: this program develops several functions for an array of integers.
 * Included are functions to fill up an array from input, print the array,
 * reverse the elements in the array, and swap two elements.
 */

#include <iostream>
using namespace std;

#define NElements 100
#define Sentinel   -1

/* Function prototypes */
int  GetIntegerArray(int array[], int max, int sentinel);
void PrintIntegerArray(int array[], int n);
void SortIntegerArray(int array[], int n);
void SwapIntegerElements(int array[], int p1, int p2);

/* Main program */
int main()
{
    int n, myArray[NElements];
    cout << "Please enter your numbers (" << Sentinel << " to stop)" << endl;
    n = GetIntegerArray(myArray, NElements, Sentinel);
    SortIntegerArray(myArray, n);
    cout << "The numbers in reverse order are:" << endl;
    PrintIntegerArray(myArray, n);
    return 0;
}

/* Function: GetIntegerArray
 * Usage: n = GetIntegerArray(array, max, sentinel);
 * -------------------------------------------------
 * This function reads elements into an integer array by reading values,
 * one per line, from the keyboard, until the sentinel value is entered.
 * The caller is responsible for declaring the array and passing it as a
 * parameter, along with its allocated size.  The value returned is the
 * number of elements actually entered and therefore gives the effective size
 * of the array, which is typically less than the allocated size given by max.
 * The user is warned if the array is full, and input stops.
 */

int GetIntegerArray(int array[], int max, int sentinel)
{
    int value, count = 0;
    cout << " ? ";
    cin  >> value;
    while (value != sentinel)
    {
        array[count] = value;
        count++;
        if (count == max)
        {
            cout << "Array full." << endl;
            return count;
        }
        cout << " ? ";
        cin >> value;
   }
   return count;
}

/*
 * Function: PrintIntegerArray
 * Usage: PrintIntegerArray(array, n);
 * -----------------------------------
 * This function displays the first n values in array,
 * one per line, to the standard output.
 */

void PrintIntegerArray(int array[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        cout << array[i] << endl;
    }
}

/*
 * Function: ReverseIntegerArray
 * Usage: ReverseIntegerArray(array, n);
 * -------------------------------------
 * This function reverses the order of the first n elements of array.
 */

void SortIntegerArray(int array[], int n)
{
    int i, limit = n / 2;

    for (i=0; i<limit; i++)
    {
        SwapIntegerElements(array, i, n-i-1);
    }
}

/*
 * Function: SwapIntegerElements
 * Usage: SwapIntegerElements(array, p1, p2);
 * ------------------------------------------
 * This function swaps the elements in array at index positions p1 and p2.
 */

void SwapIntegerElements(int array[], int p1, int p2)
{
    int tmp;

    if (array [p1] > array [p2])
    {
    tmp       = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
    }
}
