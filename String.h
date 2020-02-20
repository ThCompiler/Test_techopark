#pragma once
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <iterator>

namespace program {
    class String {
    public:
        String() = default;

        explicit String(std::string s);

        ~String() = default;

        std::string& operator[](size_t id);

        void pop();

        void delete_pole(size_t id);

        void add_pole(size_t id, std::string new_str);

        size_t size() const;

        friend
            std::istream& operator>>(std::istream& in, String& s);

        friend
            std::ostream& operator<<(std::ostream& out, String& s);

    private:
        std::vector<std::string> _string;
    };

    std::istream& operator>>(std::istream& in, String& s);

    std::ostream& operator<<(std::ostream& out, String& s);
}
