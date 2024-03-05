# ZMOS

## Description
ZMOS is an IoT OS based on [Mongoose OS](https://mongoose-os.com/mos.html)

## Features

### 1. Kernel
The kernel is the core component of the OS.  
It manages system resources and provides essential services.  
It Sets up the foundation layer for higher-level software to run.  

<b>Kernel Components:</b>  
- Basic Kernel Data Structures
- File System (VFS Integration)
- Networking (HTTP MQTT ESP-NOW Integration)
- Device Drivers
- Multitasking and Process Scheduling
- Memory Manager

### 2. Shell
The shell is a text based interface that allows users to interact with ZMOS kernel.  

<b>Shell Capabilities:</b>  
- System Bindings (Lua Wrapper for Kernel Components) [TODO]
- Scripting (Setting up a Lua REPL) [TODO]
- User Management and Access Control [TODO]

### 3. Web Dashboard
A lightweight web dashboard served via device's builtin webserver.  

<b>Dashboard Features:</b>
- Device Resources Monitor [TODO]
- A Terminal Connected to ZMOS Shell over HTTP [TODO]
- System Configurations Portal [TODO]
- Simple File Explorer and Text Editor [TODO]

### 4. Firmware OTA Update
