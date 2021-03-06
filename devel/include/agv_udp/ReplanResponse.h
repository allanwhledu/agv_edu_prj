// Generated by gencpp from file agv_udp/ReplanResponse.msg
// DO NOT EDIT!


#ifndef AGV_UDP_MESSAGE_REPLANRESPONSE_H
#define AGV_UDP_MESSAGE_REPLANRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace agv_udp
{
template <class ContainerAllocator>
struct ReplanResponse_
{
  typedef ReplanResponse_<ContainerAllocator> Type;

  ReplanResponse_()
    : new_goal(0)  {
    }
  ReplanResponse_(const ContainerAllocator& _alloc)
    : new_goal(0)  {
  (void)_alloc;
    }



   typedef uint32_t _new_goal_type;
  _new_goal_type new_goal;





  typedef boost::shared_ptr< ::agv_udp::ReplanResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::agv_udp::ReplanResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ReplanResponse_

typedef ::agv_udp::ReplanResponse_<std::allocator<void> > ReplanResponse;

typedef boost::shared_ptr< ::agv_udp::ReplanResponse > ReplanResponsePtr;
typedef boost::shared_ptr< ::agv_udp::ReplanResponse const> ReplanResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::agv_udp::ReplanResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::agv_udp::ReplanResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace agv_udp

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'agv_udp': ['/home/sjtuwhl/ROBOTLAB_WS/src/agv_udp/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::agv_udp::ReplanResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::agv_udp::ReplanResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::agv_udp::ReplanResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::agv_udp::ReplanResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::agv_udp::ReplanResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::agv_udp::ReplanResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::agv_udp::ReplanResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "69d0dd20ad906bb6e1e367ea883b4903";
  }

  static const char* value(const ::agv_udp::ReplanResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x69d0dd20ad906bb6ULL;
  static const uint64_t static_value2 = 0xe1e367ea883b4903ULL;
};

template<class ContainerAllocator>
struct DataType< ::agv_udp::ReplanResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "agv_udp/ReplanResponse";
  }

  static const char* value(const ::agv_udp::ReplanResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::agv_udp::ReplanResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 new_goal\n"
"\n"
;
  }

  static const char* value(const ::agv_udp::ReplanResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::agv_udp::ReplanResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.new_goal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReplanResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::agv_udp::ReplanResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::agv_udp::ReplanResponse_<ContainerAllocator>& v)
  {
    s << indent << "new_goal: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.new_goal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AGV_UDP_MESSAGE_REPLANRESPONSE_H
