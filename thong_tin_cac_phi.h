#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct DichVu {
	string tenDichVu;
	int giaDichVu;
	bool tinhTheoDienTich;
	bool tinhTheoSoNguoi;
	bool tinhTheoSoXe;
	bool tinhTheoSoDienNuoc;
};
void menuPhi(vector<DichVu>& dsDichVu);
void themPhi(vector<DichVu> &dsDichVu);
void suaThongTinPhi(vector<DichVu> &dsDichVu);
void xoaPhi(vector<DichVu> &dsDichVu);
void xemDanhSachPhi(const vector<DichVu>& dsDichVu);
