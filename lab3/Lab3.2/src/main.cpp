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
#include "HashTable.h"

using namespace std;

void convertText();
void insertHash();
void convertToNumbers();
void compareText();
bool compareSentences(string lineOne, string lineTwo);

HashTable table;

int main()
{
    //convert();
    insertHash();
    //convertToNumbers();
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
        
        //cout << c;
        cout << sentence;

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
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 2; j <= 10; j++)
        {
            if(i != j)
            {
                string fileOne;
                fileOne = "num/num" + to_string(i) + ".txt";
                ifstream isOne;
                isOne.open(fileOne);

                string fileTwo;
                fileTwo = "num/num" + to_string(j) + ".txt";
                ifstream isTwo;
                isTwo.open(fileTwo);

                if(!isOne)
                {
                    cout << "Could not open file";
                }

                if(!isTwo)
                {
                    cout << "Could not open file";
                }


                string lineOne, lineTwo;
                while (getline(isOne, lineOne))
                {
                    while (getline(isTwo, lineTwo))
                    {
                        if(lineOne.length() == lineTwo.length())
                        {
                            //cout << "lika långa" << endl;
                            if(compareSentences(lineOne, lineTwo))
                            {
                                cout << lineOne << endl << lineTwo << endl;
                                cout << "HITTAD! File " << i << " and file: " << j << endl;
                            }  
                            
                            // if(lineOne.compare(lineTwo))
                            // {
                            //     cout << lineOne << endl << lineTwo << endl;
                            //     cout << "File " << i << " and file: " << j << endl;
                            // }

                        }   
                    }
                }

                isOne.close();
                isTwo.close();

            } 
        }
    }
}

bool compareSentences(string lineOne, string lineTwo)
{
    istringstream bufferOne(lineOne);
    istringstream bufferTwo(lineTwo);

    string wordOne, wordTwo;

    while (bufferOne >> wordOne)
    {
        while(bufferTwo >> wordTwo)
        {
            //cout << "Ord1: " << wordOne << " ord2: " << wordTwo << endl;
            if(wordOne != wordTwo)
                return false;
        }
    }
    return true;
}