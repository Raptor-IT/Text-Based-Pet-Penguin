
#include <iostream>
#include <cstdlib> 
using namespace std; 

int x = 0;
int option;
float MinValue = 0.0;
float Hunger = 25.0;
float Bordem = 25.0;
float PetState = 50.0;
string PetName;


void Feed() {
    cout << "You had fed " << PetName << endl;
    cout << "*Eating Noises*" << endl; 
    Hunger + 3; 

}

void Play() {
    cout << "You played with " << PetName << endl;
    cout << "Yay !" << endl; 
    Bordem + 3;

}


void CheckState() {
    cout << "You checked on " << PetName << endl;
    cout << "Hunger: " << Hunger << endl; 
    cout << "Bordem: " << Bordem << endl; 
    
}


void TimePassing() {
    Hunger = Hunger - rand() % 5;
    Bordem = Hunger - rand() % 5;
     
    if (Hunger <= 0) {
        cout << PetName << "Has starved to death" << endl;
        cout << "GameOver" << endl; 
        x == 1;
        
    }else if (Bordem <= 0) {
        cout << PetName << "is getting depressed" << endl;
        Bordem == MinValue; 
    }else {
        PetState = PetState + Hunger + Bordem;
     }
}


void PetMood() {

    if (PetState > 37.5) {
        cout << PetName << " Is happy" << endl;
    }else if (PetState < 37.5 and PetState >= 25){
        cout << PetName << " Could be better" << endl; 
    }else if (PetState < 25 and PetState >= 12.5){
        cout << PetName << " Is unhappy" << endl;
    }else if (PetState < 12.5) {
        cout << PetName << " Is extreamly angry";
    }
}


int main()
{   
    cout << "Please Name your pet penguin" << endl;
    cin >> PetName;
    cout << "You have named your pet penguin " << PetName << endl;

    while (x == 0) {
        cout << "How would you like to interact with " << PetName << endl;
        cout << "Press 1 to feed " << PetName << endl;
        cout << "Press 2 to play a game with " << PetName << endl;
        cout << "Press 3 to check on " << PetName << endl;
        cout << "Press 4 to quit" << endl; 
        cin >> option;

        switch (option) {
            case 1:
                Feed();
                TimePassing();
                PetMood();

                break; 
            case 2:
                Play(); 
                TimePassing();
                PetMood();

                break; 
            case 3:
                TimePassing();
                CheckState();
                PetMood(); 
                break; 
            case 4:
                cout << "The program will now close"; 
                return(0);

            deafult:
                cout << "Incorrect input try again";
        }
    }      
}

