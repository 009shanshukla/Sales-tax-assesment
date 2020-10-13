/*
 *	File: InputParser.h
 *	Created: 10 Oct 2020, 7:10 AM
 *  Author: Shantanu Shukla
 * 	Project: Sales Tax
 * 	© Makkajai Edu Tech
 *
 *  v1.00
 *
 * 	NOTES: This file contains class parser on input test files 
 *
 */

#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
class InputParser
{
    private:
        std::vector < std::vector<std::string> > splitWords;
        int count;
        

    public:
        InputParser();
        void parse(std::string textFile);
        ~InputParser();
        void shutDown(std::string msg);

        void printSplitWords();
        std::vector <std::vector<std::string> > getSplitWords();  
        int getTotalItems();
};


#endif