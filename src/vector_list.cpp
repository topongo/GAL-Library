#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include "all-headers.h"
using namespace std;

VNodeptr insertFirstV(VNodeptr n, FVector v){
    return new TVnode(v, n);
}

bool isPresentV(VNodeptr n, string name){
    if(n == NULL){
        return false;
    }
    VNodeptr t = n;
    while((t != NULL)){
        if(t->v->name == name){
            return true;
        }
        t = t->next;
    }
    return false;
}

VNodeptr remove_vsearch(VNodeptr n){
    string name;
    cout << "Vector name: "; fflush(stdin); cin >> name;
    if(n == NULL){
        return NULL;
    }
    VNodeptr t = n;
    if(n->v->name == name){
        t = n->next;
        delete n;
        return t;
    }
    while((t->next != NULL) && (t->next->v->name != name)){
        t = t->next;
    }
    if(t->next != NULL){
        VNodeptr r = t->next;
        t->next = t->next->next;
        delete r;
        return n;
    }
    return n;
}


FVector get_vsearch(VNodeptr n, string name){
    if(n == NULL){
        return NULL;
    }
    VNodeptr t = n;
    while((t != NULL) && (t->v->name != name)){
        t = t->next;
    }
    if(t == NULL){
        return NULL;
    } else {
        return t->v;
    }

}

VNodeptr insertV(VNodeptr n, string name){
    if(! isPresentV(n, name)){
        n = insertFirstV(n, init_fvector(name));
    } else {
        cout << endl << "Vector with the same name already present" << endl << endl;
    }
    return n;
}

void command_print_vector(VNodeptr n){
    string userinput; cout << "Vector name: "; fflush(stdin); cin >> userinput;
    FVector v = get_vsearch(n, userinput);
    if(v != NULL){
        print_fvector(v);
    } else {
        cout << "Vector not found" << endl << endl;
    }
}

VNodeptr command_new_vector(VNodeptr n){
    string name;
    cout << "Name= "; fflush(stdin); cin >> name;
    return insertV(n, name);
}

VNodeptr command_fvector_sum(VNodeptr n){
    string n1, n2; cout << "1st vector name: "; fflush(stdin); cin >> n1;
    cout << "2nd vector name: "; fflush(stdin); cin >> n2;
    FVector v1 = get_vsearch(n, n1), v2 = get_vsearch(n, n2);
    if((v1 == NULL) || (v2 == NULL)){
        cout << "Vector not found" << endl << endl; return n;
    }
    if(v1->n != v2->n){
        cout << "Sum not possible with vectors of different dimensions" << endl << endl; return n;
    }
    FVector res = fvector_sum(v1, v2); res->name = v1->name + "+" + v2->name;
    print_fvector(res);
    return insertFirstV(n, res);
}

VNodeptr command_fvector_difference(VNodeptr n){
    string n1, n2; cout << "1st vector name: "; fflush(stdin); cin >> n1;
    cout << "2nd vector name: "; fflush(stdin); cin >> n2;
    FVector v1 = get_vsearch(n, n1), v2 = get_vsearch(n, n2);
    if((v1 == NULL) || (v2 == NULL)){
        cout << "Vector not found" << endl << endl; return n;
    }
    if(v1->n != v2->n){
        cout << "Difference not possible with vectors of different dimensions" << endl << endl; return n;
    }
    FVector res = fvector_difference(v1, v2); res->name = v1->name + "-" + v2->name;
    print_fvector(res);
    return insertFirstV(n, res);   
}

void command_fvector_norm(VNodeptr n){
    string name; cout << "Vector name: "; fflush(stdin); cin >> name;
    FVector a = get_vsearch(n, name);
    if(a == NULL){
        cout << "Vector not found" << endl << endl;
        exit(1);
    }
    Fraction norm = fvector_norm_noroot(a);
    cout << a->name << " norm = " << fvector_norm_print(norm);
    printf("  ~  %.2f", fvector_float_norm(a)); cout << endl << endl;
}

void command_fvector_scalar_product(VNodeptr n){
    string n1, n2; cout << "1st vector name: "; fflush(stdin); cin >> n1;
    cout << "2nd vector name: "; fflush(stdin); cin >> n2;
    FVector v1 = get_vsearch(n, n1), v2 = get_vsearch(n, n2);
    if((v1 == NULL) || (v2 == NULL)){
        cout << "Vector not found" << endl << endl; exit(1);
    }
    if(v1->n != v2->n){
        cout << "Scalar product not possible with vectors of different dimensions" << endl << endl;
        exit(1);
    }
    Fraction res = fvector_scalar_product(v1, v2);
    cout << "Scalar product: "; res->print(); cout << " ~ "; res->print_float(); 
    cout << endl << endl;
}

void command_fvector_angle(VNodeptr n){
    string n1, n2; cout << "1st vector name: "; fflush(stdin); cin >> n1;
    cout << "2nd vector name: "; fflush(stdin); cin >> n2;
    FVector v1 = get_vsearch(n, n1), v2 = get_vsearch(n, n2);
    if((v1 == NULL) || (v2 == NULL)){
        cout << "Vector not found" << endl << endl; exit(1);
    }
    if(v1->n != v2->n){
        cout << "Cannot find angle between vectors of different dimensions" << endl << endl;
        exit(1);
    }
    cout << "Angle= " << fvector_angle(v1, v2) << endl << endl;
}