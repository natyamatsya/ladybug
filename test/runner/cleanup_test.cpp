#include <filesystem>
#include <system_error>

#include "test_helper/test_helper.h"

using namespace lbug::testing;
using namespace lbug::common;

int main(int argc, char** argv) {
    if (argc > 1 && std::string(argv[1]) == "--gtest_list_tests") {
        // Best-effort cleanup: use the non-throwing overload so a transient
        // failure (e.g. the dir is momentarily in use) can never crash test
        // discovery and abort the whole `ctest` run.
        std::error_code ec;
        std::filesystem::remove_all(TestHelper::getRootTempDir(), ec);
    }
    return 0;
}
