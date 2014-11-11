// Author: Himanshu Sahay
#define __MAIN__
#include "globals.h"
#include "mall.h"

#include <iostream>
using namespace std;

//TO DO: ASSIGN STORE IDs LATER

//Author: Himanshu Sahay
Mall::Mall()
{
  for(int i = 0; i<9; i++)
  R[i] = new Robot(i+1);
floormap();

}

//Author: Himanshu Sahay
/*void printcurrent(Robot *R)
  {
    //struct sqr fl[FLOORSIDE][FLOORSIDE][FLOORNUM]; //initializing the structure of arrays (extern given in header)

    int i,j,k;
  for(k=0;k<2;k++)
  {
    cout<<"Floor "<<k+1<<endl;
    cout<<"-------------------------------------\n"; //Top border
    for(i=0;i<17;i++)
  { cout<<"| "; //Left side border
    for(j=0;j<17;j++)
      {

        if(i==(R->lloc).x && j==(R->lloc).y && k==(R->lloc).z)  //CHECK THIS
          {
            cout<<"* ";
          }
        else
          {
        //cout<<"(%d, %d, %d): type %d\n", i,j,0,(fl[i][j][0]).type);
        switch(fl[i][j][k].type)
        {
          case Empty: cout<<"  ";
          break;

          case A1: cout<<"A1";
          break;

          case Store: cout<<"S ";
          break;

          case Elevator: cout<<"E ";
          break;

          case Plain: cout<<"P ";
          break;

          case Fork: cout<<"F ";
          break;

          default: cout<<"!!";
        }
      }
    }

      cout<<"|\n"; //Right side border
    }
    cout<<"-------------------------------------\n"; //Bottom border
  }
}
*/

//Author: Himanshu Sahay
void Mall::floormap()
{
int i,j,k; //Arbitrary  variables to be used in for loops
//struct sqr fl[17][17][2]; //initializeing the structure of arrays (extern given in header)



//Assigning types to every tile

for(i=0;i<2;i++)
  {
    for(j=0;j<17;j++)
      {
        for(k=0;k<17;k++)
          {
            (fl[j][k][i]).type = Empty;
            (fl[j][k][i]).forkid = 0;
          }
      }
  }


// Set structs for stores
for(i=0;i<2;i++)
{
  (fl[4][4][i]).type = Store;
  (fl[4][6][i]).type = Store;
  (fl[4][10][i]).type = Store;
  (fl[4][12][i]).type = Store;
  (fl[6][4][i]).type = Store;
  (fl[6][12][i]).type = Store;
  (fl[10][4][i]).type = Store;
  (fl[12][6][i]).type = Store;
  (fl[12][10][i]).type = Store;
  (fl[10][12][i]).type = Store;
  (fl[12][4][i]).type = Store;
  (fl[12][12][i]).type = Store;

}

(fl[4][4][0]).direction = NorthWest;
(fl[4][6][0]).direction = East;
(fl[4][10][0]).direction = West;
(fl[4][12][0]).direction = NorthEast;
(fl[6][4][0]).direction = South;
(fl[6][12][0]).direction = South;
(fl[10][12][0]).direction = North;
(fl[10][4][0]).direction = North;
(fl[12][6][0]).direction = East;
(fl[12][10][0]).direction = West;
(fl[12][4][0]).direction = SouthWest;
(fl[12][12][0]).direction = SouthEast;


(fl[4][4][1]).direction = NorthWest;
(fl[4][6][1]).direction = East;
(fl[4][10][1]).direction = West;
(fl[4][12][1]).direction = NorthEast;
(fl[6][4][1]).direction = South;
(fl[6][12][1]).direction = South;
(fl[10][12][1]).direction = North;
(fl[10][4][1]).direction = North;
(fl[12][6][1]).direction = East;
(fl[12][10][1]).direction = West;
(fl[12][4][1]).direction = SouthWest;
(fl[12][12][1]).direction = SouthEast;



// Set structs for plain tiles
for(i=0;i<2;i++)
{
 for(j=6;j<=10;j++)
 {
 if(j!=8 && i!=0)
  (fl[0][j][i]).type=Plain; //Top 6 blocks

 if(j!=8 && i!=1)
  (fl[16][j][i]).type=Plain; //Bottom 6 blocks

 if(j!=8 && i!=0)
  (fl[j][0][i]).type=Plain; //Left 6 blocks

 if(j!=8) //8 16 0 is A1 and 8 16 1 is fork
  (fl[j][16][i]).type=Plain; //Right 6 blocks
 }


 for(j=0;j<17;j++)
 {
  if(j!=8 || j!=0 && i!=0 || j!=16 && i!=1)
   (fl[j][8][i]).type=Plain; //Middle long row - vertical

  if(j!=16 || j!=8 || j!=0 && i!=0)
   (fl[8][j][i]).type=Plain; //Middle long row - column
 }

  //Top left diagonal
 (fl[1][5][i]).type=Plain;
 (fl[2][4][i]).type=Plain;
 //(fl[3][3][i]).type=Plain;
 (fl[4][2][i]).type=Plain;
 (fl[5][1][i]).type=Plain;

(fl[0][6][0]).type = Plain;
(fl[0][7][0]).type = Plain;
(fl[0][9][0]).type = Plain;
(fl[0][10][0]).type = Plain;
(fl[6][0][0]).type = Plain;
(fl[7][0][0]).type = Plain;
(fl[9][0][0]).type = Plain;
(fl[10][0][0]).type = Plain;
(fl[16][6][1]).type = Plain;
(fl[16][7][1]).type = Plain;
(fl[16][9][1]).type = Plain;
(fl[16][10][1]).type = Plain;






 //Top right diagonal
 (fl[1][11][i]).type=Plain;
 (fl[2][12][i]).type=Plain;
 //(fl[3][13][i]).type=Plain;
 (fl[4][14][i]).type=Plain;
 (fl[5][15][i]).type=Plain;

 //Bottom left diagonal
 (fl[11][1][i]).type=Plain;
 (fl[12][2][i]).type=Plain;
 //(fl[13][3][i]).type=Plain;
 (fl[14][4][i]).type=Plain;
 (fl[15][5][i]).type=Plain;

 //Bottom right diagonal
 (fl[11][15][i]).type=Plain;
 (fl[12][14][i]).type=Plain;
 //(fl[13][13][i]).type=Plain;
 (fl[14][12][i]).type=Plain;
 (fl[15][11][i]).type=Plain;

}
 /*Assigning Directions*/


 //!!! - Do Tiles that do 2 directions (Currently they are coded on only 1 direction)
 //Update: There pdirections are changed ahead
 //Tiles going East only
 for(i=1;i<16;i++)
  {
     if(i!=0 || i!=8)
	 (fl[8][i][0]).direction = East;
  }

  for(i=6;i<10;i++)
    {

     (fl[0][i][1]).direction = East;
    }

  for(i=6;i<10;i++)
  {

    (fl[16][i][0]).direction = East;
  }

  //Tiles going North only
  for(i=10;i>6;i--)
  {//A1 goes only north as well
    (fl[i][16][0]).direction = North;
  }

  for(i=10;i>6;i--)
    {
	//no fork on this side on second floor
      (fl[i][0][1]).direction = North;
    }

  for(i=1;i<16;i++)
    {
		if(i!=8)
      (fl[i][8][1]).direction = North;
    }

  //Tiles going West only
  for(i=10;i>6;i--)
  {
	  if(i!=8)
    (fl[0][i][0]).direction = West;
  }

  for(i=1;i<16;i++)
    {
	if(i!=8)
      (fl[8][i][1]).direction = West;
    }
  for(i=10;i>6;i--)
    {
		if(i!=8)
      (fl[16][i][1]).direction = West;
    }

  //Tiles going South only
  for(i=1;i<16;i++)
   {
	if(i!=8)
     (fl[i][8][0]).direction = South;
   }

   for(i=6;i<10;i++)
   {
	   if(i!=8)
     (fl[i][0][0]).direction = South;
   }

   for(i=6;i<10;i++)
    {
		if(i!=8)
     (fl[i][16][1]).direction = South;
    }

  //Tiles going North East
  (fl[11][15][0]).direction=NorthEast;
  (fl[12][14][0]).direction=NorthEast;
  (fl[14][12][0]).direction=NorthEast;
  (fl[15][11][0]).direction=NorthEast;
  (fl[16][10][0]).direction=NorthEast;

  //Tiles going South West
  (fl[10][16][1]).direction=SouthWest;
  (fl[11][15][1]).direction=SouthWest;
  (fl[12][14][1]).direction=SouthWest;
  (fl[14][12][1]).direction=SouthWest;
  (fl[15][11][1]).direction=SouthWest;

  //Tiles going South East
  (fl[10][0][0]).direction=SouthEast;
  (fl[11][1][0]).direction=SouthEast;
  (fl[12][2][0]).direction=SouthEast;
  (fl[14][4][0]).direction=SouthEast;
  (fl[15][5][0]).direction=SouthEast;

  //Tiles going North West
  (fl[11][1][1]).direction=NorthWest;
  (fl[12][2][1]).direction=NorthWest;
  (fl[14][4][1]).direction=NorthWest;
  (fl[15][5][1]).direction=NorthWest;
  (fl[16][6][1]).direction=NorthWest;

  //Tiles going North West
  (fl[1][11][0]).direction=NorthWest;
  (fl[2][12][0]).direction=NorthWest;
  (fl[4][14][0]).direction=NorthWest;
  (fl[5][15][0]).direction=NorthWest;
  (fl[6][16][0]).direction=NorthWest;

  //Tiles going South East
  (fl[0][10][1]).direction=SouthEast;
  (fl[1][11][1]).direction=SouthEast;
  (fl[2][12][1]).direction=SouthEast;
  (fl[4][14][1]).direction=SouthEast;
  (fl[5][15][1]).direction=SouthEast;

  //Tiles going SouthWest
  (fl[0][6][0]).direction=SouthWest;
  (fl[1][5][0]).direction=SouthWest;
  (fl[2][4][0]).direction=SouthWest;
  (fl[4][2][0]).direction=SouthWest;
  (fl[5][1][0]).direction=SouthWest;


  //Tiles going North East
  (fl[1][5][1]).direction=NorthEast;
  (fl[2][4][1]).direction=NorthEast;
  (fl[4][2][1]).direction=NorthEast;
  (fl[5][1][1]).direction=NorthEast;
  (fl[6][0][1]).direction=NorthEast;


//-------------------------------------------------------------------------------

  (fl[8][8][0]).forkid = 0; //Elevator
  (fl[8][8][0]).type = Elevator;
  (fl[8][8][1]).type = Elevator;
  (fl[8][8][0]).forkid = 0; //Elevator

   // Set struct for A1 (entry tile)
(fl[8][16][0]).type =A1;

  // Assigning Fork IDs
  // Forks are positions where the robot can go in more than one direction, and it deicdes the direction based on the destination

  //First floor
  //Outer forks
  (fl[3][13][0]).forkid = 1;
  (fl[3][13][0]).type = Fork;
  (fl[0][8][0]).forkid = 2;
  (fl[0][8][0]).type = Fork;
  (fl[3][3][0]).forkid = 3;
  (fl[3][3][0]).type = Fork;
  (fl[8][0][0]).forkid = 4;
  (fl[8][0][0]).type = Fork;
  (fl[13][3][0]).forkid = 5;
  (fl[13][3][0]).type = Fork;
  (fl[13][13][0]).forkid = 6;
  (fl[13][13][0]).type = Fork;

  //Inner forks
  (fl[4][8][0]).forkid = 7;
  (fl[4][8][0]).type = Fork;
  (fl[12][8][0]).forkid = 8;
  (fl[12][8][0]).type = Fork;
  (fl[8][4][0]).forkid = 9;
  (fl[8][4][0]).type = Fork;
  (fl[8][12][0]).forkid = 10;
  (fl[8][12][0]).type = Fork;
  (fl[4][7][0]).forkid = 11;
  (fl[4][7][0]).type = Fork;
  (fl[4][9][0]).forkid = 12;
  (fl[4][9][0]).type = Fork;
  (fl[12][7][0]).forkid = 13;
  (fl[12][7][0]).type = Fork;
  (fl[12][9][0]).forkid = 14;
  (fl[12][9][0]).type = Fork;
  (fl[7][4][0]).forkid = 15;
  (fl[7][4][0]).type = Fork;
  (fl[9][4][0]).forkid = 16;
  (fl[9][4][0]).type = Fork;
  (fl[7][12][0]).forkid = 17;
  (fl[7][12][0]).type = Fork;
  (fl[9][12][0]).forkid = 18;
  (fl[9][12][0]).type = Fork;

  //Second floor
  //Outer forks
  (fl[3][13][1]).forkid = 19;
  (fl[3][13][1]).type = Fork;
  (fl[3][3][1]).forkid = 20;
  (fl[3][3][1]).type = Fork;
  (fl[13][3][1]).forkid = 21;
  (fl[13][3][1]).type = Fork;
  (fl[16][8][1]).forkid = 22;
  (fl[16][8][1]).type = Fork;
  (fl[13][13][1]).forkid = 23;
  (fl[13][13][1]).type = Fork;
  (fl[8][16][1]).forkid = 24;
  (fl[8][16][1]).type = Fork;

  //Inner forks
  (fl[4][8][1]).forkid = 25;
  (fl[4][8][1]).type = Fork;
  (fl[12][8][1]).forkid = 26;
  (fl[12][8][1]).type = Fork;
  (fl[8][4][1]).forkid = 27;
  (fl[8][4][1]).type = Fork;
  (fl[8][12][1]).forkid = 28;
  (fl[8][12][1]).type = Fork;
  (fl[4][7][1]).forkid = 29;
  (fl[4][7][1]).type = Fork;
  (fl[4][9][1]).forkid = 30;
  (fl[4][9][1]).type = Fork;
  (fl[12][7][1]).forkid = 31;
  (fl[12][7][1]).type = Fork;
  (fl[12][9][1]).forkid = 32;
  (fl[12][9][1]).type = Fork;
  (fl[7][4][1]).forkid = 33;
  (fl[7][4][1]).type = Fork;
  (fl[9][4][1]).forkid = 34;
  (fl[9][4][1]).type = Fork;
  (fl[7][12][1]).forkid = 35;
  (fl[7][12][1]).type = Fork;
  (fl[9][12][1]).forkid = 36;
  (fl[9][12][1]).type = Fork;



  //Printing first floor
  cout<<"First Floor\n";
  cout<<"-------------------------------------\n"; //Top border
  for(i=0;i<17;i++)
    { cout<<"| "; //Left side border
      for(j=0;j<17;j++)
        {
          //printf("(%d, %d, %d): type %d\n", i,j,0,(fl[i][j][0]).type);
          switch(fl[i][j][0].type)
          {
            case Empty: cout<<"  ";
            break;

            case A1: cout<<"A1";
            break;

            case Store: cout<<"S ";
            break;

            case Elevator: cout<<"E ";
            break;

            case Plain: cout<<"P ";
            break;

            case Fork: cout<<"F ";
            break;

            default: cout<<"!!!";
          }
        }

        cout<<"|\n"; //Right side border
    }
    cout<<"-------------------------------------\n"; //Bottom border

  //Printing first floor
  cout<<"Second Floor\n";
  cout<<"-------------------------------------\n"; //Top border
  for(i=0;i<17;i++)
    { cout<<"| "; //Left side border
      for(j=0;j<17;j++)
        {
          //printf("(%d, %d, %d): type %d\n", i,j,0,(fl[i][j][0]).type);
          switch(fl[i][j][1].type)
          {
            case Empty: cout<<"  ";
            break;

            case A1: cout<<"A1";
            break;

            case Store: cout<<"S ";
            break;

            case Elevator: cout<<"E ";
            break;

            case Plain: cout<<"P ";
            break;

            case Fork: cout<<"F ";
            break;

            default: cout<<"!!!";
          }
        }

        cout<<"|\n"; //Right side border
    }
    cout<<"-------------------------------------\n"; //Bottom border

}
