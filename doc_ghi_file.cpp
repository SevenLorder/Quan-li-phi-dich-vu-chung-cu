#include "thong_tin_cac_phi.h"
#include "thong_tin_can_ho.h"

void ghiFileCanHo(const vector<CanHo>& dsCanHo)
{
	ofstream fileOut("can_ho.txt", ios::out);
	if (!fileOut.is_open())
	{
		cout << "LOI";
		return;
	}
	for (int i = 0; i < dsCanHo.size(); i++)
	{
		fileOut << dsCanHo[i].maCanHo << ",";
		fileOut << dsCanHo[i].tenChuHo << ",";
		fileOut << dsCanHo[i].dienTich << ",";
		fileOut << dsCanHo[i].soNguoi << ",";
		fileOut << dsCanHo[i].soXe.first << "," << dsCanHo[i].soXe.second << ",";
		fileOut << dsCanHo[i].soDienNuoc.first << "," << dsCanHo[i].soDienNuoc.second << endl;
	}
	fileOut.close();
}
void docFileCanHo(vector<CanHo>& dsCanHo)
{
	ifstream fileIn("can_hp.txt");
	if (!fileIn.is_open())
	{
		cout << "LOI";
		return;
	}
	string line;
	while (getline(fileIn, line))
	{
		CanHo canHo;
		stringstream ss(line);
		getline(ss, canHo.maCanHo, ',');
		getline(ss, canHo.tenChuHo, ',');
		ss >> canHo.dienTich;
		ss.ignore();
		ss >> canHo.soNguoi;
		ss.ignore();
		ss >> canHo.soXe.first;
		ss.ignore();
		ss >> canHo.soXe.second;
		ss.ignore();
		ss >> canHo.soDienNuoc.first;
		ss.ignore();
		ss >> canHo.soDienNuoc.second;
		dsCanHo.push_back(canHo);
	}
	fileIn.close();
}

void ghiFileDichVu(const vector<DichVu>& dsDichVu)
{
	ofstream fileOut("can_ho.txt");
	if (!fileOut.is_open())
	{
		cout << "LOI";
		return;
	}
	for (int i = 0; i < dsDichVu.size(); i++)
	{
		fileOut << dsDichVu[i].tenDichVu << ",";
		fileOut << dsDichVu[i].giaDichVu << ",";
		fileOut << dsDichVu[i].tinhTheoDienTich << ",";
		fileOut << dsDichVu[i].tinhTheoSoNguoi << ",";
		fileOut << dsDichVu[i].tinhTheoSoXe << ",";
		fileOut << dsDichVu[i].tinhTheoSoDienNuoc << endl;
	}
	fileOut.close();
}
void docFileDichVu(vector<DichVu>& dsDichVu)
{
	ifstream fileIn("cac_phi.txt");
	if (!fileIn.is_open())
	{
		cout << "LOI";
		return;
	}
	string line;
	while (getline(fileIn, line))
	{
		DichVu dichVu;
		stringstream ss(line);
		getline(ss, dichVu.tenDichVu, ',');
		ss >> dichVu.giaDichVu;
		ss.ignore();
		ss >> dichVu.tinhTheoDienTich;
		ss.ignore();
		ss >> dichVu.tinhTheoSoNguoi;
		ss.ignore();
		ss >> dichVu.tinhTheoSoXe;
		ss.ignore();
		ss >> dichVu.tinhTheoSoDienNuoc;
		dsDichVu.push_back(dichVu);
	}
	fileIn.close();
}