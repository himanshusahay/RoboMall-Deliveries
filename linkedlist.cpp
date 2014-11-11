//Author: Himanshu Sahay


#include <iostream>
#include <iomanip>
#include "linkedlist.h"
//#include <string>

//Defining the namespace for printing and reading in data
using namespace std;

//Author: Himanshu Sahay
//Public Constructor
linkedlist::linkedlist(){
      root=NULL;
}

//Author: Himanshu Sahay
//Public Destructor for Garbage Collection
linkedlist::~linkedlist(){
    destroy_list();
}

//Author: Himanshu Sahay
//Private Destructor for emptying the tree
void linkedlist::destroy_list(store_node *nextNode){
  if(nextNode!=NULL)
  {
    destroy_list(nextNode->next_store); //Go down the whole left side removing the nodes
    delete nextNode;              //Remove the node
  }
}

//Author: Himanshu Sahay
//Private Destructor for Garbage Collection
void linkedlist::destroy_list(){
  destroy_list(root);
}

//Author: Himanshu Sahay
//Public Function for adding a store node to the inventory linked list
void linkedlist::insert(int row, int col, int floor, int item_quantity){
  if(root!=NULL){ //If the list is not empty
        store_node *newNode = new store_node;
        newNode->row = row;
        newNode->col = col;
        newNode->floor = floor;
        newNode->item_quantity = item_quantity;
        //
        store_node *currNode = root, *temp, *prev;

        if( search( row, col, floor) != NULL) { // If there is already an entry with the same coordinates, add to it
            //search( row, col, floor )->item_quantity += item_quantity;

            temp = root;
            while(temp != NULL){
                if((temp->row == row)&&(temp->col == col)&&(temp->floor == floor)){
                    if(temp == root){
                        root = temp->next_store;
                        insert(row, col, floor, temp->item_quantity+item_quantity);
                        delete temp;
                    }
                    else{
                        prev->next_store = temp->next_store;
                        insert(row, col, floor, temp->item_quantity+item_quantity);
                        delete temp;
                    }
                }
                else{
                    prev = temp;
                    temp = temp->next_store;
                }
            }



            /*
            while((currNode->next_store != NULL)) {
                if(!(row == currNode->next_store->row) && (col == currNode->next_store->col) && (floor == currNode->next_store->floor))){
                    currNode = currNode->next_store;
                }
            }
            if(currNode->next_store != NULL){
                temp  = currNode->next_store;
                currNode->next_store = currNode->next_store->next_store;
                insert(temp->row, temp->col, temp->floor, temp->item_quantity + item_quantity);
            }
            else{
                ;
                insert(row, col, floor, currNode->item_quantity + item_quantity);
            }

            delete temp;
            */
        }

        else if( item_quantity > root->item_quantity) {
                newNode->next_store = root;
                root = newNode;
        }
        else {


            //OLD CODE WITH NULL ERROR
            /*
            while( item_quantity < currNode->next_store->item_quantity ) {
                currNode = currNode->next_store;
            }
            */
            while((currNode->next_store != NULL) && (item_quantity < currNode->next_store->item_quantity )) {
                currNode = currNode->next_store;
            }
            newNode->next_store = currNode->next_store; // Insert the node between current node and the one after it
            currNode->next_store = newNode;

        }
  }
  else{           //The list is empty
    root = new store_node;
    root->row = row;
    root->col = col;
    root->floor = floor;
    root->item_quantity = item_quantity;
    root->next_store = NULL;
  }
}

//Author: Himanshu Sahay
//Public Function for Printing out the Tree
void linkedlist::print_list(){
    print_list(root);
}

//Author: Himanshu Sahay
//Private Function for Printing out the List
void linkedlist::print_list(store_node *storeNode){
    if(storeNode != NULL){
        cout << "Qty Available: " << storeNode->item_quantity << "     Store Location: (" << storeNode->row << ", " << storeNode->col << ", " << storeNode->floor << ")" << endl;
        //cout << "Item count: " << storeNode->item_quantity << " Row: " << storeNode->row << " Column: " << storeNode->col << " Floor: " << storeNode->floor << endl;
        print_list(storeNode->next_store);
    }

}

//Author: Himanshu Sahay
// Private function to return the item in the linked list of store nodes with the same coordinates  as a given node, if one exists
store_node *linkedlist::search( int row, int col, int floor ) {
        if( root == NULL) {
                return NULL; // Returns null if called on an empty linked list
        }

        else{
            store_node *currNode = root;
            while( currNode != NULL) { // Check each item in the list for a match
                if( (row == currNode->row) && (col == currNode->col) && (floor == currNode->floor)) {
                    return currNode;
                }
                currNode = currNode->next_store;
            }
            return NULL; // return NULL if a matching node is not found
        }
    }
