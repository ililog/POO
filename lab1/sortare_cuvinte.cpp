#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<algorithm>
#include<iostream>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 1000

bool compareWords(char *a, char *b) {

    int len1 = strlen(a);   
    int len2 = strlen(b);

    if (len1 != len2) {
        return len1 > len2;
    }

    int ok = strcmp(a, b);
    if (ok != 1) {
        return 1;
    }
    return 0;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char *words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a sentence: ");
    
    if (scanf("%[^\n]", sentence) != 1) {
        return 1;
    }

    char *token = strtok(sentence, " ");
    while (token != NULL && wordCount < MAX_WORDS) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    std::sort(words, words+wordCount, compareWords);

    printf("\nSorted words:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}