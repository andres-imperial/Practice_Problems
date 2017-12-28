#include <iostream>
#include "list.h"
using namespace std;

// Prototypes
void PrintMenu(void);

//=============================================================================
//=============================================================================
int main(void){
    // Variables
    node *target = NULL;
    list myList;
    char userInput;
    int userVal, index;


    while(true){
        PrintMenu();
        cin >> userInput;
        switch (userInput){
            //======= Add =====================================================
            case 'A':
                cout << "Please enter value add: ";
                cin >> userVal;
                myList.AddNode(userVal);
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
        << "(I)nsert new node\n"
        << "(D)elete node\n"
        << "(S)earch for node\n"
        << "(F)ind node by index\n"
        << "(P)rint list\n"
        << "(C)lear list\n"
        << "(Q)uit program\n";
}
// End of link_list.cpp
