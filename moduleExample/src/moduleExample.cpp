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

	//
	struct PhysicsManager;
	struct AssetManager;
	//

	//let's look at a concrete example for a ECS
	//let's not have global data, the user ill be responsible of creating the object
	struct ECSManager
	{
		void init() {}; //here we can allocate all the memory the struct needs
		void cleanup() {}; //here we deallocate it


		//and here you can create your api for the ecs and hold all your data in this struct

		//if you need stuff from other components, try to request plain old data, example:

		//PhysicsManager is just another component

		void update(PhysicsManager &p, AssetManager &a, float deltaTime) {}

	};



};
};