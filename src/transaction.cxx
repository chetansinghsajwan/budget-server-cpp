module transaction;

import pistache;
import atom_core;
import db;

using namespace atom;
using Pistache::Http::Code;
using Pistache::Http::ResponseWriter;
using Pistache::Rest::Request;

auto HandlePostTransaction(const Request& request, ResponseWriter response) -> void
{
    response.send(Code::Ok, "Post transaction request recieved.");
}

auto HandlePutTransaction(const Request& request, ResponseWriter response) -> void
{
    response.send(Code::Ok, "Put transaction request recieved.");
}

auto HandleGetTransaction(const Request& request, ResponseWriter response) -> void
{
    const int id = request.param(":id").as<int>();
    const string msg = string::format("Get transaction request recieved for id '{}'.", id);

    const auto result = db::get_transaction(id);
    if (result.is_error<db::NotFoundError>())
    {
        response.send(Code::Not_Found);
        return;
    }

    const db::Transaction transaction = result.get_value();
    response.send(Code::Ok, msg.get_data());

    Json json = Json::Object{};
    json["result"] = transaction;

    reponse.send(Code::Ok, json)
    // json::format(
    //     R"({
    //         "transaction": {0}
    //     })",
    //     transaction);
}

auto HandleDeleteTransaction(const Request& request, ResponseWriter response) -> void
{
    response.send(Code::Ok, "Delete transaction request recieved.");
}
