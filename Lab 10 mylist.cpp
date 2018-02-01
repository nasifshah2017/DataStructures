/* Filename: LAB 22.cpp
 * -------------------
 * Author: Syed Nasif Ali Shah
 * Course: CSC 162
 * Date:   2016/03/31
 *
 * Purpose: This program reverses a list by taking numbers from the user
 */




#include "list.h"

int main()
{
   List<int> myList;

   cout << myList << endl;
   cout << "\n\n";
   myList.ReverseList();
   cout <<"Output of Empty reversed List: " << myList << endl;


   cout << "\n";

   myList.insertAtFront(10);

   cout << myList << endl;
   cout << "\n\n";
   myList.ReverseList();
   cout << "Output of Single reversed List: " << myList << endl;

   cout << "\n";


   myList.insertAtFront(20);

   cout << myList << endl;
   cout << "\n\n";
   myList.ReverseList();
   cout << "Output of Multiple reversed List: " << myList << endl;

   cout << "\n";

   myList.insertAtEnd(30);

   cout << myList << endl;
   cout << "\n\n";
   myList.ReverseList();
   cout << "Output of Multiple reversed List: " << myList << endl;

   cout << "\n";

   myList.ReverseList();

   cout << "Output of Final reversed List: " << myList << "\n";

   cout << endl << "Size = " << myList.getSize() << endl << endl;

   while (myList.deleteFromFront())
        cout << myList << endl;

   cout << endl << "Size = " << myList.getSize() << endl;

   return 0;
}
