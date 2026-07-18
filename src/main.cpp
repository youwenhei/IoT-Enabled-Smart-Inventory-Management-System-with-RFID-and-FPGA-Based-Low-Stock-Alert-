#include <iostream>
#include <windows.h>
#include "Inventory.h"
#include "Utility.h"
#include "Database.h"

using namespace std;

void displayMenu()
{
	displayTitle("Inventory Management System Menu");
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
	cout << "8. Inventory Dashboard" << endl;
	cout << "9. Refresh Product List" << endl;
	cout << "10. Export Report" << endl;
	cout << "11. Exit" << endl;
	std::cout << "=======================================================================\n";
	cout << "Please select an option: ";
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	Database db;
	cout << "Database Connected Successfully!" << endl;
	system("pause");

	Inventory inventory;

	while (true)
	{
		clearScreen();
		displayMenu();
		int option = getMenuOption(1, 11);

		switch (option)
		{
		case 1: // add product
			clearScreen();
			inventory.addProduct();
			pauseScreen("Press Enter to return...");
			clearScreen();
			break;

		case 2: //display products
			clearScreen();
			inventory.displayProducts();
			pauseScreen("Press Enter to return...");
			break;

		case 3: //search product
			clearScreen();
			inventory.searchProduct();
			break;

		case 4: //sort product
			inventory.sortProducts();
			break;

		case 5: //update product
			inventory.updateProduct();
			break;

		case 6: //delete product
			inventory.deleteProduct();
			break;

		case 7: //check product status
			inventory.checkProductStatus();
			break;

		case 8://display dashboard
			inventory.displayDashboard();
			break;

		case 9:
			inventory.refreshProducts();
			break;

		case 10:
			inventory.exportReport();
			break;

		case 11:
			cout << "Exiting the program....." << endl;
			cout << "Thank You for Using YouExpress Inventory Management System!" << endl;
			cout << "Goodbye! Wish You Have A Nice Day!" << endl;
			return 0;
		}
	}
}
