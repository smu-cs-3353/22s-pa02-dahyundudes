#include "DSString.h"
#include <iostream>
#include <string>

DSString::DSString() {
    str = new char[1];
}

DSString::DSString(const char* s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    str[strlen(s)] = '\0';
}

DSString::DSString(const DSString& s) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}

DSString::~DSString() {
    delete[] str;
}

DSString& DSString::operator=(const char* s) {
    if (this->str != nullptr) {
        delete[] this->str;
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        str[strlen(s)] = '\0';
    }
    return *this;
}

DSString& DSString::operator=(const DSString& s) {
    if (this->str != nullptr) {
        delete[] this->str;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
        str[strlen(s.str)] = '\0';
    }
    return *this;
}

DSString DSString::operator+(const DSString& s) {
    char* temp = new char[strlen(this->str) + strlen(s.str) + 1];
    strcpy(temp, this->str);
    strcat(temp, s.str);
    DSString result(temp);
    delete[] temp;
    return result;
}

bool DSString::operator==(const char* s) const {
    return strcmp(str, s) == 0;
}

bool DSString::operator==(const DSString& s) const {
    return strcmp(str, s.str) == 0;
}

bool DSString::operator>(const DSString& s) const {
    return strcmp(str, s.str) > 0;
}
bool DSString::operator>=(const DSString& s) const {
    return strcmp(str, s.str) >= 0;
}

bool DSString::operator<(const DSString& s) const {
    return strcmp(s.str, str) > 0;
}

bool DSString::operator<=(const DSString& s) const {
    return strcmp(s.str, str) >= 0;
}

char& DSString::operator[](const int num) const {
    return *(str + num);
}

int DSString::getLength() {
    return strlen(str);
}

int DSString::find(char c) {
    int i = 0;
    while (*(str + i) != c && i < getLength()) {
        i++;
    }
    return (i == getLength()) ? -1 : i;
}

int DSString::find(char c, int count) {
    int num = 0;
    int i = 0;
    while ((*(str + i) != c || num < count) && i < getLength()) {
        i++;
        if (*(str + i) == c)
            num++;
    }
    return (i == getLength()) ? -1 : i;
}

int DSString::findLast(char c) {
    int i = getLength() - 1;
    while (*(str + i) != c && i >= 0) {
        i--;
    }
    return (i == getLength()) ? -1 : i;
}

DSString DSString::substring(int start, int numChars) {
    if (numChars == -1)
        numChars = 0;
    DSString temp;
    temp.str = new char[numChars + 1];
    strncpy(temp.str, this->str + start, numChars);
    temp.str[numChars] = '\0';
    return temp;

}

char* DSString::c_str() {
    return str;
}

void DSString::toLower() {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        if (str[i] == 33 || str[i] == 46 || str[i] == 63) {
            //str[i] = ' ';
        }
    }
}

void DSString::toUpper() {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
}

int DSString::convertInt() {
    return std::stoi(str);
}

std::ostream& operator<<(std::ostream& fout, const DSString& s) {
    fout << s.str;
    return fout;
}