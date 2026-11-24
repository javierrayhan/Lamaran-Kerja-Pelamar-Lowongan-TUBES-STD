#ifndef LOWONGAN_H
#define LOWONGAN_H

#include <iostream>
using namespace std;

struct infotypeLowongan {
    string kodeLowongan;
    string posisi;
    string perusahaan;
    int kuota;
};

typedef struct elmLowongan *adrLowongan;

struct elmLowongan {
    infotypeLowongan info;
    adrLowongan next;
    adrLowongan prev;
};
struct ListLowongan {
    adrLowongan first;
    adrLowongan last;
};

void createListLowongan(ListLowongan &L);

// I.S. : List L terdefinisi (bisa kosong).
// F.S. : Mengembalikan true jika L kosong (L.first == nullptr), dan false jika tidak.
bool isEmptyLowongan(ListLowongan L);

// I.S. : Data lowongan (kodeLowongan, posisi, perusahaan, kuota, minPengalaman) terdefinisi.
// F.S. : Mengembalikan alamat node baru P dengan P->info = data, P->next = nullptr, P->prev = nullptr.
adrLowongan allocateLowongan(infotypeLowongan data);

// I.S. : P adalah alamat node lowongan yang valid (tidak nullptr).
// F.S. : Memori yang ditempati node P didealokasi (delete P) dan P di-set ke nullptr.
void dealokasiLowongan(adrLowongan &P);

// I.S. : List L terdefinisi (mungkin kosong), P sudah dialokasi dan kodeLowongan belum ada di L.
// F.S. : P ditambahkan sebagai elemen terakhir pada L (L.last = P); jika kode duplikat, pesan error ditampilkan dan insert dibatalkan.
void insertLastLowongan(ListLowongan &L, adrLowongan P);

// I.S. : List L terdefinisi (mungkin kosong) dan kode yang dicari terdefinisi.
// F.S. : Mengembalikan alamat node dengan info.kodeLowongan == kode, atau nullptr jika tidak ditemukan.
adrLowongan findLowongan(ListLowongan L, string kode);

// I.S. : List L, L_Rel, dan BST terdefinisi; kode lowongan target terdefinisi.
// F.S. : Seluruh node relasi yang menunjuk ke lowongan tersebut dihapus dari L_Rel & BST, lalu node Lowongan dihapus dari L.

//void deleteLowongan(ListLowongan &L, ListLamaran &L_Rel, adrBST &root, string kode);

// I.S. : List L_Low terdefinisi (mungkin kosong).
// F.S. : Seluruh data lowongan (kode, posisi, perusahaan, kuota, minPengalaman) ditampilkan ke layar, atau pesan 'Data lowongan kosong' jika L_Low kosong.
void showAllLowongan(ListLowongan L);

#endif // LOWONGAN
