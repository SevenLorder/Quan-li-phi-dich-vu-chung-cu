#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct HoaDon {
	string maHoaDon; // Cau truc: <ma can ho>-<thang>-<nam>
	CanHo canHo;
	int tongTien;
	vector<DichVu> chiTietPhi;
	vector<pair<DichVu, int>> tienTungPhi;
	string thanhToan;
	int thang;
	int nam;
};

int tinhTien1Phi(const CanHo& canHo, const DichVu& dichVu);
void menuHoaDon(vector<HoaDon>& dsHoaDon, const vector<CanHo>& dsCanHo, const vector<DichVu>& dsPhi);
void xemDanhSachHoaDon(const vector<HoaDon>& dsHoaDon);
void xuatHoaDon(vector<HoaDon>& dsHoaDon, const vector<CanHo>& dsCanHo, const vector<DichVu>& dsPhi);
void suaHoaDon(vector<HoaDon>& dsHoaDon, const vector<CanHo>& dsCanHo);
void xoaHoaDon(vector<HoaDon>& dsHoaDon);
void timHoaDon(vector<HoaDon>& dsHoaDon);