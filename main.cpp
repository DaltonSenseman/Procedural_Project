/**
 *   @file main.cpp
 *   COP-2001 Procedural Project
 *	@brief
 *
 *	An inventory management system for OraclProduction Ltd. That allows for users to create accounts and manage inventory.
 *
 *	@author Dalton Senseman
 *	@version 0.1.2 5/24/2019
 *	@bug Char inputs to menu cause infin loop
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void printMenu();

void mainMenuSwitch();

void printStartWelcome();

void produceItem(std::vector<std::string> &, std::vector<int> &);

void addMusicPlayer(std::vector<std::string> &, std::vector<std::string> &manufacturers);

void addMoviePlayer(std::vector<std::string> &, std::vector<std::string> &manufacturers);

void production_Stats(std::vector<std::string>, std::vector<std::string>, std::vector<int>);

int main() {
    printStartWelcome();
    printMenu();
    mainMenuSwitch();
    return 0;
}

/**
 *	@brief Prints the welcome menu to the console displaying verson number and date of last version
 */
void printStartWelcome() {
    std::cout << "\t\311";

    for (int i = 0; i <= 38; i++) {
        std::cout << "\315";
    }

    std::cout << "\273" << std::endl;
    std::cout << "\t\272              -Welcome-                \272\n";
    std::cout << "\t\272   OraclProduction Ltd. Inv. Manager   \272\n";
    std::cout << "\t\307";

    for (int i = 0; i <= 38; i++) {
        std::cout << "\304" << std::flush;
    }

    std::cout << "\266\n";
    std::cout << "\t\272                                       \272\n";
    std::cout << "\t\272                                       \272\n";
    std::cout << "\t\272                                       \272\n";
    std::cout << "\t\272  v0.1.2                 Date: 05-2019 \272\n";
    std::cout << "\t\310";

    for (int i = 0; i <= 38; i++) {
        std::cout << "\315";
    }
    std::cout << "\274\n";
    system("Pause");
}

/**
 *	@brief Prints the Main menu of the program so users can see what options they have to pick from
 */
void printMenu() {
    // \xxx codes are octal codes from the Axcii table
    // so cmd can display the characters for box drawing as only Axcii is supported
    std::cout << "\t\311";
    for (int i = 0; i <= 38; i++) {
        std::cout << "\315";
    }
    std::cout << "\273\n";
    std::cout << "\t\272       Production Line Tracker         \272\n";
    std::cout << "\t\307";
    for (int i = 0; i <= 38; i++) {
        std::cout << "\304";
    }
    std::cout << "\266\n";
    std::cout << "\t\272    1. Produce Items                   \272\n";
    std::cout << "\t\272    2. Add Employee Account            \272\n";
    std::cout << "\t\272    3. Add Music Player                \272\n";
    std::cout << "\t\272    4. Add Movie Player                \272\n";
    std::cout << "\t\272    5. Display Production Statistics   \272\n";
    std::cout << "\t\272    6. Exit                            \272\n";
    std::cout << "\t\310";
    for (int i = 0; i <= 38; i++) {
        std::cout << "\315";
    }
    std::cout << "\274\n";
    std::cout << "\t     Enter your selection: ";
}

/**
 * @brief Switch for main menu selection letting uses interact with different functions of the program
 */
void mainMenuSwitch() {
    int menuOption;

    // todo: combine Vectors and files to sterilize and keep tabs on total production instead of just instances.
    std::vector<std::string> products;
    std::vector<std::string> manufacturers;
    std::vector<std::string> item_type;
    std::vector<int> produced;


    do {
        std::cin >> menuOption;
        std::cout << " " << std::endl;

        //main menu switch to select one of the 6 options above.
        switch (menuOption) {
            case 1:
                std::cout << "\tSelection 1: Produce Items\n";
                produceItem(products, produced);
                system("pause");
                break;
            case 2:
                std::cout << "\tSelection 2: Adding Employee Account stub\n";
                system("pause");
                break;
            case 3:
                std::cout << "\tSelection 3: Adding Music Player\n";
                addMusicPlayer(products, manufacturers);
                break;
            case 4:
                std::cout << "\tSelection 4: Adding Movie Player\n";
                addMoviePlayer(products, manufacturers);
                break;
            case 5:
                std::cout << "\tSelection 4: Display Production stats stub\n";
                production_Stats(products, manufacturers, produced);
                break;
            case 6:
                std::cout << "\tSelection Exit\n";
                std::cout << "\tExiting . . .\n";
                break;
            default:
                std::cout << "Unexpected error has occurred in menu selection.\n";
                std::cout << "Please select a menu option #1-6 on your keyboard.\n";
                break;
        }
        printMenu();

    } while (menuOption != 6);
}

/**
 * @brief Allows user to produce items from the catalog.txt file into production
 * @param products takes the memory address to allow for items to be printed
 * @param produced takes the memory address to allow for the num of produced items to be added to the vector
 * @bug Catalog not properly formatted for clarity prints sloppy to terminal
 * @return void
 */
void produceItem(std::vector<std::string> &products, std::vector<int> &produced) {
    std::string catalog;
    std::cout << "\tProduce an Item\n";
    std::fstream productCatalog;
    productCatalog.open("catalog.txt");
    if (productCatalog.is_open()) {
        //loop prints the entire catalog to the screen so users can see the products
        while (std::getline(productCatalog, catalog)) {
            std::cout << catalog << std::endl;
        }
    }

    for (auto i = 0; i < products.size(); i++) {
        // sort per loop to stay sorted
        // Todo: change to a copied sorted vector for less mem usage faster speed.
        sort(products.begin(), products.end());
        std::cout << products[i] << '\n';
    }

    std::string manufacturer;
    std::string productName;
    std::string itemTypeCode;
    int itemTypeChoice;
    std::cout << "Produce Products\n";
    std::cout << "Enter the product manufacturer from the list above: ";
    std::cin >> manufacturer;
    std::cout << "" << std::endl;
    std::cout << "Enter product name of the chosen item: ";
    std::cin >> productName;
    std::cout << "-Enter items type-\n";
    std::cout << "1. Audio\n" <<
              "2. Visual\n" <<
              "3. AudioMobile\n" <<
              "4. VisualMobile\n";
    std::cin >> itemTypeChoice;
    switch (itemTypeChoice) {
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
    std::cout << "How many items do you want to produce: ";
    int numToProduce;
    std::cin >> numToProduce;
    int count = 1;
    while (count <= numToProduce) {
        std::ofstream productionFile("production.txt", std::ios::app);
        if (productionFile.is_open()) {
            productionFile << "|  Production Number: " << count << " Serial Number: " <<
                           manufacturer.substr(0, 3) << itemTypeCode << std::setfill('0') << std::setw(5) << count
                           << std::endl;
        } else std::cout << "Couldn't write to Production file.\n";
        productionFile.close();
        count++;
    }
    produced.push_back(numToProduce);
}

/**
 * @brief Allows user to create and add a music player product to the catalog and saving it to a text file
 * @param products takes the product vector address to be able to add items to it
 * @param manufacturers takes the manufacturers vector address to be able to add items to it
 * @bug none known
 * @return void
 */
void addMusicPlayer(std::vector<std::string> &products, std::vector<std::string> &manufacturers) {
    std::string manufacturer;
    std::string productName;
    std::string itemTypeCode;
    int itemFileFormatChoice;
    std::string itemFileFormat;
    int itemMediaTypeChoice;
    std::string itemMediaType;
    int itemTypeChoice;

    std::cout << "Add new Products\n";
    std::cout << "Enter the product manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "\n";
    std::cout << "Enter product name: \n";
    std::cin >> productName;
    std::cout << "-Enter items type-\n";
    std::cout << "1. Audio\n" <<
              "2. AudioMobile\n";
    std::cin >> itemTypeChoice;
    switch (itemTypeChoice) {
        case 1:
            itemTypeCode = "MM";
            break;
        case 2:
            itemTypeCode = "AM";
            break;
        default:
            itemTypeCode = "XX";

    }
    std::cout << "Choose devices audio File Format: \n";
    std::cout << "1. mp3 files\n" <<
              "2. .wave files\n" <<
              "3. .flac files \n";
    std::cin >> itemFileFormatChoice;
    switch (itemFileFormatChoice) {
        case 1:
            itemFileFormat = ".mp3";
            break;
        case 2:
            itemFileFormat = ".wav";
            break;
        case 3:
            itemFileFormat = ".flac";
            break;
        default:
            itemFileFormat = "Unknown";


    }
    std::cout << "" << std::endl;
    std::cout << "Input devices media type: \n";
    std::cout << "1. CD\n" <<
              "2. DVD\n" <<
              "3. Blu-Ray \n";
    std::cin >> itemMediaTypeChoice;
    switch (itemMediaTypeChoice) {
        case 1:
            itemMediaType = "CD";
            break;
        case 2:
            itemMediaType = "DVD";
            break;
        case 3:
            itemMediaType = "Blue-Ray";
            break;
        default:
            itemMediaType = "Unknown";


    }
    // sets up the write file to continue at the end of the file
    std::ofstream productCatalog("catalog.txt", std::ios::app);
    if (productCatalog.is_open()) {
        productCatalog << "|  " << manufacturer << "  |  " << productName << "  |  " << itemTypeCode <<
                       "  |  " << itemFileFormat << "  |  " << itemMediaType << std::endl;
        productCatalog.close();
    } else std::cout << "Couldn't write to catalog file.\n";
    products.push_back(productName);
    manufacturers.push_back(manufacturer);
}

/**
 * @brief Allows user to create and add a Movie player product to the catalog and saving it to a text file
 * @param products takes the memory address to allow for items to be added to the vector.
 * @param manufacturers takes the memory address to allow for items to be added to the vector.
 * @bug None known
 * @return void
 */
void addMoviePlayer(std::vector<std::string> &products, std::vector<std::string> &manufacturers) {
    std::string manufacturer;
    std::string productName;
    std::string itemTypeCode;
    int itemFileFormatChoice;
    std::string itemFileFormat;
    int itemScreenTypeChoice;
    std::string itemScreenType;
    int itemTypeChoice;

    std::cout << "Add new Products\n";
    std::cout << "Enter the product manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "" << std::endl;
    std::cout << "Enter product name: ";
    std::cin >> productName;
    std::cout << "-Enter items type-\n";
    std::cout << "1. Visual\n" <<
              "2. VisualMobile\n";
    std::cin >> itemTypeChoice;
    switch (itemTypeChoice) {
        case 1:
            itemTypeCode = "VI";
            break;
        case 2:
            itemTypeCode = "VM";
            break;
        default:
            itemTypeCode = "XX";

    }
    std::cout << "Choose devices video File Format: \n";
    std::cout << "1. .mp4 files\n" <<
              "2. .webm files\n" <<
              "3. .flv files\n";
    std::cin >> itemFileFormatChoice;
    switch (itemFileFormatChoice) {
        case 1:
            itemFileFormat = ".mp4";
            break;
        case 2:
            itemFileFormat = ".webm";
            break;
        case 3:
            itemFileFormat = ".flv";
            break;
        default:
            itemFileFormat = "Unknown";


    }
    std::cout << "\n";
    std::cout << "Input devices screen size:\n";
    std::cout << "1. 480p\n" <<
              "2. 720p\n" <<
              "3. 1080p\n" <<
              "4. 1440p\n" <<
              "5. 4K\n";
    std::cin >> itemScreenTypeChoice;
    switch (itemScreenTypeChoice) {
        case 1:
            itemScreenType = "480p";
            break;
        case 2:
            itemScreenType = "720p";
            break;
        case 3:
            itemScreenType = "1080p";
            break;
        case 4:
            itemScreenType = "1440p";
            break;
        case 5:
            itemScreenType = "4K";
            break;
        default:
            itemScreenType = "Unknown";


    }
    // sets up the write file to continue at the end of the catalog file
    std::ofstream productCatalog("catalog.txt", std::ios::app);
    if (productCatalog.is_open()) {
        productCatalog << "|  " << manufacturer << "  |  " << productName << "  |  " << itemTypeCode <<
                       "  |  " << itemFileFormat << "  |  " << itemScreenType << std::endl;
        productCatalog.close();
    } else std::cout << "Couldn't write to catalog file.\n";
    products.push_back(productName);
    manufacturers.push_back(manufacturer);
}
/**
 * @breif allows the user to see production stats printing production lists, and searching the production
 * @param products takes the vector to allow the function to print the contents
 * @param produced takes the vector to allow the function to print the contents
 * @param manufacturers takes the vector to allow the function to print the contents
 * @bug None known
 * @return void
 */
void production_Stats(std::vector<std::string> products, std::vector<std::string> manufacturers, std::vector<int> produced) {
    int menu_selection;
    std::cout << "Select a menu option\n";
    std::cout << "1. Display production information\n" <<
              "2. Search for a production Number via Serial#\n";
    std::cin >> menu_selection;
    switch (menu_selection) {
        case 1:
            for (auto i = 0; i < products.size(); i++) {
                std::cout << manufacturers[i] << ' ';
                std::cout << products[i] << ' ';
                std::cout << produced[i] << '\n';
            }
            break;
        case 2:

            break;
        default:
            std::cout << "invalid selection please choose a different option\n";
    }
}
