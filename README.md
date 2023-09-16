# KNN Classifier

Machine learning algorithm (K nearest neighbors) on a TCP server in C++ with command design and multi-threading capabilities.  
Based on linear regression prediction module, the algorithm uses a mathematical calculation and learns from uploaded data.  
New data that is uploaded to it is then categorized based on the calculation module.  
This is the final project of advanced programming 1 course in Bar-Ilan University.

## Table of Contents

- [Run](#run)
  - [Server](#server)
  - [Client](#client)
- [Code Description](#code-description)
  - [Server](#server-1)
  - [Client](#client-1)
- [Optimizations](#optimizations)
- [Collaborators](#collaborators)

## Run

### Server

1. Clone the repository.
2. Open a terminal window and navigate to the repository path using the command `cd repo_path` where `repo_path` is the path of your repository.
3. Compile the client and server code using the `make` command.
4. Once the code is compiled, run the server end by typing in `./server.out port` where `port` is the port chosen by the user and designated by the operating system for the current connection.
   **Note: the designated port range offered by the OS is between 0 and 65535.**
5. After the server is up and running, waiting for a connection to be made by the client, you can move on to running the client end.

### Client

1. Open a terminal window and navigate to the repository path using the command `cd repo_path` where `repo_path` is the path of your repository.
2. Run the client by typing the following command `./client.out ip port` where `ip` is the IPv4 address of the server, and `port` is the same port used by the server.
3. After the connection to the server has been made, a menu will be sent from the server to choose an operation to be executed by the KNN classifier server.
   **Note: Please choose inputs 1, 2, 3, 4, 5, or 8 from the menu; otherwise, "invalid input" will be sent back, and you will be forced to choose again.**
4. Once a valid option has been sent to the server, its execution will be initiated by the server and client.

## Code Description

This program uses a Server - Client network interface to communicate and execute requests given by the client in the server.

### Server

The KNN server performs operations regarding handling vector files, training through them, and classifying test files based on its training with the KNN algorithm.  
The server uses a `command` design pattern, which enables us to separate the server's execution operations implementations from the execution itself, meaning the IO is independent of the operations the server is running.  
The following image describes the command interface and the relations between the server operations:  
![image](https://user-images.githubusercontent.com/60584742/214577351-6b978ae8-895d-4e63-a626-6eff62b34d3f.png)

Note that `Command` and `DefaultIO` are abstract classes.  
Let us explain this server design pattern broadly and then dive into every component.  
Each `Command` child is an operation of the server inheriting from `Command` component its execution method, configuration, description, and `DefaultIO`.  
The `DefaultIO` class determines the manner in which the input and output of the user and executions will be performed. In our program, we have `SocketIO` to communicate between server and client interface.
The `CLI` is instantiated to start each command's execution with the designated `DefaultIO` which is selected.

- **CLI**: Is a class that holds all commands and `DefaultIO`, and its start method initiates the interaction between the operations of the server and the IO selected by the user.
- **Command**: Is an abstract class that determines what methods and fields every command should have like execute, configuration, defaultIO, and description.
- **DefaultIO**: Is an abstract class that determines in which manner the input and output will be handled.
- **SocketIO**: Is a class that inherits from `DefaultIO` that is used to communicate through a socket interface.
- **Operations**: Are all the classes that inherit from `Command` and hold the execution method designated to them.

### Client

The client end receives a menu of operations to perform from. Each operation is split into cases in which there is a designated interaction between the server and the client.  
The client runs endlessly until operation 8 is performed, the socket is then closed, and the connection between the client and server is terminated.

## Optimizations

- Added threading to enable multiple client handling.
- Added threading to download files in the background.
- Added a loop to the receiving end to handle files bigger than 4KB.
- Added validation of vector length of both files in the Upload operation.

## Collaborators

- Alik Teplitsky
- Roi Nir
