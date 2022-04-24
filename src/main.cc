#include "graph.h"
#include <iostream>

int main (int argc, char** argv) {
    /*
    starting bit of parsed_book1.txt
    the boy who lived mr and mrs dursley of number four privet drive were proud
    */

    if (argc < 2) {
        std::cout << "give a word" << std::endl;
    }

    Graph g ("parsed_book1.txt");
    //g.ReadGraph();
    g.PrintAdjacents(argv[1]);
}