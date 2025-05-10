import pistache;
import transaction;

using Pistache::Port;
using Pistache::Ipv4;
using Pistache::Address;
using Pistache::Http::Endpoint;
using Pistache::Rest::Router;
using Pistache::Rest::Routes::bind;

auto main() -> int
{
    Router router;

    router.post("/transaction", bind(handle_post_transaction));
    router.put("/transaction", bind(handle_put_transaction));
    router.get("/transaction", bind(handle_get_transaction));
    router.del("/transaction", bind(handle_del_transaction));

    auto opts = Endpoint::options().threads(1);

    Address addr(Ipv4::any(), Port(8080));
    Endpoint server{ addr };
    server.init(opts);
    server.setHandler(router.handler());
    server.serve();
}
