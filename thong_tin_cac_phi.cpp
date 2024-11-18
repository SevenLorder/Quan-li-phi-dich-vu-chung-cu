#include "thong_tin_cac_phi.h"
#include "doc_ghi_file.h"
void menuPhi(vector<DichVu>& Phi)
{
	int choice;
	do
	{
		system("cls");
		cout << "-----------------------Thong tin cac phi-----------------------" << endl;
		cout << "1. Xem danh sach phi" << endl;
		cout << "2. Them phi" << endl;
		cout << "3. Sua thong tin phi" << endl;
		cout << "4. Xoa phi" << endl;
		cout << "5. Tro lai" << endl;
		cout << "Chon chuc nang: ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			xemDanhSachPhi(Phi);
			break;
		case 2:
			themPhi(Phi);
			break;
		case 3:
			suaThongTinPhi(Phi);
			break;
		case 4:
			xoaPhi(Phi);
			break;
		case 5:
			return;
		}
		system("pause");
	} while (choice != 5);
}

void xemDanhSachPhi(const vector<DichVu>& Phi)
{
	system("cls");
	cout << setfill('-');
	cout << setw(130) << "-" << '\n';
	cout << setfill(' ');
	cout << setw(20) << left << "Ten phi" 
		<< setw(10) << left << "Gia"
		<< setw(25) << left << "Tinh theo m2"
		<< setw(25) << left << "Tinh theo dau nguoi"
		<< setw(25) << left << "Tinh theo so xe"
		<< setw(25) << left << "Tinh theo kWh";
	cout << '\n';
	cout << setfill('-');
	cout << setw(130) << left << "-" << '\n';
	cout << setfill(' ');
	for (int i = 0; i < Phi.size(); i++)
	{
		cout << setw(20) << left << Phi[i].tenDichVu;
		cout << setw(10) << left << Phi[i].giaDichVu
			<< setw(25) << left << Phi[i].tinhTheoDienTich
			<< setw(25) << left << Phi[i].tinhTheoSoNguoi
			<< setw(25) << left << Phi[i].tinhTheoSoXe
			<< setw(25) << left << Phi[i].tinhTheoSoDienNuoc << endl;
	}
}
void themPhi(vector<DichVu> &Phi)
{
	DichVu dichVu;
	cout << "Nhap ten phi: ";
	cin.ignore();
	getline(cin, dichVu.tenDichVu);
	cout << "Nhap gia dich vu: ";
	cin >> dichVu.giaDichVu;
	cout << "Tinh theo dien tich (1: Co, 0: Khong): ";
	cin >> dichVu.tinhTheoDienTich;
	cout << "Tinh theo so nguoi (1: Co, 0: Khong): ";
	cin >> dichVu.tinhTheoSoNguoi;
	cout << "Tinh theo so xe (1: Co, 0: Khong): ";
	cin >> dichVu.tinhTheoSoXe;
	cout << "Tinh theo so dien nuoc (1: Co, 0: Khong): ";
	cin >> dichVu.tinhTheoSoDienNuoc;
	Phi.push_back(dichVu);

	ghiFileDichVu(Phi);
}
void suaThongTinPhi(vector<DichVu> &Phi)
{
	bool check = false;
	string tenPhi;
	cout << "Nhap ten phi can sua: ";
	cin.ignore();
	getline(cin, tenPhi);
	for (int i = 0; i < Phi.size(); i++)
	{
		if (Phi[i].tenDichVu == tenPhi)
		{
			cout << "Nhap ten phi: ";
			getline(cin, Phi[i].tenDichVu);
			cout << "Nhap gia dich vu: ";
			cin >> Phi[i].giaDichVu;
			cout << "Tinh theo dien tich (0: Khong, 1: Co): ";
			cin >> Phi[i].tinhTheoDienTich;
			cout << "Tinh theo so nguoi (0: Khong, 1: Co): ";
			cin >> Phi[i].tinhTheoSoNguoi;
			cout << "Tinh theo so xe (0: Khong, 1: Co): ";
			cin >> Phi[i].tinhTheoSoXe;
			cout << "Tinh theo so dien nuoc (0: Khong, 1: Co): ";
			cin >> Phi[i].tinhTheoSoDienNuoc;
			check = true;
			break;
		}
	}
	if (check == false) {
		cout << "Khong tim thay phi" << endl;
		return;
	}
	ghiFileDichVu(Phi);
}
void xoaPhi(vector<DichVu> &Phi)
{
	bool check = false;
	string tenPhi;
	cout << "Nhap ten phi can xoa: ";
	cin.ignore();
	getline(cin, tenPhi);
	for (int i = 0; i < Phi.size(); i++)
	{
		if (Phi[i].tenDichVu == tenPhi)
		{
			Phi.erase(Phi.begin() + i);
			check = true;
			break;
		}
	}
	if (check == false) {
		cout << "Khong tim thay phi" << endl;
		return;
	}
	ghiFileDichVu(Phi);
}