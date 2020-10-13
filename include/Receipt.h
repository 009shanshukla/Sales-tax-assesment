/*
 *	File: Receipt.h
 *	Created: 10 Oct 2020, 7:18 AM
 *  Author: Shantanu Shukla
 * 	Project: Sales Tax
 * 	© Makkajai Edu Tech
 *
 *  v1.00
 *
 * 	NOTES: This file contains sales tax class related to calculation on purchased items
 *
 */

#ifndef RECEIPT_H
#define RECEIPT_H

#include "InputParser.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> 

static const char *exemptedList[3] = {"book","chocolate","pills"};

struct Items
{
    int count;
    double price;
    std::string item;
    double basicSalesTax;
    double importDuty;
    double tax;
};

class Receipt
{
    private:
        double salesTax;
        double total;
        InputParser inputParser;
        struct Items* items; 

    public:

        Receipt();
        Receipt(std::string file);
        ~Receipt();

        void setPurchaseList();
        bool isDouble(std::string val);
        void receiptDetails();
        void setItems(int index, int count, double price, std::string vendor);
        void calculateTax(int id);
};

#endif