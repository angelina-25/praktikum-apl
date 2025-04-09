#include <iostream>
#include <cstring>
using namespace std;

const int MAX_ITEMS = 100;
const int MAX_USERS = 10;
const int MAX_NAME = 50;
const int MAX_NIM = 15;
const int MAX_KODE = 11;
const int MAX_NAMA_BARANG = 50;

struct Profile {
    char nama[MAX_NAME];
    char nim[MAX_NIM];
};

struct User {
    Profile profil;
};

struct Inventory {
    char kode[MAX_ITEMS][MAX_KODE];      
    char nama[MAX_ITEMS][MAX_NAMA_BARANG];     
    int stok[MAX_ITEMS];
    int harga[MAX_ITEMS];
    int itemCount;
};

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    Inventory inventory;
    inventory.itemCount = 0;
    int pilihan = 0;
    
    while (true) {
        cout << "============================" << endl;
        cout << "|       Menu User          |" << endl;
        cout << "============================" << endl;
        cout << "| 1 | Register Akun        |" << endl;
        cout << "| 2 | Login                |" << endl;
        cout << "| 3 | Keluar               |" << endl;
        cout << "============================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();  
        
        if (pilihan == 1) {
            if (userCount < MAX_USERS) {
                cout << "\n=== Register Akun ===\n";
                cout << "Masukkan Nama: ";
                cin.getline(users[userCount].profil.nama, MAX_NAME);
                cout << "Masukkan NIM: ";
                cin.getline(users[userCount].profil.nim, MAX_NIM);
                cout << "Akun berhasil didaftarkan!\n";
                userCount++;
            } else {
                cout << "\nBatas maksimal akun telah tercapai!\n";
            }
        } else if (pilihan == 2) {
            if (userCount == 0) {
                cout << "\nBelum ada akun yang terdaftar. Silakan register terlebih dahulu!\n";
                continue;
            }
            
            char nama[MAX_NAME];
            char nim[MAX_NIM];
            int attempts = 3;
            bool loggedIn = false;
            
            while (attempts > 0) {
                cout << "\n=== Login ===\n";
                cout << "Masukkan Nama: ";
                cin.getline(nama, MAX_NAME);
                cout << "Masukkan NIM: ";
                cin.getline(nim, MAX_NIM);
                
                for (int i = 0; i < userCount; i++) {
                    if (strcmp(users[i].profil.nama, nama) == 0 && strcmp(users[i].profil.nim, nim) == 0) {
                        cout << "Login berhasil!\n";
                        loggedIn = true;
                        break;
                    }
                }
                if (loggedIn) break;
                
                attempts--;
                cout << "Nama atau NIM salah! Percobaan tersisa: " << attempts << "\n";
            }
            
            if (!loggedIn) {
                cout << "Gagal login. Program berhenti.\n";
                break;
            }
            
            while (true) {
                cout << "\n=======================================";
                cout << "\n|    Menu Manajemen Inventaris Toko   |";
                cout << "\n=======================================";
                cout << "\n| 1 | Tampilkan Inventaris            |";
                cout << "\n| 2 | Tambah Barang                   |";
                cout << "\n| 3 | Edit Barang                     |";
                cout << "\n| 4 | Hapus Barang                    |";
                cout << "\n| 5 | Logout                          |";
                cout << "\n=======================================";
                cout << "\nPilih menu: ";
                cin >> pilihan;
                cin.ignore();
                
                if (pilihan == 1) {
                    cout << "\nInventaris:" << endl;
                    for (int i = 0; i < inventory.itemCount; i++) {
                        cout << (i+1) << ". " << inventory.nama[i] << " - Stok: " << inventory.stok[i] << " - Harga: " << inventory.harga[i] << endl;
                    }
                } else if (pilihan == 2) {
                    if (inventory.itemCount < MAX_ITEMS) {
                        cout << "Masukkan kode barang: ";
                        cin.getline(inventory.kode[inventory.itemCount], MAX_KODE);
                        cout << "Masukkan nama barang: ";
                        cin.getline(inventory.nama[inventory.itemCount], MAX_NAMA_BARANG);
                        cout << "Masukkan stok barang: ";
                        cin >> inventory.stok[inventory.itemCount];
                        cout << "Masukkan harga barang: ";
                        cin >> inventory.harga[inventory.itemCount];
                        cin.clear();
                        cin.ignore();
                        inventory.itemCount++;
                        cout << "Barang berhasil ditambahkan!\n";
                    } else {
                        cout << "Inventaris penuh!\n";
                    }
                } else if (pilihan == 3){
                    int nomor;
                    cout << "Masukkan nomor barang yang akan diedit: ";
                    cin >> nomor;
                    cin.ignore();
                    
                    if (nomor > 0 && nomor <= inventory.itemCount) {
                        int index = nomor - 1;
                        cout << "Masukkan kode barang baru: ";
                        cin.getline(inventory.kode[index], MAX_KODE);
                        cout << "Masukkan nama barang baru: ";
                        cin.getline(inventory.nama[index], MAX_NAMA_BARANG);
                        cout << "Masukkan stok barang baru: ";
                        cin >> inventory.stok[index];
                        cout << "Masukkan harga barang baru: ";
                        cin >> inventory.harga[index];
                        cin.clear();
                        cin.ignore();
                        cout << "Barang berhasil diedit!\n";
                    } else {
                        cout << "Nomor barang tidak valid!\n";
                    }
                }else if (pilihan == 4){
                    int nomor;
                    cout << "Masukkan nomor barang yang akan dihapus: ";
                    cin >> nomor;
                    cin.ignore();
                    
                    if (nomor > 0 && nomor <= inventory.itemCount) {
                        int index = nomor - 1;
                        for (int i = index; i < inventory.itemCount - 1; i++) {
                            strcpy(inventory.kode[i], inventory.kode[i+1]);
                            strcpy(inventory.nama[i], inventory.nama[i+1]);
                            inventory.stok[i] = inventory.stok[i+1];
                            inventory.harga[i] = inventory.harga[i+1];
                        }
                        inventory.itemCount--;
                        cout << "Barang berhasil dihapus!\n";
                    } else {
                        cout << "Nomor barang tidak valid!\n";
                    }
                } else if (pilihan == 5) {
                    cout << "Logout berhasil.\n";
                    break;
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            }
        } else if (pilihan == 3) {
            cout << "Program berhenti.\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
    return 0;
}