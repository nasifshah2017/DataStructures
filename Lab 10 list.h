/* Filename: list.h
 * -------------------------
 * Author: M. van Bommel
 * Course: CSci 162
 * Date:   23 April 2016
 *
 * Purpose: Generic template class implementation of list.
 *
 * To create a list to store datatype d, declare it as a List<d> name;
 * for example, to create a list of integers, use
 *                  List<int> myIntList;
 *
 * To then use a method m on the list, use name.m();
 * for example, to insert the number 10 at the front of myIntList, use
 *                  myIntList.InsertAtFront(10);
 *
 * A list can be displayed using stream insertion:
 *                  cout << myIntList << endl;
 *
 * Note:
 *   In order to use display or stream insertion on your list,
 *   stream insertion (<<) must be defined for the data type used in the list.
 */

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class ListNode
{
    public:
        T value;
        ListNode *next;

        ListNode(T v, ListNode *n = NULL) { value = v; next  = n; }
};

template <class T>
class List
{
    private:
        ListNode<T>  *head, *tail;
        int           listSize;
    public:
        List()   { head = tail = NULL; listSize = 0; }
       ~List();
        bool insertAtFront(T);
        bool insertAtEnd(T);
        bool deleteFromFront();
         T   getFront() const;
        bool isEmpty()  const  { return listSize == 0; }
        int  getSize()  const  { return listSize; }
        void display(ostream &)  const;
        void ReverseList();
};

template <class T>
List<T>::~List()
{
    while (head != NULL)
    {
        tail = head;
        head = head->next;
        delete tail;
    }
}

template <class T>
bool List<T>::insertAtFront(T v)
{
    ListNode<T> *temp = new ListNode<T>(v, head);
    if (temp == NULL) return false;
    head = temp;
    if (tail == NULL) tail = head;
    listSize++;
    return true;
}

template <class T>
bool List<T>::insertAtEnd(T v)
{
    ListNode<T> *temp = new ListNode<T>(v, NULL);
    if (head == NULL) head = temp;
    else tail->next = temp;
    tail = temp;
    listSize++;
    return true;
}

template <class T>
bool List<T>::deleteFromFront()
{
    ListNode<T> *temp = head;
    if (head == NULL) return false;
    if (tail == head) tail = NULL;
    head = head->next;
    delete temp;
    listSize--;
    return true;
}

template <class T>
T List<T>::getFront() const
{
    if (head == NULL) {
        cout << endl << "Cannot get front of empty list!" << endl;
        exit(0);
    }
    return head->value;
}

template <class T>
void List<T>::display(ostream &os) const
{
    os << "Head -> ";
    ListNode<T> *temp = head;
    while (temp != NULL)
    {
        os << temp->value << " -> ";
        temp = temp->next;
    }
    os << "NULL";
}

template <class T>
ostream & operator<<(ostream &os, List<T> &theList)
{
    theList.display(os);
    return os;
}

template <class T>
void List<T>::ReverseList()
{

        ListNode<T> *current, *prev, *next;

        current = head; //Initial state
        prev = NULL; // Initial state
        tail = head;

        while (current != NULL)
        {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    //}
}

#endif // LIST_H_INCLUDED
