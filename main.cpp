#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include "House.cpp"

using namespace std;
//vector to store all House
vector<House> house;

void createHouses(){
  // creating vars
  int userOptions;
  char sortOption;
 string h1 = "123 Awesomesauce St.";
 string h2 = "321 Data Ave.";
 string h3 = "500 Semester Rd.";
 string h4 = "1 Sweet Drive";
 int choice;
//each address has info to go with it.

//TO DO: Add more house objects at beginning here instead of during program running
House* house1 = new House(15235,h1,false,175000,2,false,true,false,true);
House* house2 = new House(15212,h2,true,135999,3,true,false,false,true);
House* house3 = new House(15909,h3,false,120899,3,true,false,true,true);
House* house4 = new House(15616,h4,true,201000,4,true,true,true,true);

// pushing these Houses on the list
house.push_back(*house3);
house.push_back(*house1);
house.push_back(*house4);
house.push_back(*house2);

cout << "Number of Houses on list: " << house.size() << '\n';
// printing them out
house[0].printHouseStatus();
house[1].printHouseStatus();
house[2].printHouseStatus();
house[3].printHouseStatus();

cout <<"This is your unsorted list. What would you like to do:"<<'\n';
cout<< "(1) Enter a house"<< '\n';
cout<< "(2) Delete a house" << '\n';
cout<< "(3) Sort by..."<< '\n';

cin >> choice;
//i know this switch should be coverted into three functions I just put all the algos in the switch.
switch (userOptions){
  case '1' : 
House* insertNode(House* hs, House* newHouse = nullptr){
   //creating node to add, checking if it already exists or not
    if (newHouse == nullptr)
    
        string addresses;
        int price;
        cout << "\nEnter the new Property address:-->\n";
        cin >> addy;
        cout << "\nDoes the house have garage?(Y/N) \n";
        cin>> grg
        cout << "\nEnter the list price:-->\n";
        cin >> prc;
        cout<< "\nEnter number of bedrooms:-->";
        cin >> rm;
        cout<< "\nDoes it have a fence?(Y/N)";
        cin >> fnc;
        cout<< "\nIs the listing active?:-->";
        cin>> isActive;
        cout<<"\nDoes this listing have more than one bathroom?(Y/N)\n";
        cin>> bath1plus;
        cout>> "Does it have a basement?(Y/N) "
        cin>> bsmt;

    //If the hs is empty, insert the node as the root
    if (hs == nullptr)
    {
        hs = newHouse;
    }
    else
    {
    compare:
     
        int comparison = newHouse->House.compare(hs->House);
        switch (comparison)
        {
      //check if new house is at beginning of alphabet
        case -1:
            //set the node to the child of the node
            if (hs->childL == nullptr){
                hs->childL = newHouse;
                newHouse->parent = hs;
                cout << "This listing was successfully inserted " << hs->House << "\n";
                break; }
            //Otherwise, set the check node nown a level and try again
            else  {
                hs = hs->childL;
                goto compare;   }
      
        case 1:
            //If the node's left child is a nullptr,
            //set the node to the child of the node
            if (hs->childR == nullptr)
            {
                hs->childR = newHouse;
                newHouse->parent = hs;
                cout << "Listing was successfully inserted " << hs->House << "\n";
                break;   }
            //if not go down level and try again
            else
            { hs = hs->childR;
                goto compare; }
            //if node exists, dont insert.
        case 0:
            cout << "House is already on list. \n";
            break;
        }
    }  //iterate to root of the modified hs before returning the hs
    while (hs->parent != nullptr){
        hs = hs->parent;
    }
  //Return the modified hs
    return hs;

//deleting node option
     case '2':
   TreeNode* deleteNode(TreeNode* tree)

    TreeNode* slated = nullptr;

    string check;
    int comparitor;
    cout << "Which house would you like to delete? (Street name and house number only)\n";
    cin >> check;

    //Look for the node that matches check
navigate1:
    comparitor = check.compare(tree->House);
    switch (comparitor)
    {
        //If the search term is less than the currently observed node
    case -1:
        //If the search ends with no node of the same name
        if (tree->childL == nullptr)
        {
            cout << "Could not find the address you're looking for.\nNothing will be deleted.\n";
            //Iterate back to the top of the tree and exit
            while (tree->parent != nullptr)  {
                tree = tree->parent;  }
            return tree; 
        else {
            tree = tree->childL;
            goto navigate1;  }
    case 1:
        //If cant find node
        if (tree->childR == nullptr) {
            cout << "Could not find the node you are looking for.\nNo node will be deleted.\n";
            //Iterate to top of the tree and exit
            while (tree->parent != nullptr) {
                tree = tree->parent;   }
            return tree;   }
        //Otherwise descend a level
        else  {
            tree = tree->childR;
            goto navigate1;   }
        //When it finds a node of the same name
    case 0:
        slated = tree;
        break; }
    //navigate top of tree
    while (tree->parent != nullptr) {
        tree = tree->parent; }

    TreeNode* orphanL;
    orphanL = slated->childL;
    TreeNode* orphanR;
    orphanR = slated->childR;
    bool orphanLIsNull = false;
    bool orphanRIsNull = false;
    if (orphanL == nullptr) { orphanLIsNull = true; }
    if (orphanR == nullptr) { orphanRIsNull = true; }
    //Decide which node to remove
    tree = slated->parent;
    bool directionIsL;
    if (slated->House.compare(tree->House) == -1) {
        directionIsL = true;
    } else if (slated->House.compare(tree->House) == 1) {
        directionIsL = false; }
    //if slated has no children:
    if (orphanLIsNull && orphanRIsNull) {
        //Depending on which side slated is on, set nullptrs accordingly
        if (directionIsL) {
            tree->childL = nullptr; }
        else if (!directionIsL) {
            tree->childR = nullptr;  }
    }
   else if (!orphanLIsNull && orphanRIsNull) {
   //depending on which side slated is on, link left orphan to parent
        if (directionIsL)  {
            tree->childL = orphanL;  }
        else if (!directionIsL)   {
            tree->childR = orphanL;   }
    }
    //if slated has a right child
    else if (orphanLIsNull && !orphanRIsNull) {
        //depending on which side slated is on, link right orphan to parent
        if (directionIsL) {
            tree->childL = orphanR; }
        else if (!directionIsL) {
            tree->childR = orphanR;  }
    }
    //if slated has two children
    else if (!orphanLIsNull && !orphanRIsNull) {
        //nullify the slated node as above
        if (directionIsL)  {
            tree->childL = nullptr; }
        else if (!directionIsL) {
            tree->childR = nullptr; }
        //Insert the two orphan nodes back into the tree
        while (tree->parent != nullptr)  {
            tree = tree->parent; }

        insertNode(tree, orphanL);
        insertNode(tree, orphanR);
    }
    //navigate back to the top of the tree
    while (tree->parent != nullptr){
        tree = tree->parent; }
    return tree;

     case '3':
 //sorting choice
     cout<<"What would you like to sort by?:"<< '\n';
     cout<< "(L)List Price"<< '\n';
     cout<< "(B)edrooms"<<'\n';
     cin>> sortOption;
    if (sortOption=='L'){
      sort(house.begin(),house.end(),[](const House& listPrice,const House& liPrice){
      return listPrice.key < liPrice.key;
      
       else if(sortOption == 'B'){
 sort(house.begin(),house.end(),[](const House& amtRooms,const House& amtRooms){
      return amtRooms.key < amtRooms.key;}
      }
   });
house[0].printHouseStatus();
house[1].printHouseStatus();
house[2].printHouseStatus();
house[3].printHouseStatus();
    }
  // sorting through House
sort(house.begin(),house.end(),[](const House& lhs,const House& rhs){
      return lhs.key < rhs.key;
   });
house[0].printHouseStatus();
house[1].printHouseStatus();
house[2].printHouseStatus();
house[3].printHouseStatus();
      }
    }
  }
}
int main() {

 createHouses();
}

