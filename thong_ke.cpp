#include "thong_ke.h"

void thongKe(const vector<HoaDon>& dsHoaDon, const vector<CanHo>& dsCanHo)
{
	while (true) {
		system("cls");
		cout << "-----------------------THONG KE-----------------------" << endl;
		cout << "1. Thong ke tinh trang thanh toan cac can ho" << endl;
		cout << "2. Thong ke doanh thu" << endl;
		cout << "3. Thong ke so cu dan" << endl;
		cout << "4. Thong ke so can ho" << endl;
		cout << "5. Thong ke so luong xe" << endl;
		cout << "6. Thong ke so luong dien nuoc" << endl;
		cout << "7. Tro lai" << endl;
		cout << "Chon chuc nang: ";
		string choice;
		getline(cin, choice);

		if (choice == "1") {
			system("cls");
			tinhTrangThanhToan(dsHoaDon);
		}
		else if (choice == "2") {
			system("cls");
			thongKeDoanhThu(dsHoaDon);
		}
		else if (choice == "3") {
			system("cls");
			thongKeSoCuDan(dsCanHo);
		}
		else if (choice == "4") {
			system("cls");
			thongKeSoCanHo(dsCanHo);
		}
		else if (choice == "5") {
			system("cls");
			thongKeSoLuongXe(dsCanHo);
		}
		else if (choice == "6") {
			system("cls");
			thongKeSoLuongDienNuoc(dsCanHo);
		}
		else if (choice == "7") {
			return;
		}
		else {
			cout << "Chuc nang khong ton tai. Vui long chon lai!" << endl;
		}
		system("pause");
		system("cls");
	}
}	

void tinhTrangThanhToan(const vector<HoaDon>& dsHoaDon)
{
	cout << "Nhap tinh trang thanh toan (Chua thanh toan/ Da thanh toan): ";
	string tinhTrang;
	getline(cin, tinhTrang);
	
	for (int i = 0; i < dsHoaDon.size(); i++) {
		if (dsHoaDon[i].thanhToan == tinhTrang) {
			cout << setfill('-');
			cout << setw(40) << "-" << '\n';
			cout << setfill(' ');
			cout << setw(13) << left << " ";
			cout << "HOA DON CAN HO" << endl;

			int tongTien = 0;
			cout << "Thoi gian: " << dsHoaDon[i].thang << "/" << dsHoaDon[i].nam << endl;
			cout << "Ma can ho: " << dsHoaDon[i].canHo.maCanHo << endl;
			cout << "Ten chu ho: " << dsHoaDon[i].canHo.tenChuHo << endl;
			for (int j = 0; j < dsHoaDon[i].chiTietPhi.size(); j++)
			{
				tongTien += tinhTien1Phi(dsHoaDon[i].canHo, dsHoaDon[i].chiTietPhi[j]);
				cout << dsHoaDon[i].chiTietPhi[j].tenDichVu << ": " << tinhTien1Phi(dsHoaDon[i].canHo, dsHoaDon[i].chiTietPhi[i]) << " dong" << endl;
			}
			cout << "Tong tien: " << dsHoaDon[i].tongTien << " dong" << endl;
			cout << "Tinh trang thanh toan: " << dsHoaDon[i].thanhToan << endl;
		}
		
	}
	cout << setfill('-');
	cout << setw(40) << "-" << '\n';
	cout << setfill(' ');
}
void thongKeDoanhThu(const vector<HoaDon>& dsHoaDon) {
	int tongDoanhThu = 0;
	for (int i = 0; i < dsHoaDon.size(); i++) {
		if (dsHoaDon[i].thanhToan == "Da thanh toan") {
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
			cout << setfill('-');
			cout << setw(40) << "-" << '\n';
			cout << setfill(' ');

			tongDoanhThu += dsHoaDon[i].tongTien;
		}
	}
	cout << endl << "Tong doanh thu: " << tongDoanhThu << " dong" << endl;
}
void thongKeSoCuDan(const vector<CanHo>& dsCanHo) {
	int soCuDan = 0;
	xemChiTietCanHo(dsCanHo);
	for (int i = 0; i < dsCanHo.size(); i++) {
		soCuDan += dsCanHo[i].soNguoi;
	}
	cout << endl << "So cu dan: " << soCuDan << endl;
}
void thongKeSoCanHo(const vector<CanHo>& dsCanHo) {
	xemChiTietCanHo(dsCanHo);
	cout << endl << "So can ho: " << dsCanHo.size() << endl;
}
void thongKeSoLuongXe(const vector<CanHo>& dsCanHo) {
	xemChiTietCanHo(dsCanHo);
	int soLuongXeMay = 0;
	int soLuongXeOto = 0;
	for (int i = 0; i < dsCanHo.size(); i++) {
		soLuongXeMay += dsCanHo[i].soXe.first;
		soLuongXeOto += dsCanHo[i].soXe.second;
	}
	cout << endl << "So luong xe may: " << soLuongXeMay << endl;
	cout << "So luong xe oto: " << soLuongXeOto << endl;
}
void thongKeSoLuongDienNuoc(const vector<CanHo>& dsCanHo) {
	xemChiTietCanHo(dsCanHo);
	int soLuongDien = 0;
	int soLuongNuoc = 0;
	for (int i = 0; i < dsCanHo.size(); i++) {
		soLuongDien += dsCanHo[i].soDienNuoc.first;
		soLuongNuoc += dsCanHo[i].soDienNuoc.second;
	}
	cout << endl << "So luong dien tieu thu: " << soLuongDien << endl;
	cout << "So luong nuoc tieu thu: " << soLuongNuoc << endl;
}