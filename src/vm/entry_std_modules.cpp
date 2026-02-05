#include "../models/models.hpp"
#include "../libs/io/include/io_lib.hpp"

namespace kiz {

void Vm::entry_std_modules() {
    std_modules.insert("io", model::create_nfunc(io_lib::init_module));
}
} // namespace model