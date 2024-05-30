#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/common.h"
#include "../include/cgiutils.h"


#define ALT_CMD_DEF(name)

#define CMD_DEF(name, cmd_opt, dflt_comment) \
	{ #name, CMD_ ## name, cmd_opt, dflt_comment }
/*	{ #name, sizeof(#name) - 1, CMD_ ## name, min_args, handler, NULL } */
struct nagios_extcmd in_core_commands[] = {
	CMD_DEF(NONE, 0, NULL),
	CMD_DEF(ADD_HOST_COMMENT, 2, NULL),
	CMD_DEF(DEL_HOST_COMMENT, 0, NULL),
	CMD_DEF(ADD_SVC_COMMENT, 2, NULL),
	CMD_DEF(DEL_SVC_COMMENT, 0, NULL),
	CMD_DEF(ENABLE_SVC_CHECK, 0, NULL),
	CMD_DEF(DISABLE_SVC_CHECK, 0, NULL),
	CMD_DEF(SCHEDULE_SVC_CHECK, 0, NULL),
	CMD_DEF(DELAY_SVC_NOTIFICATION, 0, NULL),
	CMD_DEF(DELAY_HOST_NOTIFICATION, 0, NULL),
	CMD_DEF(DISABLE_NOTIFICATIONS, 0, NULL),
	CMD_DEF(ENABLE_NOTIFICATIONS, 0, NULL),
	CMD_DEF(RESTART_PROCESS, 0, NULL),
	CMD_DEF(SHUTDOWN_PROCESS, 0, NULL),
	CMD_DEF(ENABLE_HOST_SVC_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_HOST_SVC_CHECKS, 0, NULL),
	CMD_DEF(SCHEDULE_HOST_SVC_CHECKS, 0, NULL),
	CMD_DEF(DELAY_HOST_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DEL_ALL_HOST_COMMENTS, 0, NULL),
	CMD_DEF(DEL_ALL_SVC_COMMENTS, 0, NULL),
	CMD_DEF(ENABLE_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(ENABLE_HOST_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_HOST_NOTIFICATIONS, 0, NULL),
	CMD_DEF(ENABLE_ALL_NOTIFICATIONS_BEYOND_HOST, 0, NULL),
	CMD_DEF(DISABLE_ALL_NOTIFICATIONS_BEYOND_HOST, 0, NULL),
	CMD_DEF(ENABLE_HOST_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_HOST_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(PROCESS_SERVICE_CHECK_RESULT, 0, NULL),
	CMD_DEF(SAVE_STATE_INFORMATION, 0, NULL),
	CMD_DEF(READ_STATE_INFORMATION, 0, NULL),
	CMD_DEF(ACKNOWLEDGE_HOST_PROBLEM, 2, NULL),
	CMD_DEF(ACKNOWLEDGE_SVC_PROBLEM, 2, NULL),
	CMD_DEF(START_EXECUTING_SVC_CHECKS, 0, NULL),
	CMD_DEF(STOP_EXECUTING_SVC_CHECKS, 0, NULL),
	CMD_DEF(START_ACCEPTING_PASSIVE_SVC_CHECKS, 0, NULL),
	CMD_DEF(STOP_ACCEPTING_PASSIVE_SVC_CHECKS, 0, NULL),
	CMD_DEF(ENABLE_PASSIVE_SVC_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_PASSIVE_SVC_CHECKS, 0, NULL),
	CMD_DEF(ENABLE_EVENT_HANDLERS, 0, NULL),
	CMD_DEF(DISABLE_EVENT_HANDLERS, 0, NULL),
	CMD_DEF(ENABLE_HOST_EVENT_HANDLER, 0, NULL),
	CMD_DEF(DISABLE_HOST_EVENT_HANDLER, 0, NULL),
	CMD_DEF(ENABLE_SVC_EVENT_HANDLER, 0, NULL),
	CMD_DEF(DISABLE_SVC_EVENT_HANDLER, 0, NULL),
	CMD_DEF(ENABLE_HOST_CHECK, 0, NULL),
	CMD_DEF(DISABLE_HOST_CHECK, 0, NULL),
	CMD_DEF(START_OBSESSING_OVER_SVC_CHECKS, 0, NULL),
	CMD_DEF(STOP_OBSESSING_OVER_SVC_CHECKS, 0, NULL),
	CMD_DEF(REMOVE_HOST_ACKNOWLEDGEMENT, 0, NULL),
	CMD_DEF(REMOVE_SVC_ACKNOWLEDGEMENT, 0, NULL),
	CMD_DEF(SCHEDULE_FORCED_HOST_SVC_CHECKS, 0, NULL),
	CMD_DEF(SCHEDULE_FORCED_SVC_CHECK, 0, NULL),
	CMD_DEF(SCHEDULE_HOST_DOWNTIME, 2, NULL),
	CMD_DEF(SCHEDULE_SVC_DOWNTIME, 2, NULL),
	CMD_DEF(ENABLE_HOST_FLAP_DETECTION, 0, NULL),
	CMD_DEF(DISABLE_HOST_FLAP_DETECTION, 0, NULL),
	CMD_DEF(ENABLE_SVC_FLAP_DETECTION, 0, NULL),
	CMD_DEF(DISABLE_SVC_FLAP_DETECTION, 0, NULL),
	CMD_DEF(ENABLE_FLAP_DETECTION, 0, NULL),
	CMD_DEF(DISABLE_FLAP_DETECTION, 0, NULL),
	CMD_DEF(ENABLE_HOSTGROUP_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_HOSTGROUP_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(ENABLE_HOSTGROUP_HOST_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_HOSTGROUP_HOST_NOTIFICATIONS, 0, NULL),
	CMD_DEF(ENABLE_HOSTGROUP_SVC_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_HOSTGROUP_SVC_CHECKS, 0, NULL),
	CMD_DEF(DEL_HOST_DOWNTIME, 0, NULL),
	CMD_DEF(DEL_SVC_DOWNTIME, 0, NULL),
	CMD_DEF(ENABLE_PERFORMANCE_DATA, 0, NULL),
	CMD_DEF(DISABLE_PERFORMANCE_DATA, 0, NULL),
	CMD_DEF(SCHEDULE_HOSTGROUP_HOST_DOWNTIME, 2, NULL),
	CMD_DEF(SCHEDULE_HOSTGROUP_SVC_DOWNTIME, 2, NULL),
	CMD_DEF(SCHEDULE_HOST_SVC_DOWNTIME, 2, NULL),
	CMD_DEF(PROCESS_HOST_CHECK_RESULT, 0, NULL),
	CMD_DEF(START_EXECUTING_HOST_CHECKS, 0, NULL),
	CMD_DEF(STOP_EXECUTING_HOST_CHECKS, 0, NULL),
	CMD_DEF(START_ACCEPTING_PASSIVE_HOST_CHECKS, 0, NULL),
	CMD_DEF(STOP_ACCEPTING_PASSIVE_HOST_CHECKS, 0, NULL),
	CMD_DEF(ENABLE_PASSIVE_HOST_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_PASSIVE_HOST_CHECKS, 0, NULL),
	CMD_DEF(START_OBSESSING_OVER_HOST_CHECKS, 0, NULL),
	CMD_DEF(STOP_OBSESSING_OVER_HOST_CHECKS, 0, NULL),
	CMD_DEF(SCHEDULE_HOST_CHECK, 0, NULL),
	CMD_DEF(SCHEDULE_FORCED_HOST_CHECK, 0, NULL),
	CMD_DEF(SCHEDULE_FORCED_HOST_NOTIFICATION, 0, NULL),
	CMD_DEF(SCHEDULE_FORCED_SVC_NOTIFICATION, 0, NULL),
	CMD_DEF(START_OBSESSING_OVER_SVC, 0, NULL),
	CMD_DEF(STOP_OBSESSING_OVER_SVC, 0, NULL),
	CMD_DEF(START_OBSESSING_OVER_HOST, 0, NULL),
	CMD_DEF(STOP_OBSESSING_OVER_HOST, 0, NULL),
	CMD_DEF(ENABLE_HOSTGROUP_HOST_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_HOSTGROUP_HOST_CHECKS, 0, NULL),
	CMD_DEF(ENABLE_HOSTGROUP_PASSIVE_SVC_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_HOSTGROUP_PASSIVE_SVC_CHECKS, 0, NULL),
	CMD_DEF(ENABLE_HOSTGROUP_PASSIVE_HOST_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_HOSTGROUP_PASSIVE_HOST_CHECKS, 0, NULL),
	CMD_DEF(ENABLE_SERVICEGROUP_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_SERVICEGROUP_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(ENABLE_SERVICEGROUP_HOST_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_SERVICEGROUP_HOST_NOTIFICATIONS, 0, NULL),
	CMD_DEF(ENABLE_SERVICEGROUP_SVC_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_SERVICEGROUP_SVC_CHECKS, 0, NULL),
	CMD_DEF(ENABLE_SERVICEGROUP_HOST_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_SERVICEGROUP_HOST_CHECKS, 0, NULL),
	CMD_DEF(ENABLE_SERVICEGROUP_PASSIVE_SVC_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_SERVICEGROUP_PASSIVE_SVC_CHECKS, 0, NULL),
	CMD_DEF(ENABLE_SERVICEGROUP_PASSIVE_HOST_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_SERVICEGROUP_PASSIVE_HOST_CHECKS, 0, NULL),
	CMD_DEF(SCHEDULE_SERVICEGROUP_HOST_DOWNTIME, 2, NULL),
	CMD_DEF(SCHEDULE_SERVICEGROUP_SVC_DOWNTIME, 2, NULL),
	CMD_DEF(CHANGE_GLOBAL_HOST_EVENT_HANDLER, 0, NULL),
	CMD_DEF(CHANGE_GLOBAL_SVC_EVENT_HANDLER, 0, NULL),
	CMD_DEF(CHANGE_HOST_EVENT_HANDLER, 0, NULL),
	CMD_DEF(CHANGE_SVC_EVENT_HANDLER, 0, NULL),
	CMD_DEF(CHANGE_HOST_CHECK_COMMAND, 0, NULL),
	CMD_DEF(CHANGE_SVC_CHECK_COMMAND, 0, NULL),
	CMD_DEF(CHANGE_NORMAL_HOST_CHECK_INTERVAL, 0, NULL),
	CMD_DEF(CHANGE_NORMAL_SVC_CHECK_INTERVAL, 0, NULL),
	CMD_DEF(CHANGE_RETRY_SVC_CHECK_INTERVAL, 0, NULL),
	CMD_DEF(CHANGE_MAX_HOST_CHECK_ATTEMPTS, 0, NULL),
	CMD_DEF(CHANGE_MAX_SVC_CHECK_ATTEMPTS, 0, NULL),
	CMD_DEF(SCHEDULE_AND_PROPAGATE_TRIGGERED_HOST_DOWNTIME, 0, NULL),
	CMD_DEF(ENABLE_HOST_AND_CHILD_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_HOST_AND_CHILD_NOTIFICATIONS, 0, NULL),
	CMD_DEF(SCHEDULE_AND_PROPAGATE_HOST_DOWNTIME, 0, NULL),
	CMD_DEF(ENABLE_SERVICE_FRESHNESS_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_SERVICE_FRESHNESS_CHECKS, 0, NULL),
	CMD_DEF(ENABLE_HOST_FRESHNESS_CHECKS, 0, NULL),
	CMD_DEF(DISABLE_HOST_FRESHNESS_CHECKS, 0, NULL),
	CMD_DEF(SET_HOST_NOTIFICATION_NUMBER, 0, NULL),
	CMD_DEF(SET_SVC_NOTIFICATION_NUMBER, 0, NULL),
	CMD_DEF(CHANGE_HOST_CHECK_TIMEPERIOD, 0, NULL),
	CMD_DEF(CHANGE_SVC_CHECK_TIMEPERIOD, 0, NULL),
	CMD_DEF(PROCESS_FILE, 0, NULL),
	CMD_DEF(CHANGE_CUSTOM_HOST_VAR, 0, NULL),
	CMD_DEF(CHANGE_CUSTOM_SVC_VAR, 0, NULL),
	CMD_DEF(CHANGE_CUSTOM_CONTACT_VAR, 0, NULL),
	CMD_DEF(ENABLE_CONTACT_HOST_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_CONTACT_HOST_NOTIFICATIONS, 0, NULL),
	CMD_DEF(ENABLE_CONTACT_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_CONTACT_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(ENABLE_CONTACTGROUP_HOST_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_CONTACTGROUP_HOST_NOTIFICATIONS, 0, NULL),
	CMD_DEF(ENABLE_CONTACTGROUP_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(DISABLE_CONTACTGROUP_SVC_NOTIFICATIONS, 0, NULL),
	CMD_DEF(CHANGE_RETRY_HOST_CHECK_INTERVAL, 0, NULL),
	CMD_DEF(SEND_CUSTOM_HOST_NOTIFICATION, 2, NULL),
	CMD_DEF(SEND_CUSTOM_SVC_NOTIFICATION, 2, NULL),
	CMD_DEF(CHANGE_HOST_NOTIFICATION_TIMEPERIOD, 0, NULL),
	CMD_DEF(CHANGE_SVC_NOTIFICATION_TIMEPERIOD, 0, NULL),
	CMD_DEF(CHANGE_CONTACT_HOST_NOTIFICATION_TIMEPERIOD, 0, NULL),
	CMD_DEF(CHANGE_CONTACT_SVC_NOTIFICATION_TIMEPERIOD, 0, NULL),
	CMD_DEF(CHANGE_HOST_MODATTR, 0, NULL),
	CMD_DEF(CHANGE_SVC_MODATTR, 0, NULL),
	CMD_DEF(CHANGE_CONTACT_MODATTR, 0, NULL),
	CMD_DEF(CHANGE_CONTACT_MODHATTR, 0, NULL),
	CMD_DEF(CLEAR_HOST_FLAPPING_STATE, 0, NULL),
	CMD_DEF(CLEAR_SVC_FLAPPING_STATE, 0, NULL),
	};
#undef CMD_DEF

#ifndef ARRAY_SIZE
# define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#endif

struct nagios_extcmd* extcmd_get_command_id(int id)
{
	unsigned int i;

	for(i = 0; i < ARRAY_SIZE(in_core_commands); i++) {
		struct nagios_extcmd *ecmd;
		ecmd = &in_core_commands[i];
		if(ecmd->id == id)
			return ecmd;
		}

	return NULL;
}

struct nagios_extcmd* extcmd_get_command_name(const char *name)
{
	unsigned int i;

	for(i = 0; i < ARRAY_SIZE(in_core_commands); i++) {
		struct nagios_extcmd *ecmd;
		ecmd = &in_core_commands[i];
		if(!strcmp(ecmd->name, name))
			return ecmd;
		}

	return NULL;
}

const char *extcmd_get_name(int id) {
	struct nagios_extcmd *ecmd = extcmd_get_command_id(id);
	if (!ecmd)
		return NULL;
	return ecmd->name;
}
