module;
#include <exception>
#include "pistache/http.h"
#include "pistache/endpoint.h"
#include "pistache/http_defs.h"
#include "pistache/net.h"
#include "pistache/router.h"

export module pistache;

export namespace Pistache
{
    using ::Pistache::Address;
    using ::Pistache::Ipv4;
    using ::Pistache::Port;

    namespace Http
    {
        using ::Pistache::Http::Code;
        using ::Pistache::Http::Endpoint;
        using ::Pistache::Http::FullDate;
        using ::Pistache::Http::Method;
        using ::Pistache::Http::RequestParser;
        using ::Pistache::Http::ResponseParser;
        using ::Pistache::Http::ResponseStream;
        using ::Pistache::Http::ResponseWriter;
        using ::Pistache::Http::Version;
    }

    namespace Rest
    {
        using ::Pistache::Rest::Request;
        using ::Pistache::Rest::Router;

        namespace Routes
        {
            using ::Pistache::Rest::Routes::bind;
        }
    }
}
