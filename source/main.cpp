#include "exception.hpp"
#include "strings/range.hpp"
#include "strings/format.hpp"
#include <iostream>
using namespace ORZ;
using namespace std;

int main()
{
	try
	{
		int ix = 20;

		DWORD dw1 = GetTickCount();

		for (int ix = 0; ix < 10; ++ix)
		{
			cout << Strings::format(_X("aabbccdd%d!dbbe"), 12, 14) << endl;
		}

		dw1 = GetTickCount() - dw1;

		cout << dw1;

		

		CHECK_ARGUMENT_RANGE(ix, 30, 40);
	}
	catch( Exception& e )
	{
		cout<<e.message()<<endl;
	}
	return 0;
}