
#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER rgw_op

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./tracing/rgw_op.h"

#if !defined(TRACING_RGW_OP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define TRACING_RGW_OP_H

#include <lttng/tracepoint.h>

#include "tracing/tracing-common.h"
#include "include/int_types.h"

TRACEPOINT_EVENT(rgw_op, before_data_transfer,
    TP_ARGS(
        const char*, req_id),
    TP_FIELDS(
        ctf_string(req_id, req_id)
    )
)

TRACEPOINT_EVENT(rgw_op, after_data_transfer,
    TP_ARGS(
        const char*, req_id,
        long, ofs),
    TP_FIELDS(
        ctf_string(req_id, req_id)
        ctf_integer(long, ofs, ofs)
    )
)

TRACEPOINT_EVENT(rgw_op, processor_complete_enter,
    TP_ARGS(
        const char*, req_id),
    TP_FIELDS(
        ctf_string(req_id, req_id)
    )
)

TRACEPOINT_EVENT(rgw_op, processor_complete_exit,
    TP_ARGS(
        const char*, req_id),
    TP_FIELDS(
        ctf_string(req_id, req_id)
    )
)

#endif /* TRACING_RGW_OP_H */

#include <lttng/tracepoint-event.h>
