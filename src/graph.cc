#include "graph.h"
#include <iostream>
#include <fstream>
<<<<<<< HEAD
=======
#include <time.h> 
#include <stdlib.h>     /* srand, rand */
>>>>>>> origin/tests

/*

*/
Graph::Graph(string filename) {
    std::ifstream text(filename);

    if(!text.is_open()) throw std::runtime_error("Cannot be opened");
    
    string prev;
    string curr;
    text >> prev; // Skip the first element
    size_t counter = 0;
    while(text >> curr){
        //if(counter == 50) break;
        if(!graph.count(prev)){ // key does not exist in map
            graph[prev] = Word();
            graph[prev].word = prev;
            
        }

        graph[prev].adjacents[curr] += 1;
        prev = curr;
        counter ++;
    }

    text.close();

    for (const auto& pair : graph) {
        Word word_info = pair.second;
        word_info.highest_weight = 0;
        for (const auto& word_weight : word_info.adjacents) {
            size_t weight = word_weight.second;
            word_info.highest_weight = weight < word_info.highest_weight ? word_info.highest_weight : weight;
        } 
    }
}


string Graph::HighestWeightSentence(string word, size_t length) {
    if (length == 1) return word + ".";
    vector<string> sentence = {word};
    vector<string> best_sentence = sentence;
    size_t best_weight = 0;
    
    BacktrackHelper(word, sentence, best_weight, length, best_sentence, best_weight);

    std::cout << length << std::endl;
    visited.clear();
    return SentenceDecoder(best_sentence);
}

void Graph::BacktrackHelper(const string& word, vector<string>& sentence,size_t weight, size_t length, vector<string>& best_sentence, size_t& best_weight) {
    if (visited.count(word)) {
        visited.erase(word);
        return;
    }

    visited.insert(word);


    if (sentence.size() == length) {
<<<<<<< HEAD
        if(weight >= best_weight) {
            best_weight = weight;
            best_sentence = sentence;
        }
=======
        if(weight > best_weight) {
            best_weight = weight;
            best_sentence = sentence;
        }
        if(weight == best_weight){
            srand(time(NULL));
            int replace = rand() % 2;
            if(replace){
                best_weight = weight;
                best_sentence = sentence;
            }
        }
>>>>>>> origin/tests
        visited.erase(word);
        return;
    }

    Word info = graph[word];
    for (const auto& pair : info.adjacents) {
        string new_word = pair.first;
        size_t delta_weight = pair.second;

        if (delta_weight < 0.25 * info.highest_weight)
            continue;

        sentence.push_back(new_word);
        BacktrackHelper(new_word, sentence, weight + delta_weight, length, best_sentence, best_weight);
        sentence.pop_back();
    }
    
    if (visited.count(word)) {
        visited.erase(word);
        return;
    }
    
}

void Graph::PrintAdjacents(string word) {
    Word word_info = graph[word];

    for (auto& pair : word_info.adjacents) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    
}

void Graph::WriteToCSV(string filename){
     std::ofstream text;
     text.open(filename);
     for(auto i: graph){
        text << "element: " << i.first << "\n";
        for(auto& pair : graph[i.first].adjacents){

            text << pair.first << ": " <<  pair.second << " " ;
        }
        text << "\n";
     }
}
string Graph::SentenceDecoder(const vector<string>& words){
    string rv = "";
<<<<<<< HEAD
    //int tracker = 0;
    for (auto i : words){
        // if (tracker == 0) {
        //     rv += i[0].toupper();
        //     rv += i.substr(1, i.length() - 1);
        //     tracker++;
        //     rv += " ";
        // }
        // else {
        rv += i;
        rv += " ";


    }
=======
    for (auto i : words){
        rv += i;
        rv += " ";
    }
    rv.pop_back();
    rv.push_back('.');
>>>>>>> origin/tests
    return rv;
}