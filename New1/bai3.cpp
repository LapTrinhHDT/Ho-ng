#include<iostream>
using namespace std;

typedef int Item;
class Day
{
protected:
	int ngay;
	int thang;
	int nam;
public:
	Day();
	Day(int ngay, int thang, int nam);
	Day(const Day& day);
	~Day();
	void NhapDay();
	void XuatDay();
};
Day::Day()
{
	ngay = 0;
	thang = 0;
	nam = 0;
}
Day::Day(int ngay, int thang, int nam)
{
	ngay = ngay;
	thang = thang;
	nam = nam;
}
Day::Day(const Day& day)
{
	*this = day;
}
Day::~Day()
{
}
void Day::NhapDay()
{
	char PhanChia;   //phan chia dung ki tu "/"
	cout << "\nnhap ngay, thang, nam sinh(dd/mm/yyyy)  ";
	cin >> ngay >> PhanChia >> thang >> PhanChia >> nam;
}
void Day::XuatDay()
{
	cout << ngay << "/" << thang << "/" << nam << endl;
}

class Nguoi : public Day
{
private:
	string Ma;
	string HoTen;
	int Tuoi;
	string GioiTinh;
	Day NgaySinh;
	string DiaChi;
	float Luong;
	float TienThuong;
public:
	//ham tao ham huy 
	Nguoi();
	Nguoi(string Ma, string HoTen, int Tuoi, string GioiTinh, Day NgaySinh, string DiaChi, float Luong, float TienThuong);
	~Nguoi();
	virtual void nhap();
	virtual void xuat();
	virtual void TinhLuong() = 0;
	float getLuong();
	float getTienThuong();
};
class NhanVienChinhThuc : public Nguoi
{
private:
	string ChucVu;
	int ThamNien;
	string BoPhan; //ke toan , desinger , CEO , chao hang , 
public:
	void nhap();
	void xuat();
	void TinhLuong();
};
class NhanVienBanThoiGian : public Nguoi
{
private:
	int SoGioLam;
	float SoLuongTheoGio;
public:
	void nhap();
	void xuat();
	void TinhLuong();
};
class NhanVienLamTheoSanPham : public Nguoi
{
private:
	int SoLuongHang;
	float GiaHang;
public:
	void nhap();
	void xuat();
	void TinhLuong();
};
class NhanVienThuViec : public Nguoi
{
private:
	Day NgayVaoLam;
	float LuongTheoGio;
public:
	void nhap();
	void xuat();
	void TinhLuong();
};
class Node {
public:
	Item data;
	Node* next;
};
class QuanLiNhanVien
{
private:
	Node* head;
	Node* tail;
	long size;
public:
	QuanLiNhanVien();//khhoi tao quan li nhan vien 

	~QuanLiNhanVien();

	Node* CreateNode(Item v);
	void ThemNhanVien(Item v);//hoi if vào class nao 		
	Item DemNhanVien();	// Count the number of students with low GPA (GPA < 4)
	void Duyet() const;//tim kiem nhan vien 
	void XoaNhanVien(unsigned string sid);
	void SapXepTen();
	void SapXepLuong();
	void HienThi();
	Item TimKiemTen(unsigned string sid);
	Item TimKiemMa(unsigned string sid);
	Item SuaNhanVien();
	Item SuaTen();
	Item SuaMa();
	Item SuaChuaVu();//tang chuc , giam chuc , duoi viec, thu viec  
	Item MaxLuong();//min
	void TongLuong();
	void TongNhanVien();
	void Docfile();
	void Ghifile();
	void Menu();
	void Giaodien();
}; 
int main()
{	
	QuanLiNhanVien a;
	a.Menu();
	return 0;
}