
#include "time.h"

#if __MP_LEGACY_SUPPORT_GETTIME__

#include <mach/clock.h>
#include <mach/mach.h>

int clock_gettime( int clk_id, struct timespec *ts )
{ 
  clock_serv_t cclock;
  mach_timespec_t mts;
  host_get_clock_service( mach_host_self(), clk_id, &cclock );
  const int ret = clock_get_time( cclock, &mts );
  mach_port_deallocate( mach_task_self(), cclock );
  if ( ts )
  {
    ts->tv_sec  = mts.tv_sec;
    ts->tv_nsec = mts.tv_nsec;
  }
  return ret;
}

#endif

// // Implementation of clock_gettime for OSX10.11 and older.
// #include <sys/time.h>
// static int
// clock_gettime( int /* clk_id */, struct timespec *ts )
// {
//   struct timeval now;
//   const int rv = gettimeofday(&now, NULL);
//   if ( ts && !rv )
//   {
//     ts->tv_sec  = now.tv_sec;
//     ts->tv_nsec = now.tv_usec * 1000;
//   }
//   return rv;
// }

