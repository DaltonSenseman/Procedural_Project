/**
 *  @file main.cpp
 *  COP-2001 Procedural Project
 *	@brief
 *
 *	An inventory management system for OraclProduction Ltd. That allows for users to create accounts and manage inventory.
 *
 *	@author Dalton Senseman
 *	@version 1.3 6/07/2019
 *	@bug Char inputs to menu cause loop
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

void boot_message();

void login_menu();

void main_menu(std::vector<std::string> &manufacturers, std::vector<std::string> &products,
               std::vector<std::string> &item_types);

void main_menu_print();

void add_new_item();

void add_new_user();

void add_music_player(std::string &file_format, std::string &media_type);

void add_movie_player(std::string &file_format, std::string &media_type);

void produce_item(std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &);

std::string encrypt_string(std::string str);

int main()
{
    boot_message();
    login_menu();
    std::vector<std::string> manufacturers;
    std::vector<std::string> products;
    std::vector<std::string> item_types;
    std::ifstream load_catalog("catalog.txt", std::ios::in);
    if (load_catalog.is_open())
    {
        std::string load_line;
        std::string manufac;
        std::string produc;
        std::string type;
        while (getline(load_catalog, load_line))
        {
            std::stringstream read_in(load_line);
            read_in >> manufac >> produc >> type;
            manufacturers.push_back(manufac);
            products.push_back(produc);
            item_types.push_back(type);
        }
        load_catalog.close();
    } else std::cout << "Couldn't read catalog file.\n";
    main_menu(manufacturers, products, item_types);

    return 0;
}

/**
 * @brief message printed onto the console at startup.
 * @bug none known
 * @return void
 */
void boot_message()
{
    std::cout << "\t\311";
    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\315";
    }
    std::cout << "\273\n";
    std::cout << "\t\272              -Welcome-                \272\n";
    std::cout << "\t\272   OraclProduction Ltd. Inv. Manager   \272\n";
    std::cout << "\t\307";
    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\304" << std::flush;
    }
    std::cout << "\266\n";
    std::cout << "\t\272                                       \272\n";
    std::cout << "\t\272                                       \272\n";
    std::cout << "\t\272                                       \272\n";
    std::cout << "\t\272  v0.4                   Date: 06-2019 \272\n";
    std::cout << "\t\310";
    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\315";
    }
    std::cout << "\274\n";
    system("Pause");
}

/**
 * @brief login prompt to enter the program only allowed users may enter the program and use it.
 * @bug none known
 * @todo add the ability to track / check user names.
 * @return void
 */
void login_menu()
{
    std::string user_name;
    std::string pass_word;
    std::cout << "Please login to an account to access program\n";
    std::cout << "Enter your username: ";
    std::cin >> user_name;
    std::cout << "Enter your password: ";
    std::cin >> pass_word;
}

/**
 * @brief prints the main menu of the program and prompts for a selection.
 * @bug none known bugs
 * @return void
 */
void main_menu_print()
{
    // \xxx codes are octal codes from the Axcii table
    // so cmd can display the characters for box drawing as only Axcii is supported
    std::cout << "\t\311";
    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\315";
    }
    std::cout << "\273\n";
    std::cout << "\t\272       Production Line Tracker         \272\n";
    std::cout << "\t\307";
    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\304";
    }
    std::cout << "\266\n";
    std::cout << "\t\272    1. Produce Items                   \272\n";
    std::cout << "\t\272    2. Add Employee Account            \272\n";
    std::cout << "\t\272    3. Add New Item                    \272\n";
    std::cout << "\t\272    4. Display Production Statistics   \272\n";
    std::cout << "\t\272    5. Exit                            \272\n";
    std::cout << "\t\310";
    for (int i = 0; i <= 38; i++)
    {
        std::cout << "\315";
    }
    std::cout << "\274\n";
    std::cout << "\t     Enter your selection:" << std::flush;
}

/**
 * @brief takes a user selection and allows the users to move around the program and select an option.
 * @param manufacturers
 * @param products
 * @param item_types
 * @bug none known bugs
 * @return void
 */
void main_menu(std::vector<std::string> &manufacturers, std::vector<std::string> &products,
               std::vector<std::string> &item_types)
{
    int menu_option;

    do
    {
        main_menu_print();
        std::cin >> menu_option;
        std::cout << " " << std::endl;

        //main menu switch to select one of the 6 options above.
        switch (menu_option)
        {
            case 1:
                std::cout << "\tSelection 1: Produce Items\n";
                system("pause");
                produce_item(manufacturers, products, item_types);
                break;
            case 2:
                std::cout << "\tSelection 2: Adding Employee Account stub\n";
                system("pause");
                add_new_user();
                break;
            case 3:
                std::cout << "\tSelection 3: Adding New Item\n";
                system("pause");
                add_new_item();
                break;
            case 4:
                std::cout << "\tSelection 4: Display Production Statistics\n";
                system("pause");
                break;
            case 5:
                std::cout << "\tSelection Exit\n";
                std::cout << "\tExiting . . .\n";
                break;
            default:
                std::cout << "Unexpected error has occurred in menu selection.\n";
                std::cout << "Please select a menu option #1-5 on your keyboard.\n";
                break;
        }
    } while (menu_option != 5);
}

/**
 * @brief lets asomeone that is logged in to create a new user to access the program
 * @bug none known bugs
 * @return void
 */
void add_new_user()
{
    std::cout << "Please enter the full name of the new user\n";
    std::string first_name;
    std::cin >> first_name;
    std::string last_name;
    std::cin >> last_name;
    std::string user_name = first_name[0] + last_name;
    for (int i = 0; i < user_name.length(); i++)
    {
        user_name[i] = tolower(user_name[i]);
    }

    std::cout << "Your assigned username is: " << user_name << "\n";
    bool is_user_name_good;
    std::string pass_word;
    do
    {
        is_user_name_good = false;
        std::cout << "Enter a password, password must meet the following criteria: \n"
                  << "1 or more digits\n"
                  << "1 or more upper case letters\n"
                  << "1 or more lowercase letters\n"
                  << "Contain no Spaces\n"
                  << "Be at least 10 characters long\n";
        std::cout << "Enter your password: ";
        const int SIZE = 20;
        char password[SIZE];
        std::string *prt_pass_word = &pass_word;
        std::cin.ignore();
        std::cin.getline(password, SIZE);

        int upper = 0;
        int lower = 0;
        int number = 0;
        bool special = false;

        for (int i = 0; i < strlen(password); i++)
        {

            if (isdigit(password[i]))
            {
                number++;
            } else if (isupper(password[i]))
            {
                upper++;
            } else if (islower(password[i]))
            {
                lower++;
            }

            if (ispunct(password[i]) || isspace(password[i]))
            {
                special = true;
            }

            if (lower > 0 && upper > 0 && number > 0 && (strlen(password) >= 10) && !special)
            {
                is_user_name_good = true;
                *prt_pass_word = password;
            } else
            {
                is_user_name_good = false;
            }
        }
    } while (!is_user_name_good);

    std::string pass_word_encrypt = encrypt_string(pass_word);

    std::ofstream user_info("user_info.txt", std::ios::app);
    if (user_info.is_open())
    {
        user_info << user_name << ", " << pass_word_encrypt << std::endl;
        user_info.close();
    } else std::cout << "Couldn't write to catalog file.\n";
}

/**
 * @brief lets the user create a new item to add to the catalog moving from the general info to more detailed ones depending on their selection
 * @bug none known bugs
 * @return void
 */
void add_new_item()
{
    std::string manufacturer;
    std::string product_name;
    std::string item_type;
    std::string media_type;
    std::string file_format;
    int item_type_choice;
    int product_type_choice;

    std::cout << "Add new Products\n";
    std::cout << "Enter the product manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "\n";
    std::cout << "Enter product name: \n";
    std::cin >> product_name;
    std::cout << "-Enter items type-\n";
    std::cout << "1. Audio\n" <<
              "2. AudioMobile\n" <<
              "3. Visual\n" <<
              "4. VisualMobile\n";
    std::cin >> item_type_choice;
    switch (item_type_choice)
    {
        case 1:
            item_type = "MM";
            break;
        case 2:
            item_type = "AM";
            break;
        case 3:
            item_type = "VI";
            break;
        case 4:
            item_type = "VM";
            break;
        default:
            item_type = "XX";
    }
    do
    {
        std::cout << "What type of product is this?\n";
        std::cout << "-Enter product type-\n";
        std::cout << "1. Music Player\n"
                  << "2. Video Player\n"
                  << "3. Skip Product Information\n";
        std::cin >> product_type_choice;
        switch (product_type_choice)
        {
            case 1:
                add_music_player(file_format, media_type);
                break;
            case 2:
                add_movie_player(file_format, media_type);
                break;
            case 3:
                file_format = "Unknown";
                media_type = "Unknown";
                break;
            default:
                std::cout << "Product type choice invalid please select and option 1-3.\n";
                break;
        }
    } while (product_type_choice < 1 || product_type_choice > 3);

    std::ofstream product_catalog("catalog.txt", std::ios::app);
    if (product_catalog.is_open())
    {
        product_catalog << manufacturer << ", " << product_name << ", " << item_type <<
                        ", " << file_format << ", " << media_type << std::endl;
        product_catalog.close();
    } else std::cout << "Couldn't write to catalog file.\n";
}

/**
 * @brief after the user selected music player they can add more information on what music player it is; file type etc...
 * @param file_format
 * @param media_type
 * @bug none known bugs
 * @return void
 */
void add_music_player(std::string &file_format, std::string &media_type)
{
    int file_format_choice;
    std::string *ptr_file_format = &file_format;
    int media_type_choice;
    std::string *ptr_media_type = &media_type;

    std::cout << "Adding a music player\n";
    std::cout << "Choose products supported file format\n";
    std::cout << "1. MP3 files\n"
              << "2. WAV files\n"
              << "3. FLAC files\n"
              << "4. AAC files\n"
              << "5. WMA files\n";
    std::cin >> file_format_choice;
    switch (file_format_choice)
    {
        case 1:
            *ptr_file_format = ".mp3";
            break;
        case 2:
            *ptr_file_format = ".wav";
            break;
        case 3:
            *ptr_file_format = ".flac";
            break;
        case 4:
            *ptr_file_format = ".aac";
            break;
        case 5:
            *ptr_file_format = ".wma";
            break;
        default:
            *ptr_file_format = "Unknown";
            break;
    }
    std::cout << "\n";
    std::cout << "Input devices media type: \n";
    std::cout << "1. CD\n"
              << "2. DVD\n"
              << "3. Blu-Ray\n"
              << "4. Blu-Ray\n";
    std::cin >> media_type_choice;
    switch (media_type_choice)
    {
        case 1:
            *ptr_media_type = "CD";
            break;
        case 2:
            *ptr_media_type = "DVD";
            break;
        case 3:
            *ptr_media_type = "Blue-Ray";
            break;
        case 4:
            *ptr_media_type = "Digital Only";
            break;
        default:
            *ptr_media_type = "Unknown";
    }
}

/**
 * @brief after the user selected movie player they can add more information on what movie player it is; file type etc...
 * @param file_format
 * @param media_type
 * @bug none known bugs
 * @return void
 */
void add_movie_player(std::string &file_format, std::string &media_type)
{
    int file_format_choice;
    std::string *ptr_file_format = &file_format;
    int resolution_type_choice;
    std::string *ptr_resolution_type = &media_type;

    std::cout << "Adding a video player\n";
    std::cout << "Choose products supported file format\n";
    std::cout << "1. MP4 files\n"
              << "2. AVI files\n"
              << "3. FLV files\n"
              << "4. WMV files\n"
              << "5. MOV files\n";
    std::cin >> file_format_choice;
    switch (file_format_choice)
    {
        case 1:
            *ptr_file_format = ".mp4";
            break;
        case 2:
            *ptr_file_format = ".avi";
            break;
        case 3:
            *ptr_file_format = ".flv";
            break;
        case 4:
            *ptr_file_format = ".wmv";
            break;
        case 5:
            *ptr_file_format = ".mov";
            break;
        default:
            *ptr_file_format = "Unknown";
            break;
    }
    std::cout << "\n";
    std::cout << "Input devices screen resolution: \n";
    std::cout << "1. 480p\n"
              << "2. 720p\n"
              << "3. 1080p\n"
              << "4. 1440p\n";
    std::cin >> resolution_type_choice;
    switch (resolution_type_choice)
    {
        case 1:
            *ptr_resolution_type = "480p";
            break;
        case 2:
            *ptr_resolution_type = "720p";
            break;
        case 3:
            *ptr_resolution_type = "1080p";
            break;
        case 4:
            *ptr_resolution_type = "1440p";
            break;
        default:
            *ptr_resolution_type = "Unknown";
    }

}

/**
 * @brief lets the user create a item and produce it recording it on the production.txt
 * @param manufacturers the manufactoreres name
 * @param products the products name
 * @param item_types the item type code VI MM etc..
 * @bug none known bugs
 * @todo add the genuine serial code maker to the code adding date and check digit functionality.
 * @return void
 */
void produce_item(std::vector<std::string> &manufacturers, std::vector<std::string> &products,
                  std::vector<std::string> &item_types)
{
    int selection_choice = 0;
    int amount_to_make;
    do
    {
        std::cout << "What Items would you like to produce?\n";
        for (int i = 0; i < manufacturers.size(); i++)
        {
            std::cout << (i + 1) << ". " << manufacturers[i];
            std::cout << products[i];
            std::cout << item_types[i] << '\n';
        }
        std::cin >> selection_choice;
    } while (selection_choice > manufacturers.size() || selection_choice < 1);
    std::cout << "How many would you like to create?";
    std::cin >> amount_to_make;

    int count = 1;
    while (count <= amount_to_make)
    {
        std::ofstream productionFile("production.txt", std::ios::app);
        if (productionFile.is_open())
        {
            productionFile << "Production Number:, " << count << " Serial Number:, " <<
                           manufacturers[selection_choice].substr(0, 3) << item_types[selection_choice]
                           << std::setfill('0') << std::setw(5) << count
                           << std::endl;
        } else std::cout << "Couldn't write to Production file.\n";
        productionFile.close();
        count++;
    }
}

/**
 * @brief takes the password and sifts it 5 and divides by 10 to have a different password saved in the files for security
 * @param str string of password that the user entered
 * @bug none known bugs
 * @return string that has been encrypted
 * @todo change the simple axcii shift to a salt and hash system once the demo program of the system has been fixed.
 *
 * just a use of the repl.it solved example until I have the full hash system up and running from my sandbox program.
 */
std::string encrypt_string(std::string old_pass)
{
    if (old_pass.length() == 1)
    {
        return old_pass;
    } else
    {
        return char(((int) old_pass[0] + 5) / 10) + encrypt_string(old_pass.substr(1, old_pass.length() - 1));
    }
}