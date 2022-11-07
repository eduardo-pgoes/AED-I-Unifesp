#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    DATA STRUCTURES
*/
typedef struct {
  char left;
  char right;
} Pair; // Symbol pairs - for example, in "{}", "{" would be the left char and "}" the right char.

typedef struct {
    char* string;
    Pair* pairs;
} Sequence; // DS that contains the string to be considered and all the available pairs

/* 
    FUNCTION PROTOTYPES
*/
void readPair(Pair p);

/*
    FUNCTION IMPLEMENTATIONS
*/
void readPair(Pair p) {
    printf("Left: %c\nRight: %c\n", p.left, p.right);
}

int main() {
    int n_pairs, n_chars; // number of pairs and number of characters in input sequence
    scanf("%d %d", &n_pairs, &n_chars);
    
    // list of pairs
    Pair* pairs = (Pair*) malloc(sizeof(Pair) * n_pairs);
    
    // reads all pairs
    for (int i = 0; i < n_pairs; i++) {    
        scanf(" %c %c", &pairs[i].left, &pairs[i].right);
        readPair(pairs[i]);
    }

    // reads the sequence
    Sequence seq;
    seq.pairs = pairs;

    char* sequence = (char*) malloc(sizeof(char) * n_chars);
    // remove trailing newline
    getchar();
    for (int i = 0; i < n_chars; i++) {
        char c;
        scanf("%c", &c);
        printf("%c", c);
        strcat(sequence, &c);
    }
    for (int i = 0; i < n_chars; i++) {
        printf("%c", sequence[i]);
    }
}