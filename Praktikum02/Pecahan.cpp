#include "Pecahan.h"

int GCD (int nx, int ny) {
  int n1, n2;
  n1=nx; n2=ny;
  while(n1 != n2)
  {
    if(n1 > n2)
      n1 -= n2;
    else
      n2 -= n1;
  }
  return n1;
}

Pecahan::Pecahan(){
	n = 1;
	a = 0;
	b = 1;
}

Pecahan::Pecahan(int n, int a, int b){
	int x;

  if(a==0){
    b = 1;
  }

  // kalo a/b bisa disederhanakan
  if(a/b>=1){
		n +=  a/b;
		a = a%b;
    if(a == 0){
      b = 1;
    }
	}
	if(a!=0)
  	if(b%a == 0){
  		x = GCD(a,b);
  		a = a/x;
  		b = b/x;
  		if(a == b){
  			n++;
  			a = 0;
  			b = 1;
  		}
  	}else{
  		x = GCD(a,b);
  		a = a/x;
  		b = b/x;
  		if(a == b){
  			n++;
  			a = 0;
  			b = 1;
  		}
  	}

	this->n = n;
	this->a = a;
	this->b = b;
}

int Pecahan::getBulat (){
	return n;
}

int Pecahan::getPembilang (){
	return a;
}

int Pecahan::getPenyebut (){
	return b;
}

void Pecahan::setBulat(int _n){
	if(_n>=0)
		n = _n;
}
void Pecahan::setPembilang(int _a){
	if(_a>=0){
    Pecahan Temp = Pecahan(n, _a, b);
    n = Temp.getBulat();
  	a = Temp.getPembilang();
  	b = Temp.getPenyebut();
  }
}
void Pecahan::setPenyebut(int _b){
	if(_b>0){
    Pecahan Temp = Pecahan(n, a, _b);
    n = Temp.getBulat();
  	a = Temp.getPembilang();
  	b = Temp.getPenyebut();
  }
}
bool Pecahan::isValid (int n, int a, int b){
	return ((n>=0)&&(a>=0)&&(b>0));
}
Pecahan Pecahan::addWithThis (Pecahan P){
	return Pecahan(P.getBulat() + n, (P.getPembilang()*b) + (a*P.getPenyebut()), b*P.getPenyebut());
}
void Pecahan::accumulate(Pecahan P){
	Pecahan Temp = Pecahan(P.getBulat() + n, (P.getPembilang()*b) + (a*P.getPenyebut()), b*P.getPenyebut());
	n = Temp.getBulat();
	a = Temp.getPembilang();
	b = Temp.getPenyebut();
}
Pecahan Pecahan::add(Pecahan P1, Pecahan P2){
	return Pecahan(P1.getBulat() + P2.getBulat(), (P1.getPembilang()*P2.getPenyebut()) + (P2.getPembilang()*P1.getPenyebut()), P1.getPenyebut()*P2.getPenyebut());
}
bool Pecahan::isEQMe(Pecahan P){
  Pecahan Temp = Pecahan(P.getBulat(), P.getPembilang(), P.getPenyebut());
	return ((Temp.getBulat() == n) && (Temp.getPembilang() == a) && (Temp.getPenyebut() == b));
}
bool Pecahan::isGTMe(Pecahan P){
	if(P.getBulat() > n)
		return true;
	else if (P.getBulat() == n)
		return ( (((float)P.getPembilang() / (float)P.getPenyebut())) > ( (float)a/(float)b ) );
	else
		return false;
}
bool Pecahan::isLTMe(Pecahan P){
  if(P.getBulat() < n)
		return true;
	else if (P.getBulat() == n)
    return ( (((float)P.getPembilang() / (float)P.getPenyebut())) < ( (float)a/(float)b ) );
	else
		return false;
}
float Pecahan::value(){
	return float(a + (float(a/b)));
}
