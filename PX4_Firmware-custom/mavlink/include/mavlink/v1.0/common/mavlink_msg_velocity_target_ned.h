#pragma once
// MESSAGE VELOCITY_TARGET_NED PACKING

#define MAVLINK_MSG_ID_VELOCITY_TARGET_NED 220

MAVPACKED(
typedef struct __mavlink_velocity_target_ned_t
{
 uint32_t time_boot_ms; /*< Timestamp in milliseconds since system boot*/
 float vx; /*< X velocity in NED frame in meter / s*/
 float vy; /*< Y velocity in NED frame in meter / s*/
 float vz; /*< Z velocity in NED frame in meter / s*/
}) mavlink_velocity_target_ned_t;

#define MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN 16
#define MAVLINK_MSG_ID_VELOCITY_TARGET_NED_MIN_LEN 16
#define MAVLINK_MSG_ID_220_LEN 16
#define MAVLINK_MSG_ID_220_MIN_LEN 16

#define MAVLINK_MSG_ID_VELOCITY_TARGET_NED_CRC 213
#define MAVLINK_MSG_ID_220_CRC 213



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VELOCITY_TARGET_NED { \
	220, \
	"VELOCITY_TARGET_NED", \
	4, \
	{  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_velocity_target_ned_t, time_boot_ms) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_velocity_target_ned_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_velocity_target_ned_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_velocity_target_ned_t, vz) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VELOCITY_TARGET_NED { \
	"VELOCITY_TARGET_NED", \
	4, \
	{  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_velocity_target_ned_t, time_boot_ms) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_velocity_target_ned_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_velocity_target_ned_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_velocity_target_ned_t, vz) }, \
         } \
}
#endif

/**
 * @brief Pack a velocity_target_ned message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp in milliseconds since system boot
 * @param vx X velocity in NED frame in meter / s
 * @param vy Y velocity in NED frame in meter / s
 * @param vz Z velocity in NED frame in meter / s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_velocity_target_ned_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time_boot_ms, float vx, float vy, float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN];
	_mav_put_uint32_t(buf, 0, time_boot_ms);
	_mav_put_float(buf, 4, vx);
	_mav_put_float(buf, 8, vy);
	_mav_put_float(buf, 12, vz);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN);
#else
	mavlink_velocity_target_ned_t packet;
	packet.time_boot_ms = time_boot_ms;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VELOCITY_TARGET_NED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_CRC);
}

/**
 * @brief Pack a velocity_target_ned message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Timestamp in milliseconds since system boot
 * @param vx X velocity in NED frame in meter / s
 * @param vy Y velocity in NED frame in meter / s
 * @param vz Z velocity in NED frame in meter / s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_velocity_target_ned_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time_boot_ms,float vx,float vy,float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN];
	_mav_put_uint32_t(buf, 0, time_boot_ms);
	_mav_put_float(buf, 4, vx);
	_mav_put_float(buf, 8, vy);
	_mav_put_float(buf, 12, vz);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN);
#else
	mavlink_velocity_target_ned_t packet;
	packet.time_boot_ms = time_boot_ms;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VELOCITY_TARGET_NED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_CRC);
}

/**
 * @brief Encode a velocity_target_ned struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param velocity_target_ned C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_velocity_target_ned_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_velocity_target_ned_t* velocity_target_ned)
{
	return mavlink_msg_velocity_target_ned_pack(system_id, component_id, msg, velocity_target_ned->time_boot_ms, velocity_target_ned->vx, velocity_target_ned->vy, velocity_target_ned->vz);
}

/**
 * @brief Encode a velocity_target_ned struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param velocity_target_ned C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_velocity_target_ned_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_velocity_target_ned_t* velocity_target_ned)
{
	return mavlink_msg_velocity_target_ned_pack_chan(system_id, component_id, chan, msg, velocity_target_ned->time_boot_ms, velocity_target_ned->vx, velocity_target_ned->vy, velocity_target_ned->vz);
}

/**
 * @brief Send a velocity_target_ned message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms Timestamp in milliseconds since system boot
 * @param vx X velocity in NED frame in meter / s
 * @param vy Y velocity in NED frame in meter / s
 * @param vz Z velocity in NED frame in meter / s
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_velocity_target_ned_send(mavlink_channel_t chan, uint32_t time_boot_ms, float vx, float vy, float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN];
	_mav_put_uint32_t(buf, 0, time_boot_ms);
	_mav_put_float(buf, 4, vx);
	_mav_put_float(buf, 8, vy);
	_mav_put_float(buf, 12, vz);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_TARGET_NED, buf, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_CRC);
#else
	mavlink_velocity_target_ned_t packet;
	packet.time_boot_ms = time_boot_ms;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_TARGET_NED, (const char *)&packet, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_CRC);
#endif
}

/**
 * @brief Send a velocity_target_ned message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_velocity_target_ned_send_struct(mavlink_channel_t chan, const mavlink_velocity_target_ned_t* velocity_target_ned)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_velocity_target_ned_send(chan, velocity_target_ned->time_boot_ms, velocity_target_ned->vx, velocity_target_ned->vy, velocity_target_ned->vz);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_TARGET_NED, (const char *)velocity_target_ned, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_CRC);
#endif
}

#if MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_velocity_target_ned_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, float vx, float vy, float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time_boot_ms);
	_mav_put_float(buf, 4, vx);
	_mav_put_float(buf, 8, vy);
	_mav_put_float(buf, 12, vz);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_TARGET_NED, buf, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_CRC);
#else
	mavlink_velocity_target_ned_t *packet = (mavlink_velocity_target_ned_t *)msgbuf;
	packet->time_boot_ms = time_boot_ms;
	packet->vx = vx;
	packet->vy = vy;
	packet->vz = vz;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_TARGET_NED, (const char *)packet, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_CRC);
#endif
}
#endif

#endif

// MESSAGE VELOCITY_TARGET_NED UNPACKING


/**
 * @brief Get field time_boot_ms from velocity_target_ned message
 *
 * @return Timestamp in milliseconds since system boot
 */
static inline uint32_t mavlink_msg_velocity_target_ned_get_time_boot_ms(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field vx from velocity_target_ned message
 *
 * @return X velocity in NED frame in meter / s
 */
static inline float mavlink_msg_velocity_target_ned_get_vx(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field vy from velocity_target_ned message
 *
 * @return Y velocity in NED frame in meter / s
 */
static inline float mavlink_msg_velocity_target_ned_get_vy(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field vz from velocity_target_ned message
 *
 * @return Z velocity in NED frame in meter / s
 */
static inline float mavlink_msg_velocity_target_ned_get_vz(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a velocity_target_ned message into a struct
 *
 * @param msg The message to decode
 * @param velocity_target_ned C-struct to decode the message contents into
 */
static inline void mavlink_msg_velocity_target_ned_decode(const mavlink_message_t* msg, mavlink_velocity_target_ned_t* velocity_target_ned)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	velocity_target_ned->time_boot_ms = mavlink_msg_velocity_target_ned_get_time_boot_ms(msg);
	velocity_target_ned->vx = mavlink_msg_velocity_target_ned_get_vx(msg);
	velocity_target_ned->vy = mavlink_msg_velocity_target_ned_get_vy(msg);
	velocity_target_ned->vz = mavlink_msg_velocity_target_ned_get_vz(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN? msg->len : MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN;
        memset(velocity_target_ned, 0, MAVLINK_MSG_ID_VELOCITY_TARGET_NED_LEN);
	memcpy(velocity_target_ned, _MAV_PAYLOAD(msg), len);
#endif
}
