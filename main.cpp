#include <iostream>
#include "Tubes.h"
using namespace std;

int main()
{
    ListTim Lt;
    adrAng Q;
    adrTim p;
    int pilih,i,pilih1;
    string namaTim,namaAng;

    cout << "===============================================================\n";
    cout << "===================TUGAS BESAR STRUKTUR DATA===================\n";
    cout << "Kelompok GPU\nAnggota :";
    cout << "\n- I Made Darma Cahya Adyatma 1301213139 IF-45-09\n";
    cout << "- Mohammad Daffa Setiawan 1301213063 IF-45-09\n";
    cout << "===============================================================\n";
    cout << "===============================================================\n\n";

    //membuat List Tim
    createListTim(Lt);

    while(!0){
        cout << "=============================MENU==============================\n";
        cout << "1. Menambahkan Data Team dan Anggota E-Sport" << endl;
        cout << "2. Mencari Data pada Team dan Anggota E-Sport" << endl;
        cout << "3. Menampilkan Data Team dan Anggotanya" << endl;
        cout << "4. Menghapus Data Team dan Anggotanya" << endl;
        cout << "5. Menghitung Jumlah Anggota dari sebuah Team" << endl;
        cout << "6. Menampilkan Team yang memiliki Anggota yang paling banyak" << endl;
        cout << "7. Menampilkan Team yang memiliki Anggota yang paling sedikit" << endl;
        cout << "0. Exit" << endl;
        cout << "Masukkan menu: ";
        cin >> pilih;
        cout << "===============================================================\n";
        if(pilih == 1){
            cout << "\nMasukkan Data Team dan Anggota E-Sport\n";
            cout << "- Masukkan Data Team\n";
            cout << "  Nama Team : ";
            cin >> namaTim;
            p = newTim(namaTim);
            addTim(Lt, p);

            cout << "\n- Masukkan Data Anggota\n";
            cout << "  Berapa banyak anggota yang akan di tambahkan? "; cin >> i;
            while(0<i){
                cout << "  Nama Anggota : ";
                cin >> namaAng;
                while(fingchild(Lt,namaAng) == true){
                    cout << "  Anggota telah berada di team lain, mohon untuk masukkan nama anggota yang lain!" << endl;
                    cout << "  Nama Anggota : ";
                    cin >> namaAng;
                }
                Q = newAng(namaAng);
                addAnggota(Lt,p,Q);
                i--;
            }
        } else if(pilih == 2){
            cout << "\nMencari Data pada Team dan Anggota E-Sport\n";
            cout << "\nMencari Data: \n" << "1. Data Team E-Sport\n" << "2. Data Anggota E-Sport\n" << "Masukkan pilihan anda: ";
            cin >> pilih1;
            if(pilih1 == 1){
                cout << "\nMasukkan Nama Team E-Sport yang ingin anda cari: ";
                cin >> namaTim;
                findTim(Lt,namaTim);
            }else if(pilih1 == 2){
                cout << "\nMasukkan Nama Anggota E-Sport yang ingin anda cari: ";
                cin >> namaAng;
                findAng(Lt, namaAng);
            }
        } else if(pilih == 3){
            cout << endl;
            show(Lt);
        } else if(pilih == 4){
            cout << "\nMasukkan Nama Team yang akan dihapus: "; cin >> namaTim;
            delTim(Lt,namaTim);
        } else if(pilih == 5){
            cout << "\nMasukkan Nama Team yang akan dihitung Jumlah anggotanya: ";
            cin >> namaAng;
            Count(Lt,namaAng);
        } else if(pilih == 6){
            maxAng(Lt);
        } else if(pilih == 7){
            minAng(Lt);
        }else if (pilih == 0){
            cout << "ANDA TELAH KELUAR DARI PROGRAM"<< endl;
            break;
        } else {
            cout << "Invalid Input";
        }
        cout << endl;
    }
    return 0;
    //}
}
