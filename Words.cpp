/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Words.cpp
 * Author: Grant Elliott
 * 
 * Created on April 17, 2020, 11:55 AM
 */

#include "Words.h"

Words::Words() {
}

Words::Words(const Words& orig) {
}

Words::~Words() {
}
void Words::ReadIn(string fileName){
    ifstream din;
    din.open(fileName.c_str());
	//If file can not be found output error
    if (din.fail())
    {
        cout << "Error: Could not open " << fileName << endl;     
    }
    
    // Process input file
    string str = "";
    while (din >> str)
    {
        // Convert str to lower case
        str = FixWord(str);
        
        //Place words in vector
        word.emplace_back(str);
    }
    HybridSort();
    Frequency(word);
}
//Convert word to lowercase
string Words::FixWord(string word){
    string result = "";
    for (int i=0; i<(int)word.length(); i++)
    {
        // Save special character
        if (word[i] == '\'')
            result += word[i];
        
        // Save lower case letters
        else if ((word[i] >= 'a') && (word[i] <= 'z'))
            result += word[i];
        
        // Save upper case letters as lower case letters
        else if ((word[i] >= 'A') && (word[i] <= 'Z'))
            result += word[i] - 'A' + 'a';
    }
    return result;
}

//Sort words alphabetically
void Words::HybridSort(){
    vector<string> sortedWord[26];
    string holder = "";
    //Quickly sort each word in the array and place into a new array. Place = first letter of the word - int value of the character 'a'
    for (int i = 0;i<word.size();i++){
        holder = word[i];
        char first = holder[0];
        int place = first -'a';
        sortedWord[place].push_back(holder);
    }
    //Pass the roughly sorted array, named sortedWord, through merge sort to complete the rest of the sorting
    for (int a = 0;a<26;a++){
        MergeSortHelper(sortedWord[a]);
    }
    //clear the unsorted vector of words
    word.clear();
    //place the sorted words back into the vector "word"
    for (int a=0;a<26;a++){
        for(int i = 0; i<sortedWord[a].size();i++){
            holder = sortedWord[a][i];
            word.push_back(holder);
        }
    }
   
    
}
void Words::MergeSortHelper(vector<string> &words){
    int high = words.size();
    string newWords[high];
    string sortedNewWords[high];
    
    for (int i = 0;i<high;i++){
        newWords[i]=words[i];
    }
    MergeSort(newWords,sortedNewWords, 0, high);
    for (int i = 0;i<high;i++){
        words[i]=newWords[i];
    }
    
}

void Words::MergeSort(string words[],string copy[],int low, int high){
    // Check terminating condition
   int range = high - low + 1;
   if (range > 1)
   {
      // Divide the array and sort both halves
      int mid = (low + high) / 2;
      MergeSort(words, copy, low, mid);
      MergeSort(words, copy, mid + 1, high);

      // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index = 0;

      // Merge smallest words elements into copy array
      while (index1 <= mid && index2 <= (high-1))
      {
	 if (words[index1] < words[index2])
	    copy[index++] = words[index1++];
	 else
	    copy[index++] = words[index2++];
      }

     
      // Copy any remaining entries from the first half
      while (index1 <= mid){
          copy[index++] = words[index1++];
      }
	 

      // Copy any remaining entries from the second half
      while (index2 <= (high-1)){
	      copy[index++] = words[index2++];
      }
      
      // Copy words back from the temporary array
      for (index = 0; index < range-1; index++)
	 words[low + index] = copy[index];
	 
	 
   }
}
//Calculate frequency of each word
void Words::Frequency(vector<string> &word){
    int index = 0, counter = 0;
    string temp ="";
    ofstream outputFile;
    outputFile.open("book.count");
    
    for(int i =0;i<word.size()-1;i++){
        temp = word[i];
        index = i;
        int flag = -1;
        
        while((temp==word[index])&&(flag==-1)){
            if(index<=word.size()-2){
                counter++;
                index++;
            }else{
                flag=0;
            }
        }
        
        outputFile<<counter<<"\t"<<temp<<endl;
        counter = 0;
        i = index-1;
        
    }
    
    outputFile.close();
}