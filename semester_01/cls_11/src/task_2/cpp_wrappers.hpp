#pragma once

#include "c_style_api.hpp"

#include <memory>

namespace cls_11 {
    std::shared_ptr<c_style_api::resource> acquire_resource(c_style_api::resource_mode mode) {
        c_style_api::resource* res = c_style_api::init_resource(mode);
        return std::shared_ptr<c_style_api::resource>(res, c_style_api::release_resource);
    }

    std::shared_ptr<c_style_api::sub_resource> get_sub_resource(std::shared_ptr<c_style_api::resource> const & res) {
        c_style_api::sub_resource* sub_res = c_style_api::get_sub_resource(res.get());
        return std::shared_ptr<c_style_api::sub_resource>(res, sub_res);
    }

    std::shared_ptr<c_style_api::sub_resource> acquire_sub_resource(c_style_api::resource_mode mode) {
        std::shared_ptr<c_style_api::resource> res = acquire_resource(mode);
        return get_sub_resource(res);
    }
}