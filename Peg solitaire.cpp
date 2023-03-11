// POP_2020_12_08_projekt_1_Koitalla_Agnieszka_EiT_3_184933.cpp // Code::Blocks 17.12 // GNU GCC Compiler

#include <iostream>

#include <iomanip>


using namespace std;

const int wielkosc = 11;

void tworzeniePlanszy(char plansza[][wielkosc]);
void rysowaniePlanszy(char plansza[][wielkosc]);

void ruch(char plansza[][wielkosc]);

int liczeniePionkow(char plansza[][wielkosc]);
int sprawdzanieRuchu(char plansza[][wielkosc]);

int main() {
  char plansza[wielkosc][wielkosc];

  tworzeniePlanszy(plansza);
  rysowaniePlanszy(plansza);

  int blokada;
  int licznik = 0;

  while (licznik == 0) {

    ruch(plansza);
    rysowaniePlanszy(plansza);
    blokada = sprawdzanieRuchu(plansza);
    licznik = liczeniePionkow(plansza);

    if (blokada == 0 && licznik != 1) {
      cout << "Wszystkie pionki sa zablokowane. Nie udalo ci sie pomyslnie ukonczyc gry." << endl;
      break;
    }

  }
  if (licznik == 1) cout << "Ukonczyles pomyslnie gre!!" << endl;

  return 0;
}

void tworzeniePlanszy(char plansza[][wielkosc]) {

  //tworzenie pustej planszy
  for (int i = 0; i < wielkosc; i++) {
    for (int j = 0; j < wielkosc; j++) {

      if (i <= 1 || i >= 5) {
        if (j <= 3 || j >= 5) {

          plansza[i][j] = 'p';
        } else {

          plansza[i][j] = ' ';
        }
      } else plansza[i][j] = ' ';
    }

  }

  // Wypelnianie planszy pionkami
  for (int i = 0; i < wielkosc; i++) {
    for (int j = 0; j < wielkosc; j++) {

      if (i >= 4 && i <= 6 && j > 1 && j < 9) {
        if (i == 5 && j == 5) plansza[i][j] = '.';

        else plansza[i][j] = 'o';

      } else if (j >= 4 && j <= 6 && i > 1 && i < 9)
        plansza[i][j] = 'o';
    }
  }

}

void rysowaniePlanszy(char plansza[][wielkosc]) {

  cout << "=================================================" << endl;
  cout << "|                 MOZLIWE RUCHY                 |" << endl;
  cout << "|   gora    |   dol    |    lewo    |   prawo   |" << endl;
  cout << "=================================================" << endl;
  cout << endl;
  cout << setw(10);

  // numeracja kolumny
  for (int i = 2; i < 9; i++) {
    cout << " " << i - 1 << " ";
  }

  cout << endl;
  cout << endl;

  // numeracja wierszy i uzupelnienie pustych miejsc bialymi znakami
  for (int i = 2; i < 9; i++) {
    cout << " " << i - 1 << " ";

    for (int j = 0; j < wielkosc; j++) {

      if (plansza[i][j] == 'p') cout << "   ";
      else cout << " " << plansza[i][j] << " ";
    }
    cout << endl;
  }

}
// funkcja odpowiedzialna za wybor oraz ruch pionka
void ruch(char plansza[][wielkosc]) {

  int x, y, X, Y;
  string strona;

  cout << endl;
  cout << "Podaj numer wiersza: ";
  cin >> x;
  cout << "Podaj numer kolumny: ";
  cin >> y;

  // dopasowanie koordynatow podanych przez uzytkownika do indekskow tablicy
  X = x + 1;
  Y = y + 1;

  if (plansza[X][Y] == 'o') {

    cout << "W ktora strone chcesz ruszyc pionkiem? ";
    cin >> strona;
    cout << endl;

    if (strona == "gora") {
      if (plansza[X - 2][Y] == '.' && plansza[X - 1][Y] == 'o') { //-- sprawdzenie, czy ruch jest mozliwy
        plansza[X - 2][Y] = 'o';                                  //-- jesli jest mozliwy zamiana pustego pola na pionek
        plansza[X - 1][Y] = '.';                                  //-- usuniecie przeskoczonego pionka
        plansza[X][Y] = '.';                                      //-- zmiana pola, na ktorym stal przemieszczony pionek na puste

      } else {
        cout << "Wybierz inne miejsce!";
        cout << endl;
        cout << endl;
      }
    } else if (strona == "dol") {
      if (plansza[X + 2][Y] == '.' && plansza[X + 1][Y] == 'o') {
        plansza[X + 2][Y] = 'o';
        plansza[X + 1][Y] = '.';
        plansza[X][Y] = '.';

      } else {
        cout << "Wybierz inne miejsce!";
        cout << endl;
        cout << endl;
      }
    } else if (strona == "lewo") {
      if (plansza[X][Y - 2] == '.' && plansza[X][Y - 1] == 'o') {
        plansza[X][Y - 2] = 'o';
        plansza[X][Y - 1] = '.';
        plansza[X][Y] = '.';

      } else {
        cout << "Wybierz inne miejsce!";
        cout << endl;
        cout << endl;
      }
    } else if (strona == "prawo") {
      if (plansza[X][Y + 2] == '.' && plansza[X][Y + 1] == 'o') {
        plansza[X][Y + 2] = 'o';
        plansza[X][Y + 1] = '.';
        plansza[X][Y] = '.';

      } else {
        cout << "Wybierz inne miejsce!";
        cout << endl;
        cout << endl;
      }
    }
  } else {
    cout << "Wybierz inny pionek" << endl;

  }

}
// funkcja liczaca ilosc pozostalych na planszy pionkow
int liczeniePionkow(char plansza[][wielkosc]) {

  int licznik = 0;

  for (int i = 0; i < wielkosc; i++) {
    for (int j = 0; j < wielkosc; j++) {

      if (plansza[i][j] == 'o') {
        licznik++;
      }
    }
  }

  cout << endl;
  cout << "Liczba pozostalych pionkow na planszy: " << licznik;
  cout << endl;
  cout << endl;

  if (licznik == 1) return 1;

  else return 0;

}
// funkcja sprawdzajaca, czy pionki na planszy sa zablokowane
int sprawdzanieRuchu(char plansza[][wielkosc]) {

  int blokada = 0;

  for (int i = 0; i < wielkosc; i++) {
    for (int j = 0; j < wielkosc; j++) {

      if (plansza[i][j] == 'o') {
        if (plansza[i - 2][j] == '.' && plansza[i - 1][j] == 'o') {
          blokada++;
        } else if (plansza[i + 2][j] == '.' && plansza[i + 1][j] == 'o') {
          blokada++;
        } else if (plansza[i][j - 2] == '.' && plansza[i][j - 1] == 'o') {
          blokada++;
        } else if (plansza[i][j + 2] == '.' && plansza[i][j + 1] == 'o') {
          blokada++;
        }
      }
    }
  }

  return blokada;

}
