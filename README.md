Author: Himanshu Sahay
Language: C++

The executable file is robotdeliveriesinmall

The program is implemented as such:
- There is a class Robot for the robots that deliver goods to stores. 
- There is a wrapper class Mall which contains pointers to robots and the floor map of the mall.
- There is a function motion.cpp while includes robot.h. It has the constructor for robot and the function to move a robot. 
- A robot moves step by step and calls the move function in motion.cpp recursively.
- The first call to the move function is made in hsahay_main.cpp where it is called when a store location is given to it. 
- The robot deliveries database is built via a binary tree for the items and a linked list of stores at each item (node of the binary tree)
- Once a robot reahces a store, it is asked to input the items for that store. These instructions are given via on screen commands. 
- The database is updated at each instance of a robot going to a store. 
-------------------------------------------------------------------------------------------------------------------
How this works: 
- The main function takes user input (on screen commands).
- It asks for number of robots, number of stores for each robot, number of unique items, item codes and their counts.
- Calls are made to the move function. The item database is also updated.
- Finally, the program ends after printing the item database. 
-------------------------------------------------------------------------------------------------------------------
The Makefile contains all the compiler commands to compile, link and load (by creating .o files) and then execute.

Sincerely,
Himanshu Sahay
-------------------------------------------------------------------------------------------------------------------
