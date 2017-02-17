#include "Pecahan.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

extern Pecahan * MyArrPecahan;

int main () {

// deklarasi variabel yang anda butuhkan
int N, n, a, b, i;
Pecahan maxP, minP, P,Sum;

// program membaca nilai N
cin >> N ;

// program melakukan alokasi array MyArrPecahan sebanyak N
MyArrPecahan = new Pecahan[N];

// Program mengulangi membaca N buah Pecahan dan menyimpannya dalam array
i = 0;
cin >> n >> a >> b;
MyArrPecahan[i] = Pecahan(n,a,b);
minP = maxP = Sum = Pecahan(n,a,b);
for(i = 1; i< N; i++){
	cin >> n >> a >> b;
	P = Pecahan(n,a,b);
	MyArrPecahan[i] = P;
	if(maxP.isGTMe(P))
		maxP = P;
	if(minP.isLTMe(P)){
		minP = P;
	}
	Sum.accumulate(P);
}


/* program menghasilkan: (1) penjumlahan semua nilai pecahan, (2) beberapa baris berisi array yang disebut nilai “lipat”, (3) 1 baris berisi pecahan bernilai maksimum dan (4) 1 baris berisi pecahan bernilai minimumnya */
cout << Sum.getBulat() << " " << Sum.getPembilang() << " " << Sum.getPenyebut() << endl;
i = 0;
while(i < N/2){
	Sum = Sum.add(MyArrPecahan[i], MyArrPecahan[N-i-1]);
	cout << Sum.getBulat() << " " << Sum.getPembilang() << " " << Sum.getPenyebut() << endl;
	i++;
}
if(N%2 == 1)
	cout << MyArrPecahan[i].getBulat() << " " << MyArrPecahan[i].getPembilang() << " " << MyArrPecahan[i].getPenyebut() << endl;
cout << maxP.getBulat() << " " << maxP.getPembilang() << " " << maxP.getPenyebut() << endl;
cout << minP.getBulat() << " " << minP.getPembilang() << " " << minP.getPenyebut() << endl;
// dan menuliskan dengan output sesuai format yang diberikan pada Contoh*/

return 0;

}
