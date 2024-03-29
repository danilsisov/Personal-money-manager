//Personal money manager project for C++ programing course in Metropolia University Of Applied Scientist
//Author: Danil Sisov
//Year: 2020
//Month: December
//Platform: Linux(Ubuntu)
//Code editor: Visual Studio Code
//Compiler: gcc 9.3.0

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cctype>
#include<iomanip>
#include <string>
using namespace std;

class PersonalFinance {
private:
    char date[20]; // transaction date
    char description[20]; // user name
    char location[20]; // user lastname
    float sum; // user balance
    int balance = 0;
    float a;
    unsigned x; // income or expence

public:
    void decorativeLine(); // line painting just for decoration
    void author(); // welcome page with author name
    void depositeWithDetails(); // template for income with all needed incformation detailt to deposite.txt
    void withdrawWithDetails(); // template for expense with all needed incformation to withdraw.txt
    void deposit(); // income template
    void withdraw(); // expense template
    void depositeAll(); // accounts template
    void withdrawAll(); // accounts template
};


class Memory : PersonalFinance {
private:
    char date[25]; // transaction date
    char description[50]; // user name
    char location[30]; // user lastname
    float sum; // user balance
    int balance = 0;
    float a;
    unsigned x; // income or expence
    
public:
    void depositeRepeat();  // write to amout.txt. Checking current balance as this calculate all income and expense 
    void withdrawRepeat(); // write to amout.txt. Checking current balance as this calculate all income and expense 
    void depositeWithoutDetails(); // Add income without details
    void withdrawWithouDetails(); // Add expense without details
    void amout(); // Cheking current balance 
    void editDepositeDetails(); // income + to file
    void editWithdrawDetails(); // expense - to file
    void depositeWriteInFile(); // new income to file
    void withdrawWriteInFile(); // new expense to file
    void readAll(); //show all accounts from file with template
    void searchDep(); // search account in file
    void searchWith(); // search account in file
    void deleteIncome(); // delete account from file
    void deleteWithdraw(); // delete account from file
};


//decorative line
void PersonalFinance::decorativeLine() {
    int amount = 80;
    char symb = '-';
    for (int i = 0; i < amount; i++) {
    cout << symb;
    }
}

//start screen with author name and name of the game
void PersonalFinance::author() {
    decorativeLine();
    cout << "\n\n\t\t\t Personal finance programm" << endl;
    cout << "\t\t\t\t     by" << endl;
    cout << "\t\t\t\t©Danil Sisov\n" << endl;
    cout << "\t\t  ______________________________________"<<endl;
    cout << "\t\t  |     _       _|__|_                 |"<< endl;
    cout << "\t\t  | /| / \\     / |  | \\                |"<< endl;
    cout << "\t\t  |  | \\_/     \\_|__|_                 |"<< endl;
    cout << "\t\t  |              |  | \\             _  |"<< endl;
    cout << "\t\t  |            __|__|_/         /| / \\ |"<< endl;
    cout << "\t\t  |              |  |            | \\_/ |"<< endl;
    cout << "\t\t  |____________________________________|"<<endl;
 
    decorativeLine(); //line
    cin.get(); //freeze
}

// template for depositeRepeat
    void PersonalFinance::depositeWithDetails() {
    decorativeLine();

    cout << "\nEnter date: ";
    cin  >> date;
    cout << "Description: ";
    cin  >> description;
    cout << "Location: ";
    cin  >> location;
    cout << "Income: $";
    cin  >> x;
    cout << endl;
}

//income to amout.txt
void Memory::depositeRepeat() {
    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
    }

    while (inFile >> value) {
        if (value > 0) {
        }
    }
    inFile.close();

    cout << "Please, confirm amout:+ ";
    cin >> a;
    sum = value + a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    out.close();
}

//template for withdrawRepeat
void PersonalFinance::withdrawWithDetails() {
    decorativeLine();

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

//write expense to amout.txt
void Memory::withdrawRepeat() {
    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
    }

    while (inFile >> value) {
        if (value > 0) {
        }
    }
    inFile.close();

    cout << "Please, confirm amout:- ";
    cin >> a;
    sum = value - a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    out.close();
}

//deposite without details
void Memory::depositeWithoutDetails() {
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
    
    cout << "NOTE! YOU WILL NOT HAVE ANY DETAILS IN YOUR LIST ABOUT THIS INCOME" << endl;
    cout << "Please, enter income:+ ";
    cin >> a;
    sum = value + a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    out.close();
}

//withdraw whitout details
void Memory::withdrawWithouDetails() {
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

    cout << "NOTE! YOU WILL NOT HAVE ANY DETAILS IN YOUR LIST ABOUT THIS EXPENSE" << endl;
    cout << "Please, enter amout for expense:- ";
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
void PersonalFinance::depositeAll() {
    cout << endl;
    cout << "Date: "<< date << endl;
    cout << "Decription: " << description << endl;
    cout << "Location: " << location << endl;
    cout << "Deposite: $" << x << endl;
    decorativeLine();
}

//all accounts list
void PersonalFinance::withdrawAll() {
    cout << endl;
    cout << "Date: "<< date << endl;
    cout << "Decription: " << description << endl;
    cout << "Location: " << location << endl;
    cout << "Withdraw: $" << x << endl;
    decorativeLine();
}

//deposite +
void PersonalFinance::deposit() {
    cout << endl;
    cout << "Enter data to income: +$ ";
    cin >> x;
    sum+=x;
}

//withdraw -
void PersonalFinance::withdraw() {
    cout << endl;
    cout << "Enter data to expense: -$ ";
    cin >> x;
    sum-=x;
}


// add and save deposite to file deposite.txt
void Memory::depositeWriteInFile() {
    ofstream outfile;
    outfile.open("deposite.txt", ios::app| ios::binary);
    depositeWithDetails();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}

// add and save expense to file withdraw.txt
void Memory::withdrawWriteInFile() {
    ofstream outfile;
    outfile.open("withdraw.txt", ios::app| ios::binary);
    withdrawWithDetails();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}

//check currecnt balance
void Memory::amout() {
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
    cout << "Your Balance is = " << sum << endl; 
    inFile.close();

    cin.get();
    cout << "Press any key ☺" << endl;
    cin.get();
}

// Read all data
void Memory::readAll() {
//Deposite data---------------------------------------------------------------------------------------------------
    ifstream dep; // Stream class to read from files
    dep.open("deposite.txt", ios::binary);// open file (deposite.txt) in binary mode to write and read from file

    //If file can not to open
    if(!dep) {
        cout << "Error in deposite file! Try again" << endl;
        return;
    }

    // file open
    decorativeLine(); 
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


//Withdraw data-----------------------------------------------------------------------------------------------------
    ifstream withdra; // Stream class to read from files
    withdra.open("withdraw.txt", ios::binary);// open file (withdraw.txt) in binary mode to write and read from file

    //If file can not to open
    if(!withdra) {
        cout << "Error in withdraw file! Try again" << endl;
        return;
    }

    // file open
    decorativeLine(); 
    cout <<"\n\n\t\t\tWithdraw date" << endl;

    while(!withdra.eof()) { //read while file have symbols
        if(withdra.read(reinterpret_cast<char*>(this), sizeof(*this))) { // read and show all symblos in file 
            withdrawAll(); // template for show all accounts
        }
    }
    cout << endl;
    cin.get(); // freeze
    withdra.close(); // close file

    cout << "Press any key ☺" << endl;
    cin.get();
}

// Search needed data in deposite.txt
void Memory::searchDep() {
    decorativeLine();
    cout <<"\n\n\t\t\tFind your income since 1" << endl;
    int choise; // choose account 
    ifstream search; // Stream class to read from files
    search.open("deposite.txt", ios::binary); // open file (deposite.txt) in binary mode to write and read from file

    //ERROR
    if(!search) {
        cout << "\nError in opening! Try again" << endl;
        return;
    }
    search.seekg (0,ios::end); //Sets the position of the next character to be extracted from the input stream.
    int count = search.tellg()/sizeof(*this); // Returns the position of the current character in the input stream.
    cout << "\n Your income list have " << count << " record in the system";
    cout << "\n Write the number of income that you want to see: ";
    cin >> choise;
    search.seekg((choise-1)*sizeof(*this)); // find data what user need
    search.read(reinterpret_cast<char*>(this), sizeof(*this)); // read and show all symblos that user need
    depositeAll(); // tempalte for accounts
    cout << endl;
    cin.get();
    cout << "Press any key ☺" << endl;
    cin.get();
}

//Search needded data in withdraw.txt
void Memory::searchWith() {
    decorativeLine();
    cout <<"\n\n\t\t\tFind your expense since 1" << endl;
    int choise; // choose account 
    ifstream search; // Stream class to read from files
    search.open("deposite.txt", ios::binary); // open file (deposite.txt) in binary mode to write and read from file

    //ERROR
    if(!search) {
        cout << "\nError in opening! Try again" << endl;
        return;
    }
    search.seekg (0,ios::end); //Sets the position of the next character to be extracted from the input stream.
    int count = search.tellg()/sizeof(*this); // Returns the position of the current character in the input stream.
    cout << "\n Your expense list have " << count << " record in the system";
    cout << "\n Write the number of expense that you want to see: ";
    cin >> choise;
    search.seekg((choise-1)*sizeof(*this)); // find account what user need
    search.read(reinterpret_cast<char*>(this), sizeof(*this)); // read and show all symblos that user need
    withdrawAll(); // tempalte FOR expense
    cout << endl;
    cin.get();
    search.close();

    cout << "Press any key ☺" << endl;
    cin.get();
}

//edit deposite data
void Memory::editDepositeDetails() {
    decorativeLine();
    cout <<"\n\n\t\t\tDeposite" << endl;
    int n;
    fstream indep;
    indep.open("deposite.txt", ios::in|ios::binary); // open file in binary mode and for input mode

    //ERROR
    if(!indep) {
        cout << "\nError in opening! Try again" << endl;
        return;
    }
    indep.seekg(0, ios::end); // Go to end of input file
    int count = indep.tellg()/sizeof(*this);  //Returns the position of the current character in the input stream.
    cout << "\n Your deposite list have " << count << " record in the system";
    cout << "\n Type your id number: ";
    cin >> n;
    indep.seekg((n-1)*sizeof(*this)); // find account what user need
    indep.read(reinterpret_cast<char*>(this), sizeof(*this)); // read and show all symblos that user need
    cout << "Record " << n << " has following data" << endl;
    depositeAll();
    indep.close();
    indep.open("deposite.txt", ios::out|ios::in|ios::binary); // // open file in binary mode, for input mode and reading mode
    indep.seekp((n-1)*sizeof(*this)); //Sets the position where the next character is to be inserted into the output stream

    // open void deposite() for income
    deposit();
    indep.write(reinterpret_cast<char*>(this), sizeof(*this));
    indep.close();

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

//edit withdraw data
void Memory::editWithdrawDetails() {
    decorativeLine();
    cout <<"\n\n\t\t\tWithdraw" << endl;
    int n;
    fstream inwithdr;
    inwithdr.open("withdraw.txt", ios::in|ios::binary);

    if(!inwithdr) {
        cout << "\nError in opening! File Not Found!!" << endl;
        return;
    }

    inwithdr.seekg(0, ios::end);
    int count = inwithdr.tellg()/sizeof(*this);
    cout << "\n Your withdraw list have " << count << " record in the system";
    cout << "\n Type your id number: ";
    cin >> n;
    inwithdr.seekg((n-1)*sizeof(*this));
    inwithdr.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout << "Record " << n << " has following data" << endl;
    withdrawAll();
    inwithdr.close();
    inwithdr.open("withdraw.txt", ios::out|ios::in|ios::binary);
    inwithdr.seekp((n-1)*sizeof(*this));
    withdrawAll();
    inwithdr.write(reinterpret_cast<char*>(this), sizeof(*this));
    inwithdr.close();

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

//Delete Income data
void Memory::deleteIncome() {
    decorativeLine();
    cout <<"\n\n\t\t\tDELETE" << endl;
    int n;
    ifstream infile;
    infile.open("deposite.txt", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" income record in the file";
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
    remove("deposite.txt");
    rename("file.txt", "deposite.txt");
}

//Delete 
void Memory::deleteWithdraw() {
    decorativeLine();
    cout <<"\n\n\t\t\tDELETE EXPENCE" << endl;
    int n;
    ifstream infile;
    infile.open("withdraw.txt", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" expense record in the file";
    cout<<"\n Enter Record number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("file.txt", ios::out|ios::binary);
    infile.seekg(0);
    for(int i = 0; i < count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i == (n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("withdraw.txt");
    rename("file.txt", "withdraw.txt");
}


int main() {

    PersonalFinance PersonalFinance;
    Memory memory;
    PersonalFinance.author();
    int option;

    while(true) {   
        cout<<"\n\n\t\t\t\t  MAIN MENU"; 
		cout<<"\n\n\t01| ⊚ INCOME WITH DETAILS";
        cout<<"\n\n\t02| ⊚ EXPENSE WITH DETAILS"; 
        cout<<"\n\n\t03| ⊚ AMOUT";
		cout<<"\n\n\t04| ⊚ ALL DATA LIST"; 
        cout<<"\n\n\t05| ⊚ INCOME WITHOUT DETAILS"; 
		cout<<"\n\n\t06| ⊚ EXPENSE WITHOUT DETAILS";  
		cout<<"\n\n\t07| ⊚ SERACH INCOME BY SERIATIM"; 
        cout<<"\n\n\t08| ⊚ SERACH EXPENSE BY SERIATIM"; 
		cout<<"\n\n\t09| ⊚ DELETE INCOME BY SERIATIM";
        cout<<"\n\n\t10| ⊚ DELETE EXPENSE BY SERIATIM";
        cout<<"\n\n\t11| ⊚ EDIT INCOME DETAILS BY SERIATIM";
        cout<<"\n\n\t12| ⊚ EDIT EXPENSE DETAILS BY SERIATIM";
		cout<<"\n\n\t13| ⊚ EXIT";
        cout<<"\n\n\tSelect Your Option (1-13)⇨ ";
        cin >> option;

        switch(option) {
        case 1:
            memory.depositeWriteInFile();
            memory.depositeRepeat();
            break;
        case 2:
            memory.withdrawWriteInFile();
            memory.withdrawRepeat();
            break;
        case 3:
            memory.amout();
            break;
        case 4:
            memory.readAll();
            break;
        case 5:
            memory.depositeWithoutDetails();
            break;
        case 6:
            memory.withdrawWithouDetails();
            break;
        case 7:
            memory.searchDep();
            break;
        case 8:
            memory.searchWith();
            break;
        case 9:
            memory.deleteIncome();
            break;
        case 10:
            memory.deleteWithdraw();
            break;
        case 11:
            memory.editDepositeDetails();
            break;
        case 12:
            memory.editWithdrawDetails();
            break;
        case 13:
            cout << "\n\nThank you for using your personal finance application. Have a nice day ☻☺\n\n" << endl;
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
