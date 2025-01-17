#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include "all-headers.h"
using namespace std;

Lists command_system_build(Lists list){
    string mn; cout << "Matrix name: "; fflush(stdin); cin >> mn;
    FMatrix a = get_search(list->Mlist, mn);
    if(a == NULL){
        cout << "No such matrix" << endl << endl;
        return list;
    }
    string vn; cout << "Vector name: "; fflush(stdin); cin >> vn;
    FVector b = get_vsearch(list->Vlist, vn);
    if(b == NULL){
        cout << "No such vector" << endl << endl;
        return list;
    }
    if(b->n != a->nr){
        cout << "Invalid vector (wrong size)" << endl << endl;
        return list;
    }
    FMatrix c = fraction_matrix_copy(a);
    
    // TODO: probably change this to a static form.
    FVector d = new Tfvector;
    *d = b->copy();
    FEqsys sys = new Tfeqsys(c, d);
    sys->name = a->name + b->name; 
    cout << "System name:" << "\x1b[38;5;50m" << sys->name << "\x1b[0m" << endl << endl;
    list->Eqlist = insertFirstE(list->Eqlist, sys);
    return list;
}