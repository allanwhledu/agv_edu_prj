; Auto-generated. Do not edit!


(cl:in-package agv_udp-srv)


;//! \htmlinclude Replan-request.msg.html

(cl:defclass <Replan-request> (roslisp-msg-protocol:ros-message)
  ((replan
    :reader replan
    :initarg :replan
    :type cl:boolean
    :initform cl:nil)
   (robot_index
    :reader robot_index
    :initarg :robot_index
    :type cl:integer
    :initform 0))
)

(cl:defclass Replan-request (<Replan-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Replan-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Replan-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name agv_udp-srv:<Replan-request> is deprecated: use agv_udp-srv:Replan-request instead.")))

(cl:ensure-generic-function 'replan-val :lambda-list '(m))
(cl:defmethod replan-val ((m <Replan-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader agv_udp-srv:replan-val is deprecated.  Use agv_udp-srv:replan instead.")
  (replan m))

(cl:ensure-generic-function 'robot_index-val :lambda-list '(m))
(cl:defmethod robot_index-val ((m <Replan-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader agv_udp-srv:robot_index-val is deprecated.  Use agv_udp-srv:robot_index instead.")
  (robot_index m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Replan-request>) ostream)
  "Serializes a message object of type '<Replan-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'replan) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'robot_index)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'robot_index)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'robot_index)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'robot_index)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Replan-request>) istream)
  "Deserializes a message object of type '<Replan-request>"
    (cl:setf (cl:slot-value msg 'replan) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'robot_index)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'robot_index)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'robot_index)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'robot_index)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Replan-request>)))
  "Returns string type for a service object of type '<Replan-request>"
  "agv_udp/ReplanRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Replan-request)))
  "Returns string type for a service object of type 'Replan-request"
  "agv_udp/ReplanRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Replan-request>)))
  "Returns md5sum for a message object of type '<Replan-request>"
  "e04b284656e20206941686c48843bad8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Replan-request)))
  "Returns md5sum for a message object of type 'Replan-request"
  "e04b284656e20206941686c48843bad8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Replan-request>)))
  "Returns full string definition for message of type '<Replan-request>"
  (cl:format cl:nil "bool replan~%uint32 robot_index~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Replan-request)))
  "Returns full string definition for message of type 'Replan-request"
  (cl:format cl:nil "bool replan~%uint32 robot_index~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Replan-request>))
  (cl:+ 0
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Replan-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Replan-request
    (cl:cons ':replan (replan msg))
    (cl:cons ':robot_index (robot_index msg))
))
;//! \htmlinclude Replan-response.msg.html

(cl:defclass <Replan-response> (roslisp-msg-protocol:ros-message)
  ((new_goal
    :reader new_goal
    :initarg :new_goal
    :type cl:integer
    :initform 0))
)

(cl:defclass Replan-response (<Replan-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Replan-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Replan-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name agv_udp-srv:<Replan-response> is deprecated: use agv_udp-srv:Replan-response instead.")))

(cl:ensure-generic-function 'new_goal-val :lambda-list '(m))
(cl:defmethod new_goal-val ((m <Replan-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader agv_udp-srv:new_goal-val is deprecated.  Use agv_udp-srv:new_goal instead.")
  (new_goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Replan-response>) ostream)
  "Serializes a message object of type '<Replan-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'new_goal)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'new_goal)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'new_goal)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'new_goal)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Replan-response>) istream)
  "Deserializes a message object of type '<Replan-response>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'new_goal)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'new_goal)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'new_goal)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'new_goal)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Replan-response>)))
  "Returns string type for a service object of type '<Replan-response>"
  "agv_udp/ReplanResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Replan-response)))
  "Returns string type for a service object of type 'Replan-response"
  "agv_udp/ReplanResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Replan-response>)))
  "Returns md5sum for a message object of type '<Replan-response>"
  "e04b284656e20206941686c48843bad8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Replan-response)))
  "Returns md5sum for a message object of type 'Replan-response"
  "e04b284656e20206941686c48843bad8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Replan-response>)))
  "Returns full string definition for message of type '<Replan-response>"
  (cl:format cl:nil "uint32 new_goal~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Replan-response)))
  "Returns full string definition for message of type 'Replan-response"
  (cl:format cl:nil "uint32 new_goal~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Replan-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Replan-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Replan-response
    (cl:cons ':new_goal (new_goal msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Replan)))
  'Replan-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Replan)))
  'Replan-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Replan)))
  "Returns string type for a service object of type '<Replan>"
  "agv_udp/Replan")