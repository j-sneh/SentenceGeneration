#include "graph.h"
#include <iostream>

int main (int argc, char** argv) {
    /*
    starting bit of parsed_book1.txt
    the boy who lived mr and mrs dursley of number four privet drive were proud
    */
   
    if (argc < 3) {
        std::cout << argc << argv[0] << std::endl;
        std::cout << "give a word" << std::endl;
        return 1;
    }

    Graph g ("parsed_book1.txt");
    g.WriteToCSV("graph.csv");
    //g.ReadGraph();
    // g.PrintAdjacents(argv[1]);

    std::cout << g.HighestWeightSentence(argv[1], std::stoi(argv[2])) << std::endl;

}