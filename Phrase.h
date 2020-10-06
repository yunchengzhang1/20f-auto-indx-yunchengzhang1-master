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

    double ID;
    //default constructor
    Phrase(){}

    //overload
    Phrase(const myString &phrase, double ID, int pageNum): phrase(phrase){}

    /*
    //operator
    Phrase& operator= ( Phrase cpy)
    {
        phrase=cpy.getPhrase();
        parent=cpy.getParent();
        child=cpy.getChild();
        pageNum=getNum();
        return *this;
    }*/


    //destr
    ~Phrase()=default;



    //accessor functions
    void setPhrase(myString &phrase) {
        Phrase::phrase=phrase;
    }

    void setID(double ID){
        Phrase::ID=ID;
    }


    void setNum(int pageNum){
        Phrase::pageNum=pageNum;
    }

    const myString &getPhrase() const{
        return phrase;
    }

    bool getID(){
        return ID;
    }

    int getNum(){
        return pageNum;
    }

    //void pushbackPG(int pg)



private:

};

void destruct (Phrase* ptr)
{delete ptr; }
#endif //INC_20F_AUTO_IDX_PHRASE_H
