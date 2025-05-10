module;

#include "pqxx/pqxx"

module db;

import atom_core;
import std;

using namespace atom;

auto db::init() -> void
{
    atom::io::println("Connecting to database...");

    const auto conn_string_c = std::getenv("DB_CONNECT_STRING");
    if (conn_string_c == nullptr)
    {
        atom::io::println("Cannot connect to database, 'DB_CONNECT_STRING' env var not defined.");
        return;
    }

    const auto conn_string = string_view{ std::getenv("DB_CONNECT_STRING") };
    if (conn_string.is_empty())
    {
        atom::io::println("Cannot connect to database, connection string is empty.");
        return;
    }

    pqxx::connection cx{ conn_string.get_data() };

    atom::io::println("Connected to database.");
}
