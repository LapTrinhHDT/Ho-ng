#include<iostream>
using namespace std;

class DayOfBirth{
	protected:
		int day;
		int month;
		int year;
	public:
		DayOfBirth();
		DayOfBirth(int day, int month, int year);
		DayOfBirth(const DayOfBirth &ngay);
		~DayOfBirth();
		void NhapNgay();
		void XuatNgay();
};
DayOfBirth::DayOfBirth(){
	day=0;
	month=0;
	year=0;
}
DayOfBirth::DayOfBirth(int day, int month, int year){
	day = day;
	month = month;
	year = year
}
DayOfBirth::DayOfBirth(const DayOfBirth &ngay){
	*this = ngay;
}
DayOfBirth::~DayOfBirth(){
}
void DayOfBirth::NhapNgay(){
    char PhanChia;   //phan chia dung ki tu "/"
    cout<<"\nnhap ngay, thang, nam sinh(dd/mm/yyyy)  ";
    cin>>day>>PhanChia>>month>>PhanChia>>year;
}
void DayOfBirth::XuatNgay(){
	cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}


class Nguoi : public DayOfBirth{
	private:	
		string Name;
		int age;
		string sex;
		DayOfBirth ns;
		
		
		
	public:
			 
}; 
class NhanVien{
	
};
class ThuKi{
	
};
class CapQuanTri{
	
};
