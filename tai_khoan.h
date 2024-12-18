#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


struct TaiKhoan {
	string tenTaiKhoan;
	string matKhau;
};

void dangNhap(const vector<TaiKhoan>& dsTaiKhoan);
void dangKy(vector<TaiKhoan>& dsTaiKhoan);
void taiKhoanMenu(vector<TaiKhoan>& dsTaiKhoan);
void quenMatKhau(vector<TaiKhoan>& dsTaiKhoan);