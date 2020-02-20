#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "String.h"

namespace program {
	class TestingString
	{
	public:
		void testing();

	private:
		void show_menu();

		void read_from_file();

		void write_to_file();

		void read_from_console();

		void show_text();

		void show_element();

		void delete_element();

		void add_element();

		void change_element();

		std::pair<size_t, size_t> get_id_element() const;

		std::vector<program::String> _text;
	};
}