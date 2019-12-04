
"use strict";

let Analog = require('./Analog.js');
let RobotModeDataMsg = require('./RobotModeDataMsg.js');
let IOStates = require('./IOStates.js');
let RobotStateRTMsg = require('./RobotStateRTMsg.js');
let ToolDataMsg = require('./ToolDataMsg.js');
let MasterboardDataMsg = require('./MasterboardDataMsg.js');
let Digital = require('./Digital.js');

module.exports = {
  Analog: Analog,
  RobotModeDataMsg: RobotModeDataMsg,
  IOStates: IOStates,
  RobotStateRTMsg: RobotStateRTMsg,
  ToolDataMsg: ToolDataMsg,
  MasterboardDataMsg: MasterboardDataMsg,
  Digital: Digital,
};
