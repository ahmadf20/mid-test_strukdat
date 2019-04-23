/*
Nama program 	: mid-test_1
Nama			: Ahmad Faaiz Al-auza'i
NPM				: 140815180023
Tanggal dibuat	: 23/04/2019
***********************************************/
#include <iostream>
#include <iomanip>
using namespace std;

struct ElementList {
    int noDaftar;
    string namaTim;
    string asalDaerah;
    int Gol;
    ElementList* next;
};

typedef ElementList* pointer;
typedef pointer list;

void createList(list& first){
    first = NULL;
}

void createElement(pointer& pBaru){
    pBaru = new ElementList;
    cout << "No daftar : "; cin >> pBaru->noDaftar;
    cout << "Nama Tim : "; cin >> pBaru->namaTim;
    cout << "Asal Daerah : "; cin >> pBaru->asalDaerah;
    pBaru->Gol = 0;
    pBaru->next = NULL;
}

void insertLast(list& first, pointer pBaru){
    if (first == NULL) {
        first = pBaru;
    } else {
        pointer last = first;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = pBaru;
    }
}

void traversal(list first){
    pointer pBantu = first;
    cout << "--------------------------" << endl;
    cout << left << setw(3) <<  "No" << setw(15) << "Tim" << setw(3) << "Gol" << endl;
    cout << "--------------------------" << endl;
    while(pBantu != NULL){
        cout << left << setw(3) <<  pBantu->noDaftar << setw(15) << pBantu->namaTim << setw(3) << pBantu->Gol << endl;
        pBantu = pBantu->next;
    }
}

void linearSearch(list first, int key, int& status, pointer& pCari){
    status = 0;
    pCari = first;
    while(pCari != NULL && status == 0){
        if(key == pCari->noDaftar){
            status = 1;
        } else {
            pCari = pCari->next;
        }
    }
}

void updateGol(list& first, pointer& pCari){
    cout << "--------------------------" << endl;
    cout << left << setw(3) <<  "No" << setw(15) << "Tim" << setw(3) << "Gol" << endl;
    cout << "--------------------------" << endl;
    cout << left << setw(3) <<  pCari->noDaftar << setw(15) << pCari->namaTim << setw(3) << pCari->Gol << endl;
    cout << "Update Gol : "; cin >> pCari->Gol;
    cout << "Data Berhasil di unpdate!" << endl;
}

void sortDesc(list& first){
    for(int i = 0; i < 6; i++){
        pointer pBantu = first;
        while(pBantu->next != NULL){
            if (pBantu->Gol < pBantu->next->Gol) {
                swap(pBantu->noDaftar, pBantu->next->noDaftar);
                swap(pBantu->namaTim, pBantu->next->namaTim);
                swap(pBantu->Gol, pBantu->next->Gol);
            }
            pBantu = pBantu->next;
        }
    }
    
}

int main(){
    pointer p, pCari;
    list first;
    int status, key;

    createList(first);
    cout << "-----INPUT DATA-----" << endl;
    for(int i = 0; i < 6; i++){
        createElement(p);
        insertLast(first, p);
        traversal(first);
    }


    cout << "-----UPDATE DATA-----" << endl;
    for(int i = 0; i < 6; i++){
        cout << "No daftar : "; cin >> key;
        linearSearch(first, key, status, pCari);
        if (status == 1) {
            cout << "Data ditemukan!" << endl;
            updateGol(first, pCari);
        } else {
            cout << "data tidak ditemukan!" << endl;
        }
    }
    
    cout << "-----SHOW DATA-----" << endl;
    traversal(first);

    cout << "-----DATA SORTED-----" << endl;
    sortDesc(first);
    traversal(first);
    
}

/*
------input daftar-----
1 
Chubu 
Miyazaki
2 
Furano 
Hokaido
3 
Hirado 
Nagasaki
4 
Minamiuwa 
Ehime
5 
Toho 
Suginami
6 
Nankatsu 
Sizouka
1 
1
2 
2
3 
1
4 
0
5 
3
6 
3
*/

