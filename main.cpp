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
#include <cstring>
#include <ctime>

struct Products
{
    std::string manufacturer;
    std::string product_name;
    std::string product_type;
};

struct Production
{
    std::string manufacturer;
    std::string product_name;
    std::string product_type;
    std::string serial_number;
};

struct Record
{
    int MM = 0;
    int AM = 0;
    int VM = 0;
    int VI = 0;
    int Total = 0;
} record;

void boot_message();

void login_menu();

void main_menu(std::vector<Products> &, std::vector<Production> &);

void main_menu_print();

void add_new_item(std::vector<Products> &);

void add_new_user();

void add_music_player(std::string &file_format, std::string &media_type);

void add_movie_player(std::string &file_format, std::string &media_type);

void produce_item(const std::vector<Products> &, std::vector<Production> &);

std::string encrypt_string(std::string);

int check_digit_maker(std::string &, std::string &, int &, int &,
                      int &);

std::string make_serial_num(std::string, std::string, int);

void production_stats(const std::vector<Products> &);

void show_catalog(const std::vector<Products> &);

void print_production_stats();


int main()
{
    boot_message();
    login_menu();
    std::vector<Products> product_line;
    std::vector<Production> production_line;
    std::vector<Record> records;
    std::ifstream load_catalog("catalog.csv", std::ios::in);
    if (load_catalog.is_open())
    {
        std::string load_line;
        std::string manufac;
        std::string produc;
        std::string type;
        while (getline(load_catalog, load_line))
        {
            std::stringstream read_in(load_line);
            std::getline(read_in, manufac, ',');
            std::getline(read_in, produc, ',');
            std::getline(read_in, type, ',');
            Products load_in;
            load_in.manufacturer = manufac;
            load_in.product_name = produc;
            load_in.product_type = type;
            product_line.emplace_back(load_in);
        }
        load_catalog.close();
    }
    else std::cout << "Couldn't read catalog file.\n";

    std::ifstream load_record("record.csv", std::ios::in);
    if (load_record.is_open())
    {
        load_record >> record.MM >> record.AM >> record.VI >> record.VM >> record.Total;
        load_record.close();
    }
    else std::cout << "Couldn't read record file.\n";


    main_menu(product_line, production_line);

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
 * @bug unknown bug that prints the numerical serial number of the last products created in the product line
 * @return void
 */
void
main_menu(std::vector<Products> &product_line, std::vector<Production> &production_line)
{
    int menu_option;
    do
    {
        main_menu_print();
        std::cin >> menu_option;
        //main menu switch to select one of the 6 options above.
        switch (menu_option)
        {
            case 1:
                std::cout << "\tSelection 1: Produce Items\n";
                system("pause");
                produce_item(product_line, production_line);
                break;
            case 2:
                std::cout << "\tSelection 2: Adding Employee Account stub\n";
                system("pause");
                add_new_user();
                break;
            case 3:
                std::cout << "\tSelection 3: Adding New Item\n";
                system("pause");
                add_new_item(product_line);
                break;
            case 4:
                std::cout << "\tSelection 4: Display Production Statistics\n";
                system("pause");
                production_stats(product_line);
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
    }
    while (menu_option != 5);
}

/**
 * @brief lets someone that is logged in to create a new user to access the program
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
        i = tolower(user_name[i]);
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
            }
            else if (isupper(password[i]))
            {
                upper++;
            }
            else if (islower(password[i]))
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
            }
            else
            {
                is_user_name_good = false;
            }
        }
    }
    while (!is_user_name_good);

    std::string pass_word_encrypt = encrypt_string(pass_word);

    std::ofstream user_info("user_info.txt", std::ios::app);
    if (user_info.is_open())
    {
        user_info << user_name << ", " << pass_word_encrypt << std::endl;
        user_info.close();
    }
    else std::cout << "Couldn't write to catalog file.\n";
}

/**
 * @brief lets the user create a new item to add to the catalog moving from the general info to more detailed ones depending on their selection
 * @bug none known bugs
 * @return void
 */
void add_new_item(std::vector<Products> &product_line)
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
    }
    while (product_type_choice < 1 || product_type_choice > 3);

    Products new_product;
    new_product.manufacturer = manufacturer;
    new_product.product_name = product_name;
    new_product.product_type = item_type;
    product_line.push_back(new_product);

    std::ofstream product_catalog("catalog.csv", std::ios::app);
    if (product_catalog.is_open())
    {
        product_catalog << manufacturer << "," << product_name << "," << item_type <<
                        "," << file_format << "," << media_type << std::endl;
        product_catalog.close();
    }
    else std::cout << "Couldn't write to catalog file.\n";
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
 * @param manufacturers the manufacturers name
 * @param products the products name
 * @param item_types the item type code VI MM etc..
 * @bug none known bugs
 * @todo add the genuine serial code maker to the code adding date and check digit functionality.
 * @return void
 */
void produce_item(const std::vector<Products> &product_line, std::vector<Production> &production_line)
{
    int selection_choice = 0;
    int amount_to_make;
    std::cout << "What Items would you like to produce?\n";
    int counter = 1;
    for (const auto &i : product_line)
    {
        std::cout << counter << " -- " << i.manufacturer << " " << i.product_name << " " << i.product_type << "\n";
        counter++;
    }

    std::cin >> selection_choice;
    std::cout << "How many would you like to create?";
    std::cin >> amount_to_make;

    std::string manufacturer = product_line[selection_choice - 1].manufacturer;
    std::string product_name = product_line[selection_choice - 1].product_name;
    std::string item_type = product_line[selection_choice - 1].product_type;

    int product_number = 1;
    int count = 1;
    int value = 0;
    int AM_num = record.AM;
    int MM_num = record.MM;
    int VM_num = record.VM;
    int VI_num = record.VI;
    int Total_num = record.Total;
    while (count <= amount_to_make)
    {
        Production add_production;
        add_production.manufacturer = manufacturer;
        add_production.product_name = product_name;
        add_production.product_type = item_type;
        production_line.push_back(add_production);

        if (item_type == "AM")
        {
            value = AM_num;
            AM_num++;
            record.AM = AM_num;
        }
        else if (item_type == "MM")
        {
            value = MM_num;
            MM_num++;
            record.MM = MM_num;
        }
        else if (item_type == "VM")
        {
            value = VM_num;
            VM_num++;
            record.VM = VM_num;
        }
        else if (item_type == "VI")
        {
            value = VI_num;
            VI_num++;
            record.VI = VI_num;
        }
        else
        {
            std::cout << "Error reading item_type for incrementation.\n";
        }

        Total_num++;
        record.Total = Total_num;

        std::string serial_num_final = make_serial_num(manufacturer, item_type, value);

        std::ofstream product_catalog("ProductionLog.csv", std::ios::app);
        if (product_catalog.is_open())
        {
            product_catalog << Total_num << " " << manufacturer << "," << product_name << "," << item_type <<
                            "," << serial_num_final << std::endl;
            product_catalog.close();
            product_number++;
        }
        else std::cout << "Couldn't write to catalog file.\n";
        count++;
    }
    std::ofstream record_add("record.csv");
    if (record_add.is_open())
    {
        record_add << MM_num << "\n" << AM_num << "\n" << VM_num << "\n" << VI_num << "\n" << Total_num;
        record_add.close();
    }
    else std::cout << "Couldn't write to catalog file.\n";
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
    }
    else
    {
        return char(((int) old_pass[0] + 5) / 10) + encrypt_string(old_pass.substr(1, old_pass.length() - 1));
    }
}

/**
 * @brief generates the serial number with current data and a check digit.
 * @param manufacturer
 * @param itemTypeCode
 * @param product_number
 * @return a string that is to be the items serial code.
 */
std::string make_serial_num(std::string manufacturer, std::string itemTypeCode, int product_number)
{
    time_t sec = time(nullptr);
    tm *curTime = localtime(&sec);

    int current_year = 1900 + (curTime->tm_year);
    int current_year_last_two = current_year % 100;
    int current_month = 01 + (curTime->tm_mon);
    std::string manufacturer_serial_version = manufacturer.substr(0, 3);

    int check_digit = check_digit_maker(manufacturer, itemTypeCode, current_year_last_two, current_month,
                                        product_number);
    std::ostringstream serial_number_ss;
    serial_number_ss << manufacturer.substr(0, 3) << itemTypeCode << current_year_last_two << std::setw(2)
                     << std::setfill('0') << current_month << check_digit << std::setw(5) << std::setfill('0')
                     << product_number;
    std::string serial_number = serial_number_ss.str();
    return serial_number;
}

/**
 * @brief Creates a unique check digit for the serial number which is added for security and protection of data.
 * @param manufacturer product manufacturer
 * @param itemTypeCode  the code of the item
 * @param current_year_last_two last digits of the current year with ctime
 * @param current_month two digit number representing the current month via ctime
 * @param product_number the current products number.
 * @return a single digits 0-9 that becoems the check digit
 */
int
check_digit_maker(std::string &manufacturer, std::string &itemTypeCode, int &current_year_last_two, int &current_month,
                  int &product_number)
{
    std::vector<int> serial_num_to_digit_array;
    int check_digit = 0;
    char manufacturer_char_before[manufacturer.length()];
    strcpy(manufacturer_char_before, manufacturer.c_str());
    char manufacturer_char[3];
    for (int i = 0; i < 3; i++)
    {
        manufacturer_char[i] = manufacturer_char_before[i];
    }

    for (auto i : manufacturer_char)
    {
        i = toupper(i);
        // for (int i = 0; i < 3; i++)
        if (i == 'A' || i == 'J' || i == 'S')
        {
            serial_num_to_digit_array.push_back(1);
        }
        else if (i == 'B' || i == 'K' || i == 'T')
        {
            serial_num_to_digit_array.push_back(2);
        }
        else if (i == 'C' || i == 'L' || i == 'U')
        {
            serial_num_to_digit_array.push_back(3);
        }
        else if (i == 'D' || i == 'M' || i == 'V')
        {
            serial_num_to_digit_array.push_back(4);
        }
        else if (i == 'E' || i == 'N' || i == 'W')
        {
            serial_num_to_digit_array.push_back(5);
        }
        else if (i == 'F' || i == 'O' || i == 'X')
        {
            serial_num_to_digit_array.push_back(6);
        }
        else if (i == 'G' || i == 'P' || i == 'Y')
        {
            serial_num_to_digit_array.push_back(7);
        }
        else if (i == 'H' || i == 'Q' || i == 'Z')
        {
            serial_num_to_digit_array.push_back(8);
        }
        else if (i == 'I' || i == 'R')
        {
            serial_num_to_digit_array.push_back(9);
        }
    }

    if (itemTypeCode == "MM")
    {
        serial_num_to_digit_array.push_back(4);
        serial_num_to_digit_array.push_back(4);

    }
    else if (itemTypeCode == "VI")
    {
        serial_num_to_digit_array.push_back(4);
        serial_num_to_digit_array.push_back(3);
    }
    else if (itemTypeCode == "AM")
    {
        serial_num_to_digit_array.push_back(1);
        serial_num_to_digit_array.push_back(4);
    }
    else if (itemTypeCode == "VM")
    {
        serial_num_to_digit_array.push_back(4);
        serial_num_to_digit_array.push_back(4);
    }
    else
    {
        serial_num_to_digit_array.push_back(6);
        serial_num_to_digit_array.push_back(6);
    }

    int year_tens = current_year_last_two / 10;
    serial_num_to_digit_array.push_back(year_tens);
    int year_singles = current_year_last_two % 10;
    serial_num_to_digit_array.push_back(year_singles);

    int month_tens = current_month / 10;
    serial_num_to_digit_array.push_back(month_tens);
    int month_singles = current_month % 10;
    serial_num_to_digit_array.push_back(month_singles);

    //initial check digit of 0
    serial_num_to_digit_array.push_back(0);

    int product_10000_place = product_number / 10000 % 10;
    serial_num_to_digit_array.push_back(product_10000_place);
    int product_1000_place = product_number / 1000 % 10;
    serial_num_to_digit_array.push_back(product_1000_place);
    int product_100_place = product_number / 100 % 10;
    serial_num_to_digit_array.push_back(product_100_place);
    int product_10_place = product_number / 10 % 10;
    serial_num_to_digit_array.push_back(product_10_place);
    int product_1_place = product_number % 10;
    serial_num_to_digit_array.push_back(product_1_place);

    //Algorithm to create the check digit.
    for (auto i  : serial_num_to_digit_array)
    {
        std::cout << i;
    }

    int evens = 0;
    int odds = 0;

    for (auto i : serial_num_to_digit_array)
    {
        if (i % 2 == 0)
        {
            evens += (i * 3);
        }
        else
        {
            odds += (i * 3);
        }
    }

    int sum = (evens + odds) % 10;
    if (sum != 0)
    {
        check_digit = (10 - sum);
    }
    else
        check_digit = 0;

    return check_digit;
}

/**
 * @brief Allows the user to display the production stats on current products
 * @param product_line
 * @bug No known bugs
 * @return void
 */
void production_stats(const std::vector<Products> &product_line)
{
    int option_choice;
    do
    {
        std::cout << "Production Stats\n";
        std::cout << "Choose which option you would like to view.\n";
        std::cout << "1. Product catalog\n";
        std::cout << "2. Production statistics\n";
        std::cout << "3. Return to menu\n";
        std::cin >> option_choice;
        switch (option_choice)
        {
            case 1:
                std::cout << "Product catalog\n";
                show_catalog(product_line);
                break;
            case 2:
                std::cout << "Production Statistics\n";
                print_production_stats();
                break;
            case 3:
                std::cout << "Returning to main Menu\n";
                break;
            default:
                std::cout << "Invalid option, please choose a number 1-3 on your keyboard\n";
        }
    }
    while (option_choice != 3);

}

/**
 * @brief Prints the current catalog loaded into the program
 * @param product_line pulls in the product line to print its contents
 * @bug No known bugs
 * @return void
 */
void show_catalog(const std::vector<Products> &product_line)
{

    int count = 1;
    for (const auto &i : product_line)
    {
        std::cout << count << " -- " << i.manufacturer << " " << i.product_name << " " << i.product_type << "\n";
        count++;
    }
}

/**
 * @brief Prints the stats of current number of produced items
 * @bug No known bugs.
 * @return Void
 */
void print_production_stats()
{
    std::cout << "Produced number of Audio devices: " << record.AM << "\n";
    std::cout << "Produced number of Audio Mobile devices: " << record.MM << "\n";
    std::cout << "Produced number of Visual devices: " << record.VI << "\n";
    std::cout << "Produced number of Visual Mobile devices: " << record.VM << "\n";
    std::cout << "Total produced number of devices: " << record.Total << "\n";
    std::cout << "\n";
}