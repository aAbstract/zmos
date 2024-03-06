#include "mgos.h"

static void timer1_cb(void *arg) {
  static bool s_tick_tock = false;
  LOG(LL_INFO, ("Timer1: %s uptime: %.2lf, RAM: %lu, %lu free",
                (s_tick_tock ? "Tick" : "Tock"), mgos_uptime(),
                (unsigned long) mgos_get_heap_size(),
                (unsigned long) mgos_get_free_heap_size()));
  s_tick_tock = !s_tick_tock;
  (void) arg;
}

static void timer2_cb(void *arg) {
  static bool s_tick_tock = false;
  LOG(LL_INFO, ("Timer2: %s uptime: %.2lf, RAM: %lu, %lu free",
                (s_tick_tock ? "Tick" : "Tock"), mgos_uptime(),
                (unsigned long) mgos_get_heap_size(),
                (unsigned long) mgos_get_free_heap_size()));
  s_tick_tock = !s_tick_tock;
  (void) arg;
}

enum mgos_app_init_result mgos_app_init(void) {
  mgos_set_timer(1000, MGOS_TIMER_REPEAT, timer1_cb, NULL);
  mgos_set_timer(5000, MGOS_TIMER_REPEAT, timer2_cb, NULL);
  return MGOS_APP_INIT_SUCCESS;
}