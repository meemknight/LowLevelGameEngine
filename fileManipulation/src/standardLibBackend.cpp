#include <fileManipulation.h>
#ifdef LLGE_FILE_MANIPULATION_STD_BACKEND

//todo not tested

namespace LLGE {
	namespace fileManipulation {
		std::filesystem::path get_game_path()
		{
			return std::filesystem::canonical("/proc/self/exe").parent_path(); //todo does this work on windows?
		}

		bool createFile(std::string_view path)
		{
			std::ofstream create = std::ofstream(path, std::ios::binary);
			return create.good();
		}

		bool writeEntireFileBinary(std::string_view name, void *buffer, size_t s)
		{
			std::ofstream file(name, std::ios::binary);
			file.write((char*)buffer, s);
			return file.good();
		}

		bool appendToFileBinary(std::string_view name, void *buffer, size_t s)
		{
			std::ofstream file(name, std::ios::binary | std::ios::app);
			file.write((char*)buffer, s);
			return file.good();
		}

		bool appendToFileBinary(std::string_view name, std::string_view append)
		{
			return appendToFileBinary(name, (void*)append.data(), append.size());
		}

		size_t readEntireFileBinary(std::string_view name, void *buffer, size_t s, size_t from)
		{

			std::ifstream file(name, std::ios::binary | std::ios::ate);
			if (!file.is_open()) {
				//log(LLGE::Logger::LogLevel::ERR, "Failed to open file %s", name.c_str()); //not implemented yet
			}

			if (s == 0) { return 0; }

			std::streampos fileSize = file.tellg();
			if (fileSize <= 0) {
				return 0; //we read 0 bytes so it is not an error
			}
			if (from > fileSize) {
				return 0; //we read 0 bytes so it is not an error necessarily
			}
			if (s < ((size_t)fileSize - from)) {

				//not an error, just read as much as possible
				file.seekg(from, std::ios::beg);
				file.read(static_cast<char *>(buffer), s);

			}

			file.seekg(from, std::ios::beg);
			file.read(static_cast<char*>(buffer), std::min(s, (size_t)fileSize)); //we just read as much as possible
			if (!file) {
				//std::cerr << "Error: Failed to read file " << name << std::endl; //replace with logs later
				return 0;
			}

			auto readPos = file.tellg();
			file.close();
			return (size_t)readPos;
		}
	};
}

#endif