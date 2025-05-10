import pistache;
import atom_core;
import atom_logging;
import transaction;
import db;
import std;

using Pistache::Address;
using Pistache::Ipv4;
using Pistache::Port;
using Pistache::Http::Endpoint;
using Pistache::Rest::Router;
using Pistache::Rest::Routes::bind;

using namespace atom;
using namespace atom::logging;

auto main() -> int
{
    logger_manager::initialize();
    logger* logger = logger_manager::get_or_create_logger({ .name = "main" });

    // logger->log_info("Connecting to database...");

    const result<void, runtime_error> result = db::init();
    if (result.is_error<runtime_error>())
    {
        const runtime_error error = result.get_error<runtime_error>();
        std::cout << "Failed to connect to database" << std::endl;
        return 1;
        // logger->log_error("Failed to connect to database, error: {}", error.msg);
    }

    // logger->log_info("Connected to database.");

    Router router;

    router.post("/transaction", bind(HandlePostTransaction));
    router.put("/transaction", bind(HandlePutTransaction));
    router.get("/transaction/:id", bind(HandleGetTransaction));
    router.del("/transaction/:id", bind(HandleDeleteTransaction));

    auto opts = Endpoint::options().threads(1);

    Address addr(Ipv4::any(), Port(8080));
    Endpoint server{ addr };
    server.init(opts);
    server.setHandler(router.handler());

    // logger->log_info("Server listening on port 8080...");
    server.serve();
}
