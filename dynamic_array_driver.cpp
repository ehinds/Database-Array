/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  1/23/2016                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 1: dynamic_array_driver.cpp

Description: Opens a file "myData.txt" and reads and stores the information into a dynamic string array called DB. Allows 5 choices
to be performed by the user: Display contents of the array to the screen, add a new entry, remove an entry, search for an entry, 
or exit the program. Each time a function is invoked it states that it has been invoked and if the array becomes full the size
is doubled.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#include "tlist.h"

int main()
{
	tlist myClass;
	myClass.Choice(myClass);

	return 0;
}