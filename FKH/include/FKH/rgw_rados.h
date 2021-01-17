
#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER rgw_rados

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./tracing/rgw_rados.h"

#if !defined(TRACING_RGW_RADOS_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define TRACING_RGW_RADOS_H

#include <lttng/tracepoint.h>

#include "tracing/tracing-common.h"
#include "include/int_types.h"

TRACEPOINT_EVENT(rgw_rados, prepare_enter,
    TP_ARGS(
        const char*, req_id),
    TP_FIELDS(
        ctf_string(req_id, req_id)
    )
)

TRACEPOINT_EVENT(rgw_rados, prepare_exit,
    TP_ARGS(
        const char*, req_id),
    TP_FIELDS(
        ctf_string(req_id, req_id)
    )
)

TRACEPOINT_EVENT(rgw_rados, operate_enter,
    TP_ARGS(
        const char*, req_id),
    TP_FIELDS(
        ctf_string(req_id, req_id)
    )
)

TRACEPOINT_EVENT(rgw_rados, operate_exit,
    TP_ARGS(
        const char*, req_id),
    TP_FIELDS(
        ctf_string(req_id, req_id)
    )
)

TRACEPOINT_EVENT(rgw_rados, complete_enter,
    TP_ARGS(
        const char*, req_id),
    TP_FIELDS(
        ctf_string(req_id, req_id)
    )
)

TRACEPOINT_EVENT(rgw_rados, complete_exit,
    TP_ARGS(
        const char*, req_id),
    TP_FIELDS(
        ctf_string(req_id, req_id)
    )
)

#endif /* TRACING_RGW_RADOS_H */

#include <lttng/tracepoint-event.h>
