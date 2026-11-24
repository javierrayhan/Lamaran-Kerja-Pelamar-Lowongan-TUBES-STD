#include "lowongan.h"
//#include "relasi.h"

void createListLowongan(ListLowongan &L) {
    // I.S. : List L (belum terinisialisasi).
    // F.S. : Terbentuk list kosong L dengan L.first = nullptr dan L.last = nullptr.

    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyLowongan(ListLowongan L) {
    // I.S. : List L terdefinisi (bisa kosong).
    // F.S. : Mengembalikan true jika L kosong (L.first == nullptr), dan false jika tidak.

    return L.first == nullptr && L.last == nullptr;
}
adrLowongan allocateLowongan(infotypeLowongan x) {
    // I.S. : Data lowongan (kodeLowongan, posisi, perusahaan, kuota, minPengalaman) terdefinisi.
    // F.S. : Mengembalikan alamat elemen baru P dengan P->info = x, P->next = nullptr, P->prev = nullptr.

    adrLowongan P = new elmLowongan;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}
void dealokasiLowongan(adrLowongan &P) {
    // I.S. : P adalah alamat node lowongan yang valid (tidak nullptr).
    // F.S. : Memori yang ditempati node P didealokasi (delete P) dan P di-set ke nullptr.

    delete P;
    P = nullptr;
}
adrLowongan findLowongan(ListLowongan L, string kode) {
    // I.S. : List L terdefinisi (mungkin kosong) dan kode yang dicari terdefinisi.
    // F.S. : Mengembalikan alamat elemen lowongan dengan info.kodeLowongan == kode, atau nullptr jika tidak ditemukan.

    adrLowongan Q = L.first;
    while (Q != nullptr && Q->info.kodeLowongan != kode) {
        Q = Q->next;
    }
    return Q;
}
void insertLastLowongan(ListLowongan &L, adrLowongan P) {
    // I.S. : List L terdefinisi (mungkin kosong), P sudah dialokasi dan kodeLowongan belum ada di L.
    // F.S. : P ditambahkan sebagai elemen terakhir pada L (L.last = P); jika kode duplikat, pesan error ditampilkan dan insert dibatalkan.

    if (findLowongan(L, P->info.kodeLowongan) != nullptr) {
        cout << "Kode lowongan " << P->info.kodeLowongan << " sudah terdaftar" << endl;
        dealokasiLowongan(P);
        return;
    }
    if (isEmptyLowongan(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}
/*
void deleteLowongan(ListLamaran &L, ListLamaran &L_Rel, adrBST &root, string kode) {
    // I.S. : List L, L_Rel, dan BST terdefinisi; kode lowongan target terdefinisi.
    // F.S. : Seluruh node relasi yang menunjuk ke lowongan tersebut dihapus dari L_Rel & BST, lalu node Lowongan dihapus dari L.


}*/

void showAllLowongan(ListLowongan L) {
    // I.S. : List L_Low terdefinisi (mungkin kosong).
    // F.S. : Seluruh data lowongan (kode, posisi, perusahaan, kuota, minPengalaman) ditampilkan ke layar, atau pesan 'Data lowongan kosong' jika L_Low kosong.
}


