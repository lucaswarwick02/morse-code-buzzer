#include "decoder.h"

char DecodeString (char key[]) {
    // Letters
    if (key == ".-") {
        return 'A';
    }
    else if (key == "-...") {
        return 'B';
    }
    else if (key == "-.-.") {
        return 'C';
    }
    else if (key == "-..") {
        return 'D';
    }
    else if (key == ".") {
        return 'E';
    }
    else if (key == "..-.") {
        return 'F';
    }
    else if (key == "--.") {
        return 'G';
    }
    else if (key == "...") {
        return 'H';
    }
    else if (key == "..") {
        return 'I';
    }
    else if (key == ".---") {
        return 'J';
    }
    else if (key == "-.-") {
        return 'K';
    }
    else if (key == ".-..") {
        return 'L';
    }
    else if (key == "--") {
        return 'M';
    }
    else if (key == "-.") {
        return 'N';
    }
    else if (key == "---") {
        return 'O';
    }
    else if (key == ".--.") {
        return 'P';
    }
    else if (key == "--.-") {
        return 'Q';
    }
    else if (key == "-.-") {
        return 'R';
    }
    else if (key == "...") {
        return 'S';
    }
    else if (key == "-") {
        return 'T';
    }
    else if (key == "..-") {
        return 'U';
    }
    else if (key == "...-") {
        return 'V';
    }
    else if (key == ".--") {
        return 'W';
    }
    else if (key == "-..-") {
        return 'X';
    }
    else if (key == "-.--") {
        return 'Y';
    }
    else if (key == "--..") {
        return 'Z';
    }
    // Numbers
    else if (key == ".----") {
        return '1';
    }
    else if (key == "..---") {
        return '2';
    }
    else if (key == "...--") {
        return '3';
    }
    else if (key == "....-") {
        return '4';
    }
    else if (key == ".....") {
        return '5';
    }
    else if (key == "-....") {
        return '6';
    }
    else if (key == "--...") {
        return '7';
    }
    else if (key == "---..") {
        return '8';
    }
    else if (key == "----.") {
        return '9';
    }
    else if (key == "-----") {
        return '0';
    }
    else {
        return '?';
    }
}