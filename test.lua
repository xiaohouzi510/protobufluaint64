local sStr = ...
package.path = package.path..";./proto_lua/?.lua;./protobuf_lua/?.lua"
require "pb"
require "test_pb"

local stProto = test_pb.SSInt64Test()
stProto:ParseFromString(sStr)
print(tostring(stProto))