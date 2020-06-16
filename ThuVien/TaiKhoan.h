#pragma once

#include<iostream>
#include<fstream>

using namespace std;

class TaiKhoan
{
public:
	TaiKhoan();
	TaiKhoan(int stk, int mk);
	~TaiKhoan();
	void setStk(int stk);
	int getStk();
	void setMk(int mk);
	int getMk();
	void setCheck(int check);
	int getCheck();
	void dangNhap();

private:
	int stk;
	int mk;
	int check;
};

TaiKhoan::TaiKhoan()
{
}

TaiKhoan::TaiKhoan(int stk, int mk)
{
	this->stk = stk;
	this->mk = mk;
}

TaiKhoan::~TaiKhoan()
{
}

void TaiKhoan::setStk(int stk) {
	this->stk = stk;
}

int TaiKhoan::getStk() {
	return this->stk;
}

void TaiKhoan::setMk(int mk) {
	this->mk = mk;
}

int TaiKhoan::getMk() {
	return this->mk;
}

void TaiKhoan::setCheck(int check) {
	this->check = check;
}

int TaiKhoan::getCheck() {
	return this->check;
}

void TaiKhoan::dangNhap() {
	int inputStk;
	int inputMK;
	int stk,mk,n,tmp;
	cout << "Moi quan ly thu vien dang nhap he thong";
	cout << "\nNhap so tk : ";
	cin >> inputStk;
	cout << "Nhap mat khau : ";
	cin >> inputMK;
	cout << "STK nhap : " << inputStk << "\t MK nhap : " << inputMK << endl;
	setCheck(0);
	//kiem tra thong tin dang nhap
	//int a[50][5];
	fstream myfile;
	myfile.open("TaiKhoan.txt", ios::in);
	if (!myfile.is_open()) cout << "Khong mo duoc file TaiKhoan.txt";
	myfile >> n;
	while (!myfile.eof()) {
		for (int i = 0; i < n; i++) {
			myfile >> stk;
			if (i % 2 == 0) {
				if (stk == inputStk) {
					myfile >> mk;
					if (mk == inputMK) {
						i++;
						setCheck(1);
					}
					else
					{
						i++;
						setCheck(0);
					}
				}
				else
				{
					i++;
					myfile >> tmp;
				}
			}
		}
	}
	myfile.close();
}
