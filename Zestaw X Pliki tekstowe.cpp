// Zestaw 10. Pliki telstowe
// Zadanie 0.

#include <string> // dla getline
#include <iostream>
#include <fstream> // biblioteka dla pracy z plikami

int main() {

  std::fstream plik("Jabberwocky.txt", std::ios::in); // otwieramy plik
  std::string line; // zmienna wiersza

  // std::ios::in oznacza wypisanie ma ekran

  while (std::getline(plik, line)) {

	std::cout << line << std::endl; // wypisujemu wiersze
  }

  plik.close(); // zamykamy plik

  return 0;
}

// Zadanie 1.

#include <iostream>
#include <fstream>
#include <string> // dla getline

int main() {

  std::fstream plik("Jabberwocky.txt", std::ios::in); // otworzyc plik
  std::string word;

  int ctr = 0; // liczba slow

  // std::ios::in oznacza wypisanie na ekran

  while (!plik.eof()) { // niegacja end of cos

	plik >> word; // odczyt slow z pliku
	ctr++;
  }

  std::cout << "Liczba slow w tekscie: " << ctr << std::endl;

  plik.close(); // zamknac plik

  return 0;
}

// Zadanie 2.

#include <iostream>
#include <fstream>
#include <string>

// skrotowa wersja histogramu

int main() {

  std::fstream plik; // def pliku
  plik.open("Jabberwocky.txt", std::ios::in); // otwirzenie pliku
  std::string line;
  std::string text = " "; // to jest spacja

  int array_letter[26] = {0}; // alfabet

	while (!plik.eof()) { // poki plik sie nie skonczyl
	  getline(plik, line);
	  text += line;
	}

	// skrotowa wersja histogramu

  for (int i = 0; i < text.length(); i++) { // void
	if (65 <= text[i] && text[i] <= 90){
	  array_letter[text[i] - 65]++;
	}
	if (97 <= text[i] && text[i] <= 122){
	  array_letter[text[i] - 97]++;
	}
  }

  // PRINT

  for (int r = 0; r < 26; r++) {
    std::cout << array_letter[r] << " ";
  }

  return 0;
}

// Zadanie 3.

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

int main() {
  std::fstream file;
  file.open("time.txt", std::ios::out); // tworzymy nowy plik

  time_t curremtTime = time(0);

  file << asctime(localtime(&curremtTime));

  file.close();

  return 0;
}

// Zadanie 4.

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {

  std::fstream plik_palindrom; // def dwoch plikow
  std::fstream plik_Ymordnilap;
  plik_palindrom.open("Palindromy.txt", std::ios::in); // to wczytac
  plik_Ymordnilap.open("Ymordnilap.txt", std::ios::out); // to wypisac

  std::string line;

  while (!plik_palindrom.eof()) { // poki plik nie skonczyl sie

	getline(plik_palindrom, line);

	if (line[0] == '"') { // wiersz zaczyna sie od znaczka

	  reverse(line.begin(), line.end()); // odracanie :)
	  plik_Ymordnilap << line; // wpisac wiersz do nowego pliku

	} else {
	  plik_Ymordnilap << line; // bez odracania
	}

	plik_Ymordnilap << std::endl; // nowy wiersz
  }

  plik_palindrom.close(); // otworzyc --> zamknac
  plik_Ymordnilap.close();

  return 0;
}

// Zadanie 5.

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

int main() {

  // PREPARE

  int array_vote[10][10]; // macierz z wynikami
  int array_copy[10][10];
  int tmp; // zmienna pomocnicza

  int size_one_voteS; // liczba kandydatow LUB kolumn // n
  int size_two_voteR; // liczba wyborcow LUB wierszy // m

  srand(time(NULL));

  std::cout << "Prosze wprowadzic liczbe kandydatow oraz wyborcow" << std::endl;
  std::cin >> size_one_voteS >> size_two_voteR;

  // pierwsza def  wierszy

  for (int i = 0; i < size_one_voteS; i++) {
	for (int j = 0; j < size_two_voteR; j++) {
	  array_vote[i][j] = j;
	}
  }

  // powrorzenia

  for (int i = 0; i < size_one_voteS; i++) {
	for (int j = 0; j < size_two_voteR; j++) {

	  tmp = rand() % size_two_voteR;

	  if (array_vote[i][tmp] == tmp) {
	    array_copy[i][j] = tmp;
	    array_vote[i][tmp] = -1; // zamieniamy na liczbe poza zakresem
	  }

	  else{
	    j--;
	  }
	}
  }

  // PRACA Z PLIKIEM

  std::fstream file; // def pliku
  file.open("election.txt", std::ios::out); // wpisac do pliku

  for (int i = 0; i < size_one_voteS; i++) {
	for (int j = 0; j < size_two_voteR; j++) {

	  file << array_copy[i][j] << " ";
	}
	file << std::endl;
  }

  file.close();

  return 0;
}

// Zadanie 6.

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

// PLURALITY

int main() {

  // PREPARE

  int array_vote[10][10]; // macierz z wynikami
  int array_copy[10][10];
  int tmp; // zmienna pomocnicza

  int size_one_voteS; // liczba kandydatow LUB kolumn // n
  int size_two_voteR; // liczba wyborcow LUB wierszy // m

  srand(time(NULL));

  std::cout << "Prosze wprowadzic liczbe kandydatow oraz wyborcow" << std::endl;
  std::cin >> size_one_voteS >> size_two_voteR;

  // pierwsza def  wierszy

  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {
	  array_vote[i][j] = j;
	}
  }

  // powrorzenia

  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {

	  tmp = rand() % size_two_voteR;

	  if (array_vote[i][tmp] == tmp) {
	    array_copy[i][j] = tmp;
	    array_vote[i][tmp] = -1; // zamieniamy na liczbe poza zakresem
	  }

	  else{
	    j--;
	  }
	}
  }

  // PRACA Z PLIKIEM

  std::fstream file; // def pliku
  file.open("election.txt", std::ios::out); // wpisac do pliku

  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {

	  file << array_copy[i][j] << " ";
	}
	file << std::endl;
  }

  file.close();

  // na potrzeby zadania
  // tworzenie towej TAB (zawiera tylko jedna kolumne)

  int array_max[10];

  for (int j = 0; j < size_two_voteR; j++) { // cos jest zle z logika, ale dziala
    array_max[j] = array_copy[j][0];
	}

	int L, maxL = 0; // liczba wystepowan
	int M, maxM; // moda

	for (int i = 0; i < size_two_voteR; i++) {
	  M = array_max[i];
	  L = 0;
	  for (int j = 0; j < size_two_voteR; j++) if (array_max[j] == M) L++;
	  if (L > maxL) {
		maxL = L;
		maxM = M;
	  }
	}

  if (maxL != 1) { // remis

	std::cout << "Moda : " << maxM << std::endl;
	std::cout << "Ilosc wystepowan : " << maxL << std::endl;
  } else{
    std::cout << "No one won " << std::endl;
  }

  return 0;
}
// Zadanie 7.

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

// TWO ROUND MOJORITY (troche latwiejsza wersja)

int main() {

  // PREPARE

  int array_vote[10][10]; // macierz z wynikami
  int array_copy[10][10];
  int tmp; // zmienna pomocnicza

  int size_one_voteS; // liczba kandydatow LUB kolumn // n
  int size_two_voteR; // liczba wyborcow LUB wierszy // m

  srand(time(NULL));

  std::cout << "Prosze wprowadzic liczbe kandydatow oraz wyborcow" << std::endl;
  std::cin >> size_one_voteS >> size_two_voteR;

  // pierwsza def  wierszy

  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {
	  array_vote[i][j] = j;
	}
  }

  // powrorzenia

  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {

	  tmp = rand() % size_two_voteR;

	  if (array_vote[i][tmp] == tmp) {
		array_copy[i][j] = tmp;
		array_vote[i][tmp] = -1; // zamieniamy na liczbe poza zakresem
	  }

	  else{
		j--;
	  }
	}
  }

  // PRACA Z PLIKIEM

  std::fstream file; // def pliku
  file.open("election.txt", std::ios::out); // wpisac do pliku

  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {

	  file << array_copy[i][j] << " ";
	}
	file << std::endl;
  }

  file.close();

  // na potrzeby zadania
  // tworzenie towej TAB (zawiera tylko jedna kolumne)

  int array_max[10];

  // zerowa kolumna

  for (int j = 0; j < size_two_voteR; j++) { // cos jest zle z logika, ale dziala
	array_max[j] = array_copy[j][0];
  }

  int L, maxL = 0; // liczba wystepowan
  int M, maxM; // moda

  for (int i = 0; i < size_two_voteR; i++) {
	M = array_max[i];
	L = 0;
	for (int j = 0; j < size_two_voteR; j++) if (array_max[j] == M) L++;
	if (L > maxL) {
	  maxL = L;
	  maxM = M;
	}
  }

  if (maxL < size_two_voteR / 2) { // jesli nie ma polowy glosow, to dogrywka

    // kolejna kolumna, zerujemy wszystkie wyniki

	for (int j = 0; j < size_two_voteR; j++) { // cos jest zle z logika, ale dziala
	  array_max[j] = array_copy[j][1];
	}

	maxL = 0; // liczba wystepowan

	for (int i = 0; i < size_two_voteR; i++) {
	  M = array_max[i];
	  L = 0;
	  for (int j = 0; j < size_two_voteR; j++) if (array_max[j] == M) L++;
	  if (L > maxL) {
		maxL = L;
		maxM = M;
	  }
	}

	if (maxL != 1) { // remis

	  std::cout << "Moda : " << maxM << std::endl;
	  std::cout << "Ilosc wystepowan : " << maxL << std::endl;
	} else{
	  std::cout << "No one won " << std::endl;
	}

  } else{

	std::cout << "Moda : " << maxM << std::endl;
	std::cout << "Ilosc wystepowan : " << maxL << std::endl;
  }

  return 0;
}
// Zadanie 8.

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

// BORD

int main() {

  // PREPARE

  int array_vote[10][10]; // macierz z wynikami
  int array_copy[10][10];
  int tmp; // zmienna pomocnicza

  int size_one_voteS; // liczba kandydatow LUB kolumn // n
  int size_two_voteR; // liczba wyborcow LUB wierszy // m

  srand(time(NULL));

  std::cout << "Prosze wprowadzic liczbe kandydatow oraz wyborcow" << std::endl;
  std::cin >> size_one_voteS >> size_two_voteR;

  // pierwsza def  wierszy

  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {
	  array_vote[i][j] = j;
	}
  }

  // powrorzenia

  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {

	  tmp = rand() % size_two_voteR;

	  if (array_vote[i][tmp] == tmp) {
		array_copy[i][j] = tmp;
		array_vote[i][tmp] = -1; // zamieniamy na liczbe poza zakresem
	  } else {
		j--;
	  }
	}
  }

  // PRACA Z PLIKIEM

  std::fstream file; // def pliku
  file.open("election.txt", std::ios::out); // wpisac do pliku

  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {

	  file << array_copy[i][j] << " ";
	}
	file << std::endl;
  }

  file.close();

  // na potrzeby zadania

  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {
	  std::cout << array_copy[i][j] << " ";
	}
	std::cout << std::endl;
  }

  int array_resilts[10] = {0};


  for (int i = 0; i < size_two_voteR; i++) {
	for (int j = 0; j < size_one_voteS; j++) {
	  array_resilts[array_copy[i][j]] += size_one_voteS - 1 - j;
	}
  }

  std::cout << std::endl;

  for (int i = 0; i < size_one_voteS; i++) {
    std::cout << array_resilts[i] << " ";
  }

  return 0;
}

