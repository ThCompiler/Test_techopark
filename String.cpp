#include "String.h"

namespace program {
    explicit String::String(std::string s) {
        size_t i  = 0;
        size_t id = 0;

        std::string buffer(256, '\0');

        while (s[i]!='\0') {
            if (s[i] == '\t' && id) {
                _string.push_back(buffer.substr(0, id));

                if (id > 256) {
                    buffer.resize(256);
                }

                i++;
                id = 0;
            }
            else {
                if (id >= 256) {
                    buffer.push_back(s[i++]);
                }
                else {
                    buffer[id++] = s[i++];
                }
            }
        }
    }

    std::string& String::operator[](size_t id) {
        return _string[id];
    }

    void String::pop() {
        return _string.pop_back();
    }

    void String::delete_pole(size_t id) {
        if (id >= _string.size()) {
            throw std::out_of_range("Can't delete element in this id");
        }
        _string.erase(_string.begin() + id);
    }

    void String::add_pole(size_t id, std::string new_str) {
        if (id >= _string.size()) {
            throw std::out_of_range("Can't add new element");
        }

        _string.emplace(_string.begin() + id, new_str);
    }

    size_t String::size() const
    {
        return _string.size();
    }

    std::istream& operator>>(std::istream& in, String& s) {
        char c = '\0';
        size_t id = 0;

        std::string buffer(256, '\0');

        s._string.clear();

        while (in.get(c)) {
            if (c == '\n') {
                break;
            }

            if (c == '\t' && id) {
                s._string.push_back(buffer.substr(0, id));

                if (id > 256) {
                    buffer.resize(256);
                }

                id = 0;
            }
            else {
                if (id >= 256) {
                    buffer.push_back(c);
                }
                else {
                    buffer[id++] = c;
                }
            }
        }

        if (id) {
            s._string.push_back(buffer.substr(0, id));
        }
        return in;
    }

    std::ostream& operator<<(std::ostream& out, String& s) {
        for (size_t i = 0; i < s._string.size(); ++i) {
            out << s._string[i] << "\t";
        }
        return out;
    }
}