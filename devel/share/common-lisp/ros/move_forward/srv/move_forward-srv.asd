
(cl:in-package :asdf)

(defsystem "move_forward-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "agv_call" :depends-on ("_package_agv_call"))
    (:file "_package_agv_call" :depends-on ("_package"))
  ))