//motion.h
//Author: Himanshu Sahay
#ifndef MALL_H
#define MALL_H
#include "robot.h"

//Author: Himanshu Sahay
class Mall //Mall is wrapper class for robot and floor
{
  public:
    void floormap(); //sets the mall floor
    //void printcurrent(Robot *R);
    Mall(); //default constructor
    ~Mall();
    //struct sqr fl[17][17][2]; //every tile on the floor
    Robot *R[9]; //array of pointers to robots


};

#endif
