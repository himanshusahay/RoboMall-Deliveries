/*
Author Marco Duran
Driver file for how the shopper should run in phase 2 of the simulation
*Note not all of this code runs correctly but i believe that the logic behind it is correct
there is also no sense of time in this driver function
*/

#include <cstdlib>
#include <iostream>
#include "events.h"
#include "queue.h"
#include "shopper.h"

using namespace std;

//Author: Marco Duran
int main()
{
	EventList database;
	Shopper s;
	Queue itinerary;
	int i = 0;
	int arr_time; // the relative arrival time of the ith shopper to the simulation
	int j_items; // is the number of unique items on the ith shopper's shopping list
	string item; // is the 2 digit ASCII code for the jth item on the shopping list
	int count; // is the quantity of item that the shopper wants to buy
	int shoppers; //number of shoppers that are in the mall
	Store store;
	cout <<"Insert the number of shoppers that will be in the robomall";
	cin >> shoppers;


	while( i < shoppers)
{//runs the loop until the amount of shoppers is reached
	cout << "Insert the arrival time of shopper" << i+1 << endl;
	cin >> arr_time;
	cout << "\nInsert the number of items on the shopping list" << endl;
	cin >> j_items;

	for(int j = 0; j < j_items; j++)
	{
		cin >> item >> count;
		cout <<"[DEBUG] Item code: " << item << " " << "ItemCount: " << count;
		if(s.searchItem(database, store) == true)
		store = database.rootPtr->store;

		if(s.searchItem(database, store) == false){ //searches for the item in the database
			s.deleteItem(itinerary.headPtr, itinerary.tailPtr);//if not found it deletes the item from the queue
		}
		else{
			s.addStore(store, itinerary, database);
		}
	}

}



return 0;
}
