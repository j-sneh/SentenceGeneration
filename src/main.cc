#include "graph.h"
#include <iostream>

int main (int argc, char** argv) {
    /*
    starting bit of parsed_book1.txt
    the boy who lived mr and mrs dursley of number four privet drive were proud
    */
   
    if (argc < 3) {
        std::cout << "Usage: " <<  argv[0] << " [filename] [starting word] [length]" << std::endl;
        return 1;
    }

    Graph g (argv[1]);
    g.WriteToCSV("graph.csv");
    //g.ReadGraph();
    // g.PrintAdjacents(argv[1]);

    std::cout << g.HighestWeightSentence(argv[2], std::stoi(argv[3])) << std::endl;

}