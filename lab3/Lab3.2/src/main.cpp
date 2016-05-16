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
#include <string>
#include "HashTable.h"

using namespace std;

void convertText();
void insertHash();
void convertToNumbers();

HashTable table;

int main()
{
    //convert();
    insertHash();
    convertToNumbers();

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
        else
        {
            cout << "File " << i << " is open!";
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
        cout << " File closed!" << endl;
        
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

        while (is >> word)                   // loop getting single characters
        {                  
            if(table.getIndexByKey(word))
            {
                outfile << table.getIndexByKey(word) << endl; 
            }
        } 

        is.close();
        outfile.close();
    }

}
