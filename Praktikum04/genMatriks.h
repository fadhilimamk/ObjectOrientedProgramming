// file : genMatriks.h
#ifndef GENMATRIKS_H
#define GENMATRIKS_H

#include <ostream>

template <class atype>
class GenMatriks {
// kelas matriks yang generik
public:
// ctor tanpa parameter
// create sebuah matriks berukuran defaultbaris x defaultkol
  GenMatriks(): nBrs(defsize), nKol(defsize){
    data = new atype*[nBrs];
    for(int i=0 ; i < nBrs; i++)
      data[i] = new atype[nKol];
  }
// ctor dengan parameter
// create sebuah matriks berukuran defaultbaris x defaultkol
  GenMatriks(int nb, int nk): nBrs(nb), nKol(nk){
    data = new atype*[nBrs];
    for(int i=0 ; i < nBrs; i++)
      data[i] = new atype[nKol];
  }
// cctor menjamin terbentuk matriks dengan data dicopy GenMatriks
  GenMatriks(const GenMatriks<atype>& gm): nBrs(gm.nBrs), nKol(gm.nKol){
    data = new atype*[nBrs];
    for(int i=0 ; i < nBrs; i++){
      data[i] = new atype[nKol];
      for(int j=0; j < nKol; j++){
        data[i][j] = gm.data[i][j];
      }
    }
  }
// operator= yang menjamin data dicopy, bukan bitwise copy
  GenMatriks<atype>& operator=(const GenMatriks<atype>& gm){
    if(this != &gm){
      for(int i=0 ; i < nBrs ; i++)
        for(int j=0; j < nKol; j++)
          data[i][j] = gm.data[i][j];
    }
    return (*this);
  }
// dtor
// membebaskan kembali memori yang dipakai data
  ~GenMatriks(){
    for(int i=0 ; i < nBrs; i++)
      delete data[i];
    delete data;
  }
// isi elemen v di posisi data[i,j], i dan j terdefinisi
  void setData (int i, int j, atype v){
    data[i][j] = v;
  }
// ambil elemen v di posisi data[i,j], i dan j terdefinisi
  atype getData (int i, int j){
    return data[i][j];
  }
// getter
  int GetNBrs(){
    return nBrs;
  }
  int GetNKol(){
    return nKol;
  }
// io stream. Implementasi fungsi dibuat di sini.
  friend std::ostream& operator<< (std::ostream &os, const GenMatriks<atype>& sm){
    for(int i=0 ; i < sm.nBrs; i++){
      for(int j=0; j < sm.nKol-1; j++)
        os << sm.data[i][j] << " ";
      os << sm.data[i][sm.nKol-1] << "\n";
    }
    return os;
  }

private :
  const int defsize=100;
  const int nBrs; // banyaknya baris efektif
  const int nKol; // banyaknya kolom efektif
  atype ** data;
};

#endif
