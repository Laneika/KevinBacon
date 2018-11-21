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
#include "LabeledGraph.h"

using namespace std;


int main() {
    
    string userInput;
  
    
    LabeledGraph Laneikagraph("movies.txt");
    
    cout << "Please choose an actor or movie:  ";
    
    getline(cin, userInput);
    
    map<int, int> myMap = Laneikagraph.BreathFirstSearch(Laneikagraph.index(userInput));
    
    map<int, int> myMap2 = Laneikagraph.BreathFirstSearch2(Laneikagraph.index(userInput));
    
    if(Laneikagraph.contains(userInput)){
        
        int i = Laneikagraph.index(userInput);
    }
    else{
        cout<<"No actor with that name. Please try again.  "<<endl;
    }

    cout<<"Please enter an actor or exit:  "<<endl;

   getline(cin, userInput);
    
   while (userInput!= "exit")
    {
      vector<int> path1 = Laneikagraph.pathTo(myMap, Laneikagraph.index(userInput));
      
      vector<int> path2 = Laneikagraph.pathTo(myMap2, Laneikagraph.index(userInput));
        
      for(int i=0; i < path1.size(); i++)
      {
          cout << path1[i] << endl;
      }
      
      for(int i=0; i < path2.size(); i++)
      {
          cout<<path2[i]<<endl;
      }
      
    cout<< "The path length is: " <<  Laneikagraph.distanceTo(Laneikagraph.index(userInput));
    
    Laneikagraph.PrintPath(path1);
    
    cout<< "The path length is: " <<  Laneikagraph.distanceTo(Laneikagraph.index(userInput));
    
    Laneikagraph.PrintPath(path2);    
    
    
    cout << "Please enter an actor or exit:  " << endl;


    getline(cin, userInput);
    }
   
    return 0;
}
