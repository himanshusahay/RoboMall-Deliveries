//Author: Himanshu Sahay
#ifndef STORE_NODE_H
#define STORE_NODE_H

#include <string>
//#include "linkedlist.h"


//Author: Himanshu Sahay
//This Struct is used to hold the information held in the linked list
struct store_node{
    int row;                 //Row of the Store
    int col;                 //Column of the Store
    int floor;               //Floor of the Store
    int item_quantity;       //An integer representing the quantity of the specific item at the given store
    store_node *next_store;  //A pointer to the next store_node in the linked list
};

#endif
