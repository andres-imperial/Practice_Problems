#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
using namespace std;


//=============================================================================
//=============================================================================
class list {
    public:
        //=====================================================================
        //=====================================================================
        list(){
            head = NULL;
        } // End of list()

        //=====================================================================
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
        //=====================================================================
        void Print(void){
            cout << "Printing list: ";

            for(node *currNode = head; currNode != NULL; currNode = currNode->next){
                cout << currNode->value << " ";
            }

            cout << endl;

        } // End of Print(void)


        //=====================================================================
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
