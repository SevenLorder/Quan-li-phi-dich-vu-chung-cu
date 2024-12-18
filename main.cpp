#include "main.h"

int main()
{
	vector<TaiKhoan> dsTaiKhoan;
	docFileTaiKhoan(dsTaiKhoan);
	taiKhoanMenu(dsTaiKhoan);

	vector<CanHo> dsCanHo;
	docFileCanHo(dsCanHo);

	vector<DichVu> dsDichVu;
	docFileDichVu(dsDichVu);

	vector<HoaDon> dsHoaDon;
	docFileHoaDon(dsHoaDon, dsDichVu, dsCanHo);
	do {

		cout << "---------------------------------QUAN LI CHUNG CU---------------------------------" << endl;
		cout << "1. Thong tin cac can ho" << endl;
		cout << "2. Thong tin cac phi" << endl;
		cout << "3. Thong tin cac hoa don" << endl;
		cout << "4. Thong ke" << endl;
		cout << "5. Thoat" << endl;
		cout << "Chon chuc nang: ";
		string choice;
		getline(cin, choice);
		if (choice == "1") {
			system("cls");
			menuCanHo(dsCanHo);
		}
		else if (choice == "2") {
			system("cls");
			menuPhi(dsDichVu);
		}
		else if (choice == "3") {
			menuHoaDon(dsHoaDon, dsCanHo, dsDichVu);
		}
		else if (choice == "4") {
			system("cls");
			thongKe(dsHoaDon, dsCanHo);
		}
		else if (choice == "5") {
			return 0;
		}
		else{
			cout << "Chuc nang khong ton tai. Vui long chon lai!" << endl;
			system("pause");
		}
		//ghiFileHoaDon(dsHoaDon);
		system("cls");
	} while (true);
	return 0;
}