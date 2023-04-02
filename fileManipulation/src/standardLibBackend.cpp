#include <fileManipulation.h>
#ifdef LLGE_LINUX

namespace LLGE {
    namespace fileManipulation {
        std::filesystem::path get_game_path()
        {
            return std::filesystem::canonical("/proc/self/exe").parent_path();
        }

        bool createFile(std::string path)
        {
            std::ofstream create = std::ofstream(path, std::ios::binary);
            return create.good();
        }

        bool writeEntireFileBinary(std::string name, void *buffer, size_t s)
        {
            std::ofstream file(name, std::ios::binary);
            file.write((char*)buffer, s);
            return file.good();
        }

        bool appendToFileBinary(std::string name, void *buffer, size_t s)
        {
            std::ofstream file(name, std::ios::binary | std::ios::app);
            file.write((char*)buffer, s);
            return file.good();
        }

        bool appendToFileBinary(std::string name, std::string append)
        {
            std::ofstream file(name, std::ios::binary | std::ios::app);
            file.write(append.c_str(), append.size());
            return file.good();
        }
    };
}

#endif