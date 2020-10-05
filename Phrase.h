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
    myString phrase;
    int pageNum;

    bool parent;
    bool child;
    //default constructor
    Phrase(){}

    //overload
    Phrase(const myString &phrase, bool parent, bool child, int pageNum): phrase(phrase){}

    //operator
    Phrase& operator= (const Phrase* cpy)
    {
        phrase=cpy->phrase;
        parent=cpy->parent;
        child=cpy->child;
        pageNum=cpy->pageNum;
        return *this;
    }

    //dynamic destr
    friend void destruct (Phrase*);



    //destr
    ~Phrase() {}

    //dynamic set
    void dymSet (myString newStr, bool newP, bool newC, int newN)
    {
        phrase= newStr;
        parent= newP;
        child= newC;
        pageNum= newN;
    }


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

};

void destruct (Phrase* ptr)
{delete ptr; }
#endif //INC_20F_AUTO_IDX_PHRASE_H
