#include "Graph.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
Graph::Graph() {}

/*
 * if    already found i will tell the user
 * else  i will insert it
 */
void Graph::addCity(string name)
{
  //  auto found = city.find(name);
    if (searchCityInFile(name))
    {
        cout << name << " City is already exist in our Map" << endl;
        // I want to insert code display the city info for the user
    }
    else {
        city[name];
        //save data into file
        ofstream ofile;
        ofile.open("myfile.txt");
        ofile << endl << name << ":(";
        ofile.close();
    }
}


/*
 * if        two cities are not in the graph
 * else if   first city is not in the graph
 * else if   second city is not in the graph
 * else      we can add this edge between 2 cities
 */
void Graph::addEdge(string city1, string city2, double weight)
{
    if (searchCityInFile(city1) && searchCityInFile(city2))
    {
        cout << "Sorry can not add this edge as [ " << city1 << " ] and [ " << city2 << " ] is not in graph." << endl;
        //try add these cities
    }
    else if (searchCityInFile(city1))
    {
        cout << "Sorry can not add this edge as [ " << city1 << " ] is on graph." << endl;
        ofstream ofile;
        ofile.open("myfile.txt");
        ofile << city2 << "," << weight << ")";
        ofile << endl;
        ofile.close();
    }
    else if (searchCityInFile(city2))
    {
        ofstream ofile;
        ofile.open("myfile.txt");
        ofile << endl << city1 << ":(";
        ofile.close();
    }
    else {
        city[city1].push_back({ city2,weight });
        ofstream ofile;
        ofile.open("myfile.txt");
        ofile << city1 << ":(" << city2 << "," << weight << ")";
        ofile << endl;   
        ofile.close();
        
    }
}

void Graph::displayGraph()
{
    cout << "The Graph Data is" << endl;
    cout << "----------------------------------------------------------------" << endl;
    // Read file into map
    ifstream ifile("myfile.txt");
    string line;
    while (getline(ifile,line)){
        cout << line << endl;
    }
  ifile.close();
}


bool Graph::searchCityInFile(string city)
{
    ifstream file("myfile.txt");
    string line;
    while (getline(file, line)) {
        if (line.find(city) != string::npos) {
            return true;
        }
    }
    file.close();
    return false;
}
