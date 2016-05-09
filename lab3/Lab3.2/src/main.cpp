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

int main()
{
    //Read a file
    string sentence;

    ifstream is("text/01.txt");    // open file
    
    ofstream outfile;
    outfile.open("example_out.txt");

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
            sentence += c;
        }
    }         
    
    //cout << c;
    cout << sentence;

    is.close(); 
    outfile.close();  

    /*string line;
    ifstream myfile ("example.txt");
    
    ofstream outfile;
    outfile.open("example_out.txt");

    if (myfile.is_open())
    {
        while ( getline (myfile, line, '.'))
        {
            //Do stuff
            //To lower case
            transform(line.begin(), line.end(), line.begin(), ::tolower);

            //Every line is a sentence

            //Remove punctuations

            //Convert to hash dictionary

            //Write to text file
            outfile << line << endl;

            cout << line << '\n';
        }
        myfile.close();
    }

    else cout << "Unable to open file"; */


/*

    // Create 26 Items to store in the Hash Table.
    Item * A = new Item {"Apple", NULL};
    Item * B = new Item {"Banana", NULL};
    Item * C = new Item {"Caterpillar", NULL};
    Item * D = new Item {"Dog", NULL};
    Item * E = new Item {"Elephant", NULL};
    Item * F = new Item {"Fedora", NULL};
    Item * G = new Item {"Goosebumps", NULL};
    Item * H = new Item {"House", NULL};
    Item * I = new Item {"Insects", NULL};
    Item * J = new Item {"Jam", NULL};
    Item * K = new Item {"Kite", NULL};
    Item * L = new Item {"Limestone", NULL};
    Item * M = new Item {"Mountaineering", NULL};
    Item * N = new Item {"Night", NULL};
    Item * O = new Item {"Open Sesame", NULL};
    Item * P = new Item {"Potatoes", NULL};
    Item * Q = new Item {"Quantum Mechanics", NULL};
    Item * R = new Item {"Rrrrrrrrrrawr", NULL};
    Item * S = new Item {"Snakes", NULL};
    Item * T = new Item {"Tizzy Tube", NULL};
    Item * U = new Item {"Underworld", NULL};
    Item * V = new Item {"Volcanic Ash", NULL};
    Item * W = new Item {"Who When What Why", NULL};
    Item * X = new Item {"XXX", NULL};
    Item * Y = new Item {"Yellow", NULL};
    Item * Z = new Item {"Zest of Lemon", NULL};
    
    // Create a Hash Table of 13 Linked List elements.
    HashTable table;
    
    // Add 3 Items to Hash Table.
    table.insertItem(A);
    table.insertItem(B);
    table.insertItem(C);
    table.printTable();
    table.printHistogram();
    
    // Remove one item from Hash Table.
    table.removeItem("Apple");
    table.printTable();
    table.printHistogram();
    
    
    // Add 23 items to Hash Table.
    table.insertItem(D);
    table.insertItem(E);
    table.insertItem(F);
    table.insertItem(G);
    table.insertItem(H);
    table.insertItem(I);
    table.insertItem(J);
    table.insertItem(K);
    table.insertItem(L);
    table.insertItem(M);
    table.insertItem(N);
    table.insertItem(O);
    table.insertItem(P);
    table.insertItem(Q);
    table.insertItem(R);
    table.insertItem(S);
    table.insertItem(T);
    table.insertItem(U);
    table.insertItem(V);
    table.insertItem(W);
    table.insertItem(X);
    table.insertItem(Y);
    table.insertItem(Z);
    table.printTable();
    table.printHistogram();
    
    // Look up an item in the hash table
    Item * result = table.getItemByKey("Snakes");
    cout << result -> key << endl;*/
    return 0;
}