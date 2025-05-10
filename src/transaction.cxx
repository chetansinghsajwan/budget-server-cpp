module transaction;

import pistache;
import atom_core;

using namespace atom;
using Pistache::Rest::Request;
using Pistache::Http::ResponseWriter;
using Pistache::Http::Code;

auto handle_post_transaction(const Request& request, ResponseWriter response) -> void
{
    response.send(Code::Ok, "Post transaction request recieved.");
}

auto handle_put_transaction(const Request& request, ResponseWriter response) -> void
{
    response.send(Code::Ok, "Put transaction request recieved.");
}

auto handle_get_transaction(const Request& request, ResponseWriter response) -> void
{
    const int id = request.param(":id").as<int>();
    const string msg = string::format("Get transaction request recieved for id '{}'.", id);

    response.send(Code::Ok, msg.get_data());
}

auto handle_del_transaction(const Request& request, ResponseWriter response) -> void
{
    response.send(Code::Ok, "Del transaction request recieved.");
}
