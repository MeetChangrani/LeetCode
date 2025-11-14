#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;
class contact{
    string name;
    string phone;
public:
    contact(){}
    contact(const string n,const string p)
    {
        name=n;
        phone=p;
    }
    string getname()
    {
        return name;
    }
    string getphonenumber()
    {
        return phone;

    }
    friend istream& operator>>(istream &is,contact &contact)
    {
        cout<<"enter name";
        getline(is,contact.name);
        cout<<"enter phone number :";
        is>>contact.phone;
        is.ignore();
        return is;
    }
    void writetofile(ofstream &file)
    {
        file<<name<<" "<<phone<<endl;
    }
    void readfromfile(const string& line){
        int spacefind = line.find(" ");
        name=line.substr(0,spacefind);
        phone=line.substr(1,spacefind);
    }
    void displayformatted()
    {
        cout<<left<<setw(20)<<name<<right<<setw(15)<<phone<<endl;
    }
};
void addContact(const string& filename) {
    contact newContact;
    cin>>newContact;

    ofstream file;
    file.open(filename, ios::app);  
    if (file.is_open()) {
        newContact.writetofile(file);
        file.close();
        cout << "Contact added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}
void displayContacts(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        contact contact1;
        cout << left << setw(20) << "Name" << right << setw(15) << "Phone Number" << endl;
        cout << "--------------------------------------------" << endl;
        while (getline(file, line)) {
            contact1.readfromfile(line);
            contact1.displayformatted();
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}
int main(){
   
    string filename = "contacts.txt";
    int choice;
    do {
        cout << "\nTelephone Directory Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  
        switch (choice) {
            case 1:
                addContact(filename);
                break;
            case 2:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 2);

    return 0;
}



