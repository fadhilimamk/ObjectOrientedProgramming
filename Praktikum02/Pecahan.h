#ifndef PECAHAN_H
#define PECAHAN_H
class Pecahan {
  // Method Public
  public:
    // 5 sekawan
    // ctor tanpa parameter
    Pecahan (); //menghasilkan nilai <1,0,1>
    // ctor dengan parameter, harus menjamin membentuk pecahan yang valid
    Pecahan (int n, int a, int b); //Prekondisi: n,a,b membentuk pecahan valid
    /* n adalah bagian bulat positif, boleh nol
       a adalah pembilang dan b adalah penyebut;
       a/b adalah pecahan; a>=0; b > 0 (tidak boleh nol); b>a dan dinormalisasi
       contoh: 1 2/4 adalah pecahan dengan n=1, a=2 dan b=4 disimpan sbg 1 1/2
       contoh: 1 3/4 adalah pecahan dengan n=1, a=3 dan b=4
       jika user memberikan 1 3/2 maka pecahan yang dibentuk adalah 2 1/2
       <1,1,2) = 1 1/2; <0 1,2> = 1/2; <1,0,1> = 1.00; <1,0,4>=1.00;
    */
    // dtor, operator= tidak perlu ditulis

    // selector (getter) dan setter
    int getBulat ();              //bagian bulat, n
    int getPembilang ();          //pembilang a
    int getPenyebut();            //penyebut b
    // hanya boleh dilakukan jika dijamin dapat membentuk pecahan valid
    // perhatikan set pada sebuah komponen harus menjamin tetap membentuk pecahan
    void setBulat(int _n);
    void setPembilang(int _a);
    void setPenyebut(int _b);
    // cek validitas
    static bool isValid (int n, int a, int b); //hanya perlu cek apakah n>=0, a>=0, b >1
    // Aritmatika Pecahan
    // semua operasi harus menjamin tetap membentuk pecahan valid.
    // Misalnya 1 1/2 + 1 3/4 hasilnya adalah 3 1/4
    // Jika pembilang dan penyebut sama, maka a = 0 dan b = 1
    Pecahan addWithThis (Pecahan P); // Menghasilkan P + current objek
    void accumulate(Pecahan P); // Mennambahkan P ke current objek
    static Pecahan add(Pecahan P1, Pecahan P2); /* menghasilkan P1+P2 tanpa menyentuh current object, untuk sementara walau “aneh”, realisasikan */
    // operator logika
    bool isEQMe(Pecahan P); //true jika P sama dengan current object
    bool isGTMe(Pecahan P); //true P > current object
    bool isLTMe(Pecahan P); // trus jika P < current object
    //operator lain
    float value(); // menghasilkan nilai pecahan, misalnya 1 3/4 menjadi 1.75
  private:
    // <n,a,b> adalah sebuah bilangan n a/b ; misalnya 6 1/2 artinya 6.5
    // memenuhi kriteria yang dinyatakan dalam deskripsi ctor
    int n; // bagian bulat, n>0
    int a; // pembilang, a < b
    // jika suatu operasi menghasilkan a>b maka harus ditambahkan ke n
    int b; // penyebut  ; b>0 dan b>a dan
    // a/b dinormalisasi misalnya 2/6 menjadi 1/3; 2/4 menjadi 1/2
};
#endif
