#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;

struct Item {
    string kode;
    string nama;
    int stok;
    double harga;
};

Item inventory[MAX_ITEMS];
int itemCount = 0;

int tampilkanInventaris() {
    cout << "\n================================================================================" << endl;
    cout << "| No  | Kode       | Nama Barang        | Stok       | Harga         |" << endl;
    cout << "================================================================================" << endl;
    for (int i = 0; i < itemCount; i++) {
        cout << "| " << setw(3) << i + 1 << " | "
             << setw(10) << inventory[i].kode << " | "
             << setw(18) << inventory[i].nama << " | "
             << setw(10) << inventory[i].stok << " | "
             << setw(12) << inventory[i].harga << " |" << endl;
    }
    cout << "================================================================================\n";
    return 0;
}

int tambahBarang() {
    if (itemCount < MAX_ITEMS) {
        cout << "\nMasukkan kode barang: ";
        cin >> inventory[itemCount].kode;
        cout << "Masukkan nama barang: ";
        cin.ignore();
        getline(cin, inventory[itemCount].nama);
        cout << "Masukkan stok barang: ";
        cin >> inventory[itemCount].stok;
        cout << "Masukkan harga barang: ";
        cin >> inventory[itemCount].harga;
        itemCount++;
        cout << "Barang berhasil ditambahkan!\n";
    } else {
        cout << "Inventaris penuh!\n";
    }
    return 0;
}

int editBarang() {
    tampilkanInventaris();
    int index;
    cout << "\nMasukkan nomor barang yang ingin diedit: ";
    cin >> index;
    if (index > 0 && index <= itemCount) {
        index--; 
        cout << "Masukkan nama baru: ";
        cin.ignore();
        getline(cin, inventory[index].nama);
        cout << "Masukkan stok baru: ";
        cin >> inventory[index].stok;
        cout << "Masukkan harga baru: ";
        cin >> inventory[index].harga;
        cout << "Barang berhasil diperbarui!\n";
    } else {
        cout << "Nomor barang tidak valid!\n";
    }
    return 0;
}

int hapusBarang() {
    tampilkanInventaris();
    int index;
    cout << "\nMasukkan nomor barang yang ingin dihapus: ";
    cin >> index;
    if (index > 0 && index <= itemCount) {
        for (int i = index - 1; i < itemCount - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        itemCount--;
        cout << "Barang berhasil dihapus!\n";
    } else {
        cout << "Nomor barang tidak valid!\n";
    }
    return 0;
}

int login() {
    string nama, nim;
    int login_attempts = 3;
    while (login_attempts > 0) {
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        cin >> nim;
        cin.ignore();
        
        if (nama == "Angelina Augustin Umami" && nim == "2409106014") {
            return 1;
        } else {
            cout << "Nama atau NIM salah! Percobaan tersisa: " << --login_attempts << endl;
        }
    }
    return 0;
}

int main() {
    while (true) {
        if (!login()) {
            cout << "Anda telah mencoba login 3 kali. Program berhenti." << endl;
            break;
        }
        
        int pilihan;
        do {
            cout << "\n=======================================" << endl;
            cout << "|        Menu Manajemen Inventaris    |" << endl;
            cout << "=======================================" << endl;
            cout << "| 1 | Tampilkan Inventaris           |" << endl;
            cout << "| 2 | Tambah Barang                  |" << endl;
            cout << "| 3 | Edit Barang                    |" << endl;
            cout << "| 4 | Hapus Barang                   |" << endl;
            cout << "| 5 | Keluar                         |" << endl;
            cout << "=======================================" << endl;
            cout << "Pilih menu: ";
            cin >> pilihan;
            cin.ignore();
            
            switch (pilihan) {
                case 1:
                    tampilkanInventaris();
                    break;
                case 2:
                    tambahBarang();
                    break;
                case 3:
                    editBarang();
                    break;
                case 4:
                    hapusBarang();
                    break;
                case 5:
                    cout << "Keluar dari menu manajemen inventaris..." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
            }
        } while (pilihan != 5);
        
        char ulang;
        cout << "Apakah anda ingin mengulang program? (y/n): ";
        cin >> ulang;
        cin.ignore();
        if (ulang != 'y' && ulang != 'Y') {
            cout << "Program berhenti." << endl;
            break;
        }
    }
    return 0;
}
