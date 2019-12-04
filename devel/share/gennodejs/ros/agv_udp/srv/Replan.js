// Auto-generated. Do not edit!

// (in-package agv_udp.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class ReplanRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.replan = null;
      this.robot_index = null;
    }
    else {
      if (initObj.hasOwnProperty('replan')) {
        this.replan = initObj.replan
      }
      else {
        this.replan = false;
      }
      if (initObj.hasOwnProperty('robot_index')) {
        this.robot_index = initObj.robot_index
      }
      else {
        this.robot_index = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReplanRequest
    // Serialize message field [replan]
    bufferOffset = _serializer.bool(obj.replan, buffer, bufferOffset);
    // Serialize message field [robot_index]
    bufferOffset = _serializer.uint32(obj.robot_index, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReplanRequest
    let len;
    let data = new ReplanRequest(null);
    // Deserialize message field [replan]
    data.replan = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [robot_index]
    data.robot_index = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'agv_udp/ReplanRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5cf4d38b1baf82787e4c474ad9cb888c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool replan
    uint32 robot_index
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReplanRequest(null);
    if (msg.replan !== undefined) {
      resolved.replan = msg.replan;
    }
    else {
      resolved.replan = false
    }

    if (msg.robot_index !== undefined) {
      resolved.robot_index = msg.robot_index;
    }
    else {
      resolved.robot_index = 0
    }

    return resolved;
    }
};

class ReplanResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.new_goal = null;
    }
    else {
      if (initObj.hasOwnProperty('new_goal')) {
        this.new_goal = initObj.new_goal
      }
      else {
        this.new_goal = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReplanResponse
    // Serialize message field [new_goal]
    bufferOffset = _serializer.uint32(obj.new_goal, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReplanResponse
    let len;
    let data = new ReplanResponse(null);
    // Deserialize message field [new_goal]
    data.new_goal = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'agv_udp/ReplanResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '69d0dd20ad906bb6e1e367ea883b4903';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 new_goal
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReplanResponse(null);
    if (msg.new_goal !== undefined) {
      resolved.new_goal = msg.new_goal;
    }
    else {
      resolved.new_goal = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: ReplanRequest,
  Response: ReplanResponse,
  md5sum() { return 'e04b284656e20206941686c48843bad8'; },
  datatype() { return 'agv_udp/Replan'; }
};
