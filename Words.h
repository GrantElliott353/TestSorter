
/* 
 * File:   Words.h
 * Author: Grant Elliott
 *
 * Created on April 17, 2020, 11:55 AM
 */

#ifndef WORDS_H
#define WORDS_H

using namespace std;
#include<iostream>
#include <vector>
#include<cstring>
#include<fstream>

class Words {
public:
    Words();
    Words(const Words& orig);
    ~Words();
    void ReadIn(string fileName);
    string FixWord(string word);
    void HybridSort();
    void MergeSort(string words[],string copy[],int low, int high);
    void Frequency(vector<string> &word);
    
private:
    void MergeSortHelper(vector<string> &words);
    vector <string> word;
    
    
    
};

#endif /* WORDS_H */
