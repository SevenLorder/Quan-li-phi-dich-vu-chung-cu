#include "doc_ghi_file.h"

void menuPhi(vector<DichVu>& Phi)
{
	while (true)
	{
		system("cls");
		cout << "-----------------------THONG TIN CAC PHI-----------------------" << endl;
		cout << "1. Xem danh sach phi" << endl;
		cout << "2. Them phi" << endl;
		cout << "3. Sua thong tin phi" << endl;
		cout << "4. Xoa phi" << endl;
		cout << "5. Tim phi" << endl;
		cout << "6. Tro lai" << endl;
		cout << "Chon chuc nang: ";
		string choice;
		getline(cin, choice);
		if (choice == "1") {
			system("cls");
			xemDanhSachPhi(Phi);
		}
		else if (choice == "2") {
			system("cls");
			themPhi(Phi);
		}
		else if (choice == "3") {
			system("cls");
			suaThongTinPhi(Phi);
		}
		else if (choice == "4") {
			system("cls");
			xoaPhi(Phi);
		}
		else if (choice == "5") {
			system("cls");
			timPhi(Phi);
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
			<< setw(25) << left << boolalpha << Phi[i].tinhTheoDienTich
			<< setw(25) << left << boolalpha << Phi[i].tinhTheoSoNguoi
			<< setw(25) << left << boolalpha << Phi[i].tinhTheoSoXe
			<< setw(25) << left << boolalpha << Phi[i].tinhTheoSoDienNuoc << endl;
	}
}
void themPhi(vector<DichVu> &Phi)
{
	// de check input
	regex tenPattern("^[a-zA-Z ]*$");
	regex soPattern("(\\d+)");
	string s;

	xemDanhSachPhi(Phi);
	cout << endl;
	DichVu dichVu;
	while (true) {
		int phiIndex;
		cout << "Nhap ten phi: ";
		getline(cin, s);
		if (regex_match(s, tenPattern) == true && s != "") {
			phiIndex = binarySearch(Phi, &DichVu::tenDichVu, s); // check trung ten phi
			if (phiIndex == -1){
				dichVu.tenDichVu = s;
				break;
			}
			else {
				cout << "Ten phi da ton tai. Vui long nhap lai" << endl;
				continue;
			}
		}
		else {
			cout << "Ten phi khong hop le. Vui long nhap lai" << endl;
		}
	}
	while (true) {
		cout << "Nhap gia dich vu: ";
		getline(cin, s);
		if (regex_match(s, soPattern)) {
			dichVu.giaDichVu = stoi(s);
			break;
		}
		else {
			cout << "Gia dich vu khong hop le. Vui long nhap lai" << endl;
		}

	}
	while (true) {
		cout << "Tinh theo dien tich (1: Co, 0: Khong): ";
		getline(cin, s);
		if (s == "1" || s == "0") {
			dichVu.tinhTheoDienTich = stoi(s);
			break;
		}
		else {
			cout << "Khong hop le. Vui long nhap lai" << endl;
		}
		
	}
	while (true) {
		cout << "Tinh theo so nguoi (1: Co, 0: Khong): ";
		getline(cin, s);
		if (s == "1" || s == "0") {
			dichVu.tinhTheoSoNguoi = stoi(s);
			break;
		}
		else {
			cout << "Khong hop le. Vui long nhap lai" << endl;
		}
	}
	while (true) {
		cout << "Tinh theo so xe (1: Co, 0: Khong): ";
		getline(cin, s);
		if (s == "1" || s == "0") {
			dichVu.tinhTheoSoXe = stoi(s);
			break;
		}
		else {
			cout << "Khong hop le. Vui long nhap lai" << endl;
		}

	}
	while (true) {
		cout << "Tinh theo so dien nuoc (1: Co, 0: Khong): ";
		getline(cin, s);
		if (s == "1" || s == "0") {
			dichVu.tinhTheoSoDienNuoc = stoi(s);
			break;
		}
		else {
			cout << "Khong hop le. Vui long nhap lai" << endl;
		}

	}
	cout << endl << "Da them thanh cong" << endl;
	Phi.push_back(dichVu);

	// sort lai vector theo alphabe
	sort(Phi.begin(), Phi.end(), [](const DichVu& a, const DichVu& b) {
		return a.tenDichVu < b.tenDichVu;
	});

	ghiFileDichVu(Phi);
	return;
}
void suaThongTinPhi(vector<DichVu> &Phi)
{
	while (true) {
		bool check = false;
		string tenPhi;
		xemDanhSachPhi(Phi);
		cout << endl << "Nhap ten phi can sua: ";
		getline(cin, tenPhi);
		int phiIndex = binarySearch(Phi, &DichVu::tenDichVu, tenPhi);
		if (phiIndex == -1) {
			cout << "Khong tim thay phi" << endl;
			system("pause");
			system("cls");
			continue;
		}
		string infor;
		cout << endl;
		cout << "(1) Ten phi" << endl;
		cout << "(2) Gia dich vu" << endl;
		cout << "(3) Tinh theo dien tich" << endl;
		cout << "(4) Tinh theo so nguoi" << endl;
		cout << "(5) Tinh theo so xe" << endl;
		cout << "(6) Tinh theo so dien nuoc" << endl;
		cout << "Chon thong tin can sua: ";
		getline(cin, infor);

		// de check input
		regex tenPattern("^[a-zA-Z ]*$");
		regex soPattern("(\\d+)");
		string s;
		do {
			if (infor == "1") {
				while (true) {
					cout << "Nhap ten moi: ";
					getline(cin, s);
					if (regex_match(s, tenPattern) && s != "") {
						int phiIndex2 = binarySearch(Phi, &DichVu::tenDichVu, s);
						if (phiIndex2 != -1) {
							cout << "Ten phi da ton tai. Vui long nhap lai" << endl;
							continue;
						}
						else {
							Phi[phiIndex].tenDichVu = s;

							// sort lai vector theo alphabe
							sort(Phi.begin(), Phi.end(), [](const DichVu& a, const DichVu& b) {
								return a.tenDichVu < b.tenDichVu;
							});

							break;
						}
					}
					else {
						cout << "Ten phi khong hop le. Vui long nhap lai" << endl;
					}
				}
			}
			else if (infor == "2") {
				while (true) {
					cout << "Nhap gia moi: ";
					getline(cin, s);
					if (regex_match(s, soPattern)) {
						Phi[phiIndex].giaDichVu = stoi(s);
						break;
					}
					else {
						cout << "Gia dich vu khong hop le. Vui long nhap lai" << endl;
					}
				}
			}
			else if (infor == "3") {
				while (true) {
					cout << "Tinh theo dien tich (1: Co, 0: Khong): ";
					getline(cin, s);
					if (s == "1" || s == "0") {
						Phi[phiIndex].tinhTheoDienTich = stoi(s);
						break;
					}
					else {
						cout << "Khong hop le. Vui long nhap lai" << endl;
					}
				}
			}
			else if (infor == "4") {
				while (true) {
					cout << "Tinh theo so nguoi (1: Co, 0: Khong): ";
					getline(cin, s);
					if (s == "1" || s == "0") {
						Phi[phiIndex].tinhTheoSoNguoi = stoi(s);
						break;
					}
					else {
						cout << "Khong hop le. Vui long nhap lai" << endl;
					}
				}
			}
			else if (infor == "5") {
				while (true) {
					cout << "Tinh theo so xe (1: Co, 0: Khong): ";
					getline(cin, s);
					if (s == "1" || s == "0") {
						Phi[phiIndex].tinhTheoSoXe = stoi(s);
						break;
					}
					else {
						cout << "Khong hop le. Vui long nhap lai" << endl;
					}
				}
			}
			else if (infor == "6") {
				while (true) {
					cout << "Tinh theo so dien nuoc (1: Co, 0: Khong): ";
					getline(cin, s);
					if (s == "1" || s == "0") {
						Phi[phiIndex].tinhTheoSoDienNuoc = stoi(s);
						break;
					}
					else {
						cout << "Khong hop le. Vui long nhap lai" << endl;
					}
				}
			}
			else {
				cout << "Khong tim thay thong tin" << endl;
				cout << "Chon thong tin can sua: ";
				getline(cin, infor);
				continue;
			}
			check = true;
		} while (check == false);
		cout << endl;
		cout << "Da sua thanh cong" << endl;
		ghiFileDichVu(Phi);
		return;
	}
}
void xoaPhi(vector<DichVu> &Phi)
{
	while (true) {
		xemDanhSachPhi(Phi);
		string tenPhi;
		cout << endl << "Nhap ten phi can xoa: ";
		getline(cin, tenPhi);
		int phiIndex = binarySearch(Phi, &DichVu::tenDichVu, tenPhi);
		if (phiIndex == -1) {
			cout << "Khong tim thay phi" << endl;
			system("pause");
			system("cls");
			continue;
		}

		Phi.erase(Phi.begin() + phiIndex);
		cout << endl << "Da xoa thanh cong" << endl;
		ghiFileDichVu(Phi);
		return;
	}
}
void timPhi(const vector<DichVu>& Phi) {
	while (true)
	{
		xemDanhSachPhi(Phi);
		cout << endl << "Nhap ten phi can tim: ";
		string tenPhi;
		getline(cin, tenPhi);
		int phiIndex = binarySearch(Phi, &DichVu::tenDichVu, tenPhi);
		if (phiIndex == -1) {
			cout << "Khong tim thay phi" << endl;
			system("pause");
			system("cls");
			continue;
		}
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
		cout << setw(20) << left << Phi[phiIndex].tenDichVu;
		cout << setw(10) << left << Phi[phiIndex].giaDichVu
			<< setw(25) << left << boolalpha << Phi[phiIndex].tinhTheoDienTich
			<< setw(25) << left << boolalpha << Phi[phiIndex].tinhTheoSoNguoi
			<< setw(25) << left << boolalpha << Phi[phiIndex].tinhTheoSoXe
			<< setw(25) << left << boolalpha << Phi[phiIndex].tinhTheoSoDienNuoc << endl;
		return;
	}
}