#include "main.h"

int main()
{
	vector<CanHo> dsCanHo;
	docFileCanHo(dsCanHo);
	vector<DichVu> dsDichVu;
	docFileDichVu(dsDichVu);
	do {

		cout << "---------------------------------Quan li chung cu---------------------------------" << endl;
		cout << "1. Thong tin cac can ho" << endl;
		cout << "2. Thong tin cac phi" << endl;
		cout << "3. Thong tin cac hoa don" << endl;
		cout << "4. Thoat" << endl;
		cout << "Chon chuc nang: ";
		int choice;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			menuCanHo(dsCanHo);
			break;
		case 2:
			menuPhi(dsDichVu);
			break;
		case 4:
			return 0;
		}
	} while (true);
	return 0;
}