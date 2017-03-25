/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  1/23/2016                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 1: tlist.h

Description: Opens a file "myData.txt" and reads and stores the information into a dynamic string array called DB. Allows 5 choices
to be performed by the user: Display contents of the array to the screen, add a new entry, remove an entry, search for an entry, 
or exit the program. Each time a function is invoked it states that it has been invoked and if the array becomes full the size
is doubled.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#ifndef TLIST_H
#define TLIST_H


#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class tlist
{
public:
		tlist(); //default constructor sets the following: count = 0, capacity = //12, and allocates memory the size of string[capacity]
		~tlist(); //destructor
		bool Is_Full(); //return true if full otherwise false
		bool Is_Empty(); // return true if empty otherwise false
		int Search(const string &key);//returns location if item in list; otherwise return -1
		void Insert(const string & key); //add key to dynamic array if not full, otherwise doubles the size of the array and adds key
		void Remove(const string & key); //removes key from dynamic array if it is there, otherwise prints a message stating it was not in dynamic array
		void Display(); //displays the contents of the dynamic array, other functions may be implemented if necessary
		void Double_Size(); //Doubles the size of the array
		void Choice(tlist &myClass); //Gives choices for what to do
private:
	string *DB; //dynamic array
	int count; //number of strings stored in the dynamic array
	int capacity; //total number of cells in the dynamic array
};
#endif