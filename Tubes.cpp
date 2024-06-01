#include "Tubes.h"

void createListTim(ListTim &Lt){
    first(Lt)  = NULL;
}

adrTim newTim(string x){
    adrTim p = new tim;
    p->namaTim = x;
    p->next = NULL;
    p->child = NULL;
    return p;
}

adrAng newAng(string y){
    adrAng P = new anggota;
    P->namaAng = y;
    P->nextAng = NULL;
    return P;
}

void addTim(ListTim &Lt, adrTim P){
    if(first(Lt)==NULL){
        first(Lt) = P;
        P->next = NULL;
    }else if(first(Lt)->next == NULL){
        (first(Lt))->next = P;
        P->next = NULL;
    }else{
        adrTim q = first(Lt);
        while(q->next != NULL){
            q = q->next;
        }
        q->next = P;
        P->next = NULL;
    }
}

bool findTim(ListTim &Lt, string x){
    if(first(Lt) == NULL){
        cout << "Tidak ada Team!" << endl;
        return false;
    }else{
        adrTim p = first(Lt);
        while(p!= NULL){
            if(p->namaTim == x){
                cout << "\n-----------------------" << endl;
                cout << "+ Team ditemukan!     +" << endl;
                cout << "-----------------------" << endl;
                cout << "Team " << p->namaTim << ", anggotanya adalah ";
                adrAng q = p->child;
                while(q->nextAng!=NULL){
                    cout << q->namaAng << ", ";
                    q = q->nextAng;
                }
                cout << q->namaAng << ", ";
                return true;
            }else{
                p = p->next;
            }
        }
        cout << "\n-----------------------" << endl;
        cout << "+Team tidak ditemukan!+" << endl;
        cout << "-----------------------" << endl;
        return false;
    }
}

void findAng(ListTim Lt, string y){
    adrTim P = first(Lt);
    adrAng Q;
    adrTim save;
    bool ketemu = false;
    while(P!=NULL && ketemu == false){
        Q = child(P);
        while(Q!=NULL){
            //cout<<"Test";
            if(Q->namaAng == y){
                ketemu = true;
                save = P;
            }
            Q = Q->nextAng;
        }
        P = P->next;
    }
    if (ketemu){
        cout<< y <<" adalah anggota dari tim "<<save->namaTim<<endl;
    } else {
        cout<<"Keanggotaan tidak ditemukan!"<<endl;
    }
}

void addAnggota(ListTim &Lt, adrTim pTim , adrAng pAng){
    if(pTim->child == NULL){
        pTim->child = pAng;
    }else{
        adrAng P = pTim->child;
        while(P->nextAng != NULL){
            P = P->nextAng;
        }
        P->nextAng = pAng;
    }
}

void show(ListTim &Lt){
    if(first(Lt) == NULL){
        cout << "List Team Kosong!" << endl;
    }else{
        adrTim P = first(Lt);
        while(P!= NULL){
            adrAng q = P->child;
            cout << "+ Team " << P->namaTim << ": ";
            while(q->nextAng!=NULL){
                cout << q->namaAng << ", ";
                q = q->nextAng;
            }
            cout << q->namaAng<< endl;
            P = P->next;
        }
    }
}

int countTim(ListTim Lt){
    adrTim P = first(Lt);
    int i = 0;
    while (P!=NULL){
        i++;
        P=P->next;
    }
    return i;
}

int countAng(ListTim Lt){
    adrTim P = first(Lt);
    int i = 0;
    while (P!=NULL){
        adrAng Q = P->child;
        while(Q!=NULL){
            i++;
            Q=Q->nextAng;
        }
        P=P->next;
    }
    return i;
}
void Count(ListTim Lt, string x){
    adrTim P = first(Lt);
    while (P!=NULL){
        if(P->namaTim == x){
            int i = 0;
            adrAng Q = P->child;
            cout<<"= Jumlah Anggota Tim "<<P->namaTim<<" Adalah ";
            while(Q!=NULL){
                i++;
                Q = Q->nextAng;
            }
            cout<<i <<" =" << endl;
        }
        P = P->next;
    }
}

void maxAng(ListTim Lt){
    adrTim P = first(Lt);
    int Max = 0;
    adrTim save;
    while(P!=NULL){
        adrAng Q = P->child;
        int hitung = 0;
        while (Q!=NULL){
            hitung ++;
            Q = Q->nextAng;
        }
        if (hitung >= Max){
            Max = hitung;
            save = P;
        }
        P=P->next;
    }
    cout<<"Anggota terbanyak ada pada tim: "<<save->namaTim<<", dengan jumlah anggota "<<Max<< "Player" <<endl;
}

void minAng(ListTim Lt){
    adrTim P = first(Lt);
    int Min = 0;
    adrTim save;
    while(P!=NULL){
        adrAng Q = child(P);
        int hitung = 0;
        while (Q!=NULL){
            hitung ++;
            Q = Q->nextAng;
        }
        if(Min == 0){
            Min = hitung;
        }
        if (hitung <= Min){
            Min = hitung;
            save = P;
        }
        P=P->next;
    }
    cout<<"Anggota paling sedikit ada pada tim: "<<save->namaTim<<", dengan jumlah anggota "<<Min<< "Player" <<endl;
}

void delTim(ListTim &Lt, string x){
    adrTim P = first(Lt);
    if (first(Lt) == NULL){
        cout<<"Data kosong!"<<endl;
    } else if(P->namaTim == x){
        first(Lt) = P->next;
        P->next = NULL;
        P->child = NULL;
    } else {
        while((P->next)->namaTim != x ){
            P = P->next;
        }
        adrTim Q = P->next;
        P->next = (P->next)->next;
        Q->next = NULL;
        Q->child = NULL;
    }
}

bool fingchild(ListTim Lt, string y){
    adrTim P = first(Lt);
    while(P!=NULL){
        adrAng q = P->child;
        while(q!=NULL){
            if(q->namaAng == y){
                return true;
            }
            q = q->nextAng;
        }
        P = P->next;
    }
    return false;
}
