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
    void push(T newObj){
        data.append(newObj);
    }
    void pop(){
        if (isEmpty() != true)
            data.remove();
    }
    T& peek(){
        if (isEmpty() != true)
            return data.getTailVal();
    }
    bool isEmpty() {
        if (data.checkEmpty() == true)
            return true;
        else
            return false;
    }
};


#endif //INC_21F_FLIGHT_PLANNER_DSSTACK_H
