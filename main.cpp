//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include <fstream>
using namespace std; 

//**********Struct Style *************
struct MenuItem
{
  string name;
  double itemCost; 
  string desc; 
  char addLetter; 
  char removeLetter;
  int count; 
};

//********Class Style***********
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
/////////////////////////////////////////////////////////////////////////////////////////////
//******Struct Style**********
//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Black Tea", "Coffee", "Cappucino", "Macchiato", "Frappucino", "Espresso Shot"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].name = defaultMenuNames[i]; 
    entireMenu[i].addLetter = defaultAddLetters[i]; 
    entireMenu[i].removeLetter = defaultRemoveLetters[i]; 
    entireMenu[i].itemCost = (3.00 + i); //set a random starter cost for each item
    entireMenu[i].count = 0; //initialze all counts to 0
    entireMenu[i].desc = "delicious"; //set all default desc to "delicous"
  }


}
//****Struct Style***
void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "DrT's Effcient Menu" << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].addLetter << ")" << setw(10) << m[i].name 
    << setw(5) << "$" << m[i].itemCost << setw(5) << "(" << m[i].removeLetter
    << ")" << setw(7) << m[i].count << setw(13) << m[i].desc 
    <<endl; 
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////

//***Class Style***********
void populateObjectMenu(vector<MenuItemList> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItemList Item1;  //Item1 is an object
  MenuItemList Item2;
  MenuItemList Item3; 
  MenuItemList Item4;
  MenuItemList Item5;
  MenuItemList Item6;
  MenuItemList Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Black Tea", "Coffee", "Cappucino", "Macchiato", "Frappucino", "Espresso Shot"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 
  vector<string> defaultDesc= {"Decaf","Decaf","95 mg","160 mg","120 mg","100 mg","112 mg"};
  vector <double> defaultPrice = {2.95, 2.50, 2.95,4.95,4.95,5.50,0.95};
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


//******Class Style***
void showObjectMenu(vector<MenuItemList> &m)
{
  system("clear");
  string red = "\x1b[31;1m";
  string headerMenu = "\x1b[45;1m";
  string reset = "\x1b[0m";
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout <<setw(28)<<red<< "FW Drip Brews" <<reset<< endl; 
  cout <<headerMenu<< "ADD     NAME          COST     REMOVE  COUNT    Caffeine  "<<reset<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout <<" "<< m[i].getAddLetter()  << ")  " << setw(15)<<left << m[i].getName() <<right
    << setw(3) << "$" << m[i].getItemCost() << setw(5) << "     (" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << setw(13) << m[i].getDesc() 
    <<endl; 
  }

}



void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0; 

  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].addLetter)
      {
        cout << "\nMenu Item " << m[i].addLetter << " selected."; 
        m[i].count++; //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].name << endl;
        subtotal += m[i].itemCost; //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].removeLetter)
      {
        cout << "\nRemove Item " << m[i].removeLetter << " selected."; 
        if(m[i].count > 0) //subtract if and only if the count is > 0
        {
          m[i].count--; //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].name << endl;
          subtotal -= m[i].itemCost; //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].name << endl;
        }
      }
      else if(
                option != m[i].addLetter && 
                option != m[i].removeLetter &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl; 
  //handle the tip process here
  //calculate total due + tax + tip
  //accept payment type
  //handle cash vs credit
  //handle on-screen recipt generation here
  //handle on the text file reciept generation here
  //loop the program, reset item counts and toatl due
  //until exit
}

void printTextReceipt(vector<MenuItemList> &m)
{
  fstream receipt;
  receipt.open("receipt.txt",ios::out);

  receipt << m[0].getName() <<endl;

  receipt.close();


  fstream html;
  html.open("index.html",ios::out);
  html<< "<html><head><title>Cool</title></head>";
  html <<"<body style =\"background-color:#000000; color: #FFFFFF;\">";
  html << "<h1>"<< m[0].getName() <<endl;
  html << "</body></html>";
  html.close();

}



int main() 
{


  /***Struct Style ******
  vector<MenuItem> wholeMenu; 
  populateMenu(wholeMenu); //put some default values in the menu
  showMenu(wholeMenu); //print the current data of the menu on screen 
  acceptOrder(wholeMenu); 
  */

  //****Class Style*******
  vector <MenuItemList> objectMenu;
  populateObjectMenu (objectMenu); //put some default values in the menu
  showObjectMenu(objectMenu); //show the initial menu on the screen
  //solve and call acceptObjectOrder void function here

   printTextReceipt(objectMenu);

  return 0; 
}