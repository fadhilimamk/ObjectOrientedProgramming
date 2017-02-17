#include "Matriks.h"

Matriks::Matriks():n_brs(DEFSIZE), n_kol(DEFSIZE){
  b = new int *[n_brs];
  for(int i = 0; i< n_brs; i++){
    b[i] = new int[n_kol];
    for(int j = 0; j< n_kol; j++)
      b[i][j] = 0;
  }
}

Matriks::Matriks(int n, int m):n_brs(n), n_kol(m){
  b = new int *[n];
  for(int i = 0; i< n; i++){
    b[i] = new int[m];
    for(int j = 0; j< n; j++)
      b[i][j] = 0;
  }
}

Matriks::Matriks(const Matriks& m):n_brs(m.n_brs), n_kol(m.n_kol){
  b = new int *[n_brs];
  for(int i = 0; i< n_brs; i++){
    b[i] = new int[n_kol];
    for(int j = 0; j< n_kol; j++)
      b[i][j] = m.b[i][j];
  }
}

Matriks::~Matriks(){
  for(int i = 0; i< n_brs; i++){
    delete b[i];
  }
  delete b;
}

Matriks& Matriks::operator= (Matriks& m){
  if(this != &m){
    for(int i = 0; i< n_brs; i++){
      for(int j = 0; j< n_kol; j++)
        b[i][j] = m.b[i][j];
    }
  }

  return (*this);
}

bool IsEqSize (Matriks m1, Matriks m2){
  return (m1.n_brs== m2.n_brs && m1.n_kol== m2.n_kol);
}

Matriks& Matriks::operator+(Matriks m2){
  int n = (m2.n_brs > n_brs)? m2.n_brs : n_brs;
  int m = (m2.n_kol > n_kol)? m2.n_kol : n_kol;
  int x,y;

  Matriks* temp = new Matriks(n,m);

  for(int i = 0; i< n; i++)
    for(int j=0; j<m; j++){
      if(i < n_brs && j < n_kol)
        x = b[i][j];
      else
        x = 0;

      if(i < m2.n_brs && j < m2.n_kol)
        y = m2.b[i][j];
      else
        y = 0;

      temp->SetData(i,j,x+y);
    }

  return *temp;
}

Matriks& operator*(const Matriks& m1, const Matriks& m2){
  int n = (m2.n_brs > m1.n_brs)? m2.n_brs : m1.n_brs;
  int m = (m2.n_kol > m1.n_kol)? m2.n_kol : m1.n_kol;
  int x,y;
  Matriks* temp = new Matriks(n,m);

  for(int i = 0; i< n; i++)
    for(int j=0; j<m; j++){
      if(i < m1.n_brs && j < m1.n_kol)
        x = m1.b[i][j];
      else
        x = 1;

      if(i < m2.n_brs && j < m2.n_kol)
        y = m2.b[i][j];
      else
        y = 1;
      temp->SetData(i,j, x*y);
    }

  return *temp;
}

std::ostream& operator<<(std::ostream &os, const Matriks& m){
  os << "N = " << m.n_brs << "\n" << "M = " << m.n_kol << "\n";
  for(int i = 0; i<m.n_brs; i++){
    for(int j=0; j<m.n_kol-1; j++)
      os << m.b[i][j] << " " ;
    os << m.b[i][m.n_kol-1] << "\n";
  }
  return os;
}

void Matriks::SetData(int i, int j, int v){
  b[i][j] = v;
}
int Matriks::GetData (int i, int j){
  return b[i][j];
}

// Mengembalikan n_brs
int Matriks::GetBrs(){
  return n_brs;
}
// Mengembalikan n_kol
int Matriks::GetKol(){
  return n_kol;
}
