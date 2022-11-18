#include "DanhSachHangHoa.h"
#include "HangHoa.h"
DanhSachHangHoa::DanhSachHangHoa() {
	_pHead = NULL;
	_pTail = NULL;
	iSoLuong = 0;
};
void DanhSachHangHoa::AddTail(HangHoa a) {
	Node* pAdd = new Node(a);
	if (_pTail == NULL) {
		_pHead = _pTail = pAdd;
	}
	else {
		_pTail->_pNext = pAdd;
		_pTail = pAdd;
	}
	iSoLuong++;
};
void DanhSachHangHoa::Nhap()
{
	ifstream input("C:\\Users\\HP\\Desktop\\Project7\\Project7\\HangHoa.txt");
	HangHoa a;
	while (!input.eof()) {
		string MaH, TenH, NSX, MauS, NgayNhapK;
		string Gia;
		string sl;
		getline(input, MaH);
		a.setMaHang(MaH);
		getline(input, TenH);
		a.setTenHang(TenH);
		getline(input, NSX);
		a.setNoiSanXuat(NSX);
		getline(input, MauS);
		a.setMauSac(MauS);
		getline(input, Gia);
		int gia = stoi(Gia);
		a.setGiaBan(gia);
		getline(input, NgayNhapK);
		a.setNgayNhapKho(NgayNhapK);
		getline(input, sl);
		int SL = stoi(sl);
		a.setSoLuong(SL);
		AddTail(a);
	}
};
void DanhSachHangHoa::ThemHH() {
	HangHoa a;
	cout << "Vui long nhap cac thong tin cua hang hoa:"<<endl;
	cin >> a;
	if (!IsInHangHoa(a.getMaHang())) {
		AddTail(a);
	};
}
void DanhSachHangHoa::PrintFind(string x) {
	Node* pTemp = _pHead;
	while (pTemp != NULL) {
		if (pTemp->data.getTenHang() == x)
		{
			cout << pTemp->data;
			return;
		}
		pTemp = pTemp->_pNext;
	}
	cout << "Khong co hang hoa co ten vua nhap";
}
void DanhSachHangHoa::Xuat() {
	cout << "Ma Hang | Ten Hang | Noi san xuat | Mau sac | Gia ban | Ngay nhap kho | So luong" << endl;
	Node* pTemp = _pHead;
	while (pTemp != NULL) {
		cout << pTemp->data << endl;
		pTemp = pTemp->_pNext;
	};
};
bool DanhSachHangHoa::IsInHangHoa(string x) {
	Node* pTemp = _pHead;
	while (pTemp != NULL) {
		if (pTemp->data.getMaHang() == x)
			return true;
		pTemp = pTemp->_pNext;
	};
	return false;
}
void DanhSachHangHoa::Xoa(string x) {
	if (_pHead->data.getMaHang() == x) {
		Node* pTemp = _pHead;
		_pHead = _pHead->_pNext;
		iSoLuong--;
	}
	else {
		Node* pWalker = _pHead;
		Node* pTemp = NULL;
		while (pWalker != NULL && pWalker->data.getMaHang() != x) {
			pTemp = pWalker;
			pWalker = pWalker->_pNext;
		}
		if (pWalker == NULL)
			return;
		if (pTemp != NULL) {
			if (pWalker == _pTail) {
				_pTail = pTemp;
				_pTail->_pNext = NULL;
			}
			pTemp->_pNext = pWalker->_pNext;
			delete pWalker;
			iSoLuong--;
		}
	}
};
void DanhSachHangHoa::CapNhatSoLuong(string x, int sl) {
	Node* pTemp = _pHead;
	while (pTemp != NULL) {
		if (pTemp->data.getMaHang() == x) {
			pTemp->data.setSoLuong(sl);
			return;
		}
		pTemp = pTemp->_pNext;
	}
}
