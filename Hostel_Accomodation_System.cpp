#include <iostream> // Input-output stream
#include <fstream> // File stream
#include <windows.h> // Windows-specific functions
#include <sstream> // String stream for conversions
using namespace std;

class Hostel{

    private:
        string Name; // Name of the hostel
        int Rent, Bed; // Rent and number of beds
    public:
        // Constructor to initialize hostel details
        Hostel(string name, int rent, int bed)
        {
            Name = name;
            Rent = rent;
            Bed = bed;
        }

    // Getter functions for hostel attributes
    string getName() // Returns the name of the hostel
    {
        return Name;
    }

    int getRent() // Returns the rent of the hostel
    {
        return Rent;
    }

    int getBed() // Returns the number of available beds
    {
        return Bed;
    }

    // Function to reserve a bed in the hostel
    reserve()
    {
        // Opening input and output file streams
        ifstream in("D:/Hostel.txt");
        ofstream out("D:/Hostel Temp.txt");

        string line;
        // Reading each line from input file
        while(getline(in,line))
            {
                // Finding the hostel name in the line
                int pos = line.find("3star");
                // If hostel name found
                if(pos != string::npos)
                {
                    // Decrease the bed count by 1
                    int bed = Bed-1;
                    Bed = bed;
                    // Convert bed count to string
                    stringstream ss;
                    ss<<bed;
                    string strBed = ss.str();
                    // Find position to replace bed count in the line
                    int bedPos = line.find_last_of(':');
                    line.replace(bedPos+1, string::npos, strBed);
                }
                // Write updated line to output file
                out<<line<<endl;
            }

        // Close file streams
        out.close();
        in.close();
        // Remove original file and rename temporary file
        remove("D:/Hostel.txt");
        rename("D:/Hostel Temp.txt", "D:/Hostel.txt");
        // Print reservation success message
        cout<<"\tBed Reserved Successfuly!"<<endl;
    }
};

class Student{

    private:
        string Name, RollNo, Address; // Student details: name, roll number, address
    public:
        // Default constructor to initialize student details
        Student()
        {
            Name="";
            RollNo="";
            Address="";
        }

    // Setter functions for student attributes
    setName(string name) // Set student name
    {
        Name = name;
    }

    setRollNo(string rollNo) // Set student roll number
    {
        RollNo = rollNo;
    }

    setAddress(string address) // Set student address
    {
        Address = address;
    }

    // Getter functions for student attributes
    string getName() // Get student name
    {
        return Name;
    }

    string getRollNo() // Get student roll number
    {
        return RollNo;
    }

    string getAddress() // Get student address
    {
        return Address;
    }

};

// Main function to run the program
int main(){

    // Create a Hostel object with initial details
    Hostel h("3star", 5000, 2);
    // Open a file stream to save hostel data
    ofstream out("D:/Hostel.txt");
    // Write hostel details to the file
    out<<"\t"<<h.getName()<<" : "<<h.getRent()<<" : "<<h.getBed()<<endl<<endl;
    // Print confirmation message
    cout<<"Hostel Data Saved"<<endl;
    // Close file stream
    out.close();

    // Create a Student object
    Student s;

    // Boolean variable to control the loop
    bool exit = false;

    // Main menu loop
    while(!exit)
        {
            // Clear the console screen
            system("cls");
            int val;
            // Print menu options
            cout<<"\tWelcome To Hostel Accommodation System"<<endl;
            cout<<"\t**************************************"<<endl;
            cout<<"\t1.Reserve A Bed."<<endl;
            cout<<"\t2.Exit."<<endl;
            cout<<"\tEnter Choice: ";
            // Read user choice
            cin>>val;

            // If user chooses option 1 (Reserve A Bed)
            if(val==1)
            {
                // Clear the console screen
                system("cls");
                string name,rollNo, address;
                // Prompt user to enter student details
                cout<<"\tEnter Name of Student: ";
                cin>>name;
                s.setName(name);

                cout<<"\tEnter RollNo of Student: ";
                cin>>rollNo;
                s.setRollNo(rollNo);

                cout<<"\tEnter Address of Student: ";
                cin>>address;
                s.setAddress(address);

                // Check if beds are available in the hostel
                if(h.getBed() > 0)
                {
                    // Reserve a bed in the hostel
                    h.reserve();
                }

                // If no beds are available
                else if(h.getBed() ==0)
                {
                    // Print message that no beds are available
                    cout<<"\tSorry, Bed Not Available!"<<endl;
                }

                // Open file stream to save student data
                ofstream outFile("D:/Student.txt", ios::app);
                // Write student details to the file
                outFile<<"\t"<<s.getName()<<" : "<<s.getRollNo()<<" : "<<s.getAddress()<<endl<<endl;
                // Pause execution for 5 seconds
                Sleep(5000);
            }

            // If user chooses option 2 (Exit)
            else if(val==2)
            {
                // Clear the console screen
                system("cls");
                // Set exit flag to true to terminate the loop
                exit = true;
                // Print farewell message
                cout<<"Good Luck!"<<endl;
                // Pause execution for 3 seconds
                Sleep(3000);
            }
        }
}
