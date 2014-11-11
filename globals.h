//Author: Himanshu Sahay

#pragma once

#ifdef __MAIN__
    #define __EXTERN(type, name, value)     type name = value
#else
    #define __EXTERN(type, name, value)     extern type name;
#endif

#ifndef GLOBALS_H
#define GLOBALS_H

enum direction{North, NorthWest, West, SouthWest, South, SouthEast, East, NorthEast, Up, Down};
enum type{A1,Store,Elevator,Plain,Fork,Empty};

//Author: Himanshu Sahay
struct sqr
{
  int direction;
  int type; //type is S for store, E for elevator, T is for regular tiles, A for A1, and N for everything else (For now, unless more types used)
  int forkid; //ID for deducing which direction to take at a fork. 0 for tiles that aren't forks. 1/2/..and so on for tiles that are forks in the path
  //Fork ID = 0 and type = Empty clears the floor before we operate on it.
  int storeid; //if not store, id = 0. Else, ID ordered by store
};

//Author: Himanshu Sahay
struct coord
{
  int r;
  int c;
  int f;
};


__EXTERN(struct sqr, fl[17][17][2], {}); //initializeing the structure of arrays


//Robot structure and initialization of new robot

/*
struct robot
{
  // x, y and z cooridnates of each destination (store or A1 when exiting the mall)
  struct coord destination;
  int rnum;
  struct coord lloc; //last location of robot, used to call function in hsahay_main.c

};




void move(struct robot *rptr, int *tptr, int x, int y, int z); //function to move



void floormap(); //global function to initialize floor map
*/


#endif
