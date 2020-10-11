//
// Created by ksenia on 11.10.2020.
//

#include "helper_bot.hpp"

struct bot_state {};

bot_state* init_bot() {
    return new bot_state();
}

void stop_bot(bot_state const* state) {
    delete state;
}

void execute_command(bot_environment const* env, bot_state* state, char const* command) {
    if (command == nullptr || state == nullptr || env == nullptr)
        throw std::runtime_error("Invalid input");
    bool eq = false;
    size_t length = 0;
    for (const char *c = command; *c; ++c, ++length) {
        if (*c == 'h')
            eq = true;
    }
    if (length && eq)
        *(env->out) << "Hello!" << std::endl;
    else
        *(env->err) << "Unknown command '" << command << "'!" << std::endl;
}