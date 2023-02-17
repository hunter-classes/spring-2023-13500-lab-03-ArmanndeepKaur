#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reservoir.h"
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2)
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) 
    {
        std::cerr<<"File cannot be opened for reading\n";
        exit(1); 
    }

    std::string junk;
    getline(fin, junk);

    std::string theDate;
    double eastSt, eastEl, westSt, westEl;
    std::string westDates[365];
    double westFeets[365];
    int x = 0; 
    bool write = false;
    

    while(fin >> theDate >> eastSt >> eastEl >> westSt >> westEl)
    {
        //fin.ignore(INT_MAX, '\n');
        if(theDate == date1)
        {
            write = true;
        }
        if(write)
        {
            westDates[x] = theDate;
            westFeets[x] = westEl;
            x++;
        }
        if(theDate == date2)
        {
            write = false;
        }
      }
      for(int i = x-1; i>=0; i--)
        {
          std::cout<<westDates[i]<<": "<<westFeets[i]<<" ft\n";
        }
    fin.close();
}