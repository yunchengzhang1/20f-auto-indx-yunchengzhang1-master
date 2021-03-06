//
// Created by Arthu on 9/22/2020.
//
//https://www.cs.odu.edu/~zeil/cs361/sum18/Public/vectorImpl/index.html
//https://www.geeksforgeeks.org/program-to-create-custom-vector-class-in-c/
//https://github.com/Mikenekro/Custom_Vector/blob/master/Vector.h
//https://stackoverflow.com/questions/36405596/inheriting-stdvectoriterator-for-custom-class
#ifndef INC_20F_AUTO_IDX_MYVECTOR_H
#define INC_20F_AUTO_IDX_MYVECTOR_H

#include <iostream>
#include "Phrase.h"
using namespace std;


template <class U>
class Vector {
    //arr is the pointer of whatever passes through T, stores the address of the vector
    U *arr;
    //total storage of the vector
    int capacity;
    //number of elements in the vector
    int curr;


public:


    //getters
    //return the capacity
    int getCapacity()
    {return capacity;}
    //return size of vector
    int getSize()
    {return curr;}






    //iterator class implementation starts
    class iterator {
    private:
        U *ptr;
    public:
        iterator() {ptr= nullptr;}

        explicit iterator(U *temp1){ptr= temp1;}

        //to show array on left matches with the one on right
        bool operator==(const iterator &right) const {
            if (ptr==right.ptr)
            {return true;}
            else
                {return false;}
        }

        //or not
        bool operator!=(const iterator &right) const {
            if (ptr!=right.ptr)
            {return true;}
            else
            {return false;}
        }

        //operator on *
        U operator*() const {
            return *ptr;
        }

        //operator on ++
        iterator &operator++() {   //increment ptr
            //ptr++;
            ++ptr;
            return *this;
        }

        //when use Vector+ num
        iterator &operator++(int) {
            iterator temp(*this);
            //increment pointed val
            ++(*this);
            return temp;
        }

    }; //iterator class implementation ends

    void allocate (int newCapacity) {
        //if smaller, do nothing
        if (newCapacity <=capacity)
        {return;}
        //if size of two, replace old capacity
        if (newCapacity > (capacity*2))
        {capacity= newCapacity;}
        else {capacity= capacity*2;}
        //make buffer to fill in data
        U *temp1= new U[capacity];
        //copy original arr
        for (unsigned i=0; i<curr; i++)
        {temp1[i]= arr[i];}
        //clear arr
        delete []arr;  //SIGABRT (aborted)
        //refill arr
        arr= temp1;
    }

    //rule of three
    //constructor
    Vector() {
        arr=new U [1];
        capacity=1;
        curr=0;
    }
    //copy constructor
    Vector(const Vector<U> &cpy) {
        capacity= cpy.capacity;
        curr= cpy.curr;
        arr= new U[capacity];
        for (unsigned i=0; i<curr; i++)
        {arr[i]= cpy.arr[i]; }
    }

    ~Vector(){
        delete[] arr;}
    /*
    Vector(const Vector<Phrase> &cpy) {
        capacity= cpy.capacity;
        curr= cpy.curr;
        arr= new Phrase[capacity];
        for (unsigned i=0; i<curr; i++)
        {arr[i]= cpy.arr[i]; }
    } */
    //copy assignment operator
    Vector <U> &operator= (const Vector<U> &cpy){
        if (this!=cpy) {
            curr= cpy.curr;
            capacity=  cpy.capacity;
            arr= new U[capacity];
            for (unsigned i=0; i<curr; i++)
            {arr[i]= cpy.arr[i]; }
        }
        return *this;
    }
    /*
    Vector <Phrase> &operator= (const Vector<Phrase> &cpy){
        if (this!=cpy) {
            curr= cpy.curr;
            capacity=  cpy.capacity;
            arr= new Phrase[capacity];
            for (unsigned i=0; i<curr; i++)
            {arr[i]= cpy.arr[i]; }
        }
        return *this;
    }*/


    //iterator start
    U* begin() const
    {
        return arr;
    }

    //iterator end
    U* end() const
    {
        return arr+curr;
    }

    //functions:
    //return the # of elements in array after pushing
    void pushback(U in){
        allocate(curr+1);
        arr[curr++]=in;
    }


    //return the popped element
    U popback()
    {
        //pop 1 from curr after
        curr--;
        //return popped element
        return arr[curr-1];
    }



    //set the val stored at index at ele
    void set_at(U data, int index)
    {
        arr[index]= data;
    }

    //get element
    U get(int i)
    {
        return arr[i];
    }

    //printout
    char* printout()
    {
        char* out;
        for (unsigned i=0; i<curr;i++)
        {
            out+=arr[i];
        }
        return (out);
    }


    //get operator, return the value at index [i]
    U& operator[](int i)
    {
        return *(arr+i);
    }




    /*
    template <class V>
    friend ostream & operator<<(ostream & os, const LL<V> & dll){
        //getting dll ready for print
        dll.printout(os);
        return os;
    }

    //print out vector
    void printout(ostream& out= cout) const
    {
        iterator ptr;
        //for: ptr begins with the arr size, ends with (arr+curr)
        for (ptr=begin(); ptr!=end(); ptr++)
        {
            //print pointed value
            cout<< *ptr<<' ';
        }
        cout<< endl;
    }
    */
};











#endif //INC_20F_AUTO_IDX_MYVECTOR_H
