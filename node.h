//Author: Himanshu Sahay
#ifndef NODE_H
#define NODE_H

#include <string>
#include "linkedlist.h"

//Author: Himanshu Sahay
//This Struct is used to hold the information held in the binary tree
struct item_node{
    std::string item_id;     //The Unique ID of Item, which the tree is ordered on
    linkedlist store_list;       //Pointer to the Start of the linked list which describes the locations of the item and quantity
    item_node *left;         //Pointer to the left child of the node in the tree
    item_node *right;        //Pointer to the right child of the node in the tree
};

#endif
