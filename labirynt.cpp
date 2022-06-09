#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Kierunek { start, gora, lewo, dol, prawo };

int main()
{
    fstream file;
    file.open("labirynt.txt", ios::in);
    string labirynt_str;
    Kierunek kierunek = start;
    int labirynt[10][10];
    int line = 0;
    if (file.is_open()) {
        while (file && line < 10) {
            file >> labirynt_str;
            for (int i = 0; i < 10; i++) {
                string s;
                s.push_back(labirynt_str[i]);
                labirynt[line][i] = stoi(s);
            }
            line++;
        }
    }
    else {
        cout << "Plik nieotworzony prawidłowo";
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << to_string(labirynt[i][j]);
        }
        cout << endl;
    }

    int currentX;
    int currentY = 0;
    for (int i = 0; i < 10; i++) {
        if (labirynt[i][0] == 0) {
            currentX = i;
            break;
        }
    }

    while (currentY != 9) {
        string kierunek_str;
        //ruch w gore
        if (kierunek != dol && currentX < 9 && labirynt[currentX - 1][currentY] == 0 && labirynt[currentX - 1][currentY + 1] == 1) {
            kierunek = gora;
            currentX--;
        }
        //ruch w prawo
        else if (kierunek != lewo && labirynt[currentX][currentY + 1] == 0 && labirynt[currentX + 1][currentY + 1] == 1) {
            kierunek = prawo;
            currentY++;
        }
        //ruch w dol
        else if (kierunek != gora && currentX > 0 && labirynt[currentX + 1][currentY] == 0 && labirynt[currentX + 1][currentY - 1] == 1) {
            kierunek = dol;
            currentX++;
        }
        //ruch w lewo
        else if (kierunek != prawo && currentY > 0 && labirynt[currentX][currentY - 1] == 0 && labirynt[currentX - 1][currentY - 1] == 1) {
            kierunek = lewo;
            currentY--;
        }
        //ruch w prawo + dół
        else if (currentX < 9 && labirynt[currentX][currentY + 1] == 0 && labirynt[currentX + 1][currentY + 1] == 0 && labirynt[currentX + 1][currentY] == 1) {
            currentY++;
            cout << "Ide do (" << currentX + 1 << ", " << currentY + 1 << ") " << kierunek_str << endl;
            currentX++;
            kierunek = dol;
        }
        //ruch w górę + prawo
        else if (currentX > 0 && labirynt[currentX - 1][currentY] == 0 && labirynt[currentX - 1][currentY] == 0 && labirynt[currentX][currentY + 1] == 1) {
            currentX--;
            cout << "Ide do (" << currentX + 1 << ", " << currentY + 1 << ") " << kierunek_str << endl;
            currentY++;
            kierunek = prawo;
        }
        //ruch w dół + lewo
        else if (currentX < 9 && currentY > 0 && labirynt[currentX + 1][currentY] == 0 && labirynt[currentX + 1][currentY - 1] == 0 && labirynt[currentX][currentY - 1] == 1) {
            currentX++;
            cout << "Ide do (" << currentX + 1 << ", " << currentY + 1 << ") " << kierunek_str << endl;
            currentY--;
            kierunek = lewo;
        }
        //ruch w lewo + góra
        else if (currentY > 0 && currentX > 0 && labirynt[currentX][currentY - 1] == 0 && labirynt[currentX - 1][currentY - 1] == 0 && labirynt[currentX - 1][currentY] == 1) {
            currentY--;
            cout << "Ide do (" << currentX + 1 << ", " << currentY + 1 << ") " << kierunek_str << endl;
            currentX--;
            kierunek = gora;

        }
        cout << "Ide do (" << currentX + 1 << ", " << currentY + 1 << ") " << endl;
    }

    cout << "Wyszedlem";

    
}

