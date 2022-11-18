#include "HangHoa.h"

HangHoa::HangHoa() {
	strMaHang = "";
	strTenHang = "";
	strNoiSanXuat = "";
	strMauSac = "";
	iGiaBan = 0;
	strNgayNhapKho = "";
	iSoLuong = 0;
}
string HangHoa::getMaHang() {
	return strMaHang;
}
void HangHoa::setMaHang(string strValue) {
	strMaHang = strValue;
}
string HangHoa::getTenHang() {
	return strTenHang;
}
void HangHoa::setTenHang(string strValue) {
	strTenHang = strValue;
}
string HangHoa::getNoiSanXuat() {
	return strNoiSanXuat;
}
void HangHoa::setNoiSanXuat(string strValue) {
	strNoiSanXuat = strValue;
}
string HangHoa::getMauSac() {
	return strMauSac;
}
void HangHoa::setMauSac(string strValue) {
	strMauSac = strValue;
}
int HangHoa::getGiaBan() {
	return iGiaBan;
}
void HangHoa::setGiaBan(int iValue) {
	iGiaBan = iValue;
}
string HangHoa::getNgayNhapKho() {
	return strNgayNhapKho;
}
void HangHoa::setNgayNhapKho(string strValue) {
	strNgayNhapKho = strValue;
}
int HangHoa::getSoLuong() {
	return iSoLuong;
};
void HangHoa::setSoLuong(int iValue) {
	iSoLuong = iValue;
}
ostream& operator << (ostream& os, HangHoa a) {
	os << a.strMaHang << " | " << a.strTenHang << " | " << a.strNoiSanXuat << " | " << a.strMauSac << " | " << a.iGiaBan << " | " << a.strNgayNhapKho << " | " << a.iSoLuong;
	return os;
}
istream& operator >>(istream& is, HangHoa& a) {
	is >> a.strMaHang;
	getline(is, a.strTenHang);
	is >> a.strNoiSanXuat >> a.strMauSac >> a.iGiaBan >> a.strNgayNhapKho >> a.iSoLuong;
	return is;
}
