;; Auto-generated. Do not edit!


(when (boundp 'agv_udp::Replan)
  (if (not (find-package "AGV_UDP"))
    (make-package "AGV_UDP"))
  (shadow 'Replan (find-package "AGV_UDP")))
(unless (find-package "AGV_UDP::REPLAN")
  (make-package "AGV_UDP::REPLAN"))
(unless (find-package "AGV_UDP::REPLANREQUEST")
  (make-package "AGV_UDP::REPLANREQUEST"))
(unless (find-package "AGV_UDP::REPLANRESPONSE")
  (make-package "AGV_UDP::REPLANRESPONSE"))

(in-package "ROS")





(defclass agv_udp::ReplanRequest
  :super ros::object
  :slots (_replan _robot_index ))

(defmethod agv_udp::ReplanRequest
  (:init
   (&key
    ((:replan __replan) nil)
    ((:robot_index __robot_index) 0)
    )
   (send-super :init)
   (setq _replan __replan)
   (setq _robot_index (round __robot_index))
   self)
  (:replan
   (&optional __replan)
   (if __replan (setq _replan __replan)) _replan)
  (:robot_index
   (&optional __robot_index)
   (if __robot_index (setq _robot_index __robot_index)) _robot_index)
  (:serialization-length
   ()
   (+
    ;; bool _replan
    1
    ;; uint32 _robot_index
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _replan
       (if _replan (write-byte -1 s) (write-byte 0 s))
     ;; uint32 _robot_index
       (write-long _robot_index s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _replan
     (setq _replan (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint32 _robot_index
     (setq _robot_index (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass agv_udp::ReplanResponse
  :super ros::object
  :slots (_new_goal ))

(defmethod agv_udp::ReplanResponse
  (:init
   (&key
    ((:new_goal __new_goal) 0)
    )
   (send-super :init)
   (setq _new_goal (round __new_goal))
   self)
  (:new_goal
   (&optional __new_goal)
   (if __new_goal (setq _new_goal __new_goal)) _new_goal)
  (:serialization-length
   ()
   (+
    ;; uint32 _new_goal
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _new_goal
       (write-long _new_goal s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _new_goal
     (setq _new_goal (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass agv_udp::Replan
  :super ros::object
  :slots ())

(setf (get agv_udp::Replan :md5sum-) "e04b284656e20206941686c48843bad8")
(setf (get agv_udp::Replan :datatype-) "agv_udp/Replan")
(setf (get agv_udp::Replan :request) agv_udp::ReplanRequest)
(setf (get agv_udp::Replan :response) agv_udp::ReplanResponse)

(defmethod agv_udp::ReplanRequest
  (:response () (instance agv_udp::ReplanResponse :init)))

(setf (get agv_udp::ReplanRequest :md5sum-) "e04b284656e20206941686c48843bad8")
(setf (get agv_udp::ReplanRequest :datatype-) "agv_udp/ReplanRequest")
(setf (get agv_udp::ReplanRequest :definition-)
      "bool replan
uint32 robot_index
---
uint32 new_goal

")

(setf (get agv_udp::ReplanResponse :md5sum-) "e04b284656e20206941686c48843bad8")
(setf (get agv_udp::ReplanResponse :datatype-) "agv_udp/ReplanResponse")
(setf (get agv_udp::ReplanResponse :definition-)
      "bool replan
uint32 robot_index
---
uint32 new_goal

")



(provide :agv_udp/Replan "e04b284656e20206941686c48843bad8")


