local sStr1 = ...
package.path = package.path..";./proto_lua/?.lua;./protobuf_lua/?.lua"
require "pb"
require "test_pb"

local stProto1 = test_pb.SSInt64Test()
stProto1:ParseFromString(sStr1)
print("------------------------------2")
print(stProto1)
print("------------------------------3")
local sStr2 = stProto1:SerializeToString()
local stProto2 = test_pb.SSInt64Test()
stProto2:ParseFromString(sStr2)
print(stProto2)
print("------------------------------4")
local stProto3 = test_pb.SSInt64Test()
stProto3.TeamID = int64.new("9223372036854775807")
stProto3.TeamIDs:append(int64.new("-9223372036854775807"))
stProto3.TeamIDs:append(int64.new("-4611686018427387903"))
stProto3.TeamIDs:append(int64.new("4611686018427387903"))
print(stProto3)