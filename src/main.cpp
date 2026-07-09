#include "Inventory.h"
#include "Product.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <limits>

using namespace std;

void clearScreen()
{
	system("cls");
}

void pauseScreen()
{
	cout << "Press Enter to continue...";
	cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	cin.get();
}

void displayMenu()
{
	cout << "====================================================" << endl;
	cout << "Inventory Management System Menu" << endl;
	cout << "====================================================" << endl;
	cout << "\n";
	cout << "Welcome to YouExpress Inventory Management System!" << endl;
	cout << "Manage your products efficiently and effectively." << endl;
	cout << "\n";
	cout << "What would you like to do today?" << endl;
	cout << "\n";
	cout << "1. Add Product" << endl;
	cout << "2. Display Products" << endl;
	cout << "3. Search Product" << endl;
	cout << "4. Sort Products" << endl;
	cout << "5. Update Product" << endl;
	cout << "6. Delete Product" << endl;
	cout << "7. Check Product Status" << endl;
	cout << "8. Exit" << endl;
	cout << "====================================================" << endl;
	cout << "\n";
	cout << "Please select an option: ";
}

int main()
{
	SetConsoleOutputCP(CP_UTF8); // Set console output to UTF-8)

	Inventory inventory; // Create an instance of Inventory

	while (true)
	{
		displayMenu();
		int option;

		while (true)
		{
			if (!(std::cin >> option))
			{
				cout << "The input is invalid. Please re-enter a number between 1 and 8." << endl;
				cout << "Thank you for your understanding." << endl;
				cin.clear();
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				pauseScreen();
				continue;
			}

			if (option < 1 || option > 8)
			{
				cout << "The option is invalid. Please try again " << endl;
				cout << "Thank you for your understanding." << endl;
				continue;
			}
			break;
		}

		switch (option)
		{
		case 1: // add product
			clearScreen();
			inventory.addProduct();
			pauseScreen();
			clearScreen();
			break;

		case 2: //display products
			clearScreen();
			inventory.displayProducts();
			pauseScreen();
			clearScreen();
			break;

		case 3: //search product
			clearScreen();
			inventory.searchProduct();
			pauseScreen();
			clearScreen();
			break;

		case 4: //sort product
			clearScreen();

			pauseScreen();
			clearScreen();
			break;

		case 5: //update product
			clearScreen();

			pauseScreen();
			clearScreen();
			break;

		case 6: //delete product
			clearScreen();

			pauseScreen();
			clearScreen();
			break;

		case 7: //check product status
			clearScreen();

			pauseScreen();
			clearScreen();
			break;

		case 8:
			cout << "Exiting the program....." << endl;
			cout << "Thank You for Using YouExpress Inventory Management System!" << endl;
			cout << "Goodbye! Wish You Have A Nice Day!" << endl;
			
			return 0;

		default:
			cout << "It is not a valid option." << endl;
			cout << "Please try again" << endl;
			break;
		}
	}

	return 0;
}
