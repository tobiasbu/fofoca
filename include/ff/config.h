#ifndef _FF_CONFIG_H_
#define _FF_CONFIG_H_

#if defined(_WIN32)

	/// Windows
	#define FF_OS_WINDOWS
	/// Windows
	#define FF_OS_WIN32
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif

#elif defined(__APPLE__) && defined(__MACH__)

	// Apple platform, see which one it is
	#include "TargetConditionals.h"
  #define FF_OS_UNIX

	#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR

		// iOS
		#define FF_OS_IOS

	#elif TARGET_OS_MAC

		// MacOS
		#define FF_OS_MACOS

	#else

		// Unsupported Apple system
		#error This Apple operating system is not supported by Fofoca library

	#endif

#elif defined(__unix__)

  #define FF_OS_UNIX

	// UNIX system
	#if defined(__ANDROID__)

		// Android
		#define FF_OS_ANDROID

	#elif defined(__linux__)

		// Linux
		#define FF_OS_LINUX

	#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)

		// FreeBSD
		#define FF_OS_FREEBSD

	#else

		// Unsupported UNIX system
		#error This UNIX operating system is not supported by Fofoca

	#endif

#else

	// Unsupported system
	#error This operating system is not supported by Fofoca

#endif

#endif
