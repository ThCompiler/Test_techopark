#include "../include/Test.h"

namespace program {
    void TestingString::testing() {
        std::cout << "Hello, It's test of class String, which have own features\n";
        
        char ans = '\0';

        show_menu();

        while (std::cin >> ans && ans != 'e') {
            switch (ans - '0')
            {
            case 1:
                read_from_console();
                break;
            case 2:
                show_text();
                break;
            case 3:
                read_from_file();
                break;
            case 4:
                write_to_file();
                break;
            case 5:
                show_element();
                break;
            case 6:
                change_element();
                break;
            case 7:
                delete_element();
                break;
            case 8:
                add_element();
                break;
            case 9:
                system("cls");
                break;
            default:
                std::cout << "Unknow answer\n";
                break;
            }
            show_menu();
        }
        std::cout << "Bye)\n";
    }

    void TestingString::show_menu() {
        std::cout << "You can do this things:\n";
        std::cout << "1 - Enter text from keydoard\n";
        std::cout << "2 - Show text on screan\n";
        std::cout << "3 - Read text from file\n";
        std::cout << "4 - Write text ro file\n";
        std::cout << "5 - Show the n element of the i string\n";
        std::cout << "6 - Change the n element of the i string\n";
        std::cout << "7 - Delete the n element of the i string\n";
        std::cout << "8 - Add in the n element of the i string\n";
        std::cout << "9 - Clear console\n";
        std::cout << "e - Exit\n";
    }

    void TestingString::read_from_file() {
        std::cout << "Enter name of file\n";

        std::string file_name;

        std::cin >> file_name;

        std::ifstream in(file_name);

        if (!in.is_open()) {
            throw std::runtime_error("Can't open file");
        }

        program::String tmp;

        while (in >> tmp) {
            _text.push_back(tmp);
        }
    }

    void TestingString::write_to_file() {
        std::cout << "Enter name of file\n";

        std::string file_name;

        std::cin >> file_name;

        std::ofstream out(file_name);

        if (!out.is_open()) {
            throw std::runtime_error("Can't open file");
        }

        for (size_t i = 0; i < _text.size(); ++i) {
            out << _text[i] << "\n";
        }
    }

    void TestingString::read_from_console() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Last string of input must be a string starting with a tab character\n";

        char check = '\0';

        program::String tmp;

        while (std::cin.get(check)) {
            if (check == '\t') {
                break;
            }
            else {
                std::cin.putback(check);
            }

            std::cin >> tmp;

            _text.push_back(tmp);
        }
    }

    void TestingString::show_text() {
        for (size_t i = 0; i < _text.size(); ++i) {
            std::cout << _text[i] << "\n";
        }
    }

    void TestingString::show_element() {
        std::pair<size_t, size_t> id = get_id_element();

        std::cout << _text[id.first][id.second] << "\n";
    }

    void TestingString::delete_element()
    {
        std::pair<size_t, size_t> id = get_id_element();

        _text[id.first].delete_pole(id.second);
    }

    void TestingString::add_element() {
        std::pair<size_t, size_t> id = get_id_element();

        std::cout << "Enter value for this element\n";

        std::string new_val;

        std::cin >> new_val;

        _text[id.first].add_pole(id.second, new_val);
    }

    void TestingString::change_element() {
        std::pair<size_t, size_t> id = get_id_element();

        std::cout << "Enter new value for this element\n";

        std::string new_val;

        std::cin >> new_val;

        _text[id.first][id.second] = new_val;
    }

    std::pair<size_t, size_t> TestingString::get_id_element() const
    {
        size_t i = 0;
        size_t j = 0;

        std::cout << "Enter number of line, where this element is(start with 0)\n";
        std::cin >> i;

        std::cout << "Enter number of element in this line(start with 0)\n";
        std::cin >> j;

        return { i, j };
    }
}