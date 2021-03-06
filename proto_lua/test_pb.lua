-- Generated By protoc-gen-lua Do not Edit
local protobuf = require "protobuf"
module('test_pb')


local TESTDATA = protobuf.Descriptor();
local TESTDATA_SELFID_FIELD = protobuf.FieldDescriptor();
local TESTDATA_OTHERID_FIELD = protobuf.FieldDescriptor();
local SSINT64TEST = protobuf.Descriptor();
local SSINT64TEST_PVPTYPE_FIELD = protobuf.FieldDescriptor();
local SSINT64TEST_HARDTYPE_FIELD = protobuf.FieldDescriptor();
local SSINT64TEST_TEAMID_FIELD = protobuf.FieldDescriptor();
local SSINT64TEST_TEAMIDS_FIELD = protobuf.FieldDescriptor();
local SSINT64TEST_ROLEID_FIELD = protobuf.FieldDescriptor();
local SSINT64TEST_ROLEIDS_FIELD = protobuf.FieldDescriptor();
local SSINT64TEST_DATAS_FIELD = protobuf.FieldDescriptor();

TESTDATA_SELFID_FIELD.name = "SelfID"
TESTDATA_SELFID_FIELD.full_name = ".TestData.SelfID"
TESTDATA_SELFID_FIELD.number = 1
TESTDATA_SELFID_FIELD.index = 0
TESTDATA_SELFID_FIELD.label = 1
TESTDATA_SELFID_FIELD.has_default_value = false
TESTDATA_SELFID_FIELD.default_value = 0
TESTDATA_SELFID_FIELD.type = 3
TESTDATA_SELFID_FIELD.cpp_type = 2

TESTDATA_OTHERID_FIELD.name = "OtherID"
TESTDATA_OTHERID_FIELD.full_name = ".TestData.OtherID"
TESTDATA_OTHERID_FIELD.number = 2
TESTDATA_OTHERID_FIELD.index = 1
TESTDATA_OTHERID_FIELD.label = 1
TESTDATA_OTHERID_FIELD.has_default_value = false
TESTDATA_OTHERID_FIELD.default_value = 0
TESTDATA_OTHERID_FIELD.type = 4
TESTDATA_OTHERID_FIELD.cpp_type = 4

TESTDATA.name = "TestData"
TESTDATA.full_name = ".TestData"
TESTDATA.nested_types = {}
TESTDATA.enum_types = {}
TESTDATA.fields = {TESTDATA_SELFID_FIELD, TESTDATA_OTHERID_FIELD}
TESTDATA.is_extendable = false
TESTDATA.extensions = {}
SSINT64TEST_PVPTYPE_FIELD.name = "PvpType"
SSINT64TEST_PVPTYPE_FIELD.full_name = ".SSInt64Test.PvpType"
SSINT64TEST_PVPTYPE_FIELD.number = 1
SSINT64TEST_PVPTYPE_FIELD.index = 0
SSINT64TEST_PVPTYPE_FIELD.label = 1
SSINT64TEST_PVPTYPE_FIELD.has_default_value = false
SSINT64TEST_PVPTYPE_FIELD.default_value = 0
SSINT64TEST_PVPTYPE_FIELD.type = 5
SSINT64TEST_PVPTYPE_FIELD.cpp_type = 1

SSINT64TEST_HARDTYPE_FIELD.name = "HardType"
SSINT64TEST_HARDTYPE_FIELD.full_name = ".SSInt64Test.HardType"
SSINT64TEST_HARDTYPE_FIELD.number = 2
SSINT64TEST_HARDTYPE_FIELD.index = 1
SSINT64TEST_HARDTYPE_FIELD.label = 1
SSINT64TEST_HARDTYPE_FIELD.has_default_value = false
SSINT64TEST_HARDTYPE_FIELD.default_value = 0
SSINT64TEST_HARDTYPE_FIELD.type = 5
SSINT64TEST_HARDTYPE_FIELD.cpp_type = 1

SSINT64TEST_TEAMID_FIELD.name = "TeamID"
SSINT64TEST_TEAMID_FIELD.full_name = ".SSInt64Test.TeamID"
SSINT64TEST_TEAMID_FIELD.number = 3
SSINT64TEST_TEAMID_FIELD.index = 2
SSINT64TEST_TEAMID_FIELD.label = 1
SSINT64TEST_TEAMID_FIELD.has_default_value = false
SSINT64TEST_TEAMID_FIELD.default_value = 0
SSINT64TEST_TEAMID_FIELD.type = 3
SSINT64TEST_TEAMID_FIELD.cpp_type = 2

SSINT64TEST_TEAMIDS_FIELD.name = "TeamIDs"
SSINT64TEST_TEAMIDS_FIELD.full_name = ".SSInt64Test.TeamIDs"
SSINT64TEST_TEAMIDS_FIELD.number = 4
SSINT64TEST_TEAMIDS_FIELD.index = 3
SSINT64TEST_TEAMIDS_FIELD.label = 3
SSINT64TEST_TEAMIDS_FIELD.has_default_value = false
SSINT64TEST_TEAMIDS_FIELD.default_value = {}
SSINT64TEST_TEAMIDS_FIELD.type = 3
SSINT64TEST_TEAMIDS_FIELD.cpp_type = 2

SSINT64TEST_ROLEID_FIELD.name = "RoleID"
SSINT64TEST_ROLEID_FIELD.full_name = ".SSInt64Test.RoleID"
SSINT64TEST_ROLEID_FIELD.number = 5
SSINT64TEST_ROLEID_FIELD.index = 4
SSINT64TEST_ROLEID_FIELD.label = 1
SSINT64TEST_ROLEID_FIELD.has_default_value = false
SSINT64TEST_ROLEID_FIELD.default_value = 0
SSINT64TEST_ROLEID_FIELD.type = 4
SSINT64TEST_ROLEID_FIELD.cpp_type = 4

SSINT64TEST_ROLEIDS_FIELD.name = "RoleIDs"
SSINT64TEST_ROLEIDS_FIELD.full_name = ".SSInt64Test.RoleIDs"
SSINT64TEST_ROLEIDS_FIELD.number = 6
SSINT64TEST_ROLEIDS_FIELD.index = 5
SSINT64TEST_ROLEIDS_FIELD.label = 3
SSINT64TEST_ROLEIDS_FIELD.has_default_value = false
SSINT64TEST_ROLEIDS_FIELD.default_value = {}
SSINT64TEST_ROLEIDS_FIELD.type = 4
SSINT64TEST_ROLEIDS_FIELD.cpp_type = 4

SSINT64TEST_DATAS_FIELD.name = "Datas"
SSINT64TEST_DATAS_FIELD.full_name = ".SSInt64Test.Datas"
SSINT64TEST_DATAS_FIELD.number = 7
SSINT64TEST_DATAS_FIELD.index = 6
SSINT64TEST_DATAS_FIELD.label = 3
SSINT64TEST_DATAS_FIELD.has_default_value = false
SSINT64TEST_DATAS_FIELD.default_value = {}
SSINT64TEST_DATAS_FIELD.message_type = TESTDATA
SSINT64TEST_DATAS_FIELD.type = 11
SSINT64TEST_DATAS_FIELD.cpp_type = 10

SSINT64TEST.name = "SSInt64Test"
SSINT64TEST.full_name = ".SSInt64Test"
SSINT64TEST.nested_types = {}
SSINT64TEST.enum_types = {}
SSINT64TEST.fields = {SSINT64TEST_PVPTYPE_FIELD, SSINT64TEST_HARDTYPE_FIELD, SSINT64TEST_TEAMID_FIELD, SSINT64TEST_TEAMIDS_FIELD, SSINT64TEST_ROLEID_FIELD, SSINT64TEST_ROLEIDS_FIELD, SSINT64TEST_DATAS_FIELD}
SSINT64TEST.is_extendable = false
SSINT64TEST.extensions = {}

SSInt64Test = protobuf.Message(SSINT64TEST)
TestData = protobuf.Message(TESTDATA)

