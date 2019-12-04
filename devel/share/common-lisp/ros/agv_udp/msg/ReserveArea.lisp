; Auto-generated. Do not edit!


(cl:in-package agv_udp-msg)


;//! \htmlinclude ReserveArea.msg.html

(cl:defclass <ReserveArea> (roslisp-msg-protocol:ros-message)
  ((first_area
    :reader first_area
    :initarg :first_area
    :type cl:integer
    :initform 0)
   (second_area
    :reader second_area
    :initarg :second_area
    :type cl:integer
    :initform 0)
   (is_dest
    :reader is_dest
    :initarg :is_dest
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ReserveArea (<ReserveArea>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReserveArea>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReserveArea)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name agv_udp-msg:<ReserveArea> is deprecated: use agv_udp-msg:ReserveArea instead.")))

(cl:ensure-generic-function 'first_area-val :lambda-list '(m))
(cl:defmethod first_area-val ((m <ReserveArea>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader agv_udp-msg:first_area-val is deprecated.  Use agv_udp-msg:first_area instead.")
  (first_area m))

(cl:ensure-generic-function 'second_area-val :lambda-list '(m))
(cl:defmethod second_area-val ((m <ReserveArea>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader agv_udp-msg:second_area-val is deprecated.  Use agv_udp-msg:second_area instead.")
  (second_area m))

(cl:ensure-generic-function 'is_dest-val :lambda-list '(m))
(cl:defmethod is_dest-val ((m <ReserveArea>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader agv_udp-msg:is_dest-val is deprecated.  Use agv_udp-msg:is_dest instead.")
  (is_dest m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReserveArea>) ostream)
  "Serializes a message object of type '<ReserveArea>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'first_area)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'first_area)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'first_area)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'first_area)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'second_area)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'second_area)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'second_area)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'second_area)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_dest) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReserveArea>) istream)
  "Deserializes a message object of type '<ReserveArea>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'first_area)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'first_area)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'first_area)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'first_area)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'second_area)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'second_area)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'second_area)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'second_area)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'is_dest) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReserveArea>)))
  "Returns string type for a message object of type '<ReserveArea>"
  "agv_udp/ReserveArea")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReserveArea)))
  "Returns string type for a message object of type 'ReserveArea"
  "agv_udp/ReserveArea")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReserveArea>)))
  "Returns md5sum for a message object of type '<ReserveArea>"
  "c22270ab7b7fd72c83a94fc322460280")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReserveArea)))
  "Returns md5sum for a message object of type 'ReserveArea"
  "c22270ab7b7fd72c83a94fc322460280")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReserveArea>)))
  "Returns full string definition for message of type '<ReserveArea>"
  (cl:format cl:nil "uint32 first_area~%uint32 second_area~%bool is_dest~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReserveArea)))
  "Returns full string definition for message of type 'ReserveArea"
  (cl:format cl:nil "uint32 first_area~%uint32 second_area~%bool is_dest~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReserveArea>))
  (cl:+ 0
     4
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReserveArea>))
  "Converts a ROS message object to a list"
  (cl:list 'ReserveArea
    (cl:cons ':first_area (first_area msg))
    (cl:cons ':second_area (second_area msg))
    (cl:cons ':is_dest (is_dest msg))
))
