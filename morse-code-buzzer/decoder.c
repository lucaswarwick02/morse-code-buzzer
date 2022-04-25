#include "decoder.h"
#include <string.h>

struct pair {
    char key;
    char value[5];
};

const int LIST_SIZE = 36;

struct pair mappings[36] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'0', "-----"}
};

char * CharToCode (char key) {
    int i;
    for (i = 0; i < LIST_SIZE; i++) {
        if (mappings[i].key == key) return mappings[i].value;
    }
    // Invalid Key
    return "";
}

char CodeToChar (char value[]) {
    int i;
    for (i = 0; i < LIST_SIZE; i++) {
        if (strcmp(mappings[i].value, value) == 0) return mappings[i].key;
    }
    // Invalid Value
    return '?';
}