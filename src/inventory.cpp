#include "Inventory.h"
#include "Utility.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <limits>

Inventory::Inventory()
{
	newProductID = 1;
}

int Inventory::getMenuOption(int min, int max) const
{
	int option;

	while(true)
	{
		if(std::cin >> option)
		{
			if(option >= min && option <= max)
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return option;
			}
		}

		std::cout << "The input is invalid. Please try again." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

//date validation function
bool isValidDate(const std::string& date)
{
	if(date.empty())
		return true; //for specific product

	if(date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		return false;
	}

	for(size_t i = 0; i < date.length(); i++)
	{
		if(i == 4 || i == 7)
			continue;
		if(!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		if(month < 1 || month > 12)
		{
			return false;
		}

		if (year < 1900)
			return false;

		int daysInMonth;

		switch(month)
		{
		case 2:
			if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				daysInMonth = 29; // Leap year
			else
				daysInMonth = 28;
			break;

		case 4: case 6: case 9: case 11:
			daysInMonth = 30;
			break;

		default:
			daysInMonth = 31;
		}

		if(day < 1 || day > daysInMonth)
		{
			return false;
		}

	return true;
}

//barcode validation function
bool isValidBarcode(const std::string& barcode)
{
	if(barcode.length() != 9)
	{
		return false;
	}

	for(char c : barcode)
	{
		if(!std::isdigit(static_cast<unsigned char>(c)))
		{
			return false;
		}
	}

	return true;
}

//quantity validation function
bool isValidQuantity(int quantity)
{
	return quantity >= 0;
}

//price validation function
bool isValidPrice(double price)
{
	return price >= 0.0;
}

//supplier validation function
bool isValidSupplier(const std::string& supplier)
{
	if(supplier.empty())
	{
		return false;
	}

	for(char c : supplier)
	{
		if(!std::isalnum(static_cast<unsigned char>(c)) && c != ' ' && c != '&' && c != '-')
		{
			return false;
		}
	}
	return true;
}

//add product function
void Inventory::addProduct()
{
	int quantity;
	double price;
	std::string barcode, name, description, category, supplier, expiryDate, manufactureDate;

	std::cout << "\n===============================Add Product===============================\n";
	
	//barcode validation
	do
	{
		std::cout << "Enter Product Barcode (9 digits): ";
		std::getline(std::cin, barcode);

		if (!isValidBarcode(barcode))
		{
			std::cout << "The barcode format is invalid. Please re-enter the barcode with 9 digits." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}

		else if (isBarcodeExist(barcode))
		{
			std::cout << "The barcode is already in use. Please enter a unique barcode." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}
	} while (!isValidBarcode(barcode) || isBarcodeExist(barcode));

	//name validation
	while(true)
	{
		std::cout << "Enter Product Name: ";
		std::getline(std::cin, name);

		if(!name.empty() && name.find_first_not_of(' ') != std::string::npos)
		{
			break;
		}
		std::cout << "The Product Name cannot be empty. Please enter a Product Name: " << std::endl;
	}

	//description vaidation
	while(true)
	{
		std::cout << "Enter Product Description: ";
		std::getline(std::cin, description);

		if(!description.empty() && description.find_first_not_of(' ') != std::string::npos)
		{
			break;
		}
		std::cout << "The Product Description cannot be empty. Please enter the Product Description: ";
	}

	//category validation
	while(true)
	{
		std::cout << "Enter Product Category: ";
		std::getline(std::cin, category);

		if(!category.empty() && category.find_first_not_of(' ') != std::string::npos)
		{
			break;
		}
		std::cout << "The Product Category cannot be empty. Please enter a Product Category: ";
	}

	//quantity validation
	while(true)
	{
		std::cout << "Enter Product Quantity: ";
		if(!(std::cin >> quantity) || quantity < 0)
		{
			std::cout << "The quantity format is invalid. Please re-enter a valid quantity." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if(!isValidQuantity(quantity))
		{
			std::cout << "The quantity cannot be negative. Please re-enter the quantity with a non-negative quantity." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
			continue;
		}
		break;
	}

	//product price validation
	while(true)
	{
		std::cout << "Enter Product Price: RM ";
		if(!(std::cin >> price) || price < 0.0)
		{
			std::cout << "The price format is invalid. Please re-enter the price with a non-negative number." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;

		}

		if(!isValidPrice(price))
		{
			std::cout << "The price cannot be negative. Please re-enter the price with a non-negative number." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
			continue;
		}
		break;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//supplier validation
	while(true)
	{
		std::cout << "Enter Product Supplier: ";
		std::getline(std::cin, supplier);

		if(!isValidSupplier(supplier))
		{
			std::cout << "The supplier format is invalid. Please re-enter the supplier name with only letters, numbers, and spaces." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
			continue;
		}
		break;
	}

	//expiry date validation
	do
	{
		std::cout << "Enter Product Expiry Date (YYYY-MM-DD, press Enter if none): ";
		std::getline(std::cin, expiryDate);

		if(!isValidDate(expiryDate))
		{
			std::cout << "The date format is invalid. Please re-enter the date in YYYY-MM-DD format." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}
	} while(!isValidDate(expiryDate));

	//manufacture date validation
	do
	{
		std::cout << "Enter Product Manufacture Date (YYYY-MM-DD, press Enter if none): ";
		std::getline(std::cin, manufactureDate);

		if(!isValidDate(manufactureDate))
		{
			std::cout << "The date format is invalid. Please re-enter the date in YYYY-MM-DD format." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}
	} while(!isValidDate(manufactureDate));

	//check for expiry date and manufacture date
	if(!expiryDate.empty() && !manufactureDate.empty() && expiryDate < manufactureDate)
	{
		std::cout << "The expiry date cannot be earlier than the manufacture date. Please re-enter the dates." << std::endl;
		std::cout << "Thank you for your understanding." << std::endl;
		return;
	}

	Product newProduct(
		newProductID,
		barcode,
		name,
		description,
		category,
		quantity,
		price,
		supplier,
		expiryDate,
		manufactureDate
	);

	addProduct(newProduct);
	newProductID++;

	std::cout << "=======================================================================\n";
	std::cout << "Product is added successfully!\n";
}

//check for the existance of barcode
bool Inventory::isBarcodeExist(const std::string& barcode) const
{
	for(const auto& product : products)
	{
		if(product.getBarcode() == barcode)
		{
			return true;
		}
	}
	return false;
}

std::string toLowerCase(const std::string& str)
{
	std::string lowerStr = str;
	std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
		[](unsigned char c) {return std::tolower(c); });
	return lowerStr;
}

bool Inventory::hasProducts() const
{
	if(!products.empty())
	{
		return true;
	}

	else
	{
		std::cout << "No products available in the inventory." << std::endl;
		std::cout << "Please add products before continuing." << std::endl;
		return false;
	}
}

void Inventory::addProduct(const Product& product)
{
	products.push_back(product); //to add the product to the vector 
	//(products(empty)) become (products(1)) after adding the product
}

void Inventory::displayProducts() const
{
	if(!hasProducts())
	{
		return;
	}

	for(const auto& product : products)
	{
		product.display();
	}
}

//search product function
void Inventory::searchProduct() const
{
	clearScreen();
	if(!hasProducts())
	{
		pauseScreen("Please Enter to return...");
		clearScreen();
		return;
	}

	int option;
	std::cout << "=======================================================================\n";
	std::cout << "Search Product Menu:\n";
	std::cout << "=======================================================================\n";
	std::cout << "1. Search by Product ID" << std::endl;
	std::cout << "2. Search by Product Barcode" << std::endl;
	std::cout << "3. Search by Product Name" << std::endl;
	std::cout << "4. Search by Product Category" << std::endl;
	std::cout << "5. Search by Product Price Range" << std::endl;
	std::cout << "6. Search by Product Supplier" << std::endl;
	std::cout << "7. Return to Main Menu" << std::endl;
	std::cout << "8. Exit" << std::endl;
	std::cout << "=======================================================================\n";
	std::cout << "Please select an option: ";

	option = getMenuOption(1, 8);
	if(option == 7)
	{
		std::cout << "You are now returning to main menu..." << std::endl;
		return;
	}

	if(option == 8)
	{
		char confirm;
		std::cout << "Are you sure you want to exit the program? (Y/N): ";
		std::cin >> confirm;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		confirm = std::tolower(static_cast<unsigned char>(confirm));
		if(confirm == 'y')
		{
			std::cout << "You are exiting the program. Thank you for using the Inventory Management System!" << std::endl;
			std::cout << "Goodbye! Wish you have a happy day!" << std::endl;
			exit(0);
		}
		else
		{
			std::cout << "Exit cancelled. Returning to Search Menu..." << std::endl;
			return;
		}
	}

	bool found = false;

	switch(option)
	{
	// id
	case 1:
	{
		int id;

		//input validation
		while(true)
		{
			std::cout << "Please enter Product ID to search: ";

			if(std::cin >> id && id > 0)
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}

			std::cout << "The Product ID is invalid. Please re-enter a positive integer." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		//start to search
		for(const auto& product : products)
		{
			if(product.getID() == id)
			{
				product.display();
				found = true;
				break;
			}
		}

		if(!found)
		{
			std::cout << "Sorry! The product with ID " << id << " is not found. Please try again!" << std::endl;
		}
		break;
	}

	// barcode
	case 2:
	{
		std::string barcode;

		while(true)
		{
			std::cout << "Please enter Product Barcode to search: ";
			std::getline(std::cin, barcode);

			if(isValidBarcode(barcode))
			{
				break;
			}

			std::cout << "The Product Barcode is invalid. Please re-enter a valid barcode." << std::endl;
		}

		for (const auto& product : products)
		{
			if (product.getBarcode() == barcode)
			{
				product.display();
				found = true;
				break;
			}
		}

		if (!found)
		{
			std::cout << "Sorry! The product with Barcode " << barcode << " is not found. Please try again!" << std::endl;
		}
		break;
	}

	// name
	case 3:
	{
		std::string name;

		while(true)
		{
			std::cout << "Please enter Product Name to search: ";
			std::getline(std::cin, name);

			if(!name.empty() && name.find_first_not_of(' ') != std::string::npos)
				break;

			std::cout << "The Product Name cannot be empty. Please enter a product name." << std::endl;
		}

		std::string keyword = toLowerCase(name);

		for(const auto& product : products)
		{
			if(toLowerCase(product.getName()).find(keyword)
				!= std::string::npos)
			{
				product.display();
				found = true;
			}
		}

		if(!found)
		{
			std::cout << "Sorry! The product with Name " << name << " is not found. Please try again!" << std::endl;
		}
		break;
	}

	// category
	case 4:
	{
		std::string category;

		while(true)
		{
			std::cout << "Please enter Product Category to search: ";
			std::getline(std::cin, category);

			if(!category.empty() && category.find_first_not_of(' ') != std::string::npos)
				break;

			std::cout << "The Product Category cannot be empty. Please enter a category." << std::endl;
		}
		
		std::string keyword = toLowerCase(category);

		for(const auto& product : products)
		{
			if(toLowerCase(product.getCategory()).find(keyword)
				!= std::string::npos)
			{
				product.display();
				found = true;
			}
		}

		if(!found)
		{
			std::cout << "Sorry! The product with Category " << category << " is not found. Please try again!" << std::endl;
		}
		break;
	}

	// price range
	case 5:
	{
		double minPrice, maxPrice;

		while(true)
		{
			//min price validation
			while(true)
			{
				std::cout << "Please enter the Minimum Price: RM ";

				if(std::cin >> minPrice && minPrice >= 0)
				{
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}

				std::cout << "The Price input is invalid. Please re-enter a non-negative number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			//max price validation
			while(true)
			{
				std::cout << "Please enter the Maximum Price: RM ";

				if(std::cin >> maxPrice && maxPrice >= 0)
				{
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}

				std::cout << "The Price input is invalid. Please re-enter a non-negative number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			if(minPrice <= maxPrice)
			{
				break;
			}
			std::cout << "The Minimum Price cannot be greater than the Maximum Price. Please try again!" << std::endl;
		}

		for(const auto& product : products)
		{
			if(product.getPrice() >= minPrice && product.getPrice() <= maxPrice)
			{
				product.display();
				found = true;
			}
		}

		if(!found)
		{
			std::cout << "Sorry! No products found in the price range RM " << minPrice << " - RM " << maxPrice << ". Please try again!" << std::endl;
		}
		break;
	}

	// supplier
	case 6:
	{
		std::string supplier;

		while(true)
		{
			std::cout << "Please enter Product Supplier to search: ";
			std::getline(std::cin, supplier);

			if(!supplier.empty() && supplier.find_first_not_of(' ') != std::string::npos)
				break;

			std::cout << "The Product Supplier cannot be empty. Please enter a Product Supplier." << std::endl;
		}

		std::string keyword = toLowerCase(supplier);

		for(const auto& product : products)
		{
			if(toLowerCase(product.getSupplier()).find(keyword)
				!= std::string::npos)
			{
				product.display();
				found = true;
			}
		}

		if(!found)
		{
			std::cout << "Sorry! The product with Supplier " << supplier << " is not found. Please try again!" << std::endl;
		}
		break;
	}

	default:
	{
		std::cout << "This is an invalid option. Please try again!" << std::endl;
		break;
	}
	}

	if(found)
	{
		std::cout << "\nSearch completed successfully.\n";
	}
	pauseScreen("Press Enter to return...");
	clearScreen();
}

//sort product function
void Inventory::sortProducts()
{
	clearScreen();
	if(!hasProducts())
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
	if(option == 7)
	{
		std::cout << "You are now returning to main menu..." << std::endl;
		return;
	}

	if(option == 8)
	{
		char confirm;
		std::cout << "Are you sure you want to exit the program? (Y/N): ";
		std::cin >> confirm;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		confirm = std::tolower(static_cast<unsigned char>(confirm));
		if(confirm == 'y')
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

	switch(option)
	{
		//sort by id
		case 1:
		{
			std::cout << "Sorting by ID..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if(ascending)
					return a.getID() < b.getID();
				else
					return a.getID() > b.getID();
			});
		break;
		}

		//sort by name
		case 2:
		{
			std::cout << "Sorting by Name..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if(ascending)
					return toLowerCase(a.getName()) < toLowerCase(b.getName());
				else
					return toLowerCase(a.getName()) > toLowerCase(b.getName());
			});
			break;
		}

		//sort by category
		case 3:
		{
			std::cout << "Sorting by Category..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if(ascending)
					return toLowerCase(a.getCategory()) < toLowerCase(b.getCategory());
				else
					return toLowerCase(a.getCategory()) > toLowerCase(b.getCategory());
			});
			break;
		}

		//sort by quantity
		case 4:
		{
			std::cout << "Sorting by Quantity..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if(ascending)
					return a.getQuantity() < b.getQuantity();
				else
					return a.getQuantity() > b.getQuantity();
			});
			break;
		}

		//sort by price
		case 5:
		{
			std::cout << "Sorting by Price..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				if(ascending)
					return a.getPrice() < b.getPrice();
				else
					return a.getPrice() > b.getPrice();
			});
			break;
		}

		//sort by expiry date
		case 6:
		{
			std::cout << "Sorting by Expiry Date..." << std::endl;
			std::sort(products.begin(), products.end(), [ascending](const Product& a, const Product& b)
			{
				bool aEmpty = a.getExpiryDate().empty();
				bool bEmpty = b.getExpiryDate().empty();

				if(aEmpty && bEmpty)
					return false;

				if(aEmpty)
					return false;

				if(bEmpty)
					return true;

				if(ascending)
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
