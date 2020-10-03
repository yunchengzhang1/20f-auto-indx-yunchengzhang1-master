//
// Created by Arthu on 9/15/2020.
//
#ifndef INC_20F_AUTO_IDX_LINKEDLIST_H
#define INC_20F_AUTO_IDX_LINKEDLIST_H

#include <iostream>
using namespace std;




template <class T>
class LL
{
    struct node {

        //whatever data that comes through T to be stored in node
        T data;
        //two direction pointers for doubly linked list
        node* prev;
        node* next;
        node* buffer;
        //default construct
        node(T data): data(data), prev(nullptr), next(nullptr) {}
    };
    //head and tail ptr
    node* head;
    node* tail;

public:

    //default construct
    LL(): head(nullptr), tail(nullptr){}

    //destructor, clear nodes to nullptr
    ~LL()
    {
        node *buffer= nullptr;
        while (head)
        {
            buffer=head;
            head= head->next;
            delete buffer;
        }
        head= nullptr;
    }

    T& getData()
    {
        return data;
    }

    //add node to front, next node pointer points to the head
    void addFront(T data)
    {
        //assign data to Node
        node *Node= new node(data);
        //store head to buffer
        node *buffer= head;
        if (head== nullptr)
        {
            //if empty
            head= Node;
            tail= Node;
        } else{
            //if not empty
            //old data go next
            Node->next= head;
            //assign new data to new head
            head= Node;
            //the previous node of the next node of new head is the new head
            Node->next->prev= Node;
        }

    }
    //add node after the tail
    void addAfter(T data)
    {
        //assign data to Node
        node *Node= new node(data);
        if (head ==nullptr)
        {
            //if runs into end
            head= Node;
            tail= Node;
        }
        else {
            tail->next=Node;
            tail=Node;
        }
    }

    /*
    void insertAt(T data, int n)
    {

        node* temp1= new node();
        temp1->data=data;
        temp1->next= NULL;
        //special case: insert head
        if (n==1){
            temp1->next=head;
            head= temp1;
            return;
        }
        //point to the first node
        // head (temp2)->node->node->target->node->tail
        node* temp2=head;
        //for loop to move temp pointer to the node before target
        // head->node->temp2->target->node->tail
        for (int i=0; i<n-2;i++ )
        {
            //move pointer to the
            temp2= temp2-> next;
        }
        temp1->next=temp2->next;
        temp2->next= temp1;
    } */


    //remove data
    void removeData(T data)
    {
        node* target= searchData(data);
        node* buffer= head;

        if (buffer==target)
        {
            //skip the matched value
            head= buffer->next;
        }
        else {
            while (target !=nullptr)
            {
                if (buffer->next ==target)
                {
                    //buffer's next node becomes target's next node
                    buffer->next= target->next;
                    //target itself be replaced by buffer
                    target->next->prev= buffer;
                    //assassination complete
                    delete target;
                    return;
                }
                buffer= buffer->next;
            }
        }
    }

    //node* getAt()

    //find the data
    int findIndex (node* head, T data)
    {
        int index=0;
        node* buffer=head;
        while (buffer!=NULL)
        {
            if (buffer->data==data)
            {return index;}
            buffer=buffer->next;
            index++;
        }
        //if found nothing
        return -1;
    }

/*
    T& getAt(const int index)
    {
        if (index ==0)
        {
            return head->getData();
        }
        else if (tail->next==nullptr)
        {
            return tail->getData();
        }
        else {

        }
    }*/

    template <class U>
    friend ostream & operator<<(ostream & os, const LL<U> & dll){
        //getting dll ready for print
        dll.printout(os);
        return os;
    }









private:


    //return the node
    node* searchData(T in)
    {
        node *Node= head;
        while (Node !=nullptr)
        {
            if (Node->data== in)
            {return Node;}
            Node = Node->next;
        }
        return nullptr;
    }

    //size of linked list
    int LLsize;



    void printout(ostream& out= cout) const
    {
        //from the head
        node *Node=head;
        //until the end of list
        while (Node !=nullptr)
        {   //print the data stored in this node
            out<<Node->data<<endl;
            //jump to the next node
            Node= Node->next;
        }
    }



};









//template <typename T>
//template <typename T>
//template <typename T>









#endif //INC_20F_AUTO_IDX_LINKEDLIST_H
