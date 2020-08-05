#include <iostream>
#include <string>
#include"Sach.h"
#include"PhieuMuon.h"
#include"TaiKhoan.h"
#include"ThanhVien.h"

using namespace std;

void giaoDien() {
	TaiKhoan taiKhoan;
	taiKhoan.dangNhap();
	if (taiKhoan.getCheck()) {
		cout << "\nDang nhap thanh cong\n";
		string choice2 = "y";
		while (choice2 == "y") {
			//Khoi tao Menu:
			cout << "\nMoi ban dung chon chuc nang : \n";
			cout << "1 - Lap phieu muon \n";
			cout << "2 - Lap phieu tra \n";
			cout << "3 - Quan ly thong tin sach trong thu vien\n";
			cout << "4 - Quan ly thong tin thanh vien\n";

			int chon;
			cout << "Chon : ";
			cin >> chon;
			switch (chon) 
			{
				case 1: {
					cout << "\nChuc nang '1 - Lap phieu muon' duoc chon \n"; 
					int mssv, maSach;
					int tonTai;
					cout << "\nMoi nhap MSSV muon sach : ";
					cin >> mssv;
					ThanhVien thanhVien;
					thanhVien.setMssv(mssv);
					thanhVien.getThanhVien();
					if (!thanhVien.getCheckMssv()) {
						cout << "\nThanh vien co MSSV " << mssv << " khong ton tai!";
						break;
					}
					int dsMa[50];
					int countMa = 0;
					Sach sach;
					cout << "\nMoi nhap ma sach : ";
					cin >> maSach;
					sach.setMaSach(maSach);
					sach.ktraMaSach("DanhMucSach");
					if (sach.getCheckMaSach()) {
						dsMa[countMa++] = maSach;
					}
					else
					{
						cout << "\nMa sach khong ton tai!\n";
					}
					//dsMa[countMa++] = maSach;
					string choiceAdd = "";
					cout << "\nBan muon them sach vao phieu muon? (y/n) :\n";
					cout << "Chon : ";
					cin >> choiceAdd;
					while (choiceAdd == "y") {
						cout << "\nMoi nhap ma sach : ";
						cin >> maSach;
						sach.setMaSach(maSach);
						sach.ktraMaSach("DanhMucSach");
						if (sach.getCheckMaSach()) {
							tonTai = 0;
							for (int j = 0; j < countMa; j++) {
								if (maSach == dsMa[j]) {
									tonTai = 1;
									break;
								}
							}
							if (tonTai) {
								cout << "Ma sach da chon ben tren";
							}
							else
							{
								dsMa[countMa++] = maSach;
							}
						}
						else
						{
							cout << "\nMa sach khong ton tai!\n";
						}
						cout << "\nBan muon them sach vao phieu muon? (y/n) :\n";
						cout << "Chon : ";
						cin >> choiceAdd;
					}
					string confirm = "";
					cout << "\nXac nhan muon cac ma sach: ";
					for (int j = 0; j < countMa; j++) {
						if (j == countMa - 1) {
							cout << dsMa[j];
						}
						else
						{
							cout << dsMa[j] << ", ";
						}

					}
					cout << "\nChon (y/n) : ";
					cin >> confirm;
					if (confirm == "y") {
						PhieuMuon phieu;
						phieu.setMssv(mssv);
						for (int j = 0; j < countMa; j++) {
							sach.setMaSach(dsMa[j]);
							sach.muonSach();
						}
						phieu.taoPhieuMuon(dsMa,countMa);
					}
					break;
				}

				case 2: {
					cout << "\nChuc nang '2 - Lap phieu tra' duoc chon \n";
					int maMuon;
					cout << "\nMoi nhap ma phieu muon : ";
					cin >> maMuon;
					PhieuMuon phieu;
					phieu.setMaMuon(maMuon);
					phieu.ktraMaPhieu();
					if (phieu.getCheckMaPhieu()) {
						phieu.taoPhieuTra();
					}
					else
					{
						cout << "\nMa phieu muon khong ton tai!";
					}
					break;
				}

				case 3: {			
					string choiceTV = "y";
					while (choiceTV == "y") {
						int chonTV, maSach;
						string ten, tacGia, nhaXB, namXB;
						cout << "\n3 - Quan ly thong tin sach trong thu vien\n";
						cout << "\nMoi chon chuc nang tuong ung:\n";
						cout << "1 - Xem danh muc sach\n";
						cout << "2 - Tim kiem sach trong thu vien\n";
						cout << "3 - Them sach vao thu vien\n";
						cout << "4 - Sua sach trong thu vien\n";
						cout << "5 - Xoa sach trong thu vien\n";
						cout << "Chon: ";
						cin >> chonTV;
						switch (chonTV) {
							case 1: {
								cout << "\n3.1 - Xem danh muc sach duoc chon\n";
								Sach sach;
								sach.danhMucSach();
								break;
							}
							case 2: {
								Sach sach;
								cout << "\n3.2 - Tim kiem sach trong thu vien duoc chon\n";
								cout << "\nNhap ma sach: ";
								cin >> maSach;
								sach.setMaSach(maSach);
								sach.ktraMaSach("ThuVien");
								if (!sach.getCheckMaSach()) {
									cout << "\nSach co ma sach " << maSach << " khong ton tai trong thu vien!";
									break;
								}
								else
								{
									cout << "\nMa sach: " << sach.getMaSach();
									cout << "\nTen sach: " << sach.getTenSach();
									cout << "\nTac gia: " << sach.getTacGia();
									cout << "\nNha xuat ban: " << sach.getNhaXB();
									cout << "\nNam xuat ban: " << sach.getNamXB();
								}
								break;
							}						
							case 3: {
								Sach sach;
								cout << "\n3.3 - Them sach vao thu vien duoc chon\n";
								cout << "\nNhap ma sach: ";
								cin >> maSach;
								//fflush(stdin);
								sach.setMaSach(maSach);
								sach.ktraMaSach("ThuVien");
								if (sach.getCheckMaSach()) {
									cout << "\nSach co ma sach " << maSach << " da ton tai trong thu vien!";
									break;
								}
								else
								{
									cin.ignore();
									cout << "Ten sach: ";
									getline(cin, ten, '\n');
									cout << "Tac gia: ";
									getline(cin, tacGia, '\n');
									cout << "Nha xuat ban: ";
									getline(cin, nhaXB, '\n');
									cout << "Nam xuat ban: ";
									cin >> namXB;

									cout << "\nXac nhan thong tin them sach: ";
									cout << "\nMa sach: " << maSach;
									cout << "\nTen sach: " << ten;
									cout << "\nTac gia: " << tacGia;
									cout << "\nNha xuat ban: " << nhaXB;
									cout << "\nNam xuat ban: " << namXB;
									string confirmThem = "";
									cout << "\nChon (y/n): ";
									cin >> confirmThem;
									if (confirmThem == "y") {
										Sach sach(maSach, ten, tacGia, nhaXB, namXB);
										sach.themSachThuVien();
									}
								}

								break;
							}
							case 4: {
								cout << "\n3.4 - Sua sach trong thu vien duoc chon\n";
								Sach sach;
								//ThanhVien thanhVien;
								cout << "\nNhap ma sach can sua: ";
								cin >> maSach;
								//fflush(stdin);
								sach.setMaSach(maSach);
								sach.ktraMaSach("ThuVien");
								if (!sach.getCheckMaSach()) {
									cout << "\nSach co ma sach " << maSach << " khong ton ton tai trong thu vien!";
									break;
								}
								else
								{
									sach.ktraMaSach("DanhMucSach");
									if (!sach.getCheckMaSach()) {
										cout << "\nSach co ma sach " << maSach << " co trong phieu muon khong duoc phep sua!";
										break;
									}
									else
									{
										cout << "\nSua thong tin sach: ";
										cout << "\nMa sach: " << sach.getMaSach();
										cout << "\nTen sach: " << sach.getTenSach();
										cout << "\nTac gia: " << sach.getTacGia();
										cout << "\nNha xuat ban: " << sach.getNhaXB();
										cout << "\nNam xuat ban: " << sach.getNamXB();

										cout << "\n\nNhap thong tin sua: ";
										cin.ignore();
										cout << "\nNhap ten sach can sua: ";
										getline(cin, ten, '\n');
										//cin.ignore();
										cout << "Nhap ten tac gia can sua: ";
										getline(cin, tacGia, '\n');
										cout << "Nhap nha xuat ban can sua: ";
										getline(cin, nhaXB, '\n');
										cout << "Nhap nam xuat ban can sua: ";
										cin >> namXB;

										cout << "\nXac nhan thong tin sua sach: ";
										cout << "\nTen sach: " << ten;
										cout << "\nTen tac gia: " << tacGia;
										cout << "\nNha xuat ban: " << nhaXB;
										cout << "\nNam xuat ban: " << namXB;
										string confirmSua = "";
										cout << "\nChon (y/n): ";
										cin >> confirmSua;
										if (confirmSua == "y") {
											Sach sach(maSach, ten, tacGia, nhaXB, namXB);
											sach.suaSachThuVien("ThuVien");
											sach.suaSachThuVien("DanhMucSach");
											if (sach.getCheckMaSach()) {
												cout << "\nSua sach thanh cong";
											}
											else
											{
												cout << "\nSua sach khong thanh cong";
											}
										}
									}

								
								}
								break;
							}
							case 5: {
								cout << "\n3.5 - Xoa sach thu vien duoc chon\n";
								Sach sach;
								cout << "\nNhap ma sach can xoa: ";
								cin >> maSach;
								//fflush(stdin);
								sach.setMaSach(maSach);
								sach.ktraMaSach("ThuVien");
								if (!sach.getCheckMaSach()) {
									cout << "\nSach co ma sach " << maSach << " khong ton ton tai trong thu vien!";
									break;
								}
								else
								{
									sach.ktraMaSach("DanhMucSach");
									if (!sach.getCheckMaSach()) {
										cout << "\nSach co ma sach " << maSach << " co trong phieu muon khong duoc phep xoa!";
										break;
									}
									else
									{
										cout << "\nXac nhan xoa thong tin sach: ";
										cout << "\nMa sach: " << sach.getMaSach();
										cout << "\nTen sach: " << sach.getTenSach();
										cout << "\nTac gia: " << sach.getTacGia();
										cout << "\nNha xuat ban: " << sach.getNhaXB();
										cout << "\nNam xuat ban: " << sach.getNamXB();

										string confirmXoa = "";
										cout << "\nChon (y/n): ";
										cin >> confirmXoa;
										if (confirmXoa == "y") {
											sach.xoaSachThuVien("ThuVien");
											sach.xoaSachThuVien("DanhMucSach");
											if (sach.getCheckMaSach()) {
												cout << "\nXoa sach thanh cong";
											}
											else
											{
												cout << "\nXoa sach khong thanh cong";
											}
										}
									}
								}
									
								break;
							}
							default: {
								break;
							}			
						}
						cout << "\n\nBan muon thuc hien chuc nang voi sach? (y/n) :\n";
						cout << "Chon : ";
						cin >> choiceTV;
					}

					break;
				}				
				case 4: {
					string choiceTV = "y";
					while (choiceTV == "y"){
						int mssv, chonTV;
						string ten, lop, sdt, hetHan;
						cout << "\n4 - Quan ly thong tin thanh vien duoc chon\n";
						cout << "\nMoi chon chuc nang tuong ung:\n";
						cout << "1 - Xem danh sach thanh vien\n";
						cout << "2 - Xem thong tin thanh vien theo ma sinh vien\n";
						cout << "3 - Xem thong tin muon sach cua thanh vien\n";
						cout << "4 - Them thanh vien\n";
						cout << "5 - Sua thanh vien\n";
						cout << "6 - Xoa thanh vien\n";
						cout << "Chon: ";
						cin >> chonTV;
						switch (chonTV) {
							case 1: {
								cout << "\n4.1 - Xem danh sach thanh vien duoc chon\n";
								cout << "Nhap ma so sinh vien can xem: ";
								ThanhVien thanhvien;
								thanhvien.danhSachThanhVien();
								break;
							}
							case 2: {
								cout << "\n4.2 - Xem thong tin thanh vien duoc chon\n";
								cout << "Nhap ma so sinh vien can xem: ";
								cin >> mssv;
								ThanhVien thanhVien;
								thanhVien.setMssv(mssv);
								thanhVien.getThanhVien();
								if(thanhVien.getCheckMssv()) {
									cout << "\nMa so sinh vien: "<<thanhVien.getMssv();
									cout << "\nTen thanh vien: "<<thanhVien.getTenThanhVien();
									cout << "\nLop quan ly: "<<thanhVien.getLopQuanLy();
									cout << "\nSo dien thoai: "<<thanhVien.getSdt();
									cout << "\nNgay het han the: "<<thanhVien.getNgayHetHanThe();
								}
								else
								{
									cout << "\nThanh vien co MSSV " << mssv << " khong ton tai!";
								}
								break;
							}
							case 3: {
								cout << "\n4.3 - Xem thong tin muon sach cua thanh vien duoc chon\n";
								cout << "Nhap ma so sinh vien can xem: ";
								cin >> mssv;
								ThanhVien thanhVien;
								thanhVien.setMssv(mssv);
								thanhVien.getThanhVien();
								if(thanhVien.getCheckMssv()) {
									PhieuMuon phieuMuon;
									phieuMuon.setMssv(mssv);
									phieuMuon.timPhieuTheoMssv();
								}
								else
								{
									cout << "\nThanh vien co MSSV " << mssv << " khong ton tai!";
								}
								break;
							}
							case 4: {
								ThanhVien thanhVien;
								cout << "\n4.4 - Them thanh vien duoc chon\n";
								cout << "\nNhap ma so sinh vien: ";
								cin >> mssv;
								//fflush(stdin);
								thanhVien.setMssv(mssv);
								thanhVien.getThanhVien();
								if (thanhVien.getCheckMssv()) {
									cout << "\nThanh vien co MSSV " << mssv << " da ton ton tai!";
									break;
								}
								else
								{
									cin.ignore();
									cout << "Ten thanh vien: ";
									getline(cin, ten,'\n');
									//cin.ignore();
									cout << "Lop quan ly: ";
									cin >> lop;
									cout << "So dien thoai: ";
									cin >> sdt;
									cout << "Ngay het han the: ";
									cin >> hetHan;
									
									cout << "\nXac nhan thong tin them thanh vien: ";
									cout << "\nMa so sinh vien: " << mssv;
									cout << "\nTen thanh vien: " << ten;
									cout << "\nLop quan ly: " << lop;
									cout << "\nSo dien thoai: " << sdt;
									cout << "\nNgay het han the: " << hetHan;
									string confirmThem = "";
									cout << "\nChon (y/n): ";
									cin >> confirmThem;
									if (confirmThem == "y") {
										ThanhVien thanhVien(mssv,ten,lop,sdt,hetHan);
										thanhVien.themThanhVien();
									}									
								}
								
								break;
							}
							case 5: {
								cout << "\n4.5 - Sua thanh vien duoc chon\n";
								ThanhVien thanhVien;
								cout << "\nNhap ma so sinh vien can sua: ";
								cin >> mssv;
								//fflush(stdin);
								thanhVien.setMssv(mssv);
								thanhVien.getThanhVien();
								if (!thanhVien.getCheckMssv()) {
									cout << "\nThanh vien co MSSV " << mssv << " khong ton tai!";
									break;
								}
								else
								{
									cout << "\nSua thong tin thanh vien: ";
									cout << "\nMa so sinh vien: " << thanhVien.getMssv();
									cout << "\nTen thanh vien: " << thanhVien.getTenThanhVien();
									cout << "\nLop quan ly: " << thanhVien.getLopQuanLy();
									cout << "\nSo dien thoai: " << thanhVien.getSdt();
									cout << "\nNgay het han the: " << thanhVien.getNgayHetHanThe();

									cin.ignore();
									cout << "\n\nNhap thong tin sua: ";
									cout << "\nNhap ten thanh vien can sua: ";
									getline(cin, ten, '\n');
									//cin.ignore();
									cout << "Nhap lop quan ly can sua: ";
									cin >> lop;
									cout << "Nhap so dien thoai can sua: ";
									cin >> sdt;
									cout << "Nhap ngay het han the can sua: ";
									cin >> hetHan;

									cout << "\nXac nhan thong tin sua thanh vien: ";
									cout << "\nTen thanh vien: " << ten;
									cout << "\nLop quan ly: " << lop;
									cout << "\nSo dien thoai: " << sdt;
									cout << "\nNgay het han the: " << hetHan;
									string confirmSua = "";
									cout << "\nChon (y/n): ";
									cin >> confirmSua;
									if (confirmSua == "y") {
										ThanhVien thanhVien(mssv, ten, lop, sdt, hetHan);
										thanhVien.suaThanhVien();
									}
								}
								break;
							}
							case 6: {
								cout << "\n4.6 - Xoa thanh vien duoc chon\n";
								ThanhVien thanhVien;
								cout << "\nNhap ma so sinh vien can xoa: ";
								cin >> mssv;
								thanhVien.setMssv(mssv);
								thanhVien.getThanhVien();
								if (!thanhVien.getCheckMssv()) {
									cout << "\nThanh vien co MSSV " << mssv << " khong ton tai!";
									break;
								}
								else
								{
									thanhVien.kiemTraPhieuMuon();
									if (thanhVien.getCheckPhieuMuon()) {
										cout << "Thanh vien dang muon sach khong the xoa thong tin thanh vien";
										break;
									}
									else {
										cout << "\nXac nhan xoa thong tin thanh vien: ";
										cout << "\nMa so sinh vien: " << thanhVien.getMssv();
										cout << "\nTen thanh vien: " << thanhVien.getTenThanhVien();
										cout << "\nLop quan ly: " << thanhVien.getLopQuanLy();
										cout << "\nSo dien thoai: " << thanhVien.getSdt();
										cout << "\nNgay het han the: " << thanhVien.getNgayHetHanThe();

										string confirmXoa = "";
										cout << "\nChon (y/n): ";
										cin >> confirmXoa;
										if (confirmXoa == "y") {
											ThanhVien tv(thanhVien.getMssv(), thanhVien.getTenThanhVien(), thanhVien.getLopQuanLy(), thanhVien.getSdt(), thanhVien.getNgayHetHanThe());
											tv.xoaThanhVien();
										}
									}
								}
								break;
							}
							default: {
								break;
							}
						}

						//cin >> mssv;
						
						cout << "\n\nBan muon thuc hien chuc nang voi thanh vien? (y/n) :\n";
						cout << "Chon : ";
						cin >> choiceTV;
					}
					
					break;
				}
				default: {
					break;
				}

			}

			cout << "\n\nBan muon thuc hien chuc nang? (y/n) :\n";
			cout << "Chon : ";
			cin >> choice2;
		}	
	}else
	{
		cout << "\nDang nhap that bai";
	}
}

int main() {
	giaoDien();
	_getch();
	return 0;
}
