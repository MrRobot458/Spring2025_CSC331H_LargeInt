/*
* Purpose:
*     This is the header file for the DoublyLinkedList class. The C++ language standard is C++20.
*
* Input: None.
* Output: None.
*/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

//---- Node struct definition ----//
template <typename T>
struct Node {
    T info;         // Stores data of a generic type
    Node<T>* next;  // Points to a node that comes after
    Node<T>* prev;  // Points to a node that comes before 

    // Constructor
    Node(const T& item) : info(item), next(nullptr), prev(nullptr) { }
};

//---- DoublyLinkedList class declaration ----//
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* first;  // Pointer to the first node of the list
    Node<T>* last;   // Pointer to the last node of the list
    int length;      // Stores the number of items in the list

    // Copies another list
    void copy(const DoublyLinkedList<T>&);

    // Deletes the entire list
    void destroy();

public:
    // Constructor
    DoublyLinkedList();

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList<T>&);

    // Overloads the assignment operator (=)
    const DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);

    // Destructor
    ~DoublyLinkedList();

    // Searches the list for a given item
    bool searchItem(T) const;

    // Inserts a given item at the front of the list
    bool insertFirst(T);

    // Inserts a given item at the end of the list
    bool insertLast(T);

    // Deletes a given item from the list
    void deleteItem(T);

    // Checks if the list is empty
    bool isEmpty() const;

    // Returns the length of the list
    int getLength() const;

    // Displays the list
    void printList() const;

    //--- Iterator class declaration ---//
    class Iterator {
    private:
        Node<T>* current;

    public:
        // Constructor
        Iterator();

        // Overloaded constructor
        Iterator(Node<T>*);

        // Destructor
        ~Iterator();

        // Overloads the dereference operator (*)
        T& operator*() const;

        // Overloads the arrow operator (->)
        T* operator->() const;

        // Overloads the pre-increment operator (++T)
        Iterator operator++();

        // Overloads the pre-decrement operator (--T)
        Iterator operator--();

        // Overloads the post-increment operator (T++)
        Iterator operator++(int);

        // Overloads the post-decrement operator (T--)
        Iterator operator--(int);

        // Overloads the equality operator (==)
        bool operator==(const Iterator&) const;

        // Overloads the inequality operator (!=)
        bool operator!=(const Iterator&) const;
    };

    //--- DoublyLinkedList Iterator methods declarations ---//

    // Returns the starting point for traversing the list
    Iterator begin();

    // Returns the endpoint for traversing the list
    Iterator end();

    // Returns the starting point for traversing the list in reverse
    Iterator revBegin();

    // Returns the endpoint for traversing the list in reverse
    Iterator revEnd();
};

#endif
