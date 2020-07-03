#pragma once
#include<iostream>
#include <iomanip>
#include<fstream>
#include<string> 
#include<conio.h>
#include<sstream>
#include"Sach.h"

using namespace std;

class PhieuMuon
{
public:
	PhieuMuon();
	~PhieuMuon();
	void setMaMuon(int maMuon);
	int getMaMuon();
	void setMssv(int mssv);
	int getMssv();
	void setMaSach(int maSach);
	int getMaSach();
	void setNgayMuon(string ngayMuon);
	string getNgayMuon();
	void setNgayTra(string ngayTra);
	string getNgayTra();
	void taoPhieuMuon(int a[50], int countMa);
	void setCheckMaPhieu(int check);
	int getCheckMaPhieu();
	void ktraMaPhieu();
	void taoPhieuTra();
	void taoTraSach(int maSachTra);
	void timPhieuTheoMssv();
	void getSachThuVien(int maSach);

private:
	int maMuon;
	int mssv;
	int maSach;
	string ngayMuon;
	string ngayTra;
	int checkMaPhieu;
};

PhieuMuon::PhieuMuon()
{
}

PhieuMuon::~PhieuMuon()
{
}

void PhieuMuon::setMaMuon(int maMuon) {
	this->maMuon = maMuon;
}

int PhieuMuon::getMaMuon() {
	return this->maMuon;
}

void PhieuMuon::setMssv(int mssv) {
	this->mssv = mssv;
}

int PhieuMuon::getMssv() {
	return this->mssv;
}

void PhieuMuon::setMaSach(int maSach) {
	this->maSach = maSach;
}

int PhieuMuon::getMaSach() {
	return this->maSach;
}

void PhieuMuon::setNgayMuon(string ngayMuon) {
	this->ngayMuon = ngayMuon;
}

string PhieuMuon::getNgayMuon() {
	return this->ngayMuon;
}

void PhieuMuon::setNgayTra(string ngayTra) {
	this->ngayTra = ngayTra;
}

string PhieuMuon::getNgayTra() {
	return this->ngayTra;
}

void PhieuMuon::setCheckMaPhieu(int check) {
	this->checkMaPhieu = check;
}

int PhieuMuon::getCheckMaPhieu() {
	return this->checkMaPhieu;
}

void PhieuMuon::taoPhieuMuon(int ds[50], int countMa) {	
	string strMssv = to_string(getMssv());
	string strMaSach = "";
	//for (int j = 0; j < countMa; j++){

	strMaSach += to_string(ds[0]);
	if (countMa == 0) {
		cout << "\nBan chua nhap ma sach, tao phieu khong thanh cong";
	}
	else {
		strMssv += strMaSach;
		int maPhieu;
		maPhieu = stoi(strMssv);
		setMaMuon(maPhieu);
		fstream file;
		file.open("PhieuMuon.txt", ios::app | ios::out);
		if (!file.is_open())
		{
			cout << "Khong mo duoc file PhieuMuon.txt";
		}
		else
		{
			file << getMaMuon() << "\t" << getMssv() << "\t";
			for (int j = 0; j < countMa; j++) {
				file << ds[j] << "\t";
			}
			file << "\n";
			cout << "\nTao phieu muon thanh cong\n";

			cout << setfill('-');
			cout << "+" << setw(15) << "+" << setw(30) << "+" << endl;
			cout << setfill(' ');

			cout << setw(15) << left << "| Ma muon";
			cout << "| " << setw(28) << left << getMaMuon() << "|" << endl;

			cout << setfill('-');
			cout << setw(15) << "+" << setw(30) << "+" << "+" << endl;
			cout << setfill(' ');

			cout << setw(15) << left << "| Mssv";
			cout << "| " << setw(28) << left  << getMssv() << "|" << endl;

			cout << setfill('-');
			cout << setw(15) << "+" << setw(30) << "+" << "+" << endl;
			cout << setfill(' ');

			cout << setw(15) << left << "| Sach muon:";
			cout << setw(30) << left << "| " << "|" << endl;
			for (int j = 0; j < countMa; j++) {
				cout << setfill('-');
				cout << setw(15) << "+" << setw(30) << "+" << "+" << endl;
				cout << setfill(' ');
				getSachThuVien(ds[j]);
			}
			cout << setfill('-');
			cout << setw(15) << "+" << setw(30) << "+" << "+" << endl;
			cout << setfill(' ');
		}
		file.close();
	}
}

void PhieuMuon::ktraMaPhieu() {
	setCheckMaPhieu(0);
	int maPhieu;
	string str;
	fstream file;
	file.open("PhieuMuon.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file PhieuMuon.txt";
	}
	else
	{
		while (!file.eof()) {
			file >> maPhieu;
			if (getMaMuon() == maPhieu) {
				setCheckMaPhieu(1);
				break;
			}
			/*getline(file, str, '\t');
			getline(file, str, '\t');*/
			getline(file, str, '\n');
		}
	}
	file.close();
}

void PhieuMuon::taoPhieuTra() {
	string dsPhieu[50];
	int phieu[50];
	int countPhieu, position;
	int maMuon = 0, mssv = 0, maSach = 0;
	fstream file;
	file.open("PhieuMuon.txt", ios::in || ios::out);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file PhieuMuon.txt";
	}
	else
	{
		position = 0;
		countPhieu = 0;
		while (!file.eof()) {
			getline(file, dsPhieu[countPhieu++],'\n');
		}
	}
	countPhieu--;
	file.close();
	if (countPhieu > 0) {
		string s;
		string strMaPhieu;
		int intMaPhieu = 0, pCount = 0;
		for (int j = 0; j < countPhieu; j++) {
			s = dsPhieu[j];
			string delimiter = "\t";
			strMaPhieu = s.substr(0, s.find(delimiter));
			if (strMaPhieu != "") {
				stringstream geek(strMaPhieu);
				geek >> intMaPhieu;
				if (intMaPhieu == getMaMuon()) {
					position = j;
					size_t pos = 0;
					string token;
					pCount = 0;
					while ((pos = s.find(delimiter)) != string::npos) {
						token = s.substr(0, pos);
						stringstream geek(token);
						geek >> phieu[pCount++];
						s.erase(0, pos + delimiter.length());
					}
				}
			}

		}
		//cout << position << endl;
		for (int j1 = 2; j1 < pCount; j1++) {
			taoTraSach(phieu[j1]);
		}

		fstream filePM;
		filePM.open("PhieuMuon.txt", ios::out);
		if (!filePM.is_open())
		{
			cout << "Khong mo duoc file PhieuMuon.txt";
		}
		else {
			for (int i1 = 0; i1 < countPhieu; i1++) {
				if (i1 != position) {
					filePM << dsPhieu[i1] << "\n";
				}
			}
		}

		cout << "\nTra sach thanh cong\n";

		cout << setfill('-');
		cout << "+" << setw(15) << "+" << setw(30) << "+" << endl;
		cout << setfill(' ');

		cout << setw(15) << left << "| Ma muon";
		cout << "| " << setw(28) << left << phieu[0] << "|" << endl;

		cout << setfill('-');
		cout << setw(15) << "+" << setw(30) << "+" << "+" << endl;
		cout << setfill(' ');

		cout << setw(15) << left << "| Mssv";
		cout << "| " << setw(28) << left << phieu[1] << "|" << endl;

		cout << setfill('-');
		cout << setw(15) << "+" << setw(30) << "+" << "+" << endl;
		cout << setfill(' ');

		cout << setw(15) << left << "| Sach tra:";
		cout << setw(30) << left << "| " << "|" << endl;
		for (int j = 2; j < pCount; j++) {
			cout << setfill('-');
			cout << setw(15) << "+" << setw(30) << "+" << "+" << endl;
			cout << setfill(' ');
			getSachThuVien(phieu[j]);
		}
		cout << setfill('-');
		cout << setw(15) << "+" << setw(30) << "+" << "+" << endl;
		cout << setfill(' ');

		filePM.close();
	}
	else
	{
		cout << endl << "Khong co phieu muon nao";
	}
}

void PhieuMuon::taoTraSach(int maSachTra) {
	int maSach;
	string str, tenSach, tacGia, nhaXB, namXB;
	fstream fileTV;
	fileTV.open("ThuVien.txt", ios::in);
	if (!fileTV.is_open())
	{
		cout << "Khong mo duoc file ThuVien.txt";
	}
	else
	{
		while (!fileTV.eof()) {
			fileTV >> maSach;
			if (maSach == maSachTra) {
				getline(fileTV, str, '\t');
				getline(fileTV, tenSach, '\t');
				getline(fileTV, tacGia, '\t');
				getline(fileTV, nhaXB, '\t');
				getline(fileTV, namXB, '\n');
			}
			else
			{
				getline(fileTV, str, '\t');
				getline(fileTV, str, '\t');
				getline(fileTV, str, '\t');
				getline(fileTV, str, '\t');
				getline(fileTV, str, '\n');
			}
		}
	}
	fileTV.close();

	fstream fileDM;
	fileDM.open("DanhMucSach.txt", ios::app | ios::out);
	if (!fileDM.is_open())
	{
		cout << "Khong mo duoc file DanhMucSach.txt";
	}
	else {
		fileDM  << maSachTra << "\t" << tenSach << "\t" << tacGia << "\t" << nhaXB << "\t" << namXB << "\n";
	}
	fileDM.close();
}

void PhieuMuon::timPhieuTheoMssv() {
	int maPhieu, mssv, countSach, countMaSach, dsSach[50];
	string str,s,strMaSach,dsMaSach[50];
	fstream file;
	file.open("PhieuMuon.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file PhieuMuon.txt";
	}
	else
	{
		countMaSach = 0;
		while (!file.eof()) {
			file >> maPhieu;
			file >> mssv;
			if (getMssv() == mssv) {
				getline(file, str, '\t');
				getline(file, str, '\n');
				dsMaSach[countMaSach++] = str;
			}
			else
			{
				getline(file, str, '\n');
			}			
		}
	}
	file.close();
	countMaSach--;
	if (countMaSach > 0) {
		countSach = 0;
		for (int i = 0; i < countMaSach; i++)
		{
			s = dsMaSach[i];
			string delimiter = "\t";
			size_t pos = 0;
			string token;
			while ((pos = s.find(delimiter)) != string::npos) {
				token = s.substr(0, pos);
				stringstream geek(token);
				geek >> dsSach[countSach++];
				s.erase(0, pos + delimiter.length());
			}
		}

		int cSachTV = 0, dsSachTV[50], tmp;
		for (int i = 0; i < countSach; i++) {
			for (int j = i + 1; j < countSach; j++) {
				if (dsSach[i] > dsSach[j]) {
					tmp = dsSach[i];
					dsSach[i] = dsSach[j];
					dsSach[j] = tmp;
				}
			}
		}
		dsSachTV[cSachTV++] = dsSach[0];
		for (int i = 0; i < countSach - 1; i++) {
			if (dsSach[i] != dsSach[i + 1]) {
				dsSachTV[cSachTV++] = dsSach[i + 1];
			}
		}
		cout << endl << "So sach thanh vien " << getMssv() << " muon la: " << (cSachTV);
		cout << "\nCac quyen thanh vien muon la: " << endl;
		cout << setfill('-');
		cout << "+" << setw(15) << "+" << setw(30) << "+" << endl;
		cout << setfill(' ');
		for (int j = 0; j < cSachTV; j++)
		{
			getSachThuVien(dsSachTV[j]);
			cout << setfill('-');
			cout << setw(15) << "+" << setw(30) << "+" << "+" << endl;
			cout << setfill(' ');
			//cout << "\n";
		}
	}
	else {
		cout << endl << "Thanh vien khong muon sach cua thu vien" ;
	}
}

void PhieuMuon::getSachThuVien(int maSach) {
	int maSachThuVien;
	string str, tenSach, tacGia, nhaXB, namXB;
	fstream fileTV;
	fileTV.open("ThuVien.txt", ios::in);
	if (!fileTV.is_open())
	{
		cout << "Khong mo duoc file ThuVien.txt";
	}
	else
	{
		while (!fileTV.eof()) {
			fileTV >> maSachThuVien;
			if (maSach == maSachThuVien) {
				getline(fileTV, str, '\t');
				getline(fileTV, tenSach, '\t');
				getline(fileTV, tacGia, '\t');
				getline(fileTV, nhaXB, '\t');
				getline(fileTV, namXB, '\n');
				break;
			}
			else
			{
				getline(fileTV, str, '\n');
			}
		}
	}
	fileTV.close();
	cout << setw(15) << left << "| Ma sach";
	cout << "| " << setw(28) << left << maSach << "|" << endl;
	cout << setw(15) << left << "| Ten sach";
	cout << "| " << setw(28) << left << tenSach << "|" << endl;
}