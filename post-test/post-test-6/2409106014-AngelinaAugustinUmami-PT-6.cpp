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

void registerUser(User* users, int* userCount) {
    if (*userCount < MAX_USERS) {
        cout << "\n=== Register Akun ===\n";
        cout << "Masukkan Nama: ";
        cin.ignore();
        cin.getline(users[*userCount].profil.nama, MAX_NAME);
        cout << "Masukkan NIM: ";
        cin.getline(users[*userCount].profil.nim, MAX_NIM);
        cout << "Akun berhasil didaftarkan!\n";
        (*userCount)++;
    } else {
        cout << "\nBatas maksimal akun telah tercapai!\n";
    }
}

int loginUser(User* users, int* userCount) {
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

        for (int i = 0; i < *userCount; i++) {
            if (strcmp(users[i].profil.nama, nama) == 0 && strcmp(users[i].profil.nim, nim) == 0) {
                cout << "Login berhasil!\n";
                return 1;
            }
        }
        cout << "Nama atau NIM salah! Percobaan tersisa: " << attempts << "\n";
    }
    cout << "Gagal login.\n";
    return 0;
}
void bubbleSort_descending(Inventory &inv) {
    for (int i = 0; i < inv.itemCount - 1; i++) {
        for (int j = 0; j < inv.itemCount - i - 1; j++) {
            if (strcmp(inv.nama[j], inv.nama[j + 1]) < 0) {
                char tempNama[MAX_NAMA_BARANG];
                strcpy(tempNama, inv.nama[j]);
                strcpy(inv.nama[j], inv.nama[j + 1]);
                strcpy(inv.nama[j + 1], tempNama);
            }
        }
    }
}
void insertionSort_ascending(Inventory &inv) {
    for (int i = 1; i < inv.itemCount; i++) {

        char tempKode[MAX_KODE];
        strcpy(tempKode, inv.kode[i]);
        int tempStok = inv.stok[i];
        int tempHarga = inv.harga[i];
        char tempNama[MAX_NAMA_BARANG];
        strcpy(tempNama, inv.nama[i]);

        int j = i - 1;
        while (j >= 0 && strcmp(inv.kode[j], tempKode) > 0) {
            strcpy(inv.kode[j + 1], inv.kode[j]);
            inv.stok[j + 1] = inv.stok[j];
            inv.harga[j + 1] = inv.harga[j];
            strcpy(inv.nama[j + 1], inv.nama[j]);
            j--;
        }
        strcpy(inv.kode[j + 1], tempKode);
        inv.stok[j + 1] = tempStok;
        inv.harga[j + 1] = tempHarga;
        strcpy(inv.nama[j + 1], tempNama);
    }
}


void selectionSort(Inventory &inv) {
    for (int i = 0; i < inv.itemCount - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < inv.itemCount; j++) {
            if (strcmp(inv.nama[j], inv.nama[minIndex]) < 0) {
                minIndex = j;
            }
        }

        char tempNama[MAX_NAMA_BARANG];
        strcpy(tempNama, inv.nama[i]);
        strcpy(inv.nama[i], inv.nama[minIndex]);
        strcpy(inv.nama[minIndex], tempNama);

        char tempKode[MAX_KODE];
        strcpy(tempKode, inv.kode[i]);
        strcpy(inv.kode[i], inv.kode[minIndex]);
        strcpy(inv.kode[minIndex], tempKode);

        int tempHarga = inv.harga[i];
        inv.harga[i] = inv.harga[minIndex];
        inv.harga[minIndex] = tempHarga;

        int tempStok = inv.stok[i];
        inv.stok[i] = inv.stok[minIndex];
        inv.stok[minIndex] = tempStok;

        cout << "Tahap ke-" << i + 1 << ": ";
        for (int k = 0; k < inv.itemCount; k++) {
            cout << inv.nama[k] << " ";
        }
        cout << endl;
    }
}

void tampilkanInventaris( Inventory &inv) {
    selectionSort(inv);
    cout << "\n=== Daftar Inventaris ===\n";
    for (int i = 0; i < inv.itemCount; i++) {
            cout << i + 1 << ". " << inv.nama[i]
            << " - kode: " << inv.kode[i]
            << " - Stok: " << inv.stok[i]
            << " - Harga: " << inv.harga[i]
            << endl;
    }
}
void tampilkanInventaris_descending( Inventory &inv) {
    bubbleSort_descending(inv);
    cout << "\n=== Daftar Inventaris ===\n";
    for (int i = 0; i < inv.itemCount; i++) {
        cout << i + 1 << ". " << inv.nama[i]
        << " - kode: " << inv.kode[i]
        << " - Stok: " << inv.stok[i]
        << " - Harga: " << inv.harga[i]
        << endl;
    }
}

void tampilkanInventaris_ascending( Inventory &inv) {
    insertionSort_ascending(inv);
    cout << "\n=== Daftar Inventaris ===\n";
    for (int i = 0; i < inv.itemCount; i++) {
            cout << i + 1 << ". " << inv.nama[i]
            << " - kode: " << inv.kode[i]
            << " - Stok: " << inv.stok[i]
            << " - Harga: " << inv.harga[i]
            << endl;
    }
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

void updateHargaBarang(Inventory* inv, int index, int* hargaBaru) {
    if (index >= 0 && index < inv->itemCount) {
        inv->harga[index] = *hargaBaru;
        cout << "Harga barang berhasil diperbarui menjadi " << inv->harga[index] << endl;
    } else {
        cout << "Index tidak valid!\n";
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
        cout << "\n| 6 | Update Harga Barang (Pointer)   |";
        cout << "\n=======================================";
        cout << "\nPilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:  
            int pilih; 
            cout << " Menu Sorting " <<endl;
            cout << " 1. Sorting Huruf Berdasarkan Descending" <<endl;
            cout << " 2. Sorting Angka Berdasarkan Ascending" <<endl;
            cout << " 3. Sorting " <<endl;
            cout << " Pilih menu: ";
            cin >> pilih ;
            switch (pilih)
            {
                case 1:
                    tampilkanInventaris_descending(inv);
                    break;
                case 2:
                    tampilkanInventaris_ascending(inv);
                    break;
                case 3:
                    tampilkanInventaris(inv);
                    break;
            default:
                cout << "pilihan tidak valid";
            }

            break;
            case 2: tambahBarang(inv); break;
            case 3: editBarang(inv); break;
            case 4: hapusBarang(inv); break;
            case 5: cout << "Logout berhasil.\n"; return;
            case 6: {
                int nomor, hargaBaru;
                cout << "\nDaftar Barang:\n";
                tampilkanInventaris(inv);
                cout << "Masukkan nomor barang: ";
                cin >> nomor;
                if (nomor > 0 && nomor <= inv.itemCount) {
                    cout << "Masukkan harga baru: ";
                    cin >> hargaBaru;
                    updateHargaBarang(&inv, nomor - 1, &hargaBaru);
                } else {
                    cout << "Nomor tidak valid!\n";
                }
                break;
            }
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
            case 1:
                registerUser(users, &userCount);
                break;
            case 2:
                if (userCount == 0) {
                    cout << "\nBelum ada akun yang terdaftar. Silakan register terlebih dahulu!\n";
                    break;
                }
                if (loginUser(users, &userCount) == 1) {
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