#include "graph.h"
#include <iostream>
#include <fstream>
#include <time.h> 
#include <stdlib.h>
#include <stdexcept>

Graph::Graph(string filename) {
    std::ifstream text(filename);

    if(!text.is_open()){
        throw std::runtime_error("Cannot be opened");
    }

    string prev;
    string curr;
    text >> prev; // Skip the first element
    while(text >> curr){
        if(!graph.count(prev)){ // key does not exist in map
            graph[prev] = Word();
            graph[prev].word = prev;  
        }
        
        vector< std::pair<string, size_t> >& adj = graph[prev].adjacents;

        //Return an iterator pointing to the element in the adjacents such that the word is equal to current 
        auto word_iter = std::find_if(adj.begin(), adj.end(), 
                                    [curr](std::pair<string, size_t> p) {return p.first == curr;});
        
        if (word_iter == adj.end()) {
            adj.push_back(std::make_pair(curr, 1));
        } else {
            word_iter->second += 1;
        }
        prev = curr;
    }

    // Sort each individual vector in the adjacency list by frequency
    for (auto &it : graph) {
        vector<pair<string, size_t>>& v = it.second.adjacents;
        std::sort(v.begin(), v.end(), 
            [](const pair<string, size_t> & a, const pair<string, size_t> & b){ 
            return a.second > b.second; 
        });
    }

    for(auto &it: graph){
        it.second.buckets = it.second.adjacents;
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

void Graph::WriteAsBFS(string filename, string start) {
    std::ofstream text;
    text.open(filename);

    Word curr = graph[start];
    unordered_set < string > visited;
    queue <Word> to_visit;

    to_visit.push(curr);

    while (!to_visit.empty()) {
        curr = to_visit.front();
        to_visit.pop();

        for (pair<string, size_t>& word_and_weight : curr.adjacents) {
            string w = word_and_weight.first;
            if (!visited.count(w)){
                text << "{" << w << ", " << word_and_weight.second << "}" << " ";
                visited.insert(w);
                to_visit.push(graph[w]);
            } else {
                 text << "(" << w << ", " << word_and_weight.second << ")" << " ";
            }
        }

        text << std::endl;
    }
}

string Graph::SentenceDecoder(const vector<string>& words){
    string rv = "";
    for (const auto& i : words){
        rv += i + " ";
    }
    rv.pop_back();
    rv.push_back('.');
    return rv;
}

string Graph::ProbabilisticSentence(string word, size_t length){
    vector<string> rv;
    rv.push_back(word);
    
    srand(time(NULL));
    srand(rand());

    for(size_t count = 0; count < length - 1; ++count){
        Word& curr_word = graph[word];
        vector< pair<string, size_t> >& curr_buckets = curr_word.buckets;

        int bucket_length = curr_buckets.back().second; // size of cumulative sum of frequencies
        unsigned long bucket = (rand() % bucket_length)+1;
        for(unsigned int i = 0; i < curr_buckets.size(); ++i){
            if (curr_buckets[i].second >= bucket){
                word = curr_buckets[i].first;
                rv.push_back(word);
                break;
            }
        }
        
    }
    return SentenceDecoder(rv);
}

string Graph::HighestGreedySentence(string word, size_t length) {
	string curr = word;
	std::vector<string> v;

	while (!graph[curr].adjacents.empty() && length--) {
		v.push_back(curr);
		curr = graph[curr].adjacents.front().first;
	}

	return SentenceDecoder(v);
}

string Graph::LowestGreedySentence(string word, size_t length) {
	string curr = word;
	std::vector<string> v;

	while (!graph[curr].adjacents.empty() && length--) {
		v.push_back(curr);
		curr = graph[curr].adjacents.back().first;
	}

	return SentenceDecoder(v);
}

string Graph::RandomSentence(string word, size_t length) {
	string curr = word;
	std::vector<string> v;
    srand(time(NULL));
    srand(rand());

	while (!graph[curr].adjacents.empty() && length--) {
		v.push_back(curr);
        int index = rand() % graph[curr].adjacents.size();
		curr = graph[curr].adjacents[index].first;
	}

	return SentenceDecoder(v);
}
