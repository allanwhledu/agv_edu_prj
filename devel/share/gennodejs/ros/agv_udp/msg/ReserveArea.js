// Auto-generated. Do not edit!

// (in-package agv_udp.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ReserveArea {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.first_area = null;
      this.second_area = null;
      this.is_dest = null;
    }
    else {
      if (initObj.hasOwnProperty('first_area')) {
        this.first_area = initObj.first_area
      }
      else {
        this.first_area = 0;
      }
      if (initObj.hasOwnProperty('second_area')) {
        this.second_area = initObj.second_area
      }
      else {
        this.second_area = 0;
      }
      if (initObj.hasOwnProperty('is_dest')) {
        this.is_dest = initObj.is_dest
      }
      else {
        this.is_dest = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReserveArea
    // Serialize message field [first_area]
    bufferOffset = _serializer.uint32(obj.first_area, buffer, bufferOffset);
    // Serialize message field [second_area]
    bufferOffset = _serializer.uint32(obj.second_area, buffer, bufferOffset);
    // Serialize message field [is_dest]
    bufferOffset = _serializer.bool(obj.is_dest, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReserveArea
    let len;
    let data = new ReserveArea(null);
    // Deserialize message field [first_area]
    data.first_area = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [second_area]
    data.second_area = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [is_dest]
    data.is_dest = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 9;
  }

  static datatype() {
    // Returns string type for a message object
    return 'agv_udp/ReserveArea';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c22270ab7b7fd72c83a94fc322460280';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 first_area
    uint32 second_area
    bool is_dest
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReserveArea(null);
    if (msg.first_area !== undefined) {
      resolved.first_area = msg.first_area;
    }
    else {
      resolved.first_area = 0
    }

    if (msg.second_area !== undefined) {
      resolved.second_area = msg.second_area;
    }
    else {
      resolved.second_area = 0
    }

    if (msg.is_dest !== undefined) {
      resolved.is_dest = msg.is_dest;
    }
    else {
      resolved.is_dest = false
    }

    return resolved;
    }
};

module.exports = ReserveArea;
