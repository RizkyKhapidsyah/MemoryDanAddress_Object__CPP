#include <iostream>
#include <string>
#include <chrono>
#include <conio.h>

using namespace std;

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

class Kosong
{
public:
	int data()
	{
		return 1;
	}
};

class Isi
{
public:
	int dataInt1;  // 4 Bytes
	int dataInt2;  // 4 Bytes
	double dataDouble;
	string dataStr;
};

class Mahasiswa
{
public:
	string nama;

	Mahasiswa(const char* nama)
	{
		Mahasiswa::nama = nama;
	}
};

int main()
{
	/* Besaran Memory untuk sebuah object */
	/* Kita akan menampilkan besar dari class kosong */
	cout << "Alokasi Class: Kosong adalah  = " << sizeof(Kosong) << " byte" << endl;
	cout << "Alokasi Class: Isi adalah     = " << sizeof(Isi) << " byte" << endl;

	//Address
	string a;
	string b;
	Mahasiswa object1 = Mahasiswa("RizkyKhapidsyah");		//Berada di Stack
	Mahasiswa* object2 = new Mahasiswa("RizkyKhapidsyah");	//Berada di Heap
	string c;
	string d;

	cout << "\nAddress : " << endl;
	cout << &a << endl;
	cout << &b << endl;
	cout << &object1 << endl;
	cout << &object2 << endl;
	cout << object2 << endl;
	cout << &c << endl;
	cout << &d << endl;

	//Seberapa Cepat kita membuat object di masing-masing memory
	TimePoint* tStackStart = new TimePoint();
	TimePoint* tStackEnd = new TimePoint();
	TimePoint* tHeapStart = new TimePoint();
	TimePoint* tHeapEnd = new TimePoint();
	
	cin.get();
	*tStackStart = Clock::now();
	Mahasiswa object3 = Mahasiswa("Testing1");
	*tStackEnd = Clock::now();

	cin.get();
	*tHeapStart = Clock::now();
	Mahasiswa *object4 = new Mahasiswa("Testing2");
	*tHeapEnd = Clock::now();

	chrono::duration<double> durasi = *tStackEnd - *tStackStart;
	cout << "Waktu pembuatan object di Stack adalah  = " << durasi.count() << endl;

	durasi = *tHeapEnd - *tHeapStart;
	cout << "Waktu pembuatan object di Heap adalah   = " << durasi.count() << endl;
	
	_getch();
	return 0;
}

/*
	Memori dari sebuah class tergantung dari 
	seberapa banyak atribut yang berada pada 
	class tersebut.
*/
