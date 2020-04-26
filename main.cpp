/*
Author: Jesus Cardenas
Date: 4/26/2020
Teacher: Dr. Tyson McMillan

A coffee shop check out menu created by translating a struct program to an object oriented
program, then creating all functions to get input and checking out as well as printing a ticket
*/



#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include <fstream>
#include <unistd.h> 
#include "Input_Validation_Extended.h"
using namespace std; 


//Creating a class for menu items
class MenuItemList
{
  private:
    string name;
    double itemCost;
    string desc;
    char addLetter;
    char removeLetter;
    int count;
  public:
    void setName(string n) { name = n; }
    void setItemCost(double iT) {itemCost = iT; }
    void setDesc(string d) {desc = d; }
    void setAddLetter(char aL) { addLetter = aL; }
    void setRemoveLetter (char rL) { removeLetter = rL; }
    void setCount(int c )  { count = c; }
    string getName () const { return name; }
    double getItemCost () const { return itemCost; }
    string getDesc() const { return desc; }
    char getAddLetter() const { return addLetter; }
    char getRemoveLetter () const { return removeLetter; }
    int getCount () const { return count; }

    //void print () // print menu item data on demand



};

//Global variables for color
 
  string headerRed = "\x1b[31;1m";
  string headerMenu = "\x1b[45;1m";
  string reset = "\x1b[0m";
  string errorColor = "\x1b[41;1m";
  string red = "\x1b[" + to_string(32) + ";"+to_string(91)+"m";

//Global variable for user option and sub-total
  double total = 0.0;
  double subtotal = 0.0; 
  double const tax = 0.0825;
  double tip = 0.0;
  double payment=0.0;
 

  


//Creating menu items using vectors
void populateObjectMenu(vector<MenuItemList> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; //Number of menu items
  MenuItemList Item1;  //Item1 is an object
  MenuItemList Item2;
  MenuItemList Item3; 
  MenuItemList Item4;
  MenuItemList Item5;
  MenuItemList Item6;
  MenuItemList Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); 
  entireMenu.push_back(Item3); 
  entireMenu.push_back(Item4); 
  entireMenu.push_back(Item5); 
  entireMenu.push_back(Item6); 
  entireMenu.push_back(Item7); 

  //Menu Item Names
  vector<string> defaultMenuNames = {"Green Tea", "Black Tea", "Coffee", "Cappucino", "Macchiato", "Frappucino", "Espresso Shot"}; 
  
  //Menu Add choices
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 

  //Menu Remove letter choices
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  //Caffeine level
  vector<string> defaultDesc= {"Decaf","Decaf","95 mg","160 mg","120 mg","100 mg","112 mg"};

  //Prices
  vector <double> defaultPrice = {2.95, 2.50, 2.95,4.95,4.95,5.50,0.95};
  
  //Loop to add all values into vector
  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter (defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setItemCost (defaultPrice[i]); 
    entireMenu[i].setCount(0); //initialze all counts to 0
    entireMenu[i].setDesc (defaultDesc[i]); //set all default desc to "delicous"
  }


}

//Menu visible to user
void showObjectMenu(vector<MenuItemList> &m)
{
  system("clear");
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout <<setw(28)<<headerRed<< "FW Drip Brews" <<reset<< endl; 
  cout<<"\t\tFort Worth's only hipster-free coffee shop"<<endl;
  cout <<headerMenu<< "ADD     NAME          COST     REMOVE  COUNT    Caffeine  "<<reset<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout <<headerMenu<<" "<< m[i].getAddLetter()  << ")"<<reset<<"  " << setw(15)<<left << m[i].getName() <<right
    << setw(3) << "$" << m[i].getItemCost() << setw(5) << "     (" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << setw(13) << m[i].getDesc() 
    <<endl; 
  }

}


//Function to obtain the menu order.
void acceptObjectOrder(vector<MenuItemList> &m)
{
  char option = '\0';// the user-selected menu item
  //Obtaining menu order from user.
  do
  {
    
    cout << red << "\n(X TO PLACE ORDER)"<<reset<<" \nPlease choose an item : ";
    cin >> option; 

    for(int i=0; i <m.size(); i++)
    {
      if(option == m[i].getAddLetter())
      {
        cout << "\nMenu Item " << m[i].getAddLetter() << " selected."; 
        int addCounter= m[i].getCount()+1;
        m[i].setCount(addCounter); //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getItemCost(); //increment the subtotal by the cost of the item 
        showObjectMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRemoveLetter())
      {
        
        if(m[i].getCount() > 0) //subtract if and only if the count is > 0
        {
          int removeCounter = m[i].getCount()-1;
          m[i].setCount(removeCounter); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getItemCost(); //decrement the subtotal by the cost of the item
          showObjectMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << errorColor<<"Item count must be > 0 to remove: " << m[i].getName() <<reset<< endl;
        }
      }
      else if(
                option != m[i].getAddLetter() && 
                option != m[i].getRemoveLetter() &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout <<errorColor<< "\nInvalid input (" << option << "). Please try again." <<reset<<endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  
  system("clear");
}

void tipProcess()
{ cout <<setprecision(2);
  int tipOption;
  
 
    cout<<headerMenu <<"        Would you like to leave a tip?        "<<reset<<endl;
    cout<<setw(5)<<"(0)"<<setw(10)<<" (1) "<<setw(10)<<" (2) "<<setw(10)<<" (3) "<<setw(10)<<"(4)  "<<endl;
    cout<<setw(5)<<"0%"<<setw(10)<<" 15% "<<setw(10)<<" 20% "<<setw(10)<<" 25% "<<setw(10)<<"custom"<<endl;
    cout<<setprecision(2)<<setw(5)<<"0 "<<setw(10)<<(subtotal*.15)<<setw(10)<<(subtotal*.20)<<setw(10)<<(subtotal*.25)<<endl<<endl;

    do
    {
      cout<< "Please make a selection ("<<red<<"0,1,2,3,4"<<reset<<"): "<<red;
      tipOption = validateInt(tipOption); //Verifing that the user uses an int
      cout<<reset;
      

    
         //if loop to check user tip selection
          if (tipOption==0){tip=0.0;}
          else if  (tipOption==1){tip=subtotal*.15;}
          else if  (tipOption==2){tip=subtotal*.20;}
          else if  (tipOption==3){tip=subtotal*.25;}
          else if  (tipOption==4){  
                                      int customTip;
                                      cout<<"\nWhat percentage would you like to leave? (whole number)"<<endl;
                                      customTip=validateInt(customTip);
            
                                      tip=(customTip/100.0)*subtotal;}
            else {
                  cout<<errorColor<<"That's not a valid answer."<<reset<<endl<<endl;

                 }

    } while(tipOption != 0 && tipOption != 1 && tipOption != 2 && tipOption != 3 && tipOption != 4);



}

void calculateBill()
{
  cout <<setprecision(2);
  system("clear");
  cout<<headerMenu <<"               Total Due               "<<reset<<endl;
  
  cout << "\n  Subtotal: " <<subtotal<<endl;
  cout << "  Tax: " <<(subtotal*tax)<<endl;
  cout << "  Tip: " <<tip<<endl<<endl;
  cout << "  Total: "<<total<<endl;


}



  ////////accept payment type//////////////
  void cashFunction()
  {
    cout <<setprecision(2); 
    system ("clear");
    cout<<headerMenu<<"     What is the tendered amount?     "<<reset<<endl;
    cout <<" $ ";
    payment = validateDouble(payment);

    //Making sure we are paid fully.
    while (payment<total)
       {

         cout <<"\nAn amount of $"<<red<< (total-payment)<<reset<<" is due. ";
         cout<<"\nWhat is the "<<red<<"NEW"<<reset<< " total tendered amount? ";
         payment = validateDouble(payment);
       }
    
    //If user paid more than owed, then this will run.
    if (payment> total)
      {
        cout <<"\nYour change is: " <<red<<(payment-total)<<reset<<endl;
      }
    else if (payment == total)
     {
      cout <<"\nThank you for your business.";
     }
    else 
      cout << "How did you break my code?";

    cout<<"\n\nPrinting receipt"<<endl;
      sleep(5); //pause 3 seconds.

  }



  
  void creditFunction () 
    {
      string creditCard;
      system ("clear");
      cout <<headerMenu<< "                   Credit Card                  "<<reset<<endl;
      cout << "Please type the 16 digits on the front of the CC"<<endl;
      cout<<red<<"#";
      cin >> creditCard;
      cout<<reset;
      while (creditCard.length()!=16)
      {

        cout <<"\nYou entered a wrong credit card number, please try again."<<endl;
        cout<<red<<"#";
        cin >> creditCard;
        cout<<reset;
      }

      cout<<"Contacting bank..."<<endl;
      sleep(3); //pause 3 seconds. 

      cout<<"connected..."<<endl;
      sleep(3); //pause 3 seconds. 

      cout<<"processing..."<<endl;
      sleep(3); //pause 3 seconds. 

      cout<<"Payment accepted"<<endl;
      sleep(3); //pause 3 seconds.

      cout<<"Printing receipt"<<endl;
      sleep(3); //pause 3 seconds.

    }



  //handle on-screen recipt generation here
  void printTextReceipt(vector<MenuItemList> &m)
  {
    cout <<setprecision(2);
    //Creating and opening a txt file called receipt.txt
    fstream receipt;
    receipt.open("receipt.txt",ios::out);

    //Creating header
     receipt<<"\t\t\tFW Drip Brews"<<endl;
     receipt <<"Fort Worth's only hipster-free coffee shop"<<endl;
     receipt <<"******************************************"<<endl;
     receipt <<"\t\t\tItems purchased"<<endl;
     receipt <<"******************************************"<<endl;

    //Will check vector size and will display all purchased items
    for(int i = 0; i < m.size(); i++)
    {
    
      if(m[i].getCount()>0)
      {
        //Shows count followed by name
        receipt <<"\t"<< m[i].getCount() <<"\t"<< m[i].getName()<<endl;
       
      }
    }
  //display total for user's record
    receipt << "\n\t  Subtotal: " <<subtotal<<endl;
    receipt << "\t  Tax: " <<(subtotal*tax)<<endl;
    receipt << "\t  Tip: " <<tip<<endl<<endl;
    receipt << "\t  Total: "<<total<<endl;

    receipt <<"******************************************"<<endl;
    receipt<<"\tLike us on facebook @FWDripBrews"<<endl;
    receipt <<"******************************************"<<endl;
        
    receipt.close();


        
  }

//showing the ticket to the user on the screen
  void showReceipt(vector<MenuItemList> &m)
  {
    cout <<setprecision(2);
    system("clear");
   

    //Creating header
    cout <<setw(20)<<headerRed<< "FW Drip Brews" <<reset<< endl; 
    cout<<"\tFort Worth's only hipster-free coffee shop"<<endl;
    cout <<headerMenu<< "**********************************************"<<reset<<endl;
    cout <<"\t\t\tItems purchased"<<endl;
    cout <<headerMenu<< "**********************************************"<<reset<<endl;

    //Will check vector size and will display all purchased items
    for(int i = 0; i < m.size(); i++)
    {
    
      if(m[i].getCount()>0)
      {
        //Shows count followed by name
        cout <<"\t"<< m[i].getCount() <<"\t"<< m[i].getName()<<endl;
       
      }
    }
  //display total for user's record
    cout << "\n  Subtotal: " <<subtotal<<endl;
    cout << "  Tax: " <<(subtotal*tax)<<endl;
    cout << "  Tip: " <<tip<<endl<<endl;
    cout << "  Total: "<<total<<endl;

    cout <<headerMenu<< "**********************************************"<<reset<<endl;
    cout<<"\t\tLike us on facebook @FWDripBrews"<<endl;
    cout <<headerMenu<< "**********************************************"<<reset<<endl;
       
            
  }








/********************Main function*************************/
int main() 
{
  cout <<setprecision(2);
  int payOption;
  char answer = '\0';
 do
 {
    vector <MenuItemList> objectMenu;
    populateObjectMenu (objectMenu); //put some default values in the menu
    showObjectMenu(objectMenu); //show the initial menu on the screen
    acceptObjectOrder(objectMenu);//Function that obtains the user's order
    tipProcess();  //Function that asks and calculates tip
    
    
    //Calculating total by calling global variables
    total = (subtotal*tax)+ subtotal + tip;

    //function that calculates the bill and displays it for the user.
    calculateBill();
    
    //Obtaining payment method from user
      cout << headerMenu<< "\n\n      How would you like to pay?       "<<reset<<endl<<endl
          << "(1) Cash " <<endl
          << "(2) Credit Card"<<endl;

      cout << "Choice:";
      payOption = validateInt(payOption);

      //Calling the option needed to process payment
        if (payOption == 1) {cashFunction(); }
        else if (payOption ==2) {creditFunction(); }
        else {
          
            do 
            {
                  if (payOption == 1) {cashFunction(); }
                  else if (payOption ==2) {creditFunction(); }
                    else {
                  cout <<endl<<errorColor<< "Thats not a valid choice"<<reset<<endl;
                  cout << "Please enter a valid choice";
                  payOption = validateInt(payOption);
                  }
            } while (payOption != 1 && payOption !=2 );

        }


    showReceipt(objectMenu); //Showing the same text as the receipt but on screen.
    printTextReceipt(objectMenu);
      

      cout << "\nPress E to end program." << endl; 
      cout << "\nPress any other key to restart."<<endl;
      cin >> answer;
    

  } while (answer != 'E' && answer != 'e');

  
  
  return 0; 
}