#include "SpecialMatriks.h"

SpecialMatriks::SpecialMatriks():Matriks(){
}

SpecialMatriks::SpecialMatriks(int n): Matriks(n,n){
}

SpecialMatriks::SpecialMatriks(const SpecialMatriks& sm): Matriks(sm){
}

SpecialMatriks::~SpecialMatriks(){
}

SpecialMatriks& SpecialMatriks::operator=(SpecialMatriks& sm){
  for(int i = 0; i< n_brs; i++)
    for(int j = 0; j< n_brs; j++)
      this->b[i][j] = sm.b[i][j];

  return (*this);
}

SpecialMatriks& SpecialMatriks::operator+ (SpecialMatriks sm2){
  int s = this->n_brs > sm2.n_brs ? this->n_brs : sm2.n_brs;
  int x,y;
  SpecialMatriks* temp = new SpecialMatriks(s);

  for(int i=0 ; i<s ; i++)
    for(int j=0; j<s ; j++){
      if(i < n_brs && j < n_kol)
        x = b[i][j];
      else
        x = 0;

      if(i < sm2.n_brs && j < sm2.n_kol)
        y = sm2.b[i][j];
      else
        y = 0;

      temp->b[i][j] = (x || y);

    }

  return (*temp);
}

SpecialMatriks& operator* (const SpecialMatriks& sm1, const SpecialMatriks& sm2){
  int s = sm1.n_brs > sm2.n_brs ? sm1.n_brs : sm2.n_brs;
  int x,y;
  SpecialMatriks* temp = new SpecialMatriks(s);
  for(int i=0 ; i<s ; i++)
    for(int j=0; j<s ; j++){
      if(i < sm1.n_brs && j < sm1.n_kol)
        x = sm1.b[i][j];
      else
        x = 1;

      if(i < sm2.n_brs && j < sm2.n_kol)
        y = sm2.b[i][j];
      else
        y = 1;

      temp->b[i][j] = (x*y);
    }

  return (*temp);
}

void SpecialMatriks::SetData (int i, int j, int v){
  if(v == 1 || v == 0){
    Matriks::SetData(i,j,v);
  }else{
    Matriks::SetData(i,j,0);
  }
}
//
// int main(){
//   return 0;
// }
