/***************************************************************************
* Copyright (c) 2016, Martin Renou, Johan Mabille, Sylvain Corlay and      *
* Wolf Vollprecht                                                          *
*                                                                          *
* Distributed under the terms of the BSD 3-Clause License.                 *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/

#ifndef XPYT_PYTHON_INTERPRETER_HPP
#define XPYT_PYTHON_INTERPRETER_HPP

#include <string>

#include "Python.h"

#include "xeus/xjson.hpp"
#include "xeus/xinterpreter.hpp"

namespace xpyt
{
    class python_interpreter : public xeus::xinterpreter
    {

    public:

        python_interpreter(int argc, const char* const* argv);
        virtual ~python_interpreter();

    private:

        void configure_impl() override;

        xeus::xjson execute_request_impl(
            int execution_counter,
            const std::string& code,
            bool silent,
            bool store_history,
            const xeus::xjson_node* user_expressions,
            bool allow_stdin) override;

        xeus::xjson complete_request_impl(
            const std::string& code,
            int cursor_pos) override;

        xeus::xjson inspect_request_impl(
            const std::string& code,
            int cursor_pos,
            int detail_level) override;

        xeus::xjson history_request_impl(const xeus::xhistory_arguments& args) override;

        xeus::xjson is_complete_request_impl(const std::string& code) override;

        xeus::xjson kernel_info_request_impl() override;

        void input_reply_impl(const std::string& value) override;
    };
}

#endif
