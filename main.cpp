#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {

  string password = "admin123";
  string passinput;

  do {
    cout << "masukkan password supermarket\n>> ";
    cin >> passinput;

    if (!(passinput == password)) {
      cout << "password salah! coba lagi\n\n";
    }

  } while (!(passinput == password));

  cout << "selamat datang";

  return 0;
}
