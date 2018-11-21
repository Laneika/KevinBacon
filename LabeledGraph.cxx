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

LabeledGraph::LabeledGraph(std::string movieFile){
   string line;
    ifstream file(movieFile.c_str());
   if(file.is_open())
   {
       while(getline(file, line))
       {
            std::vector<std::string> v;
            std::istringstream is1( line );
            std::string t;
            
            // Split the line
     while ( std::getline( is1, t, '/' ) )
            {
                if ( t.empty() ) v.push_back( "/" );
                else v.push_back( t );
            }
            for ( int i = 0; i < v.size(); i++)
             {
                LabeledGraph::add_vertex(v[i]);
                if (i!=0){
                    LabeledGraph::add_edge(v[0], v[i]);
                }
                
            }

            
       }
       file.close();
   }
   else cout <<"unable to open file";
}


std::map<int, int> LabeledGraph::BreathFirstSearch(int v)
{
    int start_state = v;
    
    distances[v] = 0;
    
    map<int, int> parent_state;
    parent_state[start_state] = -1;
   
    bool *visited = new bool[V()];
    for(int i = 0; i < V(); i++)
    {
        visited[i] = false;
    }

    queue<int> open_set;
 
    visited[start_state] = true;
    open_set.push(start_state);
 
   
    while(!open_set.empty())
    {
       
        start_state = open_set.front();
        open_set.pop();
 
        set<int>var = neighbors(start_state);
        std::set<int>::const_iterator child_state;
        for (child_state = var.begin(); child_state != var.end(); ++child_state)
         {
            if (!visited[*child_state])
            {
                visited[*child_state] = true;
                distances[*child_state] = distances[v] +1; 
                open_set.push(*child_state);
                parent_state[*child_state] = start_state;
            }
         }
    }
    return parent_state;
}


bool fncomp (int lhs, int rhs) {return lhs>rhs;}

std::map<int, int> LabeledGraph::BreathFirstSearch2(int v)
{
    int start_state = v;
      
    distances[v] = 0;
    
    map<int, int> parent_state;
    parent_state[start_state]= -1;
    
    bool *visited = new bool[V()];
    for(int i = 0; i < V(); i++)
    {
        visited[i] = false;
        
    }
    
    queue<int> open_set;
 
    visited[v] = true;
    open_set.push(start_state);
 
    while(!open_set.empty())
    {
       
        start_state = open_set.front();
        open_set.pop();
        
        bool(*fn_tp)(int,int) = fncomp;
        
        std::set<int,bool(*)(int,int)> var (fn_tp);
        
        var = neighbors2(start_state);
        
        std::set<int>::const_iterator child_state;
        
        for (child_state = var.begin(); child_state != var.end(); ++child_state)
         {
            if (!visited[*child_state])
                
            {
                distances[*child_state]= distances[v]+1;
                visited[*child_state] = true;
                open_set.push(*child_state);
                parent_state[*child_state]= start_state;
                
            }
         }
    }
    return parent_state;
}

std::vector<int> LabeledGraph::pathTo(std::map<int,int> &parent_map, int target)
{
    vector<int> Lpath;
    int t = target;
    while(parent_map[t] != -1)
    {
       
        Lpath.push_back(t);
        t = parent_map[t];
    }
    Lpath.push_back(t);
    return Lpath;
        
}

void LabeledGraph::PrintPath(std::vector<int> path)
{
    for(int i=0; i<path.size(); i++)
    {
    cout<<getName(path[i])<<endl;
    }
        
}

void LabeledGraph::add_vertex(string vlabel){
  labels.push_back(vlabel);
  indexedLabels.insert(pair<string, int>(vlabel, V()));
  indexedLabels2.insert(pair<int, string>(V(), vlabel));
  set<int> s;
  edges.push_back(s);
}

void LabeledGraph::add_edge(string source, string target){
    if (!contains(source))
      add_vertex(source);
    if (!contains(target))
      add_vertex(target);
    edges[indexedLabels[source]].insert(indexedLabels[target]);
    edges[indexedLabels[target]].insert(indexedLabels[source]);
    nedges++;
}

bool LabeledGraph::contains(string vlabel) const {
  return indexedLabels.find(vlabel) != indexedLabels.end();
}

set<int> LabeledGraph::neighbors(int v) const{
    return edges[v];
}

set<int,bool(*)(int,int)> LabeledGraph::neighbors2(int v) const{
   bool(*fn_tp)(int,int) = fncomp;
   std::set<int,bool(*)(int,int)> result (fn_tp);
    //iterate through  edges[v]; and insert each item into result
    std::set<int> neigb = edges[v];
    std::set<int>::const_iterator it;
        for (it =neigb.begin(); it != neigb.end(); ++it)
         {
            result.insert(*it); 
        }
    return result;
}

string LabeledGraph::label(int v) const {
    return labels[v];
}

int LabeledGraph::index(string vlabel) {
    return indexedLabels[vlabel];
}

string LabeledGraph::getName(int i) const {
    string name = "";
    std::map<int,std::string>::const_iterator displayName;
    displayName = indexedLabels2.find(i);
    name = displayName->second;
    return name;
}

ostream& operator<< (ostream &out, const LabeledGraph &g) {
    
    string movie = "";
    
    for(int i = 0; i < g.edges.size(); i++)
    {
        out << i << "----->";
        movie.append(g.getName(i) + "\n");
        std::set<int> neighbors = g.edges.at(i);
        
        for (std::set<int>::iterator it=neighbors.begin(); it!=neighbors.end(); ++it)
        {
            std::cout << ' ' << *it;
            movie.append("    " + g.getName(*it) + "\n");
        }
         std::cout << endl;
    }
    
    cout << movie ;
  return out;
}

std::map<int, int> LabeledGraph::personalityHistogram(){
    std::map<int, int> PersonalityNumbers;
    
     for(int i = 0; i < edges.size(); i++){
         
         int distance = distanceTo(i);
         
        PersonalityNumbers[distance] = PersonalityNumbers[distance]+1;
     }
    
    return PersonalityNumbers;
}


