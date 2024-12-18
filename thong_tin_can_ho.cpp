#include "doc_ghi_file.h"

void menuCanHo(vector<CanHo>& dsCanHo)
{
	while (true) {
		cout << "-----------------------THONG TIN CAN HO-----------------------" << endl;
		cout << "1. Xem danh sach can ho" << endl;
		cout << "2. Them can ho" << endl;
		cout << "3. Sua thong tin can ho" << endl;
		cout << "4. Xoa can ho" << endl;
		cout << "5. Tim can ho" << endl;
		cout << "6. Tro lai" << endl;
		cout << "Chon chuc nang: ";
		string choice;
		getline(cin, choice);
		if (choice == "1") {
			system("cls");
			xemDanhSachCanHo(dsCanHo);
		}
		else if (choice == "2") {
			system("cls");
			themCanHo(dsCanHo);
		}
		else if (choice == "3") {
			system("cls");
			suaThongTinCanHo(dsCanHo);
		}
		else if (choice == "4") {
			system("cls");
			xoaCanHo(dsCanHo);
		}
		else if (choice == "5") {
			system("cls");
			timCanHo(dsCanHo);
		}
		else if (choice == "6") {
			return;
		}
		else{
			cout << "Chuc nang khong ton tai. Vui long chon lai!" << endl;
		}
		system("pause");
		system("cls");
	}
}
void xemDanhSachCanHo(const vector<CanHo>& dsCanHo)
{
	cout << setfill('-');
	cout << setw(70) << "-" << '\n';
	cout << setfill(' ');
	cout << setw(15) << left << "Ma can ho";
	cout << setw(30) << left << "Ho ten";
	cout << setw(15) << left << "Dien tich";
	cout << setw(10) << left << "So nguoi" << endl;
	cout << setfill('-');
	cout << setw(70) << left << "-" << '\n';
	cout << setfill(' ');

	for (int i = 0; i < dsCanHo.size(); i++)
	{
		cout << setw(15) << dsCanHo[i].maCanHo
			<< setw(30) << dsCanHo[i].tenChuHo
			<< setw(15) << dsCanHo[i].dienTich
			<< setw(10) << dsCanHo[i].soNguoi << endl;
	}
}
void xemChiTietCanHo(const vector<CanHo>& dsCanHo) {
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
	// de check input
	regex maCanHoPattern("(^\\d+)\\.(\\d+)");
	regex tenPattern("^[a-zA-Z ]*$");
	regex soPattern("(\\d+)");
	xemDanhSachCanHo(dsCanHo);
	cout << endl;
	CanHo canHo;
	string s;
	while(true) {
		int check;
		cout << "Nhap ma can ho (<so tang>.<so nha>): ";
		getline(cin, s);
		if (regex_match(s, maCanHoPattern) == true && s != "") {
			check = binarySearch(dsCanHo, &CanHo::maCanHo, s); // kiem tra xem ma can ho da ton tai chua
			if (check == -1) {
				canHo.maCanHo = s;
				break;
			}
			else {
				cout << "Ma can ho da ton tai" << endl;
			}
		}
		else
		{
			cout << "Ma can ho khong hop le" << endl;
		}
	}
	while(true) {
		cout << "Nhap ho ten chu ho: ";
		getline(cin, s);
		if (regex_match(s, tenPattern) == true && s != "") {
			canHo.tenChuHo = s;
			break;
		}
		else
		{
			cout << "Ten chu ho khong hop le" << endl;
		}
	}
	while (true) {
		cout << "Nhap so nguoi: ";
		getline(cin, s);
		if (regex_match(s, soPattern) == true) {
			canHo.soNguoi = stoi(s);
			break;
		}
		else
		{
			cout << "So nguoi khong hop le" << endl;
		}
	}
	while (true) {
		cout << "Nhap dien tich: ";
		getline(cin, s);
		if (regex_match(s, soPattern) == true) {
			canHo.dienTich = stoi(s);
			break;

		}
		else
		{
			cout << "Dien tich khong hop le" << endl;
		}
	}

	while (true) {
		cout << "Nhap so xe may: ";
		getline(cin, s);
		if (regex_match(s, soPattern) == true) {
			canHo.soXe.first = stoi(s);
			break;
		}
		else
		{
			cout << "So xe may khong hop le" << endl;
		}
	} 
	while (true) {
		cout << "Nhap so xe hoi: ";
		getline(cin, s);
		if (regex_match(s, soPattern) == true) {
			canHo.soXe.second = stoi(s);
			break;
		}
		else
		{
			cout << "So xe hoi khong hop le" << endl;
		}
	}
	while (true) {
		cout << "Nhap so dien: ";
		getline(cin, s);
		if (regex_match(s, soPattern) == true) {
			canHo.soDienNuoc.first = stoi(s);
			break;
		}
		else
		{
			cout << "So dien khong hop le" << endl;
		}
	}
	while (true) {
		cout << "Nhap so nuoc: ";
		getline(cin, s);
		if (regex_match(s, soPattern) == true) {
			canHo.soDienNuoc.second = stoi(s);
			break;
		}
		else
		{
			cout << "So nuoc khong hop le" << endl;
		}
	}
	dsCanHo.push_back(canHo);

	// Sap xe vector dsCanHo theo maCanHo tang dan
	sort(dsCanHo.begin(), dsCanHo.end(), [](const CanHo& a, const CanHo& b) {
		return a.maCanHo < b.maCanHo;
		});

	cout << endl << "Da them thanh cong" << endl;

	ghiFileCanHo(dsCanHo);
}
void suaThongTinCanHo(vector<CanHo> &dsCanHo)
{
	while (true) {
		string maCanHo, infor;
		int canHoIndex;
		xemChiTietCanHo(dsCanHo);
		cout << endl;
		cout << "Nhap ma can ho can sua (<so tang>.<so nha>): ";
		getline(cin, maCanHo);
		canHoIndex = binarySearch(dsCanHo, &CanHo::maCanHo, maCanHo); // kiem tra xem ma can ho da ton tai chua
		if (canHoIndex == -1)
		{
			cout << "Khong tim thay can ho" << endl;
			system("pause");
			system("cls");
			continue;
		}
		cout << "(1) Ma can ho" << endl;
		cout << "(2) Ho ten chu ho" << endl;
		cout << "(3) So nguoi" << endl;
		cout << "(4) Dien tich" << endl;
		cout << "(5) So xe may" << endl;
		cout << "(6) So xe hoi" << endl;
		cout << "(7) So dien" << endl;
		cout << "(8) So nuoc" << endl;	
		cout << "Chon thong tin can sua: ";
		getline(cin, infor);

		// de check input
		regex maCanHoPattern("(^\\d+)\\.(\\d+)");
		regex tenPattern("^[a-zA-Z ]*$");
		regex soPattern("(\\d+)");

		string s;
		while (true){
			if (infor == "1") {
				cout << "Nhap ma can ho moi: ";
				getline(cin, s);
				int canHoIndex2 = binarySearch(dsCanHo, &CanHo::maCanHo, s); // kiem tra xem ma can ho da ton tai chua
				if (canHoIndex2 == -1 && s != "" && regex_match(s, maCanHoPattern) == true) {
					dsCanHo[canHoIndex].maCanHo = s;

					// Sap xe vector dsCanHo theo maCanHo tang dan
					sort(dsCanHo.begin(), dsCanHo.end(), [](const CanHo& a, const CanHo& b) {
						return a.maCanHo < b.maCanHo;
						});
					break;
				}
				else
				{
					cout << "Ma can ho khong hop le" << endl;
					continue;
				}
			}
			if (infor == "2") {
				cout << "Nhap ho ten moi: ";
				getline(cin, s);
				if (regex_match(s, tenPattern) == true && s != "") {
					dsCanHo[canHoIndex].tenChuHo = s;
					break;
				}
				else
				{
					cout << "Ten chu ho khong hop le" << endl;
					continue;
				}
			}
			else if (infor == "3") {
				cout << "Nhap so nguoi moi: ";
				getline(cin, s);
				if (regex_match(s, soPattern) == true) {
					dsCanHo[canHoIndex].soNguoi = stoi(s);
					break;
				}
				else
				{
					cout << "So nguoi khong hop le" << endl;
					continue;
				}
			}
			else if (infor == "4") {
				cout << "Nhap dien tich moi: ";
				getline(cin, s);
				if (regex_match(s, soPattern) == true) {
					dsCanHo[canHoIndex].dienTich = stoi(s);
					break;
				}
				else
				{
					cout << "Dien tich khong hop le" << endl;
					continue;
				}
			}
			else if (infor == "5") {
				cout << "Nhap so xe may moi: ";
				getline(cin, s);
				if (regex_match(s, soPattern) == true) {
					dsCanHo[canHoIndex].soXe.first = stoi(s);
					break;
				}
				else
				{
					cout << "So xe may khong hop le" << endl;
					continue;
				}
			}
			else if (infor == "6") {
				cout << "Nhap so xe hoi moi: ";
				getline(cin, s);
				if (regex_match(s, soPattern) == true) {
					dsCanHo[canHoIndex].soXe.second = stoi(s);
					break;
				}
				else
				{
					cout << "So xe hoi khong hop le" << endl;
					continue;
				}
			}
			else if (infor == "7") {
				cout << "Nhap so dien moi: ";
				getline(cin, s);
				if (regex_match(s, soPattern) == true) {
					dsCanHo[canHoIndex].soDienNuoc.first = stoi(s);
					break;
				}
				else
				{
					cout << "So dien khong hop le" << endl;
					continue;
				}
			}
			else if (infor == "8") {
				cout << "Nhap so nuoc moi: ";
				getline(cin, s);
				if (regex_match(s, soPattern) == true) {
					dsCanHo[canHoIndex].soDienNuoc.second = stoi(s);
					break;
				}
				else
				{
					cout << "So nuoc khong hop le" << endl;
					continue;
				}
			}
			else {
				cout << "Khong tim thay thong tin" << endl;
				cout << "Chon thong tin can sua: ";
				getline(cin, infor);
				continue;
			}
		}
		cout << endl << "Da sua thanh cong" << endl;
		ghiFileCanHo(dsCanHo);
		return;
	}
}
void xoaCanHo(vector<CanHo> &dsCanHo)
{
	while (true)
	{
		bool check = false;
		string maCanHo;
		xemDanhSachCanHo(dsCanHo);
		cout << endl << "Nhap ma can ho can xoa (<so tang>.<so nha>): ";
		getline(cin, maCanHo);
		int canHoIndex = binarySearch(dsCanHo, &CanHo::maCanHo, maCanHo); // kiem tra xem ma can ho da ton tai chua
		if (canHoIndex != -1) {
			dsCanHo.erase(dsCanHo.begin() + canHoIndex);
			cout << endl << "Da xoa thanh cong" << endl;
			ghiFileCanHo(dsCanHo);
			return;
		}
		else
		{
			cout << "Khong tim thay can ho" << endl;
			system("pause");
			system("cls");
		}
	}
}
void timCanHo(const vector<CanHo>& dsCanHo) {
	while (true) {
		xemChiTietCanHo(dsCanHo);
		cout << endl;
		cout << "Nhap ma can ho can tim (<so tang>.<so nha>): ";
		string maCanHo;
		getline(cin, maCanHo);
		int canHoIndex = -1;
		canHoIndex = binarySearch(dsCanHo, &CanHo::maCanHo, maCanHo);
		if (canHoIndex != -1) {

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

			cout << setw(15) << dsCanHo[canHoIndex].maCanHo
				<< setw(30) << dsCanHo[canHoIndex].tenChuHo
				<< setw(15) << dsCanHo[canHoIndex].dienTich
				<< setw(10) << dsCanHo[canHoIndex].soNguoi;
			stringstream ss;
			ss << dsCanHo[canHoIndex].soXe.first << "/" << dsCanHo[canHoIndex].soXe.second;
			cout << setw(20) << ss.str();
			ss.str(""); // Xóa dữ liệu
			ss.clear(); // Xóa các trạng thái lỗi
			ss << dsCanHo[canHoIndex].soDienNuoc.first << "/" << dsCanHo[canHoIndex].soDienNuoc.second;
			cout << setw(20) << ss.str() << endl;
			return;
		}
		else {
			cout << "Khong tim thay can ho" << endl;
			system("pause");
			system("cls");
		}
	}
}

