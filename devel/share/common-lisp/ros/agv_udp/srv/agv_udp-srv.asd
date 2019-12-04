
(cl:in-package :asdf)

(defsystem "agv_udp-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Replan" :depends-on ("_package_Replan"))
    (:file "_package_Replan" :depends-on ("_package"))
  ))