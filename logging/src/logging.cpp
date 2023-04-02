#include <logging.h>

namespace LLGE
{
namespace logging
{

	LogManager defaultLog;

	void log(std::string_view message, int type, unsigned int id)
	{
		//LLGE_RESOURCES_PATH "/../logs"

		defaultLog.log(message, type, id);
	}






};
};