#include "Core.hpp"

int main()
{
	{
		Engine::Core core;
		core.Run();
	}
#if _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}

