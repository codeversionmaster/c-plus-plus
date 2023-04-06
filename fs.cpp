#include <iostream>
#include <filesystem>

int main() {
    // Note that it is sub namespace std::filesystem
    namespace fs = std::filesystem;

    // This is the path to examine
    fs::path explore_path = "./dir_to_examine";

    // Check the path exists and is a directory
    if (fs::exists(explore_path) && fs::is_directory(explore_path)) {
        uintmax_t total_size = 0;

	// Parse through the directory
        for (const auto& entry : fs::directory_iterator(explore_path)) {
            auto status = fs::status(entry);

	    // Check if the path is directory or file
            std::cout << (fs::is_directory(status) ? "[Directory]" : "[File]     ") << " " << entry.path() << '\n';

	    // Add file size to total_size if it is file
            if (fs::is_regular_file(status)) {
                total_size += fs::file_size(entry);
            }
        }

        std::cout << "Total size of regular files is: " << total_size << " bytes\n";
    } else {
        std::cerr << "Invalid directory: " << explore_path << '\n';
    }

    return 0;
}

