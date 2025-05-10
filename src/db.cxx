module;

#include "pqxx/pqxx"

module db;

import atom_core;
import std;

using namespace atom;

pqxx::connection* db::_conn = nullptr;

auto db::init() -> result<void, runtime_error>
{
    contract_debug_expects(not is_init(), "db is already initialized.");

    const auto conn_string_c = std::getenv("DB_CONNECT_STRING");
    if (conn_string_c == nullptr)
    {
        return runtime_error{ "'DB_CONNECT_STRING' env var not defined." };
    }

    const auto conn_string = string_view{ std::getenv("DB_CONNECT_STRING") };
    if (conn_string.is_empty())
    {
        return runtime_error{ "Connection string is empty." };
    }

    _conn = new pqxx::connection{ conn_string.get_data() };

    return create_from_void_tag{};
}

auto db::is_init() -> bool
{
    return _conn != nullptr;
}

auto db::get_transaction(u64 id) -> result<Transaction, NotFoundError>
{
    contract_debug_expects(is_init(), "db is not initialized.");

    const string query = string::format(
        R"(
        select
            id,
            title,
            owner_id
        from transactions
        where id = {}
        )",
        id);

    auto tx = pqxx::work{ *_conn };
    const auto result = tx.query01<u64, std::string, u64>(query.get_data());
    tx.commit();

    if (not result.has_value())
    {
        return NotFoundError{};
    }

    const auto result_value = result.value();
    auto transaction = Transaction{};
    transaction.id = id;
    transaction.title = std::get<1>(result_value);
    transaction.owner_id = std::get<2>(result_value);

    return transaction;
}
