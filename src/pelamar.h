#ifndef PELAMAR_H
#define PELAMAR_H

#include <iostream>
using namespace std;

struct infotypePelamar {
    string idPelamar;
    string nama;
    string pendidikanTerakhir;
    int pengalamanTahun;
};

typedef struct elmPelamar *adrPelamar;

struct elmPelamar {
    infotypePelamar info;
    adrPelamar next;
    adrPelamar prev;
};

struct ListPelamar {
    adrPelamar first;
    adrPelamar last;
};

// Fungsi primitif dasar ADT ListPelamar

// I.S. : List L (belum terinisialisasi).
// F.S. : Terbentuk list kosong L dengan L.first = nullptr dan L.last = nullptr.
void createListPelamar(ListPelamar &L);

// I.S. : List L terdefinisi (bisa kosong).
// F.S. : Mengembalikan true jika L kosong (L.first == nullptr), dan false jika tidak.
bool isEmptyPelamar(ListPelamar L);

// I.S. : Data pelamar (idPelamar, nama, pendidikanTerakhir, pengalamanTahun) terdefinisi.
// F.S. : Mengembalikan alamat elemen baru P dengan P->info = data, P->next = nullptr, P->prev = nullptr.
adrPelamar alokasiPelamar(infotypePelamar data);

// I.S. : P adalah alamat elemen pelamar yang valid (tidak nullptr).
// F.S. : Memori yang ditempati node P didealokasi (delete P) dan P di-set ke nullptr.
void dealokasiPelamar(adrPelamar &P);

// I.S. : List L terdefinisi (mungkin kosong), P sudah dialokasi.
// F.S. : P ditambahkan sebagai elemen pertama pada list L (L.first = P).
void insertFirstPelamar(ListPelamar &L, adrPelamar P);

// I.S. : List L terdefinisi (mungkin kosong), P sudah dialokasi dan idPelamar belum ada di L.
// F.S. : P ditambahkan sebagai elemen terakhir pada list L (L.last = P); jika idPelamar duplikat, proses insert dibatalkan.
void insertLastPelamar(ListPelamar &L, adrPelamar P);

// I.S. : List L terdefinisi (mungkin kosong) dan idPelamar yang dicari terdefinisi.
// F.S. : Mengembalikan alamat elemen pelamar dengan info.idPelamar == idPelamar, atau nullptr jika tidak ditemukan.
adrPelamar findPelamar(ListPelamar L, string idPelamar);

// I.S :
// F.S :
void deletePelamarById(ListPelamar &L);

// I.S. : List L terdefinisi dan tidak kosong.
// F.S. : Elemen pertama list L dilepas dari list dan alamatnya disimpan pada P.
void deleteFirstPelamar(ListPelamar &L, adrPelamar &P);

// I.S. : List L terdefinisi dan tidak kosong.
// F.S. : Elemen terakhir list L dilepas dari list dan alamatnya disimpan pada P.
void deleteLastPelamar(ListPelamar &L, adrPelamar &P);

// I.S. : List L terdefinisi, Prec adalah elemen valid di L dan bukan elemen terakhir.
// F.S. : Elemen setelah Prec dilepas dari list L dan alamatnya disimpan pada P.
void deleteAfterPelamar(ListPelamar &L, adrPelamar Prec, adrPelamar &P);

// I.S. : Pointer P terdefinisi (mungkin nullptr).
// F.S. : Menampilkan detail satu pelamar ke layar jika P != nullptr.
void showDetailPelamar(adrPelamar P);

// I.S. : List L terdefinisi (mungkin kosong).
// F.S. : Menampilkan seluruh data pelamar pada L ke layar, atau pesan kosong jika L kosong.
void showAllPelamar(ListPelamar L);

// I.S. : List L terdefinisi (mungkin kosong).
// F.S. : Mengembalikan jumlah total elemen pelamar yang ada di dalam list L.
int countPelamar(ListPelamar L);

// Fungsionalitas Wajib

// Fungsionalitas Opsional
#endif