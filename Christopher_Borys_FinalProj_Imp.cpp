// Name: Christopher Borys
// Due Date: 12/2/19
//
// Final Project - Implementation File

#include <iostream>
#include <string>
#include "Christopher_Borys_FinalProj_Header.h"
using namespace std;

/* item base class functions */
item::item()
{
	/* Default item class constructor */

	ID = 0; // ID initialized to 0
	name = " "; // name value is initialized as blank
	status = " "; // status value is initialized as blank
	category = " "; // category value is initialized as blank
}

item::item(int id, string n, string s, string c)
{
	/* item class constructor */

	ID = id; // ID value is stored in ID variable
	name = n; // name value stored in name variable
	status = s; // status value is stored in status variable
	category = c; // category value stored in category variable
}

void item::setID(int id)
{
	if (id != 0) // executes if ID is not zero
		ID = id; // sets individual ID
	else // executes if ID is 0
		ID = 0; // sets ID as 0
}

int item::getID()
{
	return ID; // returns ID value of an item
}

void item::setName(string n)
{
	if (n != " ") // executes if item's name isn't blank
		name = n; // sets item's name in name variable
	else // executes if item's name is blank
		name = " "; // sets item's name as blank
}

string item::getName()
{
	return name; // returns item's name
}

void item::setStatus(string s)
{
	if (s != " ") // executes if item's status isn't blank
		status = s; // sets item's status in status variable
	else // executes if item's status is blank
		status = " "; // sets item's name as blank
}

string item::getStatus()
{
	return status; // return's item's status
}

void item::setCategory(string c)
{
	if (c == "book" || c == "journal" || c == "magazine") // executes if entered category is book, journal, or magazine
		category = c; // sets item's category in category variable
	else // executes if none of the options above is entered
		category = " "; // sets item's category to be blank
}

string item::getCategory()
{
	return category; // returns item's category
}

void item::print()
{
	/* Print function for all items */

	cout << "ID: " << ID << endl; // prints ID
	cout << "Name: " << name << endl; // prints name
	cout << "Status: " << status << endl; // prints status
	cout << "Category: " << category << endl << endl; // prints category
}

/* book derived class functions */
book::book()
{
	/* default book class constructor */

	ID = 0; // ID initialized to 0
	name = " "; // name initialized to be blank
	status = " "; // status initialzied to be blank
	category = " "; // category initialized to be blank
	author_name = " "; // author initialized to be blank
}

book::book(int id, string n, string s, string c, string a)
{
	/* book class constructor */

	ID = id; // ID value stored in ID variable
	name = n; // name value stored in name variable
	status = s; // status value stored in status variable
	category = c; // category value stored in category variable
	author_name = a; // author value stored in author variable
}

void book::setAuthor(string a)
{
	if (a != " ") // executes if author value isn't blank
		author_name = a; // sets author value in author variable
	else // executes if author name is blank
		author_name = " "; // sets author's name as blank
}

string book::getAuthor()
{
	return author_name; // returns author value
}

/* journal derived class functions */
journal::journal()
{
	/* default journal class constructor */

	ID = 0; // ID initialized to 0
	name = " "; // name initialized to be blank
	status = " "; // status initialized to be blank
	category = " "; // category initialized to be blank
	volume = 0; // volume initialized to be blank
}

journal::journal(int id, string n, string s, string c, int v)
{
	/* journal class constructor */

	ID = id; // ID value stored in ID variable
	name = n; // name value stored in name variable
	status = s; // status value stored in status variable
	category = c; // category value stored in category variable
	volume = v; // volume value stored in volume variable
}

void journal::setVolume(int v)
{
	if (v != 0) // executes if the volume value isn't zero
		volume = v; // stores value in volume variable
	else // executes if the volume value is zero
		volume = 0; // stores value as zero
}

int journal::getVolume()
{
	return volume; // returns volume value
}

/* magazine derived class functions */
magazine::magazine()
{
	/* default magazine class constructor */

	ID = 0; // ID initialized to 0
	name = " "; // name initialized to be blank
	status = " "; // status initialized to be blank
	category = " "; // category initialized to be blank
	issue_number = 0; // issue initialized to be blank
}

magazine::magazine(int id, string n, string s, string c, int i)
{
	/* magazine class constructor */

	ID = id; // ID value stored in ID variable
	name = n; // name value stored in name variable
	status = s; // status value stored in status variable
	category = c; // category value stored in category variable
	issue_number = i; // issue value stored in issue variable
}

void magazine::setIssue(int i)
{
	if (i != 0) // executes if issue value is not 0
		issue_number = i; // stores issue value in issue variable 
	else // executes if issue value is 0
		issue_number = 0; // stores issue value as 0
}

int magazine::getIssue()
{
	return issue_number; // returns issue value
}