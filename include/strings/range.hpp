#ifndef ORZ_STRINGS_RANGE_INCLUDE
#define ORZ_STRINGS_RANGE_INCLUDE

#include "../typedefine.hpp"
#include <xutility>

namespace ORZ
{
	namespace Strings
	{
		namespace Internal
		{
			template<class T> struct RangeContain
			{
				typedef typename T::const_iterator iterator;

			};

			template< class ContainT >
			class Range
			{
			public:
				typedef typename RangeContain<ContainT>::iterator iterator;
				typedef typename std::iterator_traits<iterator>::distance_type distance_type;
				typedef typename std::iterator_traits<iterator>::reference reference;

			protected:

				iterator _begin;
				iterator _end;

			public:
				Range(iterator begin, iterator end)
					: _begin(begin)
					, _end(end)
				{

				}

				iterator begin() const {
					return _begin;
				}

				iterator end() const {
					return _end;
				}

				Bool empty() const {
					return (begin() == end());
				}

				distance_type size() const {
					return std::distance(begin(), end());
				}

				ContainT contain() const {

					return ContainT(begin(), end());
				}

				iterator find(reference v)
				{
					return std::find(_begin, _end, v);
				}
			};
		}
		
		typedef Internal::Range<String> Range;
	}
}

#endif