#include "doc_ghi_file.h"

void taiKhoanMenu(vector<TaiKhoan>& dsTaiKhoan) {
	while (true)
	{
		cout << "-----------------------TAI KHOAN-----------------------" << endl;
		cout << "(1) Dang nhap" << endl;
		cout << "(2) Dang ky" << endl;
		cout << "(3) Quen mat khau" << endl;
		cout << "Nhap lua chon cua ban: ";
		string choice;
		getline(cin, choice);
		if (choice == "1") {
			system("cls");
			dangNhap(dsTaiKhoan);
			break;
		}
		else if (choice == "2") {
			system("cls");
			dangKy(dsTaiKhoan);
			system("cls");
		}
		else if (choice == "3") {
			system("cls");
			quenMatKhau(dsTaiKhoan);
			system("cls");		}
		else {
			cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
			system("pause");
			system("cls");
		}
	}
	system("cls");
}

void dangNhap(const vector<TaiKhoan>& dsTaiKhoan) {
	while (true)
	{
		cout << "-----------------------DANG NHAP-----------------------" << endl;
		cout << "Nhap ten tai khoan: ";
		string tenTaiKhoan;
		getline(cin, tenTaiKhoan);
		cout << "Nhap mat khau: ";
		string matKhau;
		getline(cin, matKhau);
		int taiKhoanIndex = binarySearch(dsTaiKhoan, &TaiKhoan::tenTaiKhoan, tenTaiKhoan);

		if (taiKhoanIndex != -1 && dsTaiKhoan[taiKhoanIndex].matKhau == matKhau)
		{
			cout << endl << "Dang nhap thanh cong!" << endl;
			system("pause");
			return;
		}
		else{
			cout << "Dang nhap that bai!" << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}

void dangKy(vector<TaiKhoan>& dsTaiKhoan) {
	while (true)
	{
		cout << "-----------------------DANG KY-----------------------" << endl;
		cout << "Nhap ten tai khoan: ";
		string tenTaiKhoan;
		getline(cin, tenTaiKhoan);
		bool check = false;
		for (int i = 0; i < dsTaiKhoan.size(); i++) {
			if (tenTaiKhoan == dsTaiKhoan[i].tenTaiKhoan) {
				cout << "Ten tai khoan da ton tai. Vui long chon ten khac" << endl;
				check = true;
				system("pause");
				break;
			}
		}
		if (check == true) {
			system("cls");
			continue;
		}
		cout << "Nhap mat khau: ";
		string matKhau;
		getline(cin, matKhau);
		cout << "Nhap lai mat khau: ";
		string matKhau2;
		getline(cin, matKhau2);
		if (matKhau != matKhau2) {
			cout << "Mat khau khong trung khop. Vui long nhap lai!" << endl;
			system("pause");
			system("cls");
			continue;
		}
		cout << endl << "Dang ky thanh cong!" << endl;
		TaiKhoan taiKhoan;
		taiKhoan.tenTaiKhoan = tenTaiKhoan;
		taiKhoan.matKhau = matKhau;
		dsTaiKhoan.push_back(taiKhoan);
		ghiFileTaiKhoan(dsTaiKhoan);
		system("pause");
		return;
	}
}
void quenMatKhau(vector<TaiKhoan>& dsTaiKhoan) {
	while (true)
	{
		cout << "-----------------------QUEN MAT KHAU-----------------------" << endl;
		cout << "Nhap ten tai khoan: ";
		string tenTaiKhoan;
		getline(cin, tenTaiKhoan);
		bool check = false;
		int taiKhoanIndex = -1;
		for (int i = 0; i < dsTaiKhoan.size(); i++) {
			if (tenTaiKhoan == dsTaiKhoan[i].tenTaiKhoan) {
				taiKhoanIndex = i;
				break;
			}
		}
		if (taiKhoanIndex == -1) {
			cout << "Ten tai khoan khong ton tai. Vui long nhap lai!" << endl;
			system("pause");
			system("cls");
			continue;
		}
		else {
			while (true) {
				cout << "Nhap mat khau moi: ";
				string matKhau;
				getline(cin, matKhau);
				cout << "Nhap lai mat khau: ";
				string matKhau2;
				getline(cin, matKhau2);
				if (matKhau != matKhau2) {
					cout << "Mat khau khong trung khop. Vui long nhap lai!" << endl;
					system("pause");
					continue;
				}
				else {
					dsTaiKhoan[taiKhoanIndex].matKhau = matKhau;
					ghiFileTaiKhoan(dsTaiKhoan);
					cout << endl << "Mat khau da duoc doi thanh cong!" << endl;
					system("pause");
					return;
				}
			}
		}
	}
}