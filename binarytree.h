//Author: Himanshu Sahay

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstddef>
//#include <string>
#include "node.h"

//Author: Himanshu Sahay
class binarytree
{
    public:
        binarytree();
        ~binarytree();

        void insert(std::string item_id, int row, int col, int floor, int item_quantity);
        //void insert(std::string item_id, store_node *new_store);
        item_node *search(std::string item_id);
        void destroy_tree();
        void print_tree();
        // virtual ~binarytree();


    private:
        void destroy_tree(item_node *child);
        void insert(std::string item_id, int row, int col, int floor, int item_quantity, item_node *child);
        //void insert(std::string item_id, store_node *new_store, item_node *child);
        item_node *search(std::string item_id, item_node *child);
        void print_tree(item_node *currNode);

        item_node *root;

};



#endif // BINARYTREE_H
