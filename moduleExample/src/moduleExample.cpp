#include <moduleExample.h>
#include <assert.h> //todo make our own assert api

namespace LLGE
{
namespace ModuleExample
{

	void foo() {/*...*/ }

	//provide a definition for both linux or windows, if the module works only on oneplatform provide a blakn definition for the other
	//or even better assert an error

#ifdef LLGE_WINDOWS
	void windowsOnlyFunction() { /*...*/; }
#endif

#ifdef LLGE_LINUX
	void windowsOnlyFunction() { assert(0); }
#endif


	//how to structure big systems
	struct MyStruct
	{

		MyStruct() {};

		void init() {}; //here we can allocate all the memory the struct needs

		void cleanup() {}; //here we deallocate it

	};

	//if you really need some global state you can do this
	//and asert if the module was initialized when calling functions
	static void initializeModule() {};


};
};