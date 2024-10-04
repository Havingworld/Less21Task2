
#include <iostream>
#include <vector>
#include <string>

struct structRoom
{
    std::string sTypeRoom;
    float fAreaRoom{ 1.0f };
};

struct stuctFloor 
{
    float fCeilingHeight{ 2.0f };
    int nNumRooms{ 2 };
    std::vector <structRoom> vecRooms;

};

struct structBuilding
{

    std::string sTypeBuilding;
    int nNumFloors{ 1 };
    std::vector <stuctFloor> vecFloors;
    bool bFireplace{ false };
    float fAreaBuilding{ 1.0f };

};

int main()
{

    int nNumPlotsLand{ 0 }; //var for cycle of entering plots of land in village vector
    std::cout << "Enter the number of plots land in village: ";
    std::cin >> nNumPlotsLand;

    std::vector <structBuilding> vecPlotsLand; //вектор для количества зданий на участке
    std::vector <std::vector <structBuilding>> vecVillage; //вектор с участками
    
    for (int i = 0; i < nNumPlotsLand; i++) { // нарезали кусок земли на участки
        vecVillage.push_back(vecPlotsLand);
    }

    for (int i = 0; i < vecVillage.size(); i++) { //строим здания на участках
        int nNumBuildingsOnPlotsLand{ 0 }; //var for cycle of entering plots of land in village vector
        std::cout << "Enter the number of buildings on plot land #" << i << ": ";
        std::cin >> nNumBuildingsOnPlotsLand;

        for (int j = 0; j < nNumBuildingsOnPlotsLand; j++) { // заполняем вектор с домами
            structBuilding building;
            vecVillage[i].push_back(building);
        }

    }
    
    for (int i = 0; i < vecVillage.size(); i++) { //описание каждого дома на участке
        for (int j = 0; j < vecVillage[i].size(); j++) { 
            std::cout << "Enter a description of the building #" << j << " on plot land #" << i << "\n";
            std::cout << "Enter a type of the building (home, sauna, garage, barn, etc.): ";
            std::cin >> vecVillage[i][j].sTypeBuilding;
            if (vecVillage[i][j].sTypeBuilding == "home") {
                std::cout << "Enter the number of floors(1-4): ";
                std::cin >> vecVillage[i][j].nNumFloors;
                for (int k = 0; k < vecVillage[i][j].nNumFloors; k++) { //строим этажи
                    stuctFloor floor;
                    std::cout << "Enter the ceiling height floor #" << k <<": ";
                    std::cin >> floor.fCeilingHeight;
                    std::cout << "Enter the number of rooms(2-4): ";
                    std::cin >> floor.nNumRooms;
                    for (int l = 0; l < floor.nNumRooms; l++) { //разбиваем этажи на комнаты
                        structRoom room;
                        std::cout << "Enter type of room #" << k << l << "\n";
                        std::cout << "Bedroom, kitchen, bathroom, nursery, livingRoom, etc.: ";
                        std::cin >> room.sTypeRoom;
                        std::cout << "Enter area of room: ";
                        std::cin >> room.fAreaRoom;
                        floor.vecRooms.push_back(room);
                    }

                    vecVillage[i][j].vecFloors.push_back(floor);
                }
                std::cout << "There is a fireplace in the house? true/false: ";
                std::cin >> vecVillage[i][j].bFireplace;
            }
            if (vecVillage[i][j].sTypeBuilding == "sauna") {
                std::cout << "There is a fireplace in the burnhouse? true/false: ";
                std::string sFireplace{""};
                std::cin >> sFireplace;
                vecVillage[i][j].bFireplace ? sFireplace == "true" : sFireplace == "false";
            }
            std::cout << "Enter area of building: ";
            std::cin >> vecVillage[i][j].fAreaBuilding;
        }

    }

    //вывод вектора
     
    for (int i = 0; i < vecVillage.size(); i++) {
       
        std::cout << "Buildings on plot land #" << i << ": ";

        for (int j = 0; j < vecVillage[i].size(); j++) {
            std::cout << vecVillage[i][j].sTypeBuilding << " ,";
        }

        std::cout << '\n';
    }
    
    return 1;
}

