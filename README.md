# Communication Program: Client and Server

This project implements a client-server communication system using UNIX signals (`SIGUSR1` and `SIGUSR2`). The program consists of two executables: `client` and `server`. It focuses on inter-process communication, error handling, and efficient performance.

---

## Features

### Mandatory Part:
1. **Server**:
   - Launches first and displays its **Process ID (PID)** upon startup.
   - Receives strings sent by clients and prints them.
   - Handles multiple clients sequentially without needing to restart.

2. **Client**:
   - Takes two parameters:
     1. Server PID.
     2. String to send.
   - Sends the provided string to the server using **UNIX signals**.

3. **Communication**:
   - The server must display received strings promptly (delays longer than necessary are considered unacceptable).
   - Communication between the client and server exclusively uses `SIGUSR1` and `SIGUSR2`.

4. **Error Handling**:
   - Thorough handling to avoid segmentation faults, memory leaks, or unexpected behavior.

### Bonus Part:
- **Acknowledgment**:
  - The server sends an acknowledgment signal back to the client after successfully receiving a message.

---

## Instructions for Use

### 1. Compilation:
Run the following command to compile the project:
```bash
make
```
This will produce two executables:
```
client
server
```
### 2. Usage:
Start the Server:
```bash
./server
```
The server will display its PID.

Send a Message from the Client:
```bash
./client <server_pid> "<message>"
```
Replace <server_pid> with the PID displayed by the server.
Replace <message> with the string you want to send.

#The project uses ft_printf function which mimics the behaviour of the original printf function.
