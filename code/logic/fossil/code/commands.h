/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#ifndef FOSSIL_APP_COMMAND_H
#define FOSSIL_APP_COMMAND_H

#include <fossil/crabdb/framework.h>
#include <fossil/sys/framework.h>
#include <fossil/io/framework.h>

#define FOSSIL_APP_NAME "Crab Control"
#define FOSSIL_APP_VERSION "0.1.0"

#ifdef __cplusplus
extern "C" {
#endif

// Function prototypes for each command handler
/**
 * Command handlers for the Fossil Logic application.
 * Each function corresponds to a specific command that the application can process.
 */

// Displays help information for available commands
void handle_help(void);

// Displays the application version
void handle_version(void);

// Displays the application name
void handle_name(void);

// Scans the specified node
void handle_scan(ccstring node);

// Displays the status of the application
void handle_status(void);

// Displays detailed information about the specified node
void handle_info(ccstring node);

// Deploys the application or a specific component
void handle_deploy(void);

// Executes a query operation
void handle_query(void);

// Executes a command
void handle_exec(void);

// Synchronizes data across nodes
void handle_sync(void);

// Retrieves application logs
void handle_logs(void);

// Executes a spider script on the specified node
void handle_spider(ccstring script);

// Pushes data to the specified database and node
void handle_push(ccstring db, ccstring node);

// Pulls data from the specified database and node
void handle_pull(ccstring db, ccstring node);

// Starts up the specified node
void handle_startup(ccstring node);

// Restarts the specified node
void handle_restart(ccstring node);

// Shuts down the specified node
void handle_shutdown(ccstring node);

// Retrieves application metrics
void handle_metrics(void);

// Pings the specified node to check connectivity
void handle_ping(ccstring node);

// Sets a configuration key to a specified value
void handle_set(ccstring key, ccstring val);

// Gets the value of a specified configuration key
void handle_get(ccstring key);

// Adds a new node with the specified host
void handle_nodes_add(ccstring host);

// Removes a node with the specified host
void handle_nodes_remove(ccstring host);

// Lists all nodes in the network
void handle_nodes_list(void);

// Authenticates the specified node
void handle_auth(ccstring node);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_APP_CODE_H */
