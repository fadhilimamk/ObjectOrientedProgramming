#include "Kamus.h"

#define NIL_KEY -99
#define NIL_VALUE ""

Kamus::Kamus(int size){
  t_key = new TabelGenerik<int>(NIL_KEY,size);
  t_value = new TabelGenerik<string>(NIL_VALUE,size);
}

Kamus::~Kamus(){
  delete t_key;
  delete t_value;
}

void Kamus::Print(){
  for(int i=0; i<t_value->GetSize(); i++){
    cout << t_value->GetData()[i] << endl;
  }
}

void Kamus::Add(int k, string v){
  t_key->Add(k);
  t_value->Add(v);
}

void Kamus::Add(int i, int k, string v){
  if(t_key->GetData()[i]!=NIL_KEY){
    t_key->GetData()[i] = k;
    t_value->GetData()[i] = v;
  }else{
    t_key->Add(k);
    t_value->Add(v);
  }
}

void Kamus::Del(int k){
  for(int i=0; i<t_key->GetSize(); i++){
    if(t_key->GetData()[i]==k){
      t_key->Del(i);
      t_value->Del(i);
    }
  }
}


void Kamus::Del(string v){
  for(int i=0; i<t_key->GetSize(); i++){
    if(t_value->GetData()[i].compare(v) == 0){
      t_key->Del(i);
      t_value->Del(i);
    }
  }
}

void Kamus::Del(int k, string v){
  int idx = this->Search(k,v);
  if(idx != NIL_KEY){
    t_key->Del(idx);
    t_value->Del(idx);
  }
}

int Kamus::Search(int k, string v){
  bool found = false;
  int idx = 0;
  while (idx < t_key->GetSize() && !found){
    if(t_key->GetData()[idx] == k && t_value->GetData()[idx].compare(v)==0)
      found = true;
    else
      idx ++;
  }

  return found ? idx : NIL_KEY;
}

TabelGenerik<int>* Kamus::GetKeyData(){
  return t_key;
}

TabelGenerik<string>* Kamus::GetValueData(){
  return t_value;
}
