#include "rectangle.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void Rectangle::setWidth(double w)
{
    if (w < 0)
    {
        cout << "Cannot have negative width " << w << " of rectangle!" << endl;
        exit(0);
    }
    else width = w;
}

void Rectangle::setLength(double len)
{
    if (len < 0)
    {
        cout << "Cannot have negative length " << len << " of rectangle!" << endl;
        exit(0);
    }
    else length = len;


}

void Rectangle::drawTop() const
{
    double t = width - (int) width;
    int s;
    int i;

    cout << " ";

    for (i = getWidth() + .5; i > 0; i--)
    {
        cout << "-";
    }

    cout << "\n";
}

void Rectangle::draw() const
{
    double t = width - (int) width;
    double m = length - (int) length;
    int q, s;

    drawTop();


    if (t>=0.5) s = width + 1;
    else s = width;

    if (m>=0.5) q = length + 1;
    else q = length;

    for (int j = 0; j<q; j++) cout << "|" << setw(s + 2) << "|\n";
    cout << " ";
    for (int i = 0; i<s; i++) cout << "-";


}







