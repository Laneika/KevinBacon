#include <set>
#include <map>
#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <list>
#include <sstream>
#include <queue>
#include <cassert>
#include "LabeledGraph.h"



using namespace std;

int main3()
{
    
 
  cout << "TestDistance.cpp"<<endl;
   
  LabeledGraph LaneikaTest("movies.txt");
  
  int distance;
   
   map<int, int> myMap = LaneikaTest.BreathFirstSearch(LaneikaTest.index("Bacon, Kevin"));
  
   distance =  LaneikaTest.distanceTo(LaneikaTest.index("Müller, Wolfgang"));
   
   cout << distance << endl;
   
   assert(distance == 4);
   distance =  LaneikaTest.distanceTo(LaneikaTest.index("Wager, Tony"));
   
   cout << distance << endl;
   
   assert(distance == 4);
   distance =  LaneikaTest.distanceTo(LaneikaTest.index("Beatty, Warren"));
      
   cout << distance << endl;
      
   assert(distance == 4);
   distance =  LaneikaTest.distanceTo(LaneikaTest.index("Miller, Bob"));
      
   cout << distance << endl;
      
   assert(distance == 6);
  

}
