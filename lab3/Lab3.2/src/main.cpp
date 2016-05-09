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

void convert();
void insertHash();

int main()
{
    //convert();
    insertHash();
    /*Det vi vill göra:
    Läsa in filer och ta bort punkter + göra om till små bokstäver - CHECK!
    Lägga in ord från filerna i hashtabellen
        Om ordet inte finns ska det läggas in sist
        Om ordet finns ska inget göras
    Göra om meningarna i filerna till sifferkombinationer
    Jämföra filerna*/
    return 0;
}

void convert()
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
    HashTable table;
    string word;
    ifstream is;
    is.open("example.txt");

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
            cout << word << " finns redan!!" << endl;
        }
            
    }        
    is.close(); 

    // Create 26 Items to store in the Hash Table.
    /*Item * A = new Item {"Apple", NULL};
    Item * B = new Item {"Banana", NULL};
    Item * C = new Item {"Citron", NULL};

    // Create a Hash Table of 13 Linked List elements.
    
    
    // Add 3 Items to Hash Table.
    table.insertItem(A, table.getNumberOfItems());
    table.insertItem(B, table.getNumberOfItems());
    table.insertItem(C, table.getNumberOfItems());
    /*table.insertItem(D);
    table.insertItem(E);
    table.insertItem(F);*/
    table.printTable();
    //table.printHistogram();
    
    // Remove one item from Hash Table.
    //table.removeItem("Apple");
    
    // Look up an item in the hash table
    //Item * result = table.getItemByKey("lite");
    //cout << result -> key << endl;
}
