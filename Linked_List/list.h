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
        } // End of AddNode
        
        //=====================================================================
        //=====================================================================
        void Print(void){
            cout << "Printing list: ";
            
            for(node *currNode = head; currNode != NULL; currNode = currNode->next){
                cout << currNode->value << " ";
            }
            
            cout << endl;
            
        } // End of Print
        
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
            
        } // End of Delete
        
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
            
        } // End of Search
        
    
    private:
        node *head, *tail;
};


#endif // LIST_H
