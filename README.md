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
The server uses a `command` design pattern, which enables us to seperate the servers execution operations implementations from the execution itself.  
Meaning the IO is independent of the operations the server is running.  
