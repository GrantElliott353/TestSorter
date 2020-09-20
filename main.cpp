/* 
 * File:   main.cpp
 * Author: Grant Elliott
 *
 * Created on April 17, 2020, 11:47 AM
 */
#include <iostream>
#include <cstdlib>

#include "Words.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Words word;
    string fileName;
    cout<<"Enter the name of the text file (include '.txt'): ";
    cin>> fileName;
    
    word.ReadIn(fileName);
    return 0;
}

