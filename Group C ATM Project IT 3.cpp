#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctime>
#include <map>

using namespace std;

int main(){

	long int account_No;
	string name;
	char type[10];
    float balance1;
    int i, npin, choice;

    srand(time(0));
	int pin = rand();

    double balance = 500000, withdraw;
    

    cout<<"=========================================================\n";
    cout<<"\t\tWelcome to Mini ATM Mobile            "<<endl;
    cout<<"\t\t           By:                        "<<endl;
    cout<<"\t\t   ####  GROUP C  ####                "<<endl;
    cout<<"=========================================================\n";
    
     // Create a map of string keys and int values
    map<string, int> userId;

  // Add some entries to the map
  userId["Akwila"] = 149;
  userId["Alexandra"] = 007;
  userId["Beatrice"] = 154;
  userId["Badar"] = 649;

  // Create a second map with string keys and the first map as the value
  map<string, map<string, int>> namesByCategory;

  // Add the first map to the second map
  namesByCategory["member"] = userId;

  // Print the values in the second map
  for (auto outerPair : namesByCategory) {
    cout << outerPair.first << ": " << endl;
    for (auto innerPair : outerPair.second) {
      cout << "  " << innerPair.first << ": " << innerPair.second << endl;
    }
  }
  
    cout<<"\n\t\thint pin : " << pin << endl;
    
    cout<<"\n\t\t== WELCOME USER == \n";

    for (i=0;i<3;i++){
        cout <<"\t\tEnter Your Pin: ";
        cin>>npin;
        balance1=balance;
        
        if (npin==pin){
            repeat:
            system("cls");

            do{
                cout<<"\n\n";
                cout<<"\t\t*                Main Menu                *"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t*           1 - Check Balance             *"<<endl;
                cout<<"\t\t*           2 - Withdraw Cash             *"<<endl;
                cout<<"\t\t*           3 - Update User Details       *"<<endl;
                cout<<"\t\t*           4 - Exit                      *"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t*******************************************"<<endl;cout<<"\n";
                
                cout<<"\t\t             Enter Option: ";
                cin>>choice;

                switch(choice){
                    case 1:
                        cout<<"\n\t\t\t [ BALANCE INQUIRY ] \n\n";
                        cout<<"\t\t\t***************************"<< endl;
                        cout<<"\t\t\t  Your Bank Balance : Rp"<< balance1 <<endl;
                        cout<<"\t\t\t***************************"<< endl;
                        getch();
                        goto repeat;
                        break;

                    case 2:
                        withdraw:
                        cout<<"\n\t\t\t  [ WITHDRAW ] \n\n";
                        cout<<"\t\t\t***************************"<< endl;
                        cout<<"\n\t\t\t Enter the amount : ";
                        cin>>withdraw;
                        if(withdraw<=balance1){
                            balance1 = balance1 - withdraw;
                            cout<<"\t\t\t Your remaining balance : Rp"<< balance1<< endl;
                        } else{
                            cout<<"\t\t!! You have only Rp."<< balance1 << " balance in your account. !!\n";
                            goto withdraw;
                        }
                        break;
					
					case 3:
                        cout << "\n\t\t\t [ UPDATE USER DETAILS ] \n\n" << endl;
                        cout << "Enter name\n";
						cin.ignore();

						// To use space in string
						getline(cin, name);
				
						cout << "Enter Account number\n";
						cin >> account_No;
						cout << "Enter Account type (Personal/Business)\n";
						cin >> type;
						
						cout << "\n Succesfully Updated! \n "<< endl;
						cout << "Name: " << name << endl;
						cout << "Account No: " << account_No << endl;
						cout << "Account Type: " << type << endl;
						cout << "Balance: " << balance1 << endl;
						
                        
                        break;

                    case 4:
                        exit(1);
                        break;
                    
                    default:
                        cout<<"\n\t\t Invalid! Please Enter The Correct Option. \n";
                        getch();
                        break;
                	
                	}
                   	    time_t currtime = time(0);
	                    char *mytime = ctime(&currtime);
                        cout << "\t\t\tDate & Time: ";
                        cout << mytime << endl; 
                        getch();
                        goto repeat;
                        break;
            }while (choice!=0);
            return 0;
        } else
            cout<<"\t\t\t Wrong Pin! Please Try Again.\n\n";
    }
		getch();
}