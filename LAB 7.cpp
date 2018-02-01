/* Filename: LAB 19.cpp
 * -------------------
 * Author: Syed Nasif Ali Shah
 * Course: CSci 162
 * Date:   28/29 January 2016
 *
 * Purpose: It arranges a file by placing the last name of the students at
 * the front, and also calculates the final marks from all the marks
 */

#include <iostream>
#include "rectangle.h"

using namespace std;


int main()

{
    double len, wid;

    cout << " Please input the length of your Rectangle \n";
    cin  >> len;
    cout << " Please input the width of your Rectangle \n";
    cin  >> wid;

    Rectangle (wid, len).draw();

    return 0;
}
