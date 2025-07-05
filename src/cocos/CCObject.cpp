#include "Geode/cocos/cocoa/CCObject.h"
#include <cocos2d.h>
#include <sol/forward.hpp>
#include <sol/sol.hpp>
using namespace cocos2d;

#include <cocos2d.h>
#include <sol/sol.hpp>
using namespace cocos2d;

int CCObject_release(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument for CCObject_release, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    self->release();
    return 0;
}

int CCObject_retain(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument for CCObject_retain, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    self->retain();
    sol::stack::push(L, self);
    return 1;
}

int CCObject_autorelease(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument for CCObject_autorelease, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    CCObject* result = self->autorelease();
    sol::stack::push(L, result);
    return 1;
}

int CCObject_copy(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument for CCObject_copy, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    CCObject* result = self->copy();
    sol::stack::push(L, result);
    return 1;
}

int CCObject_isSingleReference(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument for CCObject_isSingleReference, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    bool result = self->isSingleReference();
    sol::stack::push(L, result);
    return 1;
}

int CCObject_retainCount(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument for CCObject_retainCount, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    unsigned int result = self->retainCount();
    sol::stack::push(L, result);
    return 1;
}

int CCObject_isEqual(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments for CCObject_isEqual, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer for self");
    }
    const CCObject* other = sol::stack::get<const CCObject*>(L, 2);
    if (!other) {
        return luaL_error(L, "Invalid CCObject pointer for other");
    }
    bool result = self->isEqual(other);
    sol::stack::push(L, result);
    return 1;
}

int CCObject_acceptVisitor(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments for CCObject_acceptVisitor, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    CCDataVisitor* visitor = sol::stack::get<CCDataVisitor*>(L, 2);
    if (!visitor) {
        return luaL_error(L, "Invalid CCDataVisitor pointer");
    }
    self->acceptVisitor(*visitor);
    return 0;
}

int CCObject_update(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments for CCObject_update, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    float dt = sol::stack::get<float>(L, 2);
    self->update(dt);
    return 0;
}

int CCObject_encodeWithCoder(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments for CCObject_encodeWithCoder, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    DS_Dictionary* coder = sol::stack::get<DS_Dictionary*>(L, 2);
    if (!coder) {
        return luaL_error(L, "Invalid DS_Dictionary pointer");
    }
    self->encodeWithCoder(coder);
    return 0;
}

int CCObject_createWithCoder(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument for CCObject_createWithCoder, got %d", argc);
    }
    DS_Dictionary* coder = sol::stack::get<DS_Dictionary*>(L, 1);
    if (!coder) {
        return luaL_error(L, "Invalid DS_Dictionary pointer");
    }
    CCObject* result = CCObject::createWithCoder(coder);
    sol::stack::push(L, result);
    return 1;
}

int CCObject_canEncode(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument for CCObject_canEncode, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    bool result = self->canEncode();
    sol::stack::push(L, result);
    return 1;
}

// int CCObject_getObjType(lua_State* L) {
//     int argc = lua_gettop(L);
//     if (argc != 1) {
//         return luaL_error(L, "Expected 1 argument for CCObject_getObjType, got %d", argc);
//     }
//     CCObject* self = sol::stack::get<CCObject*>(L, 1);
//     if (!self) {
//         return luaL_error(L, "Invalid CCObject pointer");
//     }
//     CCObjectType result = self->getObjType();
//     sol::stack::push(L, static_cast<int>(result));
//     return 1;
// }

int CCObject_getTag(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument for CCObject_getTag, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    int result = self->getTag();
    sol::stack::push(L, result);
    return 1;
}

int CCObject_setTag(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments for CCObject_setTag, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    int tag = sol::stack::get<int>(L, 2);
    self->setTag(tag);
    return 0;
}

int CCObject_setObjType(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments for CCObject_setObjType, got %d", argc);
    }
    CCObject* self = sol::stack::get<CCObject*>(L, 1);
    if (!self) {
        return luaL_error(L, "Invalid CCObject pointer");
    }
    int type = sol::stack::get<int>(L, 2);
    self->setObjType(static_cast<CCObjectType>(type));
    return 0;
}

int CCObject__call(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument for CCObject __call, got %d", argc);
    }
    CCObject* ptr = sol::stack::get<CCObject*>(L, 1);
    auto casted_ptr = dynamic_cast<CCObject*>(ptr);
    if (!casted_ptr) {
        return luaL_error(L, "Pointer is not CCObject*");
    }
    sol::stack::push(L, casted_ptr);
    return 1;
}

void register_CCObject(sol::state& lua) {
    std::optional usertype = lua.get<sol::usertype<CCObject>>("CCObject");
    geode::log::info("{} CCObject", usertype.has_value() ? "Already registered" : "registering first time");
    if(usertype.has_value()) {
        return;
    }

    auto t = lua.new_usertype<CCObject>("CCObject", sol::no_constructor);
    t["release"] = &CCObject_release;
    t["retain"] = &CCObject_retain;
    t["autorelease"] = &CCObject_autorelease;
    t["copy"] = &CCObject_copy;
    t["isSingleReference"] = &CCObject_isSingleReference;
    t["retainCount"] = &CCObject_retainCount;
    t["isEqual"] = &CCObject_isEqual;
    t["acceptVisitor"] = &CCObject_acceptVisitor;
    t["update"] = &CCObject_update;
    t["encodeWithCoder"] = &CCObject_encodeWithCoder;
    t["createWithCoder"] = &CCObject_createWithCoder;
    t["canEncode"] = &CCObject_canEncode;
    // t["getObjType"] = &CCObject_getObjType;
    t["getTag"] = &CCObject_getTag;
    t["setTag"] = &CCObject_setTag;
    t["setObjType"] = &CCObject_setObjType;
    t[sol::metatable_key]["__call"] = &CCObject__call;
}