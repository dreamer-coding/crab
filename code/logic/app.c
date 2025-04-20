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
#include "fossil/code/app.h"


bool app_entry(int argc, char** argv) {
    if (argc < 2) {
        fossil_io_printf("{blue,bold}Usage: crabctl <command> [options]{reset}\n");
        return EXIT_FAILURE;
    }

    // The first argument is the command
    const char *command = argv[1];

    // Parse the command
    if (fossil_io_cstring_compare(command, "--help") == 0) {
        handle_help();
    } else if (fossil_io_cstring_compare(command, "--version") == 0) {
        handle_version();
    } else if (fossil_io_cstring_compare(command, "--name") == 0) {
        handle_name();
    } else if (fossil_io_cstring_compare(command, "scan") == 0 && argc > 2) {
        handle_scan(argv[2]);
    } else if (fossil_io_cstring_compare(command, "status") == 0) {
        handle_status();
    } else if (fossil_io_cstring_compare(command, "info") == 0 && argc > 2) {
        handle_info(argv[2]);
    } else if (fossil_io_cstring_compare(command, "deploy") == 0) {
        handle_deploy();
    } else if (fossil_io_cstring_compare(command, "query") == 0) {
        handle_query();
    } else if (fossil_io_cstring_compare(command, "exec") == 0) {
        handle_exec();
    } else if (fossil_io_cstring_compare(command, "sync") == 0) {
        handle_sync();
    } else if (fossil_io_cstring_compare(command, "logs") == 0) {
        handle_logs();
    } else if (fossil_io_cstring_compare(command, "spider") == 0 && argc > 2) {
        handle_spider(argv[2]);
    } else if (fossil_io_cstring_compare(command, "push") == 0 && argc > 3) {
        handle_push(argv[2], argv[3]);
    } else if (fossil_io_cstring_compare(command, "pull") == 0 && argc > 3) {
        handle_pull(argv[2], argv[3]);
    } else if (fossil_io_cstring_compare(command, "startup") == 0 && argc > 2) {
        handle_startup(argv[2]);
    } else if (fossil_io_cstring_compare(command, "restart") == 0 && argc > 2) {
        handle_restart(argv[2]);
    } else if (fossil_io_cstring_compare(command, "shutdown") == 0 && argc > 2) {
        handle_shutdown(argv[2]);
    } else if (fossil_io_cstring_compare(command, "metrics") == 0) {
        handle_metrics();
    } else if (fossil_io_cstring_compare(command, "ping") == 0 && argc > 2) {
        handle_ping(argv[2]);
    } else if (fossil_io_cstring_compare(command, "set") == 0 && argc > 3) {
        handle_set(argv[2], argv[3]);
    } else if (fossil_io_cstring_compare(command, "get") == 0 && argc > 2) {
        handle_get(argv[2]);
    } else if (fossil_io_cstring_compare(command, "nodes") == 0) {
        if (argc > 3) {
            if (fossil_io_cstring_compare(argv[2], "add") == 0) {
                handle_nodes_add(argv[3]);
            } else if (fossil_io_cstring_compare(argv[2], "remove") == 0) {
                handle_nodes_remove(argv[3]);
            }
        } else if (argc == 3 && fossil_io_cstring_compare(argv[2], "list") == 0) {
            handle_nodes_list();
        }
    } else if (fossil_io_cstring_compare(command, "auth") == 0 && argc > 2) {
        handle_auth(argv[2]);
    } else {
        fossil_io_printf("Unknown command: %s\n", command);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
