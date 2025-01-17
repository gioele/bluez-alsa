/*
 * BlueALSA - bluez.h
 * Copyright (c) 2016-2023 Arkadiusz Bokowy
 *
 * This file is a part of bluez-alsa.
 *
 * This project is licensed under the terms of the MIT license.
 *
 */

#pragma once
#ifndef BLUEALSA_BLUEZ_H_
#define BLUEALSA_BLUEZ_H_

#include <stdbool.h>

#include <glib.h>

#include "a2dp.h"
#include "ba-device.h"

#define BLUEZ_A2DP_VOLUME_MIN 0
#define BLUEZ_A2DP_VOLUME_MAX 127

enum bluez_a2dp_transport_state {
	BLUEZ_A2DP_TRANSPORT_STATE_IDLE,
	BLUEZ_A2DP_TRANSPORT_STATE_PENDING,
	BLUEZ_A2DP_TRANSPORT_STATE_ACTIVE,
};

int bluez_init(void);

bool bluez_a2dp_set_configuration(
		const char *dbus_current_sep_path,
		const struct a2dp_sep *sep,
		GError **error);

void bluez_battery_provider_update(
		struct ba_device *device);

#endif
