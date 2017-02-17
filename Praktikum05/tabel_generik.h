#ifndef TABELGENERIK_H
#define TABELGENERIK_H


/** @class TabelGenerik<atype>
  * Kelas Tabel generik dengan tipe data atype
  */
template <class atype>
class TabelGenerik {
public:
  /** @brief Constructor.
	  * Menciptakan TabelGenerik kosong yang berukuran default_size = 50
	  * @param nil_value Nilai 'Nil' yang didefinisikan
	  */
    TabelGenerik(atype nil_value): nil(nil_value), size(default_size){
      data = new atype[size];
      for(int i=0; i<size; i++){
        data[i] = nil_value;
      }
      number_tab++;
    }

  /** @brief Constructor.
	  * Menciptakan TabelGenerik kosong yang berukuran size
    * elemen tabel diinisialisasi dengan nil.
	  * @param nil_value Nilai 'Nil' yang didefinisikan
	  * @param size Ukuran TabelGenerik, size harus > 0
	  */
    TabelGenerik(atype nil_value, int size): nil(nil_value), size(size){
      data = new atype[size];
      for(int i=0; i<size; i++){
        data[i] = nil_value;
      }
      number_tab++;
    }

  /** @brief Copy Constructor.
	  * Menciptakan TabelGenerik kosong yang berukuran sama dengan tabel
	  * @param tabel TabelGenerik yang akan dicopy
	  */
    TabelGenerik(const TabelGenerik& tabel):size(tabel.size), nil(tabel.nil){
      data = new atype[size];
      for(int i=0; i<size; i++){
        data[i] = tabel.data[i];
      }
      number_tab++;
    }

  /** @brief Destructor.
    * Mematikan objek TabelGenerik
    */
    ~TabelGenerik(){
      delete[] data;
    }

  /** @brief Operator=
    * Memastikan TabelGenerik tidak dicopy secara bitwise
    * @param tabel TabelGenerik yang akan dicopy
    */
    TabelGenerik& operator=(const TabelGenerik& tabel){
      for(int i=0; i<size; i++){
        data[i] = tabel.data[i];
      }
    }

  /** @brief GetSize
    * Mengembalikan ukuran TabelGenerik
    */
   int  GetSize(){
     return size;
   }

 /** @brief GetData
   * Mengembalikan pointer ke data
   */
   atype* GetData(){
     return data;
   }

 /** @brief IsEmpty
   * Mengecek apakah TabelGenerik sedang kosong
   */
   bool IsEmpty(){
     return this->NbElmt == 0;
   }

 /** @brief IsFull
   * Mengecek apakah TabelGenerik sedang penuh
   */
   bool IsFull(){
     return this->NbElmt() == size;
   }

 /** @brief Add
   * Menambahkan elemen baru kedalam TabelGenerik
   * @param x data yang akan dimasukan kedalam tabel
   */
   void Add(atype x){
     int idx = 0;
     bool stop = false;
     while(idx < size && !stop){
          if (data[idx] == nil)
            stop = true;
          else
            idx++;
     }
     if(idx<size)
      data[idx] = x;
   }

 /** @brief Del
   * Menghapus data dari tabel
   * @param i indeks data yang akan dihapus, nilau diubah menjadi nil
   */
   atype Del(int i){
     atype temp = data[i];
     data[i] = nil;
   }

 /** @brief DelX
   * Mencari dan menghapus x pada tabel. Elemen yang dihapus adalah elemen hasil pencarian dengan indeks terkecil
   * @param x elemen yang akan dicari dan dihapus
   */
   void DelX(atype x){
     int idx = 0;
     bool found = false;
     while(idx < size && !found){
        if(data[idx]==x)
          found = true;
        else
          idx++;
     }
     if(found)
      data[idx] = nil;
   }

 /** @brief NbElmt
   * Menghitung jumlah elemen pada tabel
   */
   int NbElmt(){
     int count = 0;
     for(int i=0; i < size; i++)
      if(data[i] != nil)
        count++;
     return count;
   }

 /** @brief IsEq
   * Memeriksa kesamaan tabel
   * @param tabel TabelGenerik yang akan diperiksa kesamaannya
   */
   bool IsEq(TabelGenerik<atype> tabel){
     bool equivalent = true;
     if(size != tabel.size){
       equivalent = false;
     }else{
       int i = 0;
       while (i < size && equivalent){
         if(data[i] == tabel.data[i])
          i++;
        else
          equivalent = false;
       }
     }

     return equivalent;
   }

 /** @brief NumberTabelGenerik
   * Mengirimkan jumlah tabel generik yang pernah diciptakan
   */
   static int NumberTabelGenerik(){
     return number_tab;
   }

private:
   const atype nil;               // representasi nilai kosong
   const int default_size= 50;    // default ukuran tabel untuk ctor tanpa parameter
   const int size;                // ukuran tabel, tak boleh diubah
   atype* data;                   // Data yang tersimpan dalam tabel
   static int number_tab;         // Banyaknya tabel yang pernah diciptakan melalui constructor dan copy constructor
};

template<typename T>
int TabelGenerik<T>::number_tab = 0; // inisialisasi number_tab

#endif
