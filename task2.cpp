#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

class contact {
    string name;
    string phone;
public:
    contact() {}
    contact(const string& n, const string& p) {
        name = n;
        phone = p;
    }
    string getname() const {
        return name;
    }
    string getphonenumber() const {
        return phone;
    }
    void setname(const string& newname) {
        name = newname;
    }
    void setphone(const string& newphone) {
        phone = newphone;
    }
    friend istream& operator>>(istream& is, contact& contact) {
        cout << "Enter name: ";
        getline(is, contact.name);
        cout << "Enter phone number: ";
        is >> contact.phone;
        is.ignore();
        return is;
    }
    void writetofile(ofstream& file) {
        file << name << " " << phone << endl;
    }
    void readfromfile(const string& line) {
        int spacefind = line.find(" ");
        name = line.substr(0, spacefind);
        phone = line.substr(spacefind + 1);
    }
    void displayformatted() const {
        cout << left << setw(20) << name << right << setw(15) << phone << endl;
    }
};

// Function to add a contact to file
void addContact(const string& filename) {
    contact newContact;
    cin >> newContact;

    ofstream file;
    file.open(filename, ios::app);
    if (file.is_open()) {
        newContact.writetofile(file);
        file.close();
        cout << "Contact added successfully!" << endl;
    }
    else {
        cout << "Error opening file!" << endl;
    }
}

// Function to display all contacts
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
    }
    else {
        cout << "Error opening file!" << endl;
    }
}

// Function to update a contact by name using file operations
void updateContact(const string& filename) {
    string nameToUpdate;
    cout << "Enter the name of the contact to update: ";
    getline(cin, nameToUpdate);

    ifstream file(filename);
    ofstream tempFile("temp.txt");
    if (!file.is_open() || !tempFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    bool contactFound = false;
    contact contact1;

    // Read from original file and write to temporary file with the update
    while (getline(file, line)) {
        contact1.readfromfile(line);
        if (contact1.getname() == nameToUpdate) {
            contactFound = true;
            cout << "Contact found. Enter new details:\n";
            cin >> contact1; // Get new details from the user
        }
        contact1.writetofile(tempFile); // Write the updated contact to temp file
    }

    file.close();
    tempFile.close();

    if (!contactFound) {
        cout << "Contact not found!" << endl;
        remove("temp.txt"); // Remove temp file if no contact was updated
    } else {
        remove(filename.c_str());           // Delete the original file
        rename("temp.txt", filename.c_str()); // Rename temp file to original file
        cout << "Contact updated successfully!" << endl;
    }
}

int main() {
    string filename = "contacts.txt";
    int choice;
    do {
        cout << "\nTelephone Directory Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Update Contact\n";
        cout << "3. Display Contacts\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  
        switch (choice) {
            case 1:
                addContact(filename);
                break;
            case 2:
                updateContact(filename);
                break;
            case 3:
                displayContacts(filename);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
