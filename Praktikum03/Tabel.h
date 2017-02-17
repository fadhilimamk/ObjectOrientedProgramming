#ifndef TABEL_H
#define TABEL_H
class Tabel {
// Method Public
public:
// 5 sekawan
// ctor tanpa parameter
   Tabel(); //menghasilkan tabel dengan ukuran defaultSize
// ctor dengan parameter, harus menjamin membentuk Tabel yang valid
   Tabel(int size); //Prekondisi: size >0

// cctor
   Tabel(const Tabel&);

// dtor harus menjamin memori yang dialokasi dikembalikan
    ~Tabel();

// operator= menjamin bukan bitwise copy
   Tabel& operator=(const Tabel&);

// selector(getter) dan setter
   int  GetSize();              //Ukuran Tabel
   int* GetData();          // Data yang diperoleh dari tabel

// tidak ada setter sebab tabel tak boleh diubah setelah dibuat
// operasi tabel
   bool IsEmpty();
/* mengirimkan true jika tabel kosong, semua nilai Nil
   Mengirimkan false jika tabel tidak kosong
*/
   bool IsFull();
/* Mengirimkan true jika banyaknya elemen tabel=size ; false jika tidak */

   void Add(int x);
/* I.S. tabel tidak penuh, X <> Nil */
/*menambahkan X sebagai elemen tabel pada tempat kosong dengan indeks paling kecil*/

   int Del(int i);
/* mengirimkan nilai pada indeks i, dan mengosongkan data_[i] */

   void DelX(int x);
/* I.S. X <> Nil;
F.S. sebuah elemen bernilai X dengan indeks terkecil dihapus, jika ada
Proses: menghapus nilai X dengan indeks paling keci yang disimpan dalam tabel, jika ada. Jika tak ada, I.S=F.S */

   int NbElmt( );
/* Mengirimkan banyaknya elemen tabel, mengirimkan 0 jika tabel "kosong" */

// operator aritmatika
   int Sum();
/* mengirimkan hasil pejumlahan semua elemen tabel, mengirimkan 0 jika tabel kosong */
   bool Or();
/* I.S. Tabel isinya adalah bit: 0,1 atau Nil
Menghasilkan hasil operasi OR dari semua elemen data_[i] yang bukan NIL */

   Tabel Accumulate();
/* mengirimkan sebuah tabel dengan alokasi memori baru yang ukurannya 1 dan isinya adalah hasil penjumlahan semua elemen tabel */

// operator logika
   bool IsEq(Tabel t);
/*true jika T sama dengan current object */
   bool IsBit(int i);
/* mengirimkan true jika data_[i] merepresentasi bit, yaitu 0 atau 1 atau Nil ; Nil akan diabaikan*/

private:
   const int Nil=-99; // artinya "kosong" tak terdefinisi
   const int defaultSize= 50; // default ukuran tabel untuk ctor tanpa parameter
   int size; // ukuran tabel, tak boleh diubah
   int* data_; // Data yang tersimpan dalam tabel
};
#endif
