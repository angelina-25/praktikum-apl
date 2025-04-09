// #include <iostream>
// using namespace std;
// //Deklarasi fungsi
// int tambah(int a1, int a2);
// int main(){
// //Pemanggilan fungsi
// int angka1, angka2;
// cout << "Angka Pertama : "; cin >> angka1;
// cout << "Angka Kedua : "; cin >> angka2;
// cout << "Hasil Penjumlahan = " << tambah(angka1, angka2);
// }
// //Definisi fungsi
// int tambah(int a1, int a2){
// int hasil;
// //Perlu ditampung pada variabel
// hasil = a1 + a2;
// return hasil;
// }

// #include <iostream>
// using namespace std;
// // Deklarasi prosedur
// void hasilTambah(int a, int b);
// int main()
// {
// // Pemanggilan prosedur (tidak perlu ditampung pada variabel)
// hasilTambah(5, 3);
// return 0;
// }
// // Definisi prosedur
// void hasilTambah(int a, int b)
// {
// cout << "Hasil penjumlahan " << a << " + " << b << " = " << a + b <<
// endl;
// }

// #include <iostream>
// using namespace std;
// // Fungsi prosedur dengan parameter
// void sapaUser(string nama)
// {
// cout << "Halo, " << nama << "! Selamat datang di C++." << endl;
// }
// int main()
// {
// sapaUser("Ifnu"); // "Ifnu" adalah argumen
// return 0;
// }

// #include <iostream>
// using namespace std;
// void ubahNilai(int x) {
// x = 10; // Hanya mengubah nilai dalam fungsi
// }
// int main() {
// int angka = 5;
// ubahNilai(angka);
// cout << "Nilai angka setelah fungsi dipanggil: " << angka <<
// endl; // Masih 5
// return 0;
// }

// #include <iostream>
// using namespace std;
// void ubahNilai(int &x) {
// x = 10; // Mengubah nilai asli
// }
// int main() {
// int angka = 5;
// ubahNilai(angka);
// cout << "Nilai angka setelah fungsi dipanggil: " << angka <<
// endl; // Menjadi 10
// return 0;
// }

// #include <iostream>
// using namespace std;
// void sapaUser(string nama = "User") {
// cout << "Halo, " << nama << "!" << endl;
// }
// int main() {
// sapaUser(); // Output: "Halo, User!"
// sapaUser("Ifnu"); // Output: "Halo, Ifnu!"
// return 0;
// }

// #include <iostream>
// using namespace std;
// int globalVar = 20; // Variabel global
// void contohFungsi() {
// cout << "Nilai globalVar dalam fungsi: " << globalVar << endl;
// }
// int main() {
// contohFungsi();
// cout << "Nilai globalVar dalam main: " << globalVar << endl;
// return 0;
// }

// #include <iostream>
// using namespace std;
// void contohFungsi() {
// int lokalVar = 10; // Variabel lokal
// cout << "Nilai lokalVar: " << lokalVar << endl;
// }
// int main() {
// contohFungsi();
// // cout << lokalVar; // ERROR! lokalVar tidak bisa diakses di sini
// return 0;
// }

// #include <iostream>
// using namespace std;
// int angka = 50; // Variabel global
// void contohFungsi() {
// int angka = 10; // Variabel lokal dengan nama yang sama
// cout << "Nilai angka dalam fungsi: " << angka << endl; //
// Menampilkan 10
// }
// int main() {
// contohFungsi();
// cout << "Nilai angka dalam main: " << angka << endl; // Menampilkan
// 50
// return 0;
// }