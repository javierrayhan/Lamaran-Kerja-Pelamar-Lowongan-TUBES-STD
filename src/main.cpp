#include <iostream>
using namespace std;

int main(){
    int pilihan = -1;

    while (pilihan != 0){
        cout << "1. Kelola Data Pelamar          " << endl;
        cout << "2. Kelola Data Lowongan         " << endl;
        cout << "3. Transaksi Pengajuan Lamaran  " << endl;
        cout << "4. Penilaian & Ranking BST      " << endl;
        cout << "5. Laporan & Analitik Sistem    " << endl;
        cout << "6. Load Data Dummy              " << endl;
        cout << "0. Keluar" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Pilih menu [0-9]: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:

            case 2:

            case 3:

            case 4:

            case 5:

            case 6:

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid, coba lagi. " << endl;

        }
    }
}