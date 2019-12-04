; Auto-generated. Do not edit!


(cl:in-package move_forward-srv)


;//! \htmlinclude agv_call-request.msg.html

(cl:defclass <agv_call-request> (roslisp-msg-protocol:ros-message)
  ((action
    :reader action
    :initarg :action
    :type cl:integer
    :initform 0))
)

(cl:defclass agv_call-request (<agv_call-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <agv_call-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'agv_call-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name move_forward-srv:<agv_call-request> is deprecated: use move_forward-srv:agv_call-request instead.")))

(cl:ensure-generic-function 'action-val :lambda-list '(m))
(cl:defmethod action-val ((m <agv_call-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader move_forward-srv:action-val is deprecated.  Use move_forward-srv:action instead.")
  (action m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <agv_call-request>) ostream)
  "Serializes a message object of type '<agv_call-request>"
  (cl:let* ((signed (cl:slot-value msg 'action)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <agv_call-request>) istream)
  "Deserializes a message object of type '<agv_call-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'action) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<agv_call-request>)))
  "Returns string type for a service object of type '<agv_call-request>"
  "move_forward/agv_callRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'agv_call-request)))
  "Returns string type for a service object of type 'agv_call-request"
  "move_forward/agv_callRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<agv_call-request>)))
  "Returns md5sum for a message object of type '<agv_call-request>"
  "bbdd7d6a90f6922f6aae5a0ca449c65d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'agv_call-request)))
  "Returns md5sum for a message object of type 'agv_call-request"
  "bbdd7d6a90f6922f6aae5a0ca449c65d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<agv_call-request>)))
  "Returns full string definition for message of type '<agv_call-request>"
  (cl:format cl:nil "int64 action~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'agv_call-request)))
  "Returns full string definition for message of type 'agv_call-request"
  (cl:format cl:nil "int64 action~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <agv_call-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <agv_call-request>))
  "Converts a ROS message object to a list"
  (cl:list 'agv_call-request
    (cl:cons ':action (action msg))
))
;//! \htmlinclude agv_call-response.msg.html

(cl:defclass <agv_call-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass agv_call-response (<agv_call-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <agv_call-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'agv_call-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name move_forward-srv:<agv_call-response> is deprecated: use move_forward-srv:agv_call-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <agv_call-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader move_forward-srv:result-val is deprecated.  Use move_forward-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <agv_call-response>) ostream)
  "Serializes a message object of type '<agv_call-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <agv_call-response>) istream)
  "Deserializes a message object of type '<agv_call-response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<agv_call-response>)))
  "Returns string type for a service object of type '<agv_call-response>"
  "move_forward/agv_callResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'agv_call-response)))
  "Returns string type for a service object of type 'agv_call-response"
  "move_forward/agv_callResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<agv_call-response>)))
  "Returns md5sum for a message object of type '<agv_call-response>"
  "bbdd7d6a90f6922f6aae5a0ca449c65d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'agv_call-response)))
  "Returns md5sum for a message object of type 'agv_call-response"
  "bbdd7d6a90f6922f6aae5a0ca449c65d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<agv_call-response>)))
  "Returns full string definition for message of type '<agv_call-response>"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'agv_call-response)))
  "Returns full string definition for message of type 'agv_call-response"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <agv_call-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <agv_call-response>))
  "Converts a ROS message object to a list"
  (cl:list 'agv_call-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'agv_call)))
  'agv_call-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'agv_call)))
  'agv_call-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'agv_call)))
  "Returns string type for a service object of type '<agv_call>"
  "move_forward/agv_call")