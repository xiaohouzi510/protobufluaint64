local sStr1 = ...
package.path = package.path..";./proto_lua/?.lua;./protobuf_lua/?.lua"
require "pb"
require "test_pb"

local stProto1 = test_pb.SSInt64Test()
stProto1:ParseFromString(sStr1)
print(tostring(stProto1))

local stProto2 = test_pb.SSInt64Test()
local sStr2 = stProto1:SerializeToString()
stProto2:ParseFromString(sStr1)
print(tostring(stProto2))