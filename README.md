# aiden-lab-challenge
Responses to Challenge 1 given by the Aiden Lab in Winter 2016

Challenge 1A (challenge1a.c)

* This program, written in C, takes at least two numbers of type (int) as its arguments, constructs an array of integers known as bucket_sizes, and places every number but the last in this array. It then recursively checks to see if the numbers in the array can be summed in some combination to reach the last parameter. This checking is done using the function "int check_buckets(int bucket_sizes[], int target_value)"; it should be noted that this function requires a 0 to be the final number in the array; main() handles this entry, and the program halts if a 0 is passed as an argument.  
* Example commandline call: ./challenge1a 2 7 9
**bucket_sizes = [2, 7]; target_value = 9

# Challenge 1B (challenge1b.cpp, dictionary.txt)
