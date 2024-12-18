#include "doc_ghi_file.h"
#include <cstring>

void ghiFileCanHo(const vector<CanHo>& dsCanHo)
{
	ofstream fileOut("can_ho.csv", ios::out);
	if (!fileOut.is_open())
	{
		cout << "LOI";
		return;
	}
	fileOut << "Ma can ho,Ten chu ho,Dien tich,So nguoi,So xe may,So xe hoi,So dien,So nuoc" << endl;
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
	ifstream fileIn("can_ho.csv");
	if (!fileIn.is_open())
	{
		cout << "LOI";
		return;
	}
	string line;
	getline(fileIn, line);
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
	ofstream fileOut("cac_phi.csv");
	if (!fileOut.is_open())
	{
		cout << "LOI";
		return;
	}
	fileOut << "Ten dich vu,Gia dich vu,Tinh theo dien tich,Tinh theo so nguoi,Tinh theo so xe,Tinh theo so dien nuoc" << endl;
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
	ifstream fileIn("cac_phi.csv");
	if (!fileIn.is_open())
	{
		cout << "LOI";
		return;
	}
	string line;
	getline(fileIn, line);
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

void ghiFileHoaDon(const vector<HoaDon>& dsHoaDon)
{
	ofstream fileOut("hoa_don.csv");
	if (!fileOut.is_open())
	{
		cout << "LOI";
		return;
	}
	int tongTien = 0;
	fileOut << "Ma hoa don,Thoi gian,Ma can ho,Ten chu ho,[Ten phi:Tien],Tong tien,Tinh trang thanh toan" << endl;
	for (int i = 0; i < dsHoaDon.size(); i++)
	{
		fileOut << dsHoaDon[i].canHo.maCanHo << "-" << dsHoaDon[i].thang << "-" << dsHoaDon[i].nam << ",";
		fileOut << dsHoaDon[i].thang << "/" << dsHoaDon[i].nam << ",";
		fileOut << dsHoaDon[i].canHo.maCanHo << ",";
		fileOut << dsHoaDon[i].canHo.tenChuHo << ",";
		fileOut << "[";  
		for (int j = 0; j < dsHoaDon[i].chiTietPhi.size(); j++)
		{
			if (j == dsHoaDon[i].chiTietPhi.size() - 1)  
			{
				fileOut << dsHoaDon[i].tienTungPhi[j].first.tenDichVu << ":" << dsHoaDon[i].tienTungPhi[j].second << "],";
			}
			else {
				fileOut << dsHoaDon[i].tienTungPhi[j].first.tenDichVu << ":" << dsHoaDon[i].tienTungPhi[j].second << ";";
			}
		}
		fileOut << dsHoaDon[i].tongTien << ",";
		fileOut << dsHoaDon[i].thanhToan << endl;
	}

	fileOut.close();
}

void docFileHoaDon(vector<HoaDon>& dsHoaDon, const vector<DichVu>& dsPhi, const vector<CanHo>& dsCanHo)
{
	ifstream fileIn("hoa_don.csv");
	if (!fileIn.is_open())
	{
		cout << "LOI";
		return;
	}
	string line;
	getline(fileIn, line);
	while (getline(fileIn, line))
	{
		HoaDon hoaDon;
		stringstream ss(line);
		string s;
		getline(ss, hoaDon.maHoaDon, ','); // ma hoa don
		getline(ss, s, '/'); // thang
		hoaDon.thang = stoi(s);
		getline(ss, s, ','); // nam
		hoaDon.nam = stoi(s);
		string maCanHo;
		getline(ss, maCanHo, ','); // ma can ho
		int canHoIndex = binarySearch(dsCanHo, &CanHo::maCanHo, maCanHo);
		hoaDon.canHo = dsCanHo[canHoIndex];

		getline(ss, s, '['); // nguyen dong chi tiet phi [ ... ]
		getline(ss, s, ']');
		stringstream dongPhi(s);
		while (getline(dongPhi, s, ';'))
		{
			string tenPhi;
			string tien;
			stringstream tungPhi(s);
			getline(tungPhi, tenPhi, ':');
			getline(tungPhi, tien);

			int phiIndex = binarySearch(dsPhi, &DichVu::tenDichVu, tenPhi);
			if (phiIndex != -1)
			{
				hoaDon.tienTungPhi.push_back(make_pair(dsPhi[phiIndex], stoi(tien)));
				hoaDon.chiTietPhi.push_back(dsPhi[phiIndex]);
			}
		}
		getline(ss, s, ','); // dau , sau ]
		getline(ss, s, ','); // tong tien
		hoaDon.tongTien = stoi(s);
		getline(ss, hoaDon.thanhToan); // tinh trang thanh toan
		dsHoaDon.push_back(hoaDon);
	}
	fileIn.close();
}

void ghiFileTaiKhoan(const vector<TaiKhoan>& dsTaiKhoan)
{
	ofstream fileOut("tai_khoan.csv");
	if (!fileOut.is_open())
	{
		cout << "LOI";
		return;
	}
	fileOut << "Ten tai khoan,Mat khau" << endl;
	for (int i = 0; i < dsTaiKhoan.size(); i++)
	{
		fileOut << dsTaiKhoan[i].tenTaiKhoan << ",";
		fileOut << dsTaiKhoan[i].matKhau << endl;
	}
	fileOut.close();
}
void docFileTaiKhoan(vector<TaiKhoan>& dsTaiKhoan)
{
	ifstream fileIn("tai_khoan.csv");
	if (!fileIn.is_open())
	{
		cout << "LOI";
		return;
	}
	string line;
	getline(fileIn, line);
	while (getline(fileIn, line))
	{
		TaiKhoan taiKhoan;
		stringstream ss(line);
		getline(ss, taiKhoan.tenTaiKhoan, ',');
		getline(ss, taiKhoan.matKhau, ',');
		dsTaiKhoan.push_back(taiKhoan);
	}
	fileIn.close();
}