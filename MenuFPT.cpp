#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#define TIENVAY 500000000
#define THOIHANVAY 24 // NAM
#define LAISUAT 0.006 // NAM
#define LAITHANG 0.05
struct SinhVien {
	char ten[100];
	float diem;
};
void DoiTien() {
	int x;
	cout << "\nNhap vao so tien can doi: "; cin >> x;
	int loaitien[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
	int soto;
	for (int i = 0; i < 9; i++) {
		soto = x / loaitien[i];
		if (soto != 0) {
			cout << soto << " to " << loaitien[i] << "\n";
		}
		x = x % loaitien[i];
	}
}
void FPOLYLOTT() {
	int a, b;
	cout << "Nhap 2 so a, b: ";
	cin >> a >> b;
	srand(time(NULL));
	int res = rand() % (14 + 1) + 1;
	cout << "So may man: " << res;
	if (a == res && b == res) cout << "\nChuc mung ban da trung giai nhat";
	else if (a == res || b == res) cout << "\nChuc mung ban da trung giai nhi";
	else if (a != res && b != res) cout << "\nChuc ban may man lan sau";
}
void TinhTien() {
	int t1, m1, t2, m2, t, m;
	do {
		cout << "\nNhap gio vao: ";
		cin >> t1 >> m1;
		if (t1 < 12 || t1 > 23) cout << "\nQuan chi hoat dong tu 12h -> 23h";
	} while (t1 < 12 || t1 > 23);
	do {
		cout << "\nNhap gio ra: ";
		cin >> t2 >> m2;
		if (t1 < 12 || t1 > 23) cout << "\nQuan chi hoat dong tu 12h -> 23h";
	} while (t1 < 12 || t1 > 23);
	t = t2 - t1; m = m2 - m1;
	if (m < 0) {
		m = 60 - abs(m);
		t = t - 1;
	}
	cout << t << "h : " << m<<"p";
	double tien = 0;
	for (int i = 1; i <= t; i++) {
		if(i < 4) tien += 150000;
		if(i >= 4) tien += 150000 * 0.7;
	}
	if (t1 >= 14 && t1 <= 17) tien = tien * 0.9;
	cout << "\nSo tien phai tra la: " << tien;
}
int KiemTraNguyenTo(int n) {
	if (n < 2) return 0;
	else if (n > 2) {
		if (n % 2 == 0) return 0;
		for (int i = 3; i < n / 2; i += 2) {
			if (n % i == 0) return 0;
		}
	}
	return 1;
}
void KiemTraSoNguyen(int n) {
	if (KiemTraNguyenTo(n))
		cout << n << " la so nguyen to\n";
	if (n == int(n))
		cout << n << " la so nguyen\n";
	if (sqrt(n) * sqrt(n) == n)
		cout << n << " la so chinh phuong\n";
}
void KTSN() {
	int n;
	cout << "Nhap n: "; cin >> n;
	KiemTraSoNguyen(n);
}
void Menu() {
	cout << "\n----- Chon chuc nang -----\n";
	cout << "\n<<----- 1. Kiem tra so nguyen -----\n";
	cout << "\n<<----- 2. Uoc so chung va boi so chung cua 2 so -----\n";
	cout << "\n<<----- 3. Tinh tien cho quan Karaoke -----\n";
	cout << "\n<<----- 4. Tinh tien dien -----\n";
	cout << "\n<<----- 5. Doi tien -----\n";
	cout << "\n<<----- 6. Tinh lai suat ngan hang vay tra gop -----\n";
	cout << "\n<<----- 7. Chuong trinh vay tien mua xe -----\n";
	cout << "\n<<----- 8. Sap xep thong tin sinh vien -----\n";
	cout << "\n<<----- 9. Game FPOLY - LOTT (2/15) -----\n";
	cout << "\n<<----- 10.Tinh toan phan so -----\n";
}
void MuaXe() {
	int x;
	cout << "\nNhap % vay toi da: "; cin >> x;
	cout << "Thang " << "\t" << "So tien phai tra \n";
	long int tienvay = TIENVAY * x;
	long int gocphaitra = tienvay / 288;
	for (int i = 1; i <= 288; i++) {
		long int laiphaitra = tienvay * LAISUAT;
		long int sotienphaitra = gocphaitra + laiphaitra;
		cout << i << "\t" << sotienphaitra << "\n";
		tienvay -= gocphaitra;
	}
}
void Nhap(SinhVien sv[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap sinh vien thu " << i + 1 << "\n";
		fflush(stdin);
		cout << "Ho ten: "; cin >> sv[i].ten;
		cout << "Diem: "; cin >> sv[i].diem;
	}
}
void HocLuc(SinhVien sv) {
	float diem = sv.diem;
	if (diem >= 9) cout << "Xuat sac";
	else if (diem >= 8) cout << "Gioi";
	else if (diem >= 6.5) cout << "Kha";
	else if (diem >= 5.0) cout << "Trung binh";
	else if (diem < 5) cout << "Yeu";
}
void Xuat(SinhVien sv[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nSinh vien thu " << i + 1;
		cout << " -- Ho ten: " << sv[i].ten;
		cout << " || Diem: " << sv[i].diem;
		cout << " || Xep loai hoc luc: ";
		HocLuc(sv[i]);
	}
}
void SapXepGiamDan(SinhVien sv[], int n) {
	cout << "\nSap xep sinh vien giam dan theo diem -- ";
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sv[i].diem < sv[j].diem) {
				SinhVien t;
				t = sv[i];
				sv[i] = sv[j];
				sv[j] = t;
			}
		}
	}
}
void SV() {
	SinhVien sv[100]; int n;
	cout << "Nhap so luong sv: "; cin >> n;
	Nhap(sv, n);
	Xuat(sv, n);
	SapXepGiamDan(sv, n);
	Xuat(sv, n);
}
void TinhTienDien() {
	double tien;
	int x;
	cout << "\nNhap vao so (kwh) dien su dung: ";
	cin >> x;
	if (x >= 0 && x <= 50) {
		tien = 1.678 * x;
	}
	if (x > 50 && x <= 100) {
		tien = 1.734 * x;
	}
	if (x > 100 && x <= 200) {
		tien = 2.014 * x;
	}
	if (x > 200 && x <= 300) {
		tien = 2.536 * x;
	}
	if (x > 300 && x <= 400) {
		tien = 2.834 * x;
	}
	if (x > 400) {
		tien = 2.927 * x;
	}
	cout << "\nSo tien dien phai tra la: " << tien;
}
int UCLN(int a, int b) {
	while (a != b) {
		if (a > b) a = a - b;
		else b = b - a;
	}
	return a;
}
void XuatUCBC(int a, int b) {
	cout << "\nUCLN: " << UCLN(a, b);
	cout << "\nBCNN: " << a * b / UCLN(a, b);
}
void UCBC() {
	int a, b;
	cout << "Nhap a: "; cin >> a;
	cout << "Nhap b: "; cin >> b;
	XuatUCBC(a, b);
}
void LaiSuat() {
	long int x;
	cout << "\nNhap so tien muon vay: "; cin >> x;
	long int gocphaitra = x / 12;
	cout << setw(5) << "\nKi han " << setw(10) << " Lai phai tra " << setw(5) << " Goc phai tra " << setw(5) << " So tien phai tra " << setw(5) << " So tien con lai " << setw(5) << "\n\n";
	for (int i = 1; i <= 12; i++) {
		long int laiphaitra = x * LAITHANG;
		long int sotienphaitra = gocphaitra + laiphaitra;
		cout <<"  "<< i << "\t" << laiphaitra << "\t\t" << gocphaitra << "\t\t" << sotienphaitra << "\t\t" << x - gocphaitra << "\n";
		x = x - gocphaitra;
	}
}
int main() {
	Menu(); int x; cout << "\nChon chuc nang: "; cin >> x;
	system("cls");
	if (x == 1) KTSN();
	if (x == 2) UCBC();
	if (x == 3) TinhTien();
	if (x == 4) TinhTienDien();
	if (x == 5) DoiTien();
	if (x == 6) LaiSuat();
	if (x == 7) MuaXe();
	if (x == 8) SV();
	if (x == 9) FPOLYLOTT();
	if (x == 10) cout << "\nNhac qua eo lam ok?\n";
	cout << "\n"; system("pause");
}
