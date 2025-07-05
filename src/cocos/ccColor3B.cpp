// Color3B.cpp
#include "ccTypes.h"
#include <sol/sol.hpp>
#include <Geode/Geode.hpp>


using T = cocos2d::ccColor3B;

void register_ccColor3B(sol::state& lua) {

    struct color3b_custom_ctor {
        cocos2d::ccColor3B operator()(float r, float g, float b) {
            return cocos2d::ccColor3B{static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b)};
        }
    };

    auto t = lua.new_usertype<T>("ccColor3B",
        sol::constructors<T(), T(const T&), color3b_custom_ctor>());
    t["r"] = &cocos2d::ccColor3B::r;
    t["g"] = &cocos2d::ccColor3B::g;
    t["b"] = &cocos2d::ccColor3B::b;
}