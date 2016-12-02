# aiden-lab-challenge
Responses to Challenge 1 given by the Aiden Lab in Winter 2016

Challenge 1A (challenge1a.c)

* This program, written in C, takes at least two numbers of type (int) as its arguments, constructs an array of integers known as bucket_sizes, and places every number but the last in this array. It then recursively checks to see if the numbers in the array can be summed in some combination to reach the last parameter. This checking is done using the function "int check_buckets(int bucket_sizes[], int target_value)"; it should be noted that this function requires a 0 to be the final number in the array; main() handles this entry, and the program halts if a 0 is passed as an argument.  
* Example command line call: ./challenge1a 2 7 9
   * bucket_sizes = [2, 7, 0]; target_value = 9

Challenge 1B (challenge1b.cpp, dictionary.txt)

* This program, written in C++, takes a number-containing string and translates it into a string containing a combination of numbers and letters which are useful in attempting to remember the string of numbers. This is done by associating 3 letters with each number 1-9 (with 1 being associated with a, b, and c, and 9 being associated with y and z) and attempting to buid words from those associations. The words are checked against a dictionary file (the provided dictionary.txt works quite nicely, though you can provide your own if you wish, as long as it is formatted with one word per line), and put into the result string if there is a matching word in the dictionary file. This process is greatly accelerated by the use of a map associating number strings with dictionary entries; rather than attempting to translate individual numbers to one of two or three letters, it simply translates all the words in the dictionary file to a string at the beginning, and then translates as many words as the user likes by simply finding the associated word for a given number entry. 
* A few things to be aware of:
  * It is important to note that the program technically accepts any C++ string, but only numbers are translated.
  * The number string is actually given to the program during runtime as an input, not as a parameter passed during the function call.
* Example input/output combination: 
  * Input: 32156464
  * Output: gean 6464
  
Compiling

* As you have access to the following libraries, you should have no troubles compiling/executing any of this code:
  * stdlib.h, stdio.h, assert.h, iostream,  map, fstream, string
  
Citations

* The dictionary.txt file is actually the The UK Advanced Cryptics Dictionary by Ross Beresford. The rest of the copyright information can be found in the "UKACD17_copyright_information.txt" file. Copyright (c) J Ross Beresford 1993-2000. All Rights Reserved.

        The following restriction is placed on the use of this
        publication: if The UK Advanced Cryptics Dictionary is used
        in a software package or redistributed in any form, the
        copyright notice must be prominently displayed and the text
        of this document must be included verbatim.

        There are no other restrictions: I would like to see the
        list distributed as widely as possible.
