﻿/*
Creator: Joshua Ye
Class: ICS4U1
Date: January 21, 2020
Title: Midterm - Restaurant Management System
Purpose: Restaurant management system that allows the user to display, fill, empty, and modify three types of tables
*/

#include <iostream>
#include <string>
#include <iomanip>
#include<vector>

using namespace std;

// Superclass
class Guests
{
    protected:
        // User's information
        string name;
        int numGuests;
        string comment;
    public:
        // Get and set functions for the user's information
        void setName(string a)
        {
            name = a;
        }
        string getName()
        {
            return name;
        }
        void setNumGuests(int b)
        {
            numGuests = b;
        }
        int getNumGuests()
        {
            return numGuests;
        }
        void setComment(string c)
        {
            comment = c;
        }
        string getComment()
        {
            return comment;
        }
};

// Subclasses for different types of tables: bar, family, and banquet
class Bar : public Guests
{
   public:
        // Constructor of subclass that initializes the variables to store the user's information
        Bar(string x, int y, string z)
            {
                name = x;
                numGuests = y;
                comment = z;
            }
};
class Family : public Guests
{
   public:
        Family(string x, int y, string z)
            {
                name = x;
                numGuests = y;
                comment = z;
            }
};
class Banquet : public Guests
{
   public:
        Banquet(string x, int y, string z)
            {
                name = x;
                numGuests = y;
                comment = z;
            }
};

// Function that asks the user for the amount of bar, family, and banquet tables
int num_Tables(string type, int seats)
{
    int num = 0;

    while (true)
    {
        cout << "The " << type << " table has a max of " << seats << " seats." << endl;
        cout << "Enter the number of " << type << " tables: ";
        cin >> num;
        cout << endl;
           
        if (num < 0 or cin.fail())
        {
            cout << "Enter a valid number of "<< type << " tables" << endl;
        }
       
        else
        {
          cout << endl;
          break;
        }
       
        cin.clear();
        cin.ignore();
    }
    return num;
}

// Function that displays the main menu and asks the user what they want to do
int menu()
{
    cout << "Menu Choices" << endl;
    cout << "1. Display Tables" << endl;
    cout << "2. Fill Table" << endl;
    cout << "3. Empty Table" << endl;
    cout << "4. Modify Table" << endl;
    cout << "5. Exit" << endl << endl;
    cout << "Enter Choice Number: ";
    int input;
    cin >> input;
    cout << endl;

    while (cin.fail() or input > 5 or input < 1)
    {
        cout << endl << "Please enter a number from one to five: ";
        cin.clear();
        cin.ignore();
        cin >> input;
        cout << endl;
    }
    return input;
}

void display()
{
  
}

int main(void)
{
    // Title screen
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$ Ye Restaurant $$$$$$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
   
    // Intro to program
    cout << "Welcome to my restaurant management system, where you can set up tables and coordinate reservations!" << endl << endl;
    
    // Asking users for the amount of tables for each type
    int bar,family,banquet;
    while (true)
    {
        bar = num_Tables("bar", 2);
        family = num_Tables("family", 5);
        banquet = num_Tables("banquet", 10);
       
        if ((bar + family + banquet) == 0)
        {
            cout << "Minimum of 1 table is required!" << endl;
        }
       
        else
        {
            break;
        }
    }

    // Creating the vectors of pointer objects, one for each table type
    vector<Bar*> barList;
    // Filling each table with the default status
    for (int i = 0; i < bar ; i++)
    {
      barList.push_back(new Bar("N/A",0,"Empty table."));
    }
    vector<Family*> familyList;
    for (int i = 0; i < family ; i++)
    {
      familyList.push_back(new Family("N/A",0,"Empty table."));
    }
    vector<Banquet*> banquetList;
    for (int i = 0; i < banquet ; i++)
    {
      banquetList.push_back(new Banquet("N/A",0,"Empty table."));
    }
   
    while(true)
    {
        // Asking the user to input something from the menu
        int input = menu();
        
        switch(input)
        {
          // User chooses 1 - displaying table status
          case 1:
          {
            int tableType;
            // Asking user for what table type they would like to see
            cout << "1. Bar Table" << endl;
            cout << "2. Family Table" << endl;
            cout << "3. Banquet Table" << endl;
            cout << "In which table type would you like to display? ";
            cin >> tableType;
            cout << endl;
            // If user input is not valid
            while (tableType < 0 or tableType > 4 or cin.fail())
            {
                cout << "Invalid input. Please enter a number between one and three: " <<  endl;
                cin.clear();
                cin.ignore();
                cin >> tableType;
                cout << endl;
            }

            // Displaying table statuses based on which table type the user requested
            switch(tableType)
            {
              case 1:
                // Displaying the user's table type, name, number of guests, and comments
                for (int i = 0; i < bar ; i++){
                  cout << "Bar Table " << i+1 << ":" << endl;
                  cout << "Name of reservation - " << barList[i]->getName() << endl;
                  cout << "Number of guests - " << barList[i]->getNumGuests() << " guests" << endl; 
                  cout << "Comments: " << barList[i]->getComment() << endl << endl;

                }
                break;
              case 2:
                for (int i = 0; i < family ; i++){
                  cout << "Family Table " << i+1 << ":" << endl;
                  cout << "Name of reservation - " << familyList[i]->getName() << endl;
                  cout << "Number of guests - " << familyList[i]->getNumGuests() << " guests" << endl;
                  cout << "Comments: " << familyList[i]->getComment() << endl << endl;
                }
                break;
              case 3:
                for (int i = 0; i < banquet ; i++){
                  cout << "Banquet Table " << i+1 << ":" << endl;
                  cout << "Name of reservation - " << banquetList[i]->getName() << endl;
                  cout << "Number of guests - " << banquetList[i]->getNumGuests() << " guests" << endl;
                  cout << "Comments: " << banquetList[i]->getComment() << endl << endl;
                }
                break;
            }
            break;
          }

          // User chooses 2 - fill a table
          case 2:
          {
              // Asking user for information like name, number of guests, type of table, and comments
              string fullName;
              cout << "Enter your full name: ";
              cin.ignore();
              getline(cin,fullName);
              cout << endl;
              int number;
              cout << "Enter the number of guests attending: ";
              cin >> number;
              cout << endl;
              while (cin.fail() or number < 1)
              {
                cout << "Please enter a valid number of guests: ";
                cin.clear();
                cin.ignore();
                cin >> number;
                cout << endl;
              }
              int tableType;
              cout << "1. Bar Table (Max 2 ppl)" << endl;
              cout << "2. Family Table (Max 5 ppl)" << endl;
              cout << "3. Banquet Table (Max 10 ppl)" << endl;
              cout << "What table type would you like? ";
              cin >> tableType;
              cout << endl;

              while (tableType > 3 or tableType < 1)
              {
                cout << "Invalid input Please enter a valid type of table: ";
                cin.clear();
                cin.ignore();
                cin >> tableType;
                cout << endl;
              }

              // If number of guests are greater than the max capacity of the type of table
              while ((tableType == 1 and number > 2) or (tableType == 2 and number > 5) or (tableType == 3 and number > 10))
              {
                  cout << "Invalid type of table for capacity of guests. Please enter a different table type: ";
                  cin >> tableType;
                  cout << endl;
              }

              bool d = false, e = false, f = false;
              // Checking if there are any empty tables
              while (tableType == 1)
              {
                for (int i = 0; i < bar ; i++){
                if (barList[i]->getName()=="N/A" and barList[i]->getNumGuests()==0){
                    d = true;
                    break;
                }
                }
                if (d == true)
                {
                  break;
                }
                cout << "All bar tables are filled. Please choose another type of table: ";
                cin >> tableType;
                cout << endl;
              } 
              while (tableType == 2)
              {
                for (int i = 0; i < family ; i++){
                if (familyList[i]->getName()=="N/A" and familyList[i]->getNumGuests()==0){
                    e = true;
                    break;
                }
                }
                if (e == true)
                {
                  break;
                }
                cout << "All family tables are filled. Please choose another type of table: ";
                cin >> tableType;
                cout << endl;
              } 
              while (tableType == 3)
              {
                for (int i = 0; i < banquet ; i++){
                if (banquetList[i]->getName()=="N/A" and banquetList[i]->getNumGuests()==0){
                    f = true;
                    break;
                }
                }
                if (f == true)
                {
                  break;
                }
                cout << "All family tables are filled. Please choose another type of table: ";
                cin >> tableType;
                cout << endl;
              } 

              string comment;
              cout << "Any comments or special concerns: ";
              cin.ignore();
              getline(cin,comment);
              cout << endl;
              
              bool i = false, j = false, k = false;
              // Filling in an empty table with the user's information depending on table type
              switch (tableType) 
              {
                case 1:
                  for (int i = 0; i < bar; i++)
                  {
                    if (barList[i]->getName()=="N/A" and barList[i]->getNumGuests()==0 and barList[i]->getComment()=="Empty table.")
                    {
                      barList[i]->setName(fullName);
                      barList[i]->setNumGuests(number);
                      barList[i]->setComment(comment);
                      i = true;
                      break;
                    }
                  }
                  break;
                 case 2:
                  for (int i = 0; i < family; i++)
                  {
                    if (familyList[i]->getName()=="N/A" and familyList[i]->getNumGuests()==0 and familyList[i]->getComment()=="Empty table.")
                    {
                      familyList[i]->setName(fullName);
                      familyList[i]->setNumGuests(number);
                      familyList[i]->setComment(comment);
                      j = true;
                      break;
                    }
                  }
                  break;
                case 3:
                  for (int i = 0; i < banquet; i++)
                  {
                    if (banquetList[i]->getName()=="N/A" and banquetList[i]->getNumGuests()==0 and banquetList[i]->getComment()=="Empty table.")
                    {
                      banquetList[i]->setName(fullName);
                      banquetList[i]->setNumGuests(number);
                      banquetList[i]->setComment(comment);
                      k = true;
                      break;
                    }
                  }
                  break;
               }
               // If user successfully made reservation, confirmation message will appear
               if (i == true or j == true or k == true)
               {
                cout << "Thank you for making a reservation!" << endl << endl;
                break;
               }
              cout << endl;
              break;
          }
           
          // User chooses 3 - empty a table
          case 3:
          {
            // Asking user for the type of table and the guest's name to remove
            int tableType;
            cout << "1. Bar Table" << endl;
            cout << "2. Family Table" << endl;
            cout << "3. Banquet Table" << endl;
            cout << "In which table type would you like to empty? ";
            cin >> tableType;
            cout << endl;
            while (tableType < 0 or tableType > 4 or cin.fail())
            {
                cout << "Invalid input. Please enter a number between one and three: ";
                cin.clear();
                cin.ignore();
                cin >> tableType;
                cout << endl;
            }
            string deletedGuest;
            cout << "Enter the full name of the guest you want to remove: ";
            cin.ignore();
            getline(cin,deletedGuest);
            cout << endl;

            bool a = false, b = false, c = false;
            // Emptying the table of the specified guest's name depending on table type
            switch(tableType)
            {
              case 1:
                for (int i = 0; i < bar ; i++){
                if (barList[i]->getName()==deletedGuest){
                    barList[i]->setName("N/A");
                    barList[i]->setNumGuests(0);
                    barList[i]->setComment("Empty table.");
                    a = true;
                    break;
                }
                }
                break;
              case 2:
                for (int i = 0; i < family ; i++){
                if (familyList[i]->getName()==deletedGuest){
                    familyList[i]->setName("N/A");
                    familyList[i]->setNumGuests(0);
                    familyList[i]->setComment("Empty table.");
                    b = true;
                    break;
                }
                }
                break;
              case 3:
                for (int i = 0; i < banquet ; i++){
                if (banquetList[i]->getName()==deletedGuest){
                    banquetList[i]->setName("N/A");
                    banquetList[i]->setNumGuests(0);
                    banquetList[i]->setComment("Empty table.");
                    c = true;
                    break;
                }
                }
                break;
            }
            // If emptying table was successful, display confirmation message
            if (a == true or b == true or c == true)
            {
              cout << "Thank you for removing " << deletedGuest << "'s reservation!" << endl << endl;
              break;
            }
            // If specified guest's name could not be found in the database
            else
            {
              cout << "Sorry we could not find a '" << deletedGuest << "' in out system." << endl << endl;
              break;
            }
          }

          // User chooses 4 - modify a table
          case 4:
          {
            // Asking user for type of table and name of guest to modify
            int tableType;
            cout << "1. Bar Table" << endl;
            cout << "2. Family Table" << endl;
            cout << "3. Banquet Table" << endl;
            cout << "In which table type would you like to modify? ";
            cin >> tableType;
            cout << endl;
            while (tableType < 0 or tableType > 4 or cin.fail())
            {
                cout << "Invalid input. Please enter a number between one and three: ";
                cin.clear();
                cin.ignore();
                cin >> tableType;
                cout << endl;
            }
            string modifyGuest;
            cout << "Enter the full name of the guest you want to modify: ";
            cin.ignore();
            getline(cin,modifyGuest);
            cout << endl;
            // Asking user for new name and new comments
            string newName;
            cout << "Enter the new name of the guest: ";
            getline(cin,newName);
            cout << endl;
            string newComment;
            cout << "Any comments or special concerns: ";
            getline(cin,newComment);
            cout << endl;

            bool l = false, m = false, n = false;
            // Modifying guest information based on new updates
            switch(tableType)
            {
              case 1:
                for (int i = 0; i < bar ; i++){
                if (barList[i]->getName()==modifyGuest){
                    barList[i]->setName(newName);
                    barList[i]->setComment(newComment);
                    l = true;
                    break;
                }
                }
                break;
              case 2:
                for (int i = 0; i < family ; i++){
                if (familyList[i]->getName()==modifyGuest){
                    familyList[i]->setName(newName);
                    familyList[i]->setComment(newComment);
                    m = true;
                    break;
                }
                }
                break;
              case 3:
                for (int i = 0; i < banquet ; i++){
                if (banquetList[i]->getName()==modifyGuest){
                    banquetList[i]->setName(newName);
                    banquetList[i]->setComment(newComment);
                    n = true;
                    break;
                }
                }
                break;
          }
          // If modification was successful, display confirmation message
          if (l == true or m == true or n == true)
          {
            cout << "Thank you for modifying your reservation, " << newName << "!" << endl << endl;
            break;
          }
          // If specified guest's name could not be found
          else
          {
            cout << "Sorry we could not find a '" << modifyGuest << "' in out system." << endl << endl;
            break;
          }
          }

          // User chooses 5 - exit program
          case 5:
          {
            // Thank you message
            cout << "Thank for using my restaurant management system!";
            
            // Clearing up vectors of pointer objects for each table type
            barList.clear();
            barList.shrink_to_fit();
            familyList.clear();
            familyList.shrink_to_fit();
            banquetList.clear();
            banquetList.shrink_to_fit();

            return 0;
          }
        }

    }        
}