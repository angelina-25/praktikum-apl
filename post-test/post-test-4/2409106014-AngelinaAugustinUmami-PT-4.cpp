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

void registerUser(User users[], int &userCount) {
    if (userCount < MAX_USERS) {
        cout << "\n=== Register Akun ===\n";
        cout << "Masukkan Nama: ";
        cin.ignore();
        cin.getline(users[userCount].profil.nama, MAX_NAME);
        cout << "Masukkan NIM: ";
        cin.getline(users[userCount].profil.nim, MAX_NIM);
        cout << "Akun berhasil didaftarkan!\n";
        userCount++;
    } else {
        cout << "\nBatas maksimal akun telah tercapai!\n";
    }
}

int loginUser(User users[], int userCount) {
    char nama[MAX_NAME];
    char nim[MAX_NIM];
    int attempts = 3;

    while (attempts-- > 0) {
        cout << "\n=== Login ===\n";
        cout << "Masukkan Nama: ";
        cin.ignore();
        cin.getline(nama, MAX_NAME);
        cout << "Masukkan NIM: ";
        cin.getline(nim, MAX_NIM);

        for (int i = 0; i < userCount; i++) {
            if (strcmp(users[i].profil.nama, nama) == 0 && strcmp(users[i].profil.nim, nim) == 0) {
                cout << "Login berhasil!\n";
                return 1; // login sukses
            }
        }
        cout << "Nama atau NIM salah! Percobaan tersisa: " << attempts << "\n";
    }
    cout << "Gagal login.\n";
    return 0; // login gagal
}


void tampilkanInventaris(const Inventory &inv, int index = 0) {
    if (index >= inv.itemCount) return;
    cout << index + 1 << ". " << inv.nama[index] << " - Stok: " << inv.stok[index] << " - Harga: " << inv.harga[index] << endl;
    tampilkanInventaris(inv, index + 1);
}

void tambahBarang(Inventory &inv) {
    if (inv.itemCount < MAX_ITEMS) {
        cout << "Masukkan kode barang: ";
        cin.ignore();
        cin.getline(inv.kode[inv.itemCount], MAX_KODE);
        cout << "Masukkan nama barang: ";
        cin.getline(inv.nama[inv.itemCount], MAX_NAMA_BARANG);
        cout << "Masukkan stok barang: ";
        cin >> inv.stok[inv.itemCount];
        cout << "Masukkan harga barang: ";
        cin >> inv.harga[inv.itemCount];
        inv.itemCount++;
        cout << "Barang berhasil ditambahkan!\n";
    } else {
        cout << "Inventaris penuh!\n";
    }
}

void tambahBarang(Inventory &inv, const char kode[], const char nama[], int stok, int harga) {
    if (inv.itemCount < MAX_ITEMS) {
        strcpy(inv.kode[inv.itemCount], kode);
        strcpy(inv.nama[inv.itemCount], nama);
        inv.stok[inv.itemCount] = stok;
        inv.harga[inv.itemCount] = harga;
        inv.itemCount++;
        cout << "Barang berhasil ditambahkan (via parameter)!\n";
    } else {
        cout << "Inventaris penuh!\n";
    }
}

void editBarang(Inventory &inv) {
    if (inv.itemCount == 0) {
        cout << "Inventaris kosong.\n";
        return;
    }

    cout << "\nDaftar Barang:\n";
    tampilkanInventaris(inv);

    int nomor;
    cout << "Masukkan nomor barang yang akan diedit: ";
    cin >> nomor;
    cin.ignore();

    if (nomor > 0 && nomor <= inv.itemCount) {
        int index = nomor - 1;
        cout << "Masukkan kode barang baru: ";
        cin.getline(inv.kode[index], MAX_KODE);
        cout << "Masukkan nama barang baru: ";
        cin.getline(inv.nama[index], MAX_NAMA_BARANG);
        cout << "Masukkan stok barang baru: ";
        cin >> inv.stok[index];
        cout << "Masukkan harga barang baru: ";
        cin >> inv.harga[index];
        cin.ignore();
        cout << "Barang berhasil diedit!\n";
    } else {
        cout << "Nomor barang tidak valid!\n";
    }
}


void hapusBarang(Inventory &inv) {
    if (inv.itemCount == 0) {
        cout << "Inventaris kosong.\n";
        return;
    }

    cout << "\nDaftar Barang:\n";
    tampilkanInventaris(inv);

    int nomor;
    cout << "Masukkan nomor barang yang akan dihapus: ";
    cin >> nomor;
    cin.ignore();

    if (nomor > 0 && nomor <= inv.itemCount) {
        int index = nomor - 1;
        for (int i = index; i < inv.itemCount - 1; i++) {
            strcpy(inv.kode[i], inv.kode[i+1]);
            strcpy(inv.nama[i], inv.nama[i+1]);
            inv.stok[i] = inv.stok[i+1];
            inv.harga[i] = inv.harga[i+1];
        }
        inv.itemCount--;
        cout << "Barang berhasil dihapus!\n";
    } else {
        cout << "Nomor barang tidak valid!\n";
    }
}

void menuInventaris(Inventory &inv) {
    int pilihan;
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

        switch (pilihan) {
            case 1: tampilkanInventaris(inv); break;
            case 2: tambahBarang(inv); break;
            case 3: editBarang(inv); break;
            case 4: hapusBarang(inv); break;
            case 5: cout << "Logout berhasil.\n"; return;
            default: cout << "Pilihan tidak valid!\n";
        }
    }
}

int main() {
    User users[MAX_USERS];
    Inventory inventory;
    int userCount = 0;
    inventory.itemCount = 0;

    int pilihan;
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

        switch (pilihan) {
            case 1: registerUser(users, userCount); break;
            case 2:
                if (userCount == 0) {
                    cout << "\nBelum ada akun yang terdaftar. Silakan register terlebih dahulu!\n";
            break;
            }
            if (loginUser(users, userCount) == 1) {
                menuInventaris(inventory);
            } else {
                return 0;
            }
            break;
            case 3:
                cout << "Program berhenti.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
