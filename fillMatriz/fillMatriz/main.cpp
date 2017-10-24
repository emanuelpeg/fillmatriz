#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void cambiarA0(int ** matriz)
{
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {

            if (matriz[i][j] == -1) matriz[i][j] =0;

        }
    }
}

int countAll0(int ** matriz)
{
    int acu = 0;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {

            if (matriz[i][j] == 0) acu++;

        }
    }

    return acu;
}

int count0(int x,int y, int ** matriz)
{
    if (x >= 0 && x < 50 && y >= 0 && y < 50) {
        if(matriz[x][y] == 0)
        {
            matriz[x][y] = -1;
            return 1 + count0(x+1,y, matriz)
                    + count0(x-1,y, matriz)
                    + count0(x,y+1, matriz)
                    + count0(x,y-1, matriz);
        }
    }
    return 0;
}

int construirPuertaX(int proximaPuertaX, int proximaPuertaY, int ** matriz, bool &derecha){
    if (derecha) {
        while (proximaPuertaX < 50) {
            if (matriz[proximaPuertaX][proximaPuertaY] == 1) {
                matriz[proximaPuertaX][proximaPuertaY] = 0;
                return proximaPuertaX;
            }
            proximaPuertaX++;
        }
        derecha = false;
        return proximaPuertaX -1;
    } else {
        while (proximaPuertaX >= 0) {
            if (matriz[proximaPuertaX][proximaPuertaY] == 1) {
                matriz[proximaPuertaX][proximaPuertaY] = 0;
                return proximaPuertaX;
            }
            proximaPuertaX--;
        }
        derecha = true;
        return proximaPuertaX + 1;
    }
    return 0;
}

int construirPuertaY(int proximaPuertaX, int proximaPuertaY, int ** matriz, bool &abajo){
    if (abajo) {
        while (proximaPuertaY < 50) {
            if (matriz[proximaPuertaX][proximaPuertaY] == 1) {
                matriz[proximaPuertaX][proximaPuertaY] = 0;
                return proximaPuertaY;
            }
            proximaPuertaY++;
        }
        abajo = false;
        return proximaPuertaY -1;
    } else {
        while (proximaPuertaY >= 0) {
            if (matriz[proximaPuertaX][proximaPuertaY] == 1) {
                matriz[proximaPuertaX][proximaPuertaY] = 0;
                return proximaPuertaY;
            }
            proximaPuertaY--;
        }
        abajo = true;
        return proximaPuertaY + 1;
    }
}

int main()
{
    int ** matriz = new int*[50];
    for (int i = 0; i < 50; i++) {
        matriz[i] = new int[50];
        for (int j = 0; j < 50; j++) {

            matriz[i][j] = 0;

        }
    }

    int i = 0;

    srand(time(NULL));
    while (i <= 8) {
        int r = rand() % 4  + 1 + 5 * i;
        int c = rand() % 4 + 1 + 5 * i;

        for (int j = 0; j < 50; j++){
            matriz[r][j] = 1;
        }

        for (int j = 0; j < 50; j++){
            matriz[j][c] = 1;
        }
        i++;
    }

    int zerosArea = count0(0, 0, matriz);
    cambiarA0(matriz);
    int Allzeros = countAll0(matriz);

    int proximaPuertaX = 0;
    int proximaPuertaY = 0;

    bool derecha = true;
    bool abajo = true;

    bool enX = rand() % 2;

    while (zerosArea < (Allzeros)) {

        if (enX) {
            proximaPuertaX = construirPuertaX(proximaPuertaX, proximaPuertaY, matriz, derecha);
            enX = rand() % 2;

            if (derecha) {
                if (proximaPuertaX < 48) proximaPuertaX++;
            } else {
                if (proximaPuertaX > 0) proximaPuertaX--;
            }

        } else {
            proximaPuertaY = construirPuertaY(proximaPuertaX, proximaPuertaY, matriz, abajo);
            enX = rand() % 2;

            if (derecha) {
                if (proximaPuertaY < 48) proximaPuertaY++;
            } else {
                if (proximaPuertaY > 0) proximaPuertaY--;
            }
        }

        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                cout << matriz[i][j];
            }
            cout << endl;
        }

        cout<< proximaPuertaX << " " << proximaPuertaY << endl;

        zerosArea = count0(0, 0, matriz);
        cambiarA0(matriz);
        Allzeros = countAll0(matriz);

        cout<< zerosArea << " " << Allzeros << endl;
//        char a;
//        cin >> a;
    }

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            cout << matriz[i][j];
        }
        cout << endl;
    }

    return 0;
}


