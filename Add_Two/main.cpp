#include <iostream>
#include <cmath>
#include <cstring>
#include "list.h"
#include "node.h"
using namespace std;

// Prototypes
list AddTwo(list, list);


//=============================================================================
//=============================================================================
int main(void){
    list list1;
    list list2;
    list result;

    // Init list 1 and 2
    list1.AddNode(2);
    list1.AddNode(4);
    list1.AddNode(3);
    list2.AddNode(5);
    list2.AddNode(6);
    list2.AddNode(4);

    result = AddTwo(list1, list2);

    result.Print();

    return 0;

}


//=============================================================================
//=============================================================================
list AddTwo(list list1, list list2){
    int total = 0;

    for(int i = 0; i < list1.Length(); ++i){
        total += list1.Find(i)->value * pow(10, i);
        total += list2.Find(i)->value * pow(10, i);
    }

    list result;
    string totalStr = to_string(total);

    for(int i = totalStr.length() - 1; i >= 0; --i){
        result.AddNode(int(totalStr[i]) - '0');
    }

    // for(int i = 1; mod != total; ++i){
    //     mod = (total % int(pow(10,i))) / pow(10, i-1);
    //     result.AddNode(mod);
    // }

    return result;

}
