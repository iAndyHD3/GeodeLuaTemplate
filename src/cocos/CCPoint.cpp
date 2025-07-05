#include <cocos2d.h>
#include <sol/sol.hpp>

using namespace cocos2d;

int CCPoint_setPoint(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Expected 3 arguments, got %d", argc);
    }
    if (!lua_isnumber(L, 2) || !lua_isnumber(L, 3)) {
        return luaL_error(L, "Expected numbers for x and y");
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    float x = sol::stack::get<float>(L, 2);
    float y = sol::stack::get<float>(L, 3);
    self->setPoint(x, y);
    return 0;
}

int CCPoint_equals(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint target = sol::stack::get<CCPoint>(L, 2);
    bool result = self->equals(target);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_fuzzyEquals(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Expected 3 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint target = sol::stack::get<CCPoint>(L, 2);
    if (!lua_isnumber(L, 3)) {
        return luaL_error(L, "Expected number for variance");
    }
    float var = sol::stack::get<float>(L, 3);
    bool result = self->fuzzyEquals(target, var);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_getLength(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    float result = self->getLength();
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_getLengthSq(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    float result = self->getLengthSq();
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_getDistanceSq(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint other = sol::stack::get<CCPoint>(L, 2);
    float result = self->getDistanceSq(other);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_getDistance(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint other = sol::stack::get<CCPoint>(L, 2);
    float result = self->getDistance(other);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_getAngle(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc == 1) {
        CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
        float result = self->getAngle();
        sol::stack::push(L, result);
        return 1;
    } else if (argc == 2) {
        CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
        CCPoint other = sol::stack::get<CCPoint>(L, 2);
        float result = self->getAngle(other);
        sol::stack::push(L, result);
        return 1;
    }
    return luaL_error(L, "Expected 1 or 2 arguments, got %d", argc);
}

int CCPoint_dot(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint other = sol::stack::get<CCPoint>(L, 2);
    float result = self->dot(other);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_cross(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint other = sol::stack::get<CCPoint>(L, 2);
    float result = self->cross(other);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_getPerp(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint result = self->getPerp();
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_getRPerp(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint result = self->getRPerp();
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_project(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint other = sol::stack::get<CCPoint>(L, 2);
    CCPoint result = self->project(other);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_rotate(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint other = sol::stack::get<CCPoint>(L, 2);
    CCPoint result = self->rotate(other);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_unrotate(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint other = sol::stack::get<CCPoint>(L, 2);
    CCPoint result = self->unrotate(other);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_normalize(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint result = self->normalize();
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_lerp(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Expected 3 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint other = sol::stack::get<CCPoint>(L, 2);
    if (!lua_isnumber(L, 3)) {
        return luaL_error(L, "Expected number for alpha");
    }
    float alpha = sol::stack::get<float>(L, 3);
    CCPoint result = self->lerp(other, alpha);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_rotateByAngle(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Expected 3 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    CCPoint pivot = sol::stack::get<CCPoint>(L, 2);
    if (!lua_isnumber(L, 3)) {
        return luaL_error(L, "Expected number for angle");
    }
    float angle = sol::stack::get<float>(L, 3);
    CCPoint result = self->rotateByAngle(pivot, angle);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_forAngle(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument, got %d", argc);
    }
    if (!lua_isnumber(L, 1)) {
        return luaL_error(L, "Expected number for angle");
    }
    float angle = sol::stack::get<float>(L, 1);
    CCPoint result = CCPoint::forAngle(angle);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_add(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Expected 3 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    if (!lua_isnumber(L, 2) || !lua_isnumber(L, 3)) {
        return luaL_error(L, "Expected numbers for index and value");
    }
    int idx = sol::stack::get<int>(L, 2);
    float val = sol::stack::get<float>(L, 3);
    self->add(idx, val);
    return 0;
}

int CCPoint_at(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Expected 2 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    if (!lua_isnumber(L, 2)) {
        return luaL_error(L, "Expected number for index");
    }
    int idx = sol::stack::get<int>(L, 2);
    float result = self->at(idx);
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_isZero(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    bool result = self->isZero();
    sol::stack::push(L, result);
    return 1;
}

int CCPoint_set(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Expected 3 arguments, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    if (!lua_isnumber(L, 2) || !lua_isnumber(L, 3)) {
        return luaL_error(L, "Expected numbers for index and value");
    }
    int idx = sol::stack::get<int>(L, 2);
    float val = sol::stack::get<float>(L, 3);
    self->set(idx, val);
    return 0;
}

int CCPoint_swap(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Expected 1 argument, got %d", argc);
    }
    CCPoint* self = sol::stack::get<CCPoint*>(L, 1);
    self->swap();
    return 0;
}

void register_CCPoint(sol::state& lua) {
    auto t = lua.new_usertype<CCPoint>("CCPoint",
        sol::constructors<
            CCPoint(),
            CCPoint(float, float),
            CCPoint(const CCPoint&),
            CCPoint(const CCSize&)
        >());

    t["x"] = &CCPoint::x;
    t["y"] = &CCPoint::y;
    t["setPoint"] = &CCPoint_setPoint;
    t["equals"] = &CCPoint_equals;
    t["fuzzyEquals"] = &CCPoint_fuzzyEquals;
    t["getLength"] = &CCPoint_getLength;
    t["getLengthSq"] = &CCPoint_getLengthSq;
    t["getDistanceSq"] = &CCPoint_getDistanceSq;
    t["getDistance"] = &CCPoint_getDistance;
    t["getAngle"] = sol::overload(
        [](CCPoint* self) { return self->getAngle(); },
        [](CCPoint* self, const CCPoint& other) { return self->getAngle(other); }
    );
    t["dot"] = &CCPoint_dot;
    t["cross"] = &CCPoint_cross;
    t["getPerp"] = &CCPoint_getPerp;
    t["getRPerp"] = &CCPoint_getRPerp;
    t["project"] = &CCPoint_project;
    t["rotate"] = &CCPoint_rotate;
    t["unrotate"] = &CCPoint_unrotate;
    t["normalize"] = &CCPoint_normalize;
    t["lerp"] = &CCPoint_lerp;
    t["rotateByAngle"] = &CCPoint_rotateByAngle;
    t["forAngle"] = &CCPoint_forAngle;
    t["add"] = &CCPoint_add;
    t["at"] = &CCPoint_at;
    t["isZero"] = &CCPoint_isZero;
    t["set"] = &CCPoint_set;
    t["swap"] = &CCPoint_swap;

}