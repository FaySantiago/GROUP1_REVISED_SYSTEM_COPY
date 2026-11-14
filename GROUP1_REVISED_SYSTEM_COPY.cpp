#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

const string RED    = "\033[31m";
const string GREEN  = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE   = "\033[34m";
const string CYAN   = "\033[36m";
const string RESET  = "\033[0m";
//new calculation
int tally(int seniorDiscount[], int numOfPeople){

    int total = 0;

    for(int i = 0; i < numOfPeople; i++){
        total += seniorDiscount[i];

    }

    return total;
}
int nightCost(int roomCost, int numOfNights) {
    return ((numOfNights - 1) * roomCost);
}

int foodItems(string foodChoice, int pancake, int tapsilog, int longsilog, int bacsilog, int sinigang, int adobo, int kares, int fillet, int burger, int pasta, int beef, int seafood, int foodAmount[4]) {
    if(foodChoice == "1"){
        return (pancake*foodAmount[0]) + (tapsilog*foodAmount[1]) + (longsilog*foodAmount[2]) + (bacsilog*foodAmount[3]);
    }
    else if(foodChoice == "2"){
        return (sinigang*foodAmount[0]) + (adobo*foodAmount[1]) + (kares*foodAmount[2]) + (fillet*foodAmount[3]);
    }
    else{
        return (burger*foodAmount[0]) + (pasta*foodAmount[1]) + (beef*foodAmount[2]) + (seafood*foodAmount[3]);
    } 
}

int treatItems(int hotstone, int aroma, int facial, int sauna){
    return hotstone + aroma + facial + sauna;
}

int serviceCost(int roomServiceCost, int foodServiceCost, int spaCost) {
    return (roomServiceCost + foodServiceCost + spaCost);
}

int totalBill(int roomCost, int numOfNights, int numOfPeople, int roomServiceCost, int foodServiceCost, int spaCost, int seniorDiscount[]) {
    return nightCost(roomCost, numOfNights) + serviceCost(roomServiceCost, foodServiceCost, spaCost) + tally(seniorDiscount, numOfPeople); 
}

void displayBreakfastMenu(int ITEM_WIDTH){
    cout << endl;
    cout << CYAN;
    cout << "================ BREAKFAST MENU ================\n";
    cout << RESET;
    cout << left << setw(ITEM_WIDTH) << "Pancakes:" << "P130" << endl;
    cout << left << setw(ITEM_WIDTH) << "Tapsilog:" << "P200" << endl;
    cout << left << setw(ITEM_WIDTH) << "Longsilog:" << "P230" << endl;
    cout << left << setw(ITEM_WIDTH) << "Bacsilog:" << "P250" << endl;
    cout << endl;
    cout << "Select the items you would like to order." << endl;
    cout << "--------------------------------------------------" << endl;
}

void displayLunchMenu(int ITEM_WIDTH){
    cout << endl;
    cout << CYAN;
    cout << "================ LUNCH MENU ================\n";
    cout << RESET;
    cout << left << setw(ITEM_WIDTH) << "Sinigang na Sugpo:" << "P600" << endl;
    cout << left << setw(ITEM_WIDTH) << "Pork Adobo:" << "P750" << endl;
    cout << left << setw(ITEM_WIDTH) << "Kare Kare:" << "P530" << endl;
    cout << left << setw(ITEM_WIDTH) << "Chicken Fillet:" << "P170" << endl;
    cout << endl;
    cout << "Select the items you would like to order." << endl;
    cout << "--------------------------------------------------" << endl;
}

void displayDinnerMenu(int ITEM_WIDTH){
    cout << endl;
    cout << CYAN;
    cout << "================ DINNER MENU ================\n";
    cout << RESET;
    cout << left << setw(ITEM_WIDTH) << "Burger Steak with Mashed Potatoes:" << "P1150" << endl;
    cout << left << setw(ITEM_WIDTH) << "Pasta Bolognese:" << "P540" << endl;
    cout << left << setw(ITEM_WIDTH) << "Beef Bulalo:" << "P950" << endl;
    cout << left << setw(ITEM_WIDTH) << "Seafood Chowder:" << "P830" << endl;
    cout << endl;
    cout << "Select the items you would like to order." << endl;
    cout << "--------------------------------------------------" << endl;
}

void printHeader(string title)
{
    cout << CYAN;
    cout << "\n==================================================\n";
    cout << title << endl;
    cout << "==================================================\n";
    cout << RESET;
    cout << endl;
}

void successMessage(string message)
{
    cout << GREEN;
    cout << endl;
    cout << "[SUCCESS] "
         << message
         << endl;
    cout << endl;
    cout << RESET;
}

void displayRoomCatalogue()
{
    const int width = 30;
    cout << left << GREEN << "[1] MEDIUM" << RESET << setw(25) << RED << "[2] LARGE" << RESET << setw(25) << YELLOW << "[3] LUXURIOUS" << RESET << endl;
    cout << setw(width) << "Rate: Php 100" << setw(width) << "Rate: Php 250" << setw(width) << "Rate: Php 500" << endl;
    cout << setw(width) << "- Room Service" << setw(width) << "- Room Service" << setw(width) << "- Room Service" << endl;
    cout << setw(width) << "" << setw(width) << "- Food Service" << setw(width) << "- Food Service" << endl;
    cout << setw(width) << "" << setw(width) << "" << setw(width) << "- Private Spa Service" << endl;
}

//new method and function

int roomServiceYes(){
    cout << endl;
    cout << GREEN;
    cout << "[SUCCESS] Room service availed." << endl;
    cout << RESET;
    cout << endl;
    return 30;
}
void roomServiceNo(){
    cout << RED;
    cout << "You declined room service." << endl;
    cout << RESET;
}

void invalidInput(){
    cout << RED;
    cout << "Not valid input." << endl;
    cout << RESET;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void SpaDisplay(int ITEM_WIDTH){
    cout << endl;
    cout << CYAN;
    cout << "================ SPA TREATMENTS ===============\n";
    cout << RESET;
    cout << left << setw(ITEM_WIDTH) << "Hot Stone Treatment:" << "P999" << endl;
    cout << left << setw(ITEM_WIDTH) << "Aromatherapy Treatment(P789):" << "P789" << endl;
    cout << left << setw(ITEM_WIDTH) << "Facial Treatments(P1599):" << "P1599" << endl;
    cout << left << setw(ITEM_WIDTH) << "Sauna(1399):" << "P1399" << endl;
    cout << CYAN;
    cout << "=================================================";
    cout << RESET;
    cout << endl;
    cout << "Select the treatments you would like to order." << endl;
    cout << "--------------------------------------------------" << endl;
}


int main(){
    const int ITEM_WIDTH = 35;
    string resrv;
    string choice;
    string confirm;
    bool confirmcheck = false;
    bool chosen = false;
    string chosenRoom = "";
    int roomCost = 0;
    int numOfNights = 0;
    int numOfPeople;
    // new datatype v
    string nameofPerson[8];
    // inicialize your values but leaving {} blank, or giving the numbers value
    // = {1,2,3,4} for example for array[0] array[1] and so on
    int ageofPerson[8] = {};
    bool agecheck = false;
    

    string services;
    string roomService;
    string foodService;
    string foodChoice;
    bool foodOptions = false;
    bool roomCheck = false;
    bool spaCheck = false;
    bool reservCheck = false;
    bool nightCheck = false;
    bool peopleCheck = false;
    
    string breakfast[4];
    breakfast[0] = "Pancakes(P130)";
    int pancakes = 0;
    int pancakesum;
    breakfast[1] = "Tapsilog(P200)";
    int tapsilog = 0;
    int tapsilogsum;
    breakfast[2] = "Longsilog(P230)";
    int longsilog = 0;
    int longsilogsum;
    breakfast[3] = "Bacsilog(P250)";
    int bacsilog = 0;
    int bacsilogsum;
    

    string lunch[4];
    lunch[0] = "Sinigang na Sugpo(P600)";
    int sinigang = 0;
    int sinigangsum;
    lunch[1] = "Pork Adobo(P750)";
    int adobo = 0;
    int adobosum;
    lunch[2] = "Kare Kare(P530)";
    int kare = 0;
    int karesum;
    lunch[3] = "Chicken fillet(P170)";
    int fillet = 0;
    int filletsum;

    string dinner[4];
    dinner[0] = "Burger Steak with Mashed Potatoes(P1150)";
    int burger = 0;
    int burgersum;
    dinner[1] = "Pasta Bolognese(P540)";
    int pasta = 0;
    int pastasum;
    dinner[2] = "Beef Bulalo(P950)";
    int beef = 0;
    int beefsum;
    dinner[3] = "Seafood Chowder(P830)";
    int seafood = 0;
    int seafoodsum;
    string foodChosen[4];
    //all new data types for food menu
    bool ordervalid = false;
    int foodAmount[4] = {};
    string finishOrder;
    bool orderCheck = false;
    string orderChecks [4];
    bool moreOrder = false;
    string orderMore;
    bool foodConfirmed = false;
    string foodConfirmation;
    
    string spa;
    string treatments[4];
    string treatChosen[4];
    treatments[0] = "Hot Stone Treatment(P999)";
    int hotstone = 0;
    treatments[1] = "Aromatherapy Treatment(P789)";
    int aroma = 0;
    treatments[2] = "Facial Treatments(P1599)";
    int facial = 0;
    treatments[3] = "Sauna(1399)";
    int sauna = 0;
    //all new spa data types v
    bool orderTreat = false;
    bool treatValid = false;
    string finishTreat;
    bool moreSpa = false;
    string spaMore;
    bool spaConfirmed = false;
    string spaConfirmation;
    bool spaYesorNo = false;

    int roomServiceCost = 0;
    int foodServiceCost = 0;
    int spaCost = 0;

    printHeader("         THE ASTRAL SUITE HOTEL RESERVATION");
    cout << "Welcome to The Astral Suite Hotel. We look forward to serving you!" << endl;
    cout << "Would you like to make a reservation?\n" << endl;
    cout << endl;
    cout << YELLOW;
    cout << "Enter 'y' to make a reservation or 'n' to exit the program: ";
    cout << RESET;

    do {
        cin >> resrv;
        cout << endl;

        if (resrv == "y" || resrv == "Y") {
        const int width = 30;

        cout << "\n";
        cout << CYAN;
        cout << string(90, '=') << endl;
        cout << setw(50) << "ROOM CATALOGUE" << endl;
        cout << string(90, '=') << endl;
        cout << RESET;
        displayRoomCatalogue();
        cout << CYAN;
        cout << string(90, '=') << endl;
        cout << RESET;
        break;

        } else if (resrv == "n" || resrv == "N") {
            cout << "Thank you for checking out The Astral Suite Hotel. We hope to see you soon!" << endl;
            cout << "========================================" << endl;
            return 0;
        } else {
            cout << RED;
            cout << "Not valid choice. Try again." << endl;
            cout << RESET;
        }
    } while (true);
    
    srand(time(0));
    int medAvailable = (rand() % 51);
    int larAvailable = (rand() % 31);
    int luxAvailable = (rand() % 11);
    
    cout << endl;
    printHeader ("             ROOM AVAILABILITY TODAY");
    cout << "Medium rooms available: " << medAvailable << endl;
    cout << "Large rooms available: " << larAvailable << endl;
    cout << "Luxurious rooms available: " << luxAvailable << endl;
    cout << " " << endl;


    do {
        
        confirmcheck = false;
        cout << endl;
        printHeader("                 CHOOSE YOUR ROOM");
        cout << "Please scroll above to review the available room types and their available service/s." << endl;
        cout << "ENTER:" << endl;
        cout << "\t'1' for Medium" << endl;
        cout << "\t'2' for Large" << endl;
        cout << "\t'3' for Luxurious" << endl;
        cout << YELLOW;
        cout << "Enter here: ";
        cout << RESET;

        cin >> choice;
        cout << endl;
        
        if(choice == "1"){
            if(medAvailable == 0){
                    cout << RED;
                    cout << "[UNAVAILABLE]Sorry this room is unavailable, please choose another.\n";
                    cout << " " << endl;
                    cout << RESET;
            }
            else{ 
                cout << endl;
                cout << "[ROOM INFORMATION]" << endl;
                cout << "Medium Room" << endl;
                cout << "- Max Capacity: 2" << endl;
                cout << "\t- Room Service (Php 30)" << endl;
                cout << endl;
                cout << " " << endl;
                cout << "Confirm room?" << endl;
                cout << YELLOW;
                cout << "Enter 'y' for yes or 'n' for no: ";
                cout << RESET;
                do{
                    cin >> confirm;
                    if(confirm == "y" || confirm == "Y"){
                        chosenRoom = "Medium";
                        roomCost = 100;
                        chosen = true;
                        confirmcheck = true;
                    }
                    else if(confirm == "n" || confirm == "N"){
                        cout << endl;
                        confirmcheck = true;
                    }
                    else{
                        cout << "Not a valid option." << endl;
                    }
                }while(confirmcheck == false);
                
            }
        }
        else if(choice == "2"){
            if(larAvailable == 0){
                    cout << RED;
                    cout << "Sorry this room is unavailable, please choose another.\n";
                    cout << " " << endl;
                    cout << RESET;
                }
                else{
                    cout << endl;
                    cout << "[ROOM INFORMATION]" << endl;
                    cout << "Large Room" << endl;
                    cout << "- Max Capacity: 4" << endl;
                    cout << "- Room Service (Php 30)" << endl;
                    cout << "- Food Service (Price will depend on availed food item/s)" << endl;
                    cout << endl;
                    cout << YELLOW;
                    cout << "Confirm room?" << endl;
                    cout << "Enter 'y' for yes or 'n' for no: ";
                    cout << RESET;
                    do{
                        cin >> confirm;
                        if(confirm == "y" || confirm == "Y"){
                            chosenRoom = "Large";
                            roomCost = 250;
                            chosen = true;    
                            confirmcheck = true;
                        }
                        else if(confirm == "n" || confirm == "N"){
                            cout << endl;
                            confirmcheck = true;
                        }
                        else{
                            cout << RED;
                            cout << "Not a valid option." << endl;
                            cout << RESET;  
                        }
                    }while(confirmcheck == false);
                    
                }
            }
        else if(choice == "3"){
            if(luxAvailable == 0){
                    cout << RED;
                    cout << "Sorry, this room is unavailable, please choose another.\n";
                    cout << " " << endl;
                    cout << RESET;
                }
                else{ 
                    cout << endl;
                    cout << "[ROOM INFORMATION]" << endl;
                    cout << "Luxurious Room" << endl;
                    cout << "- Max Capacity: 8" << endl;
                    cout << "\t- Room Service (Php 30)" << endl;
                    cout << "\t- Food Service (Price will depend on availed food item/s)" << endl;
                    cout << "\t- Private Spa Service (Price will depend on availed spa treatment/s)" << endl;
                    cout << endl;
                    cout << YELLOW;
                    cout << "Confirm room?" << endl;
                    cout << "Enter 'y' for yes or 'n' for no: ";
                    cout << RESET;
                    do{
                        cin >> confirm;
                        if(confirm == "y" || confirm == "Y"){
                            chosenRoom = "Luxurious";
                            roomCost = 500;
                            chosen = true;
                            confirmcheck = true;
                        }
                        else if(confirm == "n" || confirm == "N"){
                            cout << endl;
                            confirmcheck = true;
                        }
                        else{
                            cout << RED;
                            cout << "Not a valid option." << endl;
                            cout << RESET;
                        }
                    }while(confirmcheck == false); 
                }
        }
        else{
            cout << RED;
            cout << "Not valid choice. Try again." << endl;
            cout << RESET;
        }
        
    } while (chosen == false);
    cout << " " << endl;
    cout << "Great! You availed the " << chosenRoom << " room. Let's proceed to the next step of your reservation." << endl;
    cout << endl;

    printHeader("                 BOOKING DETAILS");
    cout << "How many nights will you be staying?" << endl;
    cout << YELLOW;
    cout << "Enter here: ";
    cout << RESET;
    do{
        if(!(cin >> numOfNights)){
        cout << RED;
        cout << "Not valid input." << endl;
        cout << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{

            nightCheck = true;
        }
        
    }while(nightCheck == false);
    cout << endl;
    cout << "How many people will be in this booking?" << endl;
    cout << YELLOW;
    cout << "Enter here: ";
    cout << RESET;
    do{
        if(!(cin >> numOfPeople)){
        cout << RED;
        cout << "Not valid input." << endl;
        cout << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            //new code here V
            if(choice == "1"){

                if(numOfPeople >= 3){
                    cout << "Too namny people, TWO is max." << endl << endl;
                }
                else{
                    peopleCheck = true;
                }
            }
            else if(choice == "2"){
                
                if(numOfPeople >= 5 ){
                    cout << "Too namny people, FOUR is max." << endl << endl;
                }
                else{
                    peopleCheck = true;
                }
            }
            else{
                if(numOfPeople >= 9 ){
                    cout << "Too namny people, EIGHT is max." << endl << endl;
                }
                else{
                    peopleCheck = true;
                }
            }
        }

    }while(peopleCheck == false);
    
    //new code here v
    cout << endl;

    for(int i = 0; i < numOfPeople; i++){
        agecheck = false;

        do{
            cout << "Guest " << i + 1 << ", please anter your age: ";
            if(!(cin >> ageofPerson[i])){
                cout << RED;
                cout << "Not valid input." << endl;
                cout << RESET;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else{
                 cout << endl;
                    agecheck = true;
            }
        }while(agecheck == false);
    }
    //new code stops here ^
    cout << endl;
    cout << "Would you like to check the included services with your availed room?" << endl;
    cout << YELLOW;
    cout << "Enter 'y' for yes or 'n' for no: ";
    cout << RESET;
    
    do{
        cin >> services;
        cout << endl;
        
        confirmcheck = false;
        
        if (services == "y" || services == "Y"){
            
            confirmcheck = true;
            cout << endl;
            printHeader("                 HOTEL SERVICES");
            if ((services == "y" || services == "Y") && (chosenRoom == "Large" || chosenRoom == "Luxurious")){
            }
            cout << endl;
            
            if (chosenRoom == "Medium") {
                cout << "MEDIUM ROOM AVAILABLE SERVICES:" << endl;
                cout << "\t Room service (Php 30)" << endl;
                cout << endl;
                cout << YELLOW;
                cout << "Enter 'y' to accept or 'n' to decline: ";
                cout << RESET;
                
                do{
                    cin >> roomService;

                    if(roomService == "y" || roomService == "Y"){
                        roomServiceCost = roomServiceYes();
                        roomCheck = true;
                    }
                    else if(roomService == "n" || roomService == "N"){
                        roomServiceNo();
                        roomCheck = true;
                    }
                    else{
                        cout << "Not a valid Option." << endl << endl;
                    }
                }while(roomCheck == false);
            } else if (chosenRoom == "Large") {
                cout << "LARGE ROOM AVAILABLE SERVICES:" << endl;
                cout << "\t Room service (Php 30)" << endl;
                cout << "\t Food service (Price will vary to availed food items)" << endl;
                cout << endl;
                cout << "Would you like to avail room service?" << endl;
                cout << YELLOW;
                cout << "Enter 'y' to accept or 'n' to decline: ";
                cout << RESET;

                do{
                    cin >> roomService;

                    if(roomService == "y" || roomService == "Y"){

                        roomServiceCost = roomServiceYes();
                        roomCheck = true;
                    }
                    else if(roomService == "n" || roomService == "N"){
                        roomServiceNo();
                        roomCheck = true;
                    }
                    else{
                        cout << "Not a valid Option." << endl << endl;
                    }
                }while(roomCheck == false);
                
                cout << "Would you like to avail food service?" << endl;
                cout << YELLOW;
                cout << "Enter 'y' to accept or 'n' to decline: ";
                cout << RESET;

                do{
                    cin >> foodService;

                    if(foodService == "y" || foodService == "Y"){
                        cout << GREEN;
                        cout << "[SUCCESS] Food service availed." << endl;
                        cout << RESET;
                        
                        
                        do{

                            do{

                            
                                foodConfirmed = false;

                                cout << "===========================================================================" << endl;
                                cout << "Please choose a meal option:" << endl;
                                cout << "\t '1' to check out the BREAKFAST menu" << endl;
                                cout << "\t '2' to check out the LUNCH menu" << endl;
                                cout << "\t '3' to check out the DINNER menu" << endl;
                                cout << YELLOW;
                                cout << "\tNOTE: You can only choose ONE meal option." << endl;
                                cout << "Enter here: ";
                                cout << RESET;


                                cin >> foodChoice;
                                
                                if(foodChoice == "1"){
                                    cout << endl;
                                    displayBreakfastMenu(ITEM_WIDTH);
                                    //new code v
                                    for(int i = 0; orderCheck == false; i = 0){
                                        
                                        ordervalid = false;
                                        moreOrder = false;
                                        orderMore = "nil";
                                        
                                    
                                        while(!(cin >> i)){
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            cout << "type 0 if you want to finish ordering." << endl;

                                        }
                                        if(i >= 5){

                                            cout << "number outside of meal number." << endl;
                                        }
                                        else if(i <= 0){
                                            do{
                                                cout << "finished ordering?(y/n)" << endl;

                                                cin >> finishOrder;

                                                if(finishOrder == "y" || finishOrder == "Y"){
                                                    ordervalid = true;
                                                    orderCheck = true;
                                                    foodOptions = true;

                                                }
                                                else if(finishOrder == "n" || finishOrder == "N"){
                                                    ordervalid = true;
                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                }
                                                else{
                                                    cout << "Not a valid response." << endl;
                                                }

                                            }while(ordervalid == false);
                                        }
                                        else{
                                            if(i == 1){
                                                if(foodChosen[0] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[0] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[0] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[0])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            pancakes = 130;
                                                            orderChecks[0] = "yes";
                                                            pancakesum = pancakes*foodAmount[0];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){

                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[0] == "Not");


                                                }
                                            }
                                            else if(i == 2){
                                                if(foodChosen[1] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[1] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[1] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[1])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            tapsilog = 200;
                                                            orderChecks[1] = "yes";
                                                            tapsilogsum = tapsilog*foodAmount[1];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[1] == "Not");
                                                }
                                            }
                                            else if(i == 3){
                                                if(foodChosen[2] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[2] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[2] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[2])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            longsilog = 230;
                                                            orderChecks[2] = "yes";
                                                            longsilogsum = longsilog*foodAmount[2];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[2] == "Not");
                                                }
                                            }
                                            else if(i == 4){
                                                if(foodChosen[3] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[3] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[3] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[3])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            bacsilog = 250;
                                                            orderChecks[3] = "yes";
                                                            bacsilogsum = bacsilog*foodAmount[3];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[3] == "Not");
                                                }
                                            }
                                        }
                                    }
                                    foodOptions = true;
                                        
                                }else if(foodChoice == "2"){
                                    cout << endl;
                                    displayLunchMenu(ITEM_WIDTH);
                                    //newcode v
                                        for(int i = 0; orderCheck == false; i = 0){
                                        
                                        
                                        ordervalid = false;
                                        moreOrder = false;
                                        orderMore = "nil";
                                        
                                    
                                        while(!(cin >> i)){
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            cout << "type 0 if you want to finish ordering." << endl;

                                        }
                                        if(i >= 5){

                                            cout << "number outside of meal number." << endl;
                                        }
                                        else if(i <= 0){
                                            do{
                                                cout << "finished ordering?(y/n)" << endl;

                                                cin >> finishOrder;

                                                if(finishOrder == "y" || finishOrder == "Y"){
                                                    ordervalid = true;
                                                    orderCheck = true;
                                                    foodOptions = true;

                                                }
                                                else if(finishOrder == "n" || finishOrder == "N"){
                                                    ordervalid = true;
                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                }
                                                else{
                                                    cout << "Not a valid response." << endl;
                                                }

                                            }while(ordervalid == false);
                                        }
                                        else{
                                            if(i == 1){
                                                if(foodChosen[0] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[0] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[0] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[0])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            sinigang = 600;
                                                            orderChecks[0] = "yes";
                                                            sinigangsum = sinigang*foodAmount[0];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayLunchMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[0] == "Not");


                                                }
                                            }
                                            else if(i == 2){
                                                if(foodChosen[1] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[1] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[1] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[1])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            adobo = 750;
                                                            orderChecks[1] = "yes";
                                                            adobosum = adobo*foodAmount[1];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayLunchMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[1] == "Not");
                                                }
                                            }
                                            else if(i == 3){
                                                if(foodChosen[2] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[2] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[2] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[2])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            kare = 530;
                                                            orderChecks[2] = "yes";
                                                            karesum = kare*foodAmount[2];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayLunchMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[2] == "Not");
                                                }
                                            }
                                            else if(i == 4){
                                                if(foodChosen[3] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[3] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[3] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[3])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            fillet = 170;
                                                            orderChecks[3] = "yes";
                                                            filletsum = fillet*foodAmount[3];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayLunchMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[3] == "Not");
                                                }
                                            }
                                        }
                                    }
                                    foodOptions = true;
                                        
                                }else if(foodChoice == "3"){
                                    cout << endl;
                                    displayDinnerMenu(ITEM_WIDTH);
                                    //new code v
                                    for(int i = 0; orderCheck == false; i = 0){
                                        
                                        
                                        ordervalid = false;
                                        moreOrder = false;
                                        orderMore = "nil";
                                        
                                    
                                        while(!(cin >> i)){
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            cout << "type 0 if you want to finish ordering." << endl;

                                        }
                                        if(i >= 5){

                                            cout << "number outside of meal number." << endl;
                                        }
                                        else if(i <= 0){
                                            do{
                                                cout << "finished ordering?(y/n)" << endl;

                                                cin >> finishOrder;

                                                if(finishOrder == "y" || finishOrder == "Y"){
                                                    ordervalid = true;
                                                    orderCheck = true;
                                                    foodOptions = true;

                                                }
                                                else if(finishOrder == "n" || finishOrder == "N"){
                                                    ordervalid = true;
                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                }
                                                else{
                                                    cout << "Not a valid response." << endl;
                                                }

                                            }while(ordervalid == false);
                                        }
                                        else{
                                            if(i == 1){
                                                if(foodChosen[0] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[0] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[0] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[0])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            burger = 1150;
                                                            orderChecks[0] = "yes";
                                                            burgersum = burger*foodAmount[0];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayDinnerMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[0] == "Not");


                                                }
                                            }
                                            else if(i == 2){
                                                if(foodChosen[1] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[1] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[1] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[1])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            pasta = 540;
                                                            orderChecks[1] = "yes";
                                                            pastasum = pasta*foodAmount[1];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayDinnerMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[1] == "Not");
                                                }
                                            }
                                            else if(i == 3){
                                                if(foodChosen[2] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[2] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[2] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[2])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            beef = 950;
                                                            orderChecks[2] = "yes";
                                                            beefsum = beef*foodAmount[2];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayDinnerMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[2] == "Not");
                                                }
                                            }
                                            else if(i == 4){
                                                if(foodChosen[3] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[3] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[3] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[3])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            seafood = 830;
                                                            orderChecks[3] = "yes";
                                                            seafood = seafood*foodAmount[3];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayDinnerMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[3] == "Not");
                                                    
                                                }
                                            }
                                        }
                                    }
                                        
                                }else{
                                    cout << RED;
                                    cout << "Not a valid option. Try again" << endl;
                                    cout << RESET;
                                }



                            }while(foodOptions == false);
                            
                            do{
                                foodOptions = false;

                                cout << "You ordered these food" << endl;
                                if(foodChoice == "1"){
                                    for(int i = 0; i < 4; i++){
                                        if(foodChosen[i] == "y"){
                                            cout << "-" << breakfast[i] << "x" << foodAmount[i] << endl;
                                        }
                                        
                                    }
                                }
                                else if(foodChoice == "2"){
                                    for(int i = 0; i < 4; i++){
                                        if(foodChosen[i] == "y"){
                                            cout << "-" << lunch[i] << "x" << foodAmount[i] << endl;
                                        }
                                        
                                    }
                                }
                                else if(foodChoice == "3"){
                                    for(int i = 0; i < 4; i++){
                                        if(foodChosen[i] == "y"){
                                            cout << "-" << dinner[i] << "x" << foodAmount[i] << endl;
                                        }
                                        
                                    }
                                }
                                cout << "Confirm order?(y/n)" << endl;

                                cin >> foodConfirmation;
                                
                                if(foodConfirmation == "y" || foodConfirmation == "Y"){

                                    cout << endl;
                                    foodOptions = true;
                                    foodConfirmed = true;
                                    cout << endl;
                                    successMessage("Your food items are now availed!");
                                    cout << endl;

                                }else if(foodConfirmation == "n" || foodConfirmation == "n"){

                                    foodOptions = false;
                                    orderCheck = false;
                                    orderChecks[0] = "y";
                                    orderChecks[1] = "y";
                                    orderChecks[2] = "y";
                                    orderChecks[3] = "y";
                                    moreOrder = false;
                                    foodConfirmed = true;
                                    foodChosen[0] = "n";
                                    foodChosen[1] = "n";
                                    foodChosen[2] = "n";
                                    foodChosen[3] = "n";
                                    foodAmount[0] = 0;
                                    foodAmount[1] = 0;
                                    foodAmount[2] = 0;
                                    foodAmount[3] = 0;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                }
                                else{

                                    cout << "Please enter a valid response." << endl;
                                }
                            
                            }while(foodConfirmed == false);
                            

                         
                                                                                    
                        }while (foodOptions == false);


                    }else if(foodService == "n" || foodService == "N"){
                        cout << endl << endl;
                        foodOptions = true;
                    }
                    else{
                        cout << "Not a valid Option." << endl << endl;
                    }
                }while(foodOptions == false);
                
                
            } else {
                cout << "LUXURIOUS ROOM AVAILABLE SERVICES:" << endl;
                cout << "\t Room service (Php 30)" << endl;
                cout << "\t Food service (Price will vary to availed food item/s)" << endl;
                cout << "\t Private Spa treatment (Price will vary to availed spa treatment/s)" << endl;
                cout << "===========================================================================" << endl;
                cout << " " << endl;
                cout << "Would you like to avail room service?" << endl;
                cout << YELLOW;
                cout << "Enter 'y' to accept or 'n' to decline: ";
                cout << RESET;
                
                do{
                    cin >> roomService;

                    if(roomService == "y" || roomService == "Y"){
                        roomServiceCost = roomServiceYes();
                        roomCheck = true;
                    }
                    else if(roomService == "n" || roomService == "N"){
                        roomServiceNo();
                        roomCheck = true;
                    }
                    else{
                        cout << "Not a valid Option." << endl << endl;
                    }
                }while(roomCheck == false);

                cout << " " << endl;
                cout << "Would you like to avail food service?" << endl;
                cout << YELLOW;
                cout << "Enter 'y' to accept or 'n' to decline: ";
                cout << RESET;

                do{
                    cin >> foodService;

                    if(foodService == "y" || foodService == "Y"){
                        cout << GREEN;
                        cout << "[SUCCESS] Food service availed." << endl;
                        cout << RESET;
                        
                        
                        do{

                            do{

                            
                                foodConfirmed = false;

                                cout << "===========================================================================" << endl;
                                cout << "Please choose a meal option:" << endl;
                                cout << "\t '1' to check out the BREAKFAST menu" << endl;
                                cout << "\t '2' to check out the LUNCH menu" << endl;
                                cout << "\t '3' to check out the DINNER menu" << endl;
                                cout << YELLOW;
                                cout << "\tNOTE: You can only choose ONE meal option." << endl;
                                cout << "Enter here: ";
                                cout << RESET;


                                cin >> foodChoice;
                                
                                if(foodChoice == "1"){
                                    cout << endl;
                                    displayBreakfastMenu(ITEM_WIDTH);
                                    //new code v
                                    for(int i = 0; orderCheck == false; i = 0){
                                        
                                        ordervalid = false;
                                        moreOrder = false;
                                        orderMore = "nil";
                                        
                                    
                                        while(!(cin >> i)){
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            cout << "type 0 if you want to finish ordering." << endl;

                                        }
                                        if(i >= 5){

                                            cout << "number outside of meal number." << endl;
                                        }
                                        else if(i <= 0){
                                            do{
                                                cout << "finished ordering?(y/n)" << endl;

                                                cin >> finishOrder;

                                                if(finishOrder == "y" || finishOrder == "Y"){
                                                    ordervalid = true;
                                                    orderCheck = true;
                                                    foodOptions = true;

                                                }
                                                else if(finishOrder == "n" || finishOrder == "N"){
                                                    ordervalid = true;
                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                }
                                                else{
                                                    cout << "Not a valid response." << endl;
                                                }

                                            }while(ordervalid == false);
                                        }
                                        else{
                                            if(i == 1){
                                                if(foodChosen[0] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[0] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[0] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[0])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            pancakes = 130;
                                                            orderChecks[0] = "yes";
                                                            pancakesum = pancakes*foodAmount[0];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){

                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[0] == "Not");


                                                }
                                            }
                                            else if(i == 2){
                                                if(foodChosen[1] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[1] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[1] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[1])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            tapsilog = 200;
                                                            orderChecks[1] = "yes";
                                                            tapsilogsum = tapsilog*foodAmount[1];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[1] == "Not");
                                                }
                                            }
                                            else if(i == 3){
                                                if(foodChosen[2] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[2] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[2] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[2])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            longsilog = 230;
                                                            orderChecks[2] = "yes";
                                                            longsilogsum = longsilog*foodAmount[2];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[2] == "Not");
                                                }
                                            }
                                            else if(i == 4){
                                                if(foodChosen[3] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[3] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[3] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[3])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            bacsilog = 250;
                                                            orderChecks[3] = "yes";
                                                            bacsilogsum = bacsilog*foodAmount[3];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[3] == "Not");
                                                }
                                            }
                                        }
                                    }
                                    foodOptions = true;
                                        
                                }else if(foodChoice == "2"){
                                    cout << endl;
                                    displayLunchMenu(ITEM_WIDTH);
                                    //newcode v
                                        for(int i = 0; orderCheck == false; i = 0){
                                        
                                        
                                        ordervalid = false;
                                        moreOrder = false;
                                        orderMore = "nil";
                                        
                                    
                                        while(!(cin >> i)){
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            cout << "type 0 if you want to finish ordering." << endl;

                                        }
                                        if(i >= 5){

                                            cout << "number outside of meal number." << endl;
                                        }
                                        else if(i <= 0){
                                            do{
                                                cout << "finished ordering?(y/n)" << endl;

                                                cin >> finishOrder;

                                                if(finishOrder == "y" || finishOrder == "Y"){
                                                    ordervalid = true;
                                                    orderCheck = true;
                                                    foodOptions = true;

                                                }
                                                else if(finishOrder == "n" || finishOrder == "N"){
                                                    ordervalid = true;
                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                }
                                                else{
                                                    cout << "Not a valid response." << endl;
                                                }

                                            }while(ordervalid == false);
                                        }
                                        else{
                                            if(i == 1){
                                                if(foodChosen[0] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[0] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[0] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[0])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            sinigang = 600;
                                                            orderChecks[0] = "yes";
                                                            sinigangsum = sinigang*foodAmount[0];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayLunchMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[0] == "Not");


                                                }
                                            }
                                            else if(i == 2){
                                                if(foodChosen[1] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[1] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[1] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[1])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            adobo = 750;
                                                            orderChecks[1] = "yes";
                                                            adobosum = adobo*foodAmount[1];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayLunchMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[1] == "Not");
                                                }
                                            }
                                            else if(i == 3){
                                                if(foodChosen[2] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[2] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[2] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[2])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            kare = 530;
                                                            orderChecks[2] = "yes";
                                                            karesum = kare*foodAmount[2];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayLunchMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[2] == "Not");
                                                }
                                            }
                                            else if(i == 4){
                                                if(foodChosen[3] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[3] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[3] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[3])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            fillet = 170;
                                                            orderChecks[3] = "yes";
                                                            filletsum = fillet*foodAmount[3];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayLunchMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[3] == "Not");
                                                }
                                            }
                                        }
                                    }
                                    foodOptions = true;
                                        
                                }else if(foodChoice == "3"){
                                    cout << endl;
                                    displayDinnerMenu(ITEM_WIDTH);
                                    //new code v
                                    for(int i = 0; orderCheck == false; i = 0){
                                        
                                        
                                        ordervalid = false;
                                        moreOrder = false;
                                        orderMore = "nil";
                                        
                                    
                                        while(!(cin >> i)){
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            cout << "type 0 if you want to finish ordering." << endl;

                                        }
                                        if(i >= 5){

                                            cout << "number outside of meal number." << endl;
                                        }
                                        else if(i <= 0){
                                            do{
                                                cout << "finished ordering?(y/n)" << endl;

                                                cin >> finishOrder;

                                                if(finishOrder == "y" || finishOrder == "Y"){
                                                    ordervalid = true;
                                                    orderCheck = true;
                                                    foodOptions = true;

                                                }
                                                else if(finishOrder == "n" || finishOrder == "N"){
                                                    ordervalid = true;
                                                    displayBreakfastMenu(ITEM_WIDTH);
                                                }
                                                else{
                                                    cout << "Not a valid response." << endl;
                                                }

                                            }while(ordervalid == false);
                                        }
                                        else{
                                            if(i == 1){
                                                if(foodChosen[0] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[0] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[0] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[0])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            burger = 1150;
                                                            orderChecks[0] = "yes";
                                                            burgersum = burger*foodAmount[0];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayDinnerMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[0] == "Not");


                                                }
                                            }
                                            else if(i == 2){
                                                if(foodChosen[1] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[1] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[1] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[1])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            pasta = 540;
                                                            orderChecks[1] = "yes";
                                                            pastasum = pasta*foodAmount[1];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayDinnerMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[1] == "Not");
                                                }
                                            }
                                            else if(i == 3){
                                                if(foodChosen[2] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[2] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[2] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[2])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            beef = 950;
                                                            orderChecks[2] = "yes";
                                                            beefsum = beef*foodAmount[2];
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayDinnerMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[2] == "Not");
                                                }
                                            }
                                            else if(i == 4){
                                                if(foodChosen[3] == "y"){

                                                    cout << "food already chosen." << endl;
                                                    cin.clear();
                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                                }else{
                                                    foodChosen[3] = "y";
                                                    cout << "How many?" << endl;
                                                    orderChecks[3] = "Not";
                                                    do{
                                                        if(!(cin >> foodAmount[3])){
                                                        cout << "please put a valid number" << endl;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        }
                                                        else{
                                                            seafood = 830;
                                                            orderChecks[3] = "yes";
                                                            
                                                            
                                                            cout << "would you like to order more?(y/n)" << endl;
                                                            do{
                                                                cin >> orderMore;
                                                                
                                                                if(orderMore == "y" || orderMore == "Y"){
                                                                    cout << endl;
                                                                    moreOrder = true;
                                                                    cin.clear();
                                                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                                    displayDinnerMenu(ITEM_WIDTH);
                                                                }
                                                                else if(orderMore == "n" || orderMore == "N"){
                                                                    
                                                                    foodOptions = true;
                                                                    orderCheck = true;
                                                                    moreOrder = true;
                                                                    cout << endl;
                                                                }
                                                                else{
                                                                    cout << "enter a valid response." << endl;
                                                                }
                                                            }while(moreOrder == false);
                                                            
                                                        }
                                                    }while(orderChecks[3] == "Not");
                                                    
                                                }
                                            }
                                        }
                                    }
                                        
                                }else{
                                    cout << RED;
                                    cout << "Not a valid option. Try again" << endl;
                                    cout << RESET;
                                }



                            }while(foodOptions == false);
                            
                            do{
                                foodOptions = false;

                                cout << "You ordered these food" << endl;
                                if(foodChoice == "1"){
                                    for(int i = 0; i < 4; i++){
                                        if(foodChosen[i] == "y"){
                                            cout << "-" << breakfast[i] << "x" << foodAmount[i] << endl;
                                        }
                                        
                                    }
                                }
                                else if(foodChoice == "2"){
                                    for(int i = 0; i < 4; i++){
                                        if(foodChosen[i] == "y"){
                                            cout << "-" << lunch[i] << "x" << foodAmount[i] << endl;
                                        }
                                        
                                    }
                                }
                                else if(foodChoice == "3"){
                                    for(int i = 0; i < 4; i++){
                                        if(foodChosen[i] == "y"){
                                            cout << "-" << dinner[i] << "x" << foodAmount[i] << endl;
                                        }
                                        
                                    }
                                }
                                cout << "Confirm order?(y/n)" << endl;

                                cin >> foodConfirmation;
                                
                                if(foodConfirmation == "y" || foodConfirmation == "Y"){

                                    cout << endl;
                                    foodOptions = true;
                                    foodConfirmed = true;
                                    cout << endl;
                                    successMessage("Your food items are now availed!");
                                    cout << endl;

                                }else if(foodConfirmation == "n" || foodConfirmation == "n"){

                                    foodOptions = false;
                                    orderCheck = false;
                                    orderChecks[0] = "y";
                                    orderChecks[1] = "y";
                                    orderChecks[2] = "y";
                                    orderChecks[3] = "y";
                                    moreOrder = false;
                                    foodConfirmed = true;
                                    foodChosen[0] = "n";
                                    foodChosen[1] = "n";
                                    foodChosen[2] = "n";
                                    foodChosen[3] = "n";
                                    foodAmount[0] = 0;
                                    foodAmount[1] = 0;
                                    foodAmount[2] = 0;
                                    foodAmount[3] = 0;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                }
                                else{

                                    cout << "Please enter a valid response." << endl;
                                }
                            
                            }while(foodConfirmed == false);
                            

                         
                                                                                    
                        }while (foodOptions == false);


                    }else if(foodService == "n" || foodService == "N"){
                        cout << endl << endl;
                        foodOptions = true;
                    }
                    else{
                        cout << "Not a valid Option." << endl << endl;
                    }
                }while(foodOptions == false);
                
                cout << "Would you like to avail private spa treatment?" << endl;
                cout << YELLOW;
                cout << "Enter 'y' to accept or 'n' to decline: ";
                cout << RESET;

                do{
                    cin >> spa;

                    if(spa == "y" || spa == "Y"){

                        SpaDisplay(ITEM_WIDTH);
                        do{
                            do{
                                for(int i = 0; orderTreat == false; i = 0){
                                    
                                    spaConfirmed = false;
                                    treatValid = false;
                                    moreSpa = false;


                                    
                                    while(!(cin >> i)){
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                        cout << "type 0 if you want to finish ordering." << endl;

                                    }
                                    if(i >= 5){

                                        cout << "number outside of treatment number." << endl;
                                    }
                                    else if(i <= 0){
                                        do{

                                            cout << "finished orderng?(y/n)" << endl;
                                            cin >> finishTreat;

                                            if(finishTreat == "y" || finishTreat == "Y"){
                                                treatValid = true;
                                                orderTreat = true;
                                                spaCheck = true;
                                                cout << endl;
                                            }
                                            else if(finishTreat == "n" || finishTreat == "N"){
                                                treatValid = true;
                                                SpaDisplay(ITEM_WIDTH);
                                            }
                                            else{
                                                cout << "Not a valid response." << endl;
                                            }

                                        }while(treatValid == false);

                                    }
                                    else{
                                        if(i == 1){
                                            if(treatChosen[0] == "y"){

                                                cout << "Treatment already chosen." << endl;
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            }else{
                                                treatChosen[0] = "y";                             
                                                hotstone = 999;

                                                cout << "would you like to order more?(y/n)" << endl;
                                                do{
                                                    cin >> spaMore;
                                                            
                                                    if(spaMore == "y" || spaMore == "Y"){
                                                        cout << endl;
                                                        moreSpa = true;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        SpaDisplay(ITEM_WIDTH);
                                                    }
                                                    else if(spaMore == "n" || spaMore == "N"){
                                                        moreSpa = true;
                                                        spaCheck = true;
                                                        orderTreat = true;
                                                        cout << endl;
                                                    }
                                                    else{
                                                        cout << "enter a valid response." << endl;
                                                    }
                                                }while(moreSpa == false);                                        
                                            }
                                        }
                                        else if(i == 2){
                                            if(treatChosen[1] == "y"){

                                                cout << "Treatment already chosen." << endl;
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            }else{
                                                treatChosen[1] = "y";
                                                aroma = 789;

                                                cout << "would you like to order more?(y/n)" << endl;
                                                do{
                                                    cin >> spaMore;
                                                            
                                                    if(spaMore == "y" || spaMore == "Y"){
                                                        cout << endl;
                                                        moreSpa = true;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        SpaDisplay(ITEM_WIDTH);
                                                    }
                                                    else if(spaMore == "n" || spaMore == "N"){
                                                        moreSpa = true;
                                                        spaCheck = true;
                                                        orderTreat = true;
                                                        cout << endl;
                                                    }
                                                    else{
                                                        cout << "enter a valid response." << endl;
                                                    }
                                                }while(moreSpa == false);
                                            }
                                        }
                                        else if(i == 3){
                                            if(treatChosen[2] == "y"){

                                                cout << "Treatment already chosen." << endl;
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            }else{
                                                treatChosen[2] = "y";
                                                facial = 1599;

                                                cout << "would you like to order more?(y/n)" << endl;
                                                do{
                                                    cin >> spaMore;
                                                            
                                                    if(spaMore == "y" || spaMore == "Y"){
                                                        cout << endl;
                                                        moreSpa = true;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        SpaDisplay(ITEM_WIDTH);
                                                    }
                                                    else if(spaMore == "n" || spaMore == "N"){
                                                        moreSpa = true;
                                                        spaCheck = true;
                                                        orderTreat = true;
                                                        cout << endl;
                                                    }
                                                    else{
                                                        cout << "enter a valid response." << endl;
                                                    }
                                                }while(moreSpa == false);
                                            }
                                        }
                                        else if(i == 4){
                                            if(treatChosen[3] == "y"){

                                                cout << "Treatment already chosen." << endl;
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                            }else{
                                                treatChosen[3] = "y";
                                                sauna = 1399;

                                                cout << "would you like to order more?(y/n)" << endl;
                                                do{
                                                    cin >> spaMore;
                                                            
                                                    if(spaMore == "y" || spaMore == "Y"){
                                                        cout << endl;
                                                        moreSpa = true;
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        SpaDisplay(ITEM_WIDTH);
                                                    }
                                                    else if(spaMore == "n" || spaMore == "N"){
                                                        moreSpa = true;
                                                        spaCheck = true;
                                                        orderTreat = true;
                                                        cout << endl;
                                                    }
                                                    else{
                                                        cout << "enter a valid response." << endl;
                                                    }
                                                }while(moreSpa == false);
                                                
                                            }
                                        }
                                        

                                    }

                                }
                            }while(spaCheck == false);

                            do{
                                cout << "You ordered these treatments" << endl;
                                
                                for(int i = 0; i < 4; i++){
                                    if(treatChosen[i] == "y"){
                                        cout << "-" << treatments[i] << endl;
                                    }
                                }
                                
                                cout << "Confirm order?(y/n)" << endl;
                                
                                cin >> spaConfirmation;

                                if(spaConfirmation == "y" || spaConfirmation == "Y"){
                                    spaConfirmed = true;
                                    spaYesorNo = true;
                                    spaCheck = true;
                                    successMessage("Your spa treatments are now availed!");

                                }
                                else if(spaConfirmation == "n" || spaConfirmation == "N"){
                                    spaConfirmation = true;
                                    moreSpa = false;
                                    spaCheck = false;
                                    orderTreat = false;
                                    spaYesorNo = false;
                                    treatValid = false;
                                    treatChosen[0] = "n";
                                    treatChosen[1] = "n";
                                    treatChosen[2] = "n";
                                    treatChosen[3] = "n";
                                }
                                else{
                                    cout << "Please enter a valid response." << endl;
                                }

                            }while(spaConfirmed == false);
                        
                        }while(spaCheck == false);
                    }else if(spa == "n" || spa == "N"){
                        cout << endl << endl;
                        spaCheck = true;
                    }
                    else{

                        cout << "Enter a valid option" << endl;
                    }
                    
                    
                    
                }while(spaYesorNo == false);
                
            }
        }else if(services == "n" || services == "N"){
            successMessage("No services availed.");
            confirmcheck = true;
            
        }
        else{
            cout << RED;
            cout << "Not a valid option.\n";
            cout << RESET;
        }
    }while(confirmcheck == false);
    
    
    if(services == "y" || services == "Y"){
        if(roomService == "Y"){
            roomService = "y";
        }
        if(foodService == "Y"){
            foodService = "y";
            if(foodChosen[0] == "Y"){
                foodChosen[0] = "y";
            }
            if(foodChosen[1] == "Y"){
                foodChosen[1] = "y";
            }
            if(foodChosen[2] == "Y"){
                foodChosen[2] = "y";
            }
            if(foodChosen[3] == "Y"){
                foodChosen[3] = "y";
            }
            
        }
        if(spa == "Y"){
            spa = "y";
            if(treatChosen[0] == "Y"){
                treatChosen[0] = "y";
            }
            if(treatChosen[1] == "Y"){
                treatChosen[1] = "y";
            }
            if(treatChosen[2] == "Y"){
                treatChosen[2] = "y";
            }
            if(treatChosen[3] == "Y"){
                treatChosen[3] = "y";
            }
        }
        
        if(foodChosen[0] != "y" && foodChosen[1] != "y" && foodChosen[2] != "y" && foodChosen[3] != "y"){
            foodService = "n";
        }
        if(chosenRoom == "Medium"){
              
        }else if(chosenRoom == "Large"){
            if(roomService == "y" && foodService == "y"){
            cout << endl;
            successMessage("Room and food service added.");
            }
            else if(roomService == "y"){
            cout << endl;
            successMessage("Room service added.");
            }
            else if(foodService == "y"){
            cout << endl;
            successMessage("Food service added.");
            cout << "\n----------------------------------------\n";
            }
            else{
            cout << endl;
            successMessage("No services added.");
            cout << "\n----------------------------------------\n";
            }
        }else if(chosenRoom == "Luxurious"){
            if(roomService == "y" && foodService == "y" && spa == "y"){
            cout << endl;
            successMessage("Room, food, and private spa treatment services added.");
            cout << "\n----------------------------------------\n";
            }
            else if(roomService == "y" && foodService == "y"){
            cout << endl;
            successMessage("Room and food services added.");
            cout << "\n----------------------------------------\n";
            }
            else if(roomService == "y" && spa == "y"){
            cout << endl;
            successMessage("Room and private spa treatment services added.");
            cout << "\n----------------------------------------\n";
            }
            else if(foodService == "y" && spa == "y"){
            cout << endl;
            successMessage("Food and private spa treatment services added.");
            cout << "\n----------------------------------------\n";
            }
            else if(roomService == "y"){
            cout << endl;
            successMessage("Room service added.");
            cout << "\n----------------------------------------\n";
            }
            else if(foodService == "y"){
            cout << endl;
            successMessage("Food service added.");
            cout << "\n----------------------------------------\n";
            }
            else if(spa == "y"){
            cout << endl;
            successMessage("Private Spa Treatment service added.");
            cout << "\n----------------------------------------\n";
            }
            else{
            cout << endl;
            successMessage("No services added.");
            cout << "\n----------------------------------------\n";
            }
        }else{
            cout << RED;
            cout << "\nInvalid room selection.\n";
            cout << RESET;  
        }
    }

    //new calculations

    int seniorDiscount[8] = {};
    
    for(int i = 0; i < numOfPeople; i++){
        
        if(ageofPerson[i] >= 60 || ageofPerson[i] <=12){
            seniorDiscount[i] = .75*roomCost;
        }
        else{
            seniorDiscount[i] = 1*roomCost;
        
        }
        
        cout << seniorDiscount[i] << endl;
    }
    int seniorTally = 0;
    seniorTally = tally(seniorDiscount, numOfPeople);

    cout << endl;
    printHeader("                 OFFICIAL RECEIPT");
    
    time_t now = time(0) + 8 * 60 * 60;
    cout << "Reservation Date Issued: " << ctime(&now) << "\n";
    
    cout << left << setw(25) << "Room Type:"      << chosenRoom << endl;
    cout << left << setw(25) << "Number of Nights:" << numOfNights << endl;
    cout << left << setw(25) << "Number of Guests:" << numOfPeople << endl;
    //new to show the people v
  for (int i = 0; i < numOfPeople; i++) {
    cout << "Guest " << i + 1 << " - Age: "
         << ageofPerson[i] << endl;

    if (ageofPerson[i] >= 60) {
        cout << "Senior discount: Php " << roomCost - seniorDiscount[i] << endl;
        cout << "Room cost after discount: Php " << seniorDiscount[i] << endl;
    } else if (ageofPerson[i] <= 12) {
        cout << "Child discount: Php " << roomCost - seniorDiscount[i] << endl;
        cout << "Room cost after discount: Php " << seniorDiscount[i] << endl;
    } else {
        cout << "Room cost: Php " << seniorDiscount[i] << endl;
    }

    cout << endl; 
}

    cout << YELLOW;
    cout << "--------------------------------------------------" << endl;
    cout << "ROOM ACCOMMODATION" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << RESET;
    cout << left << setw(35) << "Nightly Room Rate:" << "Php " << roomCost << endl;
    cout << left << setw(35) << "Room Charge:" << "Php " << nightCost(roomCost, numOfNights) << endl;
    cout << endl;

    if(roomService == "y"){
        cout << YELLOW;
        cout << "--------------------------------------------------" << endl;
        cout << "ROOM SERVICE" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << RESET;
        cout << left << setw(35) << "Room Service Fee:" << "Php " << roomServiceCost << endl;
        cout << endl;
    }

    if(foodService == "y"){
    cout << YELLOW;
    cout << "--------------------------------------------------" << endl;
    cout << "FOOD SERVICE" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << RESET;

    if(foodChoice == "1"){

        if(foodChosen[0] == "y" || foodChosen[0] == "Y"){
            cout << "  - Pancakes (Php 130) " << foodAmount[0] << endl;
            pancakes = 130;
        }

        if(foodChosen[1] == "y" || foodChosen[1] == "Y"){
            cout << "  - Tapsilog (Php 200)" << foodAmount[1] << endl;
            tapsilog = 200;
        }

        if(foodChosen[2] == "y" || foodChosen[2] == "Y"){
            cout << "  - Longsilog (Php 230)" << foodAmount[2] << endl;
            longsilog = 230;
        }

        if(foodChosen[3] == "y" || foodChosen[3] == "Y"){
            cout << "  - Bacsilog (Php 250)" << foodAmount[3] << endl;
            bacsilog = 250;
        }
    }

    else if(foodChoice == "2"){

        if(foodChosen[0] == "y" || foodChosen[0] == "Y"){
            cout << "  - Sinigang na Sugpo (Php 600)" << foodAmount[0] << endl;
            sinigang = 600;
        }

        if(foodChosen[1] == "y" || foodChosen[1] == "Y"){
            cout << "  - Pork Adobo (Php 750)" << foodAmount[1] << endl;
            adobo = 750;
        }

        if(foodChosen[2] == "y" || foodChosen[2] == "Y"){
            cout << "  - Kare Kare (Php 530)" << foodAmount[2] << endl;
            kare = 530;
        }

        if(foodChosen[3] == "y" || foodChosen[3] == "Y"){
            cout << "  - Chicken Fillet (Php 170)" << foodAmount[3] << endl;
            fillet = 170;
        }
    }

    else if(foodChoice == "3"){
        if(foodChosen[0] == "y" || foodChosen[0] == "Y"){
            cout << "  - Burger Steak with Mashed Potatoes (Php 1150)" << foodAmount[0] << endl;
            burger = 1150;
        }
        if(foodChosen[1] == "y" || foodChosen[1] == "Y"){
            cout << "  - Pasta Bolognese (Php 540)" << foodAmount[1] << endl;
            pasta = 540;
        }
        if(foodChosen[2] == "y" || foodChosen[2] == "Y"){
            cout << "  - Beef Bulalo (Php 950)" << foodAmount[2] << endl;
            beef = 950;
        }
        if(foodChosen[3] == "y" || foodChosen[3] == "Y"){
            cout << "  - Seafood Chowder (Php 830)" << foodAmount[3] << endl;
            seafood = 830;
        }
    }
    foodServiceCost = foodItems(foodChoice,pancakes,tapsilog,longsilog,bacsilog,sinigang,adobo,kare,fillet,burger,pasta,beef,seafood,foodAmount);
    cout << endl;

    cout << left << setw(35)<< "Food Service Total:"<< "Php "<< foodServiceCost<< endl;
    }

    if(spa == "y"){
    cout << YELLOW;
    cout << "--------------------------------------------------" << endl;
    cout << "PRIVATE SPA SERVICES" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << RESET;

    if(treatChosen[0] == "y" || treatChosen[0] == "Y"){
        cout << "  - Hot Stone Treatment (Php 999)" << endl;
        hotstone = 999;
    }
    if(treatChosen[1] == "y" || treatChosen[1] == "Y"){
        cout << "  - Aromatherapy Treatment (Php 789)" << endl;
        aroma = 789;
    }
    if(treatChosen[2] == "y" || treatChosen[2] == "Y"){
        cout << "  - Facial Treatment (Php 1599)" << endl;
        facial = 1599;
    }
    if(treatChosen[3] == "y" || treatChosen[3] == "Y"){
        cout << "  - Sauna (Php 1399)" << endl;
        sauna = 1399;
    }
    int spaCost = treatItems(hotstone, aroma, facial, sauna);
    cout << endl;
    cout << left << setw(35)<< "Private Spa Total:"<< "Php "<< spaCost<< endl;
    }
    cout << YELLOW;
    cout << "--------------------------------------------------" << endl;
    cout << "SERVICE COST SUMMARY" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << RESET;

    cout << left << setw(35) << "Additional Service Charges:"<< "Php "<< serviceCost(roomServiceCost, foodServiceCost, spaCost)<< endl;
    cout << endl;
    cout << GREEN;
    cout << "==================================================" << endl;
    cout << left << setw(35) << "TOTAL AMOUNT DUE:" << "Php " << totalBill(roomCost,numOfNights,numOfPeople,roomServiceCost,foodServiceCost,spaCost, seniorDiscount) << endl;
    cout << "==================================================" << endl;
    cout << RESET;
    cout << endl;
    cout << endl;
    printHeader("                 RESERVATION CONFIRMATION");
    cout << "Please scroll up to review your reservation details above." << endl;
    cout << "Confirm reservation?: ";
    cout << YELLOW;
    cout << "\nEnter 'y' to confirm or 'n' to cancel: ";
    cout << RESET;
    do{

        cin >> confirm;

        if(confirm == "Y" || confirm == "y")
        {
         srand(time(0));
            int bookingID = rand() % 9000 + 1000;
          printHeader("                 RESERVATION CONFIRMED");
         cout << "Thank you for choosing Astra Suite Hotel!" << endl;
         cout << YELLOW;
           cout << "\t Booking Reference: ASTRAL-" << bookingID << endl;
          cout << RESET;
           cout << "\t Please present this booking reference upon check-in." << endl;
          cout << " " << endl;
           cout << "Thank you for choosing The Astral Suite Hotel!" << endl;
           cout << "We look forward to serving you. Have a pleasant stay!" << endl;
           cout << CYAN;
            cout << "==========================================================" << endl;
            cout << RESET;
        }
        else if(confirm == "N" || confirm == "n")
        {
            printHeader("                 RESERVATION CANCELLED");
            cout << "Thank you for choosing The Astral Suite Hotel!" << endl;
            cout << "Please restart the program to make a new booking." << endl;
            cout << CYAN;
            cout << "====================================================" << endl;
            cout << RESET;

        }
        else{
            cout << "Please enter a valid input." << endl << endl;
        }

    }while(reservCheck == false);
    
    return 0;
}