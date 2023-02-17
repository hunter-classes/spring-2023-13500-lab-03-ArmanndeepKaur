#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reservoir.h"
#include "reverseorder.h"

//Task A 
double get_east_storage(std::string date)
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) 
  {
    std::cerr<<"File cannot be opened for reading\n";
    exit(1); 
  }

  std::string junk, theDate; 
  double eastSt, eastEl, westSt, westEl; 
  getline(fin, junk);
  
  while(fin >> theDate >> eastSt) 
  { 
    fin.ignore(INT_MAX, '\n');
    if(date == theDate)
    {
      return eastSt; 
    } 
  }
  fin.close();
  return eastSt;
}


//Task B
double get_min_east() //this function should return the minimum storage in the East basin in the 2018.
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) 
  {
    std::cerr<<"File cannot be opened for reading\n";
    exit(1); 
  }
  std::string junk, theDate;
  std::getline(fin,junk);
  double eastSt;
  double minE = INT_MAX;

  while(fin >> theDate >> eastSt) 
  { 
    fin.ignore(INT_MAX, '\n');
    if(eastSt < minE)
    {
      minE = eastSt;
      return minE; 
    } 
  }
  fin.close();
  return minE;
}

double get_max_east() //this function should return the maximum storage in the East basin in the 2018.
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) 
  {
    std::cerr<<"File cannot be opened for reading\n";
    exit(1); 
  }
  std::string junk, theDate;
  std::getline(fin,junk);
  double eastSt;
  double maxE = INT_MIN;

  while(fin >> theDate >> eastSt) 
  { 
    fin.ignore(INT_MAX, '\n');
    if(eastSt > maxE)
    {
      maxE = eastSt;
      return maxE; 
    } 
  }
  fin.close();
  return maxE;
}


//Task C
std::string compare_basins(std::string date)
{
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) 
  {
    std::cerr<<"File cannot be opened for reading\n";
    exit(1); 
  }
  std::string junk, theDate;
  std::getline(fin,junk);
  double eastEl, westEl; 

  while(fin >> theDate >> eastEl >> westEl)
  {
    if(eastEl > westEl)
    {
      return "East"; 
    }
    else if(westEl > eastEl)
    {
      return "West";
    }
    else 
    {
      return "Equal"; 
    }
  }
  fin.close();
  return 0;
}
