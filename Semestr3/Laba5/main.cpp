#include <iostream>
#include "List/List.h"
#include "ComplexLife/ComplexLife.h"
#include "ComplexStr/ComplexStr.h"

int main() {
    List list;

    list.adding(new ComplexLife(1, 2));
    list.adding(new ComplexStr("3+4i"));

    cout << "list: " << endl;
    list.show();

    list.remove(0);
    list.paste(1, new ComplexLife(5, 6));

    cout << "List again: " << endl;
    list.show();

    ComplexStr search("5+6i");
    int index = list.find(&search);
    if (index != -1) {
        cout << "Find! Index: " << index << endl;
    } else {
        cout << "Not find." << endl;
    }

    return 0;
}

