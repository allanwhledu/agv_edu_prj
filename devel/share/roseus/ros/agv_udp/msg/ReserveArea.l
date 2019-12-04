;; Auto-generated. Do not edit!


(when (boundp 'agv_udp::ReserveArea)
  (if (not (find-package "AGV_UDP"))
    (make-package "AGV_UDP"))
  (shadow 'ReserveArea (find-package "AGV_UDP")))
(unless (find-package "AGV_UDP::RESERVEAREA")
  (make-package "AGV_UDP::RESERVEAREA"))

(in-package "ROS")
;;//! \htmlinclude ReserveArea.msg.html


(defclass agv_udp::ReserveArea
  :super ros::object
  :slots (_first_area _second_area _is_dest ))

(defmethod agv_udp::ReserveArea
  (:init
   (&key
    ((:first_area __first_area) 0)
    ((:second_area __second_area) 0)
    ((:is_dest __is_dest) nil)
    )
   (send-super :init)
   (setq _first_area (round __first_area))
   (setq _second_area (round __second_area))
   (setq _is_dest __is_dest)
   self)
  (:first_area
   (&optional __first_area)
   (if __first_area (setq _first_area __first_area)) _first_area)
  (:second_area
   (&optional __second_area)
   (if __second_area (setq _second_area __second_area)) _second_area)
  (:is_dest
   (&optional __is_dest)
   (if __is_dest (setq _is_dest __is_dest)) _is_dest)
  (:serialization-length
   ()
   (+
    ;; uint32 _first_area
    4
    ;; uint32 _second_area
    4
    ;; bool _is_dest
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _first_area
       (write-long _first_area s)
     ;; uint32 _second_area
       (write-long _second_area s)
     ;; bool _is_dest
       (if _is_dest (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _first_area
     (setq _first_area (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _second_area
     (setq _second_area (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _is_dest
     (setq _is_dest (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get agv_udp::ReserveArea :md5sum-) "c22270ab7b7fd72c83a94fc322460280")
(setf (get agv_udp::ReserveArea :datatype-) "agv_udp/ReserveArea")
(setf (get agv_udp::ReserveArea :definition-)
      "uint32 first_area
uint32 second_area
bool is_dest

")



(provide :agv_udp/ReserveArea "c22270ab7b7fd72c83a94fc322460280")


