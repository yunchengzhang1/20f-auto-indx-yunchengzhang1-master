//
// Created by Arthu on 9/16/2020.
//

#ifndef INC_20F_AUTO_IDX_MYSTRING_H
#define INC_20F_AUTO_IDX_MYSTRING_H

#include <cstring>
#include <iostream>
using namespace std;

class myString {
private:
    int size;
    char* array;

public:




    //default constructor
    myString();

    //constructor
    myString(const myString& word);
    //parameterized constructor
    //assign user-wanted specific values to different objects
    myString (const char* cstring);
    //destructor
    //dealocate dynamic data
    ~myString();
    //copy assignment operator
    myString& operator=(const char* cstring);
    myString& operator=(const myString& myString);

    // functions
    int getlength();
    //add a string
    myString append(myString& in);
    //remove a string
    myString substr(int i, int num);
    //find index
    int find(myString &in);
    //replace string
    myString replace(myString&a, myString&b);
    //remove punctuations
    void replaceP(myString& in);

    //static void sort(String array[], int i);

    //reverse string
    void reverse();
    //set to lower case
    void lowerCase();
    //if it's empty
    bool isEmpty();

    int PositiveNegative(myString& in, int boo);

    void wordFilter(myString& in);
    void stopwordFilter(myString& in);
    void charsCounter(myString& in, int *Pccounter, int *Nccounter, int boo);
    void charRanking(int *Pccounter, int*Nccounter, char* Palphabets, char* Nalphabets);
    void testCounter(myString& in, int *TestCounter);

    //compare size
    //int cmp(myString& cmpobj);

    //friend
    //https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm
    //https://stackoverflow.com/questions/3312269/c-friend-function-operator-overloading-istream
    //istream ostream operators
    friend istream& operator>>(istream &input, myString& obj);
    friend ostream& operator<<(ostream &out,myString& obj);
    friend ifstream& getline(ifstream &in,myString& str, const char&delim);

    char& operator[] (unsigned i);
    char operator[] (unsigned j) const;

    myString& operator+= (myString s);
    myString& operator+=(const char* c);

    char* cStr() const;

    friend bool operator<(const myString &lhs, const myString &rhs);
    friend bool operator>(const myString &lhs, const myString &rhs);

};



#endif //INC_20F_AUTO_IDX_MYSTRING_H
