#ifndef INVENTORY_H
#define INVENTORY_H
#pragma once
#include <vector>
#include "Product.h"

class Inventory
{
private:
	std::vector<Product> products; // Vector to store the list for products dynamically
	int newProductID; // Initialize the product ID counter

public:
	Inventory();

	bool hasProducts() const;
	int getMenuOption(int min, int max) const;
	void displayProducts() const;
	bool isBarcodeExist(const std::string& barcode) const;

	void exitProgram() const;
	void returnProgram() const;

	void addProduct(); //function overloading
	void addProduct(const Product& product);

	void displaySearchMenu() const;
	void searchProduct() const;
	bool searchByID() const;
	bool searchByBarcode() const;
	bool searchByName() const;
	bool searchByCategory() const;
	bool searchBySupplier() const;
	bool searchByPriceRange() const;

	void sortProducts();
	void sortByPriceAscending() const;
	void sortByPriceDescending() const;
	void sortByExpiryDate() const;

	void updateProduct();
	std::string inputString(const std::string& prompt);
	int inputPositive(const std::string& prompt);
	double inputPrice(const std::string& prompt);
	std::string inputDate(const std::string& prompt);

	void deleteProduct();

	void checkProductStatus();
	static const int LOW_STOCK_THRESHOLD = 10;
};

#endif
