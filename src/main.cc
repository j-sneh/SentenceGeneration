#include "graph.h"
#include <iostream>

// int main () {
int main (int argc, char** argv) {
    if (argc == 0) {
        std::cout << argv[0];
    }
    /*
    starting bit of parsed_book1.txt
    the boy who lived mr and mrs dursley of number four privet drive were proud
    */
   
    // if (argc < 3) {
    //     std::cout << "Usage: " <<  argv[0] << " [filename]" << std::endl;
    //     return 1;
    // }

    //Graph g (argv[1]);
    Graph g ("tests/non_greedy1.txt");
    // std::cout <<  g.LowestGreedySentence("hello", 3) << std::endl;
    // std::cout <<  g.LowestGreedySentence("my", 4) << std::endl;
    // std::cout <<  g.LowestGreedySentence("dear", 5) << std::endl;
    // Graph *g = new Graph("processing/parsed_book.txt");
    // g.WriteToCSV("graph.csv");
    // g.WriteToCSVRunning("graph_running.csv");
    //g.ReadGraph();
    // g.PrintAdjacents(argv[1]);

    std::cout << g.HighestWeightSentence("hello", 3) << std::endl;
    // std::cout << g->ProbabilisticSentence("harry", 20) << std::endl;
    // std::cout << g.HighestWeightSentence("hello", 1);
    // std::cout << g.HighestWeightSentence("hello", 2);
    // std::cout << g.HighestWeightSentence("hello", 3);
    // std::cout << g.HighestWeightSentence("hello", 4);
    
    // std::cout << g.HighestGreedySentence("yer", 4) << std::endl;
    //g->WriteAsBFS("bfs_test.txt", "harry");
    // std::cout << g->LowestGreedySentence("harry", 20) << std::endl;

}