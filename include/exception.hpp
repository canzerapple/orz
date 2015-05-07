#ifndef ORZ_EXCEPTION_INCLUDE
#define ORZ_EXCEPTION_INCLUDE

#include "typedefine.hpp"

namespace ORZ
{

	class Exception
	{
	public:
		class Current
		{
		protected:
			String _file;
			String _function;
			Int32  _line;

		public:
			Current( 
				const String& file,
				const String& function,
				const Int32& line )
				: _file(file)
				, _line(line)
				, _function(function)
			{
				
			}

			const String& file() const {
				return _file;
			}

			const Int32& line() const {
				return _line;
			}

			const String& function() const {
				return _function;
			}
		};

	protected:
		
		Current _current;

	public:
		

		Exception( const Current& current )
			: _current(current)
		{
			
		}

		virtual String name() const = 0;

		virtual String message() const{
			return name();
		}

	};

}

#define EC ORZ::Exception::Current(__FILE__,__FUNCTION__,__LINE__)

#define ORZ_REGISTER_EXCEPTION( classOfException ) virtual String name() const { return _N(classOfException); }



#include "exception/argument.hpp"
	

#endif