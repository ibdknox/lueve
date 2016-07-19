#include <runtime.h>

static CONTINUATION_1_1(bag_update, bag, bag);
static void bag_update(bag root, bag deltas)
{
    prf("delton %b\n", bag_dump(init, deltas)); 
    bag_foreach_e(deltas, e, sym(tag), sym(http-request), c) {
        prf("got a request!: %v\n", e);
    }
}


void init_request_service(bag b)
{
    register_delta_listener(b, cont(init, bag_update, b));
}

