#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Weapons{
public:
    string Name;
    int Damage;
    int Accuracy;

    Weapons(string name, int damage, int accuracy){
        Name = name;
        Damage = damage;
        Accuracy = accuracy;
        cout << "Weapons created!" << endl;
    }

    void printer() {
        cout << "Damage:" << Damage << endl;
        cout << "Accuracy:" << Accuracy << endl;
    }

    bool hit() {
        srand(time(0));
        int randomNum = rand() % 101;
        if (randomNum <= Accuracy) {
            cout << "Hit!" << endl;
            return true;
        }
        cout << "Miss!" << endl;
        return false;
    }
};

class Players{
public:
    string Name;
    vector<Weapons> PlayerWeapons;
    int Health = 100;

    Players(string name, vector<Weapons> weapons) {
        Name = name;
        PlayerWeapons = weapons;
    }
};

void play(Players &p1, Players &p2) {
    while (true) {
        for (int i = 0; i < p1.PlayerWeapons.size(); i++) {
            cout << i + 1 << ". " << p1.PlayerWeapons[i].Name
            << ": Damage: " << p1.PlayerWeapons[i].Damage
            << ", Accuracy: " << p1.PlayerWeapons[i].Accuracy << endl;
        }
        int choosed;
        cout << "P1, Choose your move (Enter the num): "; cin >> choosed;
        bool hit;
        Weapons *we;
        while (true) {
            switch (choosed) {
                case 1: {we = &p1.PlayerWeapons[0]; hit = p1.PlayerWeapons[0].hit(); break;}
                case 2: {we = &p1.PlayerWeapons[1]; hit = p1.PlayerWeapons[1].hit(); break;}
                case 3: {we = &p1.PlayerWeapons[2]; hit = p1.PlayerWeapons[2].hit(); break;}
                default: {cout << "P1, Choose your move (Enter the num): "; cin >> choosed; continue;}
            }
            break;
        }
        if (hit) {
            p2.Health -= we->Damage;
            cout << "P2 Health: " << max(p2.Health, 0) << endl;
        }
        if (p2.Health <= 0) {
                cout << "P1 Wins!" << endl;
                return;
        }

        for (int i = 0; i < p2.PlayerWeapons.size(); i++) {
            cout << i + 1 << ". " << p2.PlayerWeapons[i].Name
            << ": Damage: " << p2.PlayerWeapons[i].Damage
            << ", Accuracy: " << p2.PlayerWeapons[i].Accuracy << endl;
        }
        cout << "P2, Choose your move (Enter the num): "; cin >> choosed;
        while (true) {
            switch (choosed) {
                case 1: {we = &p2.PlayerWeapons[0]; hit = p2.PlayerWeapons[0].hit(); break;}
                case 2: {we = &p2.PlayerWeapons[1]; hit = p2.PlayerWeapons[1].hit(); break;}
                case 3: {we = &p2.PlayerWeapons[2]; hit = p2.PlayerWeapons[2].hit(); break;}
                default: {cout << "P2, Choose your move (Enter the num): "; cin >> choosed; continue;}
            }
            break;
        }
        if (hit) {
            p1.Health -= we->Damage;
            cout << "P1 Health: " << max(p1.Health, 0) << endl;
        }
        if (p1.Health <= 0) {
                cout << "P2 Wins!" << endl;
                return;
        }
    }
}

int main() {
    cout << "Hello world!" << endl;
    Weapons Ion_Rifle("Ion_Rifle", 6, 100);
    Weapons Energon_Swords("Energon_Swords", 12, 80);
    Weapons Shoulder_Canon("Shoulder_Canon", 45, 25);
    Weapons Fusion_Canon("Fusion_Canon", 9, 90);
    Weapons Fusion_Sword("Fusion_Sword", 18, 70);
    Weapons Tank_Mode("Tank_Mode", 60, 15);

    Players Optimus_Prime("Optimus Prime", {Ion_Rifle, Energon_Swords, Shoulder_Canon});
    Players Megatron("Megatron", {Fusion_Canon ,Fusion_Sword, Tank_Mode});

    play(Optimus_Prime , Megatron);

    return 0;
}
