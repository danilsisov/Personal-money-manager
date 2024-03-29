/******************************************************************************* 
 * 
 * 
DANIL SISOV
BANK RECORD
2K20
 * 
 *    
*******************************************************************************/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cctype>
#include<iomanip>
#include <string>
using namespace std;

class bank {
private:
    char date[20]; // transaction date
    char description[20]; // user name
    char location[20]; // user lastname
    float sum; // user balance
    int balance = 0;
    float a;
    unsigned x; // deposite or withdraw
public:
    void line(); // line painting
    void author();
    void depositeWithDetails(); // welcom with author name
    void depositeRepeat();
    void withdrawWithDetails();
    void withdrawRepeat();
    int read_amout();
    void amout();
    void dep_in();
    void deposit(); // deposite +
    void withdraw(); // withdraw -
    void editDepositeDetails(); // deposite + to file
    void editWithdrawDetails(); // withdraw - to file
    void depositeWriteInFile(); // new account to file
    void withdrawWriteInFile(); // new account to file
    void depositeAll(); // accounts template
    void withdrawAll(); // accounts template
    void read_rec(); //show all accounts from file with template
    void search_rec(); // search account in file
    void delete_rec(); // delete account from file
};

//decorative line
void bank::line() {
    int amount = 80;
    char symb = '-';
    for (int i = 0; i < amount; i++) {
    cout << symb;
    }
}

//start screen with author name and name of the game
void bank::author() {
    line();
    cout << "\n\n\t\t\t Personal finance programm" << endl;
    cout << "\t\t\t\t     by" << endl;
    cout << "\t\t\t\t©Danil Sisov\n" << endl;
    cout << "\t\t  ______________________________________"<<endl;
    cout << "\t\t  |     _       _|__|_                 |"<< endl;
    cout << "\t\t  | /| / \\     / |  | \                 |"<< endl;
    cout << "\t\t  |  | \\_/     \\_|__|_                 |"<< endl;
    cout << "\t\t  |              |  | \\             _  |"<< endl;
    cout << "\t\t  |            __|__|_/         /| / \\ |"<< endl;
    cout << "\t\t  |              |  |            | \\_/ |"<< endl;
    cout << "\t\t  |____________________________________|"<<endl;

    
    line(); //line
    cin.get(); //freeze
}

// Deposite with details  
    void bank::depositeWithDetails() {
    line();

    cout << "\nEnter date: ";
    cin  >> date;
    cout << "Description: ";
    cin  >> description;
    cout << "Location: ";
    cin  >> location;
    cout << "Deposite: $";
    cin  >> x;
    cout << endl;
}

void bank::depositeRepeat() {
    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
    }

    while (inFile >> value) {
        if (value > 0) {
            cout << value;
        }
    }
    inFile.close();

    cout << "Please, confirm amout: ";
    cin >> a;
    sum = value + a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    std::cout << "End of program" << endl;
    out.close();
}

void bank::withdrawWithDetails() {
    line();

    cout << "\nEnter date: ";
    cin  >> date;
    cout << "Description: ";
    cin  >> description;
    cout << "Location: ";
    cin  >> location;
    cout << "Withdraw: $";
    cin  >> x;
    cout << endl;
}

void bank::withdrawRepeat() {
    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
    }

    while (inFile >> value) {
        if (value > 0) {
            cout << value;
        }
    }
    inFile.close();

    cout << "Please, confirm amout: ";
    cin >> a;
    sum = value - a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    std::cout << "End of program" << endl;
    out.close();
}

//all accounts list
void bank::depositeAll() {
    cout << endl;
    cout << "Date: "<< date << endl;
    cout << "Decription: " << description << endl;
    cout << "Location: " << location << endl;
    cout << "Deposite: $" << x << endl;
    line();
}

//all accounts list
void bank::withdrawAll() {
    cout << endl;
    cout << "Date: "<< date << endl;
    cout << "Decription: " << description << endl;
    cout << "Location: " << location << endl;
    cout << "Withdraw: $" << x << endl;
    line();
}

//deposite +
void bank::deposit() {
    cout << endl;
    cout << "Enter data to deposite: +$ ";
    cin >> x;
    sum+=x;
}

//withdraw -
void bank::withdraw() {
    cout << endl;
    cout << "Enter data to withdraw: -$ ";
    cin >> x;
    sum-=x;
}

int bank::read_amout() {
    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
        return 13;
    }

    while (inFile >> value)
    {
        if (value > 0)
        {  
            cout << value;
        }
    }
    inFile.close();

    return value;
}

// add and save account to file bank.txt
void bank::depositeWriteInFile() {
    ofstream outfile;
    outfile.open("deposite.txt", ios::app| ios::binary);
    depositeWithDetails();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}

// add and save account to file bank.txt
void bank::withdrawWriteInFile() {
    ofstream outfile;
    outfile.open("withdraw.txt", ios::app| ios::binary);
    withdrawWithDetails();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}


// read from file
void bank::read_rec() {
    ifstream dep; // Stream class to read from files
    dep.open("deposite.txt", ios::binary);// open file (bank.txt) in binary mode to write and read from file

    //If file can not to open
    if(!dep) {
        cout << "Error in deposite file! Try again" << endl;
        return;
    }

    // file open
    line(); 
    cout <<"\n\n\t\t\tDEPOSITE DATA" << endl;

    while(!dep.eof()) { //read while file have symbols
        if(dep.read(reinterpret_cast<char*>(this), sizeof(*this))) { // read and show all symblos in file 
            depositeAll(); // template for show all accounts
        }
    }
    cout << endl;
    cin.get();
    dep.close(); // close file
    cout << endl;


//Withdraw
    ifstream withdra; // Stream class to read from files
    withdra.open("withdraw.txt", ios::binary);// open file (bank.txt) in binary mode to write and read from file

    //If file can not to open
    if(!withdra) {
        cout << "Error in withdraw file! Try again" << endl;
        return;
    }

    // file open
    line(); 
    cout <<"\n\n\t\t\tWithdraw date" << endl;

    while(!withdra.eof()) { //read while file have symbols
        if(withdra.read(reinterpret_cast<char*>(this), sizeof(*this))) { // read and show all symblos in file 
            withdrawAll(); // template for show all accounts
        }
    }
    cout << endl;
    cin.get();
    withdra.close(); // close file

    cout << "Press any key ☺" << endl;
    cin.get();
    withdra.close(); // close file
}

void bank::amout() {
    int sum = 0;
    int x;
    ifstream inFile;
    
    inFile.open("amout.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (inFile >> x) {
        sum = sum + x;
    }
    
    inFile.close();
    cout << "Sum = " << sum << endl; 
}

void bank::search_rec() {
    line();
    cout <<"\n\n\t\t\tFind your account" << endl;
    int n; // choose account 
    ifstream in_search; // Stream class to read from files
    in_search.open("bank.txt", ios::binary); // open file (bank.txt) in binary mode to write and read from file

    //ERROR
    if(!in_search) {
        cout << "\nError in opening! Try again" << endl;
        return;
    }
    in_search.seekg (0,ios::end); //Sets the position of the next character to be extracted from the input stream.
    int count = in_search.tellg()/sizeof(*this); // Returns the position of the current character in the input stream.
    cout << "\n Our bank have " << count << " record in the system";
    cout << "\n Enter your ID number to find your personal data: ";
    cin >> n;
    in_search.seekg((n-1)*sizeof(*this)); // find account what user need
    in_search.read(reinterpret_cast<char*>(this), sizeof(*this)); // read and show all symblos that user need
    depositeAll(); // tempalte for accounts
    cout << endl;
    cin.get();
    cout << "Press any key ☺" << endl;
    cin.get();
}

void bank::editDepositeDetails() {
    line();
    cout <<"\n\n\t\t\tDeposite" << endl;
    int n;
    fstream indep;
    indep.open("bank.txt", ios::in|ios::binary); // open file in binary mode and for input mode

    //ERROR
    if(!indep) {
        cout << "\nError in opening! Try again" << endl;
        return;
    }
    indep.seekg(0, ios::end); // Go to end of input file
    int count = indep.tellg()/sizeof(*this);  //Returns the position of the current character in the input stream.
    cout << "\n Our bank have " << count << " record in the system";
    cout << "\n Type your id number: ";
    cin >> n;
    indep.seekg((n-1)*sizeof(*this)); // find account what user need
    indep.read(reinterpret_cast<char*>(this), sizeof(*this)); // read and show all symblos that user need
    cout << "Record " << n << " has following data" << endl;
    depositeAll();
    indep.close();
    indep.open("bank.txt", ios::out|ios::in|ios::binary); // // open file in binary mode, for input mode and reading mode
    indep.seekp((n-1)*sizeof(*this)); //Sets the position where the next character is to be inserted into the output stream
    // open void deposite() for deposite
    deposit();
    indep.write(reinterpret_cast<char*>(this), sizeof(*this));
}

void bank::editWithdrawDetails() {
    line();
    cout <<"\n\n\t\t\tWithdraw" << endl;
    int n;
    fstream inwithdr;
    inwithdr.open("bank.txt", ios::in|ios::binary);

    if(!inwithdr) {
        cout << "\nError in opening! File Not Found!!" << endl;
        return;
    }
    inwithdr.seekg(0, ios::end);
    int count = inwithdr.tellg()/sizeof(*this);
    cout << "\n Our bank have " << count << " record in the system";
    cout << "\n Type your id number: ";
    cin >> n;
    inwithdr.seekg((n-1)*sizeof(*this));
    inwithdr.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout << "Record " << n << " has following data" << endl;
    withdrawAll();
    inwithdr.close();
    inwithdr.open("bank.txt", ios::out|ios::in|ios::binary);
    inwithdr.seekp((n-1)*sizeof(*this));
    withdraw();
    inwithdr.write(reinterpret_cast<char*>(this), sizeof(*this));
}

void bank::delete_rec() {
    line();
    cout <<"\n\n\t\t\tDELETE" << endl;
    int n;
    ifstream infile;
    infile.open("bank.txt", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("file.txt", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("bank.txt");
    rename("file.txt", "bank.txt");
}

int main() {

    bank bank;
    bank.author();
    int option;

    while(true) {   
        cout<<"\n\n\t\t\t\t  MAIN MENU"; 
		cout<<"\n\n\t01| ⊚ DEPOSITE";
        cout<<"\n\n\t02| ⊚ WITHDRAW"; 
        cout<<"\n\n\t03| ⊚ AMOUT";
		cout<<"\n\n\t04| ⊚ ALL DATA LIST"; 
        cout<<"\n\n\t05| ⊚ LIST OF DEPOSITE CHANGE BY SERIATIM"; 
		cout<<"\n\n\t06| ⊚ LIST OF WITHDRAW CHANGE BY SERIATIM";  
		cout<<"\n\n\t07| ⊚ SERACH TRANSACTION BY SERIATIM"; 
		cout<<"\n\n\t08| ⊚ DELETE BY SERIATIM";
		cout<<"\n\n\t09| ⊚ EXIT";
        cout<<"\n\n\tSelect Your Option (1-9)⇨ ";
        cin >> option;

        switch(option) {
        case 1:
            bank.depositeWithDetails();
            bank.depositeRepeat();
            break;
        case 2:
            bank.withdrawWithDetails();
            bank.withdrawRepeat();
            break;
        case 3:
            bank.amout();
            break;
        case 4:
            bank.read_rec();
            break;
        case 5:
            bank.editDepositeDetails();
            break;
        case 6:
            bank.editWithdrawDetails();
            break;
        case 7:
            bank.search_rec();
            break;
        case 8:
            bank.delete_rec();
            break;
        case 9:
            cout << "\n\nThank you for using our bank. Have a nice day ☻☺\n\n" << endl;
            exit(0);
            break;
        default:
            cout<<"\nIncorrect number, please type number from 1 to 7 " << endl;
            cin.get();
            return main();
        }
    }
    system("pause");
    return 0;
}
