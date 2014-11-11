
#include "globals.h"
#include "mall.h"

//Author: Himanshu Sahay
#include <iostream>
using namespace std;

//Author: Himanshu Sahay
Robot::Robot(int robotnum) //constructor
{
	destination.r = -1;
	destination.c = -1;
	destination.f = -1; //invalid destination
	lloc.r = -1; //invalid last location
	lloc.c = -1;
	lloc.f = -1;
	rnum = robotnum;
	checkIfInMall =false; //set to true when robot enters mall
}

//Author: Himanshu Sahay
void Robot::move(int *tptr, int x, int y, int z) //Inputs current square postion
{

	if(checkIfInMall == true)
	{
//	cout << "Time: "<< *tptr << endl;

	//struct sqr fl[FLOORSIDE][FLOORSIDE][FLOORNUM]; //initializeing the structure of arrays (extern given in header)

  /*Enter mall at A1 on first floor.
    Goes north.
    Checks at every tile if it is a fork. If tile is not a fork, the robot keeps going.
    If the current tile is a fork, it checks what is the best path to take in order to reach the destination
    If the current coordinates match destination coordinates, it says that you have reached the desired store and moves on to the next store.

  */


//cout<<"1st destination show inside move function: "<<(rptr->destination).r<<" "<<(rptr->destination).c<<" "<<(rptr->destination).f<<endl;

//Initializes variables with coordinates of store that the robot is going to
int xtarget=destination.r;
int ytarget=destination.c;
int ztarget=destination.f;

/*Stores current location as last location at each step.
If store is reached, last locaion of previous iteration is used so that the robot can move back out of the store*/
if((fl[x][y][z]).type!=Store)
  {
  	//cout<<"Printing inside last location if statement: Last location: "<<x<<" "<<y<<" "<<z<<" and "<<temp.r<<" "<<temp.c<<" "<<temp.f<<endl;
  lloc.r = x;
	lloc.c = y;
	lloc.f = z;
  }

//cout<<"Last location: %d,%d,%d\n",(rptr->lloc).r,(rptr->lloc).c,(rptr->lloc).f);
cout<<"Time "<<(*tptr)<<"\tLocation ("<<x<<","<<y<<","<<z<<")\n";

//---------------------------------------------------------------------------------------------
  //Debug statements
  //cout<<"Position: %d %d %d\n",x,y,z);
  //cout<<"Direction: %d\n",fl[x][y][z].direction);

//Switches over robot type to facilitate robot movement
  switch((fl[x][y][z]).type)
  {
    case A1:
		cout<<"Type is: A1"<<endl;

    if(*tptr%25==0) //Prints current floor map every 5 time units
      {
		  cout<<"Time is: "<<*tptr;
        //cout<<"Current floor map\n\n";
        //Printing current floor map
        	//printcurrent(x,y,z);
      }
    if(x==xtarget && y==ytarget && z==ztarget)
      {
        return; //Ends robot movement and returns time taken in journey
      }

    else
      {
        *tptr+=1; //Time is incremented at each step by 1 unit
        move(tptr,x-1,y,z);
      }

    break;

    case Plain:
		cout<<"Plain tile"<<endl;
    if(*tptr%25==0) //Prints current floor map every 5 time units
      {
        ////cout<<"Current floor map\n";
        //Printing current floor map
      //printcurrent(x,y,z);
      }
    {
      *tptr+=1; //Time is incremented at each step by 1 unit
      switch((fl[x][y][z]).direction)
        {
          case North: //North
          x--;
          move(tptr,x,y,z);
          break;

          case NorthWest: //NorthWest
          x--;
          y--;
          move(tptr,x,y,z);
          break;

          case West: //West
          y--;
          move(tptr,x,y,z);
          break;

          case SouthWest: //SouthWest
          x++;
          y--;
          move(tptr,x,y,z);
          break;

          case South: //South
          x++;
          move(tptr,x,y,z);
          break;

          case SouthEast: //SouthEast
          x++;
          y++;
          move(tptr,x,y,z);
          break;

          case East: //East
          y++;
          move(tptr,x,y,z);
          break;

          case NorthEast: //NorthEast
          x--;
          y++;
          move(tptr,x,y,z);
          break;

          default: break;
        }
      }
      break;

      case Store: //Switch over direction to move form store

      if(*tptr%25==0) //Prints current floor map every 5 time units
        {
          //cout<<"Current floor map\n";
          //Printing current floor map
        //printcurrent(x,y,z);
        }
        cout<<"\nRobot reached store ("<<x<<","<<y<<","<<z<<") at time "<<*tptr<<endl;

        *tptr+=1; //Time is incremented by 1 unit extra for stores

		if(ztarget==1)
          {
            *tptr+=1; //Spends 1 time unit more on a second floor store than on a first floor store
          }
          return; //Returns from function if destination reached.

      break;

  //WORK ON ELEVATOR
      case Elevator:

      if(*tptr%25==0) //Prints current floor map every 5 time units
        {
          //cout<<"Current floor map\n";
          //Printing current floor map
      //  printcurrent(x,y,z);
        }

    if(ztarget==0) //Checks if target floor is first floor
      {
        if(z==1) //Checks if robot is currently on the second floor
          {
            cout<<"\nRobot got on the elevator at time: "<<*tptr<<endl;
            cout<<"\nRobot got off the elevator at time: "<<*tptr+3<<endl;
            z--;
          *tptr+=4; //3 time units in the elevator and 1 time unit to get off the elevator
        if(xtarget>10 && ytarget>5)
          {
            x++;
            move(tptr,x,y,z);
          }
        else
          {
            y++;
            move(tptr,x,y,z);
          }
        }
        else //Robot is already on the first floor and destination is also on first floor
          {
              if(xtarget>10 && ytarget>5)
                {
                  x++;
                  move(tptr,x,y,z);
                }
              else
                {
                  y++;
                  move(tptr,x,y,z);
                }
          }
        }
      else //Target floor is the second floor
      {
        if(z==0) //Checks if robot is currently on the first floor
      {
        z=1;
        cout<<"\nRobot got on the elevator at time: "<<*tptr<<endl;
        cout<<"\nRobot got off the elevator at time: "<<*tptr+3<<endl;
        *tptr+=4; //3 time units in the elevator and 1 time unit to get off the elevator
        if(xtarget<11 && ytarget<5)
          {
            y--;
            move(tptr,x,y,z);
          }
        else
          {
            x--;
            move(tptr,x,y,z);
          }
        }
      else //Robot is already on the seond floor and destination is also on the second floor
      {
        if(xtarget<11 && ytarget<5)
          {
            y--;
            move(tptr,x,y,z);
          }
        else
          {
            x--;
            move(tptr,x,y,z);
          }
        }

      }
      *tptr+=1; //Time is incremented at each step by 1 unit
      break; //Universal break for entire case Elevator:

        case Fork:

        if(*tptr%25==0) //Prints current floor map every 5 time units
          {
            //cout<<"Current floor map\n";
            //Printing current floor map
        //  printcurrent(x,y,z);
          }
        *tptr+=1; //Time is incremented at each step by 1 unit
        cout<<"\nRobot has reached fork "<<fl[x][y][z].forkid<<endl;

        switch(fl[x][y][z].forkid)
        {
          case 1:
            if(xtarget==4 && ytarget==12 && ztarget==0)
              {
                x++;
                y--;
                move(tptr,x,y,z); //Goes to store
              }
            else

              {
                x--;
                y--;
                move(tptr,x,y,z);
              }
            break;

          case 2:

            if(ytarget<6 && ztarget==0) //Destination store has y<6
              {
                y--;
                move(tptr,x,y,z);
              }
            else
              {
                x++;
                move(tptr,x,y,z);
              }
            break;

          case 3:
            if(xtarget==4 && ytarget==4 && ztarget==0)
              {
                x++;
                y++;
                move(tptr,x,y,z);
              }
            else
              {
                x++;
                y--;
                move(tptr,x,y,z);
              }
            break;

          case 4:
            if(!((xtarget==12 && ytarget==4 && ztarget==0)||(xtarget==12 && ytarget==12 && ztarget==0)))
              {
                y++;
                move(tptr,x,y,z);
              }
            else
              {
                x++;
                move(tptr,x,y,z);
              }
            break;

          case 5:
            if(xtarget==12 && ytarget==4 && ztarget==0)
              {
                x--;
                y++;
                move(tptr,x,y,z);
              }
            else
              {
                x++;
                y++;
                move(tptr,x,y,z);
              }
            break;

          case 6:
            if(xtarget==12 && ytarget==12 && ztarget==0)
              {
                x--;
                y--;
                move(tptr,x,y,z);
              }
            else
              {
                x--;
                y++;
                move(tptr,x,y,z);
              }
            break;

          case 7:
            if(xtarget==4 && ytarget==6 && ztarget==0)
              {
                y--;
                move(tptr,x,y,z); //Goes to left store
              }
            else if(xtarget==4 && ytarget==10 && ztarget==0)
              {
                y++;
                move(tptr,x,y,z);
              }
            else
              {
                x++;
                move(tptr,x,y,z);
              }
            break;

          case 8:
            if(xtarget==12 && ytarget==6 && ztarget==0)
              {
                y--;
                move(tptr,x,y,z);
              }
            else if(xtarget==12 && ytarget==10 && ztarget==0)
              {
                y++;
                move(tptr,x,y,z);
              }
            else
              {
                x++;
                move(tptr,x,y,z);
              }
            break;

          case 9:
            if(xtarget==6 && ytarget==4 && ztarget==0)
              {
                x--;
                move(tptr,x,y,z);
              }
            else if(xtarget==10 && ytarget==4 && ztarget==0)
              {
                x++;
                move(tptr,x,y,z);
              }
            else
              {
                y++;
                move(tptr,x,y,z);
              }
            break;

          case 10:
            if(xtarget==6 && ytarget==12 && ztarget==0)
              {
                x--;
                move(tptr,x,y,z);
              }
            else if(xtarget==10 && ytarget==12 && ztarget==0)
              {
                x++;
                move(tptr,x,y,z);
              }
            else
              {
                y++;
                move(tptr,x,y,z);
              }
            break;

          case 11:
            if(xtarget==4 && ytarget==6 && ztarget==0)
              {
                y--;
                move(tptr,x,y,z);
              }
            else
              {
                y++;
                move(tptr,x,y,z);
              }
            break;

          case 12:
            if(xtarget==4 && ytarget==10 && ztarget==0)
              {
                y++;
                move(tptr,x,y,z);
              }
            else
              {
                y--;
                move(tptr,x,y,z);
              }
            break;

          case 13:
            if(xtarget==12 && ytarget==6 && ztarget==0)
              {
                y--;
                move(tptr,x,y,z);
              }
            else
              {
                y++;
                move(tptr,x,y,z);
              }
            break;

          case 14:
            if(xtarget==12 && ytarget==10 && ztarget==0)
              {
                y++;
                move(tptr,x,y,z);
              }
            else
              {
                y--;
                move(tptr,x,y,z);
              }
            break;

          case 15:
            if(xtarget==6 && ytarget==4 && ztarget==0)
              {
                x--;
                move(tptr,x,y,z);
              }
            else
              {
                x++;
                move(tptr,x,y,z);
              }
            break;

          case 16:
            if(xtarget==10 && ytarget==4 && ztarget==0)
              {
                x++;
                move(tptr,x,y,z);
              }
            else
              {
                x--;
                move(tptr,x,y,z);
              }
            break;

          case 17:
            if(xtarget==6 && ytarget==12 && ztarget==0)
              {
                x--;
                move(tptr,x,y,z);
              }
            else
              {
                x++;
                move(tptr,x,y,z);
              }
            break;

          case 18:
            if(xtarget==10 && ytarget==12 && ztarget==0)
              {
                x++;
                move(tptr,x,y,z);
              }
            else
              {
                x--;
                move(tptr,x,y,z);
              }
            break;

          case 19:
            if(xtarget==4 && ytarget==12 && ztarget==1)
              {
                x++;
                y--;
                move(tptr,x,y,z);
              }
            else
              {
                x++;
                y++;
                move(tptr,x,y,z);
              }
            break;

          case 20:
            if(xtarget==4 && ytarget==4 && ztarget==1)
              {
                x++;
                y++;
                move(tptr,x,y,z);
              }
            else //floor 1 case included
              {
                x--;
                y++;
                move(tptr,x,y,z);
              }
            break;

          case 21:
            if(xtarget==12 && ytarget==4 && ztarget==1)
              {
                x--;
                y++;
                move(tptr,x,y,z);
              }
            else //floor 1 case included
             {
               x--;
               y--;
               move(tptr,x,y,z);
             }
            break;

          case 22:
            if((xtarget==12 && ytarget==4 && ztarget==1)||(xtarget==4 && ytarget==4 && ztarget==1))
              {
                y--;
                move(tptr,x,y,z);
              }
            else //floor 1 case included
              {
                x--;
                move(tptr,x,y,z);
              }
            break;

          case 23:
            if(xtarget==12 && ytarget==12 && ztarget==1)
              {
                x--;
                y--;
                move(tptr,x,y,z);
              }
            else //floor 1 case included
              {
                x++;
                y--;
                move(tptr,x,y,z);
              }
            break;

          case 24:
            if(xtarget>10 && ztarget==1)
              {
                x++;
                move(tptr,x,y,z);
              }
            else //floor 1 case included
              {
                y--;
                move(tptr,x,y,z);
              }
            break;

          case 25:
            if(xtarget==4 && ytarget==6 && ztarget==1)
              {
                y--;
                move(tptr,x,y,z);
              }
            else if(xtarget==4 && ytarget==10 && ztarget==1)
              {
                y++;
                move(tptr,x,y,z);
              }
            else
              {
                x--;
                move(tptr,x,y,z);
              }
            break;

          case 26:

              if(xtarget==12 && ytarget==6 && ztarget==1)
                {
                  y--;
                  move(tptr,x,y,z);
                }
              else if(xtarget==12 && ytarget==10 && ztarget==1)
                {
                  y++;
                  move(tptr,x,y,z);
                }
              else
                {
                  x--;
                  move(tptr,x,y,z);
                }
              break;

            case 27:
                if(xtarget==6 && ytarget==4 && ztarget==1)
                  {
                    x--;
                    move(tptr,x,y,z);
                  }
                else if(xtarget==10 && ytarget==4 && ztarget==1)
                  {
                    x++;
                    move(tptr,x,y,z);
                  }
                else
                  {
                    y--;
                    move(tptr,x,y,z);
                  }
                break;

              case 28:

                  if(xtarget==6 && ytarget==12 && ztarget==1)
                    {
                      x--;
                      move(tptr,x,y,z);
                    }
                  else if(xtarget==10 && ytarget==12 && ztarget==1)
                    {
                      x++;
                      move(tptr,x,y,z);
                    }
                  else
                    {
                      y--;
                      move(tptr,x,y,z);
                    }
                  break;

                case 29:
                  if(xtarget==4 && ytarget==6 && ztarget==1)
                    {
                      y--;
                      move(tptr,x,y,z);
                    }
                  else
                    {
                      y++;
                      move(tptr,x,y,z);
                    }
                  break;

                case 30:
                  if(xtarget==4 && ytarget==10 && ztarget==1)
                    {
                      y++;
                      move(tptr,x,y,z);
                    }
                  else
                    {
                      y--;
                      move(tptr,x,y,z);
                    }
                  break;

                case 31:
                  if(xtarget==12 && ytarget==6 && ztarget==1)
                    {
                      y--;
                      move(tptr,x,y,z);
                    }
                  else
                    {
                      y++;
                      move(tptr,x,y,z);
                    }
                  break;

                case 32:
                  if(xtarget==12 && ytarget==10 && ztarget==1)
                    {
                      y++;
                      move(tptr,x,y,z);
                    }
                  else
                    {
                      y--;
                      move(tptr,x,y,z);
                    }
                  break;
                case 33:
                  if(xtarget==6 && ytarget==4 && ztarget==1)
                    {
                      x--;
                      move(tptr,x,y,z);
                    }
                  else
                    {
                      x++;
                      move(tptr,x,y,z);
                    }
                  break;

                case 34:
                  if(xtarget==10 && ytarget==4 && ztarget==1)
                    {
                      x++;;
                      move(tptr,x,y,z);
                    }
                  else
                    {
                      x--;
                      move(tptr,x,y,z);
                    }
                  break;

                case 35:
                  if(xtarget==6 && ytarget==12 && ztarget==1)
                    {
                      x--;
                      move(tptr,x,y,z);
                    }
                  else
                    {
                      x++;
                      move(tptr,x,y,z);
                    }
                  break;

                case 36:
                  if(xtarget==10 && ytarget==12 && ztarget==1)
                    {
                      x++;
                      move(tptr,x,y,z);
                    }
                  else
                    {
                      x--;
                      move(tptr,x,y,z);
                    }
                  break;

          default: cout<<"ERROR! ERROR! ERROR!"<<endl;
        }
      break;

    case Empty: cout<<"CASE EMPTY"<<endl;
    break;

    default: cout<<"INVALID TILE"<<endl; //for both default and Empty

  	}
	}
}
