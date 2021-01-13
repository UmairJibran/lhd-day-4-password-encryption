#include<iostream>
using namespace std;

//Class for Encryption and Decryption
class PasswordEncDec{
	private:
//		Variables
		int TOTAL_KEYS;
		string password;
		int shift[TOTAL_KEYS];
		ifstream inputFile;
		ofstream outputFile;
		
//		Functions		
		void passwordSaver(){
			outputFile << password;
			outputFile.close();
			inputFile.close();
		}
		int getValue(int currValue, int shift , char p){
			if(p == 'e'){
				int temp = currValue + shift;
				if( temp >= 127){
					getValue((temp - 127) , 32 , p);
				}
				else return temp;
			}else{
				int temp = currValue - shift;
				if( temp < 32){
					getValue((temp + 127) , 32 , p);
				}
				else return temp;
			}
		}
	public:
		PasswordEncDec(){
			password = "NULL";
			inputFile.open("pass.txt");
			getline(inputFile,password);
			outputFile.open("pass.txt");
			ifstream t;
			t.open("numbers.txt");
			if(t.is_open()){
				string te;
				StringToInt STOI;
				for(int i = 0 ; i < TOTAL_KEYS ; i++){						
					getline(t,te);
					shift[i]=STOI.stoi( te );
				}
				t.close();
			}
		}
		bool fileChecker(){
			if(!(inputFile.is_open() && outputFile.is_open())){
				cout << endl << "Failed to Open File!";
				return 1;	
			}
			else{
				if(password == " "){
					cout << endl << "The File is Empty";
					return 1;
				}
				else if(password == ""){
					cout << endl << "The File is Empty";
					return 1;
				}
				else if(password == "/0"){
					cout << endl << "The File is Empty";
					return 1;
				}
				return 0;
			}
		}
		void processStarter(char o){
			for(int i = 0 , j = 0; i < password.length() ; i++,j++){
				if(j >= TOTAL_KEYS) j = 0;
				int newChar = getValue(int(password[i]),shift[j],o);
				password[i] = char(int(newChar));
			}
			passwordSaver();
			cout << "Check your output file for ";
			(o == 'e' || o == 'E')?cout<<"Encrypted":cout<<"Decrypted";
			cout<<" password";
			cout << endl << setw(50) << "Process Completed!";			
		}
};
