void Inventory::sortProducts()
{
	clearScreen();
	if (!hasProducts())
	{
		pauseScreen("Please Enter to return...");
		clearScreen();
		return;
	}

	int option;
	std::cout << "=======================================================================\n";
	std::cout << "Sort Products	Menu\n";
	std::cout << "=======================================================================\n";
	std::cout << "1. Sort by Product ID" << std::endl;
	std::cout << "2. Sort by Product Name" << std::endl;
	std::cout << "3. Sort by Category" << std::endl;
	std::cout << "4. Sort by Quantity" << std::endl;
	std::cout << "5. Sort by Price" << std::endl;
	std::cout << "6. Sort by Expiry Date" << std::endl;
	std::cout << "7. Return to Main Menu" << std::endl;
	std::cout << "8. Exit" << std::endl;
	std::cout << "=======================================================================\n";
	std::cout << "Please select an option: ";

	option = getMenuOption(1, 8);
	if (option == 7)
	{
		std::cout << "You are now returning to main menu..." << std::endl;
		return;
	}

	if (option == 8)
	{
		char confirm;
		std::cout << "Are you sure you want to exit the program? (Y/N): ";
		std::cin >> confirm;
		confirm = std::tolower(static_cast<unsigned char>(confirm));
		if (confirm == 'y' || confirm == 'Y')
		{
			std::cout << "You are exiting the program. Thank you for using the Inventory Management System!" << std::endl;
			std::cout << "Goodbye! Wish you have a happy day!" << std::endl;
			exit(0);
		}
		else
		{
			std::cout << "Exit cancelled. Returning to sort menu..." << std::endl;
			return;
		}
	}

	int order;
	std::cout << "Please select the order (1 for Ascending, 2 for Descending): ";
	order = getMenuOption(1, 2);
	bool ascending = (order == 1);

	switch (option)
	{
		case 1:
		{
			std::cout << "Sorting by ID..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if (ascending)
					return a.getID() < b.getID();
				else
					return a.getID() > b.getID();
			});
		break;
		}

		case 2:
		{
			std::cout << "Sorting by Name..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if (ascending)
					return toLowerCase(a.getName()) < toLowerCase(b.getName());
				else
					return toLowerCase(a.getName()) > toLowerCase(b.getName());
			});
			break;
		}

		case 3:
		{
			std::cout << "Sorting by Category..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if (ascending)
					return toLowerCase(a.getCategory()) < toLowerCase(b.getCategory());
				else
					return toLowerCase(a.getCategory()) > toLowerCase(b.getCategory());
			});
			break;
		}

		case 4:
		{
			std::cout << "Sorting by Quantity..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if (ascending)
					return a.getQuantity() < b.getQuantity();
				else
					return a.getQuantity() > b.getQuantity();
			});
			break;
		}

		case 5:
		{
			std::cout << "Sorting by Price..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if (ascending)
					return a.getPrice() < b.getPrice();
				else
					return a.getPrice() > b.getPrice();
			});
			break;
		}

		case 6:
		{
			std::cout << "Sorting by Expiry Date..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if (ascending)
					return a.getExpiryDate() < b.getExpiryDate();
				else
					return a.getExpiryDate() > b.getExpiryDate();
			});
			break;
		}

		default:
		{
			std::cout << "This is an invalid option. Please try again!" << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
			return;
		}
	}
	std::cout << "Congrats! The products sorted successfully!" << std::endl;
	std::cout << "Press Enter to view the sorted product list..." << std::endl;
	std::cin.get();
	clearScreen();
	displayProducts();

	std::cout << "\nPress Enter to return to the Main Menu...";
	std::cin.get();
	clearScreen();
	return;
}
