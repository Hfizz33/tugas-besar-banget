#include <cctype> // Untuk isalpha, islower, isupper
#include <iostream>
#include <string>

using namespace std;
string shiftCipher(const string &teks, int shift) {
  string hasil = teks;

  // Normalisasi nilai shift biar selalu berada di rentang 0 - 25
  shift = (shift % 26 + 26) % 26;

  for (char &c : hasil) {
    if (isalpha(c)) {
      char base = islower(c) ? 'a' : 'A';
      // Hitung offset relatif, tambahkan lompatan, wrap-around dengan modulo 26
      c = base + (c - base + shift) % 26;
    }
    // Karakter non-alfabet (spasi, angka, tanda baca) dibiarkan utuh
  }

  return hasil;
}

void login() {
  while (true) {
    string password = "ehqmrepjeqmhm";
    string passinput;

    cout << "masukkan password: ";
    cin >> passinput;

    passinput = shiftCipher(passinput, 4);

    if (passinput == password) {
      break;
    } else {
      cout << "password tidak valid!\n";
    }
  }
}
