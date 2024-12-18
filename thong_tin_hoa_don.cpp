#include "doc_ghi_file.h"

int tinhTien1Phi(const CanHo& canHo, const DichVu& dichVu)
{
	int tien = 0;
	if (dichVu.tinhTheoDienTich)
	{
		tien += canHo.dienTich * dichVu.giaDichVu;
	}
	else if (dichVu.tinhTheoSoNguoi)
	{
		tien += canHo.soNguoi * dichVu.giaDichVu;
	}
	else if (dichVu.tinhTheoSoXe)
	{
		tien += canHo.soXe.first * dichVu.giaDichVu;
		tien += canHo.soXe.second * dichVu.giaDichVu;
	}
	else if (dichVu.tinhTheoSoDienNuoc)
	{
		tien += (canHo.soDienNuoc.first + canHo.soDienNuoc.second) * dichVu.giaDichVu;
	}
	return tien;
}
void menuHoaDon(vector<HoaDon> &dsHoaDon, const vector<CanHo>& dsCanHo, const vector<DichVu>& dsPhi)
{
	while (true) {
			system("cls");
			cout << "-----------------------THONG TIN HOA DON-----------------------" << endl;
			cout << "1. Xem danh sach hoa don" << endl;
			cout << "2. Xuat hoa don" << endl;
			cout << "3. Sua hoa don" << endl;
			cout << "4. Xoa hoa don" << endl;
			cout << "5. Tim hoa don" << endl;
			cout << "6. Tro lai" << endl;
			cout << "Chon chuc nang: ";
			string choice;
			getline(cin, choice);

			if (choice == "1") {
				system("cls");
				xemDanhSachHoaDon(dsHoaDon);
			}
			else if (choice == "2") {
				system("cls");
				xuatHoaDon(dsHoaDon, dsCanHo, dsPhi);
				}
			else if (choice == "3") {
				system("cls");
				suaHoaDon(dsHoaDon, dsCanHo);
			}
			else if (choice == "4") {
				system("cls");
				xoaHoaDon(dsHoaDon);
			}
			else if (choice == "5") {
				system("cls");
				timHoaDon(dsHoaDon);
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

void xuatHoaDon(vector<HoaDon> &dsHoaDon, const vector<CanHo>& dsCanHo, const vector<DichVu>& dsPhi)
{
	while (true) {
		xemDanhSachCanHo(dsCanHo);
		cout << endl;
		cout << "Nhap ma can ho muon xuat hoa don (<so tang>.<so nha>): ";
		string maCanHo;
		getline(cin, maCanHo);
		int canHoIndex = binarySearch(dsCanHo, &CanHo::maCanHo, maCanHo);
		if (canHoIndex == -1)
		{
			cout << "Khong tim thay can ho" << endl;
			system("pause");
			system("cls");
			continue;
		}

		HoaDon hoaDon;
		string s;
		regex soPattern("(\\d+)");
		while (true) {
			cout << "Nhap thang: ";
			getline(cin, s);
			if (regex_match(s, soPattern) == true && stoi(s) >= 1 && stoi(s) <= 12) {
				hoaDon.thang = stoi(s);
				break;
			}
			else
			{
				cout << "Thang khong hop le" << endl;
				continue;
			}
		}
		while (true) {
			cout << "Nhap nam: ";
			getline(cin, s);
			if (regex_match(s, soPattern) == true) {
				hoaDon.nam = stoi(s);
				break;
			}
			else
			{
				cout << "Nam khong hop le" << endl;
				continue;
			}
		}
		while (true) {
			cout << "Nhap tinh trang thanh toan (Chua thanh toan/Da thanh toan): ";
			getline(cin, s);
			if (s == "Chua thanh toan" || s == "Da thanh toan") {
				hoaDon.thanhToan = s;
				break;
			}
			else
			{
				cout << "Tinh trang thanh toan khong hop le" << endl;
				continue;
			}
		}
		hoaDon.canHo = dsCanHo[canHoIndex];
		hoaDon.chiTietPhi = dsPhi;
		stringstream ss;
		ss << maCanHo << "-" << to_string(hoaDon.thang) << "-" << to_string(hoaDon.nam);
		hoaDon.maHoaDon = ss.str();

		cout << setfill('-');
		cout << setw(40) << left << "-" << '\n';
		cout << setfill(' ');
		int tongTien = 0;
		cout << setw(13) << left << " ";
		cout << "HOA DON CAN HO" << endl;
		cout << "Ma hoa don: " << hoaDon.maHoaDon << endl;
		cout << "Thoi gian: " << hoaDon.thang << "/" << hoaDon.nam << endl;
		cout << "Ma can ho: " << hoaDon.canHo.maCanHo << endl;
		cout << "Ten chu ho: " << hoaDon.canHo.tenChuHo << endl;
		for (int j = 0; j < hoaDon.chiTietPhi.size(); j++)
		{
			int tienMotPhi = tinhTien1Phi(hoaDon.canHo, hoaDon.chiTietPhi[j]);
			hoaDon.tienTungPhi.push_back(make_pair(hoaDon.chiTietPhi[j], tienMotPhi));
			tongTien += tienMotPhi;
			cout << hoaDon.tienTungPhi[j].first.tenDichVu << ": " << hoaDon.tienTungPhi[j].second << " dong" << endl;
		}
		hoaDon.tongTien = tongTien;
		cout << "Tong tien: " << hoaDon.tongTien << " dong" << endl;
		cout << "Tinh trang thanh toan: " << hoaDon.thanhToan << endl;
		cout << setfill('-');
		cout << setw(40) << left << "-" << '\n';
		cout << setfill(' ');

		cout << endl << "Da xuat hoa don thanh cong" << endl;
		dsHoaDon.push_back(hoaDon);
		// sort ds hoa don
		sort(dsHoaDon.begin(), dsHoaDon.end(), [](const HoaDon& a, const HoaDon& b) {
			if (a.canHo.maCanHo == b.canHo.maCanHo)
			{
				if (a.nam == b.nam)
				{
					return a.thang < b.thang;
				}
				return a.nam < b.nam;
			}
			return a.canHo.maCanHo < b.canHo.maCanHo;
		});
		ghiFileHoaDon(dsHoaDon);
		return;
	}
}
void xemDanhSachHoaDon(const vector<HoaDon> &dsHoaDon)
{
	for (int i = 0; i < dsHoaDon.size(); i++)
	{
		cout << setfill('-');
		cout << setw(40) << "-" << '\n';
		cout << setfill(' ');     
		cout << setw(13) << left << " ";
		cout << "HOA DON CAN HO" << endl;

		int tongTien = 0;
		cout << "Ma hoa don: " << dsHoaDon[i].maHoaDon << endl;
		cout << "Thoi gian: " << dsHoaDon[i].thang << "/" << dsHoaDon[i].nam << endl;
		cout << "Ma can ho: " << dsHoaDon[i].canHo.maCanHo << endl;
		cout << "Ten chu ho: " << dsHoaDon[i].canHo.tenChuHo << endl;
		for (int j = 0; j < dsHoaDon[i].chiTietPhi.size(); j++)
		{
			cout << dsHoaDon[i].tienTungPhi[j].first.tenDichVu << ": " << dsHoaDon[i].tienTungPhi[j].second << " dong" << endl;
		}
		cout << "Tong tien: " << dsHoaDon[i].tongTien << " dong" << endl;
		cout << "Tinh trang thanh toan: " << dsHoaDon[i].thanhToan << endl;
	}
	cout << setfill('-');
	cout << setw(40) << "-" << '\n';
	cout << setfill(' ');
}
void suaHoaDon(vector<HoaDon> &dsHoaDon, const vector<CanHo>& dsCanHo)
{
	while (true) 
	{
		string maHoaDon;
		xemDanhSachHoaDon(dsHoaDon);
		cout << endl;
		cout << "Nhap ma hoa don can sua (<ma can ho>-<thang>-<nam>): ";
		regex maHoaDonPattern("(\\d+)\\.(\\d+)-(\\d+)-(\\d+)");
		getline(cin, maHoaDon);
		if (regex_match(maHoaDon, maHoaDonPattern) == false)
		{
			cout << "Ma hoa don khong hop le" << endl;
			system("pause");
			system("cls");
			continue;
		}
		int hoaDonIndex = binarySearch(dsHoaDon, &HoaDon::maHoaDon, maHoaDon);
		if (hoaDonIndex == -1)
		{
			cout << "Khong tim thay hoa don" << endl;
			system("pause");
			system("cls");
			continue;
		}
		cout << endl;
		cout << "(1) Thanh toan" << endl;
		while (true) {
			cout << "Chon thong tin can sua: ";
			string choice;
			getline(cin, choice);
			if (choice == "1") {
				while (true) {
					cout << "Thanh toan (Chua thanh toan/Da thanh toan): ";
					string thanhToan;
					getline(cin, thanhToan);
					if (thanhToan == "Chua thanh toan" || thanhToan == "Da thanh toan")
					{
						dsHoaDon[hoaDonIndex].thanhToan = thanhToan;
						cout << endl << "Da cap nhat thanh cong" << endl;
						ghiFileHoaDon(dsHoaDon);
						return;
					}
					else
					{
						cout << "Tinh trang thanh toan khong hop le" << endl;
						system("pause");
						continue;
					}
				}
			}
			else {
				cout << "Khong tim thay thong tin" << endl;
				system("pause");
				continue;
			}
		}
		
	}
}
void xoaHoaDon(vector<HoaDon> &dsHoaDon)
{
	while (true) {
		string maHoaDon;
		xemDanhSachHoaDon(dsHoaDon);
		cout << endl;
		cout << "Nhap ma hoa don can xoa (<ma can ho>-<thang>-<nam>): ";
		regex maHoaDonPattern("(\\d+)\\.(\\d+)-(\\d+)-(\\d+)");
		getline(cin, maHoaDon);
		if (regex_match(maHoaDon, maHoaDonPattern) == false)
		{
			cout << "Ma hoa don khong hop le" << endl;
			system("pause");
			system("cls");
			continue;
		}
		int hoaDonIndex = binarySearch(dsHoaDon, &HoaDon::maHoaDon, maHoaDon);
		if (hoaDonIndex == -1) {
			cout << "Khong tim thay hoa don" << endl;
			system("pause");
			system("cls");
			continue;
		}
		dsHoaDon.erase(dsHoaDon.begin() + hoaDonIndex);
		ghiFileHoaDon(dsHoaDon);
		cout << endl << "Da xoa thanh cong" << endl;
		return;
	}
}
void timHoaDon(vector<HoaDon>& dsHoaDon) {
	while (true) {
		string maHoaDon;
		xemDanhSachHoaDon(dsHoaDon);
		cout << endl;
		cout << "Nhap ma hoa don can tim (<ma can ho>-<thang>-<nam>): ";
		regex maHoaDonPattern("(\\d+)\\.(\\d+)-(\\d+)-(\\d+)");
		getline(cin, maHoaDon);
		if (regex_match(maHoaDon, maHoaDonPattern) == false)
		{
			cout << "Ma hoa don khong hop le" << endl;
			system("pause");
			system("cls");
			continue;
		}
		int hoaDonIndex = binarySearch(dsHoaDon, &HoaDon::maHoaDon, maHoaDon);
		if (hoaDonIndex == -1) {
			cout << "Khong tim thay hoa don" << endl;
			system("pause");
			system("cls");
			continue;
		}
		cout << setfill('-');
		cout << setw(40) << "-" << '\n';
		cout << setfill(' ');
		cout << setw(13) << left << " ";
		cout << "HOA DON CAN HO" << endl;

		int tongTien = 0;
		cout << "Ma hoa don: " << dsHoaDon[hoaDonIndex].maHoaDon << endl;
		cout << "Thoi gian: " << dsHoaDon[hoaDonIndex].thang << "/" << dsHoaDon[hoaDonIndex].nam << endl;
		cout << "Ma can ho: " << dsHoaDon[hoaDonIndex].canHo.maCanHo << endl;
		cout << "Ten chu ho: " << dsHoaDon[hoaDonIndex].canHo.tenChuHo << endl;
		for (int j = 0; j < dsHoaDon[hoaDonIndex].chiTietPhi.size(); j++)
		{
			cout << dsHoaDon[hoaDonIndex].tienTungPhi[j].first.tenDichVu << ": " << dsHoaDon[hoaDonIndex].tienTungPhi[j].second << " dong" << endl;
		}
		cout << "Tong tien: " << dsHoaDon[hoaDonIndex].tongTien << " dong" << endl;
		cout << "Tinh trang thanh toan: " << dsHoaDon[hoaDonIndex].thanhToan << endl;
		cout << setfill('-');
		cout << setw(40) << "-" << '\n';
		cout << setfill(' ');
		return;
	}
}