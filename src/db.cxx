module;

#include "pqxx/pqxx"

module db;

import atom_core;
import std;

auto db::init() -> void
{
    atom::io::println("Connecting to database...");

    pqxx::connection cx{ "" };

    atom::io::println("Connecting to database done.");
}
