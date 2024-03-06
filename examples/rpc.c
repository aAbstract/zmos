#include "mgos.h"
#include "mgos_rpc.h"

static void sum_cb(struct mg_rpc_request_info *ri, void *cb_arg, struct mg_rpc_frame_info *fi, struct mg_str args) {
  double a = 0, b = 0;
  if (json_scanf(args.p, args.len, ri->args_fmt, &a, &b) == 2) {
    mg_rpc_send_responsef(ri, "%.2lf", a + b);
  } else {
    mg_rpc_send_errorf(ri, -1, "Bad request. Expected: {\"a\":N1,\"b\":N2}");
  }
  (void) cb_arg;
  (void) fi;
}

enum mgos_app_init_result mgos_app_init(void) {
  mg_rpc_add_handler(mgos_rpc_get_global(), "sum", "{a: %lf, b: %lf}", sum_cb, NULL);
  return MGOS_APP_INIT_SUCCESS;
}