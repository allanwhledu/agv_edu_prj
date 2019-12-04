
(cl:in-package :asdf)

(defsystem "agv_udp-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "CenterCmd" :depends-on ("_package_CenterCmd"))
    (:file "_package_CenterCmd" :depends-on ("_package"))
    (:file "ReserveArea" :depends-on ("_package_ReserveArea"))
    (:file "_package_ReserveArea" :depends-on ("_package"))
  ))