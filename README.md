# AX1_EX4
Advanced Programming course - Exercise 4
## Run
- Clone the repository.
###### SERVER
1. Open terminal window and navigate to repository path using the command `cd repo_path` where `repo_path` is the path of your repository.  
2. Compile the client and server code using `make` command.  
3. Once the code is compiled run the server end by typing in `./server.out port` where `port` is the port chosen by the user and designated by the operating system for the current connection.  
**note: the designated port range offered by the os is between 0 and 65535**  
4. After we got the server up and running and waiting for a connection to be made by the client, we can move on to running the client end. 
###### CLIENT
1. Open terminal window and navigate to repository path using the command `cd repo_path` where `repo_path` is the path of your repository.  
2. Run the client by typing the following command `./client.out ip port` where `ip` is the ipv4 address of the server so that a connection could be made  
to the designated server and `port` is the same port used by the server.  
3. After the connection to the server has been made, a menu will be sent from the server to choose operation from to be executed by the knn classifier server.  
**note: please choose inputs 1,2,3,4,5,8 from the menu, otherwise `invalid input` will be sent back you will be forced to choose again.**
4. Once a valid option has been sent to the server, it's execution will be initiated by the server and client.  
    - <ins>Option 1</ins>: Server will request a path to the `train_vectors`. insert a valid local path for `.csv` file to train the server.  
    if the path was valid and the upload was successful, a message will be sent and a local path to the `test_vectors` will be requested by the server.  
    if the path was valid and the upload was succesful, a message will be sent indicating the upload was successful.  
    **note: both the `train_vectors` and `test_vectors` must be of same vector length and also of valid format for each vector.  
    for `train_vectors` the following format will be : `(v1,v2, ... vn) , category` and for `test_vectors` the following format : `(v1,v2, ... vn)`.
    Otherwise, the upload operation will not be successful and a message will be sent from the server indicating it.**
    - <ins>Option 2</ins>: The server will send the current `[k, metric]` configuration and will wait for the client to either insert a new config or press `enter`
    and stay with the current config.  
    **note: the default configuration for `[k, metric]` are `5 AUC`, also if an invalid config has been inserted the server will send an error message.  
    furthermore, if no files were uploaded yet a message requesting to upload files will be sent.  
    lastly, if `k` is bigger than the number of vectors in the `test_vectors.csv` an error will be sent from the server.**
    - <ins>Option 3</ins>: will execute knn classification with selected configurations and uploaded files. a message indicating the classification proccess was
    successful will be sent from the server.  If files were not uploaded a message requesting files to be uploaded will be sent from the server.  
    - <ins>Option 4</ins>: the results of the classification will be sent from the server and displayed for each vector in `test_vectors`.  
    If `classify` wasn't executed or failed during runtime then an error will be sent from the server requesting that `classify` will be executed prior to this operation.  
    - <ins>Option 5</ins>: server will sent the classification results to the client and wait for a local path to be given to store the results of the classification in.  
    please follow this format to save the file locally `chosen_path\\results.txt`.  
     If `classify` wasn't executed or failed during runtime then an error will be sent from the server requesting that `classify` will be executed prior to this operation.
    - <ins>Option 8</ins>: The server will terminate the connection to the client and join the thread it was running on.  
5. After an operation has been executed successfully, menu will be sent to the client again to choose from the latter options.  
This will occur endlessly untill option 8 will be executed and the connection to the client will be terminated.  
## Code Description
This Program uses a Server - Client network interface to communicate and execute requests given by the client in the server.
###### SERVER
The knn server preforms operations regarding handling vector files, training through them and classifying test files based on it's training with the knn algorithm.  
The server uses a `command` design pattern, which enables us to seperate the servers execution operations implementations from the execution itself.  
Meaning the IO is independent of the operations the server is running.  
The following image describes the command interface and the relations between the server operations :  
![image](https://user-images.githubusercontent.com/60584742/214577351-6b978ae8-895d-4e63-a626-6eff62b34d3f.png)
Note that command and DefaultIO are abstract classes.  
Let us explain thus server design pattern broadly and then dive in every component.  
Each command child is an operation of the server inheriting from command component it's execution method , configuration, description and defaultIO.  
The DefaultIO class determines the manner in which the input and output of the user and executions will be preformed, in our program we have a SocketIO
to communicate between server and client interface.  
The CLI is instantiated to start each commands execution with the designated DefaultIO which is selected.  
- <ins>CLI</ins>: Is a class that holds all commands and DefaultIO, and it's start method initiates the interaction between the operations of the server and the IO selected by the user.  
- <ins>Command</ins> Is an abstract class that determines what methods and fields every command should have like execute, configuration, defaultIO and description.  
- <ins>DefaultIO</ins>: Is an abstract class taht determines in which manner the input and output will be handled.  
- <ins>SocketIO</ins>: Is a class that inherits from DefaultIO that is used to communicate through a socket interface.  
- <ins>Operations</ins>: Are all the classes that inherit from command and hold the execution method designated to them.  
###### CLIENT
The client end receives a menu of operations to preform from.  
Each operations is split to cases in which there is a designated interaction between the server and the client.  
The client runs endlessly untill operation 8 is preformed , the socket is then closed and the connection between the client and server is terminated.  
## Optimizations
* Added threading to enable multiple client handling.
* Added threading to download file in background.
* Added loop to receiving end to handle files bigger than 4KB.
* Added validation of vector length of both files in Upload operation.
## Collaborators
Alik Teplitsky  
Roi Nir
