#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // =========================================================================
  // 1. TEMPLATE DATA BARANG DALAM ARRAY MULTIDIMENSI (3D)
  // =========================================================================
  // Dimensi 1 [5] : Index Barang ke-i (menggantikan kolom No)
  // Dimensi 2 [2] : [0] Kelompok Angka (int), [1] Kelompok Teks (string)
  // Dimensi 3 [4] : Detail kolomnya

  // Array 3D Integer murni untuk Kode Unik, Harga Beli, dan Harga Jual
  int templateAngka[5][1][3] = {{{1001, 2700, 3500}},
                                {{1002, 16500, 19000}},
                                {{1003, 3800, 5000}},
                                {{1004, 11000, 13500}},
                                {{1005, 68000, 74000}}};

  // Array 3D String murni untuk Nama Barang, Kategori, Supplier, dan Kadaluarsa
  string templateTeks[5][1][5] = {
      {{"Indomie Goreng", "Makanan", "PT Indofood CBP", "0001", "2027-05-12"}},
      {{"Susu Ultra 1L", "Minuman", "PT Ultrajaya", "0002", "2027-01-20"}},
      {{"Sabun Lifebuoy", "Kebersihan", "PT Unilever ID", "0003",
        "2028-08-15"}},
      {{"Kopi Kapal Api", "Minuman", "PT Santos Jaya", "0004", "2027-11-30"}},
      {{"Beras Ramos 5kg", "Sembako", "CV Sumber Pangan", "0005",
        "2027-06-10"}}};

  int jumlahData = 5;

  // =========================================================================
  // 2. MENYALIN KE VECTOR MULTIDIMENSI 3D (MURNI INT & MURNI STRING)
  // =========================================================================
  vector<vector<vector<int>>>
      dataAngka; // Murni integer (Kode Unik, Harga Beli, Harga Jual)
  vector<vector<vector<string>>>
      dataTeks; // Murni string (Nama, Kategori, Supplier, Kadaluarsa)

  for (int i = 0; i < jumlahData; i++) {
    dataAngka.push_back({{templateAngka[i][0][0], templateAngka[i][0][1],
                          templateAngka[i][0][2]}});

    dataTeks.push_back({{templateTeks[i][0][0], templateTeks[i][0][1],
                         templateTeks[i][0][2], templateTeks[i][0][3]}});
  }

  // Contoh menambah 1 data baru secara dinamis (harga beli & jual langsung
  // integer!)
  dataAngka.push_back({{1006, 32000, 36000}});
  dataTeks.push_back({{"Minyak Goreng 2L", "Sembako", "PT Wilmar Nabati",
                       "0004"
                       "2027-09-01"}});

  // =========================================================================
  // 3. MENAMPILKAN TABEL DARI VECTOR 3D
  // =========================================================================
  cout << "\n=== DAFTAR INVENTARIS BARANG (VECTOR 3D INTEGER & STRING) ===\n"
       << endl;
  cout << "===================================================================="
          "==============================================================="
       << endl;
  cout << left << setw(5) << "No" << setw(22) << "Nama Barang" << setw(12)
       << "Kode Unik" << setw(16) << "Kategori" << setw(15) << "Harga Beli"
       << setw(15) << "Harga Jual" << setw(22) << "Nama Supplier" << setw(15)
       << "Kadaluarsa" << endl;
  cout << "===================================================================="
          "==============================================================="
       << endl;

  for (size_t i = 0; i < dataAngka.size(); i++) {
    cout << left << setw(5) << i + 1       // No otomatis dari indeks dimensi i
         << setw(22) << dataTeks[i][0][0]  // Nama Barang (string)
         << setw(12) << dataAngka[i][0][0] // Kode Unik (int asli)
         << setw(16) << dataTeks[i][0][1]  // Kategori (string)
         << "Rp " << setw(12) << dataAngka[i][0][1] // Harga Beli (int asli)
         << "Rp " << setw(12) << dataAngka[i][0][2] // Harga Jual (int asli)
         << setw(22) << dataTeks[i][0][2]           // Nama Supplier (string)
         << setw(15) << dataTeks[i][0][3]
         << endl; // Tanggal Kadaluarsa (string)
  }
  cout << "===================================================================="
          "==============================================================="
       << endl;

  return 0;
}
