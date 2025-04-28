// // passByValue.cpp
// # include <iostream>
// using namespace std;

// struct Address{
// string kota;
// string provinsi;
// string negara;
// };

// int main(){
// // deklarasi variabel dengan struct
// Address address1, address2;

// // mengisi value address1
// address1.kota = "Samarinda";
// address1.provinsi = "Kalimantan Timur";
// address1.negara = "Indonesia";

// // mengcopy value address1 ke address2
// address2 = address1;

// // mengganti property kota dari samarinda ke ikn
// address2.kota = "ikn";

// // value address1
// cout<< address1.kota<<endl;

// // value address2
// cout<< address2.kota;
// return 0;
// }

// arrayPtr.cpp


// #include <iostream>
// using namespace std;

// int main () {

//     cout << "pointer yang menunjuk ke suatu array"<< endl;
//     int a[5] = {1,2,3,4,5};
//     int (*aPtr)[5] = &a;
//     for (int i =0; i <5; i++){
//     cout << *aPtr <<endl;
//     }

//     cout << "Pointer yang menunjuk ke arah elemen array" <<endl;
//     int b[5] = {1,2,3,4,5,};
//     int *bPtr = b;
//     for (int i = 0; i < 5; i++){
//     cout << bPtr <<endl;
//     // cout << *bPtr <<endl;
//     bPtr++;
//     }
//     return 0;
//     }


// contoh pointer mengubah variabel a
// funcNoPtr.cpp
// #include <iostream>
// using namespace std;

// int ubahNilai(int a, int b){
//     return a=b;
// }
// int main () {
//     int a,b;
//     a=5;
//     b=20;
//     ubahNilai( a, b );
//     cout << a;
//     return 0;
// }


// Penggunaan Address-of Operator ( & ) sebagai parameter fungsi
// funcPtr.cpp
// #include <iostream>
// using namespace std;

// int ubahNilai(int &a, int b){
// return a=b;
// }

// int main () {
//     int a,b;
//     a=5;
//     b=20;
//     ubahNilai( a, b );
//     cout << a;

//     return 0;
// }

// Penggunaan Dereference Operator ( * ) sebagai parameter fungsi
// #include <iostream>
// using namespace std;

// int ubahNilai(int *a, int b){
//     return *a=b;
// }

// int main () {
//     int a,b;
//     a=5;
//     b=20;
//     ubahNilai( &a, b );
//     cout << a;

//     return 0;
// }


// pointer pada struct
// #include <iostream>
// using namespace std;

// struct Menu {
//     string nama;
//     float harga;
// };

// int main () {
//     Menu nasgor;
//     Menu *nasgorPtr = &nasgor;
//     nasgor.nama = "Nasi Goreng Cumi Hitam Pak Kris";
//     nasgor.harga = 15000;
//     cout << nasgor.nama << " " << nasgor.harga<<endl;

// // kita bisa mengakses/manipulasi value variabel nasgor
// // melalui variabel nasgorPtr
// nasgorPtr->nama = "Nasi Goreng Mawut";
// nasgorPtr->harga = 13000;
// cout << nasgor.nama << " " << nasgor.harga <<endl;

// // kalau memberi value pada atribut biasa pakai ( . )
// // kalau memberi value pada atribut dari pointer pakai ( -> )

// return 0;
// }


// #include <iostream>
// using namespace std;

// // Fungsi untuk menukar dua nilai menggunakan pointer
// void tukar(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main() {
//     int x, y;

//     // Input nilai dari pengguna
//     cout << "Masukkan nilai pertama (x): ";
//     cin >> x;
//     cout << "Masukkan nilai kedua (y): ";
//     cin >> y;

//     // Menampilkan nilai sebelum penukaran
//     cout << "\nSebelum penukaran:" << endl;
//     cout << "x = " << x << ", y = " << y << endl;

//     // Menukar nilai menggunakan fungsi dengan pointer
//     tukar(&x, &y);

//     // Menampilkan nilai setelah penukaran
//     cout << "\nSetelah penukaran:" << endl;
//     cout << "x = " << x << ", y = " << y << endl;

//     return 0;
// }
