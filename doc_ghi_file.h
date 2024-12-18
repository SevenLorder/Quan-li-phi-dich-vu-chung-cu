#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <regex>
#include "thong_tin_can_ho.h"
#include "thong_tin_cac_phi.h"
#include "thong_tin_hoa_don.h"
#include "tai_khoan.h"
using namespace std;

void ghiFileCanHo(const vector<CanHo>& dsCanHo);
void docFileCanHo(vector<CanHo>& dsCanHo);
void ghiFileDichVu(const vector<DichVu>& dsDichVu);
void docFileDichVu(vector<DichVu>& dsDichVu);

void ghiFileHoaDon(const vector<HoaDon> &dsHoaDon);
void docFileHoaDon(vector<HoaDon> &dsHoaDon, const vector<DichVu>& dsPhi, const vector<CanHo>& dsCanHo);

void ghiFileTaiKhoan(const vector<TaiKhoan>& dsTaiKhoan);
void docFileTaiKhoan(vector<TaiKhoan>& dsTaiKhoan);

template <typename array, typename key, typename object>
int binarySearch(const array& arr, const object& obj, const key& k) {
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid].*obj == k) {
			return mid;
		}
		if (arr[mid].*obj < k) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}
