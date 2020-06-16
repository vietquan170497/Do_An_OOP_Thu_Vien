#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include"PhieuMuon.h"

using namespace std;

class Sach
{
public:
	Sach();
	~Sach();
	Sach(int ma, string ten, string tacGia, string nhaXB, string namXB);
	void setMaSach(int ma);
	int getMaSach();
	void setTenSach(string ten);
	string getTenSach();
	void setTacGia(string tacgia);
	string getTacGia();
	void setNhaXB(string nhaXB);
	string getNhaXB();
	void setNamXB(string namXB);
	string getNamXB();
	void setCheckMaSach(int check);
	int getCheckMaSach();
	void setTraSach(int traSach);
	int getTraSach();
	void danhMucSach();
	void ktraMaSach(string fileName);
	void muonSach();
	void taoTraSach();
	void themSachThuVien();
	void suaSachThuVien(string fileName);
	void xoaSachThuVien(string fileName);

private:
	int maSach;
	string tenSach;
	string tacGia;
	string nhaXB;
	string namXB;
	int checkMaSach;
	int traSach;
};

Sach::Sach()
{
}

Sach::Sach(int ma, string ten, string tacGia, string nhaXB, string namXB)
{
	this->maSach = ma;
	this->tenSach = ten;
	this->tacGia = tacGia;
	this->nhaXB = nhaXB;
	this->namXB = namXB;
}

Sach::~Sach()
{
}

void Sach::setMaSach(int ma) {
	this->maSach = ma;
}

int Sach::getMaSach() {
	return this->maSach;
}

void Sach::setTenSach(string ten) {
	this->tenSach = ten;
}

string Sach::getTenSach() {
	return this->tenSach;
}

void Sach::setTacGia(string tacgia) {
	this->tacGia = tacgia;
}

string Sach::getTacGia() {
	return this->tacGia;
}

void Sach::setNhaXB(string nhaXB) {
	this->nhaXB = nhaXB;
}

string Sach::getNhaXB() {
	return this->nhaXB;
}

void Sach::setNamXB(string namXB) {
	this->namXB = namXB;
}

string Sach::getNamXB() {
	return this->namXB;
}

void Sach::setCheckMaSach(int check) {
	this->checkMaSach = check;
}

int Sach::getCheckMaSach() {
	return this->checkMaSach;
}

void Sach::setTraSach(int traSach) {
	this->traSach = traSach;
}

int Sach::getTraSach() {
	return this->traSach;
}

void Sach::danhMucSach() {
	int i;
	string str;
	string tenSach;
	string tacGia;
	string nhaXB;
	string namXB;
	fstream file;
	string strArr[50][4];
	int intArr[50];
	file.open("DanhMucSach.txt", ios::in|| ios::out);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file DanhMucSach.txt";
	}
	else
	{
		i = 0;
		while (!file.eof()) {
			file >> intArr[i];
			getline(file, str, '\t');
			getline(file, strArr[i][0], '\t');
			getline(file, strArr[i][1], '\t');
			getline(file, strArr[i][2], '\t');
			getline(file, strArr[i][3], '\n');
			i++;
		}
	}
	i--;
	cout << "\nDanh muc sach:\n";

	cout << setfill('-');
	cout << "+" << setw(10) << "+" << setw(25) << "+"<< setw(25)<< "+"<< setw(20)<< "+"<< setw(10) << "+" << endl;
	cout << setfill(' ');

	cout << setw(10) << left << "| Ma sach" << setw(25) << left << "| Ten sach" << setw(25) << left << "| Tac gia"<< setw(20) << left << "| Nha XB"<< setw(10) << left << "| Nam XB" << "|" << endl;

	cout << setfill('-');
	cout << setw(10) << "+" << setw(25) << "+" << setw(25) << "+" << setw(20) << "+" << setw(10) << "+" << "+" << endl;
	cout << setfill(' ');

	for (int i1 = 0; i1 < i; i1++) {
		cout << "| " << setw(8) << intArr[i1];
		cout << "| " << setw(23) << strArr[i1][0];
		cout << "| " << setw(23) << strArr[i1][1];
		cout << "| " << setw(18) << strArr[i1][2];
		cout << "| " << setw(8) << strArr[i1][3];
		cout << "|\n";
		cout << setfill('-');
		cout << setw(10) << "+" << setw(25) << "+" << setw(25) << "+" << setw(20) << "+" << setw(10) << "+" << "+" << endl;
		cout << setfill(' ');
	}
	file.close();
}


void Sach::ktraMaSach(string fileName) {
	setCheckMaSach(0);
	int maSach;
	string str, ten, tacGia, nhaXB, namXB;
	fstream file;
	file.open(fileName + ".txt", ios::in);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file " + fileName + ".txt";
	}
	else
	{
		while (!file.eof()) {
			file >> maSach;
			if (getMaSach() == maSach) {
				setCheckMaSach(1);
				getline(file, str, '\t');
				getline(file, ten, '\t');
				getline(file, tacGia, '\t');
				getline(file, nhaXB, '\t');
				getline(file, namXB, '\n');
				setMaSach(maSach);
				setTenSach(ten);
				setTacGia(tacGia);
				setNhaXB(nhaXB);
				setNamXB(namXB);
				break;
			}
			else {
				getline(file, str, '\n');
			}
		}
	}
	file.close();
}

void Sach::muonSach() {
	int i;
	string str;
	string tenSach;
	string tacGia;
	string nhaXB;
	string namXB;
	fstream file;
	string strArr[50][4];
	int intArr[50];
	file.open("DanhMucSach.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file DanhMucSach.txt";
	}
	else
	{
		i = 0;
		while (!file.eof()) {
			file >> intArr[i];
			getline(file, str, '\t');
			getline(file, strArr[i][0], '\t');
			getline(file, strArr[i][1], '\t');
			getline(file, strArr[i][2], '\t');
			getline(file, strArr[i][3], '\n');
			i++;
		}
	}
	file.close();
	i--;
	//sua lai danh sach sach sau khi muon
	fstream file1;
	file1.open("DanhMucSach.txt", ios::out);
	if (!file1.is_open())
	{
		cout << "Khong mo duoc file DanhMucSach.txt";
	}
	else
	{
		for (int i1 = 0; i1 < i; i1++) {
			if (intArr[i1] != getMaSach()) {
				//if (i1 == 0) {
					file1 << intArr[i1] << "\t" << strArr[i1][0] << "\t" << strArr[i1][1] << "\t" << strArr[i1][2] << "\t" << strArr[i1][3] << "\n";
				//}
				/*else
				{
					file1 << "\n" << intArr[i1] << "\t" << strArr[i1][0] << "\t" << strArr[i1][1] << "\t" << strArr[i1][2] << "\t" << strArr[i1][3];
				}*/				
			}
		}
	}
	file1.close();
}

void Sach::taoTraSach() {
//	int i;
	int maSach;
	string str, tenSach, tacGia, nhaXB, namXB;
	fstream file;
	file.open("ThuVien.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file ThuVien.txt";
	}
	else
	{
		while (!file.eof()) {
			file >> maSach;
			if (maSach == getMaSach()) {
				getline(file, str, '\t');
				getline(file, tenSach, '\t');
				getline(file, tacGia, '\t');
				getline(file, nhaXB, '\t');
				getline(file, namXB, '\n');
			}
			else
			{
				getline(file, str, '\t');
				getline(file, str, '\t');
				getline(file, str, '\t');
				getline(file, str, '\t');
				getline(file, str, '\n');
			}
		}
	}
	file.close();
	setTraSach(0);
	//them thong tin sach vao danh muc sach
	fstream fileDM;
	fileDM.open("DanhMucSach.txt", ios::app | ios::out);
	if (fileDM << getMaSach() << "\t" << tenSach << "\t" << tacGia << "\t" << nhaXB << "\t" << namXB << "\n") {
		setTraSach(1);
	}
	fileDM.close();
}

void Sach::themSachThuVien() {
	fstream fileTV;
	fileTV.open("ThuVien.txt", ios::app | ios::out);
	if (!fileTV.is_open())
	{
		cout << "Khong mo duoc file ThuVien.txt";
	}
	else
	{
		if (fileTV << getMaSach() << "\t" << getTenSach() << "\t" << getTacGia() << "\t" << getNhaXB() << "\t" << getNamXB() << "\n") {
			fstream fileDM;
			fileDM.open("DanhMucSach.txt", ios::app | ios::out);
			if (!fileDM.is_open())
			{
				cout << "Khong mo duoc file DanhMucSach.txt";
			}
			else
			{
				if (fileDM << getMaSach() << "\t" << getTenSach() << "\t" << getTacGia() << "\t" << getNhaXB() << "\t" << getNamXB() << "\n") {
					cout << "\nThem sach vao thu vien thanh cong!\n";
				}
				else
				{
					cout << "\nThem sach vao thu vien khong thanh cong!\n";
				}
			}
			fileDM.close();
			//cout << "\nThem sach vao thu vien thanh cong!\n";
		}
		else
		{
			cout << "\nThem sach vao thu vien khong thanh cong!\n";
		}
	}
	fileTV.close();
}

void Sach::suaSachThuVien(string fileName) {
	setCheckMaSach(0);
	int position, countSach;
	string dsSach[50];
	fstream file;
	file.open(fileName+".txt", ios::in);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file "+ fileName +".txt";
	}
	else
	{
		position = 0;
		countSach = 0;
		while (!file.eof()) {
			//file >> mssv;
			getline(file, dsSach[countSach++], '\n');
		}
	}
	countSach--;
	file.close();
	//cout << mssv;
	string s;
	string strMaSach, thongTinSach[10];
	int intMaSach, sachCount;
	for (int j = 0; j < countSach; j++)
	{
		s = dsSach[j];
		string delimiter = "\t";
		strMaSach = s.substr(0, s.find(delimiter));
		if (strMaSach != "") {
			stringstream geek(strMaSach);
			geek >> intMaSach;
			if (intMaSach == getMaSach()) {
				position = j;
				size_t pos = 0;
				string token;
				sachCount = 0;
				while ((pos = s.find(delimiter)) != string::npos) {
					token = s.substr(0, pos);
					thongTinSach[sachCount++] = token;
					s.erase(0, pos + delimiter.length());
				}
			}
		}

	}
	fstream fileSach;
	fileSach.open(fileName+".txt", ios::out);
	if (!fileSach.is_open())
	{
		cout << "Khong mo duoc file "+ fileName +".txt";
	}
	else {
		for (int i1 = 0; i1 < countSach; i1++) {
			if (i1 != position) {
				fileSach << dsSach[i1] << "\n";
			}
			else
			{
				if (fileSach << getMaSach() << "\t" << getTenSach() << "\t" << getTacGia() << "\t" << getNhaXB() << "\t" << getNamXB() << "\n") {
					setCheckMaSach(1);
				}
				else
				{
					setCheckMaSach(0);
				}
			}
		}
	}
}

void Sach::xoaSachThuVien(string fileName) {
	setCheckMaSach(0);
	int position, countSach;
	string dsSach[50];
	fstream file;
	file.open(fileName+".txt", ios::in);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file "+fileName+".txt";
	}
	else
	{
		position = 0;
		countSach = 0;
		while (!file.eof()) {
			//file >> mssv;
			getline(file, dsSach[countSach++], '\n');
		}
	}
	countSach--;
	file.close();
	//cout << mssv;
	string s;
	string strMaSach, thongTinSach[10];
	int intMaSach, sachCount;
	for (int j = 0; j < countSach; j++)
	{
		s = dsSach[j];
		string delimiter = "\t";
		strMaSach = s.substr(0, s.find(delimiter));
		if (strMaSach != "") {
			stringstream geek(strMaSach);
			geek >> intMaSach;
			if (intMaSach == getMaSach()) {
				position = j;
				size_t pos = 0;
				string token;
				sachCount = 0;
				while ((pos = s.find(delimiter)) != string::npos) {
					token = s.substr(0, pos);
					thongTinSach[sachCount++] = token;
					s.erase(0, pos + delimiter.length());
				}
			}
		}

	}
	fstream fileSach;
	fileSach.open(fileName+".txt", ios::out);
	if (!fileSach.is_open())
	{
		cout << "Khong mo duoc file "+ fileName +".txt";
		setCheckMaSach(0);
	}
	else {
		for (int i1 = 0; i1 < countSach; i1++) {
			if (i1 != position) {
				fileSach << dsSach[i1] << "\n";
			}
		}
		setCheckMaSach(1);
	}
}
