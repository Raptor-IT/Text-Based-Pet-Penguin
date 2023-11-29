
#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

int x = 0;
int option;
float MinValue = 0.0;
float Hunger = 25.0;
float Bordem = 25.0;
float PetState = 50.0;
float full = 23.0;
float tierd = 23.0; 
bool GameOver = false;
string PetName;


void Feed() {
    cout << " " << endl;
    cout << "You had fed " << PetName << endl;
    if (Hunger > full) {
        cout << " " << endl;
        cout << PetName << " Is getting full" << endl;
        Hunger = full;
    } else; {
        cout << "*Eating Noises*" << endl;
        Hunger = Hunger + 7.0;
    }
    

}

void Play() {
    if (Bordem > tierd) {
        cout << " " << endl;
        cout << PetName << " Is getting tierd of playing right now" << endl;    
        Bordem = tierd; 
    }
    cout << " " << endl;
    cout << "You played with " << PetName << endl;
    cout << "Yay !" << endl;
    Bordem = Bordem + 7.0;

}

void CheckState() {
    cout << "You checked on " << PetName << endl;
    cout << "Hunger: " << Hunger << endl;
    cout << "Bordem: " << Bordem << endl;

}

void TimePassing() {
    int i;
    int HungerDec = 0;
    int BordemDec = 0;

    srand((unsigned)time(NULL));
    for (i = 0; i < 4; i++) {
        HungerDec = rand() % 4;
        BordemDec = rand() % 4;
    }
    Hunger = Hunger - HungerDec;
    Bordem = Bordem - BordemDec;

    if (Hunger <= 0) {
        cout << PetName << "Has starved to death" << endl;
        cout << "(X_" << endl; 
        cout << "//\ " << endl; 
        cout << "V_/_" << endl; 
        cout << "GameOver" << endl;
        GameOver = true; 
        exit(0); 
    }
    else if (Bordem <= 0) {
        cout << PetName << "is getting depressed" << endl;
        Bordem = MinValue;
    }
    else {
        PetState = Hunger + Bordem;
    }
}


void PetMood() {

    if (PetState > 37.5) {
        cout << " " << endl;
        cout << PetName << " Is happy" << endl;
        cout << "(o<" << endl;
        cout << "//\ " << endl;
        cout << "V_/_" << endl;
        cout << " " << endl;
    }
    else if (PetState < 37.5 and PetState >= 25) {
        cout << " " << endl;
        cout << PetName << " Could be better" << endl;
        cout << "(o_" << endl;
        cout << "//\ " << endl;
        cout << "V_/_" << endl;
        cout << " " << endl;
    }
    else if (PetState < 25 and PetState >= 12.5) {
        cout << " " << endl;
        cout << PetName << " Is unhappy" << endl;
        cout << "(o> " << endl;
        cout << "//\ " << endl; 
        cout << "V_/_" << endl; 
        cout << " " << endl; 
    }   
    else if (PetState < 12.5) {
        cout << " " << endl;
        cout << PetName << " Is extreamly angry" << endl; 
        cout << "(O_ " << endl; 
        cout << "//\ " << endl;
        cout << "V_/_" << endl;
        cout << " " << endl;
    }
}

int main()
{
    cout << "Please Name your pet penguin" << endl;
    cin >> PetName;
    cout << "You have named your pet penguin " << PetName << endl;

    while (GameOver == false) {
        cout << "How would you like to interact with " << PetName << endl;
        cout << "Press 1 to feed " << PetName << endl;
        cout << "Press 2 to play a game with " << PetName << endl;
        cout << "Press 3 to check on " << PetName << endl;
        cout << "Press 4 to quit" << endl;
        cin >> option;

        switch (option) {
        case 1:
            TimePassing();
            Feed();
            PetMood();
            cout << " " << endl;
            break;
        case 2:
            TimePassing();
            Play();
            PetMood();
            cout << " " << endl;
            break;
        case 3:
            TimePassing();
            CheckState();
            PetMood();
            cout << " " << endl;
            break;
        case 4:
            cout << "The program will now close";
            return(0);
        deafult:
            cout << "Incorrect input try again";
        }
    }
}