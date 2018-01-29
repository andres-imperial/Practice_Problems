// Author: Andres Imperial
// Contact: andres.imperial@live.com
// File: list.h
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
using namespace std;


//=============================================================================
// Linked list class with a variety of functions
//=============================================================================
class list {
    public:
        //=====================================================================
        // Constructor
        //=====================================================================
        list(){
            head = NULL;
        } // End of list()

        //=====================================================================
        // Adds node to end of list
        //=====================================================================
        void AddNode(int value){
            if(head == NULL){
                head = new node;
                head->value = value;
                head->next = NULL;
                tail = head;
            }
            else{
                node *newNode = new node;
                newNode->value = value;
                newNode->next = NULL;
                tail->next = newNode;
                tail = newNode;
            }
        } // End of AddNode(int)


        //=====================================================================
        // Adds node at specific index in the list
        //=====================================================================
        bool AddNode(int index, int value){
            // Invalid index
            if(index < 0 || (!this->Find(index - 1) && index != 0))
                return false;

            node* newNode = new node;
            // Insert new value at beginning of list
            if (value == 0) {
                newNode->value = value;
                newNode->next = head;
                head = newNode;
            }
            else{
                node *prevNode = this->Find(index - 1);
                newNode->value = value;
                newNode->next = prevNode->next;
                prevNode->next = newNode;
            }

            if (newNode->next == NULL)
                tail = newNode;

            return true;

        } // End of AddNode(int, int)


        //=====================================================================
        // Concatonates one list to another, in turn setting the second list's
        // head to NULL.
        //=====================================================================
        void Append(list *listB){
            if (listB == NULL || listB->head == NULL) {
                cout << "\n(List B is empty)\n";
                return;
            }
            else if (head == NULL) {
                head = listB->head;
                tail = listB->tail;
            }
            else{
                tail->next = listB->head;
                tail = listB->tail;
            }

            listB->head = NULL;
            listB->tail = NULL;

        }// End of Append(node*)


        //=====================================================================
        // Deletes entire list.
        //=====================================================================
        void Clear(void){
            node* prevNode = head;

            while(head != NULL){
                head = head->next;
                delete prevNode;
                prevNode = head;
            }

        }// End of Clear(void)


        //=====================================================================
        // Deletes first occurence of a specific value from list
        //=====================================================================
        bool Delete(int target){
            node *prev = NULL;
            // Search through list for target value
            for(node *currNode = head; currNode != NULL; currNode = currNode->next){
                // Value found
                if(currNode->value == target){
                    // Head node was holding value
                    if(currNode == head){
                        node *temp = head;
                        head = head->next;
                        delete temp;
                        return true;
                    }
                    // Value was not in head node
                    else{
                        prev->next = currNode->next;
                        delete currNode;
                        return true;
                    }
                }
                // update previous node before next loop
                prev = currNode;

            }

            // Target value was not found
            return false;

        } // End of Delete(int)


        //=====================================================================
        // Finds node based on specific index.
        //=====================================================================
        node* Find(int index){
            int counter = 0;
            node *currNode = head;

            if(index < 0)
                return NULL;

            while(currNode != NULL && counter < index){
                ++counter;
                currNode = currNode->next;
            }

            return currNode;
        }// End of Find(int)


        //=====================================================================
        // Returns length of list
        //=====================================================================
        int Length(){
            node * currNode = head;
            int counter = 1;

            if(head == NULL){
                return 0;
            }

            while(currNode->next != NULL){
                currNode = currNode->next;
                ++counter;
            }

            return counter;

        }
        //=====================================================================
        // Remove and return first element from list.
        //=====================================================================
        int Pop(void){
            if (head == NULL) {
                return (int)NULL;
            }
            else{
                int data = head->value;
                node *temp = head;
                head = head->next;
                delete temp;
                return data;
            }
        }// End of Pop(void)


        //=====================================================================
        // Prints entire list
        //=====================================================================
        void Print(void){
            cout << "Printing list: ";

            for(node *currNode = head; currNode != NULL; currNode = currNode->next){
                cout << currNode->value << " ";
            }

            cout << endl;

        } // End of Print(void)


        //=====================================================================
        // Reverses a linked list
        //=====================================================================
        void Reverse(void){
            tail = head;
            head = Reverse(head);
            tail->next = NULL;
        }// End of Reverse(void)


        //=====================================================================
        // Reverses a linked list and return pointer to head of reversed list
        //=====================================================================
        node* Reverse(node *currNode){
            // Check for NULL; list does not exist
            if(currNode == NULL)
               return NULL;

            // list with only one node.
            if(currNode->next == NULL)
                return currNode;

            node *rest = Reverse(currNode->next);

            currNode->next->next = currNode;

            currNode->next = NULL;

            return rest;

        }// End of Reverse(void)


        //=====================================================================
        // Search list for specific value
        //=====================================================================
        bool Search(int target){
            // Search through list for value
            for(node *currNode = head; currNode != NULL; currNode = currNode->next){
                // Target value was found
                if(currNode->value == target){
                    return true;
                }
            }

            // Target value was not found
            return false;

        } // End of Search(int)


    private:
        node *head, *tail;
};


#endif // LIST_H
