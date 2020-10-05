//
// Created by Arthu on 9/16/2020.
//

#include "myString.h"
#include <cstring>
//default constructor
myString::myString()
{
    //assign&initiate array value
    array = new char[1];
    array[0]='\0';
    //initiate int size
    size=0;
}

//
myString::myString(const myString& word)
{
    //deallocate old array
    //delete [] array;
    //cout<<"deallocate old array"<<endl;
    //new size
    size = word.size;
    // \0
    //size++;
    //new array size
    array = new char[size+1];

    strcpy(array, word.array);
    //put word into array
    /*for(int i=0; i<size; i++)
    {
        array[i]= word.array[i];
    }*/
    //end-note is \0
    array[size-1]='\0';
}

myString::myString (const char* cstring)
{
    int counter=0;
    //while loop ends when reach the ending \0
    while (cstring[counter]!='\0')
    {
        counter++;
    }
    //use counter to measure size
    size=counter;
    //initiate array size
    array = new char[size+1];
    //load data into array
    for(int i=0; i<size; i++)
    {
        array[i]= cstring[i];
    }
    array[size]='\0';
}
//destructor
myString::~myString()
{   //deallocate
    delete[]array;

    //cout<<"deallocate array in destructor"<<endl;
}
//operator 1
myString& myString:: operator=(const char* cstring)
{
    //cout<<"deallocate array in operator 1"<<endl;
    int index=0;
    //while the data stored in index in this array isn't end character
    while (cstring[index]!='\0')
    {index++;}
    //plus 1 because starts 0
    index+=1;
    size=index;
    //plus 1 for the end char
    array= new char[size+1];
    for (int i=0; i<size; i++)
    {
        array[i]= cstring[i];
    }
    //end char is \0
    array[size]='\0';
    //return object
    return *this;
}

myString& myString:: operator=(const myString& myString)
{
    /*
    //cout<<"deallocate array in operator 1"<<endl;
    int index=0;
    //while the data stored in index in this array isn't end character
    while (myString[index]!='\0')
    {index++;}
    //plus 1 because starts 0
    index+=1;
    size=index;
     */
    size=myString.size;
    //plus 1 for the end char
    array= new char[size+1];
    for (int i=0; i<size; i++)
    {
        array[i]= myString[i];
    }
    //end char is \0
    array[size]='\0';
    //return object
    return *this;
}

int myString::getlength()
{
    return size;
}

myString myString::append(myString& in)
{
    //size of added content on top of old text
    int totalsize=in.size+size;
    //dynamically allocate new char
    char* newArray= new char[totalsize];
    //sync array size
    for(int i=0; i<size; i++)
    {
        newArray[i]=array[i];
    }
    //sync array index
    for(int j=size; j<totalsize; j++)
    {
        newArray[j]= in.array[j-size];
    }
    //expand size
    size= totalsize;
    //deallocate
    //delete[]array;
    //cout<<"deallocate array in append"<<endl;
    //size=totalsize;
    //array=newArray;

    //initiate array
    array= new char[size+1];
    //loop to put data in newArray into array: [old_data________]+[_______new_data]= [old_datanew_data]
    for(int k=0; k<size; k++)
    {
        array[k]=newArray[k];
    }

    //end-note is \0
    array[size]='\0';
    //deallocate newArray
    delete[]newArray;
    //cout<<"deallocate newArray in append"<<endl;

    return *this;
}
//substr: copy x amount of characters starting from index y, from position a to b: string b=a.substr(y, x);
myString myString:: substr(int i, int num)
{
    myString myStr;
    //if i less than 0 or i larger/equal than/with size, return myStr
    if (i<0||i>=size)
    {
        return myStr;
    }
    //define myStr size
    myStr.size= num;
    //http://www.cplusplus.com/reference/algorithm/min/: returns the smallest of a and b, if equal return a
    int minimum=min(size-i, num);
    myStr.array= new char[minimum++];
    //
    for(int j=i; j<i+num && j<size; j++)
    {
        myStr.array[minimum]='\0';
    }
    return myStr;
}

void myString:: replaceP(myString& in)
{
    for (int i=0; i<size; i++)
    {
        if (in.array[i]=='(')
        {
            in.array[i]=' ';
        }

        if (in.array[i]=='[') {
            int j=i;
            while (in.array[j]!=']')
            {
                if (in.array[j]==' ')
                {
                    in.array[j]='.';
                }
                j++;
            }
        }

    }

}



void myString:: lowerCase()
{
    for (int i=0; i<size; i++)
    {
        //if ASCII num between A to Z
        if (array[i]>='A' && array[i]<='Z')
        {
            //https://commons.wikimedia.org/wiki/File:ASCII-Table.svg
            array[i]= (char) (array[i]-('A'-'a'));
        }
    }
}

int myString:: PositiveNegative(myString& in, int boo)
{

    if (in.array[0]=='p')
    {
        boo=1;
    }

    else if (in.array[0]=='n')
    {
        boo=0;
    }
    else
    {
        //error
        boo=3;
    }

    return boo;

}


//return the location of the target
int myString::find(myString &in)
{
    //outer loop: iterate until reach the same size
    for(int i=1; i<size+1; i++)
    {
        //if data at the index in "array" equals data stored in index 0 of in.array[], and it's found inside "in"
        if (array[i]==in.array[0] && size-i>=in.size)
        {
            //default not found
            bool found=0;
            //inner loop
            int endofword=in.getlength()+i;
            for(int j=i; j<endofword; j++)
            {
                if(array[j]==in.array[j-i]&& array[j-1]==' ' &&array[endofword]==' ')
                {
                    //if match, found=1, return index
                    found=1;
                    break;
                }
            }
            //return the index of the found
            if(found)
            {return i;}
        }
    }
    //return value-1
    return -1;
}
//replace target a with a new string b
myString myString::replace(myString&a, myString&b)
{
    while(find(a)!=-1)
    {
        int index= find(a);
        int num= a.size;
        //allocate new char array with size of b size+ origin size-num
        char* newArray= new char[size-num+b.size];
        //cpy the old array to new
        for(int i=0; i<index; i++ )
        {
            newArray[i]= array[i];
        }
        //
        for(int j=index; j<b.getlength()+index; j++)
        {
            newArray[j]= a.array[j-index];
        }
        //
        for(int k=index+num; k<size; k++)
        {
            newArray[k-num+ b.getlength()] = array[k];
        }
        size= size-num+b.getlength();
        //deallocate array
        delete[] array;
        //cout<<"deallocate array in replace"<<endl;
        //allocate new char array with size of "size"+1
        array= new char[size+1];
        //fill array with data in newArray
        for(int l=0; l<size; l++)
        {
            array[l]= newArray[l];
        }
        //array ends with \0
        array[size]='\0';
        //deallocate newArray
        delete[] newArray;
        //cout<<"deallocate newArray in replace"<<endl;
    }
    //return object
    return *this;
}

void myString:: reverse()
{
    //allocate new char array end
    char*arrend=new char[size];
    //initiate with empty value
    for(int i=0; i<size; i++)
    {
        arrend[i]=' ';
    }
    //allocate new char array newArray
    char*newArray= new char[size];
    // for-loop to save the data in the temporary array to array end
    for(int j=0; j<size; j++)
    {
        int sizecounter=0;
        //while j is smaller than size AND array[i] is not empty
        while (j<size && array[j]!=' ')
        {
            newArray[sizecounter++]= array[j++];
        }
        int index=0;
        int k=size-j;
        //inner for-loop to put data in newArray into end
        for(k,index; index<sizecounter; k++,index++ )
        {
            arrend[k]= newArray[index];
        }
    }
    //for-loop to copy data in array end to array (beginning)
    for(int l=0; l<size; l++)
    {
        array[l]= arrend[l];
    }
    //deallocate end-array and temporary newArray
    delete[] arrend;
    //cout<<"deallocate arrend in reverse"<<endl;
    delete[] newArray;
    //cout<<"deallocate newArray in reverse"<<endl;
}

bool myString::isEmpty()
{
    return !size;
}

void myString::stopwordFilter(myString& in)
{


    for (int i=0; i<size; i++) {
        if (in.array[i] == ' ' && in.array[i + 4] == ' ') {
            in.array[i] = ' ';
            in.array[i + 1] = ' ';
            in.array[i + 2] = ' ';
            in.array[i + 3] = ' ';

        }
    }

    for (int i=0; i<size; i++) {
        if (in.array[i] == ' ' && in.array[i + 3] == ' ') {
            in.array[i] = ' ';
            in.array[i + 1] = ' ';
            in.array[i + 2] = ' ';

        }
    }

    for (int i=0; i<size; i++) {
        if (in.array[i] == ' ' && in.array[i + 2] == ' ') {
            in.array[i] = ' ';
            in.array[i + 1] = ' ';

        }
    }

    for (int i=0; i<size; i++) {
        if (in.array[i] == ' ' && in.array[i + 6] == ' ') {
            in.array[i] = ' ';
            in.array[i + 1] = ' ';
            in.array[i + 2] = ' ';
            in.array[i + 3] = ' ';
            in.array[i + 4] = ' ';
            in.array[i + 5] = ' ';

        }
    }
}




//remove stopwords
void myString::wordFilter(myString& in)
{
    myString target= "uncomfortable";

    int found=0;
    //while found something, remove the word
    while(true)
    {
        found = in.find(target);
        if (found!=-1){
            int indexend=found+target.size;
            for (found; found<indexend; found++) {
                in.array[found] = ' ';

            }
        }
        else {break;}

    }


}




/* compare size
int myString::cmp(myString& cmpobj)
{
    if (size==cmpobj.size)
    {
        //iterate through to either
        for(int i=0; i<size; i++)
        {
            if (array[i]==cmpobj.array[i])
            {
                return 1;
            }
        }
    }
}*/

//friend class operators
//https://stackoverflow.com/questions/3312269/c-friend-function-operator-overloading-istream

//input
istream& operator>>(istream &input, myString& obj)
{
    //filt to the object array
    input>>obj.array;
    //
    int index=0;
    while(obj.array[index]!='\0')
    {index++; }
    obj.size=index;
    return input;
}

//output
ostream& operator<<(ostream &output, myString& obj)
{
    output<<obj.array;
    return output;
}

//getline
//http://www.cplusplus.com/reference/istream/istream/getline/
//https://www.geeksforgeeks.org/getline-string-c/
/*ifstream& getline(ifstream &in, myString& str, const char&delim)
{

    //initiate char
    char c;
   //
   str="";


    while(in.get(c))
   {
       str+= (c);
       if(c=delim)
       {
           break;
       }
   }

   return in;



}*/
//char operator
//https://en.cppreference.com/w/cpp/keyword/throw
char& myString:: operator[] (unsigned i)
{
    if(i>=size) throw 1;
    return array[i];
}

char myString::operator[] (unsigned j) const
{
    if (j >= size) throw 1;
    return array[j];
}

//plus operator override
myString& myString::operator+= (myString s){
    //length= total size= size+new input size
    unsigned length = size+s.getlength();
    //new char array with the size of length
    char* str=new char[length];
    //fill the first part of the array: [fillinhere___]
    for(int i = 0;i<size;i++){
        str[i]=array[i];
    }
    //fill the second part of the array: [alreadyfilled_fillinhere]
    for(int i = 0;i<s.size;i++){
        str[size+1]=s[i];

    }
    //deallocate
    delete array;
    size = length;
    array= str;
    return *this;

}
myString& myString::operator+=(const char *entry){
    int length=0;
    while (entry[length]!='\0'){
        length++;
    }
    int len = size+1;
    char* arr= new char[length];
    for(int i = 0;i<getlength();i++){
        arr[i]=array[i];

    }
    for(int i =0;i<length;i++){
        arr[size+1]=entry[i];
    }
    delete array;
    size = len;
    array = arr;
    return *this;
}

char* myString:: cStr() const {return array;}

bool operator<(const myString &lhs, const myString &rhs)
{
    return strcmp(lhs.cStr(), rhs.cStr())<0;
}

bool operator>(const myString &lhs, const myString &rhs)
{
    return strcmp(lhs.cStr(), rhs.cStr())>0;
}

