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
	cout << "(dd/mm/yyyy):  ";
	cin >> ngay >> PhanChia >> thang >> PhanChia >> nam;
}

void Day::XuatDay()
{
	cout << ngay << "/" << thang << "/" << nam << endl;
}


			//XAY DUNG LOP NGUOI
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
	Nguoi(string Ma, string HoTen, int Tuoi, string GioiTinh, string DiaChi, float Luong, float TienThuong);
	Nguoi(const Nguoi &nguoi);
	~Nguoi();
	virtual void Nhap();
	virtual void Xuat();
	virtual void TinhLuong() = 0;
	float getLuong();
	float getTienThuong();
};

Nguoi::Nguoi()
{
	this->Ma = "";
	this->HoTen = "";
	this->Tuoi = 0;
	this->GioiTinh = "";
	this->DiaChi = "";
	this->Luong = 0;
	this->TienThuong = 0;
}

Nguoi::Nguoi(string Ma, string HoTen, int Tuoi, string GioiTinh, string DiaChi, float Luong, float TienThuong)
{
	this->Ma = Ma;
	this->HoTen = HoTen;
	this->Tuoi = Tuoi;
	this->GioiTinh = GioiTinh;
	this->DiaChi = DiaChi;
	this->Luong = Luong;
	this->TienThuong = TienThuong;
}

Nguoi::Nguoi(const Nguoi&nguoi)
{
	*this = nguoi;
}

Nguoi::~Nguoi()
{	
}

void Nguoi::Nhap()
{
	cout<<"\tNhap Vao Ma So Nhan Vien: ";
	fflush(stdin);
	getline(cin,Ma);
	cout<<"\tNhap Ho Va Ten (Day Du): ";
	fflush(stdin);
	getline(cin,HoTen);
	cout<<"\tNhap So Tuoi: ";
	cin >> Tuoi;
	cout<<"\tNhap Ngay Sinh  ";
	NgaySinh.NhapDay();
	cout<<"\tNhap Gioi Tinh: ";
	fflush(stdin);
	getline(cin,GioiTinh);
	cout<<"\tNhap Dia Chi: ";
	fflush(stdin);
	getline(cin,DiaChi);
}

void Nguoi::Xuat()
{
	cout<<"\tMa So Nhan Vien La: "<<Ma<<endl;
	cout<<"\tHo Ten Cua Nhan Vien La: "<<HoTen<<endl;
	cout<<"\tSo Tuoi La:"<<Tuoi<<endl;
	cout<<"\tNgay Sinh: ";
	NgaySinh.XuatDay();
	cout<<"\tGioi Tinh :"<<GioiTinh<<endl;
	cout<<"\tDia Chi: "<<DiaChi<<endl;
}

float Nguoi::getLuong()
{
	return Luong;
}
float Nguoi::getTienThuong()
{
	return TienThuong;
}

		//THONG TIN NHAN VIEN
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

void NhanVienChinhThuc::nhap()
{
	Nguoi::Nhap();
	cout<<"\tNhap Chuc vu cua nhan vien la: ";
	fflush(stdin);
	getline(cin, ChucVu);
	cout<<"\tnhap vao tham nien: ";
	cin>> ThamNien;
	cout<<"nhap Vao bo Phan viec lam: ";
	fflush(stdin);
	getline(cin, BoPhan);
}
void NhanVienChinhThuc::xuat()
{
	Nguoi::Xuat();
	cout<<"\tChuc Vu cua nhan vien : "<<ChucVu<<endl;
	cout<<"\tTham Nien : "<<ThamNien<<endl;
	cout<<"\tBo Phan Lam Viec La: "<<BoPhan<<endl;
}


void NhanVienChinhThuc::TinhLuong()
{
	
}


class NhanVienBanThoiGian : public Nguoi
{
private:
	int SoGioLam;
	float SoLuongTheoGio;
public:
	void Nhap();
	void Xuat();
	void TinhLuong();
};

void NhanVienBanThoiGian::Nhap()
{
	Nguoi::Nhap();
	cout<<"\tNhap So Gio Lam : ";
	cin>>SoGioLam;
	cout<<"\tNhap So Luong Theo Gio: ";
	cin>> SoLuongTheoGio;
}

void NhanVienBanThoiGian::Xuat()
{
	Nguoi::Xuat();
	cout<<"\tSo Gio Lam la: "<<SoGioLam<<endl;
	cout<<"\tSo luong Theo Gio La: "<<SoLuongTheoGio<<endl;
}


class NhanVienLamTheoSanPham : public Nguoi
{
private:
	int SoLuongHang;
	float GiaHang;
public:
	void Nhap();
	void Xuat();
	void TinhLuong();
};

void NhanVienLamTheoSanPham::Nhap()
{
	Nguoi::Nhap();
	cout<<"\tNhap So Luong Hang Hoa: ";
	cin>>SoLuongHang;
	cout<<"\tNhap Vao Gia Hang: ";
	cin>>GiaHang;
}

void NhanVienLamTheoSanPham::Xuat()
{
	Nguoi::Xuat();
	cout<<"\tSo Luong Hang Hoa: "<<SoLuongHang<<endl;
	cout<<"\tVao Gia Hang: "<<GiaHang<<endl;
}


class NhanVienThuViec : public Nguoi
{
private:
	Day NgayVaoLam;
	float LuongTheoGio;
public:
	void Nhap();
	void Xuat();
	void TinhLuong();
}; 

void NhanVienThuViec::Nhap()
{
	cout<<"\tNhap thoi gian vao lam ";
	NgayVaoLam.NhapDay();
	cout<<"\tNhap vao muc luong theo gio: ";
	cin>>LuongTheoGio;	
}	

void NhanVienThuViec::Xuat()
{
	cout<<"\tNgay vao lam la: ";
	NgayVaoLam.XuatDay();
	cout<<"\tMuc Luong Theo Gio La: "<<LuongTheoGio<<endl;
}

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
	void NhapDS();
	void XuatDS();
	void ThemNhanVien(Item v);//hoi if vào class nao 		
	Item DemNhanVien();	// Count the number of students with low GPA (GPA < 4)
	void Duyet() const;//tim kiem nhan vien 
	void XoaNhanVien();
	void SapXepTen();
	void SapXepLuong();
	void HienThi();
	Item TimKiemTen();
	Item TimKiemMa();
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

QuanLiNhanVien::QuanLiNhanVien()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

QuanLiNhanVien::~QuanLiNhanVien()
{
	delete head;
	delete tail;
	size = 0;
}

Node *QuanLiNhanVien::CreateNode(Item v)
{
	Node *p = CreateNode(v);
	p->data = v;
	p->next = NULL;
	return p;
}
void QuanLiNhanVien::NhapDS()
{
	
	int n;
	cout<<"\tNhap so luong nhan vien chinh thuc: ";
	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		Node *p = new createNode (v)
		nguoi->Nhap();
		nguoi->next = head;
   		head = p;
    	if (size == 0)
        	tail = p;
        cout<<endl;
    	size++;
	}
}




int main()
{	
	QuanLiNhanVien a;
	a.NhapDS();
}