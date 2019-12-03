// Generated by gencpp from file agv_udp/ReserveArea.msg
// DO NOT EDIT!


#ifndef AGV_UDP_MESSAGE_RESERVEAREA_H
#define AGV_UDP_MESSAGE_RESERVEAREA_H


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
struct ReserveArea_
{
  typedef ReserveArea_<ContainerAllocator> Type;

  ReserveArea_()
    : first_area(0)
    , second_area(0)
    , is_dest(false)  {
    }
  ReserveArea_(const ContainerAllocator& _alloc)
    : first_area(0)
    , second_area(0)
    , is_dest(false)  {
  (void)_alloc;
    }



   typedef uint32_t _first_area_type;
  _first_area_type first_area;

   typedef uint32_t _second_area_type;
  _second_area_type second_area;

   typedef uint8_t _is_dest_type;
  _is_dest_type is_dest;





  typedef boost::shared_ptr< ::agv_udp::ReserveArea_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::agv_udp::ReserveArea_<ContainerAllocator> const> ConstPtr;

}; // struct ReserveArea_

typedef ::agv_udp::ReserveArea_<std::allocator<void> > ReserveArea;

typedef boost::shared_ptr< ::agv_udp::ReserveArea > ReserveAreaPtr;
typedef boost::shared_ptr< ::agv_udp::ReserveArea const> ReserveAreaConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::agv_udp::ReserveArea_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::agv_udp::ReserveArea_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::agv_udp::ReserveArea_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::agv_udp::ReserveArea_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::agv_udp::ReserveArea_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::agv_udp::ReserveArea_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::agv_udp::ReserveArea_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::agv_udp::ReserveArea_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::agv_udp::ReserveArea_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c22270ab7b7fd72c83a94fc322460280";
  }

  static const char* value(const ::agv_udp::ReserveArea_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc22270ab7b7fd72cULL;
  static const uint64_t static_value2 = 0x83a94fc322460280ULL;
};

template<class ContainerAllocator>
struct DataType< ::agv_udp::ReserveArea_<ContainerAllocator> >
{
  static const char* value()
  {
    return "agv_udp/ReserveArea";
  }

  static const char* value(const ::agv_udp::ReserveArea_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::agv_udp::ReserveArea_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 first_area\n"
"uint32 second_area\n"
"bool is_dest\n"
;
  }

  static const char* value(const ::agv_udp::ReserveArea_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::agv_udp::ReserveArea_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.first_area);
      stream.next(m.second_area);
      stream.next(m.is_dest);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReserveArea_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::agv_udp::ReserveArea_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::agv_udp::ReserveArea_<ContainerAllocator>& v)
  {
    s << indent << "first_area: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.first_area);
    s << indent << "second_area: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.second_area);
    s << indent << "is_dest: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.is_dest);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AGV_UDP_MESSAGE_RESERVEAREA_H