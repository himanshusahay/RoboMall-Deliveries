//Author: Himanshu Sahay

//#include "globals.h"
#include "mall.h"
#include <iostream>
#include <string>
#include "binarytree.h"

using namespace std;

//Author: Himanshu Sahay
int main()
{

  cout<<"Stage 1 starts here"<<endl;
  //STAGE 1 STARTS HERE
  /*

Robot has a class.
Start with robot object. One of the class members is an array of pointers to the robots.
move() is now a member function fo the robot and can be called as mallobject->robotobject[i]->move(*tptr,x,y,z);
Mall is wrapper class for everything in this program

go to //CHECK THIS in mall->cpp
Call floormap() as mallObject.floormap();

*/


// Had to rewrite program 4 to make it work since first submission of program 4 did not work
//Variable Definitions for the item input implementation - currently done for 1 robot
  int i, num_unique_items,num_items;
  std::string item_id;
  binarytree item_tree;
  item_node *item_s_result = NULL;

  Mall *mall = new Mall(); //declaring new Mall object. Mall is wrapper class for program

  //struct robot rb; //Declares new robot (extern given in header)
  //int endtime[9],starttime[9]; //start and end times of robot simulation
  // int j;
  int time = 0;
  int rnum; //Number of robots
  int storenum; //Number of stores
  int *tptr;
  tptr = &time;
  int snum[9]; //number of stores for each robot



  //struct robot *rptr;
  //rptr = &rb; //Pointer to current robot
  int xtemp,ytemp,ztemp;
  //int snum[24]; //array for number of stroes for each robot

  // First take number of robots from user. Then take number of stores that each robot will visit.
  // Finally, take coordinates of each store to be visited

  cout << "Welcome to Robomall!" << endl;
  mall->floormap(); //Show floor map for user

  cout << "Enter the number of robots that will enter RoboMall: " << endl;
  cin>>rnum;
  cout<<"Number of robots is "<<rnum<<endl;
  //mall->R[0]->starttime = 0; //Start time of first robot is 0 time units

  for(i=0;i<rnum;i++)
    {
      cout << "Enter number of stores for robot " << i+1 <<endl;
      cin>>storenum;
      mall->R[i]->checkIfInMall = true; //robot is in the mall now
      snum[i]=storenum; //Adds number of stores for current store into the array for number of stores for all robots
      //cout<<"\nNo. of stores = "<<snum[i]<<endl;
    }
    //varibles to use in loops
    int q = 0;
    int p = 0;

    for(q=0;q<rnum;q++) //loop for number of robots
      {
        cout<<"\nNow, processing robot "<<q+1<<endl;
        for(p=0;p<=snum[q];p++) //One extra iteration to make the robot go back to the A1 tile
        {
          cout<<"\nNo. of stores for this robot: "<<snum[q];

          if(p==0) //First pass for a robot, when it goes to it's first store
            {
              cout  << "\nEnter coordinates for the store robot " << q+1 << " will visit: " << endl;
              cin >>xtemp>>ytemp>>ztemp;
              struct coord storetemp = {xtemp,ytemp,ztemp}; //Store coordinates to be visited

			         mall->R[q]->destination = storetemp;

              cout << "Enter Number of Items for this Store: " << endl;
              cin >> num_unique_items;
              cout << "Store Location: " << xtemp << " " << ytemp << " " << ztemp  << "    Number of Items to be Read In: " << num_unique_items << endl;

              //cout << "destination: " << mall->R[i]->destination.r << mall->R[i]->destination.c << mall->R[i]->destination.f << endl;
              cout << "\nRobot " << q+1 << " begins at entry location A1 at time " << mall->R[q]->starttime << endl;
              mall->R[q]->move(tptr,8,16,0); //Tells robot to start on the first tile //goes to first store

              *tptr+= num_unique_items; //robot spends one time unit in store per unique item type;

              for(i = 0; i < num_unique_items ; i++)
                {
                  cout<<"Robot is at store. Enter items to deliver followed by their counts: \n";
                  cin >> item_id >> num_items;
                  //Search the Tree for the Item_Id
                  if((item_s_result = item_tree.search(item_id)) == NULL)
                    {
                      item_tree.insert(item_id, xtemp, ytemp,ztemp, num_items);
                    }
                    else{
                      item_s_result->store_list.insert(xtemp,ytemp,ztemp,num_items);
                      //Add the New Store Location to the Linked List
                    }
                  //If it returns null, then add a new ID to the tree
                  //Else get add an entry for the store on the ID's linked list
                  cout << "Item ID: " + item_id << "    Number of Items: " << num_items << endl;
                }
            //continue;
			         // cout << "Last location: " << rb.lloc.r << " " << rb.lloc.c << " " << rb.lloc.f << endl;
        }//end if


         else if(p==snum[q]) //Final pass for a robot, when it goes back to the A1 position, to end it's simulation
            {
              struct coord storetemp = {8,16,0}; //To go back to A1 tile
              mall->R[q]->destination = storetemp;


              cout << "\nNew location set to (" << mall->R[q]->lloc.r << "," << mall->R[q]->lloc.c << "," << mall->R[q]->lloc.f << ")";
              mall->R[q]->move(tptr,mall->R[q]->lloc.r,mall->R[q]->lloc.c,mall->R[q]->lloc.f);
              cout << "\nRobot " << q+1 << " exits simulation at position A1 at time " << *tptr << endl;
              mall->R[q]->endtime = *tptr; //End time is the time when the robot reaches back to A1

			       //cout << "Last location: " << rb.lloc.r << " " << rb.lloc.c << " " << rb.lloc.f << endl;

            }//end else if

         else //All other passes for the robot, when it travels between stores
            {
              cout << "\nEnter coordinates for the stores robot " << q+1 << " will visit: ";
              cin>>xtemp>>ytemp>>ztemp;
              struct coord storetemp = {xtemp,ytemp,ztemp}; //Store coordinates to be visited
              mall->R[q]->destination = storetemp;

              cout << "Enter Number of Items for this Store: " << endl;
              cin >> num_unique_items;
              cout << "Store Location: " <<xtemp << " " << ytemp << " " << ztemp << "    Number of Items to be Read In: " << num_unique_items << endl;


              mall->R[q]->move(tptr,mall->R[q]->lloc.r,mall->R[q]->lloc.c,mall->R[q]->lloc.f);
			        //cout << "Last location: " << rb.lloc.r << " " << rb.lloc.c << " " << rb.lloc.f << endl;

              *tptr+= num_unique_items; //robot spends one time unit in store per unique item type;

              for(i = 0; i < num_unique_items ; i++)
              {
                cout<<"Robot is at store. Enter items to deliver followed by their counts: \n";
                cin >> item_id >> num_items;
                //Search the Tree for the Item_Id
                if((item_s_result = item_tree.search(item_id)) == NULL)
                {

                item_tree.insert(item_id, xtemp, ytemp, ztemp, num_items);
                }
              else
              {
                item_s_result->store_list.insert(xtemp, ytemp, ztemp, num_items);
                //Add the New Store Location to the Linked List
              }
              //If it returns null, then add a new ID to the tree
              //Else get add an entry for the store on the ID's linked list
              cout << "Item ID: " + item_id << "    Number of Items: " << num_items << endl;
              }

          }//end else

        (*tptr)+=1;

        // p++; //update p value
        // cout<<"No. of stores: "<<snum[q]<<" value of p varibale now: "<<p<<endl;

      }//end while loop for stores

      //  mall->R[i]->starttime=(mall->R[i-1]->endtime)+1; //Sets start time of next robot as end time of previous robot + 1 time unit
      // q++; //update q value
      cout<<"Value of q variable now: "<<q<<endl;
  } // while loop for robots



  // //Printing summary
  //   cout << "Summary of robot movememnt in mall" << endl;
  //   for(i=0;i<rnum;i++)
  //   cout << "\nRobot " << 1+i << " starts at " << mall->R[i]->starttime << " time units and ends at " << mall->R[i]->endtime << " time units\n";


  //Now, print database after robot has finished dropping off items
  cout<<"Print database: "<<endl;
  item_tree.print_tree();

cout<<"\n Stage 1 ends here\n";
//STAGE 1 ENDS HERE
  cout<<endl<<endl<<endl;

// //Author of Stage 2: Marco Duran
// cout << "Stage 2 \n";
//
// 	EventList database;
// 	Shopper s;
// 	Queue itinerary;
// 	i = 0;
// 	int arr_time; // the relative arrival time of the ith shopper to the simulation
// 	int j_items; // is the number of unique items on the ith shopper's shopping list
// 	string item; // is the 2 digit ASCII code for the jth item on the shopping list
// 	int count; // is the quantity of item that the shopper wants to buy
// 	int shoppers; //number of shoppers that are in the mall
// 	Store store;
// 	cout <<"Insert the number of shoppers that will be in the robomall";
// 	cin >> shoppers;
//
//
// 	while( i < shoppers)
// {//runs the loop until the amount of shoppers is reached
// 	cout << "Insert the arrival time of shopper" << i+1 << endl;
// 	cin >> arr_time;
// 	cout << "\nInsert the number of items on the shopping list" << endl;
// 	cin >> j_items;
//
// 	for(int j = 0; j < j_items; j++)
// 	{
// 		cin >> item >> count;
// 		cout <<"[DEBUG] Item code: " << item << " " << "ItemCount: " << count;
// 		if(s.searchItem(database, store) == true)
// 		store = database.rootPtr->store;
//
// 		if(s.searchItem(database, store) == false){ //searches for the item in the database
// 			s.deleteItem(itinerary.headPtr, itinerary.tailPtr);//if not found it deletes the item from the queue
// 		}
// 		else{
// 			s.addStore(store, itinerary, database);
// 		}
// 	}
//
// }



return 0;
}
