#include "decoder.h"

char DecodeString (char key[]) {
    printf("Decoding: %s\n", key);
    // Letters
    if (strcmp(key, ".-") == 0) {
        return 'A';
    }
    else if (strcmp(key, "-...") == 0) {
        return 'B';
    }
    else if (strcmp(key, "-.-.") == 0) {
        return 'C';
    }
    else if (strcmp(key, "-..") == 0) {
        return 'D';
    }
    else if (strcmp(key, ".") == 0) {
        return 'E';
    }
    else if (strcmp(key, "..-.") == 0) {
        return 'F';
    }
    else if (strcmp(key, "--.") == 0) {
        return 'G';
    }
    else if (strcmp(key, "...") == 0) {
        return 'H';
    }
    else if (strcmp(key, "..") == 0) {
        return 'I';
    }
    else if (strcmp(key, ".---") == 0) {
        return 'J';
    }
    else if (strcmp(key, "-.-") == 0) {
        return 'K';
    }
    else if (strcmp(key, ".-..") == 0) {
        return 'L';
    }
    else if (strcmp(key, "--") == 0) {
        return 'M';
    }
    else if (strcmp(key, "-.") == 0) {
        return 'N';
    }
    else if (strcmp(key, "---") == 0) {
        return 'O';
    }
    else if (strcmp(key, ".--.") == 0) {
        return 'P';
    }
    else if (strcmp(key, "--.-") == 0) {
        return 'Q';
    }
    else if (strcmp(key, "-.-") == 0) {
        return 'R';
    }
    else if (strcmp(key, "...") == 0) {
        return 'S';
    }
    else if (strcmp(key, "-") == 0) {
        return 'T';
    }
    else if (strcmp(key, "..-") == 0) {
        return 'U';
    }
    else if (strcmp(key, "...-") == 0) {
        return 'V';
    }
    else if (strcmp(key, ".--") == 0) {
        return 'W';
    }
    else if (strcmp(key, "-..-") == 0) {
        return 'X';
    }
    else if (strcmp(key, "-.--") == 0) {
        return 'Y';
    }
    else if (strcmp(key, "--..") == 0) {
        return 'Z';
    }
    // Numbers
    else if (strcmp(key, ".----") == 0) {
        return '1';
    }
    else if (strcmp(key, "..---") == 0) {
        return '2';
    }
    else if (strcmp(key, "...--") == 0) {
        return '3';
    }
    else if (strcmp(key, "....-") == 0) {
        return '4';
    }
    else if (strcmp(key, ".....") == 0) {
        return '5';
    }
    else if (strcmp(key, "-....") == 0) {
        return '6';
    }
    else if (strcmp(key, "--...") == 0) {
        return '7';
    }
    else if (strcmp(key, "---..") == 0) {
        return '8';
    }
    else if (strcmp(key, "----.") == 0) {
        return '9';
    }
    else if (strcmp(key, "-----") == 0) {
        return '0';
    }
    else {
        return '?';
    }
}