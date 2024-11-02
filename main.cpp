#include "lib.h"
#include "Creators.h"

int main()
{
	std::unique_ptr<System> sys = std::make_unique<Accounter>();
	SystemColor(color::def);
	while (1)
	{
		sys.Start();
	}
}
