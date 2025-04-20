# **crabctl** — Blue Crab Data Center CLI

**`crabctl`** is the official command-line interface for managing the **Blue Crab Data Center**, a scalable network of Raspberry Pi nodes running the CrabDB engine. It acts as a unified interface to control, monitor, and interact with `crabd` daemons over SSH, TCP, or local execution.

With a single CLI tool, you can **scan nodes**, **query distributed databases**, **deploy configs**, **sync data**, and even launch scripted automations via the `spider` command. Designed using the Fossil SDK and built with Meson, `crabctl` is lightweight, modular, and ideal for embedded systems and distributed local-first applications.

---

## 🔧 `crabctl` Command Reference

| Command                          | Description                                                                 |
|----------------------------------|-----------------------------------------------------------------------------|
| `crabctl --help`                 | Show usage and available subcommands                                        |
| `crabctl --version`              | Prints the current version number                                           |
| `crabctl scan <node>`            | Discover active `crabd` nodes on the network or via config                  |
| `crabctl status`                 | Show real-time status and health of all known nodes                         |
| `crabctl info <node>`            | View detailed diagnostics, system info, and CrabDB metadata                 |
| `crabctl deploy`                 | Deploy configuration files or binaries to nodes via SSH                     |
| `crabctl query`                  | Run queries against `.crabdb` files on remote nodes (MyShell or NoShell)    |
| `crabctl exec`                   | Execute an arbitrary shell command remotely                                 |
| `crabctl sync`                   | Synchronize a database from one node to others                              |
| `crabctl logs`                   | View or tail logs from one or more nodes                                    |
| `crabctl spider <script>`        | Execute a Spider script for orchestration or automation                     |
| `crabctl push <db> <node>`       | Push a local `.crabdb` file to a remote node                                |
| `crabctl pull <db> <node>`       | Fetch a remote `.crabdb` file to your local system                          |
| `crabctl startup <node>`         | Start the `crabd` service on all nodes or a specific node                   |
| `crabctl restart <node>`         | Restart the `crabd` service on a remote node                                |
| `crabctl shutdown <node>`        | Gracefully shut down a remote node                                          |
| `crabctl metrics`                | Collect and display metrics from all nodes (CPU, memory, I/O, CrabDB stats) |
| `crabctl ping <node>`            | Ping a node to test connectivity and latency                                |
| `crabctl set <key> <val>`        | Set a global config key-value (e.g. default timeout, retry limit)           |
| `crabctl get <key>`              | Get a global config key                                                     |
| `crabctl nodes add <host>`       | Add a new node to the managed set                                           |
| `crabctl nodes remove <host>`    | Remove a node from the managed set                                          |
| `crabctl nodes list`             | List all configured or discovered nodes                                     |
| `crabctl auth <node>`            | Authenticate with a remote node (e.g., via SSH key setup or token)          |

---

## 🕸️ `spider` — Automate the Crab

The `spider` command runs **Spider Scripts**, a domain-specific language (DSL) designed to orchestrate multiple Crab nodes in sequence or parallel. Think of it as a shell + pipeline manager for your entire Pi-based infrastructure.

```sh
crabctl spider ./scripts/deploy_all.spider
```

Spider scripts support logic, loops, conditions, and built-in commands like `connect`, `put`, `sync`, and `wait`.

---

## ✨ Examples

```sh
# Scan for nodes on LAN
crabctl scan

# View system and CrabDB status from all nodes
crabctl status

# Query a key using NoShell
crabctl query --node pi4 --mode noshell --key logs/temp:today

# Deploy config to all nodes
crabctl deploy --all --config crabd.conf

# Execute a remote command
crabctl exec --node pi7 "uptime"

# Sync a database across all nodes
crabctl sync --source pi1 --target-all --db config.crabdb

# Run a spider script to do multi-step orchestration
crabctl spider upgrade_nodes.spider
```

---

## **Prerequisites**

Ensure you have the following installed before starting:

- **Meson Build System**: This project relies on Meson. For installation instructions, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html).

## **Setting Up Meson Build**

1. **Install Meson**:
    - Follow the installation guide on the [Meson website](https://mesonbuild.com/Getting-meson.html) for your operating system.

## **Setting Up, Compiling, Installing, and Running the Project**

1. **Clone the Repository**:

    ```sh
    git clone https://github.com/fossillogic/crabctl.git
    cd crabctl
    ```

2. **Configure the Build**:

    ```sh
    meson setup builddir
    ```

3. **Compile the Project**:

    ```sh
    meson compile -C builddir
    ```

4. **Install the Project**:

    ```sh
    meson install -C builddir
    ```

5. **Run the Project**:

    ```sh
    crabctl
    ```

## **Contributing**

Interested in contributing? Please open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/crabctl).

## **Feedback and Support**

For issues, questions, or feedback, open an issue on the [GitHub repository](https://github.com/fossillogic/crabctl/issues).

## **License**

This project is licensed under the [Mozilla Public License](LICENSE).
