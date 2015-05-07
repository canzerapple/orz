#ifndef ORZ_STRINGS_FORMAT_INCLUDE
#define ORZ_STRINGS_FORMAT_INCLUDE

#include "range.hpp"

namespace ORZ
{
	namespace Strings
	{

		class FormatException
			: public Exception
		{
			String _format;
		public:

			FormatException(const String& format, const Current& c)
				: Exception(c)
				, _format(format)
			{

			}

			ORZ_REGISTER_EXCEPTION(FormatException);
		};

		class FormatTokenizer
		{
		protected:
			Range _contain;

			Range _prefix;
			Range _format;

		public:
			typedef Range::iterator iterator;

			Bool next()
			{
				static const Char SPLIT = _X('%');
				static const Char END = _X('!');

				_prefix = Range(_contain.end(),_contain.end());
				_format = Range(_contain.end(), _contain.end());

				if (_contain.empty()){
					return false;
				}

				iterator token = _contain.find(SPLIT);

				
				_prefix = Range(_contain.begin(), token);

				if (token != _contain.end())
				{
					token = _contain.find(END);

					if (token == _contain.end()){
						throw FormatException(String(_prefix.end(), token), EC);
					}

					_format = Range(_prefix.end(), token);
					_contain = Range(token + 1, _contain.end());
				}
				else
				{
					_contain = Range(_contain.end(), _contain.end());
				}

				return true;
			}

			FormatTokenizer(iterator begin, iterator end)
				: _contain(begin, end)
				, _prefix(end, end)
				, _format(end, end)
			{

			}

			String prefix() const {
				return _prefix.contain();
			}

			String format() const {
				return _format.contain();
			}

			
			template< class T >
			bool fill(String& to, const T& data)
			{
				if (next()){
					to.append(_prefix.begin(), _prefix.end());

					if (_format.empty()){
						return false;
					}
					to.append(std::to_string(data));
					return true;
				}

				return false;
				

			}
		};

		String format(const String& fmt)
		{
			return fmt;
		}

		namespace Internal
		{
			template< class T, class ... Args >
			bool format(String& to, FormatTokenizer& tokenizer, const T& data)
			{
				return tokenizer.fill(to, data);
			}

			template< class T , class ... Args >
			bool format(String& to , FormatTokenizer& tokenizer , const T& data , const Args& ... args)
			{
				if (!format(to, tokenizer, data)){
					return false;
				}

				return format(to, tokenizer, args...);
			}
		}

		template< class ... Args >
		String format(const String& fmt, const Args& ... args)
		{
			FormatTokenizer tokenizer(fmt.begin(), fmt.end());
			String to;

			Internal::format(to, tokenizer, args...);

			return to;
		}
	}
}

#endif