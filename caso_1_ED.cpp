//existe un teorema llamado four color el cual indica que con tan solo 4 colores es posible pintar las regiones de cualquier mapa de tal forma que dos regiones adyacentes nunca van a tener el mismo color. https://en.wikipedia.org/wiki/Four_color_theorem . cómo demostraría usted por medio de un programa en C++ que un mapa dado cumple con dicho teorema? que estructura de datos diseñaría para que su solución y algoritmo sea simple? cómo le suministraría la información del mapa al algoritmo?

#include <iostream>
using namespace std;

#define AMOUNT_REGIONS 4
#define AMOUNT_POSIBLE_COLORS 4

struct region
{
    int id;
    int neighbours [AMOUNT_REGIONS] = {};
    int regionColor;
};

bool verifyTheorem(region pMap[], int pNeighbours[], int pRegionColor){
    // se recorre cada vecino de la region
    for (int neighbours = 0; neighbours < AMOUNT_REGIONS; ++neighbours){
        // se verifica si es un vecino existente
        if (pNeighbours[neighbours] > 0){
            // si la region actual y el vecino tienen el mismo color, no cumple con el teorema
            if (pRegionColor == pMap[pNeighbours[neighbours] - 1].regionColor){
                return false;
            }
        }
    }
    return true;
}

int getColor(region pMap[], int pNeighbours[]){
    int color = 1;
    for (int index = 0; index < AMOUNT_REGIONS; ++index){
        // si no encontro ningun color util para pintar, entonces no cumple
        if (color == 5){
            return false; 
        }
        else{
            // si tienen el mismo color se sigue buscando
            if (color == pMap[pNeighbours[index] - 1].regionColor){
                ++color;
            }
        }
    }
    return color;
}

bool paintMap(region pMap[]){
    bool condition = true;
    // se recorre cada region
    for (int actualRegion = 0; actualRegion < AMOUNT_REGIONS; ++actualRegion){
        // si no tiene color se le asigna
        if (pMap[actualRegion].regionColor == 0){
            // se busca el color que puede servir
            int color = getColor(pMap, pMap[actualRegion].neighbours);
            // si no hay se informa
            if (color > AMOUNT_POSIBLE_COLORS){
                return false;
            }
            // si hay entonces se actualiza el mapa
            else{
                pMap[actualRegion].regionColor = color;   
            }
        }   
    }
    return condition;
}

int main (){
    // se crean las regiones
    int posibleColors [AMOUNT_POSIBLE_COLORS] = {1,2,3,4};
    region map[AMOUNT_REGIONS] = {
        {1, {2, 3, 4}, 1},
        {2, {3, 1, 4}, 4},
        {3, {1, 2, 4}, 3},
        {4, {1, 2, 3}, 2}
    };

    bool condition = paintMap(map);
    if (condition == false){
        cout << "El mapa no cumple con el teorema de cuatro colores" << endl;
        return 0;
    }
    else{
        // se verifica el teorema
        for (int region = 0; region < AMOUNT_REGIONS; ++region){
        condition = verifyTheorem(map, map[region].neighbours, map[region].regionColor);
        if (condition == false){
            cout << "El mapa no cumple con el teorema de cuatro colores" << endl;
            break;
        }
        }
        if (condition == true){
        cout << "El mapa cumple con el teorema de cuatro colores" << endl;
        }
    }
    return 0;
}