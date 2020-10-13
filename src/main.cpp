/*
 *	File: main.cpp
 *	Created: 10 Oct 2020, 7:04 AM
 *  Author: Shantanu Shukla
 * 	Project: Sales Tax
 * 	© Makkajai Edu Tech
 *
 *  v1.00
 *
 * 	NOTES: Basic sales tax is applicable at a rate of 10% on all goods, except books, food,
and medical products that are exempt. Import duty is an additional sales tax
applicable on all imported goods at a rate of 5%, with no exemptions.

 * Coding Style: Google C++ coding guidelines   

 * Problem Link: https://docs.google.com/document/d/1rejug6Vr5rWsD_ZBtPX7EvLVw385BDhx9NdqhvAio8U/
 *
 */

#include "../include/Receipt.h"

int main()
{
    //Test Case 1
    Receipt receipt1 = Receipt("test/input1.txt");
    receipt1.setPurchaseList();
    receipt1.receiptDetails();
    //Test Case 2
    Receipt receipt2 = Receipt("test/input2.txt");
    receipt2.setPurchaseList();
    receipt2.receiptDetails();
    //Test Case 3
    Receipt receipt3 = Receipt("test/input3.txt");
    receipt3.setPurchaseList();
    receipt3.receiptDetails();
}