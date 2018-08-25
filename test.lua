local sStr1 = ...
package.path = package.path..";./proto_lua/?.lua;./protobuf_lua/?.lua"
require "pb"
require "test_pb"

local stProto1 = test_pb.SSInt64Test()
stProto1:ParseFromString(sStr1)
print("------------------------------")
print(stProto1)
print("------------------------------")
local sStr2 = stProto1:SerializeToString()
local stProto2 = test_pb.SSInt64Test()
stProto2:ParseFromString(sStr2)
print(stProto2)