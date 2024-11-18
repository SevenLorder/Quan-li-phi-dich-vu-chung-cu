#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct CanHo {
	string maCanHo;
	string tenChuHo;
	int soNguoi;
	pair<int, int> soXe;
	double dienTich;
	pair<int, int> soDienNuoc;
};

void menuCanHo(vector<CanHo>& dsCanHo);
void themCanHo(vector<CanHo> &dsCanHo);
void suaThongTinCanHo(vector<CanHo> &dsCanHo);
void xoaCanHo(vector<CanHo> &dsCanHo);
void xemDanhSachCanHo(const vector<CanHo> &dsCanHo);

