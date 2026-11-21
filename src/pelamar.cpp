#include "pelamar.h"

void createListPelamar(ListPelamar &L){
    // I.S. : List L (belum terinisialisasi).
    // F.S. : Terbentuk list kosong L dengan L.first = nullptr dan L.last = nullptr.

    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyPelamar(ListPelamar L){
    // I.S. : List L terdefinisi (bisa kosong).
    // F.S. : Mengembalikan true jika L kosong (L.first == nullptr), dan false jika tidak.

    return L.first == nullptr && L.last == nullptr;
}

adrPelamar alokasiPelamar(infotypePelamar data){
    // I.S. : Data pelamar (idPelamar, nama, pendidikanTerakhir, pengalamanTahun) terdefinisi.
    // F.S. : Mengembalikan alamat elemen baru P dengan P->info = data, P->next = nullptr, P->prev = nullptr.

    adrPelamar p = new elmPelamar;
    p->info = data;
    p->next = nullptr;
    p->prev = nullptr;

    return p;
}

void dealokasiPelamar(adrPelamar &P){
    // I.S. : P adalah alamat elemen pelamar yang valid (tidak nullptr).
    // F.S. : Memori yang ditempati node P didealokasi (delete P) dan P di-set ke nullptr.

    delete P;
    P = nullptr;
}

void insertFirstPelamar(ListPelamar &L, adrPelamar P){
    // I.S. : List L terdefinisi (mungkin kosong), P sudah dialokasi.
    // F.S. : P ditambahkan sebagai elemen pertama pada list L (L.first = P).

    if (!isEmptyPelamar(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}



void insertLastPelamar(ListPelamar &L, adrPelamar P){
    // I.S. : List L terdefinisi (mungkin kosong), P sudah dialokasi dan idPelamar belum ada di L.
    // F.S. : P ditambahkan sebagai elemen terakhir pada list L (L.last = P); jika idPelamar duplikat, proses insert dibatalkan.

    adrPelamar temp = findPelamar(L, P->info.idPelamar);
    if (temp != nullptr){
        cout << "ID Pelamar " << P->info.idPelamar << " sudah terdaftar!" << endl;
        dealokasiPelamar(P);
        return;
    }

    if (isEmptyPelamar(L)){
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

adrPelamar findPelamar(ListPelamar L, string idPelamar){
    // I.S. : List L terdefinisi (mungkin kosong) dan idPelamar yang dicari terdefinisi.
    // F.S. : Mengembalikan alamat elemen pelamar dengan info.idPelamar == idPelamar, atau nullptr jika tidak ditemukan.

    adrPelamar Q = L.first;;
    bool found = false;

    while (Q != nullptr ){
        if (Q->info.idPelamar == idPelamar){
            found = true;
        } else {
            Q = Q->next;
        }
    }

    if (found){
        return Q;
    } else {
        return nullptr;
    }
}