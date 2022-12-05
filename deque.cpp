#include <iostream>
#include "deque.h"
using namespace std;

template <class T>
deque<T>::deque()
{
    Node *head = new Node;
    head->left = head;
    head->right = head;
    first = head;
}

template <class T>
deque<T>::~deque()
{
    first->right->left = 0;
    first->left->right = 0;
    first->left = 0;
    Node *cur = first;
    while (cur != 0)
    {
        Node *temp = cur;
        cur = cur->right;
        delete temp;
    }
}

template <class T>
void deque<T>::deleteFront()
{
    Node *temp = first->right;
    temp->right->left = first;
    first->right = temp->right;
    delete temp;
}

template <class T>
void deque<T>::deleteRear()
{
    Node *temp = first->left;
    temp->left->right = first;
    first->left = temp->left;
    delete temp;
}

template <class T>
void deque<T>::insertFront(const T data)
{
    Node *p = new Node(data);
    first->right->left = p;
    p->right = first->right;
    first->right = p;
    p->left = first;
}

template <class T>
void deque<T>::insertRear(const T data)
{
    Node *p = new Node(data);
    first->left->right = p;
    p->left = first->left;
    first->left = p;
    p->right = first;
}