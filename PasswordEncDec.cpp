#include<iostream>
using namespace std;

//Class for Encryption and Decryption
class PasswordEncDec{
	private:
//		Variables
		string password;
		int shift[200];
		ifstream inputFile;
		ofstream outputFile;
		int j=0;
		
//		Functions		
		void passwordSaver(){
			outputFile << password<<endl;
			//outputFile.close();
			//inputFile.close();
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
			ifstream t;
			t.open("numbers.txt");
			if(t.is_open()){
				string te;
				StringToInt STOI;
				for(int i = 0 ; i < 200 ; i++){						
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
		void func(char o){
			for(int i = 0 ; i < password.length() ; i++){
				if(j >= 200) j = 0;
				if(password[i] != char(9)){
					password[i] = char(int(getValue(int(password[i]),shift[j],o)));
					j++;
				}else continue;
			}
			passwordSaver();
		}
		void processStarter(char o){
			//justAFunction(o);
			inputFile.open("plain_password.txt");
			outputFile.open("encrypted_password.txt",ios_base::app);
			while(getline(inputFile,password)) func(o);
			cout << "Check your output file for ";
			(o == 'e' || o == 'E')?cout<<"Encrypted":cout<<"Decrypted";
			cout<<" password";
			cout << endl << setw(50) << "Process Completed!";			
		}
		
};
