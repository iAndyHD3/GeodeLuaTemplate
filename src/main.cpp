#include "Geode/binding/CCMenuItemSpriteExtra.hpp"
#include "Geode/binding/MenuLayer.hpp"
#include "Geode/cocos/sprite_nodes/CCSprite.h"
#include <Geode/Geode.hpp>
#define SOL_ALL_SAFETIES_ON 1
#define SOL_NO_EXCEPTIONS 1
#include <sol/forward.hpp>
#include <sol/raii.hpp>
#include <sol/sol.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <sol/stack_core.hpp>
#include <sol/state.hpp>
#include <sol/types.hpp>

using namespace geode::prelude;
using namespace cocos2d;


sol::table getGeodeTable(sol::state& lua)
{
    sol::table geode = lua.create_table_with(
        "log", [](const std::string& str){
            geode::log::info("LUA: {}", str);
        }
    );

    return geode;
}


using namespace cocos2d;

// CCSprite:setPositionX(x)
int CCSprite_setPositionX(lua_State* L) {
    if (lua_gettop(L) < 2)
        return luaL_error(L, "CCSprite:setPositionX expects 2 arguments (self, x)");

    if (!sol::stack::check<CCSprite*>(L, 1))
        return luaL_error(L, "Expected CCSprite* as first argument");

    if (!sol::stack::check<float>(L, 2))
        return luaL_error(L, "Expected number as second argument");

    auto self = sol::stack::get<CCSprite*>(L, 1);
    if (!self)
        return luaL_error(L, "Null CCSprite* in setPositionX");

    float x = sol::stack::get<float>(L, 2);
    self->setPositionX(x);
    return 0;
}

int CCSprite_getPositionX(lua_State* L) {
    if (lua_gettop(L) < 1 || !sol::stack::check<CCSprite*>(L, 1))
        return luaL_error(L, "Expected CCSprite* as first argument");

    auto self = sol::stack::get<CCSprite*>(L, 1);
    if (!self)
        return luaL_error(L, "Null CCSprite* in getPositionX");

    sol::stack::push(L, self->getPositionX());
    return 1;
}

int CCSprite_getPositionY(lua_State* L) {
    if (lua_gettop(L) < 1 || !sol::stack::check<CCSprite*>(L, 1))
        return luaL_error(L, "Expected CCSprite* as first argument");

    auto self = sol::stack::get<CCSprite*>(L, 1);
    if (!self)
        return luaL_error(L, "Null CCSprite* in getPositionY");

    sol::stack::push(L, self->getPositionY());
    return 1;
}

int CCSprite_setPositionY(lua_State* L) {
    if (lua_gettop(L) < 2)
        return luaL_error(L, "CCSprite:setPositionY expects 2 arguments (self, y)");

    if (!sol::stack::check<CCSprite*>(L, 1))
        return luaL_error(L, "Expected CCSprite* as first argument");

    if (!sol::stack::check<float>(L, 2))
        return luaL_error(L, "Expected number as second argument");

    auto self = sol::stack::get<CCSprite*>(L, 1);
    if (!self)
        return luaL_error(L, "Null CCSprite* in setPositionY");

    float y = sol::stack::get<float>(L, 2);
    self->setPositionY(y);
    return 0;
}

int CCSprite_create(lua_State* L) {
    if (lua_gettop(L) < 1 || !sol::stack::check<const char*>(L, 1))
        return luaL_error(L, "CCSprite.create expects a string (sprite frame name)");

    const char* name = sol::stack::get<const char*>(L, 1);
    CCSprite* sprite = CCSprite::createWithSpriteFrameName(name);
    if (!sprite)
        return luaL_error(L, "CCSprite::createWithSpriteFrameName returned null");

    sol::stack::push(L, sprite);
    return 1;
}

int CCSprite_call(lua_State* L) {
    geode::log::info("HELLO WORLD!!!");
    if (lua_gettop(L) < 1)
        return luaL_error(L, "Expected 1 argument for cast function");

    sol::object obj = sol::stack::get<sol::object>(L, 1);
    if (!obj.is<CCSprite*>()) {
        return luaL_error(L, "Expected CCSprite*");
    }
    CCSprite* sprite = obj.as<CCSprite*>();

    sol::stack::push<CCSprite*>(L, sprite);
    return 1;
}




void register_CCSprite(sol::state& lua)
{
    auto t = lua.new_usertype<CCSprite>("CCSprite", sol::no_constructor);
    t["setPositionX"] = &CCSprite_setPositionX;
    t["getPositionX"] = &CCSprite_getPositionX;
    t["getPositionY"] = &CCSprite_getPositionY;
    t["setPositionY"] = &CCSprite_setPositionY;
    t["create"] =       &CCSprite_create;
    t["from"] = &CCSprite_call;
}



sol::optional<sol::function> findHook(sol::state& lua, const std::string& className, const std::string& functionName)
{
    auto modifyTable = lua.get<sol::table>("modify");

    sol::optional luaclass = modifyTable.get<sol::table>(className);
    if(!luaclass || luaclass->get_type() != sol::type::table) return {};

    sol::optional func = (*luaclass).get<sol::function>(functionName);
    return func;
}


inline void my_panic(sol::optional<std::string> maybe_msg) {
	geode::log::error("Lua is in a panic state and will now abort() the application");
	if (maybe_msg) {
		const std::string& msg = maybe_msg.value();
		geode::log::error("LUA ERROR: {}", msg);
	}
}


void register_CCNodeRGBA(sol::state&);

sol::optional<sol::state> createLuaState()
{
    sol::state lua(sol::c_call<decltype(&my_panic), &my_panic>);
    lua.open_libraries(sol::lib::base, sol::lib::string);
    lua["geode"] = getGeodeTable(lua);

    //ofcourse this is temporal, this would need to be generated from a pre-build step
    register_CCSprite(lua);
    register_CCNodeRGBA(lua);

    auto menu = lua.new_usertype<MenuLayer>("MenuLayer",
        sol::no_constructor,
        "onAchievements", &MenuLayer::onAchievements,
        "onNewgrounds", &MenuLayer::onNewgrounds,
        "addChild", sol::resolve<void(CCNode*)>(&MenuLayer::addChild)
    );


    auto modifyTable = lua.create_named_table("modify");


    lua.set_function("include", [&](const std::string& className){
        geode::log::info("INCLUDE: {}", className);
        lua["modify"][className] = lua.create_table();
    });

    sol::load_result script = lua.load_file((std::filesystem::path(MOD_ROOT) / "test.lua").string());
    if (!script.valid()) {
        sol::error err = script;
        geode::log::error("Failed to load script: {}", err.what());
        return {};
    }

    auto res = script();
    if(!res.valid()) {
        geode::log::error("error somewhere");
        return {};
    }




    return lua;
}



class $modify(MyHook, MenuLayer) {
    void onNewgrounds(CCObject* sender) {
        auto luaOpt = createLuaState();
        if(!luaOpt) {
            geode::log::error("Something went wrong initializing lua");
            return;
        }
        auto lua = std::move(*luaOpt);

        auto func = findHook(lua, "MenuLayer", "onNewgrounds");
        geode::log::info("result: {}", func.has_value());
        if(!func) return MenuLayer::onNewgrounds(sender);
        //}


        MenuLayer* self = static_cast<MenuLayer*>(this);
        geode::log::info("sender: {}", sender);

        sol::protected_function_result result = func.value()(self, sender);

        if (!result.valid()) {
            sol::error err = result;
            geode::log::info("Script error: {}", err.what());
            return;
        }
    }
};



