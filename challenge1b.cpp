/* File: challenge1b.cpp
 * Author: Nicolas Grandel
 * ------------------------------------
 * This file contains code responding to Challenge 1B given by the Aiden Lab for job applications
 * in Winter 2016.
 */
#include <iostream>
#include <stdlib.h>
#include <map>
#include <fstream>
#include <string>

using namespace std;

/* Function: word2num
 * -----------------------
 * word2num does most of the work in num2word; it actually translates words into numbers by finding the associated number for each given letter
 * by associating each triplet of letters with a number (1->a,b,c; 2->c,d,e;... 9->y,z). 0 is not given an associated letter, and if an input string
 * contains a zero, it is retained in the translation.
 */
string word2num(string word) {
    string num; //Local variable initialization
    int length = word.length();

    for (int i = 0; i < length; i++) {
        num += (char) ((word[i] - 97) / 3 + 49); //Each number from 1-9 gets three letters; math is just to find right unicode value
    }
    return num;
}

/* Function: build_dictionary
 * ---------------------------------
 * build_dictionary uses the file "dictionary.txt" to build a map from number inputs to translated words. The actual translation
 * occurs in word2num; this function really just reads in the input, calls word2num to get the associated number, and then puts in the map entry.
 */
map<string, string> build_dictionary()
{
    map<string, string> dictionary; //Local variable initialization

    ifstream ifs;
    ifs.open("dictionary.txt");

    string str;
    getline(ifs, str);
    string num;

    while(!ifs.fail()) {//Read in words from dictionary file (one word per line)
        num = word2num(str);
        dictionary[num] = str;
        getline(ifs, str);
    }

    ifs.close();//Close the file stream
    return dictionary;
}

/* Function: num2word_helper
 * ---------------------------------
 * num2word_helper is a recursive function that finds translations of numbers into words using a map from numbers to words. Rather than
 * doing the translating itself, it provides progressively smaller sections of an input string to the dictionary map until a translation is found.
 * If no translation is found, it leaves the first number as is and attempts to translate the remainder of the string with a call to itself.
 */
string num2word_helper(string num, map<string,string> &dictionary) {
    if (num.compare("") == 0) return "";//Base case; if no digits left, finish

    int length = num.length(); //Local variable init
    string subnum;

    for(int i = 0; i < length - 1; i++) {
        subnum = num.substr(0,length - i); //Makes string smaller and smaller until a match is found; 8790 becomes 879, etc.
        if(dictionary.count(subnum) != 0) {
            //return translation of substring, a space, and then the translation of the rest of the string
            return dictionary[subnum] + " " + num2word_helper(num.substr(length - i, i), dictionary);
        }
    }
    return num[0] + num2word_helper(num.substr(1, length - 1), dictionary);//If no translation found, just current digit as is
}

/* Function: num2word
 * ----------------------------
 * num2word acts as a wrapper function, merely calling the appropriate functions to translate the num parameter.
 */
string num2word(string num) {
    map<string, string> dictionary = build_dictionary();

    return num2word_helper(num, dictionary);
}

/* Function: main
 * --------------------------------
 * main acts as a driver for the rest of the code in the file, reading in the input numbers and printing the resulting translation.
 */
int main()
{
    string num;//Local variable init

    while(num.compare("q") != 0) {//End function upon entering "q"; translate as many numbers as the user likes
        cout << "Enter a number in decimal format (q to quit): ";
        getline(cin, num);
        cout << num2word(num) << endl;
    }
    return 0;
}
