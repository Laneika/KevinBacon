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

int main2() {
    
   
    cout << "Please choose an actor or movie:  " << endl;
    
    string input;
    
    getline(cin, input);
    
  
    
    
    
    LabeledGraph Laneikagraph("movies.txt");
    
    map<int, int> myMap = Laneikagraph.BreathFirstSearch(Laneikagraph.index(input));
    
    
    map<int, int> PersonalityHistogramMap = Laneikagraph.personalityHistogram();
   
    for (map<int,int>::iterator actors = PersonalityHistogramMap.begin(); actors!= PersonalityHistogramMap.end(); ++actors)
        
    cout << actors->first << " => " << actors->second << '\n';

    
    return 0;
}

