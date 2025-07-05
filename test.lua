geode.log("start")

include("MenuLayer")

function modify.MenuLayer:onNewgrounds(p1)
    local spr = CCNode.from(p1)
    local pos = spr:getPosition()
    pos.y = pos.y + 10
    pos.x = pos.x + 10
    spr:setPosition(pos)
end


--use this to debug meta tables




-- function dumpvar(data)
--     local tablecache = {}
--     local buffer = ""
--     local padder = "    "

--     local function _dumpvar(d, depth, path)
--         local t = type(d)
--         local str = tostring(d)

--         if t == "table" then
--             if tablecache[d] then
--                 buffer = buffer .. string.rep(padder, depth) .. "<" .. str .. "> (already seen)\n"
--                 return
--             end
--             tablecache[d] = true
--             buffer = buffer .. string.rep(padder, depth) .. "(" .. str .. ") {\n"

--             -- Dump table contents
--             for k, v in pairs(d) do
--                 buffer = buffer .. string.rep(padder, depth + 1) .. "[" .. tostring(k) .. "] => "
--                 _dumpvar(v, depth + 1, path .. "." .. tostring(k))
--             end

--             -- Dump metatable if present
--             local mt = getmetatable(d)
--             if mt then
--                 buffer = buffer .. string.rep(padder, depth + 1) .. "[metatable] =>\n"
--                 _dumpvar(mt, depth + 2, path .. ".__metatable")
--             end

--             buffer = buffer .. string.rep(padder, depth) .. "}\n"
--         elseif t == "userdata" then
--             buffer = buffer .. string.rep(padder, depth) .. "(userdata) \"" .. str .. "\"\n"
--             local mt = getmetatable(d)
--             if mt then
--                 buffer = buffer .. string.rep(padder, depth + 1) .. "[metatable] =>\n"
--                 _dumpvar(mt, depth + 2, path .. ".__metatable")
--             end
--         elseif t == "function" then
--             buffer = buffer .. string.rep(padder, depth) .. "(function) \"" .. str .. "\"\n"
--         elseif t == "string" then
--             buffer = buffer .. string.rep(padder, depth) .. "(string) \"" .. str .. "\"\n"
--         elseif t == "number" then
--             buffer = buffer .. string.rep(padder, depth) .. "(number) " .. str .. "\n"
--         elseif t == "boolean" then
--             buffer = buffer .. string.rep(padder, depth) .. "(boolean) " .. tostring(d) .. "\n"
--         else
--             buffer = buffer .. string.rep(padder, depth) .. "(" .. t .. ") \"" .. str .. "\"\n"
--         end
--     end

--     _dumpvar(data, 0, "root")
--     return buffer
-- end
