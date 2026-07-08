//include guards
#ifndef PRODUCT_H
#define PRODUCT_H

#pragma once
#include <string>

class Product
{
private: //cannot be edited
	//product attributes
	int product_ID;
	std::string product_Barcode;
	std::string product_Name;
	std::string product_Description;
	std::string product_Category;

	//product stock and price
	int product_Quantity;
	double product_Price;

	//product supplier and dates
	std::string product_Supplier;
	std::string product_ExpiryDate;
	std::string product_ManufactureDate;

public: //product creation
	Product(int product_ID, std::string product_Barcode, std::string product_Name, std::string product_Description, std::string product_Category,
		int product_Quantity, double product_Price,
		std::string product_Supplier, std::string product_ExpiryDate, std::string product_ManufactureDate);

	//system function
	void display() const;
};

#endif
