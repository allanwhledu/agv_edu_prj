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

class CenterCmd {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.replan = null;
      this.reserve_area_first = null;
      this.reserve_area_second = null;
    }
    else {
      if (initObj.hasOwnProperty('replan')) {
        this.replan = initObj.replan
      }
      else {
        this.replan = [];
      }
      if (initObj.hasOwnProperty('reserve_area_first')) {
        this.reserve_area_first = initObj.reserve_area_first
      }
      else {
        this.reserve_area_first = [];
      }
      if (initObj.hasOwnProperty('reserve_area_second')) {
        this.reserve_area_second = initObj.reserve_area_second
      }
      else {
        this.reserve_area_second = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type CenterCmd
    // Serialize message field [replan]
    bufferOffset = _arraySerializer.bool(obj.replan, buffer, bufferOffset, null);
    // Serialize message field [reserve_area_first]
    bufferOffset = _arraySerializer.int32(obj.reserve_area_first, buffer, bufferOffset, null);
    // Serialize message field [reserve_area_second]
    bufferOffset = _arraySerializer.int32(obj.reserve_area_second, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CenterCmd
    let len;
    let data = new CenterCmd(null);
    // Deserialize message field [replan]
    data.replan = _arrayDeserializer.bool(buffer, bufferOffset, null)
    // Deserialize message field [reserve_area_first]
    data.reserve_area_first = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [reserve_area_second]
    data.reserve_area_second = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.replan.length;
    length += 4 * object.reserve_area_first.length;
    length += 4 * object.reserve_area_second.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'agv_udp/CenterCmd';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1f2758a33326e770ef3efda627a683a4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool[]  replan
    int32[] reserve_area_first
    int32[] reserve_area_second
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new CenterCmd(null);
    if (msg.replan !== undefined) {
      resolved.replan = msg.replan;
    }
    else {
      resolved.replan = []
    }

    if (msg.reserve_area_first !== undefined) {
      resolved.reserve_area_first = msg.reserve_area_first;
    }
    else {
      resolved.reserve_area_first = []
    }

    if (msg.reserve_area_second !== undefined) {
      resolved.reserve_area_second = msg.reserve_area_second;
    }
    else {
      resolved.reserve_area_second = []
    }

    return resolved;
    }
};

module.exports = CenterCmd;
