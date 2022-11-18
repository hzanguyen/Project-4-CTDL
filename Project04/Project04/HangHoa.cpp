#include "HangHoa.h"

HangHoa::HangHoa() {

}
string HangHoa::getMaHang() {
	return strMaHang;
}
void HangHoa::setTenHang(string strValue) {
	strTenHang = strValue;
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
double HangHoa::getGiaBan() {
	return dGiaBan;
}
void HangHoa::setGiaBan(double dValue) {
	dGiaBan = dValue;
}
string HangHoa::getNgayNhapKho() {
	return strNgayNhapKho;
}
void HangHoa::setNgayNhapKho(string strValue) {
	strNgayNhapKho = strValue;
}
int HangHoa::getSoLuong() {
	return iSoLuong;
}
void HangHoa::setSoLuong(int iValue) {
	iSoLuong = iValue;
}
ostream& operator << (ostream& os, HangHoa a) {
	os << a.strMaHang<<" | "<<a.strTenHang <<" | "<<a.strNoiSanXuat<<" | "<<a.strMauSac<<" | "<<a.dGiaBan<<" | "<<a.strNgayNhapKho<<" | "<<a.iSoLuong;
}
istream& operator >>(istream& is, HangHoa& a) {
	is >> a.strMaHang >> a.strTenHang >> a.strNoiSanXuat >> a.strMauSac >> a.dGiaBan >> a.strNgayNhapKho >> a.iSoLuong;
}
