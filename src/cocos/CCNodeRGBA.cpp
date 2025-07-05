// CCNodeRGBA_bind.cpp
#include "CCProtocols.h"
#include "Geode/cocos/base_nodes/CCNode.h"
#include "ccTypes.h"
#include <cocos2d.h>
#include <sol/sol.hpp>

//DEPENDS: Color3B

static int CCNodeRGBA_getColor(lua_State* L) {
    if (lua_gettop(L) != 1)
        return luaL_error(L, "Expected 1 argument (self)");
    
    cocos2d::CCNodeRGBA* obj = sol::stack::get<cocos2d::CCNodeRGBA*>(L, 1);
    if (!obj)
        return luaL_error(L, "Invalid object in getColor");
    auto color = obj->getColor();
    sol::stack::push(L, color);
    return 1;
}

static int CCNodeRGBA_setColor(lua_State* L) {
    if (lua_gettop(L) != 2)
        return luaL_error(L, "Expected 2 arguments (self, color)");
    cocos2d::CCNodeRGBA* obj = sol::stack::get<cocos2d::CCNodeRGBA*>(L, 1);
    if (!obj)
        return luaL_error(L, "Invalid object in setColor");
    if (!lua_istable(L, 2))
        return luaL_error(L, "Expected table for color argument");
    // Deserialize ccColor3B from table {r,g,b}
    auto color = sol::stack::get<cocos2d::ccColor3B>(L, 2);
    obj->setColor(color);
    return 0;
}

static int CCNodeRGBA_getOpacity(lua_State* L) {
    if (lua_gettop(L) != 1)
        return luaL_error(L, "Expected 1 argument (self)");
    cocos2d::CCNodeRGBA* obj = sol::stack::get<cocos2d::CCNodeRGBA*>(L, 1);
    if (!obj)
        return luaL_error(L, "Invalid object in getOpacity");
    uint8_t opacity = obj->getOpacity();
    sol::stack::push(L, opacity);
    return 1;
}

static int CCNodeRGBA_setOpacity(lua_State* L) {
    if (lua_gettop(L) != 2)
        return luaL_error(L, "Expected 2 arguments (self, opacity)");
    cocos2d::CCNodeRGBA* obj = sol::stack::get<cocos2d::CCNodeRGBA*>(L, 1);
    if (!obj)
        return luaL_error(L, "Invalid object in setOpacity");
    if (!lua_isinteger(L, 2))
        return luaL_error(L, "Expected integer for opacity");
    uint8_t opacity = static_cast<uint8_t>(lua_tointeger(L, 2));
    obj->setOpacity(opacity);
    return 0;
}

static int CCNodeRGBA_isCascadeColorEnabled(lua_State* L) {
    if (lua_gettop(L) != 1)
        return luaL_error(L, "Expected 1 argument (self)");
    cocos2d::CCNodeRGBA* obj = sol::stack::get<cocos2d::CCNodeRGBA*>(L, 1);
    if (!obj)
        return luaL_error(L, "Invalid object in isCascadeColorEnabled");
    bool enabled = obj->isCascadeColorEnabled();
    sol::stack::push(L, enabled);
    return 1;
}

static int CCNodeRGBA_setCascadeColorEnabled(lua_State* L) {
    if (lua_gettop(L) != 2)
        return luaL_error(L, "Expected 2 arguments (self, bool)");
    cocos2d::CCNodeRGBA* obj = sol::stack::get<cocos2d::CCNodeRGBA*>(L, 1);
    if (!obj)
        return luaL_error(L, "Invalid object in setCascadeColorEnabled");
    if (!lua_isboolean(L, 2))
        return luaL_error(L, "Expected boolean for setCascadeColorEnabled");
    bool enabled = lua_toboolean(L, 2) != 0;
    obj->setCascadeColorEnabled(enabled);
    return 0;
}

static int CCNodeRGBA_isCascadeOpacityEnabled(lua_State* L) {
    if (lua_gettop(L) != 1)
        return luaL_error(L, "Expected 1 argument (self)");
    cocos2d::CCNodeRGBA* obj = sol::stack::get<cocos2d::CCNodeRGBA*>(L, 1);
    if (!obj)
        return luaL_error(L, "Invalid object in isCascadeOpacityEnabled");
    bool enabled = obj->isCascadeOpacityEnabled();
    sol::stack::push(L, enabled);
    return 1;
}

static int CCNodeRGBA_setCascadeOpacityEnabled(lua_State* L) {
    if (lua_gettop(L) != 2)
        return luaL_error(L, "Expected 2 arguments (self, bool)");
    cocos2d::CCNodeRGBA* obj = sol::stack::get<cocos2d::CCNodeRGBA*>(L, 1);
    if (!obj)
        return luaL_error(L, "Invalid object in setCascadeOpacityEnabled");
    if (!lua_isboolean(L, 2))
        return luaL_error(L, "Expected boolean for setCascadeOpacityEnabled");
    bool enabled = lua_toboolean(L, 2) != 0;
    obj->setCascadeOpacityEnabled(enabled);
    return 0;
}

static int CCNodeRGBA__call(lua_State* L) {
    // Cast from CCObject* to CCNodeRGBA*
    if (lua_gettop(L) != 1)
        return luaL_error(L, "__call expected 1 argument");
    cocos2d::CCObject* ptr = sol::stack::get<cocos2d::CCObject*>(L, 1);
    cocos2d::CCNodeRGBA* node = dynamic_cast<cocos2d::CCNodeRGBA*>(ptr);
    if (!node)
        return luaL_error(L, "Pointer is not CCNodeRGBA*");
    sol::stack::push(L, node);
    return 1;
}


void register_CCNode(sol::state&);
void register_ccColor3B(sol::state&);

void register_CCNodeRGBA(sol::state& lua) {
    register_ccColor3B(lua);
    register_CCNode(lua);
    auto t = lua.new_usertype<cocos2d::CCNodeRGBA>(
        "CCNodeRGBA", sol::no_constructor,
        sol::base_classes, sol::base_list<cocos2d::CCNode, cocos2d::CCRGBAProtocol>()
    );
    t["getColor"] = &CCNodeRGBA_getColor;
    t["setColor"] = &CCNodeRGBA_setColor;
    t["getOpacity"] = &CCNodeRGBA_getOpacity;
    t["setOpacity"] = &CCNodeRGBA_setOpacity;
    t["isCascadeColorEnabled"] = &CCNodeRGBA_isCascadeColorEnabled;
    t["setCascadeColorEnabled"] = &CCNodeRGBA_setCascadeColorEnabled;
    t["isCascadeOpacityEnabled"] = &CCNodeRGBA_isCascadeOpacityEnabled;
    t["setCascadeOpacityEnabled"] = &CCNodeRGBA_setCascadeOpacityEnabled;

    t[sol::metatable_key]["__call"] = &CCNodeRGBA__call;
}
