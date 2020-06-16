#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>

using namespace std;

class ThanhVien
{
public:
	ThanhVien();
	ThanhVien(int mssv, string tenThanhVien, string lopQuanLy, string sdt, string ngayHetHanThe);
	~ThanhVien();
	void setMssv(int mssv);
	int getMssv();
	void setTenThanhVien(string ten);
	string getTenThanhVien();
	void setLopQuanLy(string lop);
	string getLopQuanLy();
	void setSdt(string std);
	string getSdt();
	void setNgayHetHanThe(string ngay);
	string getNgayHetHanThe();
	void setCheckMssv(int check);
	int getCheckPhieuMuon();
	void setCheckPhieuMuon(int checkPhieuMuon);
	int getCheckMssv();
	void getThanhVien();
	void themThanhVien();
	void suaThanhVien();
	void kiemTraPhieuMuon();
	void xoaThanhVien();

private:
	int mssv;
	string tenThanhVien;
	string lopQuanLy;
	string sdt;
	string ngayHetHanThe;
	int checkMssv;
	int checkPhieuMuon;
};

ThanhVien::ThanhVien()
{
}

ThanhVien::ThanhVien(int mssv, string tenThanhVien, string lopQuanLy, string sdt, string ngayHetHanThe)
{
	this->mssv = mssv;
	this->tenThanhVien = tenThanhVien;
	this->lopQuanLy = lopQuanLy;
	this->sdt = sdt;
	this->ngayHetHanThe = ngayHetHanThe;
}

ThanhVien::~ThanhVien()
{
}

void ThanhVien::setMssv(int mssv) {
	this->mssv = mssv;
}

int ThanhVien::getMssv() {
	return this->mssv;
}


void ThanhVien::setTenThanhVien(string ten) {
	this->tenThanhVien = ten;
}

string ThanhVien::getTenThanhVien() {
	return this->tenThanhVien;
}

void ThanhVien::setLopQuanLy(string lop) {
	this->lopQuanLy = lop;
}

string ThanhVien::getLopQuanLy() {
	return this->lopQuanLy;
}

void ThanhVien::setSdt(string sdt) {
	this->sdt = sdt;
}

string ThanhVien::getSdt() {
	return this->sdt;
}

void ThanhVien::setNgayHetHanThe(string ngay) {
	this->ngayHetHanThe = ngay;
}

string ThanhVien::getNgayHetHanThe() {
	return this->ngayHetHanThe;
}

void ThanhVien::setCheckMssv(int check) {
	this->checkMssv = check;
}

int ThanhVien::getCheckMssv() {
	return this->checkMssv;
}

void ThanhVien::setCheckPhieuMuon(int checkPhieuMuon) {
	this->checkPhieuMuon = checkPhieuMuon;
}

int ThanhVien::getCheckPhieuMuon() {
	return this->checkPhieuMuon;
}

void ThanhVien::getThanhVien() {
	setCheckMssv(0);
	int mssv;
	string strTmp, ten, lop, sdt, ngayHetHan;
	fstream file;
	file.open("ThanhVien.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file ThanhVien.txt";
	}
	else
	{
		while (!file.eof()) {
			file >> mssv;
			if (getMssv() == mssv) {
				setCheckMssv(1);
				getline(file, strTmp, '\t');
				getline(file, ten, '\t');
				getline(file, lop, '\t');
				getline(file, sdt, '\t');
				getline(file, ngayHetHan, '\n');
				setMssv(mssv);
				setTenThanhVien(ten);
				setLopQuanLy(lop);
				setSdt(sdt);
				setNgayHetHanThe(ngayHetHan);
				break;
			}
			else {
				getline(file, strTmp, '\n');
			}
		}
	}
	file.close();
}

void ThanhVien::suaThanhVien() {
	int position, countTV;
	string dsTV[50];
	fstream file;
	file.open("ThanhVien.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file ThanhVien.txt";
	}
	else
	{
		position = 0;
		countTV = 0;
		while (!file.eof()) {
			//file >> mssv;
			getline(file, dsTV[countTV++], '\n');
		}
	}
	countTV--;
	file.close();
	//cout << mssv;
	string s;
	string strMaTV, thanhVien[10];
	int intMaTV, tvCount;
	for (int j = 0; j < countTV; j++)
	{
		s = dsTV[j];
		string delimiter = "\t";
		strMaTV = s.substr(0, s.find(delimiter));
		if (strMaTV != "") {
			stringstream geek(strMaTV);
			geek >> intMaTV;
			if (intMaTV == getMssv()) {
				position = j;
				size_t pos = 0;
				string token;
				tvCount = 0;
				while ((pos = s.find(delimiter)) != string::npos) {
					token = s.substr(0, pos);
					thanhVien[tvCount++] = token;
					/*stringstream geek(token);
					geek >> phieu[pCount++];*/
					s.erase(0, pos + delimiter.length());
				}
			}
		}

	}
	fstream fileTV;
	fileTV.open("ThanhVien.txt", ios::out);
	if (!fileTV.is_open())
	{
		cout << "Khong mo duoc file ThanhVien.txt";
	}
	else {
		for (int i1 = 0; i1 < countTV; i1++) {
			if (i1 != position) {
				fileTV << dsTV[i1] << "\n";
			}
			else
			{
				if(fileTV << getMssv() << "\t" << getTenThanhVien() << "\t" << getLopQuanLy() << "\t" << getSdt() << "\t" << getNgayHetHanThe() << "\n"){
					cout << "\nSua thanh vien thanh cong!"; 
				}
				else
				{
					cout << "\nSua thanh vien khong thanh cong!";
				}
			}
		}
	}
}

void ThanhVien::xoaThanhVien() {
	int position, countTV;
	string dsTV[50];
	fstream file;
	file.open("ThanhVien.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file ThanhVien.txt";
	}
	else
	{
		position = 0;
		countTV = 0;
		while (!file.eof()) {
			//file >> mssv;
			getline(file, dsTV[countTV++], '\n');
		}
	}
	countTV--;
	file.close();
	//cout << mssv;
	string s;
	string strMaTV, thanhVien[10];
	int intMaTV, tvCount;
	for (int j = 0; j < countTV; j++)
	{
		s = dsTV[j];
		string delimiter = "\t";
		strMaTV = s.substr(0, s.find(delimiter));
		if (strMaTV != "") {
			stringstream geek(strMaTV);
			geek >> intMaTV;
			if (intMaTV == getMssv()) {
				position = j;
				size_t pos = 0;
				string token;
				tvCount = 0;
				while ((pos = s.find(delimiter)) != string::npos) {
					token = s.substr(0, pos);
					thanhVien[tvCount++] = token;
					s.erase(0, pos + delimiter.length());
				}
			}
		}

	}
	fstream fileTV;
	fileTV.open("ThanhVien.txt", ios::out);
	if (!fileTV.is_open())
	{
		cout << "Khong mo duoc file ThanhVien.txt";
	}
	else {
		for (int i1 = 0; i1 < countTV; i1++) {
			if (i1 != position) {
				fileTV << dsTV[i1] << "\n";
			}
		}
		cout << "\nXoa thanh vien thanh cong!";
	}
}

void ThanhVien::themThanhVien() {
	fstream file;
	file.open("ThanhVien.txt", ios::app | ios::out);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file ThanhVien.txt";
	}
	else
	{
		if (file << getMssv() << "\t" << getTenThanhVien() << "\t" << getLopQuanLy() << "\t" << getSdt() << "\t" << getNgayHetHanThe() << "\n"){
			cout << "\nThem thanh vien thanh cong!\n";
		}
		else
		{
			cout << "\nThem thanh vien khong thanh cong!\n";
		}
	}
	file.close();
}

void ThanhVien::kiemTraPhieuMuon() {
	int maPhieu, mssv;
	setCheckPhieuMuon(0);
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
			file >> mssv;
			if (getMssv() == mssv) {
				setCheckPhieuMuon(1);
			}
			else
			{
				getline(file, str, '\n');
			}
		}
	}
	file.close();
}

