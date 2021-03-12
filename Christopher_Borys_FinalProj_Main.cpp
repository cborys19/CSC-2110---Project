// Name: Christopher Borys
// Due Date: 12/2/19
//
// Final Project - Main File

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Christopher_Borys_FinalProj_Header.h"
using namespace std;

/* Vectors that will be used; declared globally for easier usage */
vector<item*> library; // main vector to hold car information
vector<item*> lended; // vector used with the checkout function; stores the checked out items

/* Globally declared variables; most will be used to store catalog information */
int ID, volume, issue_number, choice; // integer variables; all except choice are used to store catalog information
string name, author_name, status, category; // string variables; all used to store catalog information

/* Boolean function prototypes */
bool checkID(int id, vector<item*> &list); // will be used to verify an item in the catalog via its ID number
bool checkName(string n, vector<item*> &list); // will be used to verify an item in the catalog via its name
bool checkNameWithoutPrint(string n, vector<item*> &list); // operates the same as checkName() but does not print anything; used exclusively in add()
bool checkCategory(string c, vector<item*> &list); // will be used to verify an item in the catalog via its category
bool checkCategoryWithoutPrint(string c, vector<item*> &list); // operates the same as checkCategory() but does not print anything; used exclusively in add()
bool checkNameForAuthor(string n, vector<item*> &list); // will be used to verify an item in the catalog via its name and will also print the author information

/* Main function prototypes */
void menu(); // menu function prototype
void search(); // search function prototype
void checkout(); // check out function prototype
void returner(); // prototype for function used to return a checked out item to the catalog
void add(); // new item function prototype

int main()
{
	ifstream file("items.txt"); // loads in data from linked text file

	if (file.is_open()) // executes if file is open
	{
		while (file >> ID >> name >> status >> category) // while loop will iterate while reading in ID, name, and category information
		{
			if (category == "book") // executes if the item in the file is a book
			{
				file >> author_name; // will then read in author information (string value)
				int flag = checkID(ID, library); // function call will return a boolean integer value if the ID is found within the text file

				if (flag == 0) // executes if integer value is 0; means item is not already in the vector (aka false)
					library.push_back(new book(ID, name, status, category, author_name)); // will then store that catalog item in the library vector using the book class constructor
				else // executes if integer value is 1
					cout << "Book exists" << endl; // this will tell us the item is already loaded into the vector (aka true)
			}
			else if (category == "journal") // executes if the item in the file is a journal
			{
				file >> volume; // will then read in volume information (integer value)
				int flag = checkID(ID, library); // function call will return a boolean integer value if the ID is found within the text file

				if (flag == 0) // executes if integer value is 0; means item is not already in the vector (aka false)
					library.push_back(new journal(ID, name, status, category, volume)); // will then store that catalog item in the library vector using the journal class constructor
				else // executes if integer value is 1
					cout << "Journal exists" << endl; // this will tell us the item is already loaded into the vector (aka true)				
			}
			else if (category == "magazine") // executes if the item in the file is a magazine
			{
				file >> issue_number; // will then read in issue information (integer value)
				int flag = checkID(ID, library); // function call will return a boolean integer value if the ID is found within the text file

				if (flag == 0) // executes if integer value is 0; means item is not already in the vector (aka false)
					library.push_back(new magazine(ID, name, status, category, issue_number)); // will then store that catalog item in the library vector using the magazine class constructor
				else // executes if integer value is 1
					cout << "Magazine exists" << endl; // this will tell us the item is already loaded into the vector (aka true)
			}
		}

		file.close(); // this will then close the file
	}
	else // executes if file cannot be opened
	{
		cout << "File cannot be opened. Terminating program..." << endl; // prompts user that file cannot be opened

		return 0; // will end program
	}

	while (1) // operates while all the above is true
	{
		menu(); // recurrent menu function call

		cout << "Enter option: "; // prompts user to choose which option they'd like
		cin >> choice; // stores user's choice in this variable
		cout << endl; // formatting

		switch (choice) // switch statement to handle the variety of choices the user could've picked
		{
			case 1: // executes if the user picks option 1
				search(); // calls search function
			break;

			case 2: // executes if the user picks option 2
				checkout(); // calls check out function
			break;

			case 3: // executes if the user picks option 3
				returner();  // calls return function
			break;

			case 4: // executes if user picks option 4
				add(); // calls add new item function
			break;

			case 5: // executes if user picks option 5
				return 0; // will end program
			break;

			default: // if none of the above options are chosen; loops back to the top
			{
				cout << "Invalid option." << endl << endl;
			}
		}
	}

	system("pause"); // holds window open
}

bool checkID(int id, vector <item*>& list)
{
	bool flag = false; // boolean variable initialized to false

	for (int temp = 0; temp < list.size(); temp++) // loops through the list until it reaches the end
		if ((*list[temp]).getID() == id) // executes if memory information equals the item's ID
			flag = true; // flag will then be true

	return flag; // flag is returned
}

bool checkName(string n, vector<item*>& list)
{
	bool flag = false; // boolean variable initialized to false

	for (int temp = 0; temp < list.size(); temp++) // loops through list until it reaches the end
		if ((*list[temp]).getName() == n) // executes if the memory information is equal to the name
		{
			flag = true; // flag is then true
			(*list[temp]).print(); // that item is then printed; print function from item class
			
			/* used to print author information */
			if (n == "Fantasy")
				cout << "Author: Martin" << endl << endl;
			else if (n == "Romance")
				cout << "Author: Roberts" << endl << endl;
			else if (n == "Horror")
				cout << "Author: King" << endl << endl;
			else if (n == "Biography")
				cout << "Author: Douglass" << endl << endl;
			else if (n == "Plays")
				cout << "Author: Shakespeare" << endl << endl;
		}
	
	return flag; // flag is then returned
}

bool checkNameWithoutPrint(string n, vector<item*> &list)
{
	bool flag = false; // boolean variable initialized to false

	for (int temp = 0; temp < list.size(); temp++) // loops through list until it reaches the end
		if ((*list[temp]).getName() == n) // executes if the memory information is equal to the name
			flag = true; // if found, flag is then true

	return flag; // flag value is then returned
}

bool checkCategory(string c, vector<item*> &list)
{
	bool flag = false; // boolean variable initialized to false

	for (int temp = 0; temp < list.size(); temp++) // loops through list until it reaches the end
	{
		if ((*list[temp]).getCategory() == c) // executes if the memory information is equal to the category
		{
			flag = true; // flag is now true
			(*list[temp]).print(); // prints every catalog item belonging to that category
		}
	}

	return flag; // flag is returned
}

bool checkCategoryWithoutPrint(string c, vector<item*> &list)
{
	bool flag = false; // boolean variable initialized to false

	for (int temp = 0; temp < list.size(); temp++) // loops through list until it reaches the end
		if ((*list[temp]).getCategory() == c) // executes if the memory information is equal to the category
			flag = true; // if found, flag is then true

	return flag; // flag value is then returned
}

bool checkNameForAuthor(string n, vector<item*>& list)
{
	bool flag = false; // boolean variable initialized to false

	/* changes value of n according to what author the user searched */
	if (n == "Martin") 
		n = "Fantasy";
	else if (n == "Roberts")
		n = "Romance";
	else if (n == "King")
		n = "Horror";
	else if (n == "Douglass")
		n = "Biography";
	else if (n == "Shakespeare")
		n = "Plays";

	for (int temp = 0; temp < list.size(); temp++) // loops through list until it reaches the end
		if ((*list[temp]).getName() == n) // executes if the memory information is equal to the name
		{
			flag = true; // flag is now true
			(*list[temp]).print(); // will then print that book's information

			/* Outputs author based on title */
			if (n == "Fantasy")
				cout << "Author: Martin" << endl << endl;
			else if (n == "Romance")
				cout << "Author: Roberts" << endl << endl;
			else if (n == "Horror")
				cout << "Author: King" << endl << endl;
			else if (n == "Biography")
				cout << "Author: Douglass" << endl << endl;
			else if (n == "Plays")
				cout << "Author: Shakespeare" << endl << endl;
		}

	return flag; // flag is returned
}

void menu()
{
	cout << "Menu" << endl;
	cout << "-----------------" << endl;
	cout << "1. Search Catalog" << endl;
	cout << "2. Check Out" << endl;
	cout << "3. Return" << endl;
	cout << "4. Add a New Item" << endl;
	cout << "5. Exit" << endl << endl;
}

void search()
{
	int searchChoice; // integer variable to hold search option
	string bookName; // string variable to hold book title
	string cat; // string variable to hold category
	string auth; // string variable to hold author

	/* option menu */
	cout << "Would you like to search by: " << endl << endl;
	cout << "1. Name" << endl;
	cout << "2. Category" << endl;
	cout << "3. Author" << endl;
	cout << "4. Return" << endl;
	cout << "Option: ";
	cin >> searchChoice;
	cout << endl;
	
	bool fg = false; // boolean variable initialized to false

	try // try block used in case an exception is generated
	{
		if (searchChoice == 1) // executes if the user is searching by name
		{
			cout << "Enter title: "; // prompts user to enter name of item
			cin >> bookName; // stores name
			cout << endl; // formatting

			fg = checkName(bookName, library); // calls name checking function
			if (fg == false) // executes if the flag is false
				throw fg; // if the item is not found the error is thrown to the catch block
		}
		else if (searchChoice == 2) // executes if the user is searching by category
		{
			cout << "Enter category: "; // prompts user for category
			cin >> cat; // stores category
			cout << endl; // formatting

			fg = checkCategory(cat, library); // calls category checking function
			if (fg == false) // executes if the flag is false
				throw fg; // throws error if category isn't found
		}
		else if (searchChoice == 3) // executes if the user searches by author
		{
			cout << "Enter author: "; // prompts user for the author
			cin >> auth; // stores author
			cout << endl; // formatting

			if (auth != "Martin" && auth != "Roberts" && auth != "King" &&
				auth != "Douglass" && auth != "Shakespeare") // executes if author isn't one of these names
				throw fg; // throws error if author isn't found
			else // executes if author matches the above names
				checkNameForAuthor(auth, library); // calls name checking and author printing function
		}
		else if (searchChoice == 4) // executes if user wants to return to the main menu
			cout << "Returning to menu..." << endl << endl;
		else // executes if user doesn't pick any of the above options
			throw fg; // error is thrown
	}
	catch (bool) // catches all of the thrown boolean errors and handles them here
	{
		cout << "Exception caught. Item cannot be found." << endl; // prompts user that an exception was thrown and caught; explains reason for it
		cout << "Returning to program..." << endl << endl; // states that user is being transferred back to the main menu
	}
}

void checkout()
{
	string title; // string variable that will contain the title of the item the user wants to check out

	cout << "Enter the title of the item to check out: "; // prompts user to enter the title
	cin >> title; // stores title in string variable
	cout << endl; // formatting

	bool fg = checkName(title, library); // boolean flag variable; stores returned value from the checkName function

	try // try block that will test code based on the above boolean variable's value
	{
		if (fg == false) // executes if the flag returns false
			throw fg; // exception is then thrown
		else // executes if flag returns true
		{
			for (int temp = 0; temp < library.size(); temp++) // loops until the end of the library vector is reached
				if ((*library[temp]).getName() == title) // executes if the title of the item is found
				{
					lended.push_back(library[temp]); // this will load the requested title into the lended vector
					library.erase(library.begin() + temp); // the title will then be removed from the library vector

					cout << "Title successfully checked out!" << endl << endl; // notification of successful check out
					cout << "Inventory" << endl; // the inventory will then be printed to display that the item in fact has been checked out
					cout << "---------" << endl; // formatting

					for (int temp = 0; temp < library.size(); temp++) // loops until the end of the library vector is reached
						(*library[temp]).print(); // prints current contents of the library
				}
		}
	}
	catch (bool) // catch block that will catch the thrown boolean exception variable
	{
		cout << "Title could not be found. Returning..." << endl; // prompts user that exception was generated

		return; // returns user to the main menu
	}
}

void returner()
{
	string title; // string variable that will contain the title of the item the user wants to check out

	cout << "Enter the title you'd like to return: "; // prompts user to enter the title of the item they're returning
	cin >> title; // stores title in string variable
	cout << endl; // formatting

	bool fg = checkName(title, lended); // boolean flag variable; stores returned value from the checkName function

	try // try block that will test code based on the above boolean variable's value
	{
		if (fg == false) // executes if the flag returns false
			throw fg; // exception is then thrown
		else // executes if flag returns true
		{
			for (int temp = 0; temp < lended.size(); temp++) // loops until the end of the lended vector is reached
				if ((*lended[temp]).getName() == title) // executes if the title of the item is found
				{
					library.push_back(lended[temp]); // this will load the requested title into the library vector; will be placed at the end
					lended.erase(lended.begin() + temp); // the title will then be removed from the library vector

					cout << "Title successfully returned!" << endl << endl; // notification of successful return
					cout << "Inventory" << endl; // the inventory will then be printed to display that the item has been returned
					cout << "---------" << endl; // formatting

					for (int i = 0; i < library.size(); i++) // loops until the end of the library vector
						(*library[i]).print(); // prints current contents of the library
				}
		}
	}
	catch (bool) // catch block that will catch the thrown boolean exception variable
	{
		cout << "Title not found. Returning..." << endl; // prompts user that exception was generated and the program will return to the top of the function
	}
}

void add()
{
	bool flag = false; // initializes boolean flag variable to false
	
	try // try block to test code that may generate an exception
	{
		cout << "Enter ID: "; // prompts user to enter the desired item ID
		cin >> ID; // stores ID value

		bool flag = checkID(ID, library); // sets boolean flag variable to value returned by checkID function

		if (flag == true) // executes if flag returns true
			throw flag; // boolean variable is thrown as exception
	}
	catch (bool) // catch block to handle exceptions thrown from try block above
	{
		cout << "Invalid ID. Item may already exist. Returning..." << endl << endl; // prompts user that exception was generated and handled

		return; // exits function and returns to main menu
	}
	
	try // try block to test code that may generate an exception
	{
		cout << "Enter title: "; // prompts user to enter the desired item title
		cin >> name; // stores name value

		bool flag = checkNameWithoutPrint(name, library); // sets boolean flag variable to value returned from function

		if (flag == true) // executes if function returns true
			throw flag; // boolean variable is thrown as exception
	}
	catch (bool) // catch block to handle exceptions thrown from try block above
	{
		cout << "Invalid name. Item may already exist. Returning..." << endl << endl; // prompts user that exception was generated and handled

		return; // exits function and returns to main menu
	}

	try // try block to test code that may generate an exception
	{
		cout << "Enter category: "; // prompts user to enter the desired item category
		cin >> category; // stores category value

		bool flag = checkCategoryWithoutPrint(category, library); // sets boolean flag variable to value returned from function

		if (flag == false) // executes if function returns false
			throw flag; // boolean variable is thrown as exception
	}
	catch (bool) // catch block to handle exceptions thrown from try block above
	{
		cout << "Invalid category. Item may already exist. Returning..." << endl << endl; // prompts user that exception was generated and handled

		return;
	}

	try // try block that will test the category values; throws exception for invalid responses
	{
		if (category == "book") // executes if the user is entering a book
		{
			cout << "Enter last name of author: "; // prompts user to enter the book's author
			cin >> author_name; // stores author value
			cout << endl; // formatting

			bool flag = checkID(ID, library); // boolean flag variable that holds value returned from checkID function

			if (flag == false) // executes if checkID returned false when checking if the item was already in the library
			{
				library.push_back(new book(ID, name, status, category, author_name)); // stores new item in the library vector using book constructor

				cout << "Inventory" << endl; // inventory of library vector will then be printed to show that the item was loaded in
				cout << "---------" << endl; // formatting
				for (int i = 0; i < library.size(); i++) // loops until the end of the vector is reached
				{
					(*library[i]).print(); // library vector contents are printed
				}
			}
			else // executes if checkID returned true (aka item was already in the library)
				throw flag; // throws boolean exception to catch block
		}
		else if (category == "journal") // executes if user is entering a journal
		{
			cout << "Enter volume of journal: "; // prompts user to enter journal's volume number
			cin >> volume; // stores volume value
			cout << endl; // formatting

			bool flag = checkID(ID, library); // boolean flag variable that holds value returned from checkID function

			if (flag == false) // executes if checkID returned false when checking if the item was already in the library
			{
				library.push_back(new journal(ID, name, status, category, volume)); // stores new item in the library vector using journal constructor

				cout << "Inventory" << endl; // inventory of library vector will then be printed to show that the item was loaded in
				cout << "---------" << endl; // formatting
				for (int i = 0; i < library.size(); i++) // loops until the end of the vector is reached
				{
					(*library[i]).print(); // library vector contents are printed
				}
			}
			else // executes if checkID returned true (aka item was already in the library)
				throw flag; // throws boolean exception to catch block
		}
		else if (category == "magazine") // executes if user is entering a magazine
		{
			cout << "Enter issue of mazagine: "; // prompts user to enter magazine's issue number
			cin >> issue_number; // stores issue value
			cout << endl; // formatting

			bool flag = checkID(ID, library); // boolean flag variable that holds value returned from checkID function

			if (flag == false) // executes if checkID returned false when checking if the item was already in the library
			{
				library.push_back(new magazine(ID, name, status, category, issue_number)); // stores new item in the library vector using journal constructor

				cout << "Inventory" << endl; // inventory of library vector will then be printed to show that the item was loaded in
				cout << "---------" << endl; // formatting
				for (int i = 0; i < library.size(); i++) // loops until the end of the vector is reached
				{
					(*library[i]).print(); // library vector contents are printed
				}
			}
			else // executes if checkID returned true (aka item was already in the library)
				throw flag; // throws boolean exception to catch block
		}
		else // executes if user enters an invalid item category
			throw flag; // throws boolean exception

	}
	catch (bool) // catch block to handle thrown boolean exceptions from the try block
	{
		cout << "Error ocurred. Unable to add new item. Item may already exist." << endl;
		cout << "Returning..." << endl << endl; // prompts user that exception was caught and handled; returns to top of the function
	}	
}