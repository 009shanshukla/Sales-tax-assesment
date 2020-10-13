/*
 *	File: InputParser.cpp
 *	Created: 10 Oct 2020, 7:13 AM
 *  Author: Shantanu Shukla
 * 	Project: Sales Tax
 * 	© Makkajai Edu Tech
 *
 *  v1.00
 *
 * 	NOTES: This file contains parsing method on input test files 
 *
 */

#include "../include/InputParser.h"

InputParser::InputParser()
{
    
}

// read input test file line by line and store it in a 2d vector
void InputParser::parse(std::string textFile)
{
    std::ifstream readFile;
    readFile.open(textFile, std::ios::in);
    if(!readFile)
    {
        shutDown("file could not open: "+textFile);
    }
    std::string line = "";
    this->count = 0;
    while(getline(readFile, line))
    {
        try
        {
            this->count++;
            // if string is not empty 
            if(line != "")
            {
                char* pch = strtok((char* )line.c_str(), " ");
                std::string segs;
                std::vector <std::string> words;
                while(pch != NULL)
                {
                    segs.assign(pch);
                    //skip 'at' word 
                    if(segs != "at")
                    {
                        words.push_back(segs);  
                    }  
                    pch = strtok(NULL, " ");
                }
                this->splitWords.push_back(words);
            }
            else
            {
                shutDown("Line:"+std::to_string(count)+" in input file: "+textFile+" is empty");
            }
        }
        catch(const std::exception& e)
        {
            readFile.close();
            shutDown(e.what());
        }
    }
    readFile.close();
}


InputParser::~InputParser()
{

}

void InputParser::shutDown(std::string msg)
{
    std::cout << "(Closing Project with Error) "<< msg << std::endl;
    exit(1);
}

std::vector <std::vector<std::string> > InputParser::getSplitWords()
{
    return this->splitWords;
}

int InputParser::getTotalItems()
{
    return count;
}