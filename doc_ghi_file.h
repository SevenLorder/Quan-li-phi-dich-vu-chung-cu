#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "thong_tin_can_ho.h"
#include "thong_tin_cac_phi.h"
using namespace std;

void ghiFileCanHo(const vector<CanHo>& dsCanHo);
void docFileCanHo(vector<CanHo>& dsCanHo);
void ghiFileDichVu(const vector<DichVu>& dsDichVu);
void docFileDichVu(vector<DichVu>& dsDichVu);