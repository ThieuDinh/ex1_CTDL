#include "thuVien_Ex1_CTDL.h"
using namespace std;

void input(A1D &m)
{
	cout << "Nhap so phan tu cua mang: ";
	cin >> m.n;
	for (int i = 0; i < m.n; i++)
	{
		cout << "Nhap phan tu [" << i << "]: ";
		cin >> m.a[i];
	}

}

//1 Xuat ra phan tu giua cua mang
void xuatPTGiuaMang(A1D m)
{
	int mid = m.n / 2;
	cout << "Phan tu giua mang " << m.a[mid] << endl;
}

//2 Kiem tra phan tu dau mang co phai la so chan hay khong?
bool kiemTraSoChan(A1D m)
{
	for (int i = 0; i < m.n; i++)
	{
		if (m.a[0] % 2 == 0)
			return true;
	}
	return false;
}

//3 Mot nua mang ben trai co lon hon nua mang ben phai hay khong?
int timMangLonHon(A1D m)
{
	if (m.n % 2 != 0)
		return false;
	int Giua = m.n / 2;
	int Trai = 0;
	int Phai = 0;
	for (int i = 0; i < Giua; i++)
		Trai += m.a[i];
	for (int i = Giua; i < m.n; i++)
		Phai += m.a[i];
	if (Trai > Phai)
		return 1;
	return -1;
}

//4 Tim vi tri cua so le dau tien trong nua mang dau
int soLeDauTien(A1D m)
{
	for (int i = 0; i < m.n / 2; i++)
	{
		if (m.a[i] % 2 != 0)
			return i;
	}
	return -1;

}

//5 Tinh trung binh cong cac so le cua mang
float trungBinhCongLe(A1D m)
{
	int sum = 0;
	int count = 0;
	for (int i = 0; i < m.n; i++)
	{
		if (m.a[i] % 2 != 0)
		{
			sum += m.a[i];
			count++;
		}
	}
	if (count != 0)
		return float(sum) / count;
	else
		return -1;
}

//6 Tinh tich cac so co key trung trong mang
int tichCacKey(A1D m, int key)
{
	int count = 0;
	for (int i = 0; i < m.n; i++)
	{
		if (m.a[i] == key)
			count++;
	}
	if (count != 0)
		return (pow(key, count));
	else
		return -1;
}



//8 Tim vi tri la so nguyen to lon nhat
bool kiemTraSNT(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
			count++;
	}
	if (count == 2)
		return true;
	else
		return false;
}
int viTriSNTMax(A1D m)
{
	int max = 0;
	int viTri = 0;
	for (int i = 0; i < m.n; i++)
	{
		if (kiemTraSNT(m.a[i]) == true)
		{
			if (m.a[i] > max)
			{
				max = m.a[i];
				viTri = i;
			}
		}
	}
	return viTri;
}
//7 Kiem tra mang nhap vao co phai la mang doi xung hay khong?
bool mangDoiXung(A1D m)
{
	for (int i = 0; i < m.n / 2; i++)
	{
		if (m.a[i] != m.a[m.n - i - 1])
			return false;
	}
	return true;
}
//9 Kiem tra mang nhap vao co phai la mang tang
bool kiemTraMangTang(A1D m)
{
	for (int i = 0; i < m.n - 1; i++)
	{
		if (m.a[i] < m.a[i + 1])
			continue;
		else
			return false;
	}
	return true;
}

//10 Kiem tra nua dau mang ben trai co tinh giam dan
bool giamDanNuaTrai(A1D m)
{
	for (int i = 0; i < (m.n / 2) - 1; i++)
	{

		if (m.a[i] > m.a[i + 1])
			continue;
		else
			return false;
	}
	return true;
}

void hienthi()
{
	cout << "=========================================================================" << endl;
	cout << " \t\t\t\t Cac chuc nang " << endl;
	cout << "  1. Xuat ra phan tu giua cua mang" << endl;
	cout << "  2. Kiem tra phan tu dau mang co phai la so chan hay khong?" << endl;
	cout << "  3. Mot nua mang ben trai co lon hon nua mang ben phai hay khong?" << endl;
	cout << "  4. Tim vi tri cua so le dau tien trong nua mang dau" << endl;
	cout << "  5. Tinh trung binh cong cac so le cua mang" << endl;
	cout << "  6. Tinh tich cac so co key trung trong mang" << endl;
	cout << "  7. Kiem tra mang nhap vao co phai la mang doi xung hay khong?" << endl;
	cout << "  8. Tim vi tri la so nguyen to lon nhat" << endl;
	cout << "  9. Kiem tra mang nhap vao co phai la mang tang" << endl;
	cout << " 10. Kiem tra nua dau mang ben trai co tinh giam dan" << endl;
	cout << "  0. Thoat chuong trinh" << endl;
	cout << "=========================================================================" << endl;
}

void menu(A1D &m, int &n)
{
	int chon;
	input(m);
	do {
		cout << "\nChon 1 so de chon chuc nang: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			xuatPTGiuaMang(m);
			break;
		case 2:
			if (kiemTraSoChan(m) == true)
				cout << "Phan tu dau cua mang la so chan " << endl;
			else
				cout << "Phan tu dau cua mang khong la so chan " << endl;
			break;
		case 3:
			if (timMangLonHon(m) == 1)
				cout << "Nua mang ben trai lon hon" << endl;
			else
				cout << "Nua mang ben trai khong lon hon" << endl;
			break;
		case 4:
			if (soLeDauTien(m) != -1)
				cout << "Vi tri so le dau tien cua mang la " << soLeDauTien(m) << endl;
			else
				cout << "Nua dau cua mang khong co so le " << endl;
			break;
		case 5:
			if (trungBinhCongLe(m) != -1)
				cout << "Trung binh cong cac so le cua mang la " << trungBinhCongLe(m) << endl;
			else
				cout << "Mang khong co so le " << endl;
			break;
		case 6:
			int key;
			cout << "Nhap mot key ";
			cin >> key;
			if (tichCacKey(m, key) != -1)
				cout << "Tich cac so trung voi Key la " << tichCacKey(m, key) << endl;
			else
				cout << "Mang khong co so trung voi key " << endl;
			break;
		case 7:
			if (mangDoiXung(m) == true)
				cout << "Mang doi xung " << endl;
			else
				cout << "Mang khong doi xung" << endl;
			break;
		case 8:
			if (viTriSNTMax(m) != 0)
				cout << "Vi tri so nguyen to lon nhat trong mang " << viTriSNTMax(m) << endl;
			else
				cout << "Mang khong co so nguyen to " << endl;
			break;
		case 9:
			if (kiemTraMangTang(m) == true)
				cout << "Mang tang dan " << endl;
			else
				cout << "Mang khong tang dan " << endl;
			break;
		case 10:
			if (giamDanNuaTrai(m) == true)
				cout << "Nua dau ben trai cua mang giam dan " << endl;
			else
				cout << "Nua dau ben trai cua mang khong giam dan " << endl;
			break;
		default:
			break;
		}
	} while (chon != 0);
}
