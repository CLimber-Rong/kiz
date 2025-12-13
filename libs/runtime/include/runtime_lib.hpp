#pragma once
#include "vm.hpp"

namespace runtime_lib {

model::Object* locals(model::Object* self, const model::List* args);
model::Object* globals(model::Object* self, const model::List* args);
model::Object* vars(model::Object* self, const model::List* args);
model::Object* current_module(model::Object* self, const model::List* args);

model::Object* opstack_pop(model::Object* self, const model::List* args);

model::Object* _init_module_(model::Object* self, const model::List* args);


} // namespace runtime_lib