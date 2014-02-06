// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: command.proto

#ifndef PROTOBUF_command_2eproto__INCLUDED
#define PROTOBUF_command_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace ESB {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_command_2eproto();
void protobuf_AssignDesc_command_2eproto();
void protobuf_ShutdownFile_command_2eproto();

class Command;

enum Command_Cmd {
  Command_Cmd_ERROR = 1,
  Command_Cmd_RESPONSE = 2,
  Command_Cmd_NODE_HELLO = 3,
  Command_Cmd_PING = 4,
  Command_Cmd_PONG = 5,
  Command_Cmd_INVOKE = 6,
  Command_Cmd_REGISTER_INVOKE = 7,
  Command_Cmd_REGISTER_INVOKE_OK = 8
};
bool Command_Cmd_IsValid(int value);
const Command_Cmd Command_Cmd_Cmd_MIN = Command_Cmd_ERROR;
const Command_Cmd Command_Cmd_Cmd_MAX = Command_Cmd_REGISTER_INVOKE_OK;
const int Command_Cmd_Cmd_ARRAYSIZE = Command_Cmd_Cmd_MAX + 1;

const ::google::protobuf::EnumDescriptor* Command_Cmd_descriptor();
inline const ::std::string& Command_Cmd_Name(Command_Cmd value) {
  return ::google::protobuf::internal::NameOfEnum(
    Command_Cmd_descriptor(), value);
}
inline bool Command_Cmd_Parse(
    const ::std::string& name, Command_Cmd* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Command_Cmd>(
    Command_Cmd_descriptor(), name, value);
}
// ===================================================================

class Command : public ::google::protobuf::Message {
 public:
  Command();
  virtual ~Command();

  Command(const Command& from);

  inline Command& operator=(const Command& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Command& default_instance();

  void Swap(Command* other);

  // implements Message ----------------------------------------------

  Command* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Command& from);
  void MergeFrom(const Command& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef Command_Cmd Cmd;
  static const Cmd ERROR = Command_Cmd_ERROR;
  static const Cmd RESPONSE = Command_Cmd_RESPONSE;
  static const Cmd NODE_HELLO = Command_Cmd_NODE_HELLO;
  static const Cmd PING = Command_Cmd_PING;
  static const Cmd PONG = Command_Cmd_PONG;
  static const Cmd INVOKE = Command_Cmd_INVOKE;
  static const Cmd REGISTER_INVOKE = Command_Cmd_REGISTER_INVOKE;
  static const Cmd REGISTER_INVOKE_OK = Command_Cmd_REGISTER_INVOKE_OK;
  static inline bool Cmd_IsValid(int value) {
    return Command_Cmd_IsValid(value);
  }
  static const Cmd Cmd_MIN =
    Command_Cmd_Cmd_MIN;
  static const Cmd Cmd_MAX =
    Command_Cmd_Cmd_MAX;
  static const int Cmd_ARRAYSIZE =
    Command_Cmd_Cmd_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Cmd_descriptor() {
    return Command_Cmd_descriptor();
  }
  static inline const ::std::string& Cmd_Name(Cmd value) {
    return Command_Cmd_Name(value);
  }
  static inline bool Cmd_Parse(const ::std::string& name,
      Cmd* value) {
    return Command_Cmd_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required .ESB.Command.Cmd cmd = 1;
  inline bool has_cmd() const;
  inline void clear_cmd();
  static const int kCmdFieldNumber = 1;
  inline ::ESB::Command_Cmd cmd() const;
  inline void set_cmd(::ESB::Command_Cmd value);

  // optional string identifier = 2;
  inline bool has_identifier() const;
  inline void clear_identifier();
  static const int kIdentifierFieldNumber = 2;
  inline const ::std::string& identifier() const;
  inline void set_identifier(const ::std::string& value);
  inline void set_identifier(const char* value);
  inline void set_identifier(const char* value, size_t size);
  inline ::std::string* mutable_identifier();
  inline ::std::string* release_identifier();
  inline void set_allocated_identifier(::std::string* identifier);

  // optional string guid_from = 3;
  inline bool has_guid_from() const;
  inline void clear_guid_from();
  static const int kGuidFromFieldNumber = 3;
  inline const ::std::string& guid_from() const;
  inline void set_guid_from(const ::std::string& value);
  inline void set_guid_from(const char* value);
  inline void set_guid_from(const char* value, size_t size);
  inline ::std::string* mutable_guid_from();
  inline ::std::string* release_guid_from();
  inline void set_allocated_guid_from(::std::string* guid_from);

  // optional string guid_to = 4;
  inline bool has_guid_to() const;
  inline void clear_guid_to();
  static const int kGuidToFieldNumber = 4;
  inline const ::std::string& guid_to() const;
  inline void set_guid_to(const ::std::string& value);
  inline void set_guid_to(const char* value);
  inline void set_guid_to(const char* value, size_t size);
  inline ::std::string* mutable_guid_to();
  inline ::std::string* release_guid_to();
  inline void set_allocated_guid_to(::std::string* guid_to);

  // optional string source_proxy_guid = 5;
  inline bool has_source_proxy_guid() const;
  inline void clear_source_proxy_guid();
  static const int kSourceProxyGuidFieldNumber = 5;
  inline const ::std::string& source_proxy_guid() const;
  inline void set_source_proxy_guid(const ::std::string& value);
  inline void set_source_proxy_guid(const char* value);
  inline void set_source_proxy_guid(const char* value, size_t size);
  inline ::std::string* mutable_source_proxy_guid();
  inline ::std::string* release_source_proxy_guid();
  inline void set_allocated_source_proxy_guid(::std::string* source_proxy_guid);

  // optional string target_proxy_guid = 6;
  inline bool has_target_proxy_guid() const;
  inline void clear_target_proxy_guid();
  static const int kTargetProxyGuidFieldNumber = 6;
  inline const ::std::string& target_proxy_guid() const;
  inline void set_target_proxy_guid(const ::std::string& value);
  inline void set_target_proxy_guid(const char* value);
  inline void set_target_proxy_guid(const char* value, size_t size);
  inline ::std::string* mutable_target_proxy_guid();
  inline ::std::string* release_target_proxy_guid();
  inline void set_allocated_target_proxy_guid(::std::string* target_proxy_guid);

  // optional int32 version = 7;
  inline bool has_version() const;
  inline void clear_version();
  static const int kVersionFieldNumber = 7;
  inline ::google::protobuf::int32 version() const;
  inline void set_version(::google::protobuf::int32 value);

  // optional double start_time = 8;
  inline bool has_start_time() const;
  inline void clear_start_time();
  static const int kStartTimeFieldNumber = 8;
  inline double start_time() const;
  inline void set_start_time(double value);

  // optional int32 timeout_ms = 9;
  inline bool has_timeout_ms() const;
  inline void clear_timeout_ms();
  static const int kTimeoutMsFieldNumber = 9;
  inline ::google::protobuf::int32 timeout_ms() const;
  inline void set_timeout_ms(::google::protobuf::int32 value);

  // required string payload = 10;
  inline bool has_payload() const;
  inline void clear_payload();
  static const int kPayloadFieldNumber = 10;
  inline const ::std::string& payload() const;
  inline void set_payload(const ::std::string& value);
  inline void set_payload(const char* value);
  inline void set_payload(const char* value, size_t size);
  inline ::std::string* mutable_payload();
  inline ::std::string* release_payload();
  inline void set_allocated_payload(::std::string* payload);

  // @@protoc_insertion_point(class_scope:ESB.Command)
 private:
  inline void set_has_cmd();
  inline void clear_has_cmd();
  inline void set_has_identifier();
  inline void clear_has_identifier();
  inline void set_has_guid_from();
  inline void clear_has_guid_from();
  inline void set_has_guid_to();
  inline void clear_has_guid_to();
  inline void set_has_source_proxy_guid();
  inline void clear_has_source_proxy_guid();
  inline void set_has_target_proxy_guid();
  inline void clear_has_target_proxy_guid();
  inline void set_has_version();
  inline void clear_has_version();
  inline void set_has_start_time();
  inline void clear_has_start_time();
  inline void set_has_timeout_ms();
  inline void clear_has_timeout_ms();
  inline void set_has_payload();
  inline void clear_has_payload();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* identifier_;
  ::std::string* guid_from_;
  ::std::string* guid_to_;
  int cmd_;
  ::google::protobuf::int32 version_;
  ::std::string* source_proxy_guid_;
  ::std::string* target_proxy_guid_;
  double start_time_;
  ::std::string* payload_;
  ::google::protobuf::int32 timeout_ms_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(10 + 31) / 32];

  friend void  protobuf_AddDesc_command_2eproto();
  friend void protobuf_AssignDesc_command_2eproto();
  friend void protobuf_ShutdownFile_command_2eproto();

  void InitAsDefaultInstance();
  static Command* default_instance_;
};
// ===================================================================


// ===================================================================

// Command

// required .ESB.Command.Cmd cmd = 1;
inline bool Command::has_cmd() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Command::set_has_cmd() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Command::clear_has_cmd() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Command::clear_cmd() {
  cmd_ = 1;
  clear_has_cmd();
}
inline ::ESB::Command_Cmd Command::cmd() const {
  return static_cast< ::ESB::Command_Cmd >(cmd_);
}
inline void Command::set_cmd(::ESB::Command_Cmd value) {
  assert(::ESB::Command_Cmd_IsValid(value));
  set_has_cmd();
  cmd_ = value;
}

// optional string identifier = 2;
inline bool Command::has_identifier() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Command::set_has_identifier() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Command::clear_has_identifier() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Command::clear_identifier() {
  if (identifier_ != &::google::protobuf::internal::kEmptyString) {
    identifier_->clear();
  }
  clear_has_identifier();
}
inline const ::std::string& Command::identifier() const {
  return *identifier_;
}
inline void Command::set_identifier(const ::std::string& value) {
  set_has_identifier();
  if (identifier_ == &::google::protobuf::internal::kEmptyString) {
    identifier_ = new ::std::string;
  }
  identifier_->assign(value);
}
inline void Command::set_identifier(const char* value) {
  set_has_identifier();
  if (identifier_ == &::google::protobuf::internal::kEmptyString) {
    identifier_ = new ::std::string;
  }
  identifier_->assign(value);
}
inline void Command::set_identifier(const char* value, size_t size) {
  set_has_identifier();
  if (identifier_ == &::google::protobuf::internal::kEmptyString) {
    identifier_ = new ::std::string;
  }
  identifier_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Command::mutable_identifier() {
  set_has_identifier();
  if (identifier_ == &::google::protobuf::internal::kEmptyString) {
    identifier_ = new ::std::string;
  }
  return identifier_;
}
inline ::std::string* Command::release_identifier() {
  clear_has_identifier();
  if (identifier_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = identifier_;
    identifier_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Command::set_allocated_identifier(::std::string* identifier) {
  if (identifier_ != &::google::protobuf::internal::kEmptyString) {
    delete identifier_;
  }
  if (identifier) {
    set_has_identifier();
    identifier_ = identifier;
  } else {
    clear_has_identifier();
    identifier_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string guid_from = 3;
inline bool Command::has_guid_from() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Command::set_has_guid_from() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Command::clear_has_guid_from() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Command::clear_guid_from() {
  if (guid_from_ != &::google::protobuf::internal::kEmptyString) {
    guid_from_->clear();
  }
  clear_has_guid_from();
}
inline const ::std::string& Command::guid_from() const {
  return *guid_from_;
}
inline void Command::set_guid_from(const ::std::string& value) {
  set_has_guid_from();
  if (guid_from_ == &::google::protobuf::internal::kEmptyString) {
    guid_from_ = new ::std::string;
  }
  guid_from_->assign(value);
}
inline void Command::set_guid_from(const char* value) {
  set_has_guid_from();
  if (guid_from_ == &::google::protobuf::internal::kEmptyString) {
    guid_from_ = new ::std::string;
  }
  guid_from_->assign(value);
}
inline void Command::set_guid_from(const char* value, size_t size) {
  set_has_guid_from();
  if (guid_from_ == &::google::protobuf::internal::kEmptyString) {
    guid_from_ = new ::std::string;
  }
  guid_from_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Command::mutable_guid_from() {
  set_has_guid_from();
  if (guid_from_ == &::google::protobuf::internal::kEmptyString) {
    guid_from_ = new ::std::string;
  }
  return guid_from_;
}
inline ::std::string* Command::release_guid_from() {
  clear_has_guid_from();
  if (guid_from_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = guid_from_;
    guid_from_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Command::set_allocated_guid_from(::std::string* guid_from) {
  if (guid_from_ != &::google::protobuf::internal::kEmptyString) {
    delete guid_from_;
  }
  if (guid_from) {
    set_has_guid_from();
    guid_from_ = guid_from;
  } else {
    clear_has_guid_from();
    guid_from_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string guid_to = 4;
inline bool Command::has_guid_to() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Command::set_has_guid_to() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Command::clear_has_guid_to() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Command::clear_guid_to() {
  if (guid_to_ != &::google::protobuf::internal::kEmptyString) {
    guid_to_->clear();
  }
  clear_has_guid_to();
}
inline const ::std::string& Command::guid_to() const {
  return *guid_to_;
}
inline void Command::set_guid_to(const ::std::string& value) {
  set_has_guid_to();
  if (guid_to_ == &::google::protobuf::internal::kEmptyString) {
    guid_to_ = new ::std::string;
  }
  guid_to_->assign(value);
}
inline void Command::set_guid_to(const char* value) {
  set_has_guid_to();
  if (guid_to_ == &::google::protobuf::internal::kEmptyString) {
    guid_to_ = new ::std::string;
  }
  guid_to_->assign(value);
}
inline void Command::set_guid_to(const char* value, size_t size) {
  set_has_guid_to();
  if (guid_to_ == &::google::protobuf::internal::kEmptyString) {
    guid_to_ = new ::std::string;
  }
  guid_to_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Command::mutable_guid_to() {
  set_has_guid_to();
  if (guid_to_ == &::google::protobuf::internal::kEmptyString) {
    guid_to_ = new ::std::string;
  }
  return guid_to_;
}
inline ::std::string* Command::release_guid_to() {
  clear_has_guid_to();
  if (guid_to_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = guid_to_;
    guid_to_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Command::set_allocated_guid_to(::std::string* guid_to) {
  if (guid_to_ != &::google::protobuf::internal::kEmptyString) {
    delete guid_to_;
  }
  if (guid_to) {
    set_has_guid_to();
    guid_to_ = guid_to;
  } else {
    clear_has_guid_to();
    guid_to_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string source_proxy_guid = 5;
inline bool Command::has_source_proxy_guid() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Command::set_has_source_proxy_guid() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Command::clear_has_source_proxy_guid() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Command::clear_source_proxy_guid() {
  if (source_proxy_guid_ != &::google::protobuf::internal::kEmptyString) {
    source_proxy_guid_->clear();
  }
  clear_has_source_proxy_guid();
}
inline const ::std::string& Command::source_proxy_guid() const {
  return *source_proxy_guid_;
}
inline void Command::set_source_proxy_guid(const ::std::string& value) {
  set_has_source_proxy_guid();
  if (source_proxy_guid_ == &::google::protobuf::internal::kEmptyString) {
    source_proxy_guid_ = new ::std::string;
  }
  source_proxy_guid_->assign(value);
}
inline void Command::set_source_proxy_guid(const char* value) {
  set_has_source_proxy_guid();
  if (source_proxy_guid_ == &::google::protobuf::internal::kEmptyString) {
    source_proxy_guid_ = new ::std::string;
  }
  source_proxy_guid_->assign(value);
}
inline void Command::set_source_proxy_guid(const char* value, size_t size) {
  set_has_source_proxy_guid();
  if (source_proxy_guid_ == &::google::protobuf::internal::kEmptyString) {
    source_proxy_guid_ = new ::std::string;
  }
  source_proxy_guid_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Command::mutable_source_proxy_guid() {
  set_has_source_proxy_guid();
  if (source_proxy_guid_ == &::google::protobuf::internal::kEmptyString) {
    source_proxy_guid_ = new ::std::string;
  }
  return source_proxy_guid_;
}
inline ::std::string* Command::release_source_proxy_guid() {
  clear_has_source_proxy_guid();
  if (source_proxy_guid_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = source_proxy_guid_;
    source_proxy_guid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Command::set_allocated_source_proxy_guid(::std::string* source_proxy_guid) {
  if (source_proxy_guid_ != &::google::protobuf::internal::kEmptyString) {
    delete source_proxy_guid_;
  }
  if (source_proxy_guid) {
    set_has_source_proxy_guid();
    source_proxy_guid_ = source_proxy_guid;
  } else {
    clear_has_source_proxy_guid();
    source_proxy_guid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string target_proxy_guid = 6;
inline bool Command::has_target_proxy_guid() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Command::set_has_target_proxy_guid() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Command::clear_has_target_proxy_guid() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Command::clear_target_proxy_guid() {
  if (target_proxy_guid_ != &::google::protobuf::internal::kEmptyString) {
    target_proxy_guid_->clear();
  }
  clear_has_target_proxy_guid();
}
inline const ::std::string& Command::target_proxy_guid() const {
  return *target_proxy_guid_;
}
inline void Command::set_target_proxy_guid(const ::std::string& value) {
  set_has_target_proxy_guid();
  if (target_proxy_guid_ == &::google::protobuf::internal::kEmptyString) {
    target_proxy_guid_ = new ::std::string;
  }
  target_proxy_guid_->assign(value);
}
inline void Command::set_target_proxy_guid(const char* value) {
  set_has_target_proxy_guid();
  if (target_proxy_guid_ == &::google::protobuf::internal::kEmptyString) {
    target_proxy_guid_ = new ::std::string;
  }
  target_proxy_guid_->assign(value);
}
inline void Command::set_target_proxy_guid(const char* value, size_t size) {
  set_has_target_proxy_guid();
  if (target_proxy_guid_ == &::google::protobuf::internal::kEmptyString) {
    target_proxy_guid_ = new ::std::string;
  }
  target_proxy_guid_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Command::mutable_target_proxy_guid() {
  set_has_target_proxy_guid();
  if (target_proxy_guid_ == &::google::protobuf::internal::kEmptyString) {
    target_proxy_guid_ = new ::std::string;
  }
  return target_proxy_guid_;
}
inline ::std::string* Command::release_target_proxy_guid() {
  clear_has_target_proxy_guid();
  if (target_proxy_guid_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = target_proxy_guid_;
    target_proxy_guid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Command::set_allocated_target_proxy_guid(::std::string* target_proxy_guid) {
  if (target_proxy_guid_ != &::google::protobuf::internal::kEmptyString) {
    delete target_proxy_guid_;
  }
  if (target_proxy_guid) {
    set_has_target_proxy_guid();
    target_proxy_guid_ = target_proxy_guid;
  } else {
    clear_has_target_proxy_guid();
    target_proxy_guid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 version = 7;
inline bool Command::has_version() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Command::set_has_version() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Command::clear_has_version() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Command::clear_version() {
  version_ = 0;
  clear_has_version();
}
inline ::google::protobuf::int32 Command::version() const {
  return version_;
}
inline void Command::set_version(::google::protobuf::int32 value) {
  set_has_version();
  version_ = value;
}

// optional double start_time = 8;
inline bool Command::has_start_time() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Command::set_has_start_time() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Command::clear_has_start_time() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Command::clear_start_time() {
  start_time_ = 0;
  clear_has_start_time();
}
inline double Command::start_time() const {
  return start_time_;
}
inline void Command::set_start_time(double value) {
  set_has_start_time();
  start_time_ = value;
}

// optional int32 timeout_ms = 9;
inline bool Command::has_timeout_ms() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Command::set_has_timeout_ms() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Command::clear_has_timeout_ms() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Command::clear_timeout_ms() {
  timeout_ms_ = 0;
  clear_has_timeout_ms();
}
inline ::google::protobuf::int32 Command::timeout_ms() const {
  return timeout_ms_;
}
inline void Command::set_timeout_ms(::google::protobuf::int32 value) {
  set_has_timeout_ms();
  timeout_ms_ = value;
}

// required string payload = 10;
inline bool Command::has_payload() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void Command::set_has_payload() {
  _has_bits_[0] |= 0x00000200u;
}
inline void Command::clear_has_payload() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void Command::clear_payload() {
  if (payload_ != &::google::protobuf::internal::kEmptyString) {
    payload_->clear();
  }
  clear_has_payload();
}
inline const ::std::string& Command::payload() const {
  return *payload_;
}
inline void Command::set_payload(const ::std::string& value) {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::kEmptyString) {
    payload_ = new ::std::string;
  }
  payload_->assign(value);
}
inline void Command::set_payload(const char* value) {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::kEmptyString) {
    payload_ = new ::std::string;
  }
  payload_->assign(value);
}
inline void Command::set_payload(const char* value, size_t size) {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::kEmptyString) {
    payload_ = new ::std::string;
  }
  payload_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Command::mutable_payload() {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::kEmptyString) {
    payload_ = new ::std::string;
  }
  return payload_;
}
inline ::std::string* Command::release_payload() {
  clear_has_payload();
  if (payload_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = payload_;
    payload_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Command::set_allocated_payload(::std::string* payload) {
  if (payload_ != &::google::protobuf::internal::kEmptyString) {
    delete payload_;
  }
  if (payload) {
    set_has_payload();
    payload_ = payload;
  } else {
    clear_has_payload();
    payload_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace ESB

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ESB::Command_Cmd>() {
  return ::ESB::Command_Cmd_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_command_2eproto__INCLUDED
