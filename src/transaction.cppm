export module transaction;

import pistache;

using Pistache::Rest::Request;
using Pistache::Http::ResponseWriter;

export auto handle_post_transaction(const Request& request, ResponseWriter response) -> void;
export auto handle_get_transaction(const Request& request, ResponseWriter response) -> void;
export auto handle_put_transaction(const Request& request, ResponseWriter response) -> void;
export auto handle_del_transaction(const Request& request, ResponseWriter response) -> void;
