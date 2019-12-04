;; Auto-generated. Do not edit!


(when (boundp 'agv_udp::CenterCmd)
  (if (not (find-package "AGV_UDP"))
    (make-package "AGV_UDP"))
  (shadow 'CenterCmd (find-package "AGV_UDP")))
(unless (find-package "AGV_UDP::CENTERCMD")
  (make-package "AGV_UDP::CENTERCMD"))

(in-package "ROS")
;;//! \htmlinclude CenterCmd.msg.html


(defclass agv_udp::CenterCmd
  :super ros::object
  :slots (_replan _reserve_area_first _reserve_area_second ))

(defmethod agv_udp::CenterCmd
  (:init
   (&key
    ((:replan __replan) (let (r) (dotimes (i 0) (push nil r)) r))
    ((:reserve_area_first __reserve_area_first) (make-array 0 :initial-element 0 :element-type :integer))
    ((:reserve_area_second __reserve_area_second) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _replan __replan)
   (setq _reserve_area_first __reserve_area_first)
   (setq _reserve_area_second __reserve_area_second)
   self)
  (:replan
   (&optional __replan)
   (if __replan (setq _replan __replan)) _replan)
  (:reserve_area_first
   (&optional __reserve_area_first)
   (if __reserve_area_first (setq _reserve_area_first __reserve_area_first)) _reserve_area_first)
  (:reserve_area_second
   (&optional __reserve_area_second)
   (if __reserve_area_second (setq _reserve_area_second __reserve_area_second)) _reserve_area_second)
  (:serialization-length
   ()
   (+
    ;; bool[] _replan
    (* 1    (length _replan)) 4
    ;; int32[] _reserve_area_first
    (* 4    (length _reserve_area_first)) 4
    ;; int32[] _reserve_area_second
    (* 4    (length _reserve_area_second)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool[] _replan
     (write-long (length _replan) s)
     (dotimes (i (length _replan))
       (if (elt _replan i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; int32[] _reserve_area_first
     (write-long (length _reserve_area_first) s)
     (dotimes (i (length _reserve_area_first))
       (write-long (elt _reserve_area_first i) s)
       )
     ;; int32[] _reserve_area_second
     (write-long (length _reserve_area_second) s)
     (dotimes (i (length _reserve_area_second))
       (write-long (elt _reserve_area_second i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool[] _replan
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _replan (make-list n))
     (dotimes (i n)
     (setf (elt _replan i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     ))
   ;; int32[] _reserve_area_first
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _reserve_area_first (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _reserve_area_first i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int32[] _reserve_area_second
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _reserve_area_second (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _reserve_area_second i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get agv_udp::CenterCmd :md5sum-) "1f2758a33326e770ef3efda627a683a4")
(setf (get agv_udp::CenterCmd :datatype-) "agv_udp/CenterCmd")
(setf (get agv_udp::CenterCmd :definition-)
      "bool[]  replan
int32[] reserve_area_first
int32[] reserve_area_second

")



(provide :agv_udp/CenterCmd "1f2758a33326e770ef3efda627a683a4")


