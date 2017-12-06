#include <iostream>
#include "list.h"
using namespace std;

// Prototypes
void PrintMenu(void);

//=============================================================================
//=============================================================================
int main(void){
    list myList;
    char userInput;
    int userVal;
    
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
            //======= Print ====================================================
            case 'P':
                myList.Print();
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
        << "(D)elete node\n" 
        << "(S)earch for node\n"
        << "(P)rint list\n" 
        << "(Q)uit program\n";
}
// End of link_list.cpp
