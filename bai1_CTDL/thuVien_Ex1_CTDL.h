#include <iostream>
using namespace std;

struct A1D {
	int n;
	int a[30];
};
void input(A1D &m);
void xuatPTGiuaMang(A1D m);
bool kiemTraSoChan(A1D m);
int timMangLonHon(A1D m);
int soLeDauTien(A1D m);
float trungBinhCongLe(A1D m);
int tichCacKey(A1D m, int key);
bool mangDoiXung(A1D m);
bool kiemTraSNT(int n);
int viTriSNTMax(A1D m);
bool kiemTraMangTang(A1D m);
bool giamDanNuaTrai(A1D m);
void hienthi();
void menu(A1D &m, int &n);


