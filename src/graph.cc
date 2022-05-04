#include "graph.h"
#include <iostream>
#include <fstream>
#include <time.h> 
#include <stdlib.h>     /* srand, rand */

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
        // if(counter == 50) break;
        if(!graph.count(prev)){ // key does not exist in map
            graph[prev] = Word();
            graph[prev].word = prev;
            
        }
        
        vector< std::pair<string, size_t> >& adj = graph[prev].adjacents;

        auto word_iter = std::find_if(adj.begin(), adj.end(), [curr](std::pair<string, size_t> p) {return p.first == curr;});
        
        if (word_iter == adj.end()) {
            adj.push_back(std::make_pair(curr, 1));
        } else {
            word_iter->second += 1;
        }
        // graph[prev].adjacents[curr] += 1;
        
        prev = curr;
        counter ++;
    }

    for (auto &it : graph) {
        vector<pair<string, size_t>>& v = it.second.adjacents;
        std::sort(v.begin(), v.end(), 
            [](const pair<string, size_t> & a, const pair<string, size_t> & b)
        { 
            return a.second > b.second; 
        });

    }

    for(auto &it: graph){
        for(auto& elements: it.second.adjacents){
            it.second.buckets.push_back(elements);
        }
    }
    
    for(auto &it : graph){
        size_t running_sum = 0;
        for(auto &i: it.second.buckets){
            i.second += running_sum;
            running_sum = i.second;
        }
    }
    

    text.close();
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

    if (weight > best_weight) {
        best_weight = weight;
        best_sentence = sentence;
    }


    if (sentence.size() == length) {
        visited.erase(word);
        return;
    }

    Word info = graph[word];
    int counter = 0;
    for (const auto& pair : info.adjacents) {
        if (counter++ == info.buckets.back().second/5) {
            break;
        }

        string new_word = pair.first;
        size_t delta_weight = pair.second;

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
void Graph::WriteToCSVRunning(string filename){
     std::ofstream text;
     text.open(filename);
     for(auto i: graph){
        text << "element: " << i.first << "\n";
        for(auto& pair : graph[i.first].buckets){

            text << pair.first << ": " <<  pair.second << " " ;
        }
        text << "\n";
     }
}
string Graph::SentenceDecoder(const vector<string>& words){
    string rv = "";
    for (auto i : words){
        rv += i;
        rv += " ";
    }
    rv.pop_back();
    rv.push_back('.');
    return rv;
}

string Graph::ProbabilisticSentence(string word, size_t length){
    std::cout << word << std::endl;
    std::cout << length << std::endl;
    for(size_t count = 0; count < length; ++count){
        int bucket_length = graph[word].buckets.back().second;

        srand(time(NULL));

        unsigned long bucket = rand() % bucket_length;

        int chosen_index = -1;
        for(unsigned int i = 0; i < graph[word].buckets.size(); ++i){
            if(graph[word].buckets[i].second >= bucket){
                chosen_index = i;
            }
        }

        if(chosen_index == -1) std::cout << "Broken test case";
        
        word = graph[word].buckets[chosen_index].first;
    }


    std::cout << word << std::endl; 
    return word;
}