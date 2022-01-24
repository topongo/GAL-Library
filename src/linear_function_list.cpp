#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include "all-headers.h"
using namespace std;

FNodeptr insertFirstF(FNodeptr n, Function f){
    return new TfunctionList(f, n);
}

Function get_fsearch(FNodeptr n, string name){
    if(n == NULL){
        return NULL;
    }
    FNodeptr t = n;
    while( t != NULL ){
        if(t->f->name == name){
            return t->f;
        }
        t = t->next;
    }
    return NULL;
}

bool isPresentF(FNodeptr n, string name){
    if(n == NULL) return false;
    FNodeptr t = n;
    while(t != NULL){
        if(t->f->name == name){
            return true;
        }
    }
    return false;
}

FNodeptr insertF(FNodeptr n, string name){
    if(!isPresentF(n, name)){
        n = insertFirstF(n, init_function(name));
    } else {
        cout << "Function with the same name already exists" << endl << endl;
    }
    return n;
}

FNodeptr command_new_function(FNodeptr n){
    string name; cout << "Function name: "; fflush(stdin); cin >> name;
    return insertF(n, name);
}

void command_print_function(FNodeptr n){
    string name; cout << "Function name: "; fflush(stdin); cin >> name;
    Function f = get_fsearch(n, name);
    if(f != NULL){
        print_function(f); cout << endl << endl;
    } else {
        cout << "No such function found" << endl << endl;
    }
}