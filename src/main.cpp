#include <exception>
#include <pistache/endpoint.h>
#include <pistache/router.h>

import atom_core;

using namespace Pistache;
using namespace Pistache::Http;

auto get_transaction(const Rest::Request& request, Http::ResponseWriter response) -> void
{
    response.send(Code::Ok, "Get transaction request recieved.");
}

auto main() -> int
{
    Rest::Router router;

    router.get("/transaction", Rest::Routes::bind(get_transaction));

    auto opts = Http::Endpoint::options().threads(1);

    Address addr(Ipv4::any(), Port(8080));
    Http::Endpoint server{ addr };
    server.init(opts);
    server.setHandler(router.handler());
    server.serve();
}
