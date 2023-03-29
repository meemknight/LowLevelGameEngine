#include <componentExample.h>
#include <assert.h> //todo make our own assert api

namespace LLGE
{
namespace ComponentExample
{

	void foo() {/*...*/ }



	//provide a definition for both linux or windows, if the component works only on oneplatform provide a blakn definition for the other
	//or even better assert an error

#ifdef LLGE_WINDOWS
	void windowsOnlyFunction() { /*...*/; }
#endif

#ifdef LLGE_LINUX
	void windowsOnlyFunction() { assert(0); }
#endif


};
};