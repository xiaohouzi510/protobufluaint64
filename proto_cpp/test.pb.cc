// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "test.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* TestData_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TestData_reflection_ = NULL;
const ::google::protobuf::Descriptor* SSInt64Test_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SSInt64Test_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_test_2eproto() {
  protobuf_AddDesc_test_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "test.proto");
  GOOGLE_CHECK(file != NULL);
  TestData_descriptor_ = file->message_type(0);
  static const int TestData_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestData, selfid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestData, otherid_),
  };
  TestData_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TestData_descriptor_,
      TestData::default_instance_,
      TestData_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestData, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TestData, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(TestData));
  SSInt64Test_descriptor_ = file->message_type(1);
  static const int SSInt64Test_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SSInt64Test, pvptype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SSInt64Test, hardtype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SSInt64Test, teamid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SSInt64Test, teamids_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SSInt64Test, roleid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SSInt64Test, roleids_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SSInt64Test, datas_),
  };
  SSInt64Test_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SSInt64Test_descriptor_,
      SSInt64Test::default_instance_,
      SSInt64Test_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SSInt64Test, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SSInt64Test, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SSInt64Test));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_test_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TestData_descriptor_, &TestData::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SSInt64Test_descriptor_, &SSInt64Test::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_test_2eproto() {
  delete TestData::default_instance_;
  delete TestData_reflection_;
  delete SSInt64Test::default_instance_;
  delete SSInt64Test_reflection_;
}

void protobuf_AddDesc_test_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\ntest.proto\"+\n\010TestData\022\016\n\006SelfID\030\001 \001(\003"
    "\022\017\n\007OtherID\030\002 \001(\004\"\214\001\n\013SSInt64Test\022\017\n\007Pvp"
    "Type\030\001 \001(\005\022\020\n\010HardType\030\002 \001(\005\022\016\n\006TeamID\030\003"
    " \001(\003\022\017\n\007TeamIDs\030\004 \003(\003\022\016\n\006RoleID\030\005 \001(\004\022\017\n"
    "\007RoleIDs\030\006 \003(\004\022\030\n\005Datas\030\007 \003(\0132\t.TestData", 200);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "test.proto", &protobuf_RegisterTypes);
  TestData::default_instance_ = new TestData();
  SSInt64Test::default_instance_ = new SSInt64Test();
  TestData::default_instance_->InitAsDefaultInstance();
  SSInt64Test::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_test_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_test_2eproto {
  StaticDescriptorInitializer_test_2eproto() {
    protobuf_AddDesc_test_2eproto();
  }
} static_descriptor_initializer_test_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int TestData::kSelfIDFieldNumber;
const int TestData::kOtherIDFieldNumber;
#endif  // !_MSC_VER

TestData::TestData()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void TestData::InitAsDefaultInstance() {
}

TestData::TestData(const TestData& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void TestData::SharedCtor() {
  _cached_size_ = 0;
  selfid_ = GOOGLE_LONGLONG(0);
  otherid_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

TestData::~TestData() {
  SharedDtor();
}

void TestData::SharedDtor() {
  if (this != default_instance_) {
  }
}

void TestData::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TestData::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TestData_descriptor_;
}

const TestData& TestData::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_test_2eproto();
  return *default_instance_;
}

TestData* TestData::default_instance_ = NULL;

TestData* TestData::New() const {
  return new TestData;
}

void TestData::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    selfid_ = GOOGLE_LONGLONG(0);
    otherid_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool TestData::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 SelfID = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &selfid_)));
          set_has_selfid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_OtherID;
        break;
      }

      // optional uint64 OtherID = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_OtherID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &otherid_)));
          set_has_otherid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void TestData::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 SelfID = 1;
  if (has_selfid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->selfid(), output);
  }

  // optional uint64 OtherID = 2;
  if (has_otherid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->otherid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* TestData::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 SelfID = 1;
  if (has_selfid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->selfid(), target);
  }

  // optional uint64 OtherID = 2;
  if (has_otherid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->otherid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int TestData::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 SelfID = 1;
    if (has_selfid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->selfid());
    }

    // optional uint64 OtherID = 2;
    if (has_otherid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->otherid());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void TestData::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const TestData* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const TestData*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void TestData::MergeFrom(const TestData& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_selfid()) {
      set_selfid(from.selfid());
    }
    if (from.has_otherid()) {
      set_otherid(from.otherid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void TestData::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TestData::CopyFrom(const TestData& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TestData::IsInitialized() const {

  return true;
}

void TestData::Swap(TestData* other) {
  if (other != this) {
    std::swap(selfid_, other->selfid_);
    std::swap(otherid_, other->otherid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata TestData::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TestData_descriptor_;
  metadata.reflection = TestData_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SSInt64Test::kPvpTypeFieldNumber;
const int SSInt64Test::kHardTypeFieldNumber;
const int SSInt64Test::kTeamIDFieldNumber;
const int SSInt64Test::kTeamIDsFieldNumber;
const int SSInt64Test::kRoleIDFieldNumber;
const int SSInt64Test::kRoleIDsFieldNumber;
const int SSInt64Test::kDatasFieldNumber;
#endif  // !_MSC_VER

SSInt64Test::SSInt64Test()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SSInt64Test::InitAsDefaultInstance() {
}

SSInt64Test::SSInt64Test(const SSInt64Test& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SSInt64Test::SharedCtor() {
  _cached_size_ = 0;
  pvptype_ = 0;
  hardtype_ = 0;
  teamid_ = GOOGLE_LONGLONG(0);
  roleid_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SSInt64Test::~SSInt64Test() {
  SharedDtor();
}

void SSInt64Test::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SSInt64Test::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SSInt64Test::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SSInt64Test_descriptor_;
}

const SSInt64Test& SSInt64Test::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_test_2eproto();
  return *default_instance_;
}

SSInt64Test* SSInt64Test::default_instance_ = NULL;

SSInt64Test* SSInt64Test::New() const {
  return new SSInt64Test;
}

void SSInt64Test::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    pvptype_ = 0;
    hardtype_ = 0;
    teamid_ = GOOGLE_LONGLONG(0);
    roleid_ = GOOGLE_ULONGLONG(0);
  }
  teamids_.Clear();
  roleids_.Clear();
  datas_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SSInt64Test::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 PvpType = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &pvptype_)));
          set_has_pvptype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_HardType;
        break;
      }

      // optional int32 HardType = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_HardType:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &hardtype_)));
          set_has_hardtype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_TeamID;
        break;
      }

      // optional int64 TeamID = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_TeamID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &teamid_)));
          set_has_teamid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_TeamIDs;
        break;
      }

      // repeated int64 TeamIDs = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_TeamIDs:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 1, 32, input, this->mutable_teamids())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, this->mutable_teamids())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_TeamIDs;
        if (input->ExpectTag(40)) goto parse_RoleID;
        break;
      }

      // optional uint64 RoleID = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_RoleID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &roleid_)));
          set_has_roleid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_RoleIDs;
        break;
      }

      // repeated uint64 RoleIDs = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_RoleIDs:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 1, 48, input, this->mutable_roleids())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, this->mutable_roleids())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_RoleIDs;
        if (input->ExpectTag(58)) goto parse_Datas;
        break;
      }

      // repeated .TestData Datas = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_Datas:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_datas()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_Datas;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void SSInt64Test::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 PvpType = 1;
  if (has_pvptype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->pvptype(), output);
  }

  // optional int32 HardType = 2;
  if (has_hardtype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->hardtype(), output);
  }

  // optional int64 TeamID = 3;
  if (has_teamid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->teamid(), output);
  }

  // repeated int64 TeamIDs = 4;
  for (int i = 0; i < this->teamids_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(
      4, this->teamids(i), output);
  }

  // optional uint64 RoleID = 5;
  if (has_roleid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(5, this->roleid(), output);
  }

  // repeated uint64 RoleIDs = 6;
  for (int i = 0; i < this->roleids_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(
      6, this->roleids(i), output);
  }

  // repeated .TestData Datas = 7;
  for (int i = 0; i < this->datas_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->datas(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SSInt64Test::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 PvpType = 1;
  if (has_pvptype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->pvptype(), target);
  }

  // optional int32 HardType = 2;
  if (has_hardtype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->hardtype(), target);
  }

  // optional int64 TeamID = 3;
  if (has_teamid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->teamid(), target);
  }

  // repeated int64 TeamIDs = 4;
  for (int i = 0; i < this->teamids_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt64ToArray(4, this->teamids(i), target);
  }

  // optional uint64 RoleID = 5;
  if (has_roleid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(5, this->roleid(), target);
  }

  // repeated uint64 RoleIDs = 6;
  for (int i = 0; i < this->roleids_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt64ToArray(6, this->roleids(i), target);
  }

  // repeated .TestData Datas = 7;
  for (int i = 0; i < this->datas_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, this->datas(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SSInt64Test::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 PvpType = 1;
    if (has_pvptype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->pvptype());
    }

    // optional int32 HardType = 2;
    if (has_hardtype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->hardtype());
    }

    // optional int64 TeamID = 3;
    if (has_teamid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->teamid());
    }

    // optional uint64 RoleID = 5;
    if (has_roleid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->roleid());
    }

  }
  // repeated int64 TeamIDs = 4;
  {
    int data_size = 0;
    for (int i = 0; i < this->teamids_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int64Size(this->teamids(i));
    }
    total_size += 1 * this->teamids_size() + data_size;
  }

  // repeated uint64 RoleIDs = 6;
  {
    int data_size = 0;
    for (int i = 0; i < this->roleids_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt64Size(this->roleids(i));
    }
    total_size += 1 * this->roleids_size() + data_size;
  }

  // repeated .TestData Datas = 7;
  total_size += 1 * this->datas_size();
  for (int i = 0; i < this->datas_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->datas(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SSInt64Test::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SSInt64Test* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SSInt64Test*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SSInt64Test::MergeFrom(const SSInt64Test& from) {
  GOOGLE_CHECK_NE(&from, this);
  teamids_.MergeFrom(from.teamids_);
  roleids_.MergeFrom(from.roleids_);
  datas_.MergeFrom(from.datas_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pvptype()) {
      set_pvptype(from.pvptype());
    }
    if (from.has_hardtype()) {
      set_hardtype(from.hardtype());
    }
    if (from.has_teamid()) {
      set_teamid(from.teamid());
    }
    if (from.has_roleid()) {
      set_roleid(from.roleid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SSInt64Test::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SSInt64Test::CopyFrom(const SSInt64Test& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SSInt64Test::IsInitialized() const {

  return true;
}

void SSInt64Test::Swap(SSInt64Test* other) {
  if (other != this) {
    std::swap(pvptype_, other->pvptype_);
    std::swap(hardtype_, other->hardtype_);
    std::swap(teamid_, other->teamid_);
    teamids_.Swap(&other->teamids_);
    std::swap(roleid_, other->roleid_);
    roleids_.Swap(&other->roleids_);
    datas_.Swap(&other->datas_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SSInt64Test::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SSInt64Test_descriptor_;
  metadata.reflection = SSInt64Test_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
