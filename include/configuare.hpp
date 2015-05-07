#ifndef ORZ_CONFIGUARE_INCLUDE
#define ORZ_CONFIGUARE_INCLUDE


#if !defined( ORZ_WINDOWS ) && !defined(ORZ_LINUX)

#	if defined( _WIN32 ) || defined( _WIN64 )
#		define ORZ_WINDOWS
#	else
#		define ORZ_LINUX
#	endif

#endif

#if defined( ORZ_WINDOWS )
#	include<windows.h>
#endif

#if defined( ORZ_WINDOWS )

#	if defined( _UNICODE )
#		define ORZ_UNICODE
#	else 
#		define ORZ_MULTIBYTE
#	endif

#else defined( ORZ_LINUX )
#	define ORZ_MULTIBYTE
#endif

#define ORZ_NATIVE_TO_STRING_INTERNAL( object ) #object
#define ORZ_NATIVE_TO_STRING(object) ORZ_NATIVE_TO_STRING_INTERNAL(object)

#if defined( ORZ_UNICODE )
#	define ORZ_NATIVE_STRING_INTERNAL(chars) L##chars
#	define ORZ_NATIVE_STRING(chars) ORZ_NATIVE_TO_STRING_INTERNAL(chars)
#else
#	define ORZ_NATIVE_STRING(chars) chars
#endif

#define _X(chars)  ORZ_NATIVE_STRING(chars)
#define _N(object) ORZ_NATIVE_STRING( ORZ_NATIVE_TO_STRING(object) )

#endif // !ORZ_CONFIGUARE_INCLUDE
