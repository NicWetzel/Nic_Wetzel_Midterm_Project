// Nic Wetzel
// CIS 1202 501
// October 15, 2021

#include <iostream>
#include <string>


using namespace std;

void newCard(string name,int details[10][10])    // Function to enter a new card owned as well as the card number and hit points for that card
{
    string pokemonName;
    int cardNumber;
    int hitPoints;
    cout << "Enter name of Pokemon: ";
    cin.ignore();
    getline(cin, pokemonName);
    cout << "\nEnter card number: ";
    cin >> cardNumber;
    cout << "\nEnter hit points: ";
    cin >> hitPoints;
}

void displayCards(string cardName, int n)   // Function to cycle through the cards entered and to display them
{
    cout << "Cards Owned:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << cardName << endl;
    }
}

void sortCards(int cardDetails, int n)    // Function to sort the cards
{
    int i, j, min_index, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (cardDetails[j] < cardDetails[min_index])
            {
                min_index = j;
                temp = cardDetails[min_index];
                cardDetails[min_index] = cardDetails[i];
                cardDetails[i] = temp;
            }
        }
    }
}

string findCard(string name)    // Function to display a certain card, looking it up by card name
{
    string string1;
    cout << "Which Pokemon card are you looking for? ";
    getline(cin, string1);
    if (string1 == name)
    {
        cout << name << endl;
    }
}

int menu()     // Function to display the menu and validate the user choice
{
    int menuChoice;
    cout << "1. Enter New Card" << endl;
    cout << "2. Display All Cards" << endl;
    cout << "3. Sort Cards in Order" << endl;
    cout << "4. Find Card by Name" << endl;
    cout << "5. Exit" << endl;
    cin >> menuChoice;
    if (menuChoice < 1 || menuChoice > 5)
    {
        cout << "Please enter a valid menu selection." << endl;
        cin >> menuChoice;
    }
    return menuChoice;
}

int main()      // Main function with a switch case to call functions based on the user choices
{
    int cardDetails[10][10];
    string cardName;
    int menuChoice = 0;
    while (menuChoice != 5)
    {
        switch (menuChoice)
        {
        case 0:
            menuChoice = menu();
            break;
        case 1:
            newCard(cardName, cardDetails);
            menuChoice = 0;
            break;
        case 2:
            displayCards(cardName, 10);
            menuChoice = 0;
            break;
        case 3:
            sortCards(cardDetails, 10);
            menuChoice = 0;
            break;
        case 4:
            findCard(cardName);
            menuChoice = 0;
            break;
        case 5:
            break;
        default:
            cout << "Please enter a valid menu selection." << endl;
            menuChoice = 0;
        }
    }
}

