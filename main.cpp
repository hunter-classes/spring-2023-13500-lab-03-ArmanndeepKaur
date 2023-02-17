#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  //Task A --> East basin storage 
  std::cout<<"Enter Date: 02/16/2018\n"<<"East basin storage: "<<get_east_storage("02/16/2018")<<" billion gallons\n";
  std::cout<<"Enter Date: 04/26/2018\n"<<"East basin storage: "<<get_east_storage("04/26/2018")<<" billion gallons\n"; 
  std::cout<<"Enter Date: 09/15/2018\n"<<"East basin storage: "<<get_east_storage("09/15/2018")<<" billion gallons\n";  
  std::cout<<"Enter Date: 11/27/2018\n"<<"East basin storage: "<<get_east_storage("11/27/2018")<<" billion gallons\n";  


  //Task B --> Minimum and Maximum Storage in East Basin
  std::cout<<"Minimum Storage in East basin: "<<get_min_east()<<" billion gallons\n";
  std::cout<<"Maximum Storage in East basin: "<<get_max_east()<<" billion gallons\n";


  //Task C --> Comparing elevations
  std::cout<<"Enter Date: 01/02/2018\n"<<"On a specified date, the west basin elevation is: "<<compare_basins("01/02/2018")<<"\n";
  std::cout<<"Enter Date: 07/15/2018\n"<<"On a specified date, the west basin elevation is: "<<compare_basins("07/15/2018")<<"\n";
  std::cout<<"Enter Date: 12/22/2018\n"<<"On a specified date, the west basin elevation is: "<<compare_basins("12/22/2018")<<"\n";

  //Task D --> Reverse Order 
  std::cout<<"Enter earlier date: 06/07/2018\n"<<"Enter later date: 11/15/2028\n";
  reverse_order("06/07/2018", "11/15/2018"); 


  return 0;
}
