#include <iostream>
#include <limits> //Untuk menangani input yang salah
using namespace std;

bool konversi_satuan() {
    while (true) {
        cout << "\n=== Menu Konversi Satuan ===" << endl;
        cout << "1. Meter ke (Centimeter, Mile, Foot)" << endl;
        cout << "2. Centimeter ke (Meter, Mile, Foot)" << endl;
        cout << "3. Mile ke (Meter, Centimeter, Foot)" << endl;
        cout << "4. Foot ke (Meter, Centimeter, Mile)" << endl;
        cout << "5. Keluar" << endl;

        int pilihan;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        // Validasi input angka
        if (cin.fail() || pilihan < 1 || pilihan > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid! Silakan masukkan angka 1-5.\n";
            continue;
        }

        if (pilihan == 5) {
            cout << "Terima kasih! Program berhenti.\n";
            return true;
        }

        double nilai;
        cout << "Masukkan nilai yang ingin dikonversi: ";
        cin >> nilai;

        // Validasi input angka
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid! Masukkan angka yang benar.\n";
            return false;
        }

        switch (pilihan) {
            case 1:
                cout << nilai << " meter = " << nilai * 100 << " cm" << endl;
                cout << nilai << " meter = " << nilai * 0.000621371 << " mile" << endl;
                cout << nilai << " meter = " << nilai * 3.28084 << " foot" << endl;
                break;
            case 2:
                cout << nilai << " cm = " << nilai / 100 << " meter" << endl;
                cout << nilai << " cm = " << nilai * 0.00000621371 << " mile" << endl;
                cout << nilai << " cm = " << nilai * 0.0328084 << " foot" << endl;
                break;
            case 3:
                cout << nilai << " mile = " << nilai * 1609.34 << " meter" << endl;
                cout << nilai << " mile = " << nilai * 160934 << " cm" << endl;
                cout << nilai << " mile = " << nilai * 5280 << " foot" << endl;
                break;
            case 4:
                cout << nilai << " foot = " << nilai * 0.3048 << " meter" << endl;
                cout << nilai << " foot = " << nilai * 30.48 << " cm" << endl;
                cout << nilai << " foot = " << nilai * 0.000189394 << " mile" << endl;
                break;
        }
    }
}

bool login() { //memasukkan nama dan nim
    string username = "Angelina Augustin Umami";
    string password = "2409106014";

    int percobaan = 3;    
    while (percobaan > 0) {
        string nama, nim;
        cout << "Masukkan Nama: "; getline(cin, nama);    
        cout << "Masukkan NIM: "; getline(cin, nim); 
        
        if (nama == "Angelina Augustin Umami" && nim == "2409106014") {
            cout << "Login berhasil! Selamat datang, " << username << ".\n";
            return true;
        } else {
            percobaan--;
            cout << "Login gagal! Sisa percobaan: " << percobaan << endl;
        }
    }
    
    cout << "Anda telah gagal login 3 kali. Program berhenti.\n";  // jika login gagal, maka akan mengulang sampai tiga kali
    return false;
}

int main() {
    if (login()) { // Jika login berhasil, jalankan konversi_satuan
        konversi_satuan();
    }
    return 0;
}
