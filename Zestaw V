Zadanie 0.

#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
  int C[7][7];

  srand(time(NULL));

  for (int i = 0; i < 7; i++) {
	std::cout << std::endl;
    for (int j = 0; j < 7; j++) {
      C[i][j] = -10 + rand() % 21;
      std::cout << C[i][j] << "   ";
    }
	}
  return 0;
  }

Zadanie 1.

#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
  int C[7][7];
  int suma = 0;

  srand(time(NULL));

  for (int i = 0; i < 7; i++) {
	std::cout << std::endl;
	for (int j = 0; j < 7; j++) {
	  C[i][j] = -10 + rand() % 21;
	  std::cout << C[i][j] << "   ";
	  suma += C[i][j];
	}
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Suma elementow = " << suma << std::endl;

  return 0;
}

Zadanie 2.

#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
  int C[7][7];
  int max = C[0][0];
  int a = 0, b = 0 ; // wspolrzedne

  srand(time(NULL));

  for (int i = 0; i < 7; i++) {
	std::cout << std::endl;
	for (int j = 0; j < 7; j++) {
	  C[i][j] = -10 + rand() % 21;

	  if (C[i][j] > max) {
		max = C[i][j];
		a = i, b = j;
	  }

	  std::cout << C[i][j] << "   ";
	}
  }

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Najwiekszym elementem w macierzy jest " <<  max << std::endl;
  std::cout << "Wszpolrzedne : [" << a << "][" << b << "]" << std::endl;

  return 0;
}

Zadanie 3.

#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
  int C[7][7];
  float sumaW = 0; // wiersze
  float sumaK = 0; // kolumny

  srand(time(NULL));

  for (int i = 0; i < 7; i++) {
	std::cout << std::endl;
	for (int j = 0; j < 7; j++) {
	  C[i][j] = -10 + rand() % 21;
	  std::cout << C[i][j] << "  ";
	}
  }
  std::cout << std:: endl;
  std::cout << "Srednia arytmetyczna  : " << std::endl;

  for (int i = 0; i < 7; i++) {
	std::cout << std::endl;
	sumaW = 0;
	sumaK = 0;
	for (int j = 0; j < 7; j++) {
	  sumaW += C[i][j];
	  sumaK += C[j][i];
	}
	std::cout << "W [" << i << "] = " << sumaW / 7 << ",  K [" << i << "] = " << sumaK / 7;;
  }
  return 0;
}

Zadanie 4.

#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
  int C[7][7];

  srand(time(NULL));

  std::cout << "Macierz C : " << std::endl;
  std::cout << std::endl;

  // PREPARE

  for (int i = 0; i < 7; i++) {
	for (int j = 0; j < 7; j++) {
	  C[i][j] = -10 + rand() % 21;
	  std::cout << C[i][j] << "   ";
	}
	std::cout << std::endl;
  }

  // TRANSPOSE

  for (int i = 0; i < 7; i++) {
	for (int j = i + 1; j < 7; j++) {
	  int tmp = C[i][j];
	  C[i][j] = C[j][i];
	  C[j][i] = tmp;
	}
  }

  // PRINT

  std::cout << std::endl;
  std::cout << "C trasponowana :" << std::endl;
  std::cout << std::endl;

  for (int i = 0; i < 7; i++) {
	for (int j = 0; j < 7; j++) {
	  std::cout << C[i][j] << "   " ;
	}
	std::cout << std::endl;
  }

  return 0;
}

Zadanie 5. ( Sposob pierwszy)

#include <iostream>

int main() {

  int C[8];

  for (int n = 0; n < 8; n++) {
    std::cout << std::endl;

	for (int a = 1; a <= n; a++) {
	  C[a] = 0;
	}

	C[0] = 1; // 1 0 0

	for (int b = 1; b <= n; b++) { // 1 0 0 --> 1 1 0  --> 1 1 1 --> 1 2 1
	  for (int c = b; c >= 1; c--) {
		C[c] += C[c - 1]; // 1 + 0
	  }
	}
	for (int d = 0; d <= n; d++) {
	  std::cout << C[d] << " ";
	}
  }

  return 0;
}

Zadanie 5. (Sposob drugi)

#include <iostream>

int main() {

  const int n = 7;
  int C[n][n];

  for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++) {
	  if (j == i || j == 0) {
		C[i][j] = 1;
	  } else {
		C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	  }
	  std::cout << C[i][j] << " ";
	}
	std::cout << std::endl;
  }

  return 0;
}

Zadanie 6.

#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
  int D[20][20][3];

  srand(time(NULL));

  for (int a = 0; a < 20; a++) {
	for (int b = 0; b < 20; b++) {
	  for (int c = 0; c < 3; c++) {
		D[a][b][c] = 0 + rand() % 256;
	  }
	}
  }

  for (int c = 0; c < 3; c++) {
	std::cout << std::endl;
	std::cout << std::endl;
    for (int a = 0; a < 20; a++) {

      for (int b = 0; b < 20; b++) {
		std::cout << D[a][b][c] << "   ";
      }
	  std::cout << std::endl;
    }
  }
  return 0;
}

Zadanie 7.

#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
  int D[20][20][3]; // stara macierz
  int C[20][20]; // nowa macierz

  std::cout << "Macierz D : " << std::endl;
  std::cout << std::endl;

  srand(time(NULL));

  for (int a = 0; a < 20; a++) {
	for (int b = 0; b < 20; b++) {
	  for (int c = 0; c < 3; c++) {
		D[a][b][c] = 0 + rand() % 256;
	  }
	}
  }

  for (int c = 0; c < 3; c++) {
	std::cout << std::endl;
	std::cout << std::endl;
	for (int a = 0; a < 20; a++) {
	  for (int b = 0; b < 20; b++) {
		std::cout << D[a][b][c] << "   ";
	  }
	  std::cout << std::endl;
	}
  }
  std::cout << std::endl;
  std::cout << "Nowa macierz E : " << std::endl;
  std::cout << std::endl;

  for (int a = 0; a < 20; a++) {
    std::cout << std::endl;

	for (int b = 0; b < 20; b++) {

	  float suma = 0;

	  for (int c = 0; c < 3; c++) {
		suma += D[a][b][c];
		}
	  C[a][b] = suma / 3.;
	  std::cout << C[a][b] << "   ";
	  }
	}

  return 0;
}

// Zadanie z gwiazdka

#include <iostream>
#include<cstdlib>
#include<ctime>

int main() {

  const int n = 15;
  int A[n][n] = {0};
  int jeden = 0;

  std::srand(time(nullptr));

  // TWORZENIE MACIERZY

  std::cout << "Mapa : " << std::endl;

  for (int i = 0; i < n; i++) {
	std::cout << std::endl;
	for (int j = 0; j < n; j++) {

	  int roll = rand() % 100;
	  if (roll > 70) {
		A[i][j] = 1;
	  }
	  std::cout << A[i][j] << " ";
	}
  }

  // LICZBA IZOLOWANYCH WYSPEK (WARIANT PIERWSZY)
  // PRZECHODZIMY PO MACIERZY

  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {

	  // CZY TO JEST WYSPA ?

	  if (A[i][j] == 1) {

		// CZY TO JEST WYSPA IZOLOWANA ?

		// WYJATKOWE PRZYPADKI

		if (i == 0 && j == 0 && A[i + 1][j] == 0 && A[i][j + 1] == 0 // PRZYPADEK 00
			|| i == 0 && j == n - 1 && A[i + 1][j] == 0 && A[i][j - 1] == 0 // PRZYPADEK 0n
			|| i == n - 1 && j == 0 && A[i - 1][j] == 0 && A[i][j + 1] == 0 // PRZYPADEK n0
			|| i == n - 1 && j == n - 1 && A[i - 1][j] == 0 && A[i][j - 1] == 0) { // PRZYPDAEK nn

		  jeden += 1;

		} else if (i == 0 && A[i + 1][j] == 0 && A[i][j - 1] == 0 && A[i][j + 1] == 0 // 0j
			|| i == n - 1 && A[i - 1][j] == 0 && A[i][j - 1] == 0 && A[i][j + 1] == 0 // nj
			|| j == 0 && A[i + 1][j] == 0 && A[i - 1][j] == 0 && A[i][j + 1] == 0 // i0
			|| j == n - 1 && A[i + 1][j] == 0 && A[i - 1][j] == 0 && A[i][j - 1] == 0) { //in

		  jeden += 1;

		  // PRZYPADKI OGOLNE

		} else if (A[i + 1][j] == 0 && A[i - 1][j] == 0 && A[i][j + 1] == 0 && A[i][j - 1] == 0) {

		  jeden += 1;
		}
	  }
	}
  }

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Liczba izolowanych wyspek wynosi : " << jeden << std::endl;

  return 0;
}
