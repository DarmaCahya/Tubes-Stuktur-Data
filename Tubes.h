#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

using namespace std;


#define child(P) (P)->child
#define first(L) ((L).first)

typedef struct tim *adrTim;
typedef struct anggota *adrAng;

struct tim {
    string namaTim;
    adrAng child;
    adrTim next;
};

struct anggota {
    string namaAng;
    adrAng nextAng;
};

struct ListTim {
    adrTim first;
};

void createListTim(ListTim &Lt);
adrTim newTim(string x);
adrAng newAng(string y);
void addTim(ListTim &Lt, adrTim P);
bool findTim(ListTim &Lt, string x);
void addAnggota(ListTim &Lt, adrTim pTim , adrAng pAng);
void show(ListTim &Lt);
int countTim(ListTim Lt);
int countAng(ListTim Lt);
void Count(ListTim Lt, string x);
void maxAng(ListTim Lt);
void minAng(ListTim Lt);
void delTim(ListTim &Lt, string x);
void findAng(ListTim Lt, string y);
bool fingchild(ListTim Lt, string y);

#endif // TUBES_H_INCLUDED
