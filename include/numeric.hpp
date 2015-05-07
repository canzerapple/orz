#ifndef ORZ_NUMERIC_INCLUDE
#define ORZ_NUMERIC_INCLUDE

#include "typedefine.hpp"

#define NUMERIC_SETVALUE(pod,name,type) \
	void setValue( const pod& v ) { _value.name = v; _type = type; }

namespace ORZ
{
	class Numeric
	{
		union Value
		{
			Int8   i8;
			Int16  i16;
			Int32  i32;
			Int64  i64;

			UInt8   ui8;
			UInt16  ui16;
			UInt32  ui32;
			UInt64  ui64;

			Float32 f32;
			Float64 f64;

			Char    c;
		};

		enum Type
		{
			TYPE_INT8,
			TYPE_INT16,
			TYPE_INT32,
			TYPE_INT64,
			TYPE_UINT8,
			TYPE_UINT16,
			TYPE_UINT32,
			TYPE_UINT64,
			TYPE_FLOAT32,
			TYPE_FLOAT64,
			TYPE_CHAR
		};

		Value _value;
		Type  _type;

	protected:
		
		NUMERIC_SETVALUE(Int8, i8, TYPE_INT8);
		NUMERIC_SETVALUE(Int16, i16, TYPE_INT16);
		NUMERIC_SETVALUE(Int32, i32, TYPE_INT32);
		NUMERIC_SETVALUE(Int64, i64, TYPE_INT64);

		NUMERIC_SETVALUE(UInt8, ui8, TYPE_UINT8);
		NUMERIC_SETVALUE(UInt16, ui16, TYPE_UINT16);
		NUMERIC_SETVALUE(UInt32, ui32, TYPE_UINT32);
		NUMERIC_SETVALUE(UInt64, ui64, TYPE_UINT64);

		NUMERIC_SETVALUE(Float32, f32, TYPE_FLOAT32);
		NUMERIC_SETVALUE(Float64, f64, TYPE_FLOAT64);
		NUMERIC_SETVALUE(Char, c, TYPE_CHAR);

	public:

		template< class NumericT >
		Numeric(const NumericT& value)
		{
			setValue(value);
		}
	};
}

#undef NUMERIC_SETVALUE

#endif // !ORZ_NUMERIC_INCLUDE
