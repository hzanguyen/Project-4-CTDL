#ifndef __HANGHOA_H__ 
#define __HANGHOA_H__
#include <iostream>
#include <string>

using namespace std;

class HangHoa
{
	string strMaHang;
	string strTenHang;
	string strNoiSanXuat;
	string strMauSac;
	double dGiaBan;
	string strNgayNhapKho;
	int iSoLuong;
public:
	string getMaHang();
	void setTenHang(string strValue);
	string getTenHang();
	void setTenHang(string strValue);
	string getNoiSanXuat();
	void setNoiSanXuat(string strValue);
	string getMauSac();
	void setMauSac(string strValue);
	double getGiaBan();
	void setGiaBan(double dValue);
	string getNgayNhapKho();
	void setNgayNhapKho(string strValue);
	int getSoLuong();
	void setSoLuong(int iValue);
	friend istream& operator >>(istream& is, HangHoa& a);
	friend ostream& operator <<(ostream& os, HangHoa a);
};
#endif // !1

