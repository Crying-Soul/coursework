#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
typedef struct {
    char* sentence;
} Sentence;


typedef struct {
    Sentence* sentences;
    int num_sentences; 
} Text;
#endif