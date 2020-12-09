#include<string>
#include<iostream>

using namespace std;
//creating a class of house objects by using getters and setters
class House{
  
  public:
  
  int key;
     House
    (int ky,string addy, bool grg, int prc, int rm, bool fnc, bool actv, bool bath1plus, bool bsmt)

      :key{ky}, address{addy}, hasGarage{grg}, listPrice{prc}, amtRooms{rm}, isFenced{fnc},isActive{actv}, over1bathroom{bath1plus},hasbsmt{bsmt} 
       // set children nodes to nullptr

    House* parent;
    string value; // the searchable value
    int val_mw; // the payload of the node
    House* childL;
    House* childR;

   childL=nullptr;
        childR=nullptr;
   //setting and getting all things for house class

    void setkey(int ky){
      this->key = ky;
    }
    int getkey(){
      return key;
    }
    void setaddy(string addy){
      this-> address = addy;
    }
    string getaddy(){
      return address;
    }
    void sethasGarage(bool grg){
      this->hasGarage = grg;
    }
    bool getgrg(){
      return hasGarage;
    }
     void setlistPrice(int prc){
      this->listPrice = prc;
    }
    int getlistPrice(){
      return listPrice;
    }
     void setamtRooms(int rm){
      this->amtRooms = rm;
    }
    int getamtRoom(){
      return amtRooms;
    }
     void setisFenced(bool fence){
      this->isFenced = fence;
    }
    bool getfence(){
      return isFenced;
    }
     void setactive(bool active){
      this->isActive = active;
    }
    bool getactive(){
      return isActive;
    }
     void setbath1plus(bool bath1plus){
      this->over1bathroom = bath1plus;
    }
    bool getbath1Plus(){
      return over1bathroom;
    }
     void sethasbsmt(bool bsmt){
      this->hasbsmt = bsmt;
    }
    bool getbsmt(){
      return hasbsmt;
    }
  //printing all things in each house node linked list
    void printHouseStatus(){
        cout << "*****************************"<< '\n';
       
        cout << "Address: " << address << '\n';
        cout << "Garage: " << hasGarage << '\n';
        cout << "ListPrice: " << listPrice << '\n';
        cout << "Bedrooms: " << amtRooms << '\n';
        cout << "Fence: " << isFenced << '\n';
        cout << "Is listing Active: " << isActive << '\n';
        cout << "More than 1 bathroom: " <<over1bathroom << '\n';
        cout << "Basement: " << hasbsmt << '\n'; 
    }
  private:
  string address;
  bool hasGarage;
  int listPrice; 
  int amtRooms;
  bool isFenced;
  bool isActive;
  bool over1bathroom;
  bool hasbsmt;
};