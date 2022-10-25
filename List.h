#include <iostream>
#include "Dictionary.h"
#include <assert.h>
using namespace std;

template <typename dicnode> //template creation dicnode
class List{   //class definition of List 
  public:
    dicnode data;
    List <dicnode> *next=NULL;
};

typedef List <Dictionary> ListNode;

template <typename dicnode>

class SinglyLL //class definition SinglyLL
{
public:
    
    bool IsEmpty() //Function to check if the list is empty 
    {
        return start = NULL;
    }
     
    int Length() //Function to check the length of the list
    {
        int count = 0;
        for (ListNode* loc = start; loc; loc=loc->next) //Traversing through the list
        {
            count++; //The loop runs length of list times
        }
        return count;
    }

    bool Search(dicnode value) //Function to find a value in the list
    {
        for (ListNode* loc = start; loc; loc ->next)
        {
            if (loc->data == value)  //True if the value is found
            return true;
        }
        return false;
    }

    void Delete(dicnode value) //Function to delete a particular value from the list
    {
        ListNode* loc = start;
        ListNode* ploc = NULL;
        while (loc && loc->data != value) //Loop runs until value is found
        {
            ploc = loc;
            loc = loc->next; //Loc is the value to be deleted and ploc is the previous value
        }

        if (loc) //True if loc is non null
        {
            if (ploc) //True if ploc is non null
            {
                ploc->next = loc->next;
                delete loc; //Deleting loc
            }

            else //If ploc is null
            {
                start = loc->next;
                delete loc;
            }
        }
    }

    void Destroy() //Function to destroy the list completely
    {
        for (ListNode* current = start; current;) //Loop will run until current becomes null
        {
            ListNode* temp = current;
            current = current->next;
            delete temp; //deletes each node one by one
        }
        start = NULL; //Making start equal to null to free memory
    }

    void InsertAtStart(dicnode value, int pos = 0) //Function to insert a value at the start of the list
    {
        assert(pos >= 0 && pos <= Length());
        if (pos == 0)
        {
            ListNode* newnode = new ListNode;
            newnode->data = value;
            newnode->next = start;
            start = newnode;
        }
        else
        {
            Insert(value, start, pos - 1);
        }
    }

  
    void Insert(dicnode value, ListNode* node, int pos) //Function to add a value at a specific position
    {
        if (pos == 0) //If pos = 0, it means value is to be inserted at start
        {
            ListNode* newnode = new ListNode;
            newnode->data = value;
            newnode->next = node->next;
            node->next = newnode;
        }
        else
        {
            Insert(value, node->next, pos - 1); //Recursive call for previous position
        }
    }

    void print(ListNode* headNode)
    {
        ListNode* loc = headNode;
        while (loc)
        {
            cout << loc->data << endl;
            loc = loc->next;
        }
       
    }

    void printReverse(ListNode* headNode)
    {
        PrintReverseListRecursively(headNode);
    }

    void PrintReverseListRecursively(ListNode* headNode)
    {
        if (headNode->next)//The condition will run until node->next becomes null.
        {
            PrintReverseListRecursively(headNode->next);
        }
        cout << headNode->data << endl;
    }


    ListNode* reverseList(ListNode* start) //Function to the completely reverse the list
    {
        ListNode* ploc = nullptr;
        ListNode* loc = start;

        while (loc) //The loop will run until loc node becomes null
        {
            ListNode* temp = loc->next;
            loc->next = ploc; //Traversing through the list
            ploc = loc;
            loc = temp;
        }
        return ploc;
    }

    ListNode* filterByLetter(ListNode* start, string letter) //Function to filter the words including a specific letter
    {
        for (ListNode* current = start; current;) //The loop will run until current becomes null
        {
            if (current->data.word.find(letter) == -1) //This condition is true when letter is not found
            {
                Dictionary node = current->data;
                current = current->next;
                Delete(node); //Deleting the node with missing letter
            }
            else
            {
                current = current->next;
            }
        }
        return start; //Returning the list with all nodes with letter present
    }

    ListNode* rearrangeByEvenOddLength(ListNode* start)
    {
        if (start)
        {
            ListNode* last = start;
           
            while (last->next) //To find the last node of the list
            {
                last = last->next;
            }
            ListNode* ploc = NULL;
            ListNode* loc = start;
            ListNode* end = last;
            while (loc!=last)
            {
                if (loc->data.word.size() % 2 != 0) //This condition is tru in case the word is odd sized
                {
                    if (ploc != NULL) 
                    {
                        ploc->next = loc->next;
                        ListNode* temp = loc;
                        loc = loc->next;
                        temp->next = NULL;
                        end->next = temp;
                        end = temp;
                    }
                    else
                    {
                        ploc = loc;
                        loc = loc->next;
                        ListNode* temp = start;
                        start = start->next;
                        temp->next = NULL;
                        end->next = temp;
                        end = temp;
                    }
                }
                else // This condition is true in case of even sized words
                {
                    ploc = loc;
                    loc = loc->next;
                }
              
            }
        }
        return start;
    }

    ListNode* start = NULL; 
};

