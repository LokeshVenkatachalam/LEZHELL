# LINUX SHELL : LEZHELL

## Running the Shell
1)make
   or
2)make run
   or
3)./lezhell 
exit the shell.
## What and all shell can do 

This shell is a prototype linux shell many functions are still not working:

* pwd : prints the present working directory.
* cd  : changes the directory based on the flags given.

  * ``` bash
    cd
    cd .
    cd ..
    cd ~
    cd <directory>
    cd <full path>
    ```

* ls : lists the contents of a directory/directories seprated by space based on the flags given in any given order.

  * ```bash
    ls
    ls -a
    ls -l
    ls -al
    ls -la
    ls <directory>


* echo : echo values on prototype terminal itself

  * ```bash
    echo <"LEZHELL">
    ```

* pinfo : lists the details of a particular process (may be based on a process ID that is given).
  
  * ```bash
    pinfo
    pinfo <pid>
    ```

* Foreground Processes: terminal can be used only after the Process Completion. Example:
  
  * ```bash
    firefox 
    ```

* Background Processes: Processes that run simultaneuosly without disturbing the terminal. Example:

  * ```bash
    gedit &
    ```

* jobs : prints all the  background jobs in alphabatical order

  * ```bash
    jobs
    ```

* fg : brings a running or a stopped background job with given job number to foreground.

  * ```bash
    fg 1
    ```

* bg : changes a stopped background job to a running background job.

  * ```bash
    bg 1
    ```
