//Author: Himanshu Sahay

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


//Include Statements
#include <cstddef>
//#include <string>
#include "store_node.h"

//Author: Himanshu Sahay
class linkedlist
{
       public:
        linkedlist();
        ~linkedlist();

        void insert(int row, int col, int floor, int item_quantity);
        //item_node *search(std::string item_id);
        void destroy_list();
        void print_list();
        //virtual ~linkedlist();


    private:
        void destroy_list(store_node *nextNode);
        //void insert(int row, int col, int floor, int item_quantity, store_node *storePtr);
        store_node *search(int row, int col, int floor);
        void print_list(store_node *currNode);

        store_node *root; //root of linked list
};


#endif // LINKEDLIST_H
