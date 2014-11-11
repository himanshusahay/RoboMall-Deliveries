//Authot: Himanshu Sahay

#include "globals.h"

#ifndef ROBOT_H
#define ROBOT_H

//Author: Himanshu Sahay
class Robot
{
  public:
  bool checkIfInMall; //set to true when robot enters mall. Only move robot if this is true.
  struct coord destination;
  struct coord lloc; //last location - to get out of store
  int rnum; //robot number - only for printing purposes in main


  // Store num didn't work int snum; //max number of stores per robot = 24


  int starttime; //start and end times of robot simulation
  int endtime;
  Robot(int robotnum); //constructor
  ~Robot(); //destructor
  //function to move robot
  void move(int *tptr, int x, int y, int z); //takes in x,y,z location and takes in pointer to the location

};


#endif
