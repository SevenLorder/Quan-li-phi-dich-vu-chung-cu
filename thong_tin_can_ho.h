#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <regex>
#include <algorithm>
using namespace std;

struct CanHo {
	string maCanHo; // Cau truc: <so tang>.<so nha>
	string tenChuHo;
	int soNguoi;
	pair<int, int> soXe;
	int dienTich;
	pair<int, int> soDienNuoc;
};

void menuCanHo(vector<CanHo>& dsCanHo);
void themCanHo(vector<CanHo> &dsCanHo);
void suaThongTinCanHo(vector<CanHo> &dsCanHo);
void xoaCanHo(vector<CanHo> &dsCanHo);
void xemDanhSachCanHo(const vector<CanHo> &dsCanHo);
void xemChiTietCanHo(const vector<CanHo> &dsCanHo);
void timCanHo(const vector<CanHo>& dsCanHo);
int binarySearchCanHo(vector<CanHo>& dsCanHo);

