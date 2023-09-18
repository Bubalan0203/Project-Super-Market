# Project-Super-Market
This C++ project appears to be a  command-line-based shopping system for a supermarket. It includes functionality for both administrators and buyers. The project utilizes file handling to store and manage product information in a text file.


1. Class: shopping

This class appears to be the core of the shopping system, containing various member functions to perform different operations like adding products, modifying products, deleting products, generating a receipt, etc.
2. Main Function:

The main function creates an instance of the shopping class and calls its menu method to start the application.
3. Class Members:

private data members:
int pcode: Stores the product code.
float price, discount: Store the price and discount of a product.
string pname: Stores the product name.
4. Member Functions:

void menu(): Displays the main menu with options for administrators and buyers. It allows login for administrators and navigation to different sections.
void administrator(): Displays the administrator menu with options to add, edit, or remove products, or go back to the main menu.
void buyer(): Displays the buyer menu with options to purchase products or go back to the main menu.
void add(): Allows administrators to add a new product to the system by taking input for product details and storing them in a file.
void edit(): Allows administrators to modify existing product details.
void rem(): Allows administrators to delete a product from the system.
void receipt(): Generates a receipt for the products purchased by a buyer.
void list(): Lists all the products in the system.
5. File Operations:

The project uses file operations (fstream) to read and write product data to a file named "database.txt." This file is used to store product information persistently.
6. Data Validation:

The code includes some basic data validation, such as checking for duplicate product codes and verifying administrator login credentials.
7. Menu Navigation:

The program uses a menu-driven approach, allowing users to navigate between different functionalities.
8. Error Handling:

Some error handling is implemented to handle cases like missing data files and invalid menu choices.
9. Receipt Generation:

The receipt function calculates and displays a receipt for products purchased by a buyer, considering discounts.
10. Goto Statements:
- The code uses goto statements for menu navigation, which can be replaced with better control flow structures for improved readability.

11. UI Layout:
- The code includes a simple text-based UI layout with appropriate headers and formatting.
