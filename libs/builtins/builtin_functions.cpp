#include "include/builtin_functions.hpp"

#include <chrono>
#include <cstdint>

#include "models.hpp"

namespace builtin {

model::Object* print(model::Object* self, const model::List* args) {
    std::string text;
    for (const auto* arg : args->val) {
        text += arg->to_string() + " ";
    }
    std::cout << text << std::endl;
    return new model::Nil();
};

model::Object* input(model::Object* self, const model::List* args) {
    const auto prompt_obj = get_one_arg(args);
    std::cout << prompt_obj->to_string();
    std::string result;
    std::getline(std::cin, result);
    return new model::String(result);
};

model::Object* isinstance(model::Object* self, const model::List* args) {
    if (!(args->val.size() == 2)) {
        assert(false && "函数参数不足两个");
    }

    const auto a = args->val[0];
    const auto b = args->val[1];
    return check_based_object(a, b);
    
};

model::Object* help(model::Object* self, const model::List* args) {
    // todo
    return new model::Nil();
};

model::Object* breakpointer(model::Object* self, const model::List* args) {
    // todo
    return new model::Nil();
};

model::Object* range(model::Object* self, const model::List* args) {
    // todo
    return new model::Nil();
};

model::Object* cmd(model::Object* self, const model::List* args) {
    // todo
    return new model::Nil();
};

model::Object* now(model::Object* self, const model::List* args) {
    using namespace std::chrono;
    auto now = high_resolution_clock::now().time_since_epoch();
    int64_t time = duration_cast<nanoseconds>(now).count();
    return new model::Int( deps::BigInt(std::to_string(time)) );
};

model::Object* setattr(model::Object* self, const model::List* args) {
    // todo
    return new model::Nil();
};

model::Object* getattr(model::Object* self, const model::List* args) {
    // todo
    return new model::Nil();
};

model::Object* delattr(model::Object* self, const model::List* args) {
    // todo
    return new model::Nil();
};

model::Object* getrefc(model::Object* self, const model::List* args) {
    const auto obj = get_one_arg(args);
    return new model::Int( deps::BigInt(obj->get_refc_()) );
};

model::Object* copy(model::Object* self, const model::List* args) {
    // todo
    return new model::Nil();
};

model::Object* create(model::Object* self, const model::List* args) {
    if (args->val.empty()) {
        return new model::Object();
    }
    const auto obj = get_one_arg(args);
    const auto new_obj = new model::Object();
    new_obj->attrs.insert("__parent__", obj);
    return new_obj;

};

model::Object* typeofobj(model::Object* self, const model::List* args) {
    // todo
    return new model::Nil();
};

}
