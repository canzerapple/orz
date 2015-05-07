#ifndef ORZ_EXCEPTION_ARGUMENT_INCLUDE
#define ORZ_EXCEPTION_ARGUMENT_INCLUDE

#include <memory>

#include "../exception.hpp"
#include "../numeric.hpp"

namespace ORZ
{
	class ArgumentException
		: public Exception
	{
		String _argument;
		String _message;
	public:
		ORZ_REGISTER_EXCEPTION(ArgumentException);

		ArgumentException( 
			const String& argument , 
			const String& message , 
			const Current& current )
			: _argument(argument)
			, _message(message)
			, Exception(current)
		{

		}

		ArgumentException( 
			const String& argument ,  
			const Current& current )
			: _argument(argument)
			, Exception(current)
		{

		}
	};

	class ArgumentNullException
		: public ArgumentException
	{
		String _argument;
	public:

		ORZ_REGISTER_EXCEPTION(ArgumentNullException);

		ArgumentNullException( const String argument , const Current& current )
			: ArgumentException(argument,current)
		{

		}

		template< class T >
		static Bool check( const T* argument )
		{
			if( argument == nullptr ){
				return true;
			}

			return false;
		}

		template< class T >
		static Bool check( const std::shared_ptr<T>& argument )
		{
			return check(argument.get());
		}
	};


	class ArgumentOutOfRangeException
		: public ArgumentException
	{
		Numeric _source;
		Numeric _max;
		Numeric _min;
	public:

		ORZ_REGISTER_EXCEPTION(ArgumentOutOfRangeException);

		const Numeric& srouce() const {
			return _source;
		}

		const Numeric& maximux() const {
			return _max;
		}

		const Numeric& minimux() const {
			return _min;
		}

		ArgumentOutOfRangeException(
			const String& argument,
			const Numeric& source, 
			const Numeric& minimux, 
			const Numeric& maximux,
			const Current& current 
		)
			: ArgumentException(argument,current)
			, _source(source)
			, _min(minimux)
			, _max(maximux)
		{

		}

		template< class T >
		static Bool check(const T& source, const T& minimux, const T& maximux)
		{
			if (source >= minimux && source <= maximux){
				return false;
			}
			return true;
		}
	};
}

#define CHECK_ARGUMENT_NULL( argument ) \
	{\
		if( ArgumentNullException::check(argument) )\
						{\
			throw ArgumentNullException( _N(argument ) , EC );\
						} \
	}

#define CHECK_ARGUMENT_RANGE( argument , minimux , maximux ) \
	{\
		if( ArgumentOutOfRangeException::check(argument,minimux,maximux) )\
		{\
			throw ArgumentOutOfRangeException(_N(argument),argument,minimux,maximux,EC);\
		}\
	}


#endif // !ORZ_EXCEPTION_ARGUMENT_INCLUDE
