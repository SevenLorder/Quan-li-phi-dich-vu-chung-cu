#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "doc_ghi_file.h"
using namespace std;


void thongKe(const vector<HoaDon>& dsHoaDon, const vector<CanHo>& dsCanHo);
void tinhTrangThanhToan(const vector<HoaDon>& dsHoaDon);
void thongKeDoanhThu(const vector<HoaDon>& dsHoaDon);
void thongKeSoCuDan(const vector<CanHo>& dsCanHo);
void thongKeSoCanHo(const vector<CanHo>& dsCanHo);
void thongKeSoLuongXe(const vector<CanHo>& dsCanHo);
void thongKeSoLuongDienNuoc(const vector<CanHo>& dsCanHo);
