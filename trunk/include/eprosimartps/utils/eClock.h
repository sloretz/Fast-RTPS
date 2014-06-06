/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima RTPS is licensed to you under the terms described in the
 * EPROSIMARTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file eClock.h
 *
 *  Created on: Apr 4, 2014
 *      Author: Gonzalo Rodriguez Canosa
 *      email:  gonzalorodriguez@eprosima.com
 *              grcanosa@gmail.com  	
 */

#ifndef ECLOCK_H_
#define ECLOCK_H_

#if defined(_WIN32)
#include <time.h>
#include <windows.h> //I've ommited this line.
#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif
 
struct timezone 
{
  int  tz_minuteswest; /* minutes W of Greenwich */
  int  tz_dsttime;     /* type of dst correction */
};
 

#else
#include <sys/time.h>
#include <chrono>

#endif

#include "eprosimartps/common/types/Time_t.h"


namespace eprosima {
namespace rtps {

/**
 * Clock used to obtain the time in us since 1900.
 * @ingroup UTILITIESMODULE
 */
class eClock {
public:
	eClock();
	virtual ~eClock();
	int32_t m_seconds_from_1900_to_1970;
	int32_t m_utc_seconds_diff;
#if defined(_WIN32)
	FILETIME ft;
#else
	timeval m_now;
#endif
	bool setTimeNow(Time_t* now);
	bool setTimeRealNow(TimeReal_t* tnow);
//	int my_gettimeofday(struct timeval *tv, struct timezone *tz);
	static void my_sleep(uint32_t milliseconds);


};

} /* namespace rtps */
} /* namespace eprosima */

#endif /* CLOCK_H_ */