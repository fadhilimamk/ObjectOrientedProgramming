#ifndef SPECIALMATRIKS_H
#define SPECIALMATRIKS_H

#include "Matriks.h"

class SpecialMatriks : public Matriks {

  public:
    // ctor inisialisasi n_brs dan n_kol ctor inisialitation list, N=M=defsize
    SpecialMatriks();

    // ctor dengan param N (banyaknya baris dan juga banyaknya kolom)
    SpecialMatriks(int n);

    // cctor
    SpecialMatriks(const SpecialMatriks& sm);

    // dtor
    ~SpecialMatriks();

    SpecialMatriks& operator= (SpecialMatriks& sm);
    // overload operator+ untuk melakukan operasi OR dari nilai b dari kedua matriks
    // ditulis dengan operasi integer tanpa main bit 1+0 =1; 0+1=1; 1+1=1; 0+0=0
    SpecialMatriks& operator+ (SpecialMatriks sm2);

    // overload operator* untuk melakukan operasi bit AND (perkalian thd b)
    // ditulis dengan operasi integer tanpa main bit 1*0 =0; 0*1=0; 1*1=1; 0*0=0
    // Ditulis sebagai friend function dengan kode yang lebih sederhana
    friend SpecialMatriks& operator* (const SpecialMatriks& sm1, const SpecialMatriks& sm2);

    // isikan nilai v di posisi data[i,j], i dan j terdefinisi
    // harus dicek apakah nilainya 0 atau 1. Jika bukan 0 dan bukan 1 diisikan 0
    void SetData (int i, int j, int v);

    // private:
    // nilai data hanya boleh 0 atau 1 (berupa bit)
};

#endif
