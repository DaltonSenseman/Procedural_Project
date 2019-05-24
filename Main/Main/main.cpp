/**
 *   @file main.cpp
 *   COP-2001 Procedural Project
 *	@brief
 *
 *	An inventory management system for OraclProduction Ltd. That allows for users to be create accounts and manage inventory.
 *
 *	@author Dalton Senseman
 *	@version 0.0 5/16/2019
 *	@bug Char inputs to menu cause infin loop
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

void printMenu();
void mainMenuSwitch();
void printStartWelcome();
void produceItem();
void addMusicPlayer();

int main()
{
    printStartWelcome();
    printMenu();
    mainMenuSwitch();
    return 0;
}

/**
 *	@brief Prints the welcome menu to the console displaying verson number and date of last version
 */
void printStartWelcome()
{
    std::cout << "\t\311" << std::flush;

    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\315" << std::flush;
    }

    std::cout << "\273" << std::endl;
    std::cout << "\t\272              -Welcome-                \272" << std::endl;
    std::cout << "\t\272   OraclProduction Ltd. Inv. Manager   \272" << std::endl;
    std::cout << "\t\307" << std::flush;

    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\304" << std::flush;
    }

    std::cout << "\266" << std::endl;
    std::cout << "\t\272                                       \272" << std::endl;
    std::cout << "\t\272                                       \272" << std::endl;
    std::cout << "\t\272                                       \272" << std::endl;
    std::cout << "\t\272 Ver: 0.1.1              Date: 05-2019 \272" << std::endl;
    std::cout << "\t\310" << std::flush;

    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\315" << std::flush;
    }
    std::cout << "\274" << std::endl;
    system("Pause");
}

/**
 *	@brief Prints the Main menu of the program so users can see what options they have to pick from
 */
void printMenu()
{
    // \xxx codes are octal codes from the Axcii table
    // so cmd can display the characters for box drawing as only Axcii is supported
    std::cout << "\t\311" << std::flush;
    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\315" << std::flush;
    }
    std::cout << "\273" << std::endl;
    std::cout << "\t\272       Production Line Tracker         \272" << std::endl;
    std::cout << "\t\307" << std::flush;
    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\304" << std::flush;
    }
    std::cout << "\266" << std::endl;
    std::cout << "\t\272    1. Produce Items                   \272" << std::endl;
    std::cout << "\t\272    2. Add Employee Account            \272" << std::endl;
    std::cout << "\t\272    3. Add Music Player                \272" << std::endl;
    std::cout << "\t\272    4. Add Movie Player                \272" << std::endl;
    std::cout << "\t\272    5. Display Production Statistics   \272" << std::endl;
    std::cout << "\t\272    6. Exit                            \272" << std::endl;
    std::cout << "\t\310" << std::flush;
    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\315" << std::flush;
    }
    std::cout << "\274" << std::endl;
    std::cout << "\t     Enter your selection: " << std::flush;
}

void mainMenuSwitch()
{
    int menuOption;

    do
    {
        std::cin >> menuOption;
        std::cout << " " << std::endl;

        //main menu switch to select one of the 6 options above.
        switch (menuOption)
        {
            case 1:
                std::cout << "\tSelection 1: Produce Items stub" << std::endl;
                produceItem();
                system("pause");
                break;
            case 2:
                std::cout << "\tSelection 2: Adding Employee Account stub" << std::endl;
                system("pause");
                break;
            case 3:
                std::cout << "\tSelection 3: Adding Music Player stub" << std::endl;
                addMusicPlayer();
                break;
            case 4:
                std::cout << "\tSelection 4: Adding Movie Player stub" << std::endl;
                system("pause");
                break;
            case 5:
                std::cout << "\tSelection 4: Display Production stats stub" << std::endl;
                system("pause");
                break;
            case 6:
                std::cout << "\tSelection Exit" << std::endl;
                std::cout << "\tExiting . . ." << std::endl;
                break;
            default: std::cout << "Unexpected error has occurred in menu selection." << std::endl;
                     std::cout << "Please select a menu option #1-6 on your keyboard." << std::endl;
                break;
        }
        printMenu();

    } while (menuOption != 6);
}

void produceItem()
{
    std::string catalog;
   std::cout << "\tProduce an Item" << std::endl;
   std::fstream productCatalog;
   productCatalog.open("catalog.txt");
   if(productCatalog.is_open())
   {
       while(std::getline(productCatalog, catalog))
       {
           std::cout << catalog << std::endl;
       }
   }
}

void addMusicPlayer()
{
    std::string manufacturer;
    std::string productName;
    std::string itemTypeCode;
    int itemTypeChoice;

    std::cout << "Add new Products" << std::endl;
    std::cout << "Enter the product manufacturer: " << std::flush;
    std::cin >> manufacturer;
    std::cout << "" << std::endl;
    std::cout << "Enter product name: " << std::flush;
    std::cin >> productName;
    std::cout << "-Enter items type-" << std::endl;
    std::cout << "1. Audio\n" <<
              "2. Visual\n" <<
              "3. AudioMobile\n" <<
              "4. VisualMobile\n" << std::endl;
    std::cin >> itemTypeChoice;
    switch(itemTypeChoice)
    {
        case 1:
            itemTypeCode = "MM";
            break;
        case 2:
            itemTypeCode = "VI";
            break;
        case 3:
            itemTypeCode = "AM";
            break;
        case 4:
            itemTypeCode = "VM";
            break;
        default:
            itemTypeCode = "XX";

    }
    std::ofstream productCatalog("catalog.txt", std::ios::app);
    if(productCatalog.is_open())
    {
        productCatalog << "|  "<< manufacturer << "  |  " << productName << "  |  " << itemTypeCode << std::endl;
        productCatalog.close();
    } else std::cout << "Couldn't write to catalog file." << std::endl;
}

