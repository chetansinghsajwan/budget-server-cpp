module;

#include "pqxx/pqxx"

export module db;

import atom_core;

using namespace atom;

export struct db
{
    struct NotFoundError: public error
    {};

    struct Datetime
    {};

    struct Transaction
    {
        u64 id;
        string title;
        u64 owner_id;
        Datetime created_at;
        Datetime updated_at;
        option<Datetime> deleted_at;
    };

    static auto init() -> Result<void, RuntimeError>;
    static auto is_init() -> bool;

    static auto get_transaction(u64 id) -> Result<Transaction, NotFoundError>;

private:
    static pqxx::connection* _conn;
};
