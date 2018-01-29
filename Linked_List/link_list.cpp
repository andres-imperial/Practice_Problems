#include <iostream>
#include <cctype>
#include "list.h"
using namespace std;

// Prototypes
void PrintMenu(void);

//=============================================================================
//=============================================================================
int main(void){
    // Variables
    node *target = NULL;
    list myList, dummyList;
    char userInput;
    int userVal, index, value;
    // Init dummy list with values
    dummyList.AddNode(1);
    dummyList.AddNode(2);
    dummyList.AddNode(3);


    while(true){
        PrintMenu();
        cin >> userInput;

        switch (toupper(userInput)){
            //======= Add =====================================================
            case 'A':
                cout << "Please enter value add: ";
                cin >> userVal;
                myList.AddNode(userVal);
                break;
            //======= Delete ==================================================
            case 'D':
                cout << "Please enter value to delete: ";
                cin >> userVal;
                if(myList.Delete(userVal)){
                    cout << userVal << " was successfully deleted." << endl;
                }
                else{
                    cout << userVal << " was not found in list." << endl;
                }
                break;
            //======= Find =====================================================
            case 'F':
                cout << "Please enter index value to search for: ";
                cin >> userVal;
                target = myList.Find(userVal);
                if(target == NULL)
                    cout << "There is no information at index " << userVal << endl;
                else{
                    cout << "The value at list index " << userVal << " is "<< target->value << endl;
                }
                break;
            //======= Insert ==================================================
            case 'I':
                cout << "Please enter a value to add: ";
                cin >> userVal;
                cout << "Please enter an index to insert at: ";
                cin >> index;
                if(myList.AddNode(index, userVal) == false)
                    cout << "Error: Invalid Index" << endl;
                break;
            //======= Link ====================================================
            case 'L':{
                /* if (dummyList.head == NULL) {
                 *     cout << "Error: ListB is empty\n";
                 *     break;
                 * } */

                list *listB = &dummyList;
                cout << "Linking list B to your list . . . ";
                myList.Append(listB);
                cout << "Linked\n";
                }
                break;
            //======= Pop =====================================================
            case 'T':
                value = myList.Pop();

                if(value == NULL)
                    cout << "Error: There is no element to pop from list.\n";
                else{
                    cout << "Popping first element. (note: this linked list is not"
                        << " a strict FIFO/stack structure)\n"
                        << "Value popped is " << value << endl;
                }
                break;
            //======= Reverse ==================================================
            case 'R':
                cout << "Reversing your linked list . . .";
                myList.Reverse();
                cout << "complete!\n";
                break;
            //======= Search ===================================================
            case 'S':
                cout << "Please enter value to search for: ";
                cin >> userVal;
                if(myList.Search(userVal)){
                    cout << userVal << " was found in the list." << endl;
                }
                else{
                    cout << userVal << " was not found in the list." << endl;
                }
                break;
            //======= Print ====================================================
            case 'P':
                myList.Print();
                break;
            //======= Clear ====================================================
            case 'C':
                myList.Clear();
                break;
            //======= Quit =====================================================
            case 'Q':
                cout << "Quiting . . . " << endl;
                return 0;
                break;
            //======= Default ==================================================
            default:
                cout << "Sorry that was an invalid selection, please try again." << endl;
        }

    }


}


//=============================================================================
//=============================================================================
void PrintMenu(void){
   cout << "Main Menu\n"
        << "===========================\n"
        << "(A)dd new node\n"
        << "(C)lear list\n"
        << "(D)elete node\n"
        << "(F)ind node by index\n"
        << "(I)nsert new node\n"
        << "(L)ink another list to your list\n"
        << "(P)rint list\n"
        << "(R)everse list\n"
        << "(S)earch for node\n"
        << "(T) Pop First value from list\n"
        << "(Q)uit program\n";
}
// End of link_list.cpp
