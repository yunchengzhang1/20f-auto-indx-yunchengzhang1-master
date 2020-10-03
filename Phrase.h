//
// Created by Arthu on 9/30/2020.
//

#ifndef INC_20F_AUTO_IDX_PHRASE_H
#define INC_20F_AUTO_IDX_PHRASE_H
#include "myString.h"
#include "LinkedList.h"
#include "myVector.h"



class Phrase {
public:
    //default constructor
    Phrase(){}

    //overload
    Phrase(const myString &phrase, bool parent, bool child, int pageNum): phrase(phrase){}

    //destr
    ~Phrase() {}

    //accessor functions
    void setPhrase(myString &phrase) {
        Phrase::phrase=phrase;
    }

    void setParent(bool parent){
        Phrase::parent=parent;
    }

    void setChild(bool child){
        Phrase::child=child;
    }

    void setNum(int pageNum){
        Phrase::pageNum=pageNum;
    }

    const myString &getPhrase() const{
        return phrase;
    }

    bool getParent(){
        return parent;
    }

    bool getChild(){
        return child;
    }

    int getNum(){
        return pageNum;
    }

private:
    myString phrase;
    int pageNum;

    bool parent;
    bool child;
};
#endif //INC_20F_AUTO_IDX_PHRASE_H