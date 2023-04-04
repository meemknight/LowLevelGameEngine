#include <fileManipulation.h>
#ifdef LLGE_FILE_MANIPULATION_WINDOWS_BACKEND

#include <windows.h>
#include <fileapi.h>

namespace LLGE
{
	namespace fileManipulation
	{
		std::filesystem::path get_game_path()
		{
			char buffer[MAX_PATH];
			GetModuleFileName(NULL, buffer, MAX_PATH);
			// remove the file name
			std::string::size_type pos = std::string(buffer).find_last_of("\\/");
			std::string path = std::string(buffer).substr(0, pos);
			// Return the path as string_view
			return path;
		}

		bool createFile(std::string_view path)
		{
			HANDLE file = CreateFile(path.data(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (file == INVALID_HANDLE_VALUE) {
				// log error here
				return false;
			}
			CloseHandle(file);
			return true;
		}

		bool writeEntireFileBinary(std::string_view name, void* buffer, size_t s)
		{
			HANDLE file = CreateFile(name.data(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (file == INVALID_HANDLE_VALUE) {
				// log error here
				return false;
			}

			if (!buffer || s == 0)
			{
				CloseHandle(file);
				return true;
			}

			DWORD bytesWritten;
			bool success = WriteFile(file, buffer, static_cast<DWORD>(s), &bytesWritten, NULL) && bytesWritten == s;
			CloseHandle(file);
			return success;
		}

		bool appendToFileBinary(std::string_view name, void* buffer, size_t s)
		{
			HANDLE file = CreateFile(name.data(), FILE_APPEND_DATA, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (file == INVALID_HANDLE_VALUE) {
				// log error here
				return false;
			}

			DWORD bytesWritten;
			bool success = WriteFile(file, buffer, static_cast<DWORD>(s), &bytesWritten, NULL) && bytesWritten == s;
			CloseHandle(file);
			return success;
		}

		bool appendToFileBinary(std::string_view name, std::string_view append)
		{
			return appendToFileBinary(name, const_cast<char*>(append.data()), append.size());
		}

		size_t readEntireFileBinary(std::string_view name, void* buffer, size_t s, size_t from)
		{
			HANDLE file = CreateFile(name.data(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (file == INVALID_HANDLE_VALUE) {
				// log error here
				return false;
			}

			LARGE_INTEGER fileSize;
			if (!GetFileSizeEx(file, &fileSize)) {
				CloseHandle(file);
				return 0;
			}

			if (from > static_cast<size_t>(fileSize.QuadPart)) {
				CloseHandle(file);
				return 0;
			}

			OVERLAPPED overlapped = {};
			overlapped.Offset = static_cast<DWORD>(from);
			overlapped.OffsetHigh = static_cast<DWORD>(from >> 32);
			DWORD bytesRead;
			bool success = ReadFile(file, buffer, static_cast<DWORD>(s), &bytesRead, &overlapped);
			CloseHandle(file);

			return success ? static_cast<size_t>(bytesRead) : 0;
		}
	};
};

#endif