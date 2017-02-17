#include <iostream>
#include <string>
using namespace std;


class Kucing {
	private :
		string nama;
		string warna;
		int umur;
	public :
		Kucing (string n, string w, int u){
			this->nama = n;
			this->warna = w;
			this->umur = u;
		}
		void setNama(string nama){
			this->nama = nama;
		}
		string getNama(){
			return this->nama;
		}
		void setWarna(string warna){
			this->warna = warna;
		}
		string getWarna(){
			return this->warna;
		}
		void setUmur(int umur){
			this->umur = umur;
		}
		int getumur(){
			return this->umur;
		}
		void tickle(){
			cout << "meoww ..." << endl;
		}
};

class Orang{
	private:
		string nama;
		int umur;
	public:
		Orang(string n , int u){
			this->nama = n;
			this->umur = u;
		}
		string getNama(){
			return nama;
		}
		int getUmur(){
			return umur;
		}
		void setNama(string n){
			this->nama = n;
		}
		void setUmur(int u){
			this->umur = u;
		}
		void sayHello(){
			cout << "Hai, nama saya " << this->nama << endl << "Saya berumur " << this->umur << " tahun." << endl;
		}
};


int main(){
	// Orang susi = Orang("Susi Similikiti", 20);
	// susi.sayHello();
	return 0;
}
