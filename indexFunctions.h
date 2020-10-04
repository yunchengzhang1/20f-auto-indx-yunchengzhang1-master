//
// Created by Arthu on 9/28/2020.
//

#ifndef INC_20F_AUTO_IDX_INDEXFUNCTIONS_H
#define INC_20F_AUTO_IDX_INDEXFUNCTIONS_H

//#include "catch.hpp"
#include <fstream>
#include <iostream>
#include "myString.cpp"
#include "myString.h"
#include "LinkedList.h"
#include "myVector.h"
#include "indexFunctions.h"
#include "Phrase.h"

class indexFunc {
private:



public:
    Phrase phr;

/*
    void readFile()
    {



    }
*/

    /*
    void genWord (int i, int j, int g )
    {

    }
    */

    void parsingWord(myString* line,char* wordTemp, int i, int j)  //int i and j are always read as 0
    {

    }

    //https://www.youtube.com/watch?v=iPlW5tSUOUM
    void fillVector(Vector<Phrase>& newPhrase,myString& newWord, bool isParent, int pg) {

        //set child bool to default 0
        bool isChild=false;

        //fill in the new object with attributes: myString, bool, bool, int
        Phrase PhraseObj;
        PhraseObj.phrase= newWord;
        PhraseObj.parent= isParent;
        PhraseObj.child= isChild;
        PhraseObj.pageNum=pg;

        //push the new phrase object PhraseObj into the vector newPhrase
        newPhrase.pushback(PhraseObj);
    }

    void editP(char* in)
    {
        for (int i=0; i<100; i++)
        {
            if (in[i]=='(')
            {
                in[i]=' ';
            }

            if (in[i]=='[') {
                while (in[i]!=']')
                {
                    if (in[i]==' ')
                    {
                        in[i]='.';
                    }
                }
            }
        }
    }


    void run() {

        //initialize head
        struct node *head = NULL;
        //initialize linked lists: initial FirstRead LinkedList
        LL<myString> LinkedList;
        // linked list
        LL<myString> inWord;

        //initialize string
        myString myStr;
        //word parsed
        myString parsedWord;


        //open file input01.txt
        ifstream file("input01.txt");
        char *temp = new char[100];
        char *wordTemp = new char[15];

        //DSvector to contain myPhrase
        Vector<Phrase> myPhrase;


        //iterate through file
        for (int i = 1; i < 20; i++) {
            //read line
            file.getline(temp, 200);
            //char array to myString
            myString line = temp;



            //all to lowercase
            line.lowerCase();
            //edit punctuations
            //turn phrases within "[]" are: "[one.phrase]"
            //turn all the parent phrases "()" are " parent)"
            line.replaceP(line);
            editP(temp);


            //extract the value of number inside "<>"
            int page = extractPG(line);
            if (page!=0)
            {
                cout <<endl<< "page number is: " << page << endl;
            }
            else {cout<<endl<<"string of words: ";}


            //only parse the string of words, but not index
            if (page==0)
            {
                //get the first word
                char* word= strtok(temp," ");
                while (word!=NULL)
                {
                    bool isParent=false;


                    //if detected parent word, set isParent to 1, pass it
                    if (word[sizeof(word)-1]==')' )
                    {bool isParent=true;}
                    myString tempStr= word;

                    cout<<tempStr<<" ";

                    //use the fill vector function by providing: targeted vector
                    fillVector(myPhrase,tempStr, isParent, page);

                    //get following words
                    word=strtok(NULL," ");
                }
            }




            /*
            //parsing starts
            int a = 0;
            int b = 0;
            //if doesn't read in a page number
            if (page == 0) {

                /*
                //place parsing here
                //parsingWord(line,wordTemp, 0, 0);

                int leng= line.getlength();
                //while j< leng
                while (b<=leng)  {
                    b++;
                    //if normal word
                    if (line[b]==' ') {
                        //move the temp digit of i forward to j's position
                        for (int g=b; g<b; g++)
                        {
                            int sub1=g-a;
                            //populate wordTemp to form 1 word, g-i starts from 0 and increments
                            wordTemp[sub1]=line[g]; }
                        //turn char array to myString
                        parsedWord= wordTemp;
                        //put the parsed word into object Phrase as an attribute
                        phr.setPhrase(parsedWord);
                        a=b;
                    }// end of ' ' if statement

                    //if runs into a multi parts phrase [one word]
                    else if (line[b]=='[') {
                        int k=b+1;
                        while (line[k]!=']') {
                            wordTemp[k-a-1]=line[k];
                            k++;
                        }//end of while loop to populate wordTemp
                        //turn char array to myString
                        parsedWord= wordTemp;
                        //put the parsed word into object Phrase as an attribute
                        phr.setPhrase(parsedWord);
                        b=k;
                    }
                }//while (j<leng) ends

            }//parsing ends
            */


            //LinkedList.addAfter(line);

            //}
            //LinkedList.removeData("a");
            //int found;
            //found= LinkedList.findIndex(&head, );
            //cout<<LinkedList<<endl;



        }
        file.close();
};

    int extractPG(myString &line) {
        //extractPG used values
        int indexN = 0;   //index number/digit
        int indexC = 0;   //index counter
        int indexV = 0;   //index value
        int power;
        int tempInt = 0;


        if (line[0] == '<' && line[1] != '-') {
            indexC = line.getlength() - 1;
            //actual val of num: line[1] to line[indexC-1]
            power = 1;
            for (int p = indexC - 1; p > 0; p--) {

                //cout << line[p ] << endl;  //first loop:1

                indexN = (int) (line[p] - '0');  //line[p] is last digit, power: 10^0

                while (power > 1) {
                    indexN = indexN*10;
                    power--;
                }//while (power)
                indexV = indexV + indexN;
                tempInt++;
                power += tempInt;
            }//for (p)
            return indexV;
        } else if (line[1] == '-') {
            return -1;
        } else {
            return 0;
        }

    }
};



#endif //INC_20F_AUTO_IDX_INDEXFUNCTIONS_H
