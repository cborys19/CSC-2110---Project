#pragma once

// Name: Christopher Borys
// Due Date: 12/2/19
//
// Final Project - Header File

#include <iostream>
#include <string>
using namespace std;

/* base class - deals with general items */
class item
{
	public:
		item(); // default constructor
		item(int, string, string, string); // constructor
		void setID(int); // function to set the item's ID
		int getID(); // function that returns the item's ID
		void setName(string); // function to set the item's name
		string getName(); // function that returns the item's name
		void setStatus(string); // function to set the item's status
		string getStatus(); // function that returns the item's status 
		void setCategory(string); // function to set the item's category
		string getCategory(); // function that returns the item's category
		void print(); // print function
	
	protected:
		int ID; // integer variable to store the item's ID value
		string name; // string variable to store the item's name value
		string status; // string variable to store the item's status value
		string category; // string variable to store the item's category value
};

/* derived class - deals with books */
class book : public item // public inheritance
{
	public:
		book(); // default constructor
		book(int, string, string, string, string); // constructor
		void setAuthor(string); // function to set the book's author
		string getAuthor(); // function that returns the book's author
	
	protected:
		string author_name; // string variable to store the book's author value
};

/* derived class - deals with journals */
class journal : public item // public inheritance
{	
	public:
		journal(); // default constructor
		journal(int, string, string, string, int); // constructor
		void setVolume(int); // function to set the journal's volume
		int getVolume(); // function that returns the journal's volume

	protected:
		int volume; // integer variable to store the journal's volume value
};

/* derived class - deals with magazines */
class magazine : public item // public inheritance
{
	public:
		magazine(); // default constructor
		magazine(int, string, string, string, int); // constructor
		void setIssue(int); // function to set the magazine's issue
		int getIssue(); // function that returns the magazine's issue

	protected:
		int issue_number; // integer variable to store the magazine's issue value
};