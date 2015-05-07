#ifndef ORZ_TYPEDEFINE_INCLUDE
#define ORZ_TYPEDEFINE_INCLUDE

#include <string>
#include "configuare.hpp"

namespace ORZ
{
#if defined( ORZ_WINDOWS )
	typedef INT8  Int8;
	typedef INT16 Int16;
	typedef INT32 Int32;
	typedef INT64 Int64;

	typedef UINT8  UInt8;
	typedef UINT16 UInt16;
	typedef UINT32 UInt32;
	typedef UINT64 UInt64;
	
#	if defined( ORZ_UNICODE )
	typedef WCHAR Char;
#	else
	typedef CHAR Char;
#	endif

#endif


#if defined( ORZ_LINUX )
	typedef int8_t  Int8;
	typedef int16_t Int16;
	typedef int32_t Int32;
	typedef int64_t Int64;

	typedef uint8_t  uInt8;
	typedef uint16_t uInt16;
	typedef uint32_t uInt32;
	typedef uint64_t uInt64;

	typedef char Char;
#endif

	typedef double Float64;
	typedef float  Float32;

	typedef bool Bool;

	typedef unsigned char Byte;

	typedef std::basic_string<Char> String;

}

#endif // !ORZ_TYPEDEFINE_INCLUDE
