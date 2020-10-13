/*
 *	File: Receipt.cpp
 *	Created: 10 Oct 2020, 7:30 AM
 *  Author: Shantanu Shukla
 * 	Project: Sales Tax
 * 	© Makkajai Edu Tech
 *
 *  v1.00
 *
 * 	NOTES: This file contains sales tax calculation on purchased items 
 *
 */

#include "../include/Receipt.h"

Receipt::Receipt()
{
}

Receipt::Receipt(std::string textFile)
{
    inputParser.parse(textFile);
    // DMA of object array of items list
    items = new Items[inputParser.getTotalItems()];
}

Receipt::~Receipt()
{
}

//get Items attribute from 2D vector container purchased item lists 
void Receipt::setPurchaseList()
{
    std::vector<std::vector<std::string>> splitWords = this->inputParser.getSplitWords();

    for (int i = 0; i < splitWords.size(); i++)
    {
        int count = 0;
        std::string item = "";
        double price;
        for (int j = 0; j < splitWords[i].size(); j++)
        {
            // number of counts
            if (j == 0)
            {
                count = std::stoi(splitWords[i][j]);
                continue;
            }
            // price of item
            else if (isDouble(splitWords[i][j]))
            {
                price = std::stod(splitWords[i][j]);
            }
            // string related to item and other information 
            else
            {
                item += splitWords[i][j] + " ";
            }
        }
        // removing last space charcter
        item.pop_back();
        setItems(i, count, price, item);
    }
}

// set items in structure item with calculated tax
void Receipt::setItems(int id, int count, double price, std::string item)
{
    this->items[id].count = count;
    this->items[id].price = price;
    this->items[id].item = item;  
    this->items[id].importDuty = 0;
    this->items[id].basicSalesTax = price * 0.1;
    
    if(item.find("imported") != std::string::npos)
    {
        this->items[id].importDuty = price * 0.05;
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (item.find(exemptedList[i]) != std::string::npos)
        {
            this->items[id].basicSalesTax = 0;
            break;
        }
    }
    calculateTax(id);
}

// calculate total sales Tax and price after tax
void Receipt::calculateTax(int id)
{
    this->items[id].tax = this->items[id].basicSalesTax + this->items[id].importDuty;
    // rounding value near to 0.5
    this->items[id].tax = std::ceil(this->items[id].tax * 20.0) / 20.0;
    this->salesTax += this->items[id].tax;
    this->items[id].tax +=  this->items[id].price;
    this->total += this->items[id].tax;
}
// print receipt details
void Receipt::receiptDetails()
{
    for(int i = 0; i < inputParser.getTotalItems(); i++)
    {
        std::cout << std::fixed << std::setprecision(2) << items[i].count << " " << items[i].item << ": " << items[i].tax<<std::endl;
    }
    std::cout << "Sales Taxes: "<<salesTax<<std::endl;
    std::cout << "Total: "<< total << std::endl;
}

bool Receipt::isDouble(std::string val)
{
    for (int i = 0; i < val.length(); i++)
    {
        if (isdigit(val[i]) || val[i] == '.')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
