#include "mid360_imu_corector/mid360_imu_corector_node.hpp"

namespace mid360_imu_corector
{

Mid360ImuCorectorNode::Mid360ImuCorectorNode(
  const std::string & node_name, const std::string & node_namespace,
  const rclcpp::NodeOptions & node_options)
: rclcpp::Node(node_name, node_namespace, node_options),
  gravity_(this->declare_parameter("gravity", 9.80511))
{
  // imuの変換
  imu_publisher_ = this->create_publisher<ImuMsg>("imu/data", rclcpp::QoS(1));

  const auto mid360_imu_corector = [this](ImuMsg::UniquePtr imu_msg) {
      this->CorectImu(std::move(imu_msg));
    };
  imu_raw_subscription_ =
    this->create_subscription<ImuMsg>("imu/data_raw", rclcpp::QoS(1), mid360_imu_corector);
}

void Mid360ImuCorectorNode::CorectImu(ImuMsg::UniquePtr imu_msg)
{
  // 重力加速度の補正
  imu_msg->linear_acceleration.x *= gravity_;
  imu_msg->linear_acceleration.y *= gravity_;
  imu_msg->linear_acceleration.z *= gravity_;

  // 地軸を固定
  imu_msg->orientation = geometry_msgs::msg::Quaternion();

  // imuのパブリッシュ
  imu_publisher_->publish(std::move(imu_msg));
}

}  // namespace mid360_imu_corector

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(mid360_imu_corector::Mid360ImuCorectorNode)
