//*****************************************************************************
// Author: Evelyn Zuniga
// Assignment: Sneaker Collection Management Part 2
// Description: This program implemented more features to Part 1 such as 
//              more void functions that allow the user to see the sneakers
//              by brand, price, size, and year released.
// *******************************************************************************

#include <iostream>
#include <string>


using namespace std;

// enumeration data types for the sneakers
enum SneakerBrand { NIKE, ADIDAS, JORDAN, NEW_BALANCE, VANS, OTHER };
enum SneakerCategory { RUNNING, BASKETBALL, LIFESTYLE, SKATE, TRAINING };

// struct for the sneaker
struct Sneaker
{
	string modelName; // name of sneaker model
	SneakerBrand brand; // brand of sneaker
	SneakerCategory category; // category of sneaker
	double size; // shoe size
	double price; // retail price in USD
	bool isDeadstock; // true is unworn/in box
	int yearReleased; // year the shoe was released
};

// function prototypes
string brandToString(SneakerBrand b); // returns the brand name as a readable string
string categoryToString(SneakerCategory c); // returns the category as a readable string
void displaySneaker(Sneaker s); // prints all fields of a sneaker
void displayAll(Sneaker arr[], int count); // calls displaySneaker for every item
void addSneaker(Sneaker arr[], int &count); // allows user to add a sneaker to collection
void searchByBrand(Sneaker arr[], int count, SneakerBrand target); // prints all sneakers matching the given brand
void searchBySize(Sneaker arr[], int count, double targetSize); // prints all sneakers matching the exact size
void sortByPrice(Sneaker arr[], int count); // sorts the collection from lowest to highest price in place
void sortByYear(Sneaker arr[], int count); // sorts from oldest to newest.

//constant
const int MAX_SNEAKERS = 20;
Sneaker collection[MAX_SNEAKERS];
int count = 0;


int main()
{
    
    collection[count] = {"Air Force 1 '07 ", NIKE, LIFESTYLE, 5, 110, false, 2007}; 
    count++;
    
    collection[count] = {"Samba", ADIDAS, LIFESTYLE, 6, 100, true, 2025}; 
    count++;
    
    collection[count] = {"Air Jordan 2K10", JORDAN, BASKETBALL, 5.5, 75, true, 2010}; 
    count++;
    
    collection[count] = {"New Balance 9060", NEW_BALANCE, RUNNING, 5, 159.99, false, 2025}; 
    count++;
    
    collection[count] = {"Vans Old Skool", VANS, SKATE, 5, 60, true, 1990}; 
    count++;
    
    collection[count] = {"Converse Chuck Taylor II", OTHER, LIFESTYLE, 6.5, 65.99, false, 2015}; 
    count++;
    
    collection[count] = {"Nike Pegasus 41", NIKE, RUNNING, 6, 144.99, true, 2024}; 
    count++;
    
    collection[count] = {"Adidas Gazelle Lo Pro", ADIDAS, LIFESTYLE, 5, 140, false, 2025}; 
    count++;
    
    
    int choice;
    
	do {
	    // display menu
	    cout << "===== Sneaker Collection Manager =====" << endl;
	    cout << "1. Display All Sneakers" << endl;
	    cout << "2. Add a Sneaker" << endl;
	    cout << "3. Search by Brand" << endl;
	    cout << "4. Search by Size" << endl;
	    cout << "5. Sort by Price" << endl;
	    cout << "6. Sort by Year" << endl;
	    cout << "0. Exit" << endl;
	    cout << "Enter choice (must be a number 0-6): ";
        cin >> choice;
	    
	    while (cin.fail()|| choice < 0 || choice > 6) 
                    {
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout << "Invalid choice. Please enter a number between 0 and 6" << endl;
                        cin >> choice;
                    }
	 
        
        switch (choice) {
            case 1: 
                displayAll(collection, count);
            break;
            
            case 2: 
                addSneaker(collection, count);
            break;
            
            case 3:
                {
                    int brandChoice; 
                    cout << "Please choose a brand you want to search for (0-5)" << endl;
                    cout << "0. Nike\n1. Adidas\n2. Jordan\n3. New Balance\n4. Vans\n5. Other\n";
                    cin >> brandChoice;
                    while (cin.fail()|| brandChoice < 0 || brandChoice > 5) 
                    {
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout << "Invalid choice. Please enter a number between 0 and 5" << endl;
                        cin >> brandChoice;
                    }
                    searchByBrand(collection, count, static_cast<SneakerBrand>(brandChoice));
                }
                break;
                
            case 4:
                {
                    double sneakerSize; // allows user to enter a size
                    cout << "Please enter a size" << endl;
                    cin >> sneakerSize;
                    while (cin.fail()|| sneakerSize < 0 || sneakerSize > 40) 
                    {
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout << "Please enter a valid size" << endl;
                        cin >> sneakerSize;
                    }
                    searchBySize(collection, count, sneakerSize);
                }
                break;
                
            case 5:
                sortByPrice(collection, count);
                cout << "Sneakers from cheapest to most expensive" << endl;
                displayAll(collection, count);
                break;
                
            case 6:
                sortByYear(collection, count);
                cout << "Sneakers from oldest to newest" << endl;
                displayAll(collection, count);
            break;
            
            case 0:
            cout << "Goodbye, thank you for using the Sneaker Collection Manager" << endl;
            break;
            
            default:
            cout << "Invalid choice! Please enter a number 0-6." << endl;
            
        }
	    
	} while (choice != 0);
	
	return 0;
     
}
// returns the brand name as a readable string
string brandToString(SneakerBrand b) {
    switch (b) {
        case NIKE: 
        return "Nike";
        
        case ADIDAS:
        return "Adidas";
        
        case JORDAN: 
        return "Jordan";
        
        case NEW_BALANCE: 
        return "New Balance";
        
        case VANS: 
        return "Vans";
        
        default: 
        return "Other brand";
    }
}

// returns the category as a readable string
string categoryToString(SneakerCategory c) {
    switch (c) {
        case RUNNING: 
        return "Running";
        
        case BASKETBALL: 
        return "Basketball";
        
        case LIFESTYLE: 
        return "Lifestyle";
        
        case SKATE: 
        return "Skate";
        
        case TRAINING: 
        return "Training";
        
        default: 
        return "Unknown Category";
    }
}

// prints all fields of a sneaker
void displaySneaker(Sneaker s) {
    cout << "Sneaker Information" << endl;
    cout << "---------------------------" << endl;
    cout << "Sneaker Model: " << s.modelName << endl;
    cout << "Sneaker Brand: " << brandToString(s.brand) << endl;
    cout << "Sneaker Category: " << categoryToString(s.category) << endl;
    cout << "Sneaker Size: " << s.size << endl;
    cout << "Sneaker Price: $ " << s.price << endl;
    
    cout << "Deadstock: ";
    if (s.isDeadstock) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    cout << "Year Released: " << s.yearReleased << endl;
}

// calls displaySneaker for every item
void displayAll(Sneaker arr[], int count) {
    for (int i = 0; i < count; i++) {
        displaySneaker(arr[i]);
    }
    
    if (count == 0) {
        cout << "Sorry :( , there are no sneakers in your collection" << endl;
    }
}

// allows user to add a sneaker to collection
void addSneaker(Sneaker arr[], int &count) {
    if (count >= MAX_SNEAKERS) 
    { 
        cout << "Cannot add anymore sneakers" << endl;
        return;
    }
    
    Sneaker newSneaker; // temporary variable so that you can add a new sneaker
    
    // varaibles for the brand choice and category choice
    int brandChoice;
    int categoryChoice;
    
    cin.ignore();
    
    cout << "Enter model name: " << endl;
    getline(cin, newSneaker.modelName); // get line is used in case user enters a namespace
    
    
    cout << "Enter sneaker brand: " << endl;
    cout << "0. Nike\n1. Adidas\n2. Jordan\n3. New Balance\n4. Vans\n5. Other\n";
    cin >> brandChoice;
    while (cin.fail()|| brandChoice < 0 || brandChoice > 5) 
                    {
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout << "Invalid choice. Please enter a number between 0 and 5" << endl;
                        cin >> brandChoice;
                    }
    newSneaker.brand = static_cast<SneakerBrand>(brandChoice);
    
    cout << "Enter sneaker category: " << endl;
    cout << "0. Running\n1. Basketball\n2. Lifestyle\n3. Skate\n4. Training\n";
    cin >> categoryChoice; 
    while (cin.fail()|| categoryChoice < 0 || categoryChoice > 4) 
                    {
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout << "Invalid choice. Please enter a number between 0 and 4" << endl;
                        cin >> categoryChoice;
                    }
    newSneaker.category = static_cast<SneakerCategory>(categoryChoice);
    
    cout << "Enter sneaker size: " << endl;
    cin >> newSneaker.size;
    while (cin.fail()|| newSneaker.size < 0 || newSneaker.size > 40) 
                    {
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout << "Please enter a valid size" << endl;
                        cin >> newSneaker.size;
                    }
    
    cout << "Enter sneaker price: " << endl;
    cin >> newSneaker.price;
    while(cin.fail() || newSneaker.price <0)
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Please enter a valid price" << endl;
        cin >> newSneaker.price;
    }
    
    cout << "Is the sneaker deadstock? (1 = Yes and 0 = No " << endl;
    cin >> newSneaker.isDeadstock;
    while(cin.fail() || newSneaker.isDeadstock != 0 && newSneaker.isDeadstock != 1)
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Please enter 1 for Yes and 0 for No" << endl;
        cin >> newSneaker.isDeadstock;
    }
    
    cout << "Enter the year the sneaker was released: " << endl;
    cin >> newSneaker.yearReleased;
    if (cin.fail())
    {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Please enter a number for the year: ";
            cin >> newSneaker.yearReleased;
    }
    
    arr[count] = newSneaker;
    count ++;
    
    cout << "Congrats, you added a sneaker!!" << endl;
    
}

// searches by the sneaker's brand
void searchByBrand(Sneaker arr[], int count, SneakerBrand target) {

    bool sneakerFound = false; // checks if there is a sneaker w/ that brand name
    
    for (int i = 0; i < count; i++) 
    {
        if (arr[i].brand == target)
        {
            displaySneaker(arr[i]);
            sneakerFound = true;
        }
    }
    
    if (!sneakerFound) 
    {
        cout << "Sorry !! No sneakers found for that brand" << endl;
    }
}

// searches and prints all sneakers matching the exact size
void searchBySize(Sneaker arr[], int count, double targetSize) {
    
     bool sneakerFound = false; // checks if there is a sneaker w/ that exact size
     
      for (int i = 0; i < count; i++) {
        if (arr[i].size == targetSize)
        {
            displaySneaker(arr[i]);
            sneakerFound = true;
        }
}
    
    if (!sneakerFound) {
        cout << "Sorry !! No sneakers found for that size" << endl;
    }
}

// sorts the sneakers by price from lowest to highest
void sortByPrice(Sneaker arr[], int count) {
    int minIndex;
    
    for (int i = 0; i < count - 1; i++) {
        minIndex = i;
        
        for (int j = i + 1; j < count; j++) 
        {
            if (arr[j].price < arr[minIndex].price)
                minIndex = j;
        }
        
        Sneaker temp = arr[i]; // temporary variable
        arr[i] = arr[minIndex]; // moves the sneaker foward
        arr[minIndex] = temp;
    }
}

// sorts from oldest to newest.
void sortByYear(Sneaker arr[], int count) {
    int minIndex;
    
    for (int i = 0; i < count - 1; i++) {
        minIndex = i;
        
        for (int j = i + 1; j < count; j++) 
        {
            if (arr[j].yearReleased < arr[minIndex].yearReleased)
                minIndex = j;
        }
        
        Sneaker temp = arr[i]; // temporary variable
        arr[i] = arr[minIndex]; // moves the sneaker foward
        arr[minIndex] = temp;
    }
    
}