#include "Inventory.h"
#include <iostream>
#include <cctype>

Inventory::Inventory()
{
	newProductID = 1;
}

//date validation function
bool isValidDate(const std::string& date) 
{
	if (date.empty())
		return true; //for specific product

	if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
	{
		return false;
	}

	for (int i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7) continue;
		if (!isdigit(date[i])) return false;
	}
}

void Inventory::addProduct()
{
	int quantity;
	double price;
	std::string barcode, name, description, category, supplier, expiryDate, manufactureDate;

	std::cout << "\n===============================Add Product===============================\n";
	std::cout << "Enter Product Barcode: ";
	std::getline(std::cin, barcode);

	std::cout << "Enter Product Name: ";
	std::getline(std::cin, name);

	std::cout << "Enter Product Description: ";
	std::getline(std::cin, description);

	std::cout << "Enter Product Category: ";
	std::getline(std::cin, category);

	std::cout << "Enter Product Quantity: ";
	std::cin >> quantity;

	std::cout << "Enter Product Price: RM ";
	std::cin >> price;

	std::cin.ignore();

	std::cout << "Enter Product Supplier: ";
	std::getline(std::cin, supplier);

	do
	{
		std::cout << "Enter Product Expiry Date (YYYY-MM-DD, press Enter if none): ";
		std::getline(std::cin, expiryDate);

		if (!isValidDate(expiryDate))
		{
			std::cout << "The date format is invalid. Please re-enter the date in YYYY-MM-DD format." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}
	} while (!isValidDate(expiryDate));

	do
	{
		std::cout << "Enter Product Manufacture Date (YYYY-MM-DD, press Enter if none): ";
		std::getline(std::cin, manufactureDate);

		if (!isValidDate(manufactureDate))
		{
			std::cout << "The date format is invalid. Please re-enter the date in YYYY-MM-DD format." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}
	} while (!isValidDate(manufactureDate));

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

void Inventory::addProduct(const Product& product) 
{
	products.push_back(product); //to add the product to the vector 
	//(products(empty)) become (products(1)) after adding the product
}

void Inventory::displayProducts() const 
{
	//take each product in the vector and display it
	for (const auto& product : products) {
		product.display();
	}
}

void Inventory::searchProduct() const
{
	int id;

	std::cout << "Please Enter the Product ID to Search: ";
	std::cin >> id;

	bool found = false;

	for (const auto& product : products)
	{
		if (product.getID() == id)
		{
			product.display();
			found = true;
			break;
		}
	}

	if (!found)
	{
		std::cout << "The product with ID " << id << " is not found." << std::endl;
	}
}
