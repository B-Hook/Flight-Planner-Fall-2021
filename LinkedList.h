//
// Created by Braiden Hook on 10/26/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_LINKEDLIST_H
#define INC_21F_FLIGHT_PLANNER_LINKEDLIST_H

using namespace std;

template <typename T>

struct Node {
    T data;
    Node *next;
    Node *prev;
};

template <typename T>

class LinkedList {

private: //private data members
    Node <T> *head;
    Node <T> *tail;
    int *length;
public:
// Default Constructor
    LinkedList() {

        this->head = nullptr;
        this->tail = nullptr;
        this->length = new int (0);
    }
// Destructor
    ~LinkedList() {
        Node<T> *curr = this->head;
        //transversing through the list deleting each node
        while (curr != nullptr){
            Node<T> *deletedNode = curr;
            curr = curr->next;
            delete deletedNode;
        }
        this->head = nullptr;
        this->tail = nullptr;
        *length = 0;
    }
// Copy Constructor
    LinkedList(const LinkedList &copy){
        Node<T> *curr = copy.head;
        //transversing through list copying each node and appending it
        while (curr != nullptr){
            append(curr->data);
            curr = curr->next;
        }
    }
// Copy Assignment
    LinkedList &operator=(const LinkedList &copy){
        //if not a copy
        if (this != &copy) {
            this->clear();
            Node<T> *curr = copy.head;
            //transversing through list copying each node and appending it
            while (curr != nullptr){
                append(curr->data);
                curr = curr->next;
            }
        }
        return *this;
    }
// Append method that inserts a new node at the end of the list
    void append(T newObj) {
        Node<T> *newNode = new Node<T>; // Creating a new Node
        newNode->data = newObj; // Inserting the passed object into the new Node
        newNode->next = nullptr; // As it is the end of the list, the next node will always be null
        // If the current list is empty
        if (this->head == nullptr) {
            newNode->prev = nullptr; // Makes the pointer to the previous node null
            this->head = newNode; // Makes the head the new node
            this->tail = newNode; // As it is the only node in the list, it is also the tail
        }
            // When list is not empty
        else {
            this->tail->next = newNode; // Inserting the new node after the last node of the list
            newNode->prev = this->tail; // Making the prev pointer of the new node to the previous node
            this->tail = newNode; //Making the new node the tail of the list
        }
        *length = *length + 1; // increase length by 1
    }
    void clear() {
        Node<T> *curr = this->head;
        while (curr != nullptr){
            Node<T> *freeNode = curr;
            curr = curr->next;
            free(freeNode);
        }
        this->head = nullptr;
        this->tail = nullptr;
        *length = 0;
    }
};


#endif //INC_21F_FLIGHT_PLANNER_LINKEDLIST_H
