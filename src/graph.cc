#include "graph.h"
#include <iostream>
#include <fstream>
/*

*/
Graph::Graph(string filename) {
    std::ifstream text(filename);

    if(!text.is_open()) throw std::runtime_error("Cannot be opened");
    
    string prev;
    string curr;
    text >> prev; // Skip the first element
    int counter = 0;
    while(text >> curr){
        //if(counter == 50) break;
        if(graph.count(prev)){ //key exists in map
            //curr exists in Word 
            //curr does not exist in Word
        }
        else{ // key does not exist in map
            graph[prev] = Word();
            graph[prev].word = prev;
            
        }

        graph[prev].adjacents[curr] += 1;
        prev = curr;
        counter ++;
    }

    text.close();
}

string Graph::HighestWeightSentence(int length) {
    std::cout << length << std::endl;
    return "";
}

void Graph::ReadGraph(){
    // for(auto i: graph){
    //     std::cout << i.first << std::endl;
    //     auto& adj = i.second.adjacents;

    // }
}

void Graph::PrintAdjacents(string word) {
    Word word_info = graph[word];

    for (auto pair : word_info.adjacents) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}