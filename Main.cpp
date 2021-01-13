//My Personal Password Encrypter/Decrypter

#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>

#include "StringToInt.cpp"
#include "PasswordEncDec.cpp"
#include "Menu.cpp"

using namespace std;

int main(){
	Menu start;
	start.menu();
	cout << endl << "Author: Umair Jibran" << endl;
	system("PAUSE");
}
