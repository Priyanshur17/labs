//1. Given two character strings s1 and s2. Using C and pthread to write a parallel program to
//find out the number of substrings, in string s1, that are exactly the same as string s2. The
//strings are ended with ‘\0’. For example, suppose number_substring(s1, s2) implements
//the function, then number_substring (“abcdab”, “ab”) = 2, number_substring(“aaa”, “a”)=
//3, number_substring(“abac”, “bc”) = 0. Suppose the size of s1 and s2 are n1 and n2,
//respectively, and p threads are used, we assume that n1 mod p = 0, and n2 < n1/p. Strings
//s1 and s2 are stored in a file named “strings.txt”. String s1 is evenly partitioned among p
//threads to concurrently search for matching with string s2. After a thread finishes its work
//and obtains the number of local matching, this local number is added into a global
//variable showing the total number of matched substrings in string s1. Finally this total
//number is printed out. The format of the strings.txt is like this(the first string iss1 and the
//second one is s2):
//s1: Hello we are doing pthread testing with string.
//s2:in
//HINT: divide the s1 into two half and create two threads to search substring in this two
//half.




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STRING_LENGTH 1000

char s1[MAX_STRING_LENGTH];
char s2[MAX_STRING_LENGTH];
int n1, n2;
int p;
int totalMatches = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* countSubstrings(void* arg) {
    int thread_id = *((int*)arg);
    int matches = 0;

    int chunk_size = n1 / p;
    int start = thread_id * chunk_size;
    int end = start + chunk_size;
    int i;
    for ( i = start; i < end; i++) {
    	int j;
        for ( j = 0; j < n2 && i + j < n1; j++) {
            if (s1[i + j] != s2[j]) {
                break;
            }
            if (j == n2 - 1) {
                matches++;
            }
        }
    }

    pthread_mutex_lock(&mutex);
    totalMatches += matches;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    fgets(s1, MAX_STRING_LENGTH, file);
    fgets(s2, MAX_STRING_LENGTH, file);

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fscanf(file, "%s", s1);
    fscanf(file, "%s", s2);
    fclose(file);

    n1 = strlen(s1);
    n2 = strlen(s2);

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    printf("Enter number of threads: ");
    scanf("%d", &p);

    pthread_t threads[p];
    int thread_ids[p];
    int i;
    for ( i = 0; i < p; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, countSubstrings, &thread_ids[i]);
    }

    for (i = 0; i < p; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total matches: %d\n", totalMatches);

    return 0;
}
