; Auto-generated. Do not edit!


(cl:in-package agv_udp-msg)


;//! \htmlinclude CenterCmd.msg.html

(cl:defclass <CenterCmd> (roslisp-msg-protocol:ros-message)
  ((replan
    :reader replan
    :initarg :replan
    :type (cl:vector cl:boolean)
   :initform (cl:make-array 0 :element-type 'cl:boolean :initial-element cl:nil))
   (reserve_area_first
    :reader reserve_area_first
    :initarg :reserve_area_first
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (reserve_area_second
    :reader reserve_area_second
    :initarg :reserve_area_second
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass CenterCmd (<CenterCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CenterCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CenterCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name agv_udp-msg:<CenterCmd> is deprecated: use agv_udp-msg:CenterCmd instead.")))

(cl:ensure-generic-function 'replan-val :lambda-list '(m))
(cl:defmethod replan-val ((m <CenterCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader agv_udp-msg:replan-val is deprecated.  Use agv_udp-msg:replan instead.")
  (replan m))

(cl:ensure-generic-function 'reserve_area_first-val :lambda-list '(m))
(cl:defmethod reserve_area_first-val ((m <CenterCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader agv_udp-msg:reserve_area_first-val is deprecated.  Use agv_udp-msg:reserve_area_first instead.")
  (reserve_area_first m))

(cl:ensure-generic-function 'reserve_area_second-val :lambda-list '(m))
(cl:defmethod reserve_area_second-val ((m <CenterCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader agv_udp-msg:reserve_area_second-val is deprecated.  Use agv_udp-msg:reserve_area_second instead.")
  (reserve_area_second m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CenterCmd>) ostream)
  "Serializes a message object of type '<CenterCmd>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'replan))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if ele 1 0)) ostream))
   (cl:slot-value msg 'replan))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'reserve_area_first))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'reserve_area_first))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'reserve_area_second))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'reserve_area_second))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CenterCmd>) istream)
  "Deserializes a message object of type '<CenterCmd>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'replan) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'replan)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:not (cl:zerop (cl:read-byte istream)))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'reserve_area_first) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'reserve_area_first)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'reserve_area_second) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'reserve_area_second)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CenterCmd>)))
  "Returns string type for a message object of type '<CenterCmd>"
  "agv_udp/CenterCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CenterCmd)))
  "Returns string type for a message object of type 'CenterCmd"
  "agv_udp/CenterCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CenterCmd>)))
  "Returns md5sum for a message object of type '<CenterCmd>"
  "1f2758a33326e770ef3efda627a683a4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CenterCmd)))
  "Returns md5sum for a message object of type 'CenterCmd"
  "1f2758a33326e770ef3efda627a683a4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CenterCmd>)))
  "Returns full string definition for message of type '<CenterCmd>"
  (cl:format cl:nil "bool[]  replan~%int32[] reserve_area_first~%int32[] reserve_area_second~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CenterCmd)))
  "Returns full string definition for message of type 'CenterCmd"
  (cl:format cl:nil "bool[]  replan~%int32[] reserve_area_first~%int32[] reserve_area_second~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CenterCmd>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'replan) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'reserve_area_first) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'reserve_area_second) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CenterCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'CenterCmd
    (cl:cons ':replan (replan msg))
    (cl:cons ':reserve_area_first (reserve_area_first msg))
    (cl:cons ':reserve_area_second (reserve_area_second msg))
))
