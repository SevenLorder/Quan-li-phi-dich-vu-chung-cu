#include "thong_tin_can_ho.h"
#include "doc_ghi_file.h"
void menuCanHo(vector<CanHo>& dsCanHo)
{
	int choice = 0;
	do
	{
		system("cls");
		cout << "-----------------------Thong tin cac can ho-----------------------" << endl;
		cout << "1. Xem danh sach can ho" << endl;
		cout << "2. Them can ho" << endl;
		cout << "3. Sua thong tin can ho" << endl;
		cout << "4. Xoa can ho" << endl;
		cout << "5. Tro lai" << endl;
		cout << "Chon chuc nang: ";
		cin >> choice;
		system("cls");
	
		switch (choice)
		{
		case 1:
			xemDanhSachCanHo(dsCanHo);
			break;
		case 2:
			themCanHo(dsCanHo);
			break;
		case 3:
			suaThongTinCanHo(dsCanHo);
			break;
		case 4:
			xoaCanHo(dsCanHo);
			break;
		case 5:
			return;
		}
		system("pause");
	}while(choice != 5);
}
void xemDanhSachCanHo(const vector<CanHo>& dsCanHo)
{
	cout << setfill('-');
	cout << setw(110) << "-" << '\n';
	cout << setfill(' ');
	cout << setw(15) << left << "Ma can ho";
	cout << setw(30) << left << "Ho ten";
	cout << setw(15) << left << "Dien tich";
	cout << setw(10) << left << "So nguoi";
	cout << setw(20) << left << "Xe may/xe hoi";
	cout << setw(20) << left << "Dien/nuoc" << endl;
	cout << setfill('-');
	cout << setw(110) << left << "-" << '\n';
	cout << setfill(' ');

	for (int i = 0; i < dsCanHo.size(); i++)
	{
		cout << setw(15) << dsCanHo[i].maCanHo
			<< setw(30) << dsCanHo[i].tenChuHo
			<< setw(15) << dsCanHo[i].dienTich
			<< setw(10) << dsCanHo[i].soNguoi;
		stringstream ss;
		ss << dsCanHo[i].soXe.first << "/" << dsCanHo[i].soXe.second;
		cout << setw(20) << ss.str();
		ss.str(""); // Xóa dữ liệu
		ss.clear(); // Xóa các trạng thái lỗi
		ss << dsCanHo[i].soDienNuoc.first << "/" << dsCanHo[i].soDienNuoc.second;
		cout << setw(20) << ss.str() << endl;
	}
}
void themCanHo(vector<CanHo> &dsCanHo)
{
	CanHo canHo;
	cin.ignore();
	cout << "Nhap ma can ho: ";
	getline(cin, canHo.maCanHo);
	cout << "Nhap ho ten chu ho: ";
	getline(cin, canHo.tenChuHo);
	cout << "Nhap so nguoi: ";
	cin >> canHo.soNguoi;
	cout << "Nhap dien tich: ";
	cin >> canHo.dienTich;
	cout << "Nhap so xe may: ";
	cin >> canHo.soXe.first;
	cout << "Nhap so xe hoi: ";
	cin >> canHo.soXe.second;
	cout << "Nhap so dien: ";
	cin >> canHo.soDienNuoc.first;
	cout << "Nhap so nuoc: ";
	cin >> canHo.soDienNuoc.second;
	dsCanHo.push_back(canHo);

	ghiFileCanHo(dsCanHo);
}
void suaThongTinCanHo(vector<CanHo> &dsCanHo)
{
	bool check = false;
	string maCanHo;
	cout << "Nhap ma can ho can sua: ";
	cin.ignore();
	getline(cin, maCanHo);
	for (int i = 0; i < dsCanHo.size(); i++)
	{
		if (dsCanHo[i].maCanHo == maCanHo)
		{
			cout << "Nhap ho ten chu ho: ";
			getline(cin, dsCanHo[i].tenChuHo);
			cout << "Nhap so nguoi: ";
			cin >> dsCanHo[i].soNguoi;
			cout << "Nhap dien tich: ";
			cin >> dsCanHo[i].dienTich;
			cout << "Nhap so xe may: ";
			cin >> dsCanHo[i].soXe.first;
			cout << "Nhap so xe hoi: ";
			cin >> dsCanHo[i].soXe.second;
			cout << "Nhap so dien: ";
			cin >> dsCanHo[i].soDienNuoc.first;
			cout << "Nhap so nuoc: ";
			cin >> dsCanHo[i].soDienNuoc.second;
			check = true;
			break;
		}
	}
	if (check == false)
	{
		cout << "Khong tim thay can ho" << endl;
		return;
	}
	ghiFileCanHo(dsCanHo);
}
void xoaCanHo(vector<CanHo> &dsCanHo)
{
	bool check = false;
	string maCanHo;
	cout << "Nhap ma can ho can xoa: ";
	cin.ignore();
	getline(cin, maCanHo);
	for (int i = 0; i < dsCanHo.size(); i++)
	{
		if (dsCanHo[i].maCanHo == maCanHo)
		{
			dsCanHo.erase(dsCanHo.begin() + i);
			check = true;
			break;
		}
	}
	if (check == false)
	{
		cout << "Khong tim thay can ho" << endl;
		return;
	}
	ghiFileCanHo(dsCanHo);
}
