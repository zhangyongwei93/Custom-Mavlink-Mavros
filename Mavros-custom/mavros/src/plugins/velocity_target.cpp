/*
Publish Target Velocity values in Offboard Position Mode
@author zhangyongwei
 */

#include <mavros/mavros_plugin.h>
#include <pluginlib/class_list_macros.h>

#include <mavros_msgs/VelocityTarget.h>

namespace mavplugin {
/**
 * @brief VelocityTarget plugin.
 */
class VelocityTargetPlugin : public MavRosPlugin {
public:
    VelocityTargetPlugin() :
        nh("~"),
        uas(nullptr)
    { }

    /**
     * Plugin initializer. Constructor should not do this.
     */
    void initialize(UAS &uas_)
    {
        uas = &uas_;
        nh.param<std::string>("frame_id", frame_id, "map");
        velocity_target_pub = nh.advertise<mavros_msgs::VelocityTarget>("velocity_target", 10);

    //ROS_INFO_STREAM("********** Initialize ***************");
    }

    const message_map get_rx_handlers() {       
    //ROS_INFO_STREAM("********** Enter Handle ***************");
    //ROS_INFO("***** Mavlink ID:[%d]",MAVLINK_MSG_ID_VELOCITY_TARGET_NED);
        return {
                   MESSAGE_HANDLER(MAVLINK_MSG_ID_VELOCITY_TARGET_NED, &VelocityTargetPlugin::handle_velocity_target)
        };
    }

private:
    ros::NodeHandle nh;
    UAS *uas;
    std::string frame_id;

    ros::Publisher velocity_target_pub;

    void handle_velocity_target(const mavlink_message_t *msg, uint8_t sysid, uint8_t compid) {
        
     //ROS_INFO_STREAM("******************* Begin Handle *********************");

        mavlink_velocity_target_ned_t velocity_target;
        mavlink_msg_velocity_target_ned_decode(msg, &velocity_target);

        auto ros_msg = boost::make_shared<mavros_msgs::VelocityTarget>();

        ros_msg->header = uas->synchronized_header(frame_id, velocity_target.time_boot_ms);

		ros_msg->vx = velocity_target.vx;
		ros_msg->vy = velocity_target.vy;
		ros_msg->vz = velocity_target.vz;

        velocity_target_pub.publish(ros_msg);

        //ROS_INFO("***** vx,vy,vz:[%0.3f,%0.3f,%0.3f]",ros_msg->vx,ros_msg->vy,ros_msg->vz);
    }

};
};  // namespace mavplugin

PLUGINLIB_EXPORT_CLASS(mavplugin::VelocityTargetPlugin, mavplugin::MavRosPlugin)