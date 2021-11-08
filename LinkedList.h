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
    Node <T> *curr;
public:
// Default Constructor
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->curr = nullptr;
    }
// Destructor
    ~LinkedList() {
        currToFront(); //makes curr pointer the head
        // Transversing through the list deleting each node
        while (this->curr != nullptr){
            Node<T> *deletedNode = this->curr;
            this->curr = this->curr->next;
            delete deletedNode;
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->curr = nullptr;
    }
// Copy Constructor
    LinkedList(const LinkedList &copy){
        head = tail = curr = nullptr;
        Node<T> *temp = copy.head;
        // Transversing through list copying each node and appending it
        while (temp != nullptr){
            append(temp->data);
            temp = temp->next;
        }
    }
// Copy Assignment
    LinkedList &operator=(const LinkedList &copy){
        //if not a copy
        if (this != &copy) {
            this->clear();
            Node<T> *temp = copy.head;
            // Transversing through list copying each node and appending it
            while (temp != nullptr){
                append(temp->data);
                temp = temp->next;
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
        //*length = *length + 1; // increase length by 1
    }
// inserts before current node
    void insert (T newObj) {

        Node<T> *newNode = new Node<T>;
        newNode->data = newObj;
        // Checks to see if empty, if so then will insert the newObj at the front
        if (this->head == nullptr) {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            this->head = newNode;
            this->tail = newNode;

        }
        // If not empty then it will inserts before the current node
        else {
            newNode->prev = this->curr->prev;
            this->curr->prev = newNode;
            newNode->next = this->curr;
            // Checking to see if the new node is at the front of the list or not
            // If the prev does have a nullptr then it is the head and thus becomes the head
            // If not then there is a previous value which will need to point to the newNode completing the list
            if (newNode->prev != nullptr)
                newNode->prev->next = newNode;
            else
                this->head = newNode;
        }
    }
// Removing last node in the linked list
    void remove(){
        // If there is only one value in the list then everything will become null
        if (this->tail->prev == nullptr){
            Node<T> *deletedNode = this->tail;
            this->head = nullptr;
            this->tail = nullptr;
            this->curr = nullptr;
            free (deletedNode);
        }
        // if not then it will remove the last node of the list
        else {
            Node<T> *deletedNode = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            free (deletedNode);
        }
    }
    // Clearing the list by freeing each node and making everything null at the end
    void clear() {
        currToFront();
        while (this->curr != nullptr){
            Node<T> *freeNode = this->curr;
            this->curr = this->curr->next;
            free(freeNode);
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->curr = nullptr;
    }

    void currToFront() {
        this->curr = this->head;
    }

    void currToBack() {
        this->curr = this->tail;
    }

    void currToNext(){
        if (this->curr != nullptr)
            this->curr = this->curr->next;
    }
    void currToPrev(){
        if (this->curr != nullptr)
            this->curr = this->curr->prev;
    }

    T& getCurrVal(){
        return this->curr->data;
    }

    T& getTailVal(){
        return this->tail->data;
    }

    bool checkEmpty(){
        if (this->head == nullptr)
            return true;
        else
            return false;
    }

    bool isCurrNull(){
        if (this->curr == nullptr)
            return true;
        else
            return false;
    }

};


#endif //INC_21F_FLIGHT_PLANNER_LINKEDLIST_H
