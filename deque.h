#ifndef DEQUW_H
#define DEQUE_H
using namespace std;

template <class T>
class deque
{
    // Forward declaration
    class Node;

public:
    deque();
    ~deque();
    // Adds an item at the front of deque
    void insertFront(const T data);
    // Adds an item at the rear of deque
    void insertRear(const T data);
    // deletes an item from front of deque
    void deleteFront();
    // deletes an item from rear of deque
    void deleteRear();

private:
    class Node
    {
    public:
        Node(T element = 0) : data(element), left(0), right(0) {}
        T data;
        Node *right, *left;
    };
    Node *first;
};
#endif