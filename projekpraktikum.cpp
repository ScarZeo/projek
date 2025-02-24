#include <iostream>
using namespace std;

#define MAX_SISWA 100

struct Siswa {
    string nama;
    int umur;
    string kelas;
    string nis;
};

Siswa daftarSiswa[MAX_SISWA];
int jumlahSiswa = 0;

void tambahSiswa();
void tampilkanSiswa();
void tampilkanSiswaRekursif(int indeks);
void cariSiswa();

int main() {
    int pilihan;
    
    do {
        cout << "\nMenu Manajemen Sekolah:" << endl;
        cout << "1. Tambah Siswa" << endl;
        cout << "2. Tampilkan Siswa" << endl;
        cout << "3. Tampilkan Siswa (Rekursif)" << endl;
        cout << "4. Cari Siswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
            tambahSiswa();
            break;
            case 2:
            tampilkanSiswa();
            break;
            case 3:
            if (jumlahSiswa == 0) {
                cout << "Belum ada data siswa." << endl;
                } else {
                    cout << "\nDaftar Siswa (Rekursif):" << endl;
                    tampilkanSiswaRekursif(0); 
                }
                break;
                case 4:
                cariSiswa();
                break;
                case 5:
                cout << "Keluar dari program." << endl;
                break;
                default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        } while (pilihan != 5);
        
        return 0;
    }

void tambahSiswa() {
    if (jumlahSiswa >= MAX_SISWA) {
        cout << "Data siswa penuh!" << endl;
        return;
    }
        
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, daftarSiswa[jumlahSiswa].nama);
    cout << "Masukkan Umur: ";
    cin >> daftarSiswa[jumlahSiswa].umur;
    cout << "Masukkan Kelas: ";
    cin >> daftarSiswa[jumlahSiswa].kelas;
    cout << "Masukkan NIS: ";
    cin >> daftarSiswa[jumlahSiswa].nis;
        
    jumlahSiswa++;
    cout << "Siswa berhasil ditambahkan!" << endl;
}

void tampilkanSiswa() {
    if (jumlahSiswa == 0) {
        cout << "Belum ada data siswa." << endl;
        return;
    }
    
    cout << "\nDaftar Siswa:" << endl;
    for (int i = 0; i < jumlahSiswa; i++) {
        cout << i + 1 << ". Nama: " << daftarSiswa[i].nama << ", Umur: " << daftarSiswa[i].umur << ", Kelas: " << daftarSiswa[i].kelas << ", NIS: " << daftarSiswa[i].nis << endl;
    }
}

void tampilkanSiswaRekursif(int indeks) {
    if (indeks >= jumlahSiswa) return;
    
    cout << indeks + 1 << ". Nama: " << daftarSiswa[indeks].nama
    << ", Umur: " << daftarSiswa[indeks].umur
    << ", Kelas: " << daftarSiswa[indeks].kelas
    << ", NIS: " << daftarSiswa[indeks].nis << endl;
    
    tampilkanSiswaRekursif(indeks + 1); 
}

void cariSiswa() {
    string nisCari;
    cout << "Masukkan NIS yang dicari: ";
    cin >> nisCari;
    
    for (int i = 0; i < jumlahSiswa; i++) {
        if (daftarSiswa[i].nis == nisCari) {
            cout << "\nData Siswa:" << endl;
            cout << "Nama: " << daftarSiswa[i].nama << endl;
            cout << "Umur: " << daftarSiswa[i].umur << endl;
            cout << "Kelas: " << daftarSiswa[i].kelas << endl;
            cout << "NIS: " << daftarSiswa[i].nis << endl;
            return;
        }
    }
    cout << "Siswa dengan NIS " << nisCari << " tidak ditemukan." << endl;
}