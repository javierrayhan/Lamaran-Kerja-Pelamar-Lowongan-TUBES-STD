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

void deleteFirstPelamar(ListPelamar &L, adrPelamar &P){
    // I.S. : List L terdefinisi dan tidak kosong.
    // F.S. : Elemen pertama list L dilepas dari list dan alamatnya disimpan pada P.

    if (L.first == L.last){
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLastPelamar(ListPelamar &L, adrPelamar &P){
    // I.S. : List L terdefinisi dan tidak kosong.
    // F.S. : Elemen terakhir list L dilepas dari list dan alamatnya disimpan pada P.
    if (L.first ==  L.last){
        P = L.last;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.last;
        L.last = L.last->prev;
        L.last->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfterPelamar(ListPelamar &L, adrPelamar Prec, adrPelamar &P){
    // I.S. : List L terdefinisi, Prec adalah elemen valid di L dan bukan elemen terakhir.
    // F.S. : Elemen setelah Prec dilepas dari list L dan alamatnya disimpan pada P.

    if (Prec->next == L.last){
        deleteLastPelamar(L, P);
    } else {
        P = Prec->next;
        Prec->next = P->next;;
        P->next->prev = Prec;
        P->next = nullptr;
        P->prev = nullptr;
    }
}
