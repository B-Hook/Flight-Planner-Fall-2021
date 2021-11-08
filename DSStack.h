//
// Created by Braiden Hook on 10/27/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_DSSTACK_H
#define INC_21F_FLIGHT_PLANNER_DSSTACK_H
#include "LinkedList.h"

template <typename T>
class DSStack {

private:
    LinkedList<T> data;

public:
    DSStack(){

    }
    // Calls append method after pushing the newObj onto the stack
    // Append will place it on the top of the stack
    void push(T newObj){
        data.append(newObj);
    }
    // Will take the top value off of the stack
    void pop(){
        if (isEmpty() != true)
            data.remove();
    }
    // Will return the value on the top of the stack
    T& peek(){
        if (isEmpty() != true)
            return data.getTailVal();
    }
    // Checks to see if there is anything in the stack
    bool isEmpty() {
        if (data.checkEmpty() == true)
            return true;
        else
            return false;
    }
};


#endif //INC_21F_FLIGHT_PLANNER_DSSTACK_H
