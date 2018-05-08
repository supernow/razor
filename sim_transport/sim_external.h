/*-
* Copyright (c) 2017-2018 wenba, Inc.
*	All rights reserved.
*
* See the file LICENSE for redistribution information.
*/

#ifndef __sim_external_h_
#define __sim_external_h_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

enum{
	sim_connect_notify = 1000,
	sim_network_timout,
	sim_disconnect_notify,
	sim_start_play_notify,
	sim_stop_play_notify,
	net_interrupt_notify,
	net_recover_notify,
};

typedef void(*sim_notify_fn)(void* event, int type, uint32_t val);
typedef int(*sim_log_fn)(int level, const char* file, int line, const char* fmt, va_list vl);
typedef void(*sim_change_bitrate_fn)(void* event, uint32_t bw);
typedef void(*sim_state_fn)(void* event, uint32_t rbw, uint32_t sbw, int32_t rtt);

/*uid�Ǳ����û�ID�� port�Ǳ��ض˿��������ӶԷ�, event�������ϲ���ջص��¼�֪ͨ�Ķ���*/
void		sim_init(uint16_t port, void* event, sim_log_fn log_cb, sim_notify_fn notify_cb, sim_change_bitrate_fn change_bitrate_cb, sim_state_fn state_cb);
void		sim_destroy();

int			sim_connect(uint32_t local_uid, const char* peer_ip, uint16_t peer_port);
int			sim_disconnect();

/*����һ֡��Ƶ*/
int			sim_send_video(uint8_t ftype, const uint8_t* data, size_t size);
/*����һ֡��Ƶ��sizep�����ʼ��һ�����������ֵ����ֹ�������������*/
int			sim_recv_video(uint8_t* data, size_t* sizep);

void		sim_set_bitrates(uint32_t min_bitrate, uint32_t start_bitrate, uint32_t max_bitrate);

#ifdef __cplusplus
}
#endif

#endif


