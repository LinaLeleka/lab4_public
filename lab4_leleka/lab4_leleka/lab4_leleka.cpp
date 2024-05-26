#include <iostream>
#include <filesystem>
#include <iomanip>

using namespace std;
namespace fs = std::filesystem;

void ProcessingPath(const fs::path& path) {
    if (!fs::exists(path) || !fs::is_directory(path)) {
        cerr << "Error path" << endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(path)) {
        auto file_size = fs::is_regular_file(entry.status()) ? fs::file_size(entry) : 0;
        cout << setw(50) << left << entry.path().filename().string()
            << setw(10) << right << file_size << " bytes" << endl;
    }
}

int main() {
    string path;
    cout << "Catalog path: ";
    cin >> path;

    ProcessingPath(path);

    return 0;
}
