# CSC-2110---Project

Build Specifications (40 points)
  1. The system should load a catalog of books, journals, and magazines at the start of the program. (at least five of each)
  2. A user can search the catalog: The user of the system can search the library’s catalog by using the name of the item. Also, a user can list books by category (Book, Journal, or magazine).
     If you are looking specifically for a book, you can search by the name of the author.
  3. A user can check out books, journals, or magazines: The user needs to find the item first, then they can check it out. A user cannot check out an item that is already checked out.
  4. A user can return books, journals, or magazines: A user can return an item. The user needs to find the item first, then they can return it.
  5. Add new books, journals, or magazines to the catalog. A librarian can add a new item to the catalog.
  
Each item should have the following data members: ID, Name, and Status.

Books have the “Author_name” as an additional data member.

Journals have the “Volume” as an additional data member.

Magazines have the “Issue_number” as an additional data member.

The program must have the following properties (15 points):
- You should do error handling (Ex: A librarian cannot add a book that already exists)
- You should use C++ concepts that we covered in class like inheritance, and polymorphism. Example: (inheritance) You can design a generic library item, then design derived classes for different kinds of items that a user can check out.
- Your program should use a suitable data structure to store the items.

Also, design a menu (should still appear until the exit option is chosen) in the Main program that has the following options implemented to test your classes’ functionality (10 points):
  1. Search Catalog
  2. Check out
  3. Return
  4. Add a new item
  5. Exit
  
Extra Credit: (10 points)
  - Save and load data from and to a file.
