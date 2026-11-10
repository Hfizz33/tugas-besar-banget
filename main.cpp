#include "login.hpp"
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  int pilihan;
  // berada di login.
  login();

  cout << "==========================\n";
  cout << "===selamat datang kasir===\n";
  cout << "==========================\n";

  do {

    cout << "silahkan pilih salah satu opsi di bawah ini:\n"
         << "1. management barang\n"
         << "2. transaksi kasir\n"
         << "3. restock barang\n"
         << "4. riwayat transaksi kasir\n"
         << "5. keluar\n"
         << "pilih rentang angka diatas\n>>";
    cin >> pilihan;

    switch (pilihan) {
    case 1: {
      // management barang\n
      break;
    }
    case 2: {
      // transaksi kasir
      break;
    }
    case 3: {
      // restock barang
      break;
    }
    case 4: {
      // riwayat transaksi
      break;
    }
    case 5: {
      cout << "terimakasih telah menggunakan program kami";
      break;
    }
    default: {
      cout << "opsi tidak valid!\n menghentikan program...";
      return 0;
    }
    }
  } while (!(pilihan == 5));

  return 0;
}
