#include "Product.h"
#include <iostream>
#include <utility>

Product::Product(int product_ID,
    std::string product_Barcode,
    std::string product_Name,
    std::string product_Description,
    std::string product_Category,
    int product_Quantity,
    double product_Price,
    std::string product_Supplier,
    std::string product_ExpiryDate,
    std::string product_ManufactureDate)

    : product_ID(product_ID),
    product_Barcode(product_Barcode),
    product_RFID_UID("N/A"),
    product_Name(std::move(product_Name)),
    product_Description(std::move(product_Description)),
    product_Category(std::move(product_Category)),
    product_Quantity(product_Quantity),
    product_Price(product_Price),
    product_Supplier(std::move(product_Supplier)),
    product_ExpiryDate(std::move(product_ExpiryDate)),
    product_ManufactureDate(std::move(product_ManufactureDate))

{
}

void Product::display() const
{
    std::cout << "====================================================\n";
    std::cout << "Product Details:\n";
    std::cout << "====================================================\n";
    std::cout << "Product ID: " << product_ID << "\n"
        << "Product Barcode: " << product_Barcode << "\n"
        << "Product RFID UID: " << product_RFID_UID << "\n"
        << "Product Name: " << product_Name << "\n"
        << "Product Description: " << product_Description << "\n"
        << "Product Category: " << product_Category << "\n"
        << "Product Quantity: " << product_Quantity << "\n"
        << "Product Price: RM " << product_Price << "\n"
        << "Product Supplier: " << product_Supplier << "\n"
        << "Product Expiry Date: " << product_ExpiryDate << "\n"
        << "Product Manufacture Date: " << product_ManufactureDate << "\n";
    std::cout << "====================================================\n";
}
//=======================================================================
//ID
//=======================================================================
int Product::getID() const
{
	return product_ID;
}
//=======================================================================
//Barcode
//=======================================================================
std::string Product::getBarcode() const
{
	return product_Barcode;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Product::setBarcode(std::string newBarcode)
{
    product_Barcode = newBarcode;
}
//=======================================================================
//Name
//=======================================================================
std::string Product::getName() const
{
	return product_Name;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Product::setName(std::string newName)
{
    product_Name = newName;
}
//=======================================================================
// Description
//=======================================================================
std::string Product::getDescription() const
{
    return product_Description;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Product::setDescription(std::string newDescription)
{
    product_Description = newDescription;
}
//=======================================================================
//Category
//=======================================================================
std::string Product::getCategory() const
{
	return product_Category;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Product::setCategory(std::string newCategory)
{
    product_Category = newCategory;
}
//=======================================================================
//Quantity
//=======================================================================
int Product::getQuantity() const
{
    return product_Quantity;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Product::setQuantity(int newQuantity)
{
    product_Quantity = newQuantity;
}
//=======================================================================
//Price
//=======================================================================
double Product::getPrice() const
{
    return product_Price;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Product::setPrice(double newPrice)
{
    product_Price = newPrice;
}
//=======================================================================
//Supplier
//=======================================================================
std::string Product::getSupplier() const
{
    return product_Supplier;
}
////||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Product::setSupplier(std::string newSupplier)
{
    product_Supplier = newSupplier;
}
//=======================================================================
//Expiry Date
//=======================================================================
std::string Product::getExpiryDate() const
{
	return product_ExpiryDate;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Product::setExpiryDate(std::string newExpiry)
{
    product_ExpiryDate = newExpiry;
}
//=======================================================================
// Manufacture Date
//=======================================================================
std::string Product::getManufactureDate() const
{
    return product_ManufactureDate;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Product::setManufactureDate(std::string newManufacture)
{
    product_ManufactureDate = newManufacture;
}
//=======================================================================
// Inventory Value
//=======================================================================
double Product::getInventoryValue() const
{
	return product_Quantity * product_Price;
}
//=======================================================================
//RFID
//=======================================================================
std::string Product::getRFID() const
{
    return product_RFID_UID;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Product::setRFID(std::string newRFID)
{
    product_RFID_UID = newRFID;
}
