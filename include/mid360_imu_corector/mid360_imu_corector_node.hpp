#ifndef MID360_IMU_CORECTOR__MID360_IMU_CORECTOR_NODE_HPP_
#define MID360_IMU_CORECTOR__MID360_IMU_CORECTOR_NODE_HPP_

#include <string>

#include "mid360_imu_corector/visibility.hpp"
#include "rclcpp/node.hpp"
#include "sensor_msgs/msg/imu.hpp"

namespace mid360_imu_corector
{

class Mid360ImuCorector : public rclcpp::Node
{
private:
  using ImuMsg = sensor_msgs::msg::Imu;

public:
  static constexpr auto kDefaultNodeName = "mid360_imu_corector";

  MID360_IMU_CORECTOR_PUBLIC
  Mid360ImuCorector(
    const std::string & node_name, const std::string & node_namespace,
    const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions());

  MID360_IMU_CORECTOR_PUBLIC
  explicit inline Mid360ImuCorector(
    const std::string & node_name, const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
  : Mid360ImuCorector(node_name, "", node_options)
  {
  }

  MID360_IMU_CORECTOR_PUBLIC
  explicit inline Mid360ImuCorector(
    const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
  : Mid360ImuCorector(kDefaultNodeName, "", node_options)
  {
  }

  void CorectImu(ImuMsg::UniquePtr imu_msg);

private:
  // 重力加速度
  double gravity_;

  // Subscriber and publisher
  rclcpp::Subscription<ImuMsg>::SharedPtr imu_raw_subscription_;
  rclcpp::Publisher<ImuMsg>::SharedPtr imu_publisher_;
};

}  // namespace mid360_imu_corector

#endif  // MID360_IMU_CORECTOR__MID360_IMU_CORECTOR_NODE_HPP_
