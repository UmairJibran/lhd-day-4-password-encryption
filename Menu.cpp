#include <iostream>
using namespace std;
//Menu Class
class Menu{
	private:
		//Variables
		string option;
		PasswordEncDec encDec;
		//Functions
		void optionChecker(){
			switch(option[0]){
				case 'E':
				case 'e':
				case 'D':
				case 'd':{
					encDec.processStarter(option[0]);
					break;
				}
				case 'C':
				case 'c':{
					cout << endl << setw(50) << "Process Aborted!";	
					break;
				}
				default:{
					cout << endl << "Please Enter a Valid Character" << endl;
					system("PAUSE");
					system("cls");
					menu();
					break;
				}
			}
		}
	public:
		Menu(){
			option[0] = 'C';
		}
		void menu(){
			cout << endl << setw(50) << "WELCOME"
				 << endl << "Please Select an Option from the menu Below"
				 << endl << "E. Encrypt"
				 << endl << "D. Decrypt"
				 << endl << "C. CLOSE!"
				 << endl << " ---> ";
			getline(cin, option);
			optionChecker();
		}
};
