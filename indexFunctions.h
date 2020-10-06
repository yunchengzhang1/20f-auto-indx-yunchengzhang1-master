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
#include <set>
#include <unordered_set>
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
    /*
    bool operator<(const Phrase &x, const Phrase &y)
    {
        if (x.phrase != y.phrase)
        {
            return x.phrase <y.phrase;
        }
        //question: do I need to do the following for bool too?
        //return x.pgNum <y.pgNum;
    }
    */

    //https://www.youtube.com/watch?v=iPlW5tSUOUM
    void fillVector(Vector<Phrase>& newPhrase,myString& newWord, double ID, int pg) {


        //fill in the new object with attributes: myString, bool, bool, int
        Phrase PhraseObj;


        PhraseObj.setID(ID);
        PhraseObj.setPhrase(newWord);
        PhraseObj.setNum(pg);

        cout<<"object fill complete"<<endl;

        //push the new phrase object PhraseObj into the vector newPhrase
        newPhrase.pushback(PhraseObj);
        cout<<endl<<"push complete"<<endl;
    }
    /*
    void fillTest(vector<Phrase>& newPhrase,myString& newWord, bool isParent, int pg) {

        //set child bool to default 0
        bool isChild=false;

        //fill in the new object with attributes: myString, bool, bool, int
        Phrase PhraseObj;

        PhraseObj.setChild(isChild);
        PhraseObj.setParent(isParent);
        PhraseObj.setPhrase(newWord);
        PhraseObj.setNum(pg);

        cout<<"object fill complete"<<endl;

        //push the new phrase object PhraseObj into the vector newPhrase
        newPhrase.push_back(PhraseObj);
        cout<<"pushback complete"<<endl;
    }
    */


    double pwrTen (int pwr)
    {
        double base=10;
        double result=1;
        int ex=pwr;

        while (ex!=0)
        {
            result*=base;
            --ex;
        }
        return result;
    }

    //pass in a phrase, calculate its ID
    double calcID (char*in, int page)
    {
        int word_size= sizeof(in);
        double wordID=0.0;
        for (int i=0; i<(word_size); i++)
        {
            //get 2 digit nums that's unique for every alphabet
            double temp1= (double) (in[i] - '.');  //2 digit
            int pwr= 99-(2*i);                  //power
            double powerofTen= pwrTen(pwr);
            //multiply the 2 digit num stored in temp1 to a 100-(2 i) digits num
            double temp2= temp1 * powerofTen;
            wordID+=temp2;
        }
        //stored in the "end" of the ID
        double tempPG= (double) page;
        wordID+=tempPG;

        return wordID;
    }


    void editP(char* in)
    {
        for (int i=0; i<100; i++)
        {
            if (in[i]==')')
            {
                in[i]='.';
            }

            if (in[i]=='[') {
                int j=i;
                while (in[j]!=']')
                {
                    if (in[j]==' ')
                    {
                        in[j]='.';
                    }
                    j++;
                }
                in[i]=' ';
            }

            if (in[i]==']')
            {in[i]='.';}
        }
    }

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



    void run() {


        double multiplier= pwrTen (2);

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
        ifstream file("input03.txt");
        char *temp = new char[100];
        char *wordTemp = new char[15];

        //DSvector to contain myPhrase
        Vector<Phrase> myPhrase;

        //create set to put object into
        unordered_set<Phrase> phraseSet;


        //iterate through file
        for (int i = 1; i < 20; i++) {
            //read line
            file.getline(temp, 200);
            //char array to myString
            myString line = temp;

            //extract the value of number inside "<>"
            int page = extractPG(line);
            int tempPG;
            if (page==-1)
            {break;} //if reaches end of file, break for-loop

            if (page!=0)  //if reaches a page number
            {
                tempPG= page;
                cout <<endl<< "page number is: " << tempPG << endl;
            }
            else {cout<<endl<<"string of words: ";}


            //char array to lowerCase
            int toLower=sizeof(temp);
            for (int i=0; i<toLower;i++)
            {
                if (temp[i]>='A' && temp[i]<='Z')
                {
                    temp[i]= temp[i]+ 32;
                }
            }
            //all to lowercase
            line.lowerCase();
            //edit punctuations
            //turn phrases within "[]" are: "[one.phrase]"
            //turn all the parent phrases "()" are " parent)"
            line.replaceP(line);
            editP(temp);





            //only parse the string of words, but not index
            if (page==0) {
                //allocate new object
                //Phrase *tempPhrase;
                //tempPhrase= new Phrase(NULL, false, false, 0);

                //get the first word

                char *word = strtok(temp, " ");

                while (word != NULL) {

                    int word_size = sizeof(word);
                    double fullID = 0;
                    double multiplier= pwrTen (100);

                    char *tempWord= word;


                    //if detected parent word, set isParent to true, pass it
                    if (tempWord[word_size-1] == '.') {
                        //when pass in child(parent
                        //parse them by '('
                        char *childTmp = strtok(tempWord, "(");
                        char *parentTmp = strtok(NULL, "(");
                        //calculate childID= calcID(childTmp)
                        double childID= calcID(childTmp, page);
                        //calculate parentID= calcID(parentTmp)
                        //          parentID= parentID * multiplier
                        double parentID= calcID(parentTmp, page);
                        parentID= parentID * multiplier;
                        //calculate the full child ID= parentID+ childID
                        childID=parentID+ childID;
                        //acquire myString for parent and child to pass
                        myString parentStr= parentTmp;
                        myString childStr = childTmp;
                        //fill vector with data
                        fillVector (myPhrase, parentStr, parentID, page);
                        fillVector (myPhrase, childStr , childID, page);

                    }
                    else{
                        fullID= calcID(word, page);
                        fullID= fullID * multiplier;
                        myString tempStr = word;
                        fillVector (myPhrase, tempStr, fullID, page);
                    }



                    myString tempStr = word;

                    cout << tempStr << " ";


                    //tempPhrase= fillObject(tempStr, isParent, tempPG);
                    //fillTest(phraseVector, tempStr, isParent, tempPG);
                    //get following words
                    word = strtok(NULL, " ");
                }//end of word!=NULL loop means that if while there are words left in  line
            }//end of if (page!=0) means that if page has phrases


            for (const Phrase &p: myPhrase)
            {
                phraseSet.insert(p);
            }
            for (const Phrase&p: phraseSet)
            {
                myString tempString=p.getPhrase();
                int tempPage=p.getNum();
                cout<<tempString<<" appears on page "<<tempPage<<endl;
            }

            }//end of run




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


        file.close();
        }

};






#endif //INC_20F_AUTO_IDX_INDEXFUNCTIONS_H
