#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;
int main()
{
    Graph g;
    ofstream ofile;
    ofile.open("myfile.txt");
    ofile << "cairo" << ":(" << "Giza" << "," << "8.3" << ")";
    ofile << "(" << "Alexandria" << "," << "218" << ")";
    ofile << "(" << "Zagazig" << ", " << "86" << ")";
    ofile << "(" << "Ismailia" << ", " << "126" << ")" << endl;
    ofile << "Banisuef" << ":(" << "Giza" << "," << "8.3" << ")" << endl;
    ofile.close();
    g.addCity("newyork");
   g.addEdge("newyork", "losangles", 126);
 g.displayGraph();
}


