//**************************************************************
//  main.cpp
//  HashTable
//
//  Created by Kar Beringer on June 19, 2014.
//  Demonstrate a simple Hash Table in C++.
//  Implements a Linked List class.
//**************************************************************

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HashTable.h"

using namespace std;

void convertText();
void insertHash();
void convertToNumbers();
void compareText();
bool compareSentences(string lineOne, string lineTwo);
void compare(string line, int numOfFile);

HashTable table;

int main()
{
    convertText();
    insertHash();
    convertToNumbers();
    compareText();
    /*Det vi vill göra:
    Läsa in filer och ta bort punkter + göra om till små bokstäver - CHECK!
    Lägga in ord från filerna i hashtabellen
        Om ordet inte finns ska det läggas in sist
        Om ordet finns ska inget göras
    Göra om meningarna i filerna till sifferkombinationer
    Jämföra filerna*/
    return 0;
}

void convertText()
{
    //Read a file
    string sentence;
    for(int i = 1; i <= 10; i++)
    {
        string inTemp;
        if(i < 10)
        {
            inTemp = "text/0" + to_string(i) + ".txt";
        }
        else
        {
            inTemp = "text/" + to_string(i) + ".txt";
        }
        ifstream is(inTemp);

        string outTemp;
        outTemp = "out/out" + to_string(i) + ".txt";
        ofstream outfile;
        outfile.open(outTemp);

        char c;
        while (is.get(c))                   // loop getting single characters
        {                   
            if(ispunct(c))
            {
                if(c == '.' || c == '!' || c == '?')
                {
                    outfile << sentence << endl;
                    sentence.clear();
                }
                else if(c != '\'')
                {
                    sentence += ' ';
                }         
            }
            else if(c == '\n')
            {
                sentence += ' ';
            }
            else
            {
                sentence += tolower(c);
            }
        }         
        is.close(); 
        outfile.close();         
    }
}

void insertHash()
{
    string word;
    for(int i = 1; i <= 10; i++)
    {
        string inTemp;
        inTemp = "out/out" + to_string(i) + ".txt";
        ifstream is;
        is.open(inTemp);

        if(!is)
        {
            cout << "Could not open file";
        }

        while (is >> word)                   // loop getting single characters
        {                  
            Item * temp = new Item {word, NULL};
            if(!table.getItemByKey(word))
            {
                table.insertItem(temp, table.getNumberOfItems());
            }
            else
            {
                //cout << word << " finns redan!!" << endl;
            }   
        }        
        is.close();
    }
    //table.printTable();
    //table.printHistogram(); 
}

void convertToNumbers()
{
    string word;
    for(int i = 1; i <= 10; i++)
    {
        string inTemp;
        inTemp = "out/out" + to_string(i) + ".txt";
        ifstream is;
        is.open(inTemp);

        string outTemp;
        outTemp = "num/num" + to_string(i) + ".txt";
        ofstream outfile;
        outfile.open(outTemp);

        if(!is)
        {
            cout << "Could not open file";
        }

		string line;
		while (getline(is, line))
		{
			// put the line in an istringstream
			istringstream buffer(line);
			// read the words from the line
			string word;
			while (buffer >> word)
			{
	            outfile << table.getIndexByKey(word) << " "; 
			}
			outfile << endl;
		}
        is.close();
        outfile.close();
    }
}

void compareText()
{
    for(int i = 1; i <= 10; i++)
    {         
        string fileOne;
        fileOne = "num/num" + to_string(i) + ".txt";
        ifstream isOne;
        isOne.open(fileOne);

        if(!isOne)
        {
            cout << "Could not open file";
        }

        string lineOne;
        while (getline(isOne, lineOne))
        {
        	if(lineOne.size() > 15)
        	{
        		compare(lineOne, i);
        	}
        }
        isOne.close();
    } 
}

void compare(string line, int numOfFile)
{
    for(int i = 1; i <= 10; i++)
    {
        if(i != numOfFile)
        {
            string compareFile;
            compareFile = "num/num" + to_string(i) + ".txt";
            //compareFile = "num/num8.txt";
            ifstream isComp;
            isComp.open(compareFile);

            if(!isComp)
            {
                cout << "Could not open file";
            }

            string compLine;
            string words;
            while (getline(isComp, compLine))
            {
                if(compLine == line)
                {
                    //cout << "Found match in file " << numOfFile << " and " << i  << endl;
                    //cout << compLine << endl << line << endl;

					string delimiter = " ";
					size_t pos = 0;
					string token;
					while ((pos = line.find(delimiter)) != string::npos) 
					{
					    token = line.substr(0, pos);
					    line.erase(0, pos + delimiter.length());
					    int index = stoi(token);
                    	table.printWord(index);
					}
					if(line == "\0")
					{
						cout << endl;
					}
                }
            }
        }
    }    
}

bool compareSentences(string lineOne, string lineTwo)
{ 
    for(int i = 0; i < lineOne.length(); i++)
    {
        if(lineOne[i] != lineTwo[i])
            return false;
    }
    return true;
}
