#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct barang {
  int kodeunik;
  string namabarang;
  double hargabeli;
  double hargajual;
  string namapromo;
  double hargasetelahdiskon;
};

barang baru;
// 1. Ubah jadi 3 Dimensi: [Lapisan Kode Unik][Baris][Kolom Barang]
vector<vector<vector<barang>>> daftarbarang;

void PemberianPromo() {
  int pilihdiskon;
  double diskon;
  cout << "Silahkan memilih salah satu:\n1. Nataru (40%)\n2. Imlek (35%)\n3. "
          "Ramadhan (40%)\n4. Input sendiri\nPilihan: ";
  cin >> pilihdiskon;

  if (pilihdiskon == 1) {
    diskon = 40;
    baru.namapromo = "Nataru (40%)";
    baru.hargasetelahdiskon =
        baru.hargajual - (baru.hargajual * (diskon / 100));
  } else if (pilihdiskon == 2) {
    diskon = 35;
    baru.namapromo = "Imlek (35%)";
    baru.hargasetelahdiskon =
        baru.hargajual - (baru.hargajual * (diskon / 100));
  } else if (pilihdiskon == 3) {
    diskon = 40;
    baru.namapromo = "Ramadhan (40%)";
    baru.hargasetelahdiskon =
        baru.hargajual - (baru.hargajual * (diskon / 100));
  } else {
    cout << "Nama promo: ";
    cin.ignore(); // Membersihkan buffer sebelum getline
    getline(cin, baru.namapromo);
    cout << "Diskon (%): ";
    cin >> diskon;
    baru.hargasetelahdiskon =
        baru.hargajual - (baru.hargajual * (diskon / 100));
  }
}

void TambahBarang() {
  while (true) {
    char pilihan;
    cout << "\nSELAMAT DATANG DI OPSI TAMBAH BARANG\n";

    cout << "Masukkan angka unik untuk barang: ";
    cin >> baru.kodeunik;

    cout << "Masukkan nama barang: ";
    cin.ignore(); // Wajib ada agar input nama barang tidak ter-skip
    getline(cin, baru.namabarang);

    cout << "Harga beli: ";
    cin >> baru.hargabeli;

    cout << "Harga jual: ";
    cin >> baru.hargajual;

    cout << "Tambahkan promo? (y/n): ";
    cin >> pilihan;
    if (pilihan == 'y' || pilihan == 'Y') {
      PemberianPromo();
    } else {
      baru.hargasetelahdiskon = baru.hargajual;
      baru.namapromo = "Tidak ada promo";
    }

    // 2. Masukkan ke vector 3D (Lapisan [i] dipegang oleh kodeunik)
    bool ketemu = false;
    for (int i = 0; i < daftarbarang.size(); i++) {
      if (daftarbarang[i][0][0].kodeunik == baru.kodeunik) {
        daftarbarang[i].push_back(
            {baru}); // Tambah baris baru di lapisan kodeunik yang sama
        ketemu = true;
        break;
      }
    }
    if (!ketemu) {
      daftarbarang.push_back(
          {{baru}}); // Buat lapisan 3D baru untuk kodeunik baru
    }

    cout << "Ingin menambah barang lagi? (y/n): ";
    cin >> pilihan;
    if (!(pilihan == 'y' || pilihan == 'Y')) {
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  TambahBarang();

  cout << fixed << setprecision(0);

  cout << "\n=================================================================="
          "=======================================\n";
  // Bagian Header Tabel
  cout << left << setw(5) << "No" << "| " << setw(11) << "Kode Unik" << "| "
       << setw(22) << "Nama Barang" << "| " << setw(14) << "Harga Beli" << "| "
       << setw(14) << "Harga Jual" << "| " << setw(18) << "Promo" << "| "
       << setw(15) << "Harga Promo" << "\n";
  cout << "===================================================================="
          "=====================================\n";

  // 3. Loop 3 tingkat (i = lapisan kodeunik, j = baris, k = kolom)
  int no = 1;
  for (int i = 0; i < daftarbarang.size(); i++) {
    for (int j = 0; j < daftarbarang[i].size(); j++) {
      for (int k = 0; k < daftarbarang[i][j].size(); k++) {
        cout << left << setw(5) << no++ << "| " << setw(11)
             << daftarbarang[i][j][k].kodeunik << "| " << setw(22)
             << daftarbarang[i][j][k].namabarang << "| " << setw(14)
             << daftarbarang[i][j][k].hargabeli << "| " << setw(14)
             << daftarbarang[i][j][k].hargajual << "| " << setw(18)
             << daftarbarang[i][j][k].namapromo << "| " << setw(15)
             << daftarbarang[i][j][k].hargasetelahdiskon << "\n";
      }
    }
  }
  cout << "===================================================================="
          "=====================================\n";

  return 0;
}
