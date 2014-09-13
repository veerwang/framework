/*
 * =====================================================================================
 *
 *       Filename:  Debug.h
 *
 *    Description:  Leaktracer used head 
 *
 *        Version:  1.0
 *        Created:  2012年03月29日 10时16分01秒
 *       Revision:  none
 *       Compiler:  arm-g++
 *
 *         Author:  kevin (kevin.wang), kevin.wang2004@hotmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  _DEBUG_INC
#define  _DEBUG_INC
#ifdef LEAKTRACER
#include 	"../../../lib/leaktracer/inc/MemoryTrace.hpp"
#define MAC_LEAKTRACE_START   leaktracer::MemoryTrace::GetInstance().startMonitoringAllThreads();
#define MAC_LEAKTRACE_END     leaktracer::MemoryTrace::GetInstance().stopAllMonitoring();

#define MAC_LEAKTRACE_REPORT  std::ofstream oleaks; \
			      oleaks.open("leaks.out", std::ios_base::out); \
			      if (oleaks.is_open()) \
			      	leaktracer::MemoryTrace::GetInstance().writeLeaks(oleaks); \
			      else \
				std::cerr << "Failed to write to \"leaks.out\"\n";
#else
#define MAC_LEAKTRACE_START
#define MAC_LEAKTRACE_END
#define MAC_LEAKTRACE_REPORT
#endif
#endif   /* ----- #ifndef _DEBUG_INC  ----- */
