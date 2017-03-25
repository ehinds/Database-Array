/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  1/23/2016                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 1: tlist.cpp

Description: Opens a file "myData.txt" and reads and stores the information into a dynamic string array called DB. Allows 5 choices
to be performed by the user: Display contents of the array to the screen, add a new entry, remove an entry, search for an entry, 
or exit the program. Each time a function is invoked it states that it has been invoked and if the array becomes full the size
is doubled.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#include "tlist.h"

/************************************************************************************************************************************/
//Name: default constructor
//Precondition: The file has not been opened yet and variables not initialized 
//Postcondition: Opens the file and initializes variables using data from file. Calls the double array if it becomes full
//Decription: Reads the data file "myData.txt" and initializes capacity to 12 and count to 0. Informs user the default constructor is invoked.
/************************************************************************************************************************************/
tlist::tlist()
{

	cout << "Defualt Constructor Invoked \n";
	ifstream in;

	in.open("myData.txt");
	if (in.fail())
	{
		cout << "Input file did not open correctly.\n";
		exit(1);
	}

	count = 0;
	capacity = 12;
	DB = new string[capacity];
	string s;

	while (!in.eof())
	{
		in >> s;
		Insert(s);
	}

	in.close();
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: Count has not been checked to see if it equals size
//Postcondition: Count has been checked to see if it equals size
//Decription: returns true if DB is full
/*********************************************************************************************************************************/
bool tlist::Is_Full()
{
	cout << "Is_Full Invoked\n";
	return count == capacity;
}

/***********************************************************************************************************************************/
//Name: is_empty
//Precondition: Count has not been checked to see if it equals 0
//Postcondition: Count has been checked to see if it equals 0
//Decription: returns true if DB is empty
/**********************************************************************************************************************************/

bool tlist::Is_Empty()
{
	cout << "Is_Empty Invoked\n";
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: Data has not been searched for
//Postcondition: Data has been searched for and was either found or not found
//Decription: locates key in DB if it is there; otherwise -1 is returned. Says whether item is found or not
/*********************************************************************************************************************************/
int tlist::Search(const string &key)
{
	cout << "Search Invoked\n";
	for (int i = 0; i < count; i++)
	{
		if (key == DB[i])
		{
			cout << "Item Found in position " << i << " of the databse.\n";
			return i;
		}
	}

	cout << "Item Not Found\n";
	return -1;
}

/*********************************************************************************************************************************/
//Name: Insert
//Precondition: The database has not been added to
//Postcondition: Adds an entry to the database as specified by the user.
//Decription: add key to DB; if DB is full, double_size is called to increase the size of DB.
/********************************************************************************************************************************/
void tlist::Insert(const string &key)
{
	cout << "Insert Invoked\n";
	if (Is_Full())
	{
		Double_Size();
	}
	DB[count] = key;
	count++;
}

/********************************************************************************************************************************/
//Name: Remove
//Precondition: No data has been removed
//Postcondition: All data matching a specific key will be removed 
//Decription: remove all instances of key from DB if it is there.
/*******************************************************************************************************************************/
void tlist::Remove(const string &key)
{
	cout << "Remove Invoked\n";
	for (int i = 0; i <= count; i++)
	{
		if (key == DB[i])
		{
			for (int k = i; (k +1) < count; k++)
			{
				DB[k] = DB[k + 1];
			}
			count--;
		}
	}
}

/******************************************************************************************************************************/
//Name: Double_Size
//Precondition: size for DB has not been doubled
//Postcondition: size for DB has been doubled
//Decription: doubles the size (capacity) of DB
/******************************************************************************************************************************/
void tlist::Double_Size()
{
	capacity = capacity * 2;
	string *temp = new string[capacity];

	for (int i = 0; i < count; i++)
	{
		temp[i] = DB[i];
	}
	delete[] DB;
	DB = temp;
}

/****************************************************************************************************************************/
//Name: Display
//Precondition: Information hasn't been printed to the screen
//Postcondition: Information has been printed to the screen
//Decription: Prints contents of DB to the screen
/***************************************************************************************************************************/
void tlist::Display()
{
	if (Is_Empty())
	{
		cout << "The database is empty. Nothing to display.\n";
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			cout << "DB[ " << i << " ] = " <<  DB[i] << endl;
		}
	}
}

/****************************************************************************************************************************/
//Name: Choice
//Precondition: The user has not provided a choice for what actions to perform
//Postcondition: The user has selected a choice and the choice is executed. Re-loops to allow for further choices.
//Decription: Provides the user with 5 choices: Print information to the screen, add a new entry, remove an existing entry,
//search the database for an entry, or exit the program.
/***************************************************************************************************************************/
void tlist::Choice(tlist &MyClass)
{
	int choice;
	string key;

	cout << "\nWhat would you like to do?\n";
	cout << "1) Print data\n";
	cout << "2) Add a new entry\n";
	cout << "3) Remove an entry\n";
	cout << "4) Search for an entry\n";
	cout << "5) Exit\n";
	cout << "\nChoice: ";
	cin >> choice;
	cout << "\n";

	switch (choice)
	{

	case 1:
		Display();
		MyClass.Choice(MyClass);
		break;
	case 2:
		cout << "This is the data before the function is called: \n";
		Display();
		cout << "\nPlease enter a string to add: \n";
		cin >> key;
		MyClass.Insert(key);
		cout << "\n";
		cout << "This is the data after the function has been called: \n";
		Display();
		MyClass.Choice(MyClass);
		break;
	case 3:
		cout << "This is the data before the function is called: \n";
		Display();
		cout << "\nPlease enter a string to remove: \n";
		cin >> key;
		Remove(key);
		cout << "This is the data after the function has been called: \n";
		Display();
		MyClass.Choice(MyClass);
		break;
	case 4:
		cout << "Please enter a string to search for: \n";
		cin >> key;
		cout << "\n";
		Search(key);
		MyClass.Choice(MyClass);
		break;
	default:
		cout << "Goodbye!\n";
	}
}


/****************************************************************************************************************************/
//Name: destructor
//Precondition: memory for DB is still allocated
//Postcondition: memory for DB is no longer allocated
//Decription: de-allocates all memory allocated to DB.
/***************************************************************************************************************************/
tlist::~tlist()
{
	cout << "Destructor Invoked\n";
	delete[] DB;
	count = 0;
	DB = 0;
}