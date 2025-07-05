#include <cocos2d.h>
#include <sol/inheritance.hpp>
#include <sol/sol.hpp>
#include <sol/types.hpp>
#include <Geode/Geode.hpp>

using namespace cocos2d;


//DEPENDS:CCPoint
//DEPENDS:CCSize
//DEPENDS:CCRect
//DEPENDS:CCArray

int CCNode_create(lua_State* L) {
    CCNode* node = CCNode::create();
    sol::stack::push(L, node);
    return 1;
}

int CCNode_description(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:description");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->description());
    return 1;
}

int CCNode_setZOrder(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setZOrder");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    int zOrder = sol::stack::get<int>(L, 2);
    node->setZOrder(zOrder);
    return 0;
}

int CCNode_getZOrder(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getZOrder");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getZOrder());
    return 1;
}

int CCNode_setVertexZ(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setVertexZ");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float vertexZ = sol::stack::get<float>(L, 2);
    node->setVertexZ(vertexZ);
    return 0;
}

int CCNode_getVertexZ(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getVertexZ");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getVertexZ());
    return 1;
}

int CCNode_setScaleX(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setScaleX");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float scaleX = sol::stack::get<float>(L, 2);
    node->setScaleX(scaleX);
    return 0;
}

int CCNode_getScaleX(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getScaleX");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getScaleX());
    return 1;
}

int CCNode_setScaleY(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setScaleY");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float scaleY = sol::stack::get<float>(L, 2);
    node->setScaleY(scaleY);
    return 0;
}

int CCNode_getScaleY(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getScaleY");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getScaleY());
    return 1;
}

int CCNode_setScale(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 2 || argc > 3) {
        return luaL_error(L, "Invalid argument count for CCNode:setScale");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    if (argc == 2) {
        float scale = sol::stack::get<float>(L, 2);
        node->setScale(scale);
    } else {
        float scaleX = sol::stack::get<float>(L, 2);
        float scaleY = sol::stack::get<float>(L, 3);
        node->setScale(scaleX, scaleY);
    }
    return 0;
}

int CCNode_getScale(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getScale");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getScale());
    return 1;
}

int CCNode_setPosition(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 2 || argc > 3) {
        return luaL_error(L, "Invalid argument count for CCNode:setPosition");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    if (argc == 2) {
        CCPoint point = sol::stack::get<CCPoint>(L, 2);
        node->setPosition(point);
    } else {
        float x = sol::stack::get<float>(L, 2);
        float y = sol::stack::get<float>(L, 3);
        node->setPosition(x, y);
    }
    return 0;
}

int CCNode_getPosition(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getPosition");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCPoint pos = node->getPosition();
    sol::stack::push(L, pos);
    return 1;
}

int CCNode_setPositionX(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setPositionX");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float x = sol::stack::get<float>(L, 2);
    node->setPositionX(x);
    return 0;
}

int CCNode_getPositionX(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getPositionX");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getPositionX());
    return 1;
}

int CCNode_setPositionY(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setPositionY");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float y = sol::stack::get<float>(L, 2);
    node->setPositionY(y);
    return 0;
}

int CCNode_getPositionY(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getPositionY");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getPositionY());
    return 1;
}

int CCNode_setSkewX(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setSkewX");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float skewX = sol::stack::get<float>(L, 2);
    node->setSkewX(skewX);
    return 0;
}

int CCNode_getSkewX(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getSkewX");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getSkewX());
    return 1;
}

int CCNode_setSkewY(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setSkewY");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float skewY = sol::stack::get<float>(L, 2);
    node->setSkewY(skewY);
    return 0;
}

int CCNode_getSkewY(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getSkewY");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getSkewY());
    return 1;
}

int CCNode_setAnchorPoint(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setAnchorPoint");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }


    auto point = sol::stack::get<CCPoint>(L, 2);
    node->setAnchorPoint(point);
    return 0;
}

int CCNode_getAnchorPoint(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getAnchorPoint");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCPoint anchor = node->getAnchorPoint();
    sol::stack::push(L, anchor);
    return 1;
}

int CCNode_getAnchorPointInPoints(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getAnchorPointInPoints");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCPoint anchor = node->getAnchorPointInPoints();
    sol::stack::push(L, anchor);
    return 1;
}

int CCNode_setContentSize(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setContentSize");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::table size = sol::stack::get<sol::table>(L, 2);
    if (!size.valid() || !size["width"].valid() || !size["height"].valid()) {
        return luaL_error(L, "Invalid CCSize for CCNode:setContentSize");
    }
    float width = size["width"];
    float height = size["height"];
    node->setContentSize(CCSize(width, height));
    return 0;
}

int CCNode_getContentSize(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getContentSize");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCSize size = node->getContentSize();
    sol::stack::push(L, size);
    return 1;
}

int CCNode_getScaledContentSize(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getScaledContentSize");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCSize size = node->getScaledContentSize();
    sol::stack::push(L, size);
    return 1;
}

int CCNode_setVisible(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setVisible");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    bool visible = sol::stack::get<bool>(L, 2);
    node->setVisible(visible);
    return 0;
}

int CCNode_isVisible(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:isVisible");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->isVisible());
    return 1;
}

int CCNode_setRotation(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setRotation");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float rotation = sol::stack::get<float>(L, 2);
    node->setRotation(rotation);
    return 0;
}

int CCNode_getRotation(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getRotation");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getRotation());
    return 1;
}

int CCNode_setRotationX(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setRotationX");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float rotationX = sol::stack::get<float>(L, 2);
    node->setRotationX(rotationX);
    return 0;
}

int CCNode_getRotationX(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getRotationX");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getRotationX());
    return 1;
}

int CCNode_setRotationY(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setRotationY");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float rotationY = sol::stack::get<float>(L, 2);
    node->setRotationY(rotationY);
    return 0;
}

int CCNode_getRotationY(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc !=1) {
        return luaL_error(L, "Invalid argument count for CCNode:getRotationY");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getRotationY());
    return 1;
}

int CCNode_setOrderOfArrival(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setOrderOfArrival");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    unsigned int order = sol::stack::get<unsigned int>(L, 2);
    node->setOrderOfArrival(order);
    return 0;
}

int CCNode_getOrderOfArrival(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getOrderOfArrival");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getOrderOfArrival());
    return 1;
}

int CCNode_ignoreAnchorPointForPosition(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:ignoreAnchorPointForPosition");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    bool ignore = sol::stack::get<bool>(L, 2);
    node->ignoreAnchorPointForPosition(ignore);
    return 0;
}

int CCNode_isIgnoreAnchorPointForPosition(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:isIgnoreAnchorPointForPosition");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->isIgnoreAnchorPointForPosition());
    return 1;
}

int CCNode_addChild(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 2 || argc > 4) {
        return luaL_error(L, "Invalid argument count for CCNode:addChild");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCNode* child = sol::stack::get<CCNode*>(L, 2);
    if (!child) {
        return luaL_error(L, "Invalid child CCNode pointer");
    }
    if (argc == 2) {
        node->addChild(child);
    } else if (argc == 3) {
        int zOrder = sol::stack::get<int>(L, 3);
        node->addChild(child, zOrder);
    } else {
        int zOrder = sol::stack::get<int>(L, 3);
        int tag = sol::stack::get<int>(L, 4);
        node->addChild(child, zOrder, tag);
    }
    return 0;
}

int CCNode_getChildByTag(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:getChildByTag");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    int tag = sol::stack::get<int>(L, 2);
    CCNode* child = node->getChildByTag(tag);
    sol::stack::push(L, child);
    return 1;
}

int CCNode_getChildren(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getChildren");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCArray* children = node->getChildren();
    sol::stack::push(L, children);
    return 1;
}

int CCNode_getChildrenCount(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getChildrenCount");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getChildrenCount());
    return 1;
}

int CCNode_setParent(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setParent");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCNode* parent = sol::stack::get<CCNode*>(L, 2);
    node->setParent(parent);
    return 0;
}

int CCNode_getParent(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getParent");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getParent());
    return 1;
}

int CCNode_removeFromParent(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:removeFromParent");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->removeFromParent();
    return 0;
}

int CCNode_removeFromParentAndCleanup(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:removeFromParentAndCleanup");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    bool cleanup = sol::stack::get<bool>(L, 2);
    node->removeFromParentAndCleanup(cleanup);
    return 0;
}

int CCNode_removeMeAndCleanup(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:removeMeAndCleanup");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->removeMeAndCleanup();
    return 0;
}

int CCNode_removeChild(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 2 || argc > 3) {
        return luaL_error(L, "Invalid argument count for CCNode:removeChild");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCNode* child = sol::stack::get<CCNode*>(L, 2);
    if (!child) {
        return luaL_error(L, "Invalid child CCNode pointer");
    }
    if (argc == 2) {
        node->removeChild(child);
    } else {
        bool cleanup = sol::stack::get<bool>(L, 3);
        node->removeChild(child, cleanup);
    }
    return 0;
}

int CCNode_removeChildByTag(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 2 || argc > 3) {
        return luaL_error(L, "Invalid argument count for CCNode:removeChildByTag");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    int tag = sol::stack::get<int>(L, 2);
    if (argc == 2) {
        node->removeChildByTag(tag);
    } else {
        bool cleanup = sol::stack::get<bool>(L, 3);
        node->removeChildByTag(tag, cleanup);
    }
    return 0;
}

int CCNode_removeAllChildren(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 1 || argc > 2) {
        return luaL_error(L, "Invalid argument count for CCNode:removeAllChildren");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    if (argc == 1) {
        node->removeAllChildren();
    } else {
        bool cleanup = sol::stack::get<bool>(L, 2);
        node->removeAllChildrenWithCleanup(cleanup);
    }
    return 0;
}

int CCNode_reorderChild(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Invalid argument count for CCNode:reorderChild");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCNode* child = sol::stack::get<CCNode*>(L, 2);
    if (!child) {
        return luaL_error(L, "Invalid child CCNode pointer");
    }
    int zOrder = sol::stack::get<int>(L, 3);
    node->reorderChild(child, zOrder);
    return 0;
}

int CCNode_sortAllChildren(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:sortAllChildren");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->sortAllChildren();
    return 0;
}

int CCNode_getGrid(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getGrid");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getGrid());
    return 1;
}

int CCNode_setGrid(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setGrid");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCGridBase* grid = sol::stack::get<CCGridBase*>(L, 2);
    node->setGrid(grid);
    return 0;
}

int CCNode_getUserData(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getUserData");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getUserData());
    return 1;
}

int CCNode_setUserData(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setUserData");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    void* userData = sol::stack::get<void*>(L, 2);
    node->setUserData(userData);
    return 0;
}

int CCNode_getUserObject(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 1 || argc > 2) {
        return luaL_error(L, "Invalid argument count for CCNode:getUserObject");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    if (argc == 1) {
        sol::stack::push(L, node->getUserObject());
    } else {
        std::string id = sol::stack::get<std::string>(L, 2);
        sol::stack::push(L, node->getUserObject(id));
    }
    return 1;
}

int CCNode_setUserObject(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 2 || argc > 3) {
        return luaL_error(L, "Invalid argument count for CCNode:setUserObject");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    if (argc == 2) {
        CCObject* obj = sol::stack::get<CCObject*>(L, 2);
        node->setUserObject(obj);
    } else {
        std::string id = sol::stack::get<std::string>(L, 2);
        CCObject* obj = sol::stack::get<CCObject*>(L, 3);
        node->setUserObject(id, obj);
    }
    return 0;
}

int CCNode_getID(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getID");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getID());
    return 1;
}

int CCNode_setID(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setID");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    std::string id = sol::stack::get<std::string>(L, 2);
    node->setID(id);
    return 0;
}

int CCNode_getChildByID(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:getChildByID");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    std::string id = sol::stack::get<std::string>(L, 2);
    sol::stack::push(L, node->getChildByID(id));
    return 1;
}

int CCNode_getChildByIDRecursive(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:getChildByIDRecursive");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    std::string id = sol::stack::get<std::string>(L, 2);
    sol::stack::push(L, node->getChildByIDRecursive(id));
    return 1;
}

int CCNode_querySelector(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:querySelector");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    std::string query = sol::stack::get<std::string>(L, 2);
    sol::stack::push(L, node->querySelector(query));
    return 1;
}

int CCNode_removeChildByID(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:removeChildByID");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    std::string id = sol::stack::get<std::string>(L, 2);
    node->removeChildByID(id);
    return 0;
}

int CCNode_insertBefore(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Invalid argument count for CCNode:insertBefore");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCNode* child = sol::stack::get<CCNode*>(L, 2);
    if (!child) {
        return luaL_error(L, "Invalid child CCNode pointer");
    }
    CCNode* before = sol::stack::get<CCNode*>(L, 3);
    node->insertBefore(child, before);
    return 0;
}

int CCNode_insertAfter(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Invalid argument count for CCNode:insertAfter");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCNode* child = sol::stack::get<CCNode*>(L, 2);
    if (!child) {
        return luaL_error(L, "Invalid child CCNode pointer");
    }
    CCNode* after = sol::stack::get<CCNode*>(L, 3);
    node->insertAfter(child, after);
    return 0;
}

int CCNode_hasAncestor(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:hasAncestor");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCNode* ancestor = sol::stack::get<CCNode*>(L, 2);
    sol::stack::push(L, node->hasAncestor(ancestor));
    return 1;
}

int CCNode_setLayout(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 2 || argc > 4) {
        return luaL_error(L, "Invalid argument count for CCNode:setLayout");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    geode::Layout* layout = sol::stack::get<geode::Layout*>(L, 2);
    if (!layout) {
        return luaL_error(L, "Invalid Layout pointer");
    }
    bool apply = argc >= 3 ? sol::stack::get<bool>(L, 3) : true;
    bool respectAnchor = argc == 4 ? sol::stack::get<bool>(L, 4) : true;
    node->setLayout(layout, apply, respectAnchor);
    return 0;
}

int CCNode_getLayout(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getLayout");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getLayout());
    return 1;
}

int CCNode_updateLayout(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 1 || argc > 2) {
        return luaL_error(L, "Invalid argument count for CCNode:updateLayout");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    bool updateChildOrder = argc == 2 ? sol::stack::get<bool>(L, 2) : true;
    node->updateLayout(updateChildOrder);
    return 0;
}

int CCNode_setLayoutOptions(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 2 || argc > 3) {
        return luaL_error(L, "Invalid argument count for CCNode:setLayoutOptions");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    geode::LayoutOptions* options = sol::stack::get<geode::LayoutOptions*>(L, 2);
    if (!options) {
        return luaL_error(L, "Invalid LayoutOptions pointer");
    }
    bool apply = argc == 3 ? sol::stack::get<bool>(L, 3) : true;
    node->setLayoutOptions(options, apply);
    return 0;
}

int CCNode_getLayoutOptions(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getLayoutOptions");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getLayoutOptions());
    return 1;
}
/*
int CCNode_addChildAtPosition(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 3 || argc > 6) {
        return luaL_error(L, "Invalid argument count for CCNode:addChildAtPosition");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCNode* child = sol::stack::get<CCNode*>(L, 2);
    if (!child) {
        return luaL_error(L, "Invalid child CCNode pointer");
    }
    geode::Anchor anchor = (geode::Anchor)sol::stack::get<int>(L, 3);
    CCPoint offset = CCPointZero;
    CCPoint nodeAnchor = CCPointZero;
    bool useAnchorLayout = true;
    if (argc >= 4) {
        sol::table offsetTable = sol::stack::get<sol::table>(L, 4);
        if (offsetTable.valid() && offsetTable["x"].valid() && offsetTable["y"].valid()) {
            offset.x = offsetTable["x"];
            offset.y = offsetTable["y"];
        }
    }
    if (argc >= 5) {
        sol::table nodeAnchorTable = sol::stack::get<sol::table>(L, 5);
        if (nodeAnchorTable.valid() && nodeAnchorTable["x"].valid() && nodeAnchorTable["y"].valid()) {
            nodeAnchor.x = nodeAnchorTable["x"];
            nodeAnchor.y = nodeAnchorTable["y"];
        }
    }
    if (argc == 6) {
        useAnchorLayout = sol::stack::get<bool>(L, 6);
    }
    if (argc <= 4) {
        node->addChildAtPosition(child, anchor, offset, useAnchorLayout);
    } else {
        node->addChildAtPosition(child, anchor, offset, nodeAnchor, useAnchorLayout);
    }
    return 0;
}

int CCNode_updateAnchoredPosition(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc < 2 || argc > 4) {
        return luaL_error(L, "Invalid argument count for CCNode:updateAnchoredPosition");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    geode::Anchor anchor = (geode::Anchor)sol::stack::get<int>(L, 2);
    CCPoint offset = CCPointZero;
    CCPoint nodeAnchor = CCPointZero;
    if (argc >= 3) {
        sol::table offsetTable = sol::stack::get<sol::table>(L, 3);
        if (offsetTable.valid() && offsetTable["x"].valid() && offsetTable["y"].valid()) {
            offset.x = offsetTable["x"];
            offset.y = offsetTable["y"];
        }
    }
    if (argc == 4) {
        sol::table nodeAnchorTable = sol::stack::get<sol::table>(L, 4);
        if (nodeAnchorTable.valid() && nodeAnchorTable["x"].valid() && nodeAnchorTable["y"].valid()) {
            nodeAnchor.x = nodeAnchorTable["x"];
            nodeAnchor.y = nodeAnchorTable["y"];
        }
    }
    if (argc == 3) {
        node->updateAnchoredPosition(anchor, offset);
    } else {
        node->updateAnchoredPosition(anchor, offset, nodeAnchor);
    }
    return 0;
}
*/

int CCNode_swapChildIndices(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Invalid argument count for CCNode:swapChildIndices");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCNode* first = sol::stack::get<CCNode*>(L, 2);
    if (!first) {
        return luaL_error(L, "Invalid first CCNode pointer");
    }
    CCNode* second = sol::stack::get<CCNode*>(L, 3);
    if (!second) {
        return luaL_error(L, "Invalid second CCNode pointer");
    }
    node->swapChildIndices(first, second);
    return 0;
}

int CCNode_setScaledContentSize(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setScaledContentSize");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::table size = sol::stack::get<sol::table>(L, 2);
    if (!size.valid() || !size["width"].valid() || !size["height"].valid()) {
        return luaL_error(L, "Invalid CCSize for CCNode:setScaledContentSize");
    }
    float width = size["width"];
    float height = size["height"];
    node->setScaledContentSize(CCSize(width, height));
    return 0;
}

int CCNode_setContentWidth(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setContentWidth");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float width = sol::stack::get<float>(L, 2);
    node->setContentWidth(width);
    return 0;
}

int CCNode_setContentHeight(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setContentHeight");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float height = sol::stack::get<float>(L, 2);
    node->setContentHeight(height);
    return 0;
}

int CCNode_getContentWidth(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getContentWidth");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getContentWidth());
    return 1;
}

int CCNode_getContentHeight(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getContentHeight");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getContentHeight());
    return 1;
}

int CCNode_getScaledContentWidth(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getScaledContentWidth");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getScaledContentWidth());
    return 1;
}

int CCNode_getScaledContentHeight(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getScaledContentHeight");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getScaledContentHeight());
    return 1;
}

int CCNode_getShaderProgram(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getShaderProgram");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getShaderProgram());
    return 1;
}

int CCNode_setShaderProgram(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setShaderProgram");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCGLProgram* program = sol::stack::get<CCGLProgram*>(L, 2);
    if (!program) {
        return luaL_error(L, "Invalid CCGLProgram pointer");
    }
    node->setShaderProgram(program);
    return 0;
}

int CCNode_getCamera(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getCamera");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getCamera());
    return 1;
}

int CCNode_isRunning(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:isRunning");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->isRunning());
    return 1;
}

int CCNode_registerScriptHandler(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:registerScriptHandler");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    int handler = sol::stack::get<int>(L, 2);
    node->registerScriptHandler(handler);
    return 0;
}

int CCNode_unregisterScriptHandler(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:unregisterScriptHandler");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->unregisterScriptHandler();
    return 0;
}

int CCNode_getScriptHandler(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getScriptHandler");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getScriptHandler());
    return 1;
}

int CCNode_scheduleUpdateWithPriorityLua(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 3) {
        return luaL_error(L, "Invalid argument count for CCNode:scheduleUpdateWithPriorityLua");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    int handler = sol::stack::get<int>(L, 2);
    int priority = sol::stack::get<int>(L, 3);
    node->scheduleUpdateWithPriorityLua(handler, priority);
    return 0;
}

int CCNode_cleanup(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:cleanup");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->cleanup();
    return 0;
}

int CCNode_draw(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:draw");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->draw();
    return 0;
}

int CCNode_visit(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:visit");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->visit();
    return 0;
}

int CCNode_boundingBox(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:boundingBox");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCRect rect = node->boundingBox();
    sol::stack::push(L, rect);
    return 1;
}

int CCNode_setActionManager(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setActionManager");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCActionManager* manager = sol::stack::get<CCActionManager*>(L, 2);
    if (!manager) {
        return luaL_error(L, "Invalid CCActionManager pointer");
    }
    node->setActionManager(manager);
    return 0;
}

int CCNode_getActionManager(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getActionManager");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getActionManager());
    return 1;
}

int CCNode_runAction(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:runAction");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCAction* action = sol::stack::get<CCAction*>(L, 2);
    if (!action) {
        return luaL_error(L, "Invalid CCAction pointer");
    }
    sol::stack::push(L, node->runAction(action));
    return 1;
}

int CCNode_stopAllActions(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:stopAllActions");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->stopAllActions();
    return 0;
}

int CCNode_stopAction(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:stopAction");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCAction* action = sol::stack::get<CCAction*>(L, 2);
    if (!action) {
        return luaL_error(L, "Invalid CCAction pointer");
    }
    node->stopAction(action);
    return 0;
}

int CCNode_stopActionByTag(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:stopActionByTag");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    int tag = sol::stack::get<int>(L, 2);
    node->stopActionByTag(tag);
    return 0;
}

int CCNode_getActionByTag(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:getActionByTag");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    int tag = sol::stack::get<int>(L, 2);
    sol::stack::push(L, node->getActionByTag(tag));
    return 1;
}

int CCNode_numberOfRunningActions(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:numberOfRunningActions");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->numberOfRunningActions());
    return 1;
}

int CCNode_setScheduler(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setScheduler");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCScheduler* scheduler = sol::stack::get<CCScheduler*>(L, 2);
    if (!scheduler) {
        return luaL_error(L, "Invalid CCScheduler pointer");
    }
    node->setScheduler(scheduler);
    return 0;
}

int CCNode_getScheduler(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getScheduler");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getScheduler());
    return 1;
}

int CCNode_scheduleUpdate(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:scheduleUpdate");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->scheduleUpdate();
    return 0;
}

int CCNode_scheduleUpdateWithPriority(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:scheduleUpdateWithPriority");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    int priority = sol::stack::get<int>(L, 2);
    node->scheduleUpdateWithPriority(priority);
    return 0;
}

int CCNode_unscheduleUpdate(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:unscheduleUpdate");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->unscheduleUpdate();
    return 0;
}

int CCNode_resumeSchedulerAndActions(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:resumeSchedulerAndActions");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->resumeSchedulerAndActions();
    return 0;
}

int CCNode_pauseSchedulerAndActions(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:pauseSchedulerAndActions");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->pauseSchedulerAndActions();
    return 0;
}

int CCNode_update(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:update");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    float delta = sol::stack::get<float>(L, 2);
    node->update(delta);
    return 0;
}

int CCNode_transform(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:transform");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->transform();
    return 0;
}

int CCNode_transformAncestors(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:transformAncestors");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->transformAncestors();
    return 0;
}

int CCNode_updateTransform(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:updateTransform");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    node->updateTransform();
    return 0;
}


int CCNode_convertToNodeSpace(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:convertToNodeSpace");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCPoint point = sol::stack::get<CCPoint>(L, 2);
    CCPoint resultPoint = node->convertToNodeSpace(point);
    sol::stack::push(L, resultPoint);
    return 1;
}

int CCNode_convertToWorldSpace(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:convertToWorldSpace");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }

    CCPoint point = sol::stack::get<CCPoint>(L, 2);
    CCPoint resultPoint = node->convertToWorldSpace(point);
    sol::stack::push(L, resultPoint);
    return 1;
}

int CCNode_convertToNodeSpaceAR(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:convertToNodeSpaceAR");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCPoint point = sol::stack::get<CCPoint>(L, 2);
    CCPoint resultPoint = node->convertToNodeSpaceAR(point);
    sol::stack::push(L, resultPoint);
    return 1;
}

int CCNode_convertToWorldSpaceAR(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:convertToWorldSpaceAR");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCPoint point = sol::stack::get<CCPoint>(L, 2);
    CCPoint resultPoint = node->convertToWorldSpaceAR(point);
    sol::stack::push(L, resultPoint);
    return 1;
}

int CCNode_convertTouchToNodeSpace(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:convertTouchToNodeSpace");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCTouch* touch = sol::stack::get<CCTouch*>(L, 2);
    if (!touch) {
        return luaL_error(L, "Invalid CCTouch pointer");
    }
    CCPoint resultPoint = node->convertTouchToNodeSpace(touch);
    sol::stack::push(L, resultPoint);
    return 1;
}

int CCNode_convertTouchToNodeSpaceAR(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:convertTouchToNodeSpaceAR");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    CCTouch* touch = sol::stack::get<CCTouch*>(L, 2);
    if (!touch) {
        return luaL_error(L, "Invalid CCTouch pointer");
    }
    CCPoint resultPoint = node->convertTouchToNodeSpaceAR(touch);
    sol::stack::push(L, resultPoint);

    return 1;
}

int CCNode_getTag(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 1) {
        return luaL_error(L, "Invalid argument count for CCNode:getTag");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    sol::stack::push(L, node->getTag());
    return 1;
}

int CCNode_setTag(lua_State* L) {
    int argc = lua_gettop(L);
    if (argc != 2) {
        return luaL_error(L, "Invalid argument count for CCNode:setTag");
    }
    CCNode* node = sol::stack::get<CCNode*>(L, 1);
    if (!node) {
        return luaL_error(L, "Invalid CCNode pointer");
    }
    int tag = sol::stack::get<int>(L, 2);
    node->setTag(tag);
    return 0;
}

int CCNode_call(lua_State* L) {
    if (lua_gettop(L) < 1)
        return luaL_error(L, "Expected 1 argument for cast function");

    sol::object obj = sol::stack::get<sol::object>(L, 1);
    auto ptr = dynamic_cast<CCNode*>(obj.as<CCObject*>());
    if (!ptr) {
        return luaL_error(L, "Expected CCNode*");
    }

    sol::stack::push(L, ptr);
    return 1;
}



void register_CCObject(sol::state&);
void register_CCPoint(sol::state&);

void register_CCNode(sol::state& lua) {
    register_CCObject(lua);
    register_CCPoint(lua);
    auto ccnode = lua.new_usertype<CCNode>("CCNode", sol::base_classes, sol::base_list<CCObject>());

    ccnode["create"] = &CCNode_create;
    ccnode["description"] = &CCNode_description;
    ccnode["setZOrder"] = &CCNode_setZOrder;
    ccnode["getZOrder"] = &CCNode_getZOrder;
    ccnode["setVertexZ"] = &CCNode_setVertexZ;
    ccnode["getVertexZ"] = &CCNode_getVertexZ;
    ccnode["setScaleX"] = &CCNode_setScaleX;
    ccnode["getScaleX"] = &CCNode_getScaleX;
    ccnode["setScaleY"] = &CCNode_setScaleY;
    ccnode["getScaleY"] = &CCNode_getScaleY;
    ccnode["setScale"] = &CCNode_setScale;
    ccnode["getScale"] = &CCNode_getScale;
    ccnode["setPosition"] = &CCNode_setPosition;
    ccnode["getPosition"] = &CCNode_getPosition;
    ccnode["setPositionX"] = &CCNode_setPositionX;
    ccnode["getPositionX"] = &CCNode_getPositionX;
    ccnode["setPositionY"] = &CCNode_setPositionY;
    ccnode["getPositionY"] = &CCNode_getPositionY;
    ccnode["setSkewX"] = &CCNode_setSkewX;
    ccnode["getSkewX"] = &CCNode_getSkewX;
    ccnode["setSkewY"] = &CCNode_setSkewY;
    ccnode["getSkewY"] = &CCNode_getSkewY;
    ccnode["setAnchorPoint"] = &CCNode_setAnchorPoint;
    ccnode["getAnchorPoint"] = &CCNode_getAnchorPoint;
    ccnode["getAnchorPointInPoints"] = &CCNode_getAnchorPointInPoints;
    ccnode["setContentSize"] = &CCNode_setContentSize;
    ccnode["getContentSize"] = &CCNode_getContentSize;
    ccnode["getScaledContentSize"] = &CCNode_getScaledContentSize;
    ccnode["setVisible"] = &CCNode_setVisible;
    ccnode["isVisible"] = &CCNode_isVisible;
    ccnode["setRotation"] = &CCNode_setRotation;
    ccnode["getRotation"] = &CCNode_getRotation;
    ccnode["setRotationX"] = &CCNode_setRotationX;
    ccnode["getRotationX"] = &CCNode_getRotationX;
    ccnode["setRotationY"] = &CCNode_setRotationY;
    ccnode["getRotationY"] = &CCNode_getRotationY;
    ccnode["setOrderOfArrival"] = &CCNode_setOrderOfArrival;
    ccnode["getOrderOfArrival"] = &CCNode_getOrderOfArrival;
    ccnode["ignoreAnchorPointForPosition"] = &CCNode_ignoreAnchorPointForPosition;
    ccnode["isIgnoreAnchorPointForPosition"] = &CCNode_isIgnoreAnchorPointForPosition;
    ccnode["addChild"] = &CCNode_addChild;
    ccnode["getChildByTag"] = &CCNode_getChildByTag;
    ccnode["getChildren"] = &CCNode_getChildren;
    ccnode["getChildrenCount"] = &CCNode_getChildrenCount;
    ccnode["setParent"] = &CCNode_setParent;
    ccnode["getParent"] = &CCNode_getParent;
    ccnode["removeFromParent"] = &CCNode_removeFromParent;
    ccnode["removeFromParentAndCleanup"] = &CCNode_removeFromParentAndCleanup;
    ccnode["removeMeAndCleanup"] = &CCNode_removeMeAndCleanup;
    ccnode["removeChild"] = &CCNode_removeChild;
    ccnode["removeChildByTag"] = &CCNode_removeChildByTag;
    ccnode["removeAllChildren"] = &CCNode_removeAllChildren;
    ccnode["reorderChild"] = &CCNode_reorderChild;
    ccnode["sortAllChildren"] = &CCNode_sortAllChildren;
    ccnode["getGrid"] = &CCNode_getGrid;
    ccnode["setGrid"] = &CCNode_setGrid;
    ccnode["getUserData"] = &CCNode_getUserData;
    ccnode["setUserData"] = &CCNode_setUserData;
    ccnode["getUserObject"] = &CCNode_getUserObject;
    ccnode["setUserObject"] = &CCNode_setUserObject;
    ccnode["getID"] = &CCNode_getID;
    ccnode["setID"] = &CCNode_setID;
    ccnode["getChildByID"] = &CCNode_getChildByID;
    ccnode["getChildByIDRecursive"] = &CCNode_getChildByIDRecursive;
    ccnode["querySelector"] = &CCNode_querySelector;
    ccnode["removeChildByID"] = &CCNode_removeChildByID;
    ccnode["insertBefore"] = &CCNode_insertBefore;
    ccnode["insertAfter"] = &CCNode_insertAfter;
    ccnode["hasAncestor"] = &CCNode_hasAncestor;
    ccnode["setLayout"] = &CCNode_setLayout;
    ccnode["getLayout"] = &CCNode_getLayout;
    ccnode["updateLayout"] = &CCNode_updateLayout;
    ccnode["setLayoutOptions"] = &CCNode_setLayoutOptions;
    ccnode["getLayoutOptions"] = &CCNode_getLayoutOptions;
    //ccnode["addChildAtPosition"] = &CCNode_addChildAtPosition;
    //ccnode["updateAnchoredPosition"] = &CCNode_updateAnchoredPosition;
    ccnode["swapChildIndices"] = &CCNode_swapChildIndices;
    ccnode["setScaledContentSize"] = &CCNode_setScaledContentSize;
    ccnode["setContentWidth"] = &CCNode_setContentWidth;
    ccnode["setContentHeight"] = &CCNode_setContentHeight;
    ccnode["getContentWidth"] = &CCNode_getContentWidth;
    ccnode["getContentHeight"] = &CCNode_getContentHeight;
    ccnode["getScaledContentWidth"] = &CCNode_getScaledContentWidth;
    ccnode["getScaledContentHeight"] = &CCNode_getScaledContentHeight;
    ccnode["getShaderProgram"] = &CCNode_getShaderProgram;
    ccnode["setShaderProgram"] = &CCNode_setShaderProgram;
    ccnode["getCamera"] = &CCNode_getCamera;
    ccnode["isRunning"] = &CCNode_isRunning;
    ccnode["registerScriptHandler"] = &CCNode_registerScriptHandler;
    ccnode["unregisterScriptHandler"] = &CCNode_unregisterScriptHandler;
    ccnode["getScriptHandler"] = &CCNode_getScriptHandler;
    ccnode["scheduleUpdateWithPriorityLua"] = &CCNode_scheduleUpdateWithPriorityLua;
    ccnode["cleanup"] = &CCNode_cleanup;
    ccnode["draw"] = &CCNode_draw;
    ccnode["visit"] = &CCNode_visit;
    ccnode["boundingBox"] = &CCNode_boundingBox;
    ccnode["setActionManager"] = &CCNode_setActionManager;
    ccnode["getActionManager"] = &CCNode_getActionManager;
    ccnode["runAction"] = &CCNode_runAction;
    ccnode["stopAllActions"] = &CCNode_stopAllActions;
    ccnode["stopAction"] = &CCNode_stopAction;
    ccnode["stopActionByTag"] = &CCNode_stopActionByTag;
    ccnode["getActionByTag"] = &CCNode_getActionByTag;
    ccnode["numberOfRunningActions"] = &CCNode_numberOfRunningActions;
    ccnode["setScheduler"] = &CCNode_setScheduler;
    ccnode["getScheduler"] = &CCNode_getScheduler;
    ccnode["scheduleUpdate"] = &CCNode_scheduleUpdate;
    ccnode["scheduleUpdateWithPriority"] = &CCNode_scheduleUpdateWithPriority;
    ccnode["unscheduleUpdate"] = &CCNode_unscheduleUpdate;
    ccnode["resumeSchedulerAndActions"] = &CCNode_resumeSchedulerAndActions;
    ccnode["pauseSchedulerAndActions"] = &CCNode_pauseSchedulerAndActions;
    ccnode["update"] = &CCNode_update;
    ccnode["transform"] = &CCNode_transform;
    ccnode["transformAncestors"] = &CCNode_transformAncestors;
    ccnode["updateTransform"] = &CCNode_updateTransform;
    ccnode["convertToNodeSpace"] = &CCNode_convertToNodeSpace;
    ccnode["convertToWorldSpace"] = &CCNode_convertToWorldSpace;
    ccnode["convertToNodeSpaceAR"] = &CCNode_convertToNodeSpaceAR;
    ccnode["convertToWorldSpaceAR"] = &CCNode_convertToWorldSpaceAR;
    ccnode["convertTouchToNodeSpace"] = &CCNode_convertTouchToNodeSpace;
    ccnode["convertTouchToNodeSpaceAR"] = &CCNode_convertTouchToNodeSpaceAR;
    ccnode["getTag"] = &CCNode_getTag;
    ccnode["setTag"] = &CCNode_setTag;

    ccnode["from"] = &CCNode_call;
}