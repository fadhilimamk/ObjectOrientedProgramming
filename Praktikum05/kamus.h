#ifndef KAMUS_H
#define KAMUS_H

#include <iostream>
#include <string>
#include "tabel_generik.h"

using namespace std;
/** @class Kamus
  * Kelas Kamus dengan pasangan key dan value
  */
class Kamus {
public:
	/** @brief Constructor.
	  * Menciptakan kamus kosong yang berukuran size
	  * @param size Nilai ukuran kamus yang ingin dibuat.
	  */
	Kamus(int size);

  /** @brief Destructor.
    */
  ~Kamus();

	/** @brief Menampilkan isi kamus
	  * Melakukan penulisan isi kamus ke layar dimulai dari indeks terkecil.
	  */
  void Print();

   /** @brief Menambahkan elemen baru ke dalam kamus.
     * @param k Nilai kunci yang ingin ditambahkan.
     * @param v Nilai value yang ingin ditambahkan.
     */
  void Add(int k, string v);

   /** @brief Menambahkan elemen baru ke dalam kamus pada indeks i.
     * @param i Nilai indeks tabel tempat penambahan.
     * @param k Nilai kunci yang ingin ditambahkan.
     * @param v Nilai value yang ingin ditambahkan.
     */
  void Add(int i, int k, string v);

   /** @brief Menghapus seluruh isi kamus yang memiliki key yang dimasukkan.
     * @param k Nilai kunci yang ingin dihapus.
     */
  void Del(int k);

   /** @brief Menghapus seluruh isi kamus yang memiliki value yang dimasukkan.
     * @param v Nilai value yang ingin dihapus.
     */
  void Del(string v);

   /** @brief Menghapus seluruh isi kamus yang memiliki key dan value yang dimasukkan.
     * @param k Nilai kunci yang ingin dihapus.
     * @param v Nilai value yang ingin dihapus.
     */
  void Del(int k, string v);

   /** @brief Mencari kamus dengan nilai key dan value tertentu.
     * Pemeriksaan dilakukan dari indeks terkecil.
     * @param k Nilai kunci yang ingin dicari.
     * @param v Nilai value yang ingin dicari.
     * @return Hasil pencarian berupa indeks tempat ditemukannya nilai k dan v yang dicari.
     * Jika tidak ada mengembalikan nilai -99.
     */
  int Search(int k, string v);

  /** @brief Getter dari tabel key
    * @return tabel key
    */
  TabelGenerik<int>* GetKeyData();

  /** @brief Getter tabel value
    * @return tabel value
    */
  TabelGenerik<string>* GetValueData();

private:
	TabelGenerik<int>* t_key;
	TabelGenerik<string>* t_value;
};
#endif
