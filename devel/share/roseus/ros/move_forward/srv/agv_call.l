;; Auto-generated. Do not edit!


(when (boundp 'move_forward::agv_call)
  (if (not (find-package "MOVE_FORWARD"))
    (make-package "MOVE_FORWARD"))
  (shadow 'agv_call (find-package "MOVE_FORWARD")))
(unless (find-package "MOVE_FORWARD::AGV_CALL")
  (make-package "MOVE_FORWARD::AGV_CALL"))
(unless (find-package "MOVE_FORWARD::AGV_CALLREQUEST")
  (make-package "MOVE_FORWARD::AGV_CALLREQUEST"))
(unless (find-package "MOVE_FORWARD::AGV_CALLRESPONSE")
  (make-package "MOVE_FORWARD::AGV_CALLRESPONSE"))

(in-package "ROS")





(defclass move_forward::agv_callRequest
  :super ros::object
  :slots (_action ))

(defmethod move_forward::agv_callRequest
  (:init
   (&key
    ((:action __action) 0)
    )
   (send-super :init)
   (setq _action (round __action))
   self)
  (:action
   (&optional __action)
   (if __action (setq _action __action)) _action)
  (:serialization-length
   ()
   (+
    ;; int64 _action
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _action
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _action (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _action) (= (length (_action . bv)) 2)) ;; bignum
              (write-long (ash (elt (_action . bv) 0) 0) s)
              (write-long (ash (elt (_action . bv) 1) -1) s))
             ((and (class _action) (= (length (_action . bv)) 1)) ;; big1
              (write-long (elt (_action . bv) 0) s)
              (write-long (if (>= _action 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _action s)(write-long (if (>= _action 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _action
#+(or :alpha :irix6 :x86_64)
      (setf _action (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _action (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(defclass move_forward::agv_callResponse
  :super ros::object
  :slots (_result ))

(defmethod move_forward::agv_callResponse
  (:init
   (&key
    ((:result __result) nil)
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; bool _result
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _result
       (if _result (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _result
     (setq _result (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass move_forward::agv_call
  :super ros::object
  :slots ())

(setf (get move_forward::agv_call :md5sum-) "bbdd7d6a90f6922f6aae5a0ca449c65d")
(setf (get move_forward::agv_call :datatype-) "move_forward/agv_call")
(setf (get move_forward::agv_call :request) move_forward::agv_callRequest)
(setf (get move_forward::agv_call :response) move_forward::agv_callResponse)

(defmethod move_forward::agv_callRequest
  (:response () (instance move_forward::agv_callResponse :init)))

(setf (get move_forward::agv_callRequest :md5sum-) "bbdd7d6a90f6922f6aae5a0ca449c65d")
(setf (get move_forward::agv_callRequest :datatype-) "move_forward/agv_callRequest")
(setf (get move_forward::agv_callRequest :definition-)
      "int64 action
---
bool result

")

(setf (get move_forward::agv_callResponse :md5sum-) "bbdd7d6a90f6922f6aae5a0ca449c65d")
(setf (get move_forward::agv_callResponse :datatype-) "move_forward/agv_callResponse")
(setf (get move_forward::agv_callResponse :definition-)
      "int64 action
---
bool result

")



(provide :move_forward/agv_call "bbdd7d6a90f6922f6aae5a0ca449c65d")


