#include "graph.h"
#include <iostream>

// int main () {

void help() {
     std::cout << std::endl;
     std::cout << "OPTIONS: " << std::endl;
     std::cout << "To pull up this menu:\t\t\t\t\t\"0\"" << std::endl;
     std::cout << "To generate the highest weight sentence:\t\t\"1 [start word]  [length]\"" << std::endl;
     std::cout << "To generate a greedy highest-weight sentence:\t\t\"2 [start word]  [length]\"" << std::endl;
     std::cout << "To generate a greedy lowest-weight sentence:\t\t\"3 [start word]  [length]\"" << std::endl;
     std::cout << "To generate a random highest-weight sentence:\t\t\"4 [start word]  [length]\"" << std::endl;
     std::cout << "To generate a random lowest-weight sentence:\t\t\"5 [start word]  [length]\"" << std::endl;
     std::cout << "To view words that are n-degrees away (BFS):\t\t\"6 [output file] [start word]\"" << std::endl;
     std::cout << "To view the graph as adjacency lists:\t\t\t\"7 [output file] [start word]\"" << std::endl;
     std::cout << "To leave the program:\t\t\t\t\t\"8\"" << std::endl;
     std::cout << std::endl;
}
int main (int argc, char** argv) {
    /*
    starting bit of parsed_book1.txt
    the boy who lived mr and mrs dursley of number four privet drive were proud
    */
   
    if (argc < 2) {
        std::cout << "Usage: " <<  argv[0] << " [filename]" << std::endl;
        return 1;
    }

    srand(time(NULL));
    srand(rand());

    //Graph g (argv[1]);
    Graph g (argv[1]);

    std::cout << argv[1] << " has been parsed into graph!" << std::endl;
    help();

    while (true) {
        if ()

    }
    // std::cout <<  g.LowestGreedySentence("hello", 3) << std::endl;
    // std::cout <<  g.LowestGreedySentence("my", 4) << std::endl;
    // std::cout <<  g.LowestGreedySentence("dear", 5) << std::endl;
    // Graph *g = new Graph("processing/parsed_book.txt");
    // g->WriteToCSV("display_greed1.csv");
    // g.WriteToCSVRunning("graph_running.csv");
    //g.ReadGraph();
    // g.PrintAdjacents(argv[1]);

    std::cout << g.HighestWeightSentence("my", 3) << std::endl;
    // std::cout << g->ProbabilisticSentence("harry", 20) << std::endl;
    // std::cout << g.HighestWeightSentence("hello", 1);
    // std::cout << g.HighestWeightSentence("hello", 2);
    // std::cout << g.HighestWeightSentence("hello", 3);
    // std::cout << g.HighestWeightSentence("hello", 4);
    
    // std::cout << g.HighestGreedySentence("yer", 4) << std::endl;
    // g.WriteAsBFS("bfs_test.txt", "sleep");
    // g.WriteAsBFS("bfs_test.txt", "hello");
    // std::cout << g->LowestGreedySentence("harry", 20) << std::endl;

}