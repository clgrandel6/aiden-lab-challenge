  /* File: challenge1a.c
 2  * Author: Nicolas Grandel
 3  * --------------------------
 4  *  This file contains code responding to Challenge 1A given by the Aiden Lab for job applications
 5  *  in winter 2016.
 6  */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* Function: check_buckets_helper
 * ------------------------------
 * This function actually does the heavy lifting for finding a path to the target value; it recursively checks the entire array
 * to find a path to the target value, checking every possible path. The remainder of the target value divided by one of the buckets
 * is initially passed in the wrapper to minimize runtime.
 */
int check_buckets_helper(int bucket_sizes[], int target_value, int index)
{
    if(target_value < 0 || bucket_sizes[index] == 0) return 0; //If we've overshot target value or reached the end of the array, return 0
    if(target_value == 0 || (target_value % bucket_sizes[index]) == 0) return 1; //If we have found a path to the target_value, return 1

    int result = 0; //Local variable init

    index = 0;//Zero index to consider entire array
    while(result == 0 && bucket_sizes[index] != 0) { //While we still have buckets to consider and we haven't found a path
        result = check_buckets_helper(bucket_sizes, target_value - bucket_sizes[index], index); //Check each bucket to see if there is a path
        index++;
    }
    return result;
}

/* Function: check_buckets
 * ---------------------------------
 * This function acts as a wrapper for the recursive check_buckets_helper function. It takes the remainder of the target value divided by
 * each bucket and then calls the recursive function on the result.
 */
int check_buckets(int bucket_sizes[], int target_value)
{
    int i = 0; //Iterator init
    while(bucket_sizes[i] != 0) {//0 acts as flag for end of array
        //Doesn't bother with buckets larger than target value, calls recursive function on remainder of target value and current bucket to minimize runtime
        if(bucket_sizes[i] < target_value && check_buckets_helper(bucket_sizes, target_value % bucket_sizes[i], 0) == 1) return 1;
        i++;
    }
    return 0;//If no method found, return 0
}

/* Function: main
 * ---------------------
 * This function acts as a driver for the remianing code found in this file. It takes the arguments passed in the function call
 * and creates the paramters for check_buckets from them.
 * Note: main also pads bucket_sizes with a zero at the end of the array, to mark the end of the array for later use.
 */
int main(int argc, const char *argv[])
{
    assert(argc > 2); //Must be at least two extra arguments passed to function, a bucket and a target (argc counts call as an arg)

    int arr_sz; //Local variable declaration
    int target_value;
    arr_sz = argc - 1; //arrsz is equal to number of buckets passed + 1, to pad array with 0
    int bucket_sizes[arr_sz];

    for(int i = 1; i < argc - 1; i++) {
        assert(sscanf(argv[i], "%d", &bucket_sizes[i - 1]) == 1); //Scan in argument to bucket_sizes, make sure argument is integer
        assert(bucket_sizes[i - 1] != 0); //No 0 buckets allowed
    }
    bucket_sizes[arr_sz - 1] = 0; //Pad array
    assert(sscanf(argv[argc - 1], "%d", &target_value) == 1);//Scan in target_value; again, make sure argument is integer
    printf("%d \n", check_buckets(bucket_sizes, target_value)); //check_buckets!
}
